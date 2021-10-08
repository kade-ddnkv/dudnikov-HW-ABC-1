#include "fstream"
#include "road_transport.h"

// Методы в этом файле запускают соответствующие методы в зависимости от типа транспорта.
// (в зависимости от ключа key)

void in(road_transport &rt, std::ifstream &ifst) {
    char type;
    ifst >> type;

    if (type == 't') {
        rt.k = road_transport::TRUCK;
    } else if (type == 'b') {
        rt.k = road_transport::BUS;
    } else if (type == 'c') {
        rt.k = road_transport::CAR;
    } else {
        throw std::invalid_argument("Unsupported road transport.\n"
                                    "Check for symbol <" + std::string(type, 1) + "> in input file.\n"
                                                                                  "Or delete blank lines in the end of file");
    }

    switch (rt.k) {
        case road_transport::TRUCK:
            rt.p_truck = new truck;
            in(*rt.p_truck, ifst);
            break;
        case road_transport::BUS:
            rt.p_bus = new bus;
            in(*rt.p_bus, ifst);
            break;
        case road_transport::CAR:
            rt.p_car = new car;
            in(*rt.p_car, ifst);
            break;
    }
}

void inRnd(road_transport &rt, bool realistic_random) {
    rt.k = static_cast<road_transport::key>(rand() % 3);

    switch (rt.k) {
        case road_transport::TRUCK:
            rt.p_truck = new truck;
            inRnd(*rt.p_truck, realistic_random);
            break;
        case road_transport::BUS:
            rt.p_bus = new bus;
            inRnd(*rt.p_bus, realistic_random);
            break;
        case road_transport::CAR:
            rt.p_car = new car;
            inRnd(*rt.p_car, realistic_random);
            break;
    }
}

void out(road_transport &rt, std::ofstream &ofst) {
    switch (rt.k) {
        case road_transport::TRUCK:
            out(*rt.p_truck, ofst);
            break;
        case road_transport::BUS:
            out(*rt.p_bus, ofst);
            break;
        case road_transport::CAR:
            out(*rt.p_car, ofst);
            break;
        default:
            throw std::invalid_argument("Unsupported road transport.");
    }
}

double maxDistance(road_transport &rt) {
    switch (rt.k) {
        case road_transport::TRUCK:
            return maxDistance(*rt.p_truck);
        case road_transport::BUS:
            return maxDistance(*rt.p_bus);
        case road_transport::CAR:
            return maxDistance(*rt.p_car);
        default:
            throw std::invalid_argument("Unsupported road transport.");
    }
}

void clear(road_transport &rt) {
    switch (rt.k) {
        case road_transport::TRUCK:
            delete rt.p_truck;
            return;
        case road_transport::BUS:
            delete rt.p_bus;
            return;
        case road_transport::CAR:
            delete rt.p_car;
            return;
        default:
            throw std::invalid_argument("Unsupported road transport.");
    }
}
