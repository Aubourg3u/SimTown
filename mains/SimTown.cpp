#include <class/MyVector.h>
#include <class/building.h>
#include <class/globals.h>
#include <class/storey.h>

#include <cstdlib>

int main( int argc, char** argv )
{
    g_mode = "mute"; // Mode to hide all noisy cout in building and storey

    int size = 0;
    std::cout << "Welcome to SimTown, please enter the street size."
              << std::endl;
    std::cin >> size;

    // Using MyVector to store buildings
    MyVector< Building* > street;

    for( int id_b = 0; id_b < size; id_b++ )
    {
        std::cout << "Chose the building type: 1 for building, 2 four house"
                  << std::endl;
        int type;
        std::cin >> type;

        std::cout << "Chose the building's number of floors" << std::endl;
        int height;
        std::cin >> height;

        if( type == 1 )
        {
            street.push_back( new Tower( id_b, height ) );
        }
        else
        {
            street.push_back( new House( id_b, height ) );
        }
    }

    // Creating an object named 'TownHall"
    TownHall* townHall = new TownHall( 666 );

    street.push_back( townHall );

    std::cout << "Street Contents:" << std::endl;
    for( int i = 0; i < street.get_size(); i++ )
    {
        Building* building = street.at( i );
        building->display( std::cout );
        std::cout << std::endl;
    }

    for( int id_b = 0; id_b < street.get_size(); id_b++ )
    {
        delete street.at( id_b );
    }

    std::cout << "Press enter to exit...";
    std::cin.get();
    return 0; // Terminaison normale du programme.
}