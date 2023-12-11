#include "packets.hpp"

// Constructor
Packets::Packets() : head(nullptr), tail(nullptr), packetCount(0) {
    // Initialize random seed
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

/*
 * 
 * // Destructor
Packets::~Packets() {
    Node* current = head;
    Node* next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}
 * 
 * 
 * */

Packets::~Packets() {
    // Implement the destructor if needed
    // Make sure to delete allocated memory for packets
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current->next; // Assuming Packet has dynamic memory that needs to be freed
        delete current;
        current = next;
    }
}

// Function to add a packet to the list
void Packets::addPacket() {
    // Create a new packet
    Node* newNode = new Node;
    
    // Increment packet number
    ++packetCount;

    // Set packet ID
    newNode->id.packetNumber = packetCount;
    newNode->id.randomDigits = std::to_string(100 + std::rand() % 900);
    newNode->id.randomLetter = 'A' + std::rand() % 26;
    newNode->id.classificationDate = generateRandomDate();
    newNode->id.townCodes = getRandomTownCode();

    // Set GPS coordinates for longitude
    newNode->longitude.degrees = 40 + (rand() % 10);
    newNode->longitude.minutes = 28 + (rand() % 60);
    newNode->longitude.seconds = 30.0 + (rand() % 60);

    // Set GPS coordinates for latitude
    newNode->latitude.degrees = 28 + (rand() % 10);
    newNode->latitude.minutes = 20 + (rand() % 60);
    newNode->latitude.seconds = 45.0 + (rand() % 60);

    // Set client ID
    newNode->clientID = std::to_string(std::rand() % 10000000) + static_cast<char>('A' + std::rand() % 26);

    // Update links
    newNode->prev = tail;
    newNode->next = nullptr;

    if (tail != nullptr) {
        tail->next = newNode;
    } else {
        // The list is empty, set the head
        head = newNode;
    }

    // Update tail
    tail = newNode;
}

// Function to display all packets in the list
void Packets::displayPackets() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << "Packet Number: " << current->id.packetNumber << "\n";
        std::cout << "Packet ID: " << current->id.packetNumber << "-"
                  << current->id.randomDigits << current->id.randomLetter
                  << "-" << current->id.classificationDate
                  << "-" << current->id.townCodes << "\n";
        std::cout << "Longitude: " << current->longitude.degrees << "º "
                  << current->longitude.minutes << "' " << current->longitude.seconds << "\"\n";
        std::cout << "Latitude: " << current->latitude.degrees << "º "
                  << current->latitude.minutes << "' " << current->latitude.seconds << "\"\n";
        std::cout << "Client ID: " << current->clientID << "\n\n";

        current = current->next;
    }
}

// Function to check if the number of packets is divisible by 87 and display all packets
void Packets::displayPacketsIfDivisibleBy87() {
    int packetCount = 0;
    Node* current = head;

    // Count the number of packets
    while (current != nullptr) {
        packetCount++;
        current = current->next;
    }

    // Check if the number of packets is divisible by 87
    if (packetCount % 87 == 0) {
        std::cout << "Number of packets is divisible by 87. Displaying all packets:\n";
        displayPackets();  // Use the existing displayPackets function
    } else {
        std::cout << "Number of packets is not divisible by 87.\n";
    }
}


// Function to display all packets in reverse order
void Packets::displayReversePackets() {
    Node* current = tail;
    while (current != nullptr) {
        std::cout << "Packet Number: " << current->id.packetNumber << "\n";
        std::cout << "Packet ID: " << current->id.packetNumber << "-" << current->id.randomDigits
                  << "-" << current->id.randomLetter << "-" << current->id.classificationDate
                  << "-" << current->id.townCodes << "\n";
        std::cout << "Longitude: " << current->longitude.degrees << "º "
                  << current->longitude.minutes << "' " << current->longitude.seconds << "\"\n";
        std::cout << "Latitude: " << current->latitude.degrees << "º "
                  << current->latitude.minutes << "' " << current->latitude.seconds << "\"\n";
        std::cout << "Client ID: " << current->clientID << "\n\n";

        current = current->prev;
    }
}

