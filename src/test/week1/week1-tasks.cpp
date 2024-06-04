#include "week1-tasks.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "../test.h"
namespace test {
namespace week1 {

/**
 * 6 Тренировочное задание по программированию: Чётные числа
 * Дано два целых числа A и B (A <= B, A >= 1, B <= 30000). Выведите через
 * пробел все чётные числа от A до B (включительно).
 * */
std::vector<int> odd_numbers(const int a, const int b)
{
    std::vector<int> res;
    for (int i = a; i <= b; i++) {
        if (i % 2 == 0) {
            // i - чётное число
            res.push_back(i);
        }
    }
    return res;
}

void test_odd_numbers()
{
    assert(odd_numbers(1, 10) == std::vector<int>({2, 4, 6, 8, 10}));
    assert(odd_numbers(2, 3) == std::vector<int>({2}));
    assert(odd_numbers(9, 11) == std::vector<int>({10}));
}

/**
 * 7 Задание по программированию: Второе вхождение
 *
 * Дана строка. Найдите в этой строке второе вхождение буквы f
 * и выведите индекс этого вхождения. Если буква f в данной строке
 * встречается тольо один раз, выведите число -1,
 * а если не встречается ни разу, выведите число -2. Индексы нумеруются с нуля.
 * */
int second_input(const std::string& in_str)
{
    // std::string in_str;
    // std::cin >> in_str;

    int res = -2;
    for (int i = 0; i < in_str.size(); i++) {
        if (in_str[i] == 'f') {
            if (++res == 0) {
                res = i;
                break;
            }
        }
    }
    return res;
}

void test_second_input()
{
    assert(second_input("comfort") == -1);
    assert(second_input("coffee") == 3);
    assert(second_input("car") == -2);
}

/**
 * 8 Задание по программированию: Наибольший общий делитель
 *
 * В stdin даны два натуральных числа.
 * Выведите в stdout их наибольший общий делитель.
 *
 * воспользуйтесь алгоритмом Евклида:
 * Пока A > 0 и B > 0:
 * Если A > B:
 * A = A % B
 * иначе:
 * B = B % A
 * Вывести A + B
 */
int greatest_common_divisor(int a, int b)
{
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    return a + b;
}

void test_greatest_common_divisor()
{
    assert(greatest_common_divisor(25, 27) == 1);
    assert(greatest_common_divisor(12, 16) == 4);
    assert(greatest_common_divisor(13, 13) == 13);
}

/**
 * 9 Двоичные числа
 *
 * На вход дано целое положительное число N.
 * Выведите его в двоичной системе счисления без ведущих нулей.
 *
 * Правило перевода целой части числа состоит из следующих этапов:
 * - число  N  делится на новое основание  р ;
 * - полученный остаток запоминается или записывается
 *   (это будет цифра младшего разряда);
 * - целая часть полученного частного снова делится на  р ;
 * - опять запоминаем полученный остаток (это будет цифра следующего разряда)
 * и т. д.
 * Такое последовательное деление продолжается до тех пор,
 * пока целая часть частного не окажется меньше, чем основание системы счисления
 * р . Эта последняя целая часть частного будет цифрой старшего разряда.
 * Результат формируется путем последовательной записи слева направо цифры
 * старшего разряда и всех записанных остатков в порядке, обратном их получению.
 * */
std::string transform_to_binary(int n)
{

    // std::cout << "int_part: " << n << " " << std::endl;
    int p = 2; // основание системы счисления

    std::vector<int> res;
    int ost;          // полученный остаток
    int int_part = n; // целая часть полученного частного
    do {
        int_part = n / p;
        ost = n - int_part * p;
        res.push_back(ost);
        n = int_part;
    } while (int_part >= p);

    res.push_back(int_part);

    bool existOne = false;
    std::stringstream ss;
    for (auto it = res.rbegin(); it != res.rend(); ++it) {
        existOne = existOne || *it == 1;
        if (existOne) {
            ss << *it;
        }
    }
    // std::cout << ss.str() << std::endl;
    return ss.str();
}

void test_transform_to_binary()
{
    assert(transform_to_binary(5) == "101");
    assert(transform_to_binary(32) == "100000");
    assert(transform_to_binary(1) == "1");
}

void week1_tasks()
{
    suite("Week 1");
    mytest(test_odd_numbers);
    mytest(test_second_input);
    mytest(test_greatest_common_divisor);
    mytest(test_transform_to_binary);
}
} // namespace week1
} // namespace test
