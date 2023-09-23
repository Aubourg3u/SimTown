#pragma once // Pour éviter les inclusions multiples

#include <iostream>
#include<class/storey.h> 

class Building {
public:
    Building(int id, int nb_floors);
    Building();

    virtual  ~Building();

    Building& operator=(const Building& rhs);
    Building(const Building& rhs);

    virtual std::string getType() const = 0;
    virtual void print(std::ostream& out) const;

private:
    int id_;
    Storey* storeys_;
    int nb_storeys_;
};

//==================================================================================================================================================================================================================================================


class House : public Building {
public:
    House(int id, int nb_floors);
    virtual ~House();
    virtual std::string getType() const override;
};

//==================================================================================================================================================================================================================================================

class Tower : public Building {
public:
    Tower(int id, int nb_floors);
    virtual ~Tower();
    virtual std::string getType() const override;
};

//==================================================================================================================================================================================================================================================

class TownHall : public Building {
public:
    TownHall(int id);
    virtual ~TownHall();
    virtual std::string getType() const override;
};
