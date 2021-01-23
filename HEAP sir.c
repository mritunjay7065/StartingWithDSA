# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <assert.h>

typedef struct heap_t *Heap;

struct heap_t {
    int *a;
    int length; // length of a
    int heapSize;
};

Heap newHeap(int *a, int length, int heapSize) {
    Heap heap = (Heap) calloc(1, sizeof(struct heap_t));
    heap->a = a;
    heap->length = length;
    heap->heapSize = heapSize;
    return heap;
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

int parent(int i) {
    return (i - 1) / 2;
}

void swap(int *pa, int *pb) {
    typeof (*pa) temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void maxHeapify(Heap heap, int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (heap->heapSize > l && heap->a[l] > heap->a[largest]) {
        largest = l;
    }
    if (heap->heapSize > r && heap->a[r] > heap->a[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(heap->a + i, heap->a + largest);
        maxHeapify(heap, largest);
    }
}

void buildMaxHeap(Heap heap) {
    for (int i = heap->heapSize / 2 - 1; i >= 0; i--) {
        maxHeapify(heap, i);
    }
}

void heapSort(int a[], int length) {
    Heap heap = newHeap(a, length, length);
    buildMaxHeap(heap);
    for (int i = length - 1; i > 0; i--) {
        swap(heap->a, heap->a + i);
        heap->heapSize--;
        maxHeapify(heap, 0);
    }
}

void printArray(int a[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

typedef Heap PriorityQueue;
# define SIZE 2

PriorityQueue newPriorityQueue() {
    PriorityQueue priorityQueue = (PriorityQueue) calloc(1, sizeof (struct heap_t));
    priorityQueue->length = SIZE;
    priorityQueue->heapSize = 0;
    priorityQueue->a = (int *) calloc(SIZE, sizeof (int));
    return priorityQueue;
}

int maximum(PriorityQueue priorityQueue) {
    if (priorityQueue->heapSize == 0) {
        return INT_MIN;
    }
    return priorityQueue->a[0];
}

int extractMaximum(PriorityQueue priorityQueue) {
    if (priorityQueue->heapSize == 0) {
        return INT_MIN;
    }
    int max = priorityQueue->a[0];
    priorityQueue->a[0] = priorityQueue->a[--priorityQueue->heapSize];
    maxHeapify(priorityQueue, 0);
    return max;
}

int increaseKey(PriorityQueue priorityQueue, int i, int key) {
    if (i >= priorityQueue->heapSize) {
        return -1;
    }
    if (priorityQueue->a[i] > key) {
        return -1;
    }
    priorityQueue->a[i] = key;
    int p = parent(i);
    while (i > 0 && priorityQueue->a[p] < priorityQueue->a[i]) {
        swap(priorityQueue->a + i, priorityQueue->a + p);
        i = p;
        p = parent(i);
    }
    return 0;
}

void insert(PriorityQueue priorityQueue, int key) {
    if (priorityQueue->heapSize == priorityQueue->length) {
        priorityQueue->length += SIZE;
        priorityQueue->a = (int *) realloc(priorityQueue->a, sizeof(int) * (priorityQueue->length));
        assert(priorityQueue->a); // The reallocation along with the assert confirms that we
        //now have enough space in priorityQueue->a
    }
    priorityQueue->a[priorityQueue->heapSize++] = INT_MIN; // insert -infinity at the end of the
    // heap as a new element
    increaseKey(priorityQueue, priorityQueue->heapSize - 1, key); // now increase the priority
    //of the index where we have inserted -infinity to "key"
}

int main(int argc, char *argv[]) {
    printf("Heap Sort\n");
    int a[] = {21, 80, 78, 35, 49, 70, 88, 56};
    int n = 8;
    heapSort(a, n);
    printArray(a, n);
    printf("\n");

    /* Priority Queue */
    printf("Priority Queue\n");
    PriorityQueue priorityQueue = newPriorityQueue();
    int b[] = {21, 80, 78, 35, 49, 70, 88, 56};
    int nb = 8;
    for (int i = 0; i < nb; i++) {
        insert(priorityQueue, b[i]);
    }
    for (int i = 0; i < nb + 1; i++) { // An additional extraction
        printf("%d ", extractMaximum(priorityQueue));
    }
    printf("\n");
}
