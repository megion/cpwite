#include "week1-tasks.h"

namespace test {
namespace week1 {

/**
 * Задание по программированию: Второе вхождение
 */
void test_second_input()
{
    log(info, "start second_input");
    std::string in_str;
    std::cin >> in_str;
    std::cout << in_str << std::endl;
}

void week1_tasks()
{
    suite("Week 1");
    mytest(second_input);
}
} // namespace week1
} // namespace test
