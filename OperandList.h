#ifndef INC_1ST_PROJECT___CALCULATOR_OPERANDLIST_H
#define INC_1ST_PROJECT___CALCULATOR_OPERANDLIST_H
class OperandList{
private:
    struct Node{
        int value;
        Node* nextNode;
    };
    Node* head;
    Node* tail;
public:
    OperandList(): head(nullptr), tail(nullptr){

    };

    int get_front();

    void push_front(int newValue);

    void remove_front();

    ~OperandList();
};
#endif
