#ifndef NODE_H
#define NODE_H

using namespace std;

template <typename T1, typename T2>
class Node {
    private:
        T1 value1;
        T2 value2;
        Node<T1, T2>* next;
    public:
        Node(T1 _value1, T2 _value2, Node* _next)
        {
            value1 = _value1;
            value2 = _value2;
            next = _next;
        };
        T1 getValue1() { return value1; };
        T2 getValue2() { return value2; };
        Node* getNext() { return next; };
        void setNext(Node* _next) { next = _next; };
};

#endif