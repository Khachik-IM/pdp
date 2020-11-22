#include <iostream>

#define MAX 100

class Stack {
    private:
        int top;
        int arr[MAX];
    public:

    Stack() {top = -1;};
    bool push(int val);
    int pop();
    bool isEmpty();
};

bool Stack::push(int val) {
    if(this->top >= (MAX - 1)) {
        std::cout << "Stack overflow.\n";
        return false;
    };
    this->arr[++top] = val;
    return true;
}

int Stack::pop() {
    if(this->top < 0) {
        std::cout << "Stack overflow.\n";
        return 0;
    };
    int returnValue = arr[top--];
    return  returnValue;
}

bool Stack::isEmpty() {
    return (top < 0);
}

int main() {
    Stack stack;
    stack.push(5);
    stack.push(10);
    stack.push(56);
    stack.push(2);
    std::cout << "Pop - " << stack.pop() << std::endl;
    return 0;
}