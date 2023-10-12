#ifndef HEAP_PQ_H
#define HEAP_PQ_H

#include <vector>
#include <stdexcept>

template<typename E>
class Comparator {
public:
    bool operator()(const E& p, const E& q) {
        return p < q;
    }
};

template <typename E, typename C>
class HeapPriorityQueue {
private:
    std::vector<E> T;
    C isLess;

public:
    int size() const {
        return T.size();
    }

    bool empty() const {
        return T.empty();
    }

    void insert(const E& e) {
        T.push_back(e);
        int i = T.size() - 1;

        while(i > 0) {
            int parent = (i - 1) / 2;
            if (isLess(T[i], T[parent])){
                std::swap(T[i], T[parent]);
                i = parent;
            }
            else {
                break;
            }
        }
    }

    const E& min() {
        return T.front();
    }

    void removeMin() {
        if (empty()) throw std::out_of_range("Priority queue is empty");

        int parent = 0;
        T[parent] = T.back();
        T.pop_back();

        while (true) {
            int left = parent * 2 + 1;
            int right = parent * 2 + 2;
            int smallest = parent;

            if (left < T.size() && isLess(T[left], T[smallest])) {
                smallest = left;
            }

            if (right < T.size() && isLess(T[right], T[smallest])) {
                smallest = right;
            }

            if (smallest != parent) {
                std::swap(T[parent], T[smallest]);
                parent = smallest;
            } else {
                break;
            }
        }
    }

};

#endif