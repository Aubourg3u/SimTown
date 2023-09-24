#include <iostream>

class Building
{
public:
    Building( int id );
    Building();

    ~Building();

    Building& operator=( const Building& rhs );

    void print( std::ostream& out ) const
    {
        out << " Building " << id_ << " at " << this << std::endl;
    }

private:
    int id_;
};

Building::Building( int id ) : id_( id )
{
    std::cout << " At " << this << std::endl;
}
Building::Building() : id_( -1 )
{
    std::cout << " At " << this << std::endl;
}
Building::~Building()
{
    std::cout << "~Building " << id_ << std::endl;
}

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
        this->id_ = rhs.id_;
        return *this;
    };
}

;
