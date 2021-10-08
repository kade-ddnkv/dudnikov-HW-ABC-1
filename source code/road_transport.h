#include "fstream"
#include "truck.h"
#include "bus.h"
#include "car.h"
#include <iostream>

// Базовая структура дорожного транспорта.
struct road_transport {
    enum key {
        TRUCK, BUS, CAR
    };
    key k;
    union {
        truck *p_truck;
        bus *p_bus;
        car *p_car;
    };
};

// Ввод данных по одному транспорту из потока (ввод зависит от типа транспорта).
void in(road_transport &rt, std::ifstream &ifst);

// Программная генерация данных на один транспорт.
void inRnd(road_transport &rt, bool realistic_random = true);

// Вывод параметров транспорта в поток (ввод зависит от типа транспорта).
void out(road_transport &rt, std::ofstream &ofst);

// Вычисление максимальной дистанции, которую может проехать транспорт.
double maxDistance(road_transport &rt);

// Очищает указатель на объект-транспорт в куче.
void clear(road_transport &rt);