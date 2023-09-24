#include </mnt/c/Caumon/building.cpp>
#include <iostream>

int main( int argc, char** argv )
{
    int size = 0;
    std::cout << " Welcome to SimTown, please enter the street size."
              << std::endl;
    std::cin >> size;

    Building** street = new Building*[size];
    std::cout << "Street adress : " << street << std::endl;

    for( int id_b = 0; id_b < size; id_b++ )
    {
        street[id_b] = new Building( id_b );
    }

    for( int i = 0; i < size; i++ )
    {
        if( street[i] != nullptr )
        {
            street[i]->print( std::cout );
        }
    }

    for( int i = 0; i < size; i++ )
    {
        delete street[i];
    }

    delete[] street;
    return 0; // Normal termination
}
