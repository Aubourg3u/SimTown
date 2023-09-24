#include <class/storey.h>
#include <class/globals.h>

int Storey::serial_number_ =
    1; // Initialize the static member variable 'serial_number_' to 1.

// Default constructor for the 'Storey' class.
Storey::Storey() : source_( serial_number_ ), uid_( serial_number_ )
{
    serial_number_ += 1;
    if( g_mode == "verbose" )
    {
        std::cout << " Storey::Storey() : id " << uid_ << " at " << this
                  << std::endl;
    }

}

// Copy constructor for the 'Storey' class.
Storey::Storey( const Storey& rhs )
    : source_( rhs.source_ ), uid_( serial_number_ )
{
    if( g_mode == "verbose" )
    {
        std::cout << " Storey::Storey( const &rhs = id : " << rhs.uid_
                  << " ), uid = " << uid_ << " at " << this << std::endl;
    }
    serial_number_++;

}

// Destructor for the 'Storey' class.
Storey::~Storey()
{
    if( g_mode == "verbose" )
    {
        std::cout << " Storey::~Storey at " << this << std::endl;
    }
}

// Assignment operator overload for the 'Storey' class.
Storey& Storey::operator=( const Storey& rhs )
{
    if( this != &rhs )
    {
        if( g_mode == "verbose" )
        {
            std::cout << " Storey::operator= (rhs uid = " << rhs.uid_
                      << " ) , uid = " << uid_ << " at " << this << std::endl;
        }
        source_ = rhs.source_;
        uid_ = serial_number_;
        serial_number_ += 1;
    }
    return *this;
}

// Friend function to overload the '<<' operator for 'Storey' objects.
std::ostream& operator<<( std::ostream& out, const Storey& storey )
{
    out << " --Storey " << &storey << " : id = " << storey.uid_
        << " source : " << storey.source_ << " , NFT = " << storey.source_;
    return out;
}