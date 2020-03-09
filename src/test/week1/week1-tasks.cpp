#include "week1-tasks.h"

namespace test {
namespace week1 {

/**
 * Задание по программированию: Второе вхождение
 *
 * Дана строка. Найдите в этой строке второе вхождение буквы f
 * и выведите индекс этого вхождения. Если буква f в данной строке
 * встречается тольо один раз, выведите число -1,
 * а если не встречается ни разу, выведите число -2. Индексы нумеруются с нуля.
 * */
void test_second_input()
{
    std::string in_str;
    std::cin >> in_str;

    int res = -2;
    for (int i = 0; i < in_str.size(); i++) {
        if (in_str[i] == 'f') {
            if (++res == 0) {
                res = i;
                break;
            }
        }
    }
    std::cout << res << std::endl;
}

/**
 * Задание по программированию: Наибольший общий делитель
 *
 * В stdin даны два натуральных числа.
 * Выведите в stdout их наибольший общий делитель.
 * */
void test_greatest_common_divisor()
{
    int a, b;
    std::cin >> a >> b;
    // while (a > 0 && b > 0) {
    if (a > b) {
        a = a % b;
    }
    else {
        b = b % a;
    }
    std::cout << a + b << std::endl;
    // std::cin >> a >> b;
    //}
}

/**
 * Двоичные числа
 *
 * На вход дано целое положительное число N.
 * Выведите его в двоичной системе счисления без ведущих нулей.
 * */
std::string transform_to_binary(int n)
{
    int p = 2; // основание системы счисления

    /**
     * while !(a<p)
     * a = n/p // int part
     * b = n - p * a // remainder
     * next -> n = a
     */
    std::vector<int> res;
    int a = p, b;
    // std::cout << a << " ";
    while (a > 0) {
        a = n / p;
        // std::cout << a << " ";
        b = n - p * a; // here b = 0 or 1
        n = a;
        std::cout << b << " ";
        res.push_back(b);
    }

    std::cout << std::endl;
    std::cout << res << std::endl;

    return res;
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
    // mytest(second_input);
    // mytest(greatest_common_divisor);
    mytest(transform_to_binary);
}
} // namespace week1
} // namespace test
