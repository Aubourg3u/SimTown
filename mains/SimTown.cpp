#include <class/building.h>
#include <class/storey.h>
#include <class/MyVector.h>
#include <class/globals.h>

#include <cstdlib>

int main( int argc, char** argv )
{
    g_mode = "mute"; //Mode to hide all noisy cout in building and storey

    int size = 0;
    std::cout << "Welcome to SimTown, please enter the street size."
              << std::endl;
    std::cin >> size;

    // Utilisation de MyVector au lieu de tableau de pointeurs Building*
    MyVector< Building* > street;

    // Initialisation de chaque élément de 'street' avec un objet 'Tower',
    // en passant 'id_b' et '4' comme paramètres.
    for( int id_b = 0; id_b < size; id_b++ )
    {
        street.push_back( new Tower( id_b, 4 ) );
    }

    // Création d'un objet 'TownHall' nommé 'townHall' avec un ID de '666'.
    TownHall* townHall = new TownHall( 666 );

    // Ajout de 'townHall' à la fin de 'street'.
    street.push_back( townHall );

    // Affichage des éléments de 'street' en utilisant la méthode 'print' de
    // 'Building'.
    std::cout << "Street Contents:" << std::endl;
    for( int i = 0; i < street.get_size(); i++ )
    {
        Building* building = street.at( i );
        building->print( std::cout );
        std::cout << std::endl;
    }

    // Libération de la mémoire utilisée par les objets 'Building' dans
    // 'street'.
    for( int id_b = 0; id_b < street.get_size(); id_b++ )
    {
        delete street.at( id_b );
    }

    // Affichage d'un message et attente de l'appui sur la touche "Entrée" avant
    // de quitter le programme.
    std::cout << "Press enter to exit...";
    std::cin.get();
    return 0; // Terminaison normale du programme.
}