// van.cpp

#include "van.hpp"
#include <iostream>

// Constructor
Van::Van(const std::string& vanAcronym) : top(nullptr), vipTop(nullptr), acronym(vanAcronym) {
    // Other constructor initialization, if any
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
    if (vipTop) {
        std::cout << "Unloading VIP packets: ";
        while (vipTop) {
            Node* temp = vipTop;
            std::cout << temp->data->id.packetNumber << " ";
            vipTop = temp->next;
            delete temp;
        }
        std::cout << std::endl;
    } else {
        std::cout << "No VIP packets to unload." << std::endl;
    }
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

// Implement the getAcronym function
std::string Van::getAcronym() const {
    return acronym;
}

// Function to get the number of packets in the van
int Van::getNumPackets() const {
    int count = 0;
    Van::Node* current = top;  // Assuming 'top' is the head of your linked list
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to move a packet from the current van to another van
void Van::movePacket(Van& vanDestination, int movedPacketNumber) {
    // Iterate through all packets in the current van
    Node* current = top;
    Node* prev = nullptr;  // Keep track of the previous node for unlinking

    while (current) {
        // Check if the packet number matches the one to be moved
        if (current->data->id.packetNumber == movedPacketNumber) {
            // Unlink the current node from the current van
            if (prev) {
                prev->next = current->next;
            } else {
                top = current->next;
            }

            // Load the packet into the destination van
            vanDestination.loadPacket(current->data);
            
            std::cout << "Packet with number " << movedPacketNumber << " moved from " << getAcronym() 
                      << " to " << vanDestination.getAcronym() << "\n";
            
            // Delete the node, but not the packet itself
            delete current;

            // Exit the loop after moving the packet
            break;
        }

        // Move to the next packet in the current van
        prev = current;
        current = current->next;
    }
}

// Function to unload a packet with a specific packet number from the van
void Van::unloadPacket(int packetNumber) {
    Node* current = top;
    Node* prev = nullptr;  // Keep track of the previous node for unlinking

    while (current) {
        if (current->data->id.packetNumber == packetNumber) {
            // Unlink the current node from the van
            if (prev) {
                prev->next = current->next;
            } else {
                top = current->next;
            }

            // Delete the node, but not the packet itself
            delete current;
            std::cout << "Packet with number " << packetNumber << " unloaded from " << getAcronym() << "\n";
            return;
        }

        // Move to the next packet in the van
        prev = current;
        current = current->next;
    }

    // If the function reaches here, the packet was not found in the van
    std::cout << "Packet with number " << packetNumber << " not found in " << getAcronym() << "\n";
}

// In van.cpp
void Van::deliver(Packets& destination) {
    // Iterate through all packets in the current van
    Node* current = top;
    Node* prev = nullptr;  // Keep track of the previous node for unlinking

    while (current) {
        // Unlink the current node from the current van
        if (prev) {
            prev->next = current->next;
        } else {
            top = current->next;
        }

        // Add the packet to the destination van
        //destination.addNode(convertVanNodeToPacketsNode(current));

        std::cout << "Packet with number " << current->data->id.packetNumber 
                  << " delivered"  << "\n";

        // Delete the node, but not the packet itself
        delete current;

        // Move to the next packet in the current van
        current = top;
    }
}

