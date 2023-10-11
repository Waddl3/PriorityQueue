#include <iostream>
#include <fstream>
#include "ListPriorityQueue.h"

int main(int argc, char const *argv[])
{
    ListPriorityQueue<int, Comparator<int>> pq;
    int num = 0;
    int count = 5;

    std::fstream inFile("C:/Users/jesus/Documents/GitHub/PriorityQueue/small1k.txt", std::ios_base::in);

    if(!inFile.is_open()) {
        std::cout << "Error: Unable to open file." << std::endl;
        return 1;
    }
    
    while(inFile >> num){
        pq.insert(num);
    }

    inFile.close();

    while(!pq.empty() && count--) {
        std::cout << pq.min() << " ";
        pq.removeMin();
    }

    return 0;
}
