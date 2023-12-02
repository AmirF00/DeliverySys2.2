// hubs.hpp

#ifndef HUBS_HPP
#define HUBS_HPP

#include <iostream>

class Hubs {
public:
    struct PC {
        int postalCode;
        std::string acronym;
        // ... (other fields)
    };
    struct Node {
        PC data;
        Node* left;
        Node* right;
        int height;
    };
    Node* root;

private:
    

    

public:
    Hubs();
    ~Hubs();

    void addPC(int postalCode, const std::string& acronym);
    PC* searchPC(int postalCode);
    PC* searchPCPostOrder(Node* root, int postalCode);
    void displayPCs();
    // Function to get the root of the AVL tree
    Node* getRoot() const;

private:
    // AVL tree functions
    int getHeight(Node* node);
    int getBalance(Node* node);
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    Node* insert(Node* node, int postalCode, const std::string& acronym);
    Node* minValueNode(Node* node);
    Node* deleteNode(Node* root, int postalCode);
    void displayPCs(Node* root);
    void cleanupTree(Node* root);
};

#endif // HUBS_HPP
