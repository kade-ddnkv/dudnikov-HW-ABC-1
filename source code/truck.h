#include "fstream"
#include "table_output.h"
#include "random.h"

struct truck {
    // Емкость топливного бака (в литрах).
    int fuel_tank_capacity;
    // Расход топлива (в литрах) на 100 км.
    double fuel_consumption;
    // Грузоподъемность (в кг).
    int load_capacity;
};

// Ввод параметров грузовика из потока.
void in(truck &t, std::ifstream &ifst);

// Программная генерация параметров грузовика.
void inRnd(truck &t, bool realistic_random);

// Вывод параметров грузовика в поток.
void out(truck &t, std::ofstream &ofst);

// Максимальная дистанция, которую может проехать грузовик.
double maxDistance(truck &t);