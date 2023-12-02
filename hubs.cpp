// hubs.cpp

#include "hubs.hpp"

Hubs::Hubs() : root(nullptr) {
    // Constructor
}

Hubs::~Hubs() {
    // Destructor
    cleanupTree(root);
}

void Hubs::addPC(int postalCode, const std::string& acronym) {
    root = insert(root, postalCode, acronym);
}

Hubs::PC* Hubs::searchPC(int postalCode) {
    Node* result = root;
    while (result != nullptr) {
        if (postalCode < result->data.postalCode) {
            result = result->left;
        } else if (postalCode > result->data.postalCode) {
            result = result->right;
        } else {
            return &result->data;
        }
    }
    return nullptr;
}

void Hubs::displayPCs() {
    displayPCs(root);
}

int Hubs::getHeight(Node* node) {
    // Implementation
}

int Hubs::getBalance(Node* node) {
    // Implementation
}

Hubs::Node* Hubs::rotateRight(Node* y) {
    // Implementation
}

Hubs::Node* Hubs::rotateLeft(Node* x) {
    // Implementation
}

Hubs::Node* Hubs::insert(Node* node, int postalCode, const std::string& acronym) {
    // Implementation
}

Hubs::Node* Hubs::minValueNode(Node* node) {
    // Implementation
}

Hubs::Node* Hubs::deleteNode(Node* root, int postalCode) {
    // Implementation
}

void Hubs::displayPCs(Node* root) {
    // Implementation
}

void Hubs::cleanupTree(Node* root) {
    // Implementation
}
