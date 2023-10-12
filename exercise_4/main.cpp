#include <iostream>
#include <fstream>
#include <ctime>
#include "HeapPriorityQueue.h"
#include <list>

int main(int argc, char const *argv[])
{
    HeapPriorityQueue<int, Comparator<int>> pq;
    HeapPriorityQueue<int, Comparator<int>> pq2;
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
    std::list<int> lastFive; // Use a list to store the last 5 elements
    while (!pq.empty()) {
        int minVal = pq.min();
        lastFive.push_back(minVal);
        if (lastFive.size() > 5) {
            lastFive.pop_front();
        }
        pq.removeMin();
    }

    // Print the last 5 numbers
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
    std::list<int> lastFive2; // Use a list to store the last 5 elements
    while (!pq2.empty()) {
        int minVal = pq2.min();
        lastFive2.push_back(minVal);
        if (lastFive2.size() > 5) {
            lastFive2.pop_front();
        }
        pq2.removeMin();
    }

    // Print the last 5 numbers
    for (const int& val : lastFive2) {
        std::cout << val << " ";
    }

    end = clock();
    std::cout << "\nTime taken for large100k.txt sorting: " << end - start << " ms" << std::endl;

    return 0;
}
