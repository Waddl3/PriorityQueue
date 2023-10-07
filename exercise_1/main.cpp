#include <iostream>
#include "ListPriorityQueue.h"

int main(int argc, char const *argv[])
{
    ListPriorityQueue<int, int> test;

    test.insert(5);
    test.insert(4);
    test.insert(7);
    test.insert(1);
    std::cout << test.min();

    return 0;
}
