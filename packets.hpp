#ifndef PACKETS_HPP
#define PACKETS_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

struct PacketID {
    int packetNumber;
    std::string randomDigits;
    char randomLetter;
    std::string classificationDate;
    std::string townCodes;
};

struct GPSCoordinates {
    int degrees;
    int minutes;
    double seconds;
};

class Packets {
public:
    struct Node {
        PacketID id;
        GPSCoordinates longitude;
        GPSCoordinates latitude;
        std::string clientID;
        Node* prev;
        Node* next;
    };
private:
    Node* head;
    Node* tail;
    int packetCount;

public:
    // Constructor
    Packets();

    // Destructor
    ~Packets();

    // Function to add a packet to the list
    void addPacket();

    // Function to display all packets in the list
    void displayPackets();

    // Function to display all packets in reverse order
    void displayReversePackets();

    // Function to insert a packet at a specific position
    void insertPacketAtPosition(int position);

    // Function to delete a packet at a specific position
    void deletePacketAtPosition(int position);

    // Function to search for a packet by packet number
    Node* searchPacketByNumber(int packetNumber);

    // Function to peek at the front packet
    Node* peekFront();

    // Function to peek at the end packet
    Node* peekEnd();

    // Getter functions
    int getPacketCount() const;
    Node* getHead() const;
    Node* getTail() const;

    // Setter functions
    void setHead(Node* newHead);
    void setTail(Node* newTail);
    void setPacketCount(int newPacketCount);
    void movePacketToVIPList(int packetNumber, Packets& packetVIP);
    // Function to display a specific packet by packet number
    void displayPacketByNumber(int packetNumber);

private:
    // Helper function to generate a random date after 2020
    std::string generateRandomDate();

    // Helper function to select a town code at random
    std::string getRandomTownCode();
};

#endif // PACKETS_HPP
