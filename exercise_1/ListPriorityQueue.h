#ifndef LIST_PRIORITY_QUEUE_H
#define LIST_PRIORITY_QUEUE_H

#include <list>

template <typename E, typename C>
class ListPriorityQueue {

private:
std::list<E> L;
C isLess;

public:

    //We do not bother to give an explicit consturcotor for our class,
    //relying instead on default constructor
        //Default constructor fro the STL list produces an empty list,
        //which is exactly what we want.

    //insert an entry e
    void insert(const E& e) {
        auto p = L.begin();

        while(p != L.end() && !isLess(e, *p)) ++p;
        L.insert(p, e);
    }

    //removes the entry with smallest key
    void removeMin() {

    }

    //returns, but does NOT remove, an entry with smallest key.
    const E& min() const {

    }

    //number of elements
    int size() const {
        return L.size();
    }

    //check if queue if empty
    bool empty() const {
        return L.empty();
    }

};

#endif