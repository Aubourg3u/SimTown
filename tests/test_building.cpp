#include <class/building.h>

int main( int argc, char** argv )
{
    Tower Tower1( 1, 2 );
    Tower Tower2( 2, 4 );

    Tower1 = Tower2;

    House House1( 1, 2 );
    House House2( 2, 1 );

    House2 = House1;

    TownHall TH1( 0 );
    TownHall TH2( 1 );

    TH1 = TH2;

    return 0; // Normal program termination.
}