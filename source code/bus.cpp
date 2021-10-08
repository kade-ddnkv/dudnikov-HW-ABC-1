#include "bus.h"

void in(bus &b, std::ifstream &ifst) {
    ifst >> b.fuel_tank_capacity >> b.fuel_consumption >> b.passenger_capacity;
    // Проверка на корректность данных.
    if (b.fuel_tank_capacity <= 0) {
        throw std::invalid_argument("Wrong fuel tank capacity in bus!\n"
                                    "Check input file for <"
                                    + std::to_string(b.fuel_tank_capacity)
                                    + "> number\n");
    }
    if (b.fuel_consumption <= 0) {
        throw std::invalid_argument("Wrong fuel consumption in bus!\n"
                                    "Check input file for <"
                                    + std::to_string(b.fuel_consumption)
                                    + "> number\n");
    }
    if (b.passenger_capacity <= 0) {
        throw std::invalid_argument("Wrong passenger capacity in bus!\n"
                                    "Check input file for <"
                                    + std::to_string(b.passenger_capacity)
                                    + "> number\n");
    }
}

void inRnd(bus &b, bool realistic_random) {
    // Данные могут быть сгенерированы похожими на настоящие.
    if (realistic_random) {
        b.fuel_tank_capacity = randPositiveInt(150, 300);
        b.fuel_consumption = randPositiveDouble(18, 35);
        b.passenger_capacity = static_cast<short>(randPositiveInt(10, 80));
    } else {
        b.fuel_tank_capacity = randPositiveInt32();
        b.fuel_consumption = randPositiveDouble();
        b.passenger_capacity = randPositiveInt16();
    }
}

void out(bus &b, std::ofstream &ofst) {
    printWithTableView("bus", maxDistance(b), b.fuel_tank_capacity, b.fuel_consumption,
                       "passenger_cap", b.passenger_capacity, ofst);
}

double maxDistance(bus &b) {
    return b.fuel_tank_capacity / (b.fuel_consumption / 100);
}
