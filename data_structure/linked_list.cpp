#include <iostream>

struct Node {
    int data;
    Node *next;
};

class LinkedList {
    private:
        Node *head;
    public:
        LinkedList() {
            head = nullptr;
        }
        void addNode(int data);
        void insertAfter(Node* prevNode, int data);
        void deleteFirstNode();
        void deleteLastNode();
        void display();
};

void LinkedList::addNode(int data) {
    Node *node = new Node;
    node->data = data;
    node->next = head;
    head = node; 
}

void LinkedList::insertAfter(Node* prevNode, int data) {
    if (prevNode == nullptr) {
        std::cout << "Previous node is required.\n";
        return;
    }
    Node *node = new Node;
    node->data = data;
    node->next = prevNode->next;
    prevNode->next = node;
}

void LinkedList::display() {
    Node *ptr;
    ptr = head;
    while(ptr != nullptr) {
        std::cout << "data -> " << ptr->data << std::endl;
        ptr = ptr->next;
    };
}

void  LinkedList::deleteFirstNode() {
    if(head == nullptr) {
        return;
    }
    Node* tempNode = head;
    head = head->next;
    delete tempNode;
}

void  LinkedList::deleteLastNode() {
    if(head == nullptr) {
        return;
    }
    if(head->next == nullptr) {
        delete head;
        return;
    }
    Node* last = head;
    while(last->next->next != nullptr) {
        last = last->next;
    };
    delete last->next;
    last->next = nullptr;
}


int main() {
    LinkedList list;
    list.addNode(1);
    list.addNode(4);
    list.addNode(9);
    list.addNode(45);
    list.addNode(5);
    list.deleteFirstNode();
    list.deleteLastNode();
    list.display();
    return 0;
}