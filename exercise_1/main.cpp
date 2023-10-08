#include <iostream>
#include "ListPriorityQueue.h"

int main(int argc, char const *argv[])
{
    ListPriorityQueue<int, Less<int>> queue;

    queue.insert(5);
    queue.insert(4);
    queue.insert(7);
    queue.insert(1);

     while (!queue.empty()) {
        std::cout << "Min: " << queue.min() << std::endl;
        queue.removeMin();
    }

    return 0;
}
