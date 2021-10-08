#include "container.h"

void init(container &c) {
    c.len = 0;
}

void clear(container &c) {
    for (int i = 0; i < c.len; ++i) {
        clear(*c.data[i]);
        delete c.data[i];
    }
}

void in(container &c, std::ifstream &ifst) {
    while (!ifst.eof()) {
        // Проверка на случай ввод более 10000 данных из файла.
        if (c.len == c.MAX_LEN) {
            std::cout << "10000 objects were inputted.\n"
                      << "Container is full. Next objects will be ignored.\n";
            return;
        }
        c.data[c.len] = new road_transport;
        in(*c.data[c.len], ifst);
        ++c.len;
    }
}

void inRnd(container &c, int size, bool realistic_random) {
    while (c.len < size) {
        c.data[c.len] = new road_transport;
        inRnd(*c.data[c.len], realistic_random);
        ++c.len;
    }
}

void out(container &c, std::ofstream &ofst) {
    ofst << "Total objects in container: " << c.len << "\n";
    printHeader(ofst);
    for (int i = 0; i < c.len; ++i) {
        out(*c.data[i], ofst);
        ofst << '\n';
    }
}

// Вспомогательный метод. Его применение предполагает, что ему дается мин-куча, где только корень нарушает структуру.
// Метод за O(log2(кол-во элементов дереве)) последовательными свопами перемещает корень в нужное место в мин-куче.
void heapify(road_transport **data, double *keys, const int &len, int root) {
    int smallest = root;
    int l = root * 2 + 1;
    int r = root * 2 + 2;

    if (l < len && keys[l] < keys[smallest]) {
        smallest = l;
    }
    if (r < len && keys[r] < keys[smallest]) {
        smallest = r;
    }

    if (root != smallest) {
        std::swap(keys[root], keys[smallest]);
        std::swap(data[root], data[smallest]);
        heapify(data, keys, len, smallest);
    }
}

void heapSort(container &c) {
    double keys[c.len];
    for (int i = 0; i < c.len; ++i) {
        keys[i] = maxDistance(*c.data[i]);
    }

    // В начале нужно создать из неструктурированного массива мин-кучу.
    // Эта операция похожа на индукцию.
    // Начинаю запускать с нижних поддеревьев из трех элементов (база).
    // На всех следующих элементах оказывается, что два поддерева у корня являются мин-кучами (шаг индукции)
    // И только корень поддерева нарушает структуру, поэтому применяется heapify.
    for (int i = c.len / 2 - 1; i >= 0; --i) {
        heapify(c.data, keys, c.len, i);
    }

    // Для создания отсортированного массива
    // Каждый раз убираем корень дерева и ставим на его место последний элемент мин-кучи.
    // После чего применяем heapify, чтобы опять наверху оказался минимальный элемент.
    for (int i = c.len - 1; i >= 0; --i) {
        std::swap(c.data[0], c.data[i]);
        std::swap(keys[0], keys[i]);
        // Применение heapify опускает корневой элемент ниже по дереву до подходящего места.
        heapify(c.data, keys, i, 0);
    }
}

bool isSortedByDescendingOrder(container &c) {
    for (int i = 0; i < c.len - 1; ++i) {
        if (maxDistance(*c.data[i]) < maxDistance(*c.data[i + 1])) {
            return false;
        }
    }
    return true;
}
