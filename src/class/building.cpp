#include <class/building.h>

// Constructor for the 'Building' class, taking 'id' and 'nb_floors' as
// parameters.
Building::Building( int id, int nb_floors )
    : id_( id ), storeys_( nullptr ), nb_storeys_( nb_floors )
{
    std::cout << " At " << this << std::endl;
    // Dynamically allocate memory for 'storeys_' based on 'nb_floors'.
    storeys_ = new Storey[nb_storeys_];
}

// Default constructor for the 'Building' class.
Building::Building() : id_( -1 ), storeys_( nullptr ), nb_storeys_( 0 )
{
    std::cout << " At " << this << std::endl;
}

// Destructor for the 'Building' class.
Building::~Building()
{
    // Deallocate the memory used by 'storeys_'.
    delete[] this->storeys_;
    std::cout << "~Building " << id_ << " at " << this << std::endl;
}

// Assignment operator overload for the 'Building' class.
Building& Building::operator=( const Building& rhs )
{
    std::cout << "Building::Operator=( " << rhs.id_ << " ) at this " << this
              << std::endl;
    if( this == &rhs )
    {
        return *this;
    }
    else
    {
        // Delete the current 'storeys_' and copy data from 'rhs'.
        delete[] storeys_;
        this->id_ = rhs.id_;
        this->nb_storeys_ = rhs.nb_storeys_;

        // Allocate new memory for 'storeys_' and copy data.
        this->storeys_ = new Storey[this->nb_storeys_];
        for( int i = 0; i < this->nb_storeys_; ++i )
        {
            this->storeys_[i] = rhs.storeys_[i];
        }

        return *this;
    }
}

// Copy constructor for the 'Building' class.
Building::Building( const Building& rhs )
    : id_( rhs.id_ ), storeys_( nullptr ), nb_storeys_( rhs.nb_storeys_ )
{
    std::cout << "Building::Building ( rhs = " << &rhs << " , id = " << rhs.id_
              << " at " << this << " )" << std::endl;

    if( rhs.storeys_ != nullptr )
    {
        // Allocate memory for 'storeys_' and copy data.
        storeys_ = new Storey[rhs.nb_storeys_];

        for( int floor = 0; floor < nb_storeys_; ++floor )
        {
            storeys_[floor] = rhs.storeys_[floor];
        }
    }
}

// Print function for the 'Building' class.
void Building::print( std::ostream& out ) const
{
    out << " Building " << id_ << " at " << this << std::endl;
    out << " Type: " << getType() << std::endl;
    out << " Floors \n";
    for( int floor = 0; floor < nb_storeys_; ++floor )
    {
        out << storeys_[floor] << std::endl;
    }
}

//==================================================================================================================================================================================================================================================

// Constructor for the 'House' class, inheriting from 'Building'.
House::House( int id, int nb_floors ) : Building( id, nb_floors )
{
    std::cout << "Creating a House at " << this << std::endl;
}

// Destructor for the 'House' class.
House::~House() {}

// Get the type of the 'House' class.
std::string House::getType() const
{
    return "House";
}

//==================================================================================================================================================================================================================================================

// Constructor for the 'Tower' class, inheriting from 'Building'.
Tower::Tower( int id, int nb_floors ) : Building( id, nb_floors )
{
    std::cout << "Creating a Tower at " << this << std::endl;
}

// Destructor for the 'Tower' class.
Tower::~Tower() {}

// Get the type of the 'Tower' class.
std::string Tower::getType() const
{
    return "Tower";
}

//==================================================================================================================================================================================================================================================

// Constructor for the 'TownHall' class, inheriting from 'Building'.
TownHall::TownHall( int id ) : Building( id, 3 )
{
    std::cout << "Creating a City Hall at " << this << std::endl;
}

// Destructor for the 'TownHall' class.
TownHall::~TownHall() {}

// Get the type of the 'TownHall' class.
std::string TownHall::getType() const
{
    return "City Hall";
}