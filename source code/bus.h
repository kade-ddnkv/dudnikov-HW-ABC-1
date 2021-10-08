#include "fstream"
#include "table_output.h"
#include "random.h"

struct bus {
    // Емкость топливного бака (в литрах).
    int fuel_tank_capacity;
    // Расход топлива (в литрах) на 100 км.
    double fuel_consumption;
    // Пассажировместимость.
    short passenger_capacity;
};

// Ввод параметров автобуса из потока.
void in(bus &b, std::ifstream &ifst);

// Программная генерация параметров автобуса.
void inRnd(bus &b, bool realistic_random);

// Вывод параметров автобуса в поток.
void out(bus &b, std::ofstream &ofst);

// Максимальная дистанция, которую может проехать автобус.
double maxDistance(bus &b);