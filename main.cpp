// main.cpp

#include "van.hpp"
#include "packets.hpp"
#include "hubs.hpp"
#include <iostream>

int main() {
    // Create hubs
    Hubs hubs;

    // Add postal codes and acronyms to hubs
    hubs.addPC(37115, "ADT");
    hubs.addPC(37427, "PER");
    hubs.addPC(37449, "ROD");
    hubs.addPC(37893, "VDT");
    hubs.addPC(37797, "CDV");
    hubs.addPC(37796, "MOZ");
    hubs.addPC(37129, "CDB");
    hubs.addPC(37340, "ALD");
    hubs.addPC(3003, "SAL");

    // Display hubs
    std::cout << "Hubs Information:\n";
    hubs.displayPCs();
    std::cout << "\n\n";

    // Create a van and packets
    Van van;
    Packets packets;
    Packets packetsVIP;

    // Load regular packets into the van
    for (int i = 1; i <= 10; ++i) {
        packets.addPacket();
        Packets::Node* packet = packets.peekEnd();
        packets.displayPackets();
        van.loadPacket(packet);
    }

    // Display regular packets in the van
    std::cout << "Regular Packets in the Van:\n";
    van.displayPackets();
    std::cout << "\n\n";

    // Load VIP packets into the van
    for (int i = 101; i <= 110; ++i) {
        packets.addPacket();
        Packets::Node* packet = packets.peekEnd();
        van.loadPacketVIP(packet);
    }

    // Display VIP packets in the VIP van
    std::cout << "VIP Packets in the VIP Van:\n";
    van.displayPackets();  // Display VIP packets using the corrected function
    std::cout << "\n\n";

    // Unload regular and VIP packets
    van.unloadPackets();
    van.unloadVIP();

    // Display remaining regular and VIP packets in the van
    std::cout << "Regular Packets in the Van After Unloading:\n";
    van.displayPackets();
    std::cout << "\n\n";

    std::cout << "VIP Packets in the VIP Van After Unloading:\n";
    van.displayPackets();  // Display VIP packets using the corrected function
    std::cout << "\n\n";

    // Move a regular packet to the VIP list
    int packetNumberToMove = 3;
    std::cout << "Moving packet with number " << packetNumberToMove << " to VIP list...\n";
    packets.movePacketToVIPList(packetNumberToMove, packetsVIP);

    // Display regular and VIP packets after moving a packet to the VIP list
    std::cout << "Regular Packets in the Van:\n";
    van.displayPackets();
    std::cout << "\n\n";

    std::cout << "VIP Packets in the VIP Van:\n";
    van.displayPackets();  // Display VIP packets using the corrected function
    std::cout << "\n\n";

    return 0;
}