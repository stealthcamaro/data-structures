#include <iostream>

/* singly linked list class with a value
   and reference to the nextNode */
class linkedlist {
    public:
    int value;
    linkedlist* nextNode;
};

/* printList is a function using a while loop
   to loop through an entire linked list until
   the last node is reached. The last node is
   identified by having no reference (NULL) in its
   nextNode reference object pointer*/
void printList(linkedlist* l){
    while(l != NULL){
        std::cout<< l->value << std::endl;
        l = l->nextNode;
    }
}

int main(){
    linkedlist* head = new linkedlist();
    linkedlist* travisscott = new linkedlist();
    linkedlist* drake = new linkedlist();

    head->value = 67;
    head->nextNode = travisscott;
    travisscott->value = 90210;
    travisscott->nextNode = drake;
    drake->value = 6;
    drake->nextNode = NULL;

    printList(head);
    delete head;
    delete travisscott;
    delete drake;
    return 0;
}