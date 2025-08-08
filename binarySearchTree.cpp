#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* leftChild;
    Node* rightChild;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->leftChild = nullptr;
    newNode->rightChild = nullptr;
    return newNode;
}

int main() {
    Node* root = createNode(1);
    root->leftChild = createNode(2);
    root->rightChild = createNode(3);
    root->leftChild->leftChild = createNode(4);

    return 0;
}