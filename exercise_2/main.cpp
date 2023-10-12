#include <iostream>
#include <fstream>
#include "ListPriorityQueue.h"

int main(int argc, char const *argv[])
{
    ListPriorityQueue<int, Comparator<int>> pq;
    ListPriorityQueue<int, Comparator<int>> pq2;
    int num = 0;
    int count = 5;

    //small1k.txt
    std::fstream small_inFile("C:/Users/jesus/GitHub/PriorityQueue/small1k.txt", std::ios_base::in);

    //large100k.txt
    std::fstream large_inFile("C:/Users/jesus/GitHub/PriorityQueue/large100k.txt", std::ios::in);


    //check if file is not open
    if(!small_inFile.is_open()) {
        std::cout << "Error: Unable to open file." << std::endl;
        return 1;
    }
    
    while(small_inFile >> num){
        pq.insert(num);
    }

    small_inFile.close();
    std::cout << "small1k.txt File: ";
    while(!pq.empty() && count--) {
        std::cout << pq.min() << " ";
        pq.removeMin();
    }

    std::cout << std::endl;
    count = 5;

    //check if file is not open
    if(!large_inFile.is_open()) {
        std::cout << "Error: Unable to open file." << std::endl;
        return 1;
    }

    while(large_inFile >> num) {
        pq2.insert(num);
    }

    large_inFile.close();
    std::cout << "large100k.txt File: ";
    while(!pq2.empty() && count--) {
        std::cout << pq.min() << " ";
        pq2.removeMin();
    }

    return 0;
}
