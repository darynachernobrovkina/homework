#include <iostream>

template <typename T>
class Node
{
public:
    T value;
    Node *prev;
    Node(T val, Node *ptr)
    {
        this->value = val;
        this->prev = ptr;
    }
};

template <typename T>
class Stack
{
private:
    Node<T> *top;

public:
    Stack()
    {
        this->top = new Node<T>(0, nullptr);
    }
    Stack(T value)
    {
        this->top = new Node<T>(value, nullptr);
    }
    void push(T value)
    {
        Node<T> *newNode = new Node<T>(value, this->top);
        this->top = newNode;
    }
    T pop()
    {
        if (this->top)
        {
            T result = this->top->value;
            this->top = this->top->prev;
            return result;
        }
    }
    void print()
    {
        Node<T> *tmp = this->top;
        while (tmp)
        {
            std::cout << tmp->value << " ";
            tmp = tmp->prev;
        }
        std::cout << std::endl;
    }
};

int endlessUntilZero(Stack<int> *stack)
{
    int val, counter = 0;
    do
    {
        std::cout << "Enter value - ";
        std::cin >> val;
        if (val != 0)
        {
            stack->push(val);
            counter += 1;
        }
    } while (val != 0);
    return counter;
}

int main()
{
    Stack<int> *stack = new Stack<int>();
    int len = endlessUntilZero(stack);

    stack->print();
    std::cout << "Len - " << len;
    // stack->push(2);
    // stack->push(3);
    // stack->push(4);
    // stack->print();

    // stack->pop();
    // stack->print();

    return 0;
}