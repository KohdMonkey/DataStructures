#include <vector>


struct MinHeap {
    std::vector<int> heap;
    int heapSize;
    int maxHapSize;
};


MinHeap* newHeap();


int parent(int i);
int left(int i);
int right(int i);


void minHeapify(MinHeap* minHeap, int i);
void buildMinHeap(MinHeap* minHeap);
void insert(MinHeap* minHeap, int val);
void print(MinHeap* minHeap);
void expandHeap(MinHeap* minHeap);
