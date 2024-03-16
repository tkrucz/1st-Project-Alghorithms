#ifndef INC_1ST_PROJECT___CALCULATOR_LIST_H
#define INC_1ST_PROJECT___CALCULATOR_LIST_H

template<typename T>
class List {
private:
    struct Node {
        T value;
        Node *nextNode;
    };
    Node *head;
    Node *tail;
    int size;
public:
    List() : head(nullptr), tail(nullptr), size(0) {
    };

    T &get_front() {
        return head->value;
    }

    void push_front(T newValue) {
        Node *newNode = new Node;
        newNode->value = newValue;
        newNode->nextNode = nullptr;
        if (head == nullptr)
            tail = newNode;
        else {
            Node *previousNode = head;
            newNode->nextNode = previousNode;
        }
        head = newNode;
        size += 1;
    }

    void push_back(T newValue) {
        Node *newNode = new Node;
        newNode->value = newValue;
        newNode->nextNode = nullptr;
        if (head == nullptr)
            head = newNode;
        else
            tail->nextNode = newNode;
        tail = newNode;
        size += 1;
    }

    T remove_front() {
        T ret;

        Node *tmp = head;
        head = head->nextNode;
        if (head == nullptr)
            tail = nullptr;
        ret = tmp->value;
        delete tmp;
        size -= 1;

        return ret;
    }

    int getSize() {
        return size;
    }

    ~List() {
        Node *current = head;
        while (current != nullptr) {
            Node *next = current->nextNode;
            delete current;
            current = next;
        }
    }
};

#endif
