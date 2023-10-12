#ifndef HEAP_PQ_H
#define HEAP_PQ_H

#include "VectorCompleteTree.h"

template <typename E>
class Comparator {
public:
    bool operator()(const E& p, const E& q) {
        return p < q;
    }
};

template<typename E, typename C>
class HeapPriorityQueue {
private:


public:

};



#endif