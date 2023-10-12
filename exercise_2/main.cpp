#include <iostream>
#include <fstream>
#include <ctime>
#include "ListPriorityQueue.h"

int main(int argc, char const *argv[])
{
    ListPriorityQueue<int, Comparator<int>> pq;
    ListPriorityQueue<int, Comparator<int>> pq2;
    int num = 0;
    clock_t start;
    clock_t end;

    std::fstream small_inFile("C:/Users/jesus/GitHub/PriorityQueue/small1k.txt", std::ios_base::in);
    std::fstream large_inFile("C:/Users/jesus/GitHub/PriorityQueue/large100k.txt", std::ios::in);

    std::cout << "Author: Jesus Rodriguez-Luna" << std::endl << std::endl;

    if (!small_inFile.is_open()) {
        std::cout << "Error: Unable to open file." << std::endl;
        return 1;
    }

    start = clock();
    while (small_inFile >> num) {
        pq.insert(num);
    }

    small_inFile.close();
    std::cout << "small1k.txt File: ";
    int firstFiveCount = 5;

    while (!pq.empty() && firstFiveCount--) {
        std::cout << pq.min() << " ";
        pq.removeMin();
    }

    firstFiveCount = 5;

    std::cout << "\nlast 5: ";
    std::list<int> lastFive;
    while (!pq.empty()) {
        lastFive.push_back(pq.min());
        if (lastFive.size() > 5) {
            lastFive.pop_front();
        }
        pq.removeMin();
    }

    for (const int& val : lastFive) {
        std::cout << val << " ";
    }

    end = clock();
    std::cout << "\nTime taken for small1k.txt sorting: " << end - start << " ms" << std::endl << std::endl;

    if (!large_inFile.is_open()) {
        std::cout << "Error: Unable to open file." << std::endl;
        return 1;
    }

    start = clock();
    while (large_inFile >> num) {
        pq2.insert(num);
    }

    large_inFile.close();
    std::cout << "large100k.txt File: ";
    firstFiveCount = 5;

    while (!pq2.empty() && firstFiveCount--) {
        std::cout << pq2.min() << " ";
        pq2.removeMin();
    }

    firstFiveCount = 5;

    std::cout << "\nlast 5: ";
    std::list<int> lastFive2;
    while (!pq2.empty()) {
        lastFive2.push_back(pq2.min());
        if (lastFive2.size() > 5) {
            lastFive2.pop_front();
        }
        pq2.removeMin();
    }

    for (const int& val : lastFive2) {
        std::cout << val << " ";
    }

    end = clock();
    std::cout << "\nTime taken for large100k.txt sorting: " << end - start << " ms" << std::endl;

    return 0;
}
