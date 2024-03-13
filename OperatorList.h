#ifndef INC_1ST_PROJECT___CALCULATOR_OPERATORLIST_H
#define INC_1ST_PROJECT___CALCULATOR_OPERATORLIST_H

class OperatorList {
private:
    struct Node {
        char value;
        Node *nextNode;
    };
    Node *head;
    Node *tail;
    int size;
public:
    OperatorList() : head(nullptr), tail(nullptr), size(0) {

    };

    int get_front();

    void push_front(char newValue);

    void remove_front();

    int get_size();

    ~OperatorList();
};

#endif