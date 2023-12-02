// simulation.cpp

#include "simulation.hpp"

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
        std::cout << "1. Display All Packets\n";
        std::cout << "2. Load a Packet into a Van\n";
        std::cout << "3. Unload Packets from a Van\n";
        std::cout << "4. Display All Vans\n";
        std::cout << "5. Process Packets in Hubs\n";
        std::cout << "6. Display Hubs Information\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice (1-7): ";
        
        // Handle non-integer input
        if (!(std::cin >> choice)) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
            choice = -1;  // Set choice to an invalid value
        }

        switch (choice) {
            case 1:
                CentralStation.displayPackets();
                break;
            case 2:
                // Implement loading a packet into a van
                break;
            case 3:
                // Implement unloading packets from a van
                break;
            case 4:
                // Implement displaying all vans
                break;
            case 5:
                // Implement processing packets in hubs
                break;
            case 6:
                // Implement displaying hubs information
                break;
            case 7:
                std::cout << "Exiting the simulation.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 7.\n";
                break;
        }
    } while (choice != 7);
}
