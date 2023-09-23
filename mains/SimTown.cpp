#include<class/building.h>
#include<class/storey.h>

#include <cstdlib>

int main(int argc, char** argv) {
    int size = 0;
    std::cout << "Welcome to SimTown, please enter the street size." << std::endl;
    std::cin >> size;

    // Create an array of 'Building' pointers called 'street' of size 'size'.
    Building** street = new Building * [size];

    // Initialize each element of 'street' with a 'Tower' object, passing 'id_b' and '4' as parameters.
    for (int id_b = 0; id_b < size; id_b++) {
        street[id_b] = new Tower(id_b, 4);
    }

    // Create a 'TownHall' object named 'townHall' with an ID of '666'.
    TownHall* townHall = new TownHall(666);

    // Create a new array of 'Building' pointers called 'street_TH' with a size one greater than 'size'.
    Building** street_TH = new Building * [size + 1];

    // Copy the elements from 'street' to 'street_TH'.
    for (int i = 0; i < size; i++) {
        street_TH[i] = street[i];
    }

    // Deallocate the memory used by the original 'street' array.
    delete[] street;

    // Add the 'townHall' pointer to the end of 'street_TH' and update 'size' accordingly.
    street_TH[size] = townHall;
    size += 1;

    // Update the 'street' pointer to point to the modified 'street_TH' array.
    street = street_TH;

    // Deallocate memory for each 'Building' object in 'street'.
    for (int id_b = 0; id_b < size; id_b++) {
        delete street[id_b];
    }

    // Deallocate memory for the 'street' array itself.
    delete[] street;

    // Display a message and wait for the user to press enter before exiting the program.
    std::cout << "Press enter to exit...";
    std::cin.get();
    return 0; // Normal program termination.
}