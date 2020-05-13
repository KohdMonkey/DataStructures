/*
 * Implementation of minimum heap from the pseudocode in CLRS, slightly modified
 * The storage datastructure is a vector, and the heap allows expansion if capacity is reached
 */


#include <iostream>
#include "minheap.hpp"


MinHeap* newHeap() {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->heapSize = 0;
    heap->maxHapSize = 10;
    heap->heap.resize(heap->maxHapSize, -1);
    heap->heap[0] = INT32_MAX;
    return heap;
}


int parent(int i) {
    return i / 2;
}


int left(int i) {
    return (2 * i);
}


int right(int i) {
    return (2 * i) + 1;
}

/*
 * Starting at node i, determine the minimum between i and its two children
 * Swap the minimum with i, and recurse down the heap using minimum
 *
 */
void minHeapify(MinHeap* minHeap, int i) {
    std::vector<int>& heap = minHeap->heap;
    int l = left(i);
    int r = right(i);

    int smallest;

    // if smallest is left child
    if(l <= minHeap->heapSize && heap[l] < minHeap->heap[i])
        smallest = l;
    else
        smallest = i;

    // if smallest is right child
    if(r  <= minHeap->heapSize && heap[r] < heap[smallest])
        smallest = r;

    if(smallest != i) {
        std::swap(heap[smallest], heap[i]);
        minHeapify(minHeap, smallest);
    }
}


/*
 * If the elements in the vector are not in heap order, build the heap starting from a leaf
 */
void buildMinHeap(MinHeap* minHeap) {
    for(int i = minHeap->heapSize / 2; i >= 1; i--)
        minHeapify(minHeap, i);
}


/*
 * If the heap has reached capacity, expand the heap and initialize the new slots accordingly
 */
void expandHeap(MinHeap* minHeap) {
    minHeap->maxHapSize += 10;
    minHeap->heap.resize(minHeap->maxHapSize, -1);
}


/*
 * Insert a new value into the heap
 * 1. assign the value to the next position (at the end)
 * 2. recurse up from the current position to the children of the root, swapping with parent if smaller
 */
void insert(MinHeap* minHeap, int val) {
    std::vector<int>& heap = minHeap->heap;

    if((minHeap->heapSize + 1) == minHeap->maxHapSize) {
        expandHeap(minHeap);
    }

    minHeap->heapSize++;
    heap[minHeap->heapSize] = val;

    int i = minHeap->heapSize;

    while(i > 1 && heap[parent(i)] > heap[i]) {
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}


/*
 * Print the heap starting from the root
 */
void print(MinHeap* minHeap) {
    int size = minHeap->heapSize;
    for(int i = 1; i <= size/2; i++) {
        std::cout << "parent: " << minHeap->heap[i]
                  << " left child: " << minHeap->heap[left(i)]
                  << " right child: " << minHeap->heap[right(i)] << "\n";
    }
}
