#include <cstdlib>
#include <map>
#include <string>
#include <utility>
#include <vector>

#include "../test.h"
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
    for (int i = 0; i < len / 2; i++) {
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
    for (auto s : words) {
        if (s.length() >= minLength && is_palindrom(s)) {
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

/**
 * Напишите функцию UpdateIfGreater,
 * которая принимает два целочисленных аргумента: first и second.
 * Если first оказался больше second, Ваша функция должна записывать
 * в second значение параметра first.
 * При этом указанная функция не должна ничего возвращать,
 * а изменение параметра second должно быть видно на вызывающей стороне.
 */
void UpdateIfGreater(const int first, int& second)
{
    if (first > second) {
        second = first;
    }
}

void test_UpdateIfGreater()
{
    int a = 2, b = 5;
    UpdateIfGreater(a, b);
    assert(b == 5);

    int aa = 6, bb = 5;
    UpdateIfGreater(aa, bb);
    assert(bb == 6);
}

/**
 * Напишите функцию MoveStrings,
 * которая принимает два вектора строк,
 * source и destination, и дописывает все строки из первого вектора
 * в конец второго.
 * После выполнения функции вектор source должен оказаться пустым.
 */
void MoveStrings(std::vector<std::string>& src, std::vector<std::string>& dst)
{
    for (auto s : src) {
        dst.push_back(s);
    }
    src.clear();
}

void test_MoveStrings()
{
    std::vector<std::string> src = {"src"};
    std::vector<std::string> dst = {"dst"};
    MoveStrings(src, dst);

    assert(src.size() == 0);
    assert(dst == std::vector<std::string>({"dst", "src"}));
}

/**
 * Реализуйте функцию void Reverse(vector<int>& v),
 * которая переставляет элементы вектора в обратном порядке.
 */
void Reverse(std::vector<int>& v)
{
    int len = v.size();
    for (int i = 0; i < len / 2; i++) {
        std::swap<int>(v[i], v[len - 1 - i]);
    }
}

void test_Reverse()
{
    std::vector<int> v = {1, 2, 3};
    Reverse(v);
    assert(v == std::vector<int>({3, 2, 1}));
}

/**
 * Даны значения температуры, наблюдавшиеся в течение N подряд идущих дней.
 * Найдите номера дней (в нумерации с нуля) со значением температуры
 * выше среднего арифметического за все N дней.
 *
 * Гарантируется, что среднее арифметическое значений температуры является
 * целым числом.
 *
 * Формат ввода
 * Вводится число N, затем N неотрицательных целых чисел — значения температуры
 * в 0-й, 1-й, ... (N−1)-й день.
 *
 * Формат вывода
 * Первое число K — количество дней,
 * значение температуры в которых выше среднего арифметического.
 * Затем K целых чисел — номера этих дней.
 */
std::vector<int> TemperatureAverage(const std::vector<int>& tv)
{
    // calculate temperature average
    int average = 0;
    for (auto t : tv) {
        average += t;
    }
    average = average / tv.size();

    std::vector<int> result;
    for (int i = 0; i < tv.size(); ++i) {
        if (tv[i] > average) {
            result.push_back(i);
        }
    }
    return result;
}

void test_TemperatureAverage()
{
    std::vector<int> result = TemperatureAverage({7, 6, 3, 0, 9});

    assert(result.size() == 3);
    assert(result == std::vector<int>({0, 1, 4}));
}

/**
 * 9. Люди стоят в очереди, но никогда не уходят из её начала,
 * зато могут приходить в конец и уходить оттуда.
 * Более того, иногда некоторые люди могут прекращать и начинать беспокоиться
 * из-за того, что очередь не продвигается.
 *
 * Реализуйте обработку следующих операций над очередью:
 * WORRY i: пометить i-го человека с начала очереди (в нумерации с 0)
 * как беспокоящегося;
 * QUIET i: пометить i-го человека как успокоившегося;
 * COME k: добавить k спокойных человек в конец очереди;
 * COME -k: убрать k человек из конца очереди;
 * WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
 * Изначально очередь пуста.
 *
 * Формат ввода
 * Количество операций Q, затем описания операций.
 *
 * Для каждой операции WORRY i и QUIET i гарантируется,
 * что человек с номером i существует в очереди на момент операции.
 * Для каждой операции COME -k гарантируется,
 * что k не больше текущего размера очереди.
 *
 * Формат вывода
 * Для каждой операции WORRY_COUNT выведите одно целое число —
 * количество беспокоящихся людей в очереди.
 */
std::vector<int> PeopleQueue(const std::vector<int>& tv)
{
    std::vector<int> result;
    return result;
}

void test_PeopleQueue() {}

/**
 * У каждого из нас есть повторяющиеся ежемесячные дела,
 * каждое из которых нужно выполнять в конкретный день каждого месяца:
 * оплата счетов за электричество, абонентская плата за связь и пр.
 * Вам нужно реализовать работу со списком таких дел на месяц,
 * а именно, реализовать набор следующих операций:
 * ADD i s
 * Назначить дело с названием s на день i текущего месяца.
 *
 * DUMP i
 * Вывести все дела, запланированные на день i текущего месяца.
 *
 * NEXT
 * Перейти к списку дел на новый месяц.
 * При выполнении данной команды вместо текущего (старого) списка дел
 * на текущий месяц создаётся и становится активным (новый) список дел
 * на следующий месяц: все дела со старого списка дел копируются в новый список.
 * После выполнения данной команды новый список дел и следующий месяц
 * становятся текущими, а работа со старым списком дел прекращается.
 * При переходе к новому месяцу необходимо обратить внимание
 * на разное количество дней в месяцах:
 *
 * если следующий месяц имеет больше дней, чем текущий, «дополнительные» дни
 * необходимо оставить пустыми (не содержащими дел);
 *
 * если следующий месяц имеет меньше дней, чем текущий, дела со всех «лишних»
 * дней необходимо переместить на последний день следующего месяца.
 *
 * Замечания
 * Историю списков дел хранить не требуется, работа ведется только с текущим
 * списком дел текущего месяца. Более того, при создании списка дел
 * на следующий месяц, он «перетирает» предыдущий список.
 *
 * Обратите внимание, что количество команд NEXT в общей последовательности
 * команд при работе со списком дел может превышать 11.
 * Начальным текущим месяцем считается январь.
 * Количества дней в месяцах соответствуют Григорианскому календарю с той лишь
 * разницей, что в феврале всегда 28 дней.
 *
 * Формат ввода
 * Сначала число операций Q, затем описания операций.
 *
 * Названия дел s уникальны и состоят только из латинских букв, цифр и символов
 * подчёркивания. Номера дней i являются целыми числами и нумеруются от 1 до
 * размера текущего месяца.
 *
 * Формат вывода
 * Для каждой операции типа DUMP в отдельной строке выведите количество дел в
 * соответствующий день, а затем их названия,
 * разделяя их пробелом. Порядок вывода дел в рамках каждой операции
 * значения не имеет.
 */
std::vector<int> WeekDays(const std::vector<int>& tv)
{
    std::vector<int> result;
    return result;
}

void test_WeekDays() {}

/**
 * Слова называются анаграммами друг друга, если одно из них можно получить
 * перестановкой букв в другом. Например, слово «eat» можно получить
 * перестановкой букв слова «tea», поэтому эти слова являются
 * анаграммами друг друга. Даны пары слов, проверьте для каждой из них,
 * являются ли слова этой пары анаграммами друг друга.
 */
std::map<char, int> BuildCharCounters(const std::string st)
{
    std::map<char, int> m;
    for (auto s : st) {
        m[s]++;
    }
    return m;
}

bool Anagrams(const std::pair<std::string, std::string>& pair)
{
    std::map<char, int> m1 = BuildCharCounters(pair.first);
    std::map<char, int> m2 = BuildCharCounters(pair.second);
    return m1 == m2;
}

void test_Anagrams()
{
    assert(Anagrams(std::make_pair("eat", "tea")) == true);
    assert(Anagrams(std::make_pair("find", "tea")) == false);
    assert(Anagrams(std::make_pair("master", "stream")) == true);
}

void week2_tasks()
{
    suite("Week 2");
    mytest(test_factorial);
    mytest(test_is_palindrom);
    mytest(test_palindrom_filter);
    mytest(test_UpdateIfGreater);
    mytest(test_MoveStrings);
    mytest(test_Reverse);
    mytest(test_TemperatureAverage);
    mytest(test_PeopleQueue);
    mytest(test_WeekDays);
    mytest(test_Anagrams);
}
} // namespace week2
} // namespace test
