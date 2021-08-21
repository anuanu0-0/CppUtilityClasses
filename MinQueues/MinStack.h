/*
    * Design a stack class to support push, pop, empty, size, top & getMin operations.
    * All operations must be in O(1)
    * Use vector as underlying container for the stack. 
*/

#ifndef MINSTACK_H
#define MINSTACK_H
#include<vector>

using namespace std;

template<class T>
class MinStack{
    /*
        Creating 2 vectors, one for main stack and one auxilary stack for keeping
        track of the min elements. The aux stack stores only upcoming equal or lower values
        and thus maintains min element at the top of the stack.
    */
private:
    vector<int>mstack, aux;
public: 
    // Get the top of the stack
    T top();
    // Get the minimum element currently in the stack
    T getMin();
    // Push x on top of stack
    void push(T x);
    // Remove topmost element from the stack
    void pop();
    // Check if the stack is empty 
    bool empty(){
        return mstack.empty(); 
    }
    // Return the size of the stack
    int size(){
        return mstack.size();
    }
};

template<class T>
void MinStack<T>::push(T x){
    /*
        Push the element in the main stack
        If the aux stack is empty i.e for the first element, push on both the stacks
        Else push on aux stack only when it is smaller or equal to the current min in aux stack
    */
    mstack.push_back(x);
    if(aux.empty() || aux.back() >= mstack.back())
        aux.push_back(x);
}

template<class T>
void MinStack<T>::pop(){
    /*
        If the stack is not empty and top element of main stack & aux stack are same 
        then remove the top elements from both the stack.
        Else remove from only main stack
    */
    if(!mstack.empty()) {
        if(mstack.back() == aux.back())
            aux.pop_back();
        mstack.pop_back();
    }
}

template<class T>
T MinStack<T>::top(){
    // Return the topmost element of main stack.
    if(mstack.empty())
        throw *new Exception;
    
    return mstack.back();
}

template<class T>
T MinStack<T>::getMin(){
    // Return the topmost element of aux stack.
    if(aux.empty())
        throw *new Exception;
    
    return aux.back();
}

#endif // MINSTACK_H
