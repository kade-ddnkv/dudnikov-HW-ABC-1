#pragma once
#include <fstream>
#include <iomanip>

// Вспомогательный файл, нужен для красивого вывода данных в таблицу.

void printWithTableView(const std::string &type, const double &max_distance,
                        const int &fuel_tank_capacity, const double &fuel_consumption,
                     const std::string &additional_info, const int &additional_result, std::ofstream &ofst);

void printHeader(std::ofstream &ofst);

void printTitle(const std::string &title, std::ofstream &ofst);