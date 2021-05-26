Implementation of a priority queue using a max heap. To use the priority queue:

- include "MaxHeap.h" in your source file.
- declare a MaxHeap as "MaxHeap < myDataType > myMaxHeap(comparator)".
- you need to define a function comparator that accepts two objects of type myDataType and returns true if 1st compares less than 2nd object and false otherwise.
- the highest priority object(does not compare less than any other object in the heap) is the topmost item in the heap.

The following functionalities are provided:

- push(T obj) : inserts in the queue the item obj.
- pop() : deletes the highest priority item from the queue.
- top() : returns the highest priority item present in the queue.
- isEmpty() : return 1 if there is no element in the queue. 0 otherwise.
  example use: bool comparator(int x, int y) { return x < y; } MaxHeap < int > myMaxHeap(comparator); myMaxHeap.push(15);
