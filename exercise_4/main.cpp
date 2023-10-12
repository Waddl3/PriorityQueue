#include <iostream>
#include "HeapPriorityQueue.h"

int main(int argc, char const *argv[])
{
    HeapPriorityQueue<int, Comparator<int>> pq;

    pq.insert(5);
    pq.insert(4);
    pq.insert(7);
    pq.insert(1);

    std::cout << pq.min() << " ";

    pq.removeMin();
    pq.insert(3);
    pq.insert(6);
    
    std::cout << pq.min() << " ";

    pq.removeMin();

    std::cout << pq.min() << " ";

    pq.removeMin();
    pq.insert(8);

    std::cout << pq.min() << " ";

    pq.removeMin();
    pq.insert(2);

    std::cout << pq.min() << " ";

    pq.removeMin();

    std::cout << pq.min() << " ";

    pq.removeMin();

    return 0;
}
