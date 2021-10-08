#include "car.h"

void in(car &c, std::ifstream &ifst) {
    ifst >> c.fuel_tank_capacity >> c.fuel_consumption >> c.max_speed;
    // Проверка на корректность данных.
    if (c.fuel_tank_capacity <= 0) {
        throw std::invalid_argument("Wrong fuel tank capacity in car!\n"
                                    "Check input file for <"
                                    + std::to_string(c.fuel_tank_capacity)
                                    + "> number\n");
    }
    if (c.fuel_consumption <= 0) {
        throw std::invalid_argument("Wrong fuel consumption in car!\n"
                                    "Check input file for <"
                                    + std::to_string(c.fuel_consumption)
                                    + "> number\n");
    }
    if (c.max_speed <= 0) {
        throw std::invalid_argument("Wrong max speed in car!\n"
                                    "Check input file for <"
                                    + std::to_string(c.max_speed)
                                    + "> number\n");
    }
}

void inRnd(car &c, bool realistic_random) {
    // Данные могут быть сгенерированы похожими на настоящие.
    if (realistic_random) {
        c.fuel_tank_capacity = randPositiveInt(50, 90);
        c.fuel_consumption = randPositiveDouble(5, 9);
        c.max_speed = static_cast<short>(randPositiveInt(160, 190));
    } else {
        c.fuel_tank_capacity = randPositiveInt32();
        c.fuel_consumption = randPositiveDouble();
        c.max_speed = randPositiveInt16();
    }
}

void out(car &c, std::ofstream &ofst) {
    printWithTableView("car", maxDistance(c), c.fuel_tank_capacity, c.fuel_consumption,
                       "max_speed", c.max_speed, ofst);
}

double maxDistance(car &c) {
    return c.fuel_tank_capacity / (c.fuel_consumption / 100);
}
