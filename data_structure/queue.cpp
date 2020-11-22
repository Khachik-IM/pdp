#include <iostream>
#include <cstdlib>
using namespace std;
 
#define SIZE 10
 
class queue
{
    int *arr;       
    int capacity;
    int front;
    int rear;
    int count;
 
public:
    queue(int size = SIZE);
    ~queue();
 
    void dequeue();
    void enqueue(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

queue::queue(int size) {
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

 
queue::~queue() {
    delete[] arr;
}

// Utility function to remove front element from the queue
void queue::dequeue() {
    if (isEmpty()) {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    cout << "Removing " << arr[front] << '\n';
 
    front = (front + 1) % capacity;
    count--;
}
 
// Utility function to add an item to the queue
void queue::enqueue(int item) {
    if (isFull()) {
        cout << "OverFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    cout << "Inserting " << item << '\n';
 
    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

int queue::size() {
    return count;
}
 
bool queue::isEmpty() {
    return (size() == 0);
}
 
// Utility function to check if the queue is full or not
bool queue::isFull() {
    return (size() == capacity);
}

int main() {
    queue q(5);
 
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.enqueue(4);
    cout << "Queue size is " << q.size() << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    
    if (q.isEmpty()) {
        cout << "Queue Is Empty\n";
    } else {
        cout << "Queue Is Not Empty\n";
    }
    return 0;
}