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
 * Задание по программированию: Наибольший общий делитель
 *
 * В stdin даны два натуральных числа.
 * Выведите в stdout их наибольший общий делитель.
 * */
int greatest_common_divisor(int a, int b)
{
    if (a > b) {
        a = a % b;
    }
    else {
        b = b % a;
    }
    int res = a + b;
    std::cout << res << std::endl;
    return res;
}

void test_greatest_common_divisor()
{
    assert(greatest_common_divisor(25, 27) == 1);
    assert(greatest_common_divisor(12, 16) == 4);
    assert(greatest_common_divisor(13, 13) == 13);
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

    std::string str(res.begin(), res.end());
    // std::cout << std::endl;
    // std::cout << res << std::endl;

    return str;
}

void test_transform_to_binary()
{
    // assert(transform_to_binary(5) == "101");
    // assert(transform_to_binary(32) == "100000");
    // assert(transform_to_binary(1) == "1");
}

void week1_tasks()
{
    suite("Week 1");
    mytest(second_input);
    mytest(greatest_common_divisor);
    mytest(transform_to_binary);
}
} // namespace week1
} // namespace test
