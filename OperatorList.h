#ifndef INC_1ST_PROJECT___CALCULATOR_OPERATORLIST_H
#define INC_1ST_PROJECT___CALCULATOR_OPERATORLIST_H
class OperatorList{
private:
    struct Node{
        char value;
        Node* nextNode;
    };
    Node* head;
    Node* tail;
public:
    OperatorList(): head(nullptr), tail(nullptr){

    };

    int get_front();

    void push_front(char newValue);

    void remove_front();

    ~OperatorList();
};
#endif