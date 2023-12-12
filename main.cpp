// main.cpp

//#include <set>
#include "van.hpp"
#include "packets.hpp"
#include "hubs.hpp"
#include "simulation.hpp"
#include <iostream>
#include <fstream>

int main() {
    
    // Save the current cout buffer
    //std::streambuf* coutBuffer = std::cout.rdbuf();

    // Create/open the result.txt file for writing
    //std::ofstream file("result.txt");

    // Redirect cout to the file
    //std::cout.rdbuf(file.rdbuf());
    
    simulation();
    
     // After the interactive part, restore the original cout buffer
    //std::cout.rdbuf(coutBuffer);

    // You can continue using std::cout as usual for interactive output
    //std::cout << "This will be displayed in the console.\n";
    
    return 0;
}
