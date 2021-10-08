#include "fstream"
#include "table_output.h"
#include "random.h"

struct car {
    // Емкость топливного бака (в литрах).
    int fuel_tank_capacity;
    // Расход топлива (в литрах) на 100 км.
    double fuel_consumption;
    // Максимальная скорость (км/час).
    short max_speed;
};

// Ввод параметров машины из потока.
void in(car &c, std::ifstream &ifst);

// Программная генерация параметров машины.
void inRnd(car &c, bool realistic_random);

// Вывод параметров машины в поток.
void out(car &c, std::ofstream &ofst);

// Максимальная дистанция, которую может проехать машина.
double maxDistance(car &c);