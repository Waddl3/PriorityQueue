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
VectorCompleteTree<E> T;
C isLess;

typedef typename VectorCompleteTree<E>::Position Position;

public:
    //n elments
    int size() const { return T.size(); }

    //queue empty?
    bool empty() const { return size() == 0; }

    //insert elems
    void insert(const E& e) {
        T.addLast(e);   //add e to heap
        Position v = T.last();  //e's position
        while (!T.isRoot(v)) {  //up-heap bubbling
            Position u = T.parent(v);
            if(!isLess(*v, *u)) break;    //if v in order, we're done
            T.swap(v, u);                 //...else swap with parent
            v = u;
        }
    }

    //minimum elem
    const E& min() { return *(T.root()); }

    //remove minimum
    void removeMin(){
        if(size() == 1)         //only one node?
            T.removeLast();     //...remove it bro
        else {
            Position u = T.root();      //root position
            T.swap(u, T.last());        //swap last with root
            T.removeLast();             //...and remove last node

            while(T.hasLeft(u)) {       //down-heap bubbling
                Position v = T.left(u);
                if(T.hasRight(u) && isLess(*(T.right(u)), *v))
                    v = T.right(u);     //v is u's smaller child
                if(isLess(*v, *u)) {    //is u out of order?
                    T.swap(u, v);       //...then swap
                    u = v;
                }
                else break;             //else we're done
            }
        }
    }

};



#endif