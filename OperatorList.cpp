#include "OperatorList.h"
#include "iostream"

using namespace std;

void OperatorList::push_front(char newValue) {
    Node *newNode = new Node;
    newNode->value = newValue;
    newNode->nextNode = nullptr;
    Node *previousNode = head;
    head = newNode;
    newNode->nextNode = previousNode;
    size += 1;
}

int OperatorList::get_front() {
    if (head != nullptr)
        return head->value;
    else {
        cerr << "OperandList is empty" << endl;
        return -1;
    }
}

void OperatorList::remove_front() {
    if (head != nullptr) {
        Node *tmp = head;
        head = head->nextNode;
        size -= 1;
        delete tmp;
    }
}

int OperatorList::get_size() {
    return size;
}

OperatorList::~OperatorList() {
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->nextNode;
        delete current;
        current = next;
    }
    cout << "OperandList memory released" << endl;
}