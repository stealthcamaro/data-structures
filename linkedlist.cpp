#include <iostream>

/* singly linked list class with a value
   and reference to the nextNode. */
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
        std::cout << l->value << std::endl;
        l = l->nextNode;
    }
}

// Insert a new node at the end of the linked list
void insertNode(linkedlist*& head, int val) {
    linkedlist* newNode = new linkedlist();
    newNode->value = val;
    newNode->nextNode = NULL;

    // If list is empty, new node becomes the head
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Otherwise, traverse to the last node
    linkedlist* temp = head;
    while (temp->nextNode != NULL) {
        temp = temp->nextNode;
    }
    temp->nextNode = newNode;
}

// Delete the first occurrence of a value from the linked list
void deleteNode(linkedlist*& head, int val) {
    if (head == NULL) {
        std::cout << "List is empty.\n";
        return;
    }

    // If the head node is the one to delete
    if (head->value == val) {
        linkedlist* temp = head;
        head = head->nextNode;
        delete temp;
        std::cout << "Value deleted.\n";
        return;
    }

    // Otherwise, search for the node before the one to delete
    linkedlist* current = head;
    while (current->nextNode != NULL && current->nextNode->value != val) {
        current = current->nextNode;
    }

    // If value not found
    if (current->nextNode == NULL) {
        std::cout << "Value not found.\n";
        return;
    }

    // Unlink and delete the node
    linkedlist* temp = current->nextNode;
    current->nextNode = current->nextNode->nextNode;
    delete temp;
    std::cout << "Value deleted.\n";
}

// Free all nodes in the linked list to avoid memory leaks
void freeList(linkedlist*& head) {
    while (head != NULL) {
        linkedlist* temp = head;
        head = head->nextNode;
        delete temp;
    }
}

int main(){
    linkedlist* head = NULL; // Start with an empty list
    int choice, value;

    do {
        std::cout << "\n++++++ Linked List Menu ++++++\n";
        std::cout << "1. Insert Node\n";
        std::cout << "2. Delete Node\n";
        std::cout << "3. Print List\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                insertNode(head, value);
                std::cout << "Value inserted.\n";
                break;
            case 2:
                std::cout << "Enter value to delete: ";
                std::cin >> value;
                deleteNode(head, value);
                break;
            case 3:
                std::cout << "Current Linked List:\n";
                printList(head);
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    // Clean up memory before exiting
    freeList(head);
    return 0;
}
