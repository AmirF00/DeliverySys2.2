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



Hubs::PC* Hubs::searchPCPostOrder(Node* root, int postalCode) {
    if (root == nullptr) {
        return nullptr;
    }

    // Search in the left subtree
    Hubs::PC* leftResult = searchPCPostOrder(root->left, postalCode);
    if (leftResult != nullptr) {
        return leftResult;
    }

    // Search in the right subtree
    Hubs::PC* rightResult = searchPCPostOrder(root->right, postalCode);
    if (rightResult != nullptr) {
        return rightResult;
    }

    // Check the current node
    if (postalCode == root->data.postalCode) {
        return &root->data;
    }

    return nullptr;
}

void Hubs::displayPCs() {
    displayPCs(root);
}

#include "hubs.hpp"

// Other functions...

int Hubs::getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int Hubs::getBalance(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

Hubs::Node* Hubs::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Hubs::Node* Hubs::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Hubs::Node* Hubs::insert(Node* node, int postalCode, const std::string& acronym) {
    if (node == nullptr) {
        Node* newNode = new Node{PC{postalCode, acronym}, nullptr, nullptr, 1};
        return newNode;
    }

    if (postalCode < node->data.postalCode) {
        node->left = insert(node->left, postalCode, acronym);
    } else if (postalCode > node->data.postalCode) {
        node->right = insert(node->right, postalCode, acronym);
    } else {
        // Duplicate keys are not allowed
        return node;
    }

    // Update height of the current node
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    // Get the balance factor
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && postalCode < node->left->data.postalCode) {
        return rotateRight(node);
    }

    // Right Right Case
    if (balance < -1 && postalCode > node->right->data.postalCode) {
        return rotateLeft(node);
    }

    // Left Right Case
    if (balance > 1 && postalCode > node->left->data.postalCode) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && postalCode < node->right->data.postalCode) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

Hubs::Node* Hubs::minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Hubs::Node* Hubs::deleteNode(Node* root, int postalCode) {
    if (root == nullptr) {
        return root;
    }

    if (postalCode < root->data.postalCode) {
        root->left = deleteNode(root->left, postalCode);
    } else if (postalCode > root->data.postalCode) {
        root->right = deleteNode(root->right, postalCode);
    } else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;

            // No child case
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                // One child case
                *root = *temp;
            }

            delete temp;
        } else {
            // Node with two children: Get the inorder successor
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data.postalCode);
        }
    }

    // If the tree had only one node, then return
    if (root == nullptr) {
        return root;
    }

    // Update height of the current node
    root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));

    // Get the balance factor
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rotateRight(root);
    }

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0) {
        return rotateLeft(root);
    }

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void Hubs::displayPCs(Node* root) {
    if (root != nullptr) {
        displayPCs(root->left);
        std::cout << "Postal Code: " << root->data.postalCode << ", Acronym: " << root->data.acronym << std::endl;
        displayPCs(root->right);
    }
}

void Hubs::cleanupTree(Node* root) {
    if (root != nullptr) {
        cleanupTree(root->left);
        cleanupTree(root->right);
        delete root;
    }
}

Hubs::Node* Hubs::getRoot() const {
    return root;
}