// Function to insert a packet at a specific position
void Packets::insertPacketAtPosition(int position) {
    if (position < 1 || position > packetCount + 1) {
        std::cout << "Invalid position for insertion.\n";
        return;
    }

    // Create a new packet
    Node* newNode = new Node;

    // Increment packet number
    ++packetCount;

    // Set packet attributes (similar to addPacket)

    // Update links
    if (position == 1) {
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            // The list is empty, set the tail
            tail = newNode;
        }
        head = newNode;
    } else if (position == packetCount) {
        newNode->prev = tail;
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
    } else {
        Node* current = head;
        for (int i = 1; i < position - 1; ++i) {
            current = current->next;
        }
        newNode->prev = current;
        newNode->next = current->next;
        current->next->prev = newNode;
        current->next = newNode;
    }
}

// Function to delete a packet at a specific position
void Packets::deletePacketAtPosition(int position) {
    if (position < 1 || position > packetCount) {
        std::cout << "Invalid position for deletion.\n";
        return;
    }

    Node* current = head;

    if (position == 1) {
        head = current->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            // The list is empty, set the tail to nullptr
            tail = nullptr;
        }
    } else if (position == packetCount) {
        current = tail;
        tail = current->prev;
        tail->next = nullptr;
    } else {
        for (int i = 1; i < position; ++i) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    delete current;
    --packetCount;
}

// Function to search for a packet by packet number
Packets::Node* Packets::searchPacketByNumber(int packetNumber) {
    Node* current = head;
    while (current != nullptr) {
        if (current->id.packetNumber == packetNumber) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Function to peek at the front packet
Packets::Node* Packets::peekFront() {
    return head;
}

// Function to peek at the end packet
Packets::Node* Packets::peekEnd() {
    return tail;
}

// Getter functions
int Packets::getPacketCount() const {
    return packetCount;
}

Packets::Node* Packets::getHead() const {
    return head;
}

Packets::Node* Packets::getTail() const {
    return tail;
}

// Setter functions
void Packets::setHead(Node* newHead) {
    head = newHead;
}

void Packets::setTail(Node* newTail) {
    tail = newTail;
}

void Packets::setPacketCount(int newPacketCount) {
    packetCount = newPacketCount;
}

// Helper function to generate a random date after 2020
std::string Packets::generateRandomDate() {
    int day = 1 + std::rand() % 31;
    int month = 1 + std::rand() % 12;
    int year = 2020 + std::rand() % 3; // Random year between 2020 and 2022

    return std::to_string(day) +  std::to_string(month) + std::to_string(year);
}

// Helper function to select a town code at random
// Helper function to select a town code at random
std::string Packets::getRandomTownCode() {
    const std::string townCodes[] = {"ADT", "PER", "ROD", "VDT", "CDV", "MOZ", "CDB", "ALD", "SAL"};
    const std::string postalCodes[] = {"37115", "37427", "37449", "37893", "37797", "37796", "37129", "37340", "37002"};

    int index = std::rand() % 9;
    return postalCodes[index];
}


void Packets::movePacketToVIPList(int packetNumber, Packets& packetVIP) {
    Node* current = head;

    // Search for the packet in the original list
    while (current != nullptr) {
        if (current->id.packetNumber == packetNumber) {
            // Create a new packet in the VIP list
            packetVIP.addPacket();
            Packets::Node* newVIPPacket = packetVIP.peekEnd();

            // Copy data from the original packet to the VIP packet
            newVIPPacket->id = current->id;
            newVIPPacket->longitude = current->longitude;
            newVIPPacket->latitude = current->latitude;
            newVIPPacket->clientID = current->clientID;

            // Delete the packet from the original list
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                // The packet is at the head
                head = current->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                } else {
                    // The list is empty, set the tail to nullptr
                    tail = nullptr;
                }
            }

            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                // The packet is at the tail
                tail = current->prev;
                if (tail != nullptr) {
                    tail->next = nullptr;
                } else {
                    // The list is empty, set the head to nullptr
                    head = nullptr;
                }
            }

            // Delete the current node
            delete current;
            --packetCount;

            // Exit the loop once the packet is found and processed
            break;
        }
        
        // Add this line at various points to trace the flow
        std::cout << "Debug: MOVING packet " << current->id.packetNumber << std::endl;

        current = current->next;
    }
}

