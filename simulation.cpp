// simulation.cpp
#include <set>
#include "simulation.hpp"
#include "van.hpp"
#include "packets.hpp"
#include "hubs.hpp"

void simulation() {
    Packets CentralStation;
    

    // Generate x number of packets
    int x;
    std::cout << "Enter the number of packets to generate: ";
    std::cin >> x;

    for (int i = 0; i < x; ++i) {
        CentralStation.addPacket();
    }

    int choice;
    do {
        // Display menu
        std::cout << "\nMenu:\n";
        std::cout << "1. Show the data corresponding to the next parcels ready to be delivered to any selected PC\n";
        std::cout << "2. Show the descriptive statistics (absolute and relative frequencies, total amount of parcels per PC, PC with the largest or smallest number of packets, etc.) of all the PCs. For that, the algorithm must walk the tree nodes in Post-Order fashion\n";
        std::cout << "3. Search a given packet using its ID.\n";
        std::cout << "4. Delete (from the system) a given packet from a given PC\n";
        std::cout << "5. Transport (move) a manually selected (existing) packet from the SPCS to a given PC\n";
        std::cout << "6. Transport (move) a manually selected (existing) packet from a given PC to another given PC.\n";
        std::cout << "7. Carry on with the packet’s delivery\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice (1-7): ";
        
        // Handle non-integer input
        if (!(std::cin >> choice)) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
            choice = -1;  // Set choice to an invalid value
        }

        switch (choice) {
            case 0:
                {
                    std::cout << "Exiting the simulation.\n";
                    break;
                }
            case 1:
                {
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
                    hubs.addPC(37002, "SAL");

                    Van vanADT1("ADT1");
                    Van vanPER1("PER1");
                    Van vanROD1("ROD1");
                    Van vanVDT1("VDT1");
                    Van vanCDV1("CDV1");
                    Van vanMOZ1("MOZ1");
                    Van vanCDB1("CBD1");
                    Van vanALD1("ALD1");
                    Van vanSAL1("SAL1");

                    // Keep track of loaded vans
                    std::set<Van*> loadedVans;
                    int numPacketsADT1 = vanADT1.getNumPackets();
                    int numPacketsPER1 = vanPER1.getNumPackets();
                    int numPacketsROD1 = vanROD1.getNumPackets();
                    int numPacketsVDT1 = vanVDT1.getNumPackets();
                    int numPacketsCDV1 = vanCDV1.getNumPackets();
                    int numPacketsMOZ1 = vanMOZ1.getNumPackets();
                    int numPacketsCDB1 = vanCDB1.getNumPackets();
                    int numPacketsALD1 = vanALD1.getNumPackets();
                    int numPacketsSAL1 = vanSAL1.getNumPackets();
                    std::cout << "Number of packets in the van: " << numPacketsADT1 << std::endl;
                    std::cout << "Number of packets in the van: " << numPacketsPER1 << std::endl;
                    std::cout << "Number of packets in the van: " << numPacketsROD1 << std::endl;
                    std::cout << "Number of packets in the van: " << numPacketsVDT1 << std::endl;
                    std::cout << "Number of packets in the van: " << numPacketsCDV1 << std::endl;
                    std::cout << "Number of packets in the van: " << numPacketsMOZ1 << std::endl;
                    std::cout << "Number of packets in the van: " << numPacketsCDB1 << std::endl;
                    std::cout << "Number of packets in the van: " << numPacketsALD1 << std::endl;
                    std::cout << "Number of packets in the van: " << numPacketsSAL1 << std::endl;
                    // Iterate through all packets until all vans have at least one packet
                    Packets::Node* currentPacket = CentralStation.peekFront();
                    while (currentPacket && (numPacketsADT1<1 || numPacketsPER1<1 || numPacketsROD1<1 || numPacketsVDT1<1 || numPacketsCDV1<1 || numPacketsMOZ1<1 || numPacketsCDB1<1 || numPacketsALD1<1 || numPacketsSAL1<1) ) {  // Removed the condition !loadedVans.empty()

                        int packetPostalCode = std::stoi(currentPacket->id.townCodes);
                        Hubs::PC* hub = hubs.searchPC(packetPostalCode);

                        if (hub) {
                            // Find the corresponding van
                            Van* correspondingVan = nullptr;
                            switch (packetPostalCode) {
                                case 37115: correspondingVan = &vanADT1; break;
                                case 37427: correspondingVan = &vanPER1; break;
                                case 37449: correspondingVan = &vanROD1; break;
                                case 37893: correspondingVan = &vanVDT1; break;
                                case 37797: correspondingVan = &vanCDV1; break;
                                case 37796: correspondingVan = &vanMOZ1; break;
                                case 37129: correspondingVan = &vanCDB1; break;
                                case 37340: correspondingVan = &vanALD1; break;
                                case 37002: correspondingVan = &vanSAL1; break;
                            }

                            // Load the packet into the corresponding van
                            if (correspondingVan) {
                                correspondingVan->loadPacket(currentPacket);
                                loadedVans.insert(correspondingVan);
                                std::cout << "Packet loaded into the corresponding van: " << correspondingVan->getAcronym() << "\n";
                                // Update the number of packets for each van after loading a packet
                                numPacketsADT1 = vanADT1.getNumPackets();
                                numPacketsPER1 = vanPER1.getNumPackets();
                                numPacketsROD1 = vanROD1.getNumPackets();
                                numPacketsVDT1 = vanVDT1.getNumPackets();
                                numPacketsCDV1 = vanCDV1.getNumPackets();
                                numPacketsMOZ1 = vanMOZ1.getNumPackets();
                                numPacketsCDB1 = vanCDB1.getNumPackets();
                                numPacketsALD1 = vanALD1.getNumPackets();
                                numPacketsSAL1 = vanSAL1.getNumPackets();

                                // Display the number of packets for each van
                                std::cout << "Number of packets in the van ADT1: " << numPacketsADT1 << std::endl;
                                std::cout << "Number of packets in the van PER1: " << numPacketsPER1 << std::endl;
                                std::cout << "Number of packets in the van ROD1: " << numPacketsROD1 << std::endl;
                                std::cout << "Number of packets in the van VDT1: " << numPacketsVDT1 << std::endl;
                                std::cout << "Number of packets in the van CDV1: " << numPacketsCDV1 << std::endl;
                                std::cout << "Number of packets in the van MOZ1: " << numPacketsMOZ1 << std::endl;
                                std::cout << "Number of packets in the van CDB1: " << numPacketsCDB1 << std::endl;
                                std::cout << "Number of packets in the van ALD1: " << numPacketsALD1 << std::endl;
                                std::cout << "Number of packets in the van SAL1: " << numPacketsSAL1 << std::endl;
                                

                            }
                            
                            
                        }

                        // Move to the next packet
                        currentPacket = currentPacket->next;
                        
                    }

                    
                    
                    
                    
                    // Display the first packet of each loaded van
                    std::cout << "First packet in each loaded van:\n";
                    for (Van* loadedVan : loadedVans) {
                        //std::cout << "Van: " << loadedVan->getTop()->data->id.packetNumber << "\n";

                        // Display the first packet in the stack of each loaded van
                        std::cout << "First packet in the van's stack: " << loadedVan->getAcronym() << "\n"; 
                        Van::Node* vanTop = loadedVan->getTop();
                        while (vanTop) {
                            std::cout << "Packet Number: " << vanTop->data->id.packetNumber << "\n" << "Packet ID: " << vanTop->data->id.packetNumber << "-"
                  << vanTop->data->id.randomDigits << vanTop->data->id.randomLetter
                  << "-" << vanTop->data->id.classificationDate
                  << "-" << vanTop->data->id.townCodes << "\n" << "Longitude: " << vanTop->data->longitude.degrees << "º "
                  << vanTop->data->longitude.minutes << "' " << vanTop->data->longitude.seconds << "\"\n" << "Latitude: " << vanTop->data->latitude.degrees << "º "
                  << vanTop->data->latitude.minutes << "' " << vanTop->data->latitude.seconds << "\"\n"<< "Client ID: " << vanTop->data->clientID << "\n\n" <<"\n";
                            break;  // Exit the loop after printing the first packet ID
                        }
                        std::cout << "---------------------------------------------------------------------------------------\n";
                    }

                    break;
                }

            case 2:
                {
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
                    hubs.addPC(37002, "SAL");
                    Hubs::Node* root = hubs.getRoot();
                    // Iterate through all packets until all vans have at least one packet
                    Packets::Node* currentPacket = CentralStation.peekFront();
                    
                    int parcelADT =0;
                    int parcelPER =0;
                    int parcelROD =0;
                    int parcelVDT =0;
                    int parcelCDV =0;
                    int parcelMOZ =0;
                    int parcelCDB =0;
                    int parcelALD =0;
                    int parcelSAL =0;
                    int counter = 0;
                   
                    
                    while (currentPacket) {
                        
                        int packetPostalCode = std::stoi(currentPacket->id.townCodes);
                        Hubs::PC* hub = hubs.searchPCPostOrder(root, packetPostalCode);
                        if (hub) {
                            switch (packetPostalCode) {
                                case 37115: parcelADT += 1; break;
                                case 37427: parcelPER += 1; break;
                                case 37449: parcelROD += 1; break;
                                case 37893: parcelVDT += 1; break;
                                case 37797: parcelCDV += 1; break;
                                case 37796: parcelMOZ += 1; break;
                                case 37129: parcelCDB += 1; break;
                                case 37340: parcelALD += 1; break;
                                case 37002: parcelSAL += 1; break;
                            }
                        }
                        counter += 1;
                        // Move to the next packet
                        currentPacket = currentPacket->next;

                    
                    }
                    
                    std::cout << "Number of packets Per PCs:  " << std::endl;
                    std::cout << "Absolute Frequency  Per PCs:  " << std::endl;
                    std::cout << "Number of parcels for ADT " << parcelADT << std::endl;
                    std::cout << "Number of parcels for PER " << parcelPER << std::endl;
                    std::cout << "Number of parcels for ROD " << parcelROD << std::endl;
                    std::cout << "Number of parcels for VDT " << parcelVDT << std::endl;
                    std::cout << "Number of parcels for CDV " << parcelCDV << std::endl;
                    std::cout << "Number of parcels for MOZ " << parcelMOZ << std::endl;
                    std::cout << "Number of parcels for CDB " << parcelCDB << std::endl;
                    std::cout << "Number of parcels for ALD " << parcelALD << std::endl;
                    std::cout << "Number of parcels for SAL " << parcelSAL << std::endl;
                    
                    break;
                }
            case 3:
                {
                    // Generate x number of packets
                    int x;
                    std::cout << "Enter the packet number to show you your packet data: ";
                    std::cin >> x;
                    std::cout << "--------------------------------------------------" << std::endl;
                    CentralStation.displayPacketByNumber(x);
                    std::cout << "--------------------------------------------------" << std::endl;
                    break;
                    }
            case 4:
                {
                    // Generate x number of packets
                    int x;
                    std::cout << "Enter the packet number to delete packet: ";
                    std::cin >> x;
                    std::cout << "--------------------------------------------------" << std::endl;
                    CentralStation.displayPacketByNumber(x);
                    std::cout << "Deleting the packet" << std::endl;
                    CentralStation.deletePacketAtPosition(x);
                    std::cout << "Packet successfully deleted as try to show packet again below" << std::endl;
                    CentralStation.displayPacketByNumber(x);
                    std::cout << "deletion complete" << std::endl;
                    std::cout << "--------------------------------------------------" << std::endl;
                    break;
                    }
            case 5:
                // Implement processing packets in hubs
                break;
            case 6:
                // Implement displaying hubs information
                break;
            case 7:
                // implement
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 7.\n";
                break;
        }
    } while (choice != 0);
}
