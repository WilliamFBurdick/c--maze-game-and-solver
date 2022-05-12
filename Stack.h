#ifndef STACK_H
#define STACK_H
#include <cstdlib>

#include "Node.h"

using namespace std;

template <typename T1, typename T2>
class Stack {
    private:
        int size;
        Node<T1, T2> *top;
    public:
        Stack()
        {
            size = 0;
            top = nullptr;
        };
        ~Stack()
        {
            while (size > 0)
            {
                pop();
                top = nullptr;
            }
        }
        T1 peek1() {return top->getValue1();};
        T2 peek2() {return top->getValue2();};
        Node<T1, T2>* GetTop() { return top; };
        void pop()
        {
            if (size <= 0 || top == nullptr)
            {
                throw "ERROR: Stack is empty!";
            }
            else
            {
                size--;
                Node<T1, T2>* temp = top;
                top = top->getNext();
                free(temp);
            }
        };
        void push(T1 value1, T2 value2)
        {
            Node<T1, T2>* temp = top;
            top = new Node<T1, T2>(value1, value2, top);
            size++;
        };
        bool isEmpty() {return (size <= 0 || top == nullptr);};
        int GetSize() { return size; };
};

#endif