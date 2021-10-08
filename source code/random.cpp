#include <stdexcept>
#include "random.h"

double randPositiveDouble(int min, int max) {
    if (min <= 0) {
        throw std::invalid_argument("Min number of random should be > 0");
    }
    double f = (double)rand() / RAND_MAX;
    return min + f * (max - min);
}

double randPositiveDouble() {
    double f = (double)rand() / RAND_MAX;
    return 1 + f * (DBL_MAX - 1);
}

int randPositiveInt(int min, int max) {
    if (min <= 0) {
        throw std::invalid_argument("Min number of random should be > 0");
    }
    return min + rand() % (max - min);
}

int randPositiveInt32() {
    return 1 + rand() % (INT32_MAX - 1);
}

short randPositiveInt16() {
    return 1 + rand() % (INT16_MAX - 1);
}
