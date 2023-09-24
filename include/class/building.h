#pragma once // Pour éviter les inclusions multiples

#include <class/storey.h>
#include <iostream>

class Building
{
public:
    // Constructor for the 'Building' class, taking 'id' and 'nb_floors' as
    // parameters.
    Building( int id, int nb_floors );

    // Default constructor for the 'Building' class.
    Building();

    // Destructor for the 'Building' class.
    virtual ~Building();

    // Assignment operator overload for the 'Building' class.
    Building& operator=( const Building& rhs );

    // Copy constructor for the 'Building' class.
    Building( const Building& rhs );

    // Virtual function to get the type of the building (pure virtual, to be
    // implemented by derived classes).
    virtual std::string getType() const = 0;

    // Virtual function to print information about the building (to be
    // implemented by derived classes).
    virtual void print( std::ostream& out ) const;

        // Méthode pour afficher le bâtiment sous forme de dessin.
    virtual void display( std::ostream& out ) const;

    int getNbStoreys() const;

private:
    int id_;
    Storey* storeys_;
    int nb_storeys_;
};

//==================================================================================================================================================================================================================================================

class House : public Building
{
public:
    // Constructor for the 'House' class, inheriting from 'Building'.
    House( int id, int nb_floors );

    // Destructor for the 'House' class.
    virtual ~House();

    // Get the type of the 'House' class.
    virtual std::string getType() const override;

    virtual void display( std::ostream& out ) const override;
};

//==================================================================================================================================================================================================================================================

class Tower : public Building
{
public:
    // Constructor for the 'Tower' class, inheriting from 'Building'.
    Tower( int id, int nb_floors );

    // Destructor for the 'Tower' class.
    virtual ~Tower();

    // Get the type of the 'Tower' class.
    virtual std::string getType() const override;

    virtual void display( std::ostream& out ) const override;
};

//==================================================================================================================================================================================================================================================

class TownHall : public Building
{
public:
    // Constructor for the 'TownHall' class, inheriting from 'Building'.
    TownHall( int id );

    // Destructor for the 'TownHall' class.
    virtual ~TownHall();

    // Get the type of the 'TownHall' class.
    virtual std::string getType() const override;

    virtual void display( std::ostream& out ) const override;
};