#include <class/building.h>

Building::Building(int id, int nb_floors) : id_(id), storeys_(nullptr), nb_storeys_(nb_floors) {
    std::cout << " At " << this << std::endl;
    storeys_ = new Storey[nb_storeys_];
}

Building::Building() : id_(-1), storeys_(nullptr), nb_storeys_(0) {
    std::cout << " At " << this << std::endl;
}

Building::~Building() {
    delete[] this->storeys_;
    std::cout << "~Building " << id_ << " at " << this << std::endl;
}

Building& Building::operator=(const Building& rhs) {
    std::cout << "Building::Operator=( " << rhs.id_ << " ) at this " << this << std::endl;
    if (this == &rhs) {
        return *this;
    }
    else {
        delete[] storeys_;
        this->id_ = rhs.id_;
        this->nb_storeys_ = rhs.nb_storeys_;

        this->storeys_ = new Storey[this->nb_storeys_];
        for (int i = 0; i < this->nb_storeys_; ++i) {
            this->storeys_[i] = rhs.storeys_[i];
        }

        return *this;
    }
}

Building::Building(const Building& rhs) : id_(rhs.id_), storeys_(nullptr), nb_storeys_(rhs.nb_storeys_) {
    std::cout << "Building::Building ( rhs = " << &rhs << " , id = " << rhs.id_ << " at " << this << " )" << std::endl;

    if (rhs.storeys_ != nullptr) {
        storeys_ = new Storey[rhs.nb_storeys_];

        for (int floor = 0; floor < nb_storeys_; ++floor) {
            storeys_[floor] = rhs.storeys_[floor]; 
        }
    }
}

void Building::print(std::ostream& out) const {
    out << " Building " << id_ << " at " << this << std::endl;
    out << " Type: " << getType() << std::endl;
    out << " Floors \n";
    for (int floor = 0; floor < nb_storeys_; ++floor) {
        out << storeys_[floor] << std::endl;
    }
}


//==================================================================================================================================================================================================================================================

House::House(int id, int nb_floors) : Building(id, nb_floors) {
    std::cout << "Creating a House at " << this << std::endl;
}

House::~House() {
}

std::string House::getType() const {
    return "House";
}

//==================================================================================================================================================================================================================================================

Tower::Tower(int id, int nb_floors) : Building(id, nb_floors) {
    std::cout << "Creating a Tower at " << this << std::endl;
}

Tower::~Tower() {
}

std::string Tower::getType() const {
    return "Tower";
}

//==================================================================================================================================================================================================================================================

TownHall::TownHall(int id) : Building(id, 3) {
    std::cout << "Creating a City Hall at " << this << std::endl;
}

TownHall::~TownHall() {
}

std::string TownHall::getType() const {
    return "City Hall";
}