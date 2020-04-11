#include "week2-tasks.h"

namespace test {
namespace week2 {

/**
 * принимает int и возвращает факториал своего аргумента.
 * Гарантируется, что аргумент функции по модулю не превышает 10.
 * Для отрицательных аргументов функция должна возвращать 1.
 * */
int factorial(int num)
{
    if (num < 0) {
        return 1;
    }
    int res = 1;
    for (int i = 1; i <= num; i++) {
        res *= i;
    }
    return res;
}

void test_factorial()
{
    assert(factorial(1) == 1);
    assert(factorial(-2) == 1);
    assert(factorial(4) == 24);
}

/**
 * Напишите функцию, которая
 * называется IsPalindrom
 * возвращает bool
 * принимает параметр типа string и возвращает,
 * является ли переданная строка палиндромом
 * Палиндром - это слово или фраза,
 * которые одинаково читаются слева направо и справа налево.
 * Пустая строка является палиндромом.
 */
bool is_palindrom(const std::string& str)
{
    std::size_t len = str.length();
    for (int i = 0; i < len; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

void test_is_palindrom()
{
    assert(is_palindrom("madam") == true);
    assert(is_palindrom("gentleman") == false);
    assert(is_palindrom("X") == true);
}

/**
 * Напишите функцию, которая
 * называется PalindromFilter
 * возвращает vector<string>
 * принимает vector<string> words и int minLength и
 * возвращает все строки из вектора words,
 * которые являются палиндромами и имеют длину не меньше minLength
 */
std::vector<std::string> palindrom_filter(std::vector<std::string> words,
                                          int minLength)
{
    std::vector<std::string> res;
    for(auto s: words) {
        if(s.length() >= minLength && is_palindrom(s)) {
            res.push_back(s);
        }
    }
    return res;
}

void test_palindrom_filter()
{
    assert(palindrom_filter({"abacaba", "aba"}, 5) ==
           std::vector<std::string>({"abacaba"}));

    assert(palindrom_filter({"abacaba", "aba"}, 2) ==
           std::vector<std::string>({"abacaba", "aba"}));

    assert(palindrom_filter({"weew", "bro", "code"}, 4) ==
           std::vector<std::string>({"weew"}));
}

void week2_tasks()
{
    suite("Week 2");
    mytest(factorial);
    mytest(is_palindrom);
    mytest(palindrom_filter);
}
} // namespace week2
} // namespace test
