// van.cpp

#include "van.hpp"
#include <iostream>

Van::Van() : top(nullptr), vipTop(nullptr) {
    // Constructor
}

Van::~Van() {
    // Destructor
    unloadPackets(); // Unload any remaining packets
    unloadVIP();     // Unload any remaining VIP packets
}

void Van::loadPacket(Packets::Node* packet) {
    if (isFullyLoaded()) {
        std::cout << "Van is fully loaded. Cannot load more packets." << std::endl;
        return;
    }

    Node* newNode = new Node{packet, top};
    top = newNode;
    std::cout << "Packet " << packet->id.packetNumber << " loaded into the van." << std::endl;
}

void Van::unloadPackets() {
    while (top) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

void Van::loadPacketVIP(Packets::Node* packet) {
    // Load VIP packet into the special VIP van
    if (isVIPFullyLoaded()) {
        std::cout << "VIP Van is fully loaded. Cannot load more VIP packets." << std::endl;
        return;
    }

    Node* newNode = new Node{packet, vipTop};
    vipTop = newNode;
    std::cout << "VIP Packet " << packet->id.packetNumber << " loaded into the VIP van." << std::endl;
}

void Van::unloadVIP() {
    std::cout << "Unloading VIP packets: ";
    while (vipTop) {
        Node* temp = vipTop;
        std::cout << temp->data->id.packetNumber << " ";
        vipTop = temp->next;
        delete temp;
    }
    std::cout << std::endl;
}

bool Van::isFullyLoaded() const {
    return size() == MAX_CAPACITY;
}

bool Van::isVIPFullyLoaded() const {
    return VIPSize() == MAX_CAPACITY;
}

bool Van::isEmpty() const {
    return top == nullptr;
}

bool Van::isVIPEmpty() const {
    return vipTop == nullptr;
}

// Getter and setter for top
Van::Node* Van::getTop() const {
    return top;
}

void Van::setTop(Node* newTop) {
    top = newTop;
}

// Getter and setter for vipTop
Van::Node* Van::getVIPTop() const {
    return vipTop;
}

void Van::setVIPTop(Node* newTop) {
    vipTop = newTop;
}

// Helper function to get the size of the stack
int Van::size() const {
    int count = 0;
    Node* current = top;
    while (current) {
        ++count;
        current = current->next;
    }
    return count;
}

// Helper function to get the size of the VIP stack
int Van::VIPSize() const {
    int count = 0;
    Node* current = vipTop;
    while (current != nullptr) {
        ++count;
        current = current->next;
    }
    return count;
}

// Display all packets in the van
void Van::displayPackets() const {
    Node* current = top;

    while (current) {
        std::cout << "Packet ID: " << current->data->id.packetNumber << "\n";
        current = current->next;
    }
}

