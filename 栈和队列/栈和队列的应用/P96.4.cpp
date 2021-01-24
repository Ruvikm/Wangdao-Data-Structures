#include <iostream>
#include <stack>
#include <string>
#include <queue>
using namespace std;

#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define MaxSize 10
#define WaitCars 23
#define BusNum 7
#define TrackNum 2
struct Cars {
    int id;
    string type;  //货车：Track 客车：Bus
};


//P96.4
//某汽车轮渡口, 过江渡船毎次能载10辆车过江。过江车辆分为客车类和货车类, 上渡船
//有如下规定 : 同类车先到先上船; 客车先于货车上船, 且每上4辆客车, 才允许放上1
//辆货车; 若等待客车不足4辆, 则以货车代替; 若无货车等待, 允许客车都上船。试设
//计一个算法模拟渡口管理。

#pragma region P96.4

queue<Cars> Bus, Trucks, CarList;


void Load_PassCar() {
    Cars c;
    c.id = -999;
    if (!Bus.empty()) {
        c = Bus.front();
        Bus.pop();
        CarList.push(c);
    }
    else {
        if (!Trucks.empty()) {
            c = Trucks.front();
            Trucks.pop();
            CarList.push(c);
        }
    }
    if (c.id != -999)
        cout << "第" << c.id << "号" << c.type << "上船" << endl;
}

void Load_Track() {
    Cars c;
    c.id = -999;
    if (!Trucks.empty()) {
        c = Trucks.front();
        Trucks.pop();
        CarList.push(c);
    }
    else {
        if (!Trucks.empty()) {
            c = Bus.front();
            Bus.pop();
            CarList.push(c);
        }
    }
    if (c.id != -999)
        cout << "第" << c.id << "号" << c.type << "上船" << endl;
}



void Ferry_Manage() {
    int Bus_Count = 0;
    int MaxNum = 0;
    while (MaxNum < 10)
    {
        if (Bus_Count != 4) {
            Bus_Count++;
            MaxNum++;
            Load_PassCar();
        }
        if (Bus_Count == 4) {
            Bus_Count = 0;
            MaxNum++;
            Load_Track();
        }
    }
}



#pragma endregion

//test
void Init() {
    //Bus
    _for(i, 0, BusNum) {
        Cars t;
        t.id = i, t.type = "Bus";
        Bus.push(t);
    }
    //Track
   _for(i, 0, TrackNum) {
       Cars t;
       t.id = i, t.type = "Track";
       Trucks.push(t);
   }
}

int main()
{
    Init();
    Ferry_Manage();
    return 0;
}

