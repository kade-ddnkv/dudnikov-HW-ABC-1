#include "road_transport.h"
#include <iostream>
#include <iomanip>

struct container {
    enum {
        MAX_LEN = 10000
    };
    int len;
    // Массив указателей на объекты road_transport в куче.
    road_transport* data[MAX_LEN];
};

// Инициализирует контейнер.
void init(container &c);

// Очищает массив указателей и соответствующие объекты road_transport.
void clear(container &c);

// Вводит данные в контейнер из потока.
void in(container &c, std::ifstream &ifst);

// Генерирует данные в контейнер с помощью случайных чисел.
void inRnd(container &c, int size, bool realistic_random);

// Выводит данные из контейнера в поток.
void out(container &c, std::ofstream &ofst);

// Сортирует данные внутри контейнера методом "пирамидальной сортировки" ("сортировки кучей").
void heapSort(container &c);

// Проверяет, отсортированы ли данные в контейнере.
bool isSortedByDescendingOrder(container &c);