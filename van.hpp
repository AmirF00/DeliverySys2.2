// van.hpp

#ifndef VAN_HPP
#define VAN_HPP

#include "packets.hpp"

class Van {
public:

    // Constructor with acronym
    Van(const std::string& vanAcronym);
    struct Node {
        Packets::Node* data;
        Node* next;
    };
    Node* top; // For regular packets
    Node* vipTop; // For VIP packets
    std::string getAcronym() const;
    // Function to get the number of packets in the van
    int getNumPackets() const;
    // Function to deliver packets to a destination van
    void deliver(Packets& destination);
    


private:
    static const int MAX_CAPACITY = 86;
    std::string acronym;
    

public:
    Van();  // Constructor
    ~Van(); // Destructor

    void loadPacket(Packets::Node* packet);
    void unloadPackets();
    void loadPacketVIP(Packets::Node* packet);
    void displayPackets() const;
    void unloadVIP();
    bool isFullyLoaded() const;
    bool isVIPFullyLoaded() const;
    bool isEmpty() const;
    bool isVIPEmpty() const;
    // Function to unload a packet with a specific packet number from the van
    void unloadPacket(int packetNumber);
    // Function to move a packet from the current van to another van
    void movePacket(Van& vanDestination, int movedPacketNumber);
    // Getters and setters
    //Node* getTop() const;
    void setTop(Node* newTop);
    Van::Node* getTop() const;

    Node* getVIPTop() const;
    void setVIPTop(Node* newTop);

    // Helper function to get the size of the stack
    int size() const;
    int VIPSize() const;
};

#endif // VAN_HPP
