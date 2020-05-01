#ifndef TEST_WEEK2_BUS_STOP_H
#define TEST_WEEK2_BUS_STOP_H

#include <map>
#include <string>
#include <vector>

#include "../test.h"

namespace test {
namespace week2 {

/**
 * Реализуйте систему хранения автобусных маршрутов.
 * Вам нужно обрабатывать следующие запросы:
 *
 * NEW_BUS bus stop_count stop1 stop2 ... — добавить маршрут автобуса с
 * названием bus и stop_count остановками с назаниями stop1, stop2, ...
 *
 * BUSES_FOR_STOP stop — вывести названия всех маршрутов автобуса,
 * проходящих через остановку stop.
 *
 * STOPS_FOR_BUS bus — вывести названия всех остановок маршрута bus
 * со списком автобусов, на которые можно пересесть на каждой из остановок.
 *
 * ALL_BUSES — ввести список всех маршрутов с остановками.
 */
void new_bus(std::string bus, std::vector<std::string> stops);
std::vector<std::string> buses_for_stop(std::string stop);
std::vector<std::string> stops_for_bus(std::string bus);
std::vector<std::string> all_buses();

} // namespace week2
} // namespace test

#endif
