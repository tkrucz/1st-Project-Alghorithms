#ifndef INC_1ST_PROJECT___CALCULATOR_OPERANDLIST_H
#define INC_1ST_PROJECT___CALCULATOR_OPERANDLIST_H

class OperandList {
private:
    struct Node {
        int value;
        Node *nextNode;
    };
    Node *head;
    Node *tail;
    int size;
public:
    OperandList() : head(nullptr), tail(nullptr), size(0) {

    };

    int get_front();

    void push_front(int newValue);

    void remove_front();

    int get_size();

    ~OperandList();
};

#endif
