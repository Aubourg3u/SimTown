#include<class/resident.h>
#include<cstdlib>
#include<class/globals.h>
#include<iostream>

Resident::Resident( float wealth) : wealth_(rand() % 1000) {
    if( g_mode == "verbose" )
    {
        std::cout << "Resident::Resident wealth = " << wealth_ << " at " << this
                  << std::endl;
    };		
};