// Function to display a specific packet by packet number
void Packets::displayPacketByNumber(int packetNumber) {
    Node* current = head;
    
    while (current != nullptr) {
        if (current->id.packetNumber == packetNumber) {
            std::cout << "Packet Number: " << current->id.packetNumber << "\n";
            std::cout << "Packet ID: " << current->id.packetNumber << "-"
                      << current->id.randomDigits << current->id.randomLetter
                      << "-" << current->id.classificationDate
                      << "-" << current->id.townCodes << "\n";
            std::cout << "Longitude: " << current->longitude.degrees << "º "
                      << current->longitude.minutes << "' " << current->longitude.seconds << "\"\n";
            std::cout << "Latitude: " << current->latitude.degrees << "º "
                      << current->latitude.minutes << "' " << current->latitude.seconds << "\"\n";
            std::cout << "Client ID: " << current->clientID << "\n\n";
            return; // Exit the loop once the packet is found
        }

        current = current->next;
    }

    // If the packet with the given number is not found
    std::cout << "Packet with number " << packetNumber << " not found.\n";
}

// Inside packets.cpp, add the following function definition
void Packets::addNode(Node* newNode) {
    // Increment packet number
    ++packetCount;

    // Update links
    newNode->prev = tail;
    newNode->next = nullptr;

    if (tail != nullptr) {
        tail->next = newNode;
    } else {
        // The list is empty, set the head
        head = newNode;
    }

    // Update tail
    tail = newNode;
}

void Packets::addPackets(const Node& packet) {
    Node* newNode = new Node;

    newNode->id = packet.id;
    newNode->longitude = packet.longitude;
    newNode->latitude = packet.latitude;
    newNode->clientID = packet.clientID;

    newNode->prev = tail;
    newNode->next = nullptr;

    if (tail != nullptr) {
        tail->next = newNode;
    } else {
        head = newNode;
    }

    tail = newNode;
}

void Packets::addingPackets(const Packets& sourcePackets) {
    Node* currentPacket = sourcePackets.head;

    while (currentPacket != nullptr) {
        Node* newNode = new Node;

        newNode->id = currentPacket->id;
        newNode->longitude = currentPacket->longitude;
        newNode->latitude = currentPacket->latitude;
        newNode->clientID = currentPacket->clientID;

        newNode->prev = tail;
        newNode->next = nullptr;

        if (tail != nullptr) {
            tail->next = newNode;
        } else {
            head = newNode;
        }

        tail = newNode;
        currentPacket = currentPacket->next;
    }
}


void Packets::copyPacket(int packetNumber, Packets& tmppacket) {
    // Search for the packet with the specified packet number
    Node* currentPacket = peekFront();
    while (currentPacket) {
        if (currentPacket->id.packetNumber == packetNumber) {
            // Create a new node for tmppacket if it's empty
            if (tmppacket.head == nullptr) {
                tmppacket.head = new Node;
                tmppacket.tail = tmppacket.head;
            }

            // Assuming Packets has the required members
            tmppacket.tail->id = currentPacket->id;
            tmppacket.tail->longitude = currentPacket->longitude;
            tmppacket.tail->latitude = currentPacket->latitude;
            tmppacket.tail->clientID = currentPacket->clientID;

            // Insert additional members if any

            std::cout << "Packet copied successfully.\n";
            return; // Exit the function once the packet is found and copied
        }
        currentPacket = currentPacket->next;
    }

    // If the packet with the specified number is not found
    std::cout << "Packet with number " << packetNumber << " not found.\n";
}


// Inside the implementation of the `Packets` class in "packets.cpp"
void Packets::copyingPacket(const Node* sourcePacket, Node*& destinationPacket) {
    if (sourcePacket == nullptr) {
        std::cerr << "Error: Source packet is nullptr.\n";
        return;
    }

    if (destinationPacket == nullptr) {
        std::cerr << "Error: Destination packet is nullptr.\n";
        return;
    }

    // Copy data from the source packet to the destination packet
    destinationPacket->id = sourcePacket->id;
    destinationPacket->longitude = sourcePacket->longitude;
    destinationPacket->latitude = sourcePacket->latitude;
    destinationPacket->clientID = sourcePacket->clientID;
    
    // You may need to adjust this part based on the structure of your PacketID and GPSCoordinates structs
}