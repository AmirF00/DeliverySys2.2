// simulation.cpp
#include <set>
#include "simulation.hpp"
#include "van.hpp"
#include "packets.hpp"
#include "hubs.hpp"

void simulation() {
    Packets CentralStation;
    Packets CentralStationCopy;
    Packets CentralStationCopyFinal;
    Packets VIPStation;
    Packets usedProcessed;
    Packets::Node* nextNode = nullptr;  // Initialize nextNode
    
    Packets DestinationADT;
    Packets DestinationPER;
    Packets DestinationROD;
    Packets DestinationVDT;
    Packets DestinationCDV;
    Packets DestinationMOZ;
    Packets DestinationCDB;
    Packets DestinationALD;
    Packets DestinationSAL;
    
    // Create hubs
    Hubs hubsVIP;
    Van vanVIPADT1("VIPADT1");
    Van vanVIPPER1("VIPPER1");
    Van vanVIPROD1("VIPROD1");
    Van vanVIPVDT1("VIPVDT1");
    Van vanVIPCDV1("VIPCDV1");
    Van vanVIPMOZ1("VIPMOZ1");
    Van vanVIPCDB1("VIPCDB1");
    Van vanVIPALD1("VIPALD1");
    Van vanVIPSAL1("VIPSAL1");
    
    // Keep track of loaded vans
    std::set<Van*> loadedGlobalVans;
    
     // Create hubs
    Hubs hubsGlobal;

    // Add postal codes and acronyms to hubs
    hubsGlobal.addPC(37115, "ADT");
    hubsGlobal.addPC(37427, "PER");
    hubsGlobal.addPC(37449, "ROD");
    hubsGlobal.addPC(37893, "VDT");
    hubsGlobal.addPC(37797, "CDV");
    hubsGlobal.addPC(37796, "MOZ");
    hubsGlobal.addPC(37129, "CDB");
    hubsGlobal.addPC(37340, "ALD");
    hubsGlobal.addPC(37002, "SAL");

    Van vanGlobalADT1("GlobalADT1");
    Van vanGlobalPER1("GlobalPER1");
    Van vanGlobalROD1("GlobalROD1");
    Van vanGlobalVDT1("GlobalVDT1");
    Van vanGlobalCDV1("GlobalCDV1");
    Van vanGlobalMOZ1("GlobalMOZ1");
    Van vanGlobalCDB1("GlobalCDB1");
    Van vanGlobalALD1("GlobalALD1");
    Van vanGlobalSAL1("GlobalSAL1");
    
    int total = 4700;

    // Generate x number of packets
    int x;
    std::cout << "Enter the number of packets to generate: ";
    std::cin >> x;

    for (int i = 0; i < x; ++i) {
        CentralStation.addPacket();
        CentralStation.displayPacketByNumber(i);
        
    }
    
    for (int i=0; i<x;i++){
        CentralStation.copyPacket(i, CentralStationCopy);
        CentralStationCopyFinal.addingPackets(CentralStationCopy);
        std::cout << "\nDISPALY COPIED PACKET\n";
        CentralStationCopyFinal.displayPacketByNumber(i);
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
        std::cout << "8. FULL Delivery Result FAST\n";
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
                    Van vanCDB1("CDB1");
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
                    //int counter = 0;
                   
                    
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
                        //counter += 1;
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
                {
                    // Generate x number of packets
                    int x;
                    std::cout << "Enter the packet number to move packet from SPCS to PC: ";
                    std::cin >> x;
                    std::cout << "--------------------------------------------------" << std::endl;
                    CentralStation.displayPacketByNumber(x);
                    std::cout << "The packet is moving to VIP Station." << std::endl;
                    CentralStation.movePacketToVIPList(x, VIPStation);
                    std::cout << "Transfer successful!" << std::endl;
                    CentralStation.displayPacketByNumber(x);
                    std::cout << "Transfer complete" << std::endl;

                    // Iterate through all packets until all vans have at least one packet
                    Packets::Node* currentPacket = VIPStation.peekFront();
                    while (currentPacket) {  

                        int y;
                        std::cout << "Enter the PC number to move packet to: ";
                        std::cin >> y;
                        hubsVIP.addPC(37115, "ADT");
                        hubsVIP.addPC(37427, "PER");
                        hubsVIP.addPC(37449, "ROD");
                        hubsVIP.addPC(37893, "VDT");
                        hubsVIP.addPC(37797, "CDV");
                        hubsVIP.addPC(37796, "MOZ");
                        hubsVIP.addPC(37129, "CDB");
                        hubsVIP.addPC(37340, "ALD");
                        hubsVIP.addPC(37002, "SAL");
                        Hubs::PC* hub = hubsVIP.searchPC(y);

                        if (hub) {
                            // Find the corresponding van
                            Van* correspondingVan = nullptr;

                            switch (y) {
                                case 37115: correspondingVan = &vanVIPADT1; break;
                                case 37427: correspondingVan = &vanVIPPER1; break;
                                case 37449: correspondingVan = &vanVIPROD1; break;
                                case 37893: correspondingVan = &vanVIPVDT1; break;
                                case 37797: correspondingVan = &vanVIPCDV1; break;
                                case 37796: correspondingVan = &vanVIPMOZ1; break;
                                case 37129: correspondingVan = &vanVIPCDB1; break;
                                case 37340: correspondingVan = &vanVIPALD1; break;
                                case 37002: correspondingVan = &vanVIPSAL1; break;
                            }

                            // Load the packet into the corresponding van
                            if (correspondingVan) {
                                correspondingVan->loadPacket(currentPacket);
                
                                std::cout << "Packet loaded into the corresponding van: " << correspondingVan->getAcronym() << "\n";
                                Van::Node* vanTop = correspondingVan->getTop();
                                while (vanTop) {
                                    std::cout << "Packet Number: " << vanTop->data->id.packetNumber << "\n";
                                    std::cout << "Packet ID: " << vanTop->data->id.packetNumber << "-" << vanTop->data->id.randomDigits << vanTop->data->id.randomLetter << "-" << vanTop->data->id.classificationDate << "-" << vanTop->data->id.townCodes << "\n";
                                    std::cout << "Longitude: " << vanTop->data->longitude.degrees << "º " << vanTop->data->longitude.minutes << "' " << vanTop->data->longitude.seconds << "\"\n";
                                    std::cout << "Latitude: " << vanTop->data->latitude.degrees << "º " << vanTop->data->latitude.minutes << "' " << vanTop->data->latitude.seconds << "\"\n";
                                    std::cout << "Client ID: " << vanTop->data->clientID << "\n\n";
                                    vanTop = vanTop->next; 
                                }
                                std::cout << "--------------------------------------------------" << std::endl;
                            }
                            else {
                                std::cout << "Corresponding van not found.\n";
                            }
                        }
                        else {
                            std::cout << "Postal Code not found.\n";
                        }

                        // Move to the next packet
                        
                        currentPacket = currentPacket->next;
                    }
                    break;
                }

            case 6:
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
                    int packetsToProcess;
                    std::cout << "Enter the number of packets to process: ";
                    std::cin >> packetsToProcess;
                    while (currentPacket && packetsToProcess>0) {  // Removed the condition !loadedVans.empty()

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
                        --packetsToProcess;
                        
                    }

                    
                    
                    
                    
                    // Display the first packet of each loaded van
                    std::cout << "All packets in each loaded van:\n";
                    for (Van* loadedVan : loadedVans) {
                        //std::cout << "Van: " << loadedVan->getTop()->data->id.packetNumber << "\n";

                        // Display the first packet in the stack of each loaded van
                        std::cout << "All the packets in the van's stack: " << loadedVan->getAcronym() << "\n"; 
                        Van::Node* vanTop = loadedVan->getTop();
                        while (vanTop) {
                            std::cout << "Packet Number: " << vanTop->data->id.packetNumber << "\n" 
                                    << "Packet ID: " << vanTop->data->id.packetNumber << "-" 
                                    << vanTop->data->id.randomDigits << vanTop->data->id.randomLetter << "-" 
                                    << vanTop->data->id.classificationDate << "-" << vanTop->data->id.townCodes << "\n" 
                                    << "Longitude: " << vanTop->data->longitude.degrees << "º " << vanTop->data->longitude.minutes << "' " 
                                    << vanTop->data->longitude.seconds << "\"\n" 
                                    << "Latitude: " << vanTop->data->latitude.degrees << "º " << vanTop->data->latitude.minutes << "' " 
                                    << vanTop->data->latitude.seconds << "\"\n"
                                    << "Client ID: " << vanTop->data->clientID << "\n\n";
                            vanTop = vanTop->next; 
                        }
                        
                        std::cout << "---------------------------------------------------------------------------------------\n";
                    }
                    int moveFrom;
                        std::cout << "Which PCs to move packet from:  \n";
                        std::cout << "1. ADT\n";
                        std::cout << "2. PER\n";
                        std::cout << "3. ROD\n";
                        std::cout << "4. VDT\n";
                        std::cout << "5. CDV\n";
                        std::cout << "6. MOZ\n";
                        std::cout << "7. CDB\n";
                        std::cout << "8. ALD\n";
                        std::cout << "9. SAL\n";
                      
                        std::cin >> moveFrom;
                        int packNum;
                        std::cout << "Packet Number of moving packet:   ";
                        std::cin >> packNum;
                        int moveTo;
                        std::cout << "Which PCs to move packet to:  ";
                        std::cout << "1. ADT\n";
                        std::cout << "2. PER\n";
                        std::cout << "3. ROD\n";
                        std::cout << "4. VDT\n";
                        std::cout << "5. CDV\n";
                        std::cout << "6. MOZ\n";
                        std::cout << "7. CDB\n";
                        std::cout << "8. ALD\n";
                        std::cout << "9. SAL\n";
                        std::cin >> moveTo;
                        switch (moveFrom) {
                            case 1: 
                                {
                                    switch(moveTo) {
                                            case 2: vanADT1.movePacket(vanPER1, packNum); break;
                                            case 3: vanADT1.movePacket(vanROD1, packNum); break;
                                            case 4: vanADT1.movePacket(vanVDT1, packNum); break;
                                            case 5: vanADT1.movePacket(vanCDV1, packNum); break;
                                            case 6: vanADT1.movePacket(vanMOZ1, packNum); break;
                                            case 7: vanADT1.movePacket(vanCDB1, packNum); break;
                                            case 8: vanADT1.movePacket(vanALD1, packNum); break;
                                            case 9: vanADT1.movePacket(vanSAL1, packNum); break;
                                        }
                                        break;
                                    }
                            case 2:
                                 {
                                    switch(moveTo) {
                                            case 1: vanPER1.movePacket(vanADT1, packNum); break;
                                            case 3: vanPER1.movePacket(vanROD1, packNum); break;
                                            case 4: vanPER1.movePacket(vanVDT1, packNum); break;
                                            case 5: vanPER1.movePacket(vanCDV1, packNum); break;
                                            case 6: vanPER1.movePacket(vanMOZ1, packNum); break;
                                            case 7: vanPER1.movePacket(vanCDB1, packNum); break;
                                            case 8: vanPER1.movePacket(vanALD1, packNum); break;
                                            case 9: vanPER1.movePacket(vanSAL1, packNum); break;
                                        }
                                        break;
                                    }
                            case 3:
                                 {
                                    switch(moveTo) {
                                            
                                            case 1: vanROD1.movePacket(vanADT1, packNum); break;
                                            case 2: vanROD1.movePacket(vanPER1, packNum); break;
                                            case 4: vanROD1.movePacket(vanVDT1, packNum); break;
                                            case 5: vanROD1.movePacket(vanCDV1, packNum); break;
                                            case 6: vanROD1.movePacket(vanMOZ1, packNum); break;
                                            case 7: vanROD1.movePacket(vanCDB1, packNum); break;
                                            case 8: vanROD1.movePacket(vanALD1, packNum); break;
                                            case 9: vanROD1.movePacket(vanSAL1, packNum); break;
                                        }
                                        break;
                                    }
                            case 4:
                                 {
                                    switch(moveTo) {
                                            case 1: vanVDT1.movePacket(vanADT1, packNum); break;
                                            case 2: vanVDT1.movePacket(vanPER1, packNum); break;
                                            case 3: vanVDT1.movePacket(vanROD1, packNum); break;
                                            
                                            case 5: vanVDT1.movePacket(vanCDV1, packNum); break;
                                            case 6: vanVDT1.movePacket(vanMOZ1, packNum); break;
                                            case 7: vanVDT1.movePacket(vanCDB1, packNum); break;
                                            case 8: vanVDT1.movePacket(vanALD1, packNum); break;
                                            case 9: vanVDT1.movePacket(vanSAL1, packNum); break;
                                        }
                                        break;
                                    }
                            case 5: 
                                 {
                                    switch(moveTo) {
                                            case 1: vanCDV1.movePacket(vanADT1, packNum); break;
                                            case 2: vanCDV1.movePacket(vanPER1, packNum); break;
                                            case 3: vanCDV1.movePacket(vanROD1, packNum); break;
                                            case 4: vanCDV1.movePacket(vanVDT1, packNum); break;
                                            
                                            case 6: vanCDV1.movePacket(vanMOZ1, packNum); break;
                                            case 7: vanCDV1.movePacket(vanCDB1, packNum); break;
                                            case 8: vanCDV1.movePacket(vanALD1, packNum); break;
                                            case 9: vanCDV1.movePacket(vanSAL1, packNum); break;
                                        }
                                        break;
                                    }
                            case 6:
                                 {
                                    switch(moveTo) {
                                            case 1: vanMOZ1.movePacket(vanADT1, packNum); break;
                                            case 2: vanMOZ1.movePacket(vanPER1, packNum); break;
                                            case 3: vanMOZ1.movePacket(vanROD1, packNum); break;
                                            case 4: vanMOZ1.movePacket(vanVDT1, packNum); break;
                                            case 5: vanMOZ1.movePacket(vanCDV1, packNum); break;
                                            
                                            case 7: vanMOZ1.movePacket(vanCDB1, packNum); break;
                                            case 8: vanMOZ1.movePacket(vanALD1, packNum); break;
                                            case 9: vanMOZ1.movePacket(vanSAL1, packNum); break;
                                        }
                                        break;
                                    }
                            case 7:
                                 {
                                    switch(moveTo) {
                                            case 1: vanCDB1.movePacket(vanADT1, packNum); break;
                                            case 2: vanCDB1.movePacket(vanPER1, packNum); break;
                                            case 3: vanCDB1.movePacket(vanROD1, packNum); break;
                                            case 4: vanCDB1.movePacket(vanVDT1, packNum); break;
                                            case 5: vanCDB1.movePacket(vanCDV1, packNum); break;
                                            case 6: vanCDB1.movePacket(vanMOZ1, packNum); break;
                                            
                                            case 8: vanCDB1.movePacket(vanALD1, packNum); break;
                                            case 9: vanCDB1.movePacket(vanSAL1, packNum); break;
                                        }
                                        break;
                                    }
                            case 8:
                                 {
                                    switch(moveTo) {
                                            case 1: vanALD1.movePacket(vanADT1, packNum); break;
                                            case 2: vanALD1.movePacket(vanPER1, packNum); break;
                                            case 3: vanALD1.movePacket(vanROD1, packNum); break;
                                            case 4: vanALD1.movePacket(vanVDT1, packNum); break;
                                            case 5: vanALD1.movePacket(vanCDV1, packNum); break;
                                            case 6: vanALD1.movePacket(vanMOZ1, packNum); break;
                                            case 7: vanALD1.movePacket(vanCDB1, packNum); break;
                                            
                                            case 9: vanALD1.movePacket(vanSAL1, packNum); break;
                                        }
                                        break;
                                    }
                            case 9: 
                                 {
                                    switch(moveTo) {
                                            case 1: vanSAL1.movePacket(vanSAL1, packNum); break;
                                            case 2: vanSAL1.movePacket(vanPER1, packNum); break;
                                            case 3: vanSAL1.movePacket(vanROD1, packNum); break;
                                            case 4: vanSAL1.movePacket(vanVDT1, packNum); break;
                                            case 5: vanSAL1.movePacket(vanCDV1, packNum); break;
                                            case 6: vanSAL1.movePacket(vanMOZ1, packNum); break;
                                            case 7: vanSAL1.movePacket(vanCDB1, packNum); break;
                                            case 8: vanSAL1.movePacket(vanALD1, packNum); break;
                                            
                                        }
                                        break;
                                    }
                            default:
                                std::cout << "Invalid choice. Please enter a number between 1 and 7.\n";
                                break;
                            
                            }
                            // Display the first packet of each loaded van
                            std::cout << "All packets in each loaded van:\n";
                            for (Van* loadedVan : loadedVans) {
                                //std::cout << "Van: " << loadedVan->getTop()->data->id.packetNumber << "\n";

                                // Display the first packet in the stack of each loaded van
                                std::cout << "All the packets in the van's stack: " << loadedVan->getAcronym() << "\n"; 
                                Van::Node* vanTop = loadedVan->getTop();
                                while (vanTop) {
                                    std::cout << "Packet Number: " << vanTop->data->id.packetNumber << "\n" 
                                            << "Packet ID: " << vanTop->data->id.packetNumber << "-" 
                                            << vanTop->data->id.randomDigits << vanTop->data->id.randomLetter << "-" 
                                            << vanTop->data->id.classificationDate << "-" << vanTop->data->id.townCodes << "\n" 
                                            << "Longitude: " << vanTop->data->longitude.degrees << "º " << vanTop->data->longitude.minutes << "' " 
                                            << vanTop->data->longitude.seconds << "\"\n" 
                                            << "Latitude: " << vanTop->data->latitude.degrees << "º " << vanTop->data->latitude.minutes << "' " 
                                            << vanTop->data->latitude.seconds << "\"\n"
                                            << "Client ID: " << vanTop->data->clientID << "\n\n";
                                    vanTop = vanTop->next; 
                                }
                        
                            std::cout << "---------------------------------------------------------------------------------------\n";
                            }

                    break;
                }
            case 7:
                {
                    int numPacketsGlobalADT1 = vanGlobalADT1.getNumPackets();
                    int numPacketsGlobalPER1 = vanGlobalPER1.getNumPackets();
                    int numPacketsGlobalROD1 = vanGlobalROD1.getNumPackets();
                    int numPacketsGlobalVDT1 = vanGlobalVDT1.getNumPackets();
                    int numPacketsGlobalCDV1 = vanGlobalCDV1.getNumPackets();
                    int numPacketsGlobalMOZ1 = vanGlobalMOZ1.getNumPackets();
                    int numPacketsGlobalCDB1 = vanGlobalCDB1.getNumPackets();
                    int numPacketsGlobalALD1 = vanGlobalALD1.getNumPackets();
                    int numPacketsGlobalSAL1 = vanGlobalSAL1.getNumPackets();
                    std::cout << "Number of packets in the van: " << numPacketsGlobalADT1 << std::endl;
                    std::cout << "Number of packets in the van: " << numPacketsGlobalPER1 << std::endl;
                    std::cout << "Number of packets in the van: " << numPacketsGlobalROD1 << std::endl;
                    std::cout << "Number of packets in the van: " << numPacketsGlobalVDT1 << std::endl;
                    std::cout << "Number of packets in the van: " << numPacketsGlobalCDV1 << std::endl;
                    std::cout << "Number of packets in the van: " << numPacketsGlobalMOZ1 << std::endl;
                    std::cout << "Number of packets in the van: " << numPacketsGlobalCDB1 << std::endl;
                    std::cout << "Number of packets in the van: " << numPacketsGlobalALD1 << std::endl;
                    std::cout << "Number of packets in the van: " << numPacketsGlobalSAL1 << std::endl;
                    // Iterate through all packets until all vans have at least one packet
                    static Packets::Node* currentPacket = CentralStation.peekFront();
                    
                    int packetsToProcess = 197;
                    //int iterate = 0;
                    
                    
                    
                    while (currentPacket && packetsToProcess>0) {  // Removed the condition !loadedVans.empty()
                        //iterate++;
                        nextNode = currentPacket->next; // Save nextNode before moving to the next packet
                        int packetPostalCode = std::stoi(currentPacket->id.townCodes);
                        //int packetNum = currentPacket->id.packetNumber;
                        Hubs::PC* hub = hubsGlobal.searchPC(packetPostalCode);
                        
                        

                        if (hub) {
                            // Find the corresponding van
                            Van* correspondingVan = nullptr;
                            
                            
                            switch (packetPostalCode) {
                                case 37115: correspondingVan = &vanGlobalADT1; break; 
                                case 37427: correspondingVan = &vanGlobalPER1; break; 
                                case 37449: correspondingVan = &vanGlobalROD1; break; 
                                case 37893: correspondingVan = &vanGlobalVDT1; break; 
                                case 37797: correspondingVan = &vanGlobalCDV1; break; 
                                case 37796: correspondingVan = &vanGlobalMOZ1; break;  
                                case 37129: correspondingVan = &vanGlobalCDB1; break; 
                                case 37340: correspondingVan = &vanGlobalALD1; break; 
                                case 37002: correspondingVan = &vanGlobalSAL1; break;
                            }

                             // Load the packet into the corresponding van
                            if (correspondingVan) {
                                correspondingVan->loadPacket(currentPacket);
                                loadedGlobalVans.insert(correspondingVan);
                                std::cout << "Packet loaded into the corresponding van: " << correspondingVan->getAcronym() << "\n";
                                // Update the number of packets for each van after loading a packet
                                numPacketsGlobalADT1 = vanGlobalADT1.getNumPackets();
                                numPacketsGlobalPER1 = vanGlobalPER1.getNumPackets();
                                numPacketsGlobalROD1 = vanGlobalROD1.getNumPackets();
                                numPacketsGlobalVDT1 = vanGlobalVDT1.getNumPackets();
                                numPacketsGlobalCDV1 = vanGlobalCDV1.getNumPackets();
                                numPacketsGlobalMOZ1 = vanGlobalMOZ1.getNumPackets();
                                numPacketsGlobalCDB1 = vanGlobalCDB1.getNumPackets();
                                numPacketsGlobalALD1 = vanGlobalALD1.getNumPackets();
                                numPacketsGlobalSAL1 = vanGlobalSAL1.getNumPackets();

                                
                               // Remove the current packet from CentralStation
                                //CentralStation.deletePacketAtPosition(1); 

                            }
                        }
                        
                        //CentralStation.movePacketToVIPList(packetNum, usedProcessed);
                        // Move to the next packet
                         currentPacket = nextNode;  // Use nextNode to move to the next packet
                         
                        --packetsToProcess;
                        
                    }
                    
                    // Check if nextNode is not nullptr before accessing its members
                    if (nextNode) {
                        total = total - (nextNode->id.packetNumber);
                        std::cout << "NUMBER OF PACKETS IN THE CENTRAL STATION: " << total << std::endl;
                    } else {
                        std::cout << "No more packets to process.\n";
                        
                        
                        for (Van* loadedVan : loadedGlobalVans) {
                        if (!loadedVan->isFullyLoaded()) {
                            if (loadedVan->getAcronym() == "GlobalADT1" ){
                                std::cout << "Delivery to ADT\n";
                                std::cout << "---------------------------------------------------------------------------------------\n";
                                loadedVan->deliver(DestinationADT);
                                } else if (loadedVan->getAcronym() == "GlobalPER1") {
                                    std::cout << "Delivery to PER\n";
                                    std::cout << "---------------------------------------------------------------------------------------\n";
                                    loadedVan->deliver(DestinationPER);
                                    } else if (loadedVan->getAcronym() == "GlobalROD1") {
                                        std::cout << "Delivery to ROD\n";
                                        std::cout << "---------------------------------------------------------------------------------------\n";
                                        loadedVan->deliver(DestinationROD);
                                        } else if (loadedVan->getAcronym() == "GlobalVDT1") {
                                            std::cout << "Delivery to VDT\n";
                                            std::cout << "---------------------------------------------------------------------------------------\n";
                                            loadedVan->deliver(DestinationVDT);
                                            } else if  (loadedVan->getAcronym() == "GlobalCDV1") {
                                                std::cout << "Delivery to CDV\n";
                                                std::cout << "---------------------------------------------------------------------------------------\n";
                                                loadedVan->deliver(DestinationCDV);
                                                } else if (loadedVan->getAcronym() == "GlobalMOZ1") {
                                                    std::cout << "Delivery to MOZ\n";
                                                    std::cout << "---------------------------------------------------------------------------------------\n";
                                                    loadedVan->deliver(DestinationMOZ);
                                                    } else if (loadedVan->getAcronym() == "GlobalCDB1") {
                                                        std::cout << "Delivery to CDB\n";
                                                        std::cout << "---------------------------------------------------------------------------------------\n";
                                                         loadedVan->deliver(DestinationCDB);
                                                        } else if (loadedVan->getAcronym() == "GlobalALD1") {
                                                            std::cout << "Delivery to ALD\n";
                                                            std::cout << "---------------------------------------------------------------------------------------\n";
                                                             loadedVan->deliver(DestinationALD);
                                                            } else if (loadedVan->getAcronym() == "GlobalSAL1") {
                                                                std::cout << "Delivery to SAL\n";
                                                                std::cout << "---------------------------------------------------------------------------------------\n";
                                                                loadedVan->deliver(DestinationSAL);
                                                                } else {
                                                                    std::cout << "NO van Was ready to leave \n";
                                                                    }
                                                
                            }
                        
                        }
                        
                    }
                    std::cout << "---------------------------------------------------------------------------------------\n";
                    // Display the number of packets for each van
                                std::cout << "Number of packets in the van ADT1: " << numPacketsGlobalADT1 << std::endl;
                                std::cout << "Number of packets in the van PER1: " << numPacketsGlobalPER1 << std::endl;
                                std::cout << "Number of packets in the van ROD1: " << numPacketsGlobalROD1 << std::endl;
                                std::cout << "Number of packets in the van VDT1: " << numPacketsGlobalVDT1 << std::endl;
                                std::cout << "Number of packets in the van CDV1: " << numPacketsGlobalCDV1 << std::endl;
                                std::cout << "Number of packets in the van MOZ1: " << numPacketsGlobalMOZ1 << std::endl;
                                std::cout << "Number of packets in the van CDB1: " << numPacketsGlobalCDB1 << std::endl;
                                std::cout << "Number of packets in the van ALD1: " << numPacketsGlobalALD1 << std::endl;
                                std::cout << "Number of packets in the van SAL1: " << numPacketsGlobalSAL1 << std::endl;
                    std::cout << "---------------------------------------------------------------------------------------\n";
                     // Display the first packet of each loaded van
                    std::cout << "All packets in each loaded van:\n";
                    for (Van* loadedVan : loadedGlobalVans) {
                        //std::cout << "Van: " << loadedVan->getTop()->data->id.packetNumber << "\n";

                        // Display the first packet in the stack of each loaded van
                        std::cout << "All the packets in the van's stack: " << loadedVan->getAcronym() << "\n"; 
                        Van::Node* vanTop = loadedVan->getTop();
                        while (vanTop) {
                            std::cout << "Packet Number: " << vanTop->data->id.packetNumber << "\n" 
                                    << "Packet ID: " << vanTop->data->id.packetNumber << "-" 
                                    << vanTop->data->id.randomDigits << vanTop->data->id.randomLetter << "-" 
                                    << vanTop->data->id.classificationDate << "-" << vanTop->data->id.townCodes << "\n" 
                                    << "Longitude: " << vanTop->data->longitude.degrees << "º " << vanTop->data->longitude.minutes << "' " 
                                    << vanTop->data->longitude.seconds << "\"\n" 
                                    << "Latitude: " << vanTop->data->latitude.degrees << "º " << vanTop->data->latitude.minutes << "' " 
                                    << vanTop->data->latitude.seconds << "\"\n"
                                    << "Client ID: " << vanTop->data->clientID << "\n\n";
                            vanTop = vanTop->next; 
                        }
                        
                        std::cout << "---------------------------------------------------------------------------------------\n";
                    }
                    
                    
                    for (Van* loadedVan : loadedGlobalVans) {
                        if (loadedVan->isFullyLoaded()) {
                            if (loadedVan->getAcronym() == "GlobalADT1" ){
                                std::cout << "Delivery to ADT\n";
                                std::cout << "---------------------------------------------------------------------------------------\n";
                                loadedVan->deliver(DestinationADT);
                                } else if (loadedVan->getAcronym() == "GlobalPER1") {
                                    std::cout << "Delivery to PER\n";
                                    std::cout << "---------------------------------------------------------------------------------------\n";
                                    loadedVan->deliver(DestinationPER);
                                    } else if (loadedVan->getAcronym() == "GlobalROD1") {
                                        std::cout << "Delivery to ROD\n";
                                        std::cout << "---------------------------------------------------------------------------------------\n";
                                        loadedVan->deliver(DestinationROD);
                                        } else if (loadedVan->getAcronym() == "GlobalVDT1") {
                                            std::cout << "Delivery to VDT\n";
                                            std::cout << "---------------------------------------------------------------------------------------\n";
                                            loadedVan->deliver(DestinationVDT);
                                            } else if  (loadedVan->getAcronym() == "GlobalCDV1") {
                                                std::cout << "Delivery to CDV\n";
                                                std::cout << "---------------------------------------------------------------------------------------\n";
                                                loadedVan->deliver(DestinationCDV);
                                                } else if (loadedVan->getAcronym() == "GlobalMOZ1") {
                                                    std::cout << "Delivery to MOZ\n";
                                                    std::cout << "---------------------------------------------------------------------------------------\n";
                                                    loadedVan->deliver(DestinationMOZ);
                                                    } else if (loadedVan->getAcronym() == "GlobalCDB1") {
                                                        std::cout << "Delivery to CDB\n";
                                                        std::cout << "---------------------------------------------------------------------------------------\n";
                                                         loadedVan->deliver(DestinationCDB);
                                                        } else if (loadedVan->getAcronym() == "GlobalALD1") {
                                                            std::cout << "Delivery to ALD\n";
                                                            std::cout << "---------------------------------------------------------------------------------------\n";
                                                             loadedVan->deliver(DestinationALD);
                                                            } else if (loadedVan->getAcronym() == "GlobalSAL1") {
                                                                std::cout << "Delivery to SAL\n";
                                                                std::cout << "---------------------------------------------------------------------------------------\n";
                                                                loadedVan->deliver(DestinationSAL);
                                                                } else {
                                                                    std::cout << "NO van Was ready to leave \n";
                                                                    }
                                                
                            }
                        
                        }
                        
                        
                        
                        

                    


                        
                       
                        
                        


                    
                    break;
                    }
                
            case 8:
                // implement
                {
                    std::cout << "TIHS IS THE SECOND LOOP  \n";
                        std::cout << "Packets in the Copy Station  "  << std::endl;
                        //CentralStationCopyFinal.displayPackets();
                        Packets::Node* currentPacketFinal = CentralStationCopyFinal.peekFront();
                        
                        int count = 0;
                        
                       // ...
                        while (currentPacketFinal) {
                            // Get the next node before modifying the list
                            Packets::Node* nextNode = currentPacketFinal->next;
                            
                            //std::cout << "Displaying packet " << currentPacketFinal->id.packetNumber << " in CentralStationCopyFinal:\n";
                            //std::cout << "---------------------------------------------------------------------------------------\n";
                            // Display additional packet information as needed
                            //std::cout << "Town Codes: " << currentPacketFinal->id.townCodes << "\n";
                            //std::cout << "Longitude: " << currentPacketFinal->longitude << "\n";
                            //std::cout << "Latitude: " << currentPacketFinal->latitude << "\n";
                            //std::cout << "Client ID: " << currentPacketFinal->clientID << "\n";
                            //std::cout << "---------------------------------------------------------------------------------------\n";
                            // Get the town code
                            int packetPostalCode = std::stoi(currentPacketFinal->id.townCodes);
    
                            // Move the packet to VIP based on town code
                            switch (packetPostalCode) {
                                case 37115: CentralStationCopyFinal.movePacketToVIPList(currentPacketFinal->id.packetNumber, DestinationADT); break;
                                case 37427: CentralStationCopyFinal.movePacketToVIPList(currentPacketFinal->id.packetNumber, DestinationPER); break;
                                case 37449: CentralStationCopyFinal.movePacketToVIPList(currentPacketFinal->id.packetNumber, DestinationROD); break;
                                case 37893: CentralStationCopyFinal.movePacketToVIPList(currentPacketFinal->id.packetNumber, DestinationVDT); break;
                                case 37797: CentralStationCopyFinal.movePacketToVIPList(currentPacketFinal->id.packetNumber, DestinationCDV); break;
                                case 37796: CentralStationCopyFinal.movePacketToVIPList(currentPacketFinal->id.packetNumber, DestinationMOZ); break;
                                case 37129: CentralStationCopyFinal.movePacketToVIPList(currentPacketFinal->id.packetNumber, DestinationCDB); break;
                                case 37340: CentralStationCopyFinal.movePacketToVIPList(currentPacketFinal->id.packetNumber, DestinationALD); break;
                                case 37002: CentralStationCopyFinal.movePacketToVIPList(currentPacketFinal->id.packetNumber, DestinationSAL); break;
                                // Add other cases as needed for different town codes and corresponding destinations
                                // case xxx: CentralStationCopyFinal.movePacketToVIPList(currentPacketFinal->id.packetNumber, DestinationXXX); break;
                                default:
                                    std::cout << "No VIP destination found for town code: " << packetPostalCode << "\n";
                        }
                        count++;
    
                        
                             
                        
    
                        std::cout << "The LOOP COUNT: "<< count << std::endl;
                        // Move to the next packet
                        currentPacketFinal = nextNode;
                        
                        // decrease counter 
                        //--packetsToProcess2;
                    }
                    
                    std::cout << "---------------------------------------------------------------------------------------\n";
                        std::cout << "Packets in ADT\n";
                        std::cout << "Numbers of packets in ADT: " << DestinationADT.getPacketCount() << std::endl;
                        
                            DestinationADT.displayPackets();
                             
                        
                        std::cout << "---------------------------------------------------------------------------------------\n";
                        std::cout << "Packets in PER\n";
                        std::cout << "Numbers of packets in PER: " << DestinationPER.getPacketCount() << std::endl;
                        
                            DestinationPER.displayPackets();
                             
                        std::cout << "---------------------------------------------------------------------------------------\n";
                        std::cout << "Packets in ROD\n";
                        std::cout << "Numbers of packets in ROD: " << DestinationROD.getPacketCount() << std::endl;
                       
                            DestinationROD.displayPackets();
                            
                        
                        std::cout << "---------------------------------------------------------------------------------------\n";
                        std::cout << "Packets in VDT\n";
                        std::cout << "Numbers of packets in VDT: " << DestinationVDT.getPacketCount() << std::endl;
                        
                            DestinationVDT.displayPackets();
                             
                        
                        std::cout << "---------------------------------------------------------------------------------------\n";
                        std::cout << "Packets in CDV\n";
                        std::cout << "Numbers of packets in CDV: " << DestinationCDV.getPacketCount() << std::endl;
                        
                            DestinationCDV.displayPackets();
                            
                        
                        std::cout << "---------------------------------------------------------------------------------------\n";
                        std::cout << "Packets in MOZ\n";
                        std::cout << "Numbers of packets in MOZ: " << DestinationMOZ.getPacketCount() << std::endl;
                        
                            DestinationMOZ.displayPackets();
                             
                        
                        std::cout << "---------------------------------------------------------------------------------------\n";
                        std::cout << "Packets in CDB\n";
                        std::cout << "Numbers of packets in CDB: " << DestinationCDB.getPacketCount() << std::endl;
                       
                            DestinationCDB.displayPackets();
                             
                        
                        std::cout << "---------------------------------------------------------------------------------------\n";
                        std::cout << "Packets in ALD\n";
                        std::cout << "Numbers of packets in ALD: " << DestinationALD.getPacketCount() << std::endl;
                       
                            DestinationALD.displayPackets();
                            
                        
                        
                        std::cout << "---------------------------------------------------------------------------------------\n";
                        std::cout << "Packets in SAL\n";
                        std::cout << "Numbers of packets in SAL: " << DestinationSAL.getPacketCount() << std::endl;
                       
                            DestinationSAL.displayPackets();
                    std::cout << "Finished processing packets in CentralStationCopyFinal.\n";
                    break;
                    }
                
                
                
                
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 7.\n";
                break;
        }
    } while (choice != 0);
    

}
