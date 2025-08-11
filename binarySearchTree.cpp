#include <iostream>
using namespace std;

// Structure for a tree node
struct Node {
    int data;
    Node* leftChild;
    Node* rightChild;
};

// Create a new node with given data
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->leftChild = nullptr;
    newNode->rightChild = nullptr;
    return newNode;
}

// Insert a value into the BST
Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);
    }
    if (data < root->data) {
        root->leftChild = insertNode(root->leftChild, data);
    }
    else if (data > root->data) {
        root->rightChild = insertNode(root->rightChild, data);
    }
    return root;
}

// Search for a specific value in the BST
bool searchNode(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == key) {
        return true;
    }
    if (key < root->data) {
        return searchNode(root->leftChild, key);
    } else {
        return searchNode(root->rightChild, key);
    }
}

// Find the node with the smallest value
Node* findMin(Node* root) {
    while (root->leftChild != nullptr) {
        root = root->leftChild;
    }
    return root;
}

// Delete a node from the BST
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }
    if (key < root->data) {
        root->leftChild = deleteNode(root->leftChild, key);
    }
    else if (key > root->data) {
        root->rightChild = deleteNode(root->rightChild, key);
    }
    else {
        // Case 1: No child
        if (root->leftChild == nullptr && root->rightChild == nullptr) {
            delete root;
            return nullptr;
        }
        // Case 2: One child
        else if (root->leftChild == nullptr) {
            Node* temp = root->rightChild;
            delete root;
            return temp;
        }
        else if (root->rightChild == nullptr) {
            Node* temp = root->leftChild;
            delete root;
            return temp;
        }
        // Case 3: Two children
        Node* temp = findMin(root->rightChild);
        root->data = temp->data;
        root->rightChild = deleteNode(root->rightChild, temp->data);
    }
    return root;
}

// Print BST in-order (sorted order)
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->leftChild);
        cout << root->data << " ";
        inorderTraversal(root->rightChild);
    }
}

int main() {
    Node* root = nullptr;
    int choice, value;

    do {
        cout << "\n------ Binary Search Tree Menu ------\n";
        cout << "1. Insert Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Search Node\n";
        cout << "4. Print In-order Traversal\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insertNode(root, value);
                cout << "Value inserted.\n";
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                cout << "Value deleted (if it existed).\n";
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (searchNode(root, value))
                    cout << "Value found in BST.\n";
                else
                    cout << "Value not found.\n";
                break;
            case 4:
                cout << "BST In-order: ";
                inorderTraversal(root);
                cout << endl;
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
