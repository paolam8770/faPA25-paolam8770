//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) { // time complexity of o(logn) and space complexity of o(1)
        // TODO: insert index at end of heap, restore order using upheap()
        size++;
        int x = size - 1;
        weightArr[x] = idx;
        upheap(x, weightArr);
    }

    int pop(int weightArr[]) { // time complexity of o(logn) and space complexity of o(1)
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        size--;
        int x = size - 1;
        weightArr[x] = -1;
        downheap(x, weightArr);
        return weightArr[x];

      //  return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (pos > 0 && weightArr[pos] < weightArr[pos - 1] /2) {
            swap(data[pos], data[pos - 1]);
            pos = (pos - 1) /2;
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (pos > 0 && weightArr[pos] < weightArr[pos + 1] /2) {
            swap(data[pos], data[pos + 1]);
            pos = (pos + 1) /2;
        }
    }
};

#endif