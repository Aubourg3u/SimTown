#include<class/building.h>
#include<class/storey.h>

#include <cstdlib>

int main(int argc, char** argv) {
    int size = 0;
    std::cout << "Welcome to SimTown, please enter the street size." << std::endl;
    std::cin >> size;

    Building** street = new Building * [size];

    for (int id_b = 0; id_b < size; id_b++) {
        street[id_b] = new Tower(id_b, 4); // Créez des objets Tower et stockez-les dans le tableau street
    }

    // Créez un objet TownHall
    TownHall* townHall = new TownHall(666);

    // Réallouez le tableau street avec une taille plus grande
    Building** street_TH = new Building * [size + 1];
    for (int i = 0; i < size; i++) {
        street_TH[i] = street[i];
    }
    delete[] street;
    street_TH[size] = townHall; // Ajoutez la mairie à la fin du tableau
    size += 1;
    street = street_TH;

    // Nettoyage : Supprimez les objets et libérez la mémoire
    for (int id_b = 0; id_b < size; id_b++) {
        delete street[id_b];
    }
    delete[] street;

    std::cout << "Press enter to exit...";
    std::cin.get(); // Attendre une entrée de l'utilisateur
    return 0; // Fin normale
}