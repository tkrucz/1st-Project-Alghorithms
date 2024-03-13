#include "OperandList.h"
#include "iostream"

using namespace std;

void OperandList::push_front(int newValue) {
    Node *newNode = new Node;
    newNode->value = newValue;
    newNode->nextNode = nullptr;
    Node *previousNode = head;
    head = newNode;
    newNode->nextNode = previousNode;
    size += 1;
}

int OperandList::get_front() {
    if (head != nullptr)
        return head->value;
    else {
        cerr << "OperandList is empty" << endl;
        return -1;
    }
}

void OperandList::remove_front() {
    if (head != nullptr) {
        Node *tmp = head;
        head = head->nextNode;
        size -= 1;
        delete tmp;
    }
}

int OperandList::get_size() {
    return size;
}

OperandList::~OperandList() {
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->nextNode;
        delete current;
        current = next;
    }
    cout << "OperandList memory released" << endl;
}