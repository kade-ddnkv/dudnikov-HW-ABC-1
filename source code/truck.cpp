#include "truck.h"

void in(truck &t, std::ifstream &ifst) {
    ifst >> t.fuel_tank_capacity >> t.fuel_consumption >> t.load_capacity;
    // Проверка на корректность данных.
    if (t.fuel_tank_capacity <= 0) {
        throw std::invalid_argument("Wrong fuel tank capacity in truck!\n"
                                    "Check input file for <"
                                    + std::to_string(t.fuel_tank_capacity)
                                    + "> number\n");
    }
    if (t.fuel_consumption <= 0) {
        throw std::invalid_argument("Wrong fuel consumption in truck!\n"
                                    "Check input file for <"
                                    + std::to_string(t.fuel_consumption)
                                    + "> number\n");
    }
    if (t.load_capacity <= 0) {
        throw std::invalid_argument("Wrong load capacity in truck!\n"
                                    "Check input file for <"
                                    + std::to_string(t.load_capacity)
                                    + "> number\n");
    }
}

void inRnd(truck &t, bool realistic_random) {
    // Данные могут быть сгенерированы похожими на настоящие.
    if (realistic_random) {
        t.fuel_tank_capacity = randPositiveInt(150, 300);
        t.fuel_consumption = randPositiveDouble(20, 45);
        t.load_capacity = randPositiveInt(3500, 6000);
    } else {
        t.fuel_tank_capacity = randPositiveInt32();
        t.fuel_consumption = randPositiveDouble();
        t.load_capacity = randPositiveInt32();
    }
}

void out(truck &t, std::ofstream &ofst) {
    printWithTableView("truck", maxDistance(t), t.fuel_tank_capacity, t.fuel_consumption,
                       "load_cap", t.load_capacity, ofst);
}

double maxDistance(truck &t) {
    return t.fuel_tank_capacity / (t.fuel_consumption / 100);
}
