Basic Functionalities of Queue + Getting Smallest element currently in the queue in amortized O(1) time complexity.
The MinQueue uses two MinStacks to simulate the behaviour of a Queue.

Functionalities :

- push(x) : push element x at the back of the queue
- pop : remove an element from the front of the queue.
- top : return the element currently at the front of the queue.
- getMin : return the current smallest element in the queue.

Example Usage :
MinQueue < int > Q:
Q.push(5);
Q.push(3);
Q.push(10);
// currently Q looks like 5 -> 3 -> 10
// Q.getMin() returns 3.
