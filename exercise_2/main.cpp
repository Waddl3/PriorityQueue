#include <iostream>
#include <fstream>
#include "ListPriorityQueue.h"

int main(int argc, char const *argv[])
{
    ListPriorityQueue<int, Comparator<int>> pq;
    int num;

    std::ifstream inFile;
    inFile.open("small1k.txt", std::fstream::binary);

    while(inFile >> num){
        pq.insert(num);
    }

    inFile.close();

    while(!pq.empty()) {
        std::cout << pq.min() << " ";
        pq.removeMin();
    }

    return 0;
}
