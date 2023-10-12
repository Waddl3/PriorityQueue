#ifndef VECTOR_COMPLETE_TREE_H
#define VECTOR_COMPLETE_TREE_H

#include <vector>

template <typename E>
class VectorCompleteTree {
private:
    // Member data
    std::vector<E> V; // Tree contents

public:
    // Publicly accessible types
    typedef typename std::vector<E>::iterator Position; // A position in the tree

protected:
    // Protected utility functions
    Position pos(int i) { return V.begin() + i; }  // Map an index to a position
    int idx(const Position& p) const { return p - V.begin(); } // Map a position to an index

public:
    // Constructor
    VectorCompleteTree() : V(1) {}

    // Get the size of the tree
    int size() const { return V.size() - 1; }

    // Get the left child of a position
    Position left(const Position& p) { return pos(2 * idx(p)); }

    // Get the right child of a position
    Position right(const Position& p) { return pos(2 * idx(p) + 1); }

    // Get the parent of a position
    Position parent(const Position& p) { return pos(idx(p) / 2); }

    // Check if a position has a left child
    bool hasLeft(const Position& p) const { return 2 * idx(p) <= size(); }

    // Check if a position has a right child
    bool hasRight(const Position& p) const { return 2 * idx(p) + 1 <= size(); }

    // Check if a position is the root of the tree
    bool isRoot(const Position& p) const { return idx(p) == 1; }

    // Get the position of the root
    Position root() { return pos(1); }

    // Get the position of the last element
    Position last() { return pos(size()); }

    // Add an element to the end of the tree
    void addLast(const E& e) { V.push_back(e); }

    // Remove the last element from the tree
    void removeLast() { V.pop_back(); }

    // Swap the elements at two positions
    void swap(const Position& p, const Position& q) {
        E e = *q;
        *q = *p;
        *p = e;
    }
};

#endif