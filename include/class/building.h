#include <iostream>
#include "storey.cpp"

class Building {
public:
  Building(int id, int nb_floors);
  Building();

  ~Building();

  Building& operator=(const Building& rhs);
  Building(const Building& rhs);

  void print(std::ostream& out ) const {
	out << " Building " << id_ << " at " << this  << std::endl;
        out << " Floors \n";
	for (int floor = 0; floor < nb_storeys_; ++floor) {
		out << storeys_[floor] << std::endl;
	}	
  }

private: 
  int id_;
  Storey* storeys_;
  int nb_storeys_;
};

Building::Building(int id, int nb_floors = 1 ) : id_( id ), storeys_(nullptr), nb_storeys_(nb_floors) {
	std::cout << " At " << this << std::endl;
	storeys_ = new Storey[nb_storeys_];
}
Building::Building() : id_(-1), storeys_(nullptr), nb_storeys_(0){
	std::cout << " At " << this << std::endl;
}
Building::~Building() { 
	delete[] this->storeys_;
	std::cout << "~Building " << id_ << " at " << this << std::endl;
}

Building& Building::operator=(const Building& rhs) {
	std::cout << "Building::Operator=( " << rhs.id_ << " ) at this " << this << std::endl; 
	if (this == &rhs ) {
            return *this; 
        } else {
	    this -> id_ = rhs.id_;
    	    return *this ;   
        };	
}

Building::Building(const Building& rhs) : id_(rhs.id_), storeys_(nullptr), nb_storeys_(rhs.nb_storeys_) {
    std::cout << "Building::Building ( rhs = " << &rhs << " , id = " << rhs.id_ << " at " << this << " )" << std::endl;

    if (rhs.storeys_ != nullptr) {
        // Allouer un nouveau tableau de Storey
        storeys_ = new Storey[rhs.nb_storeys_];

        // Copier chaque élément du tableau rhs.storeys_ dans storeys_
        for (int floor = 0; floor < nb_storeys_; ++floor) {
            storeys_[floor] = rhs.storeys_[floor]; // Assurez-vous que Storey a un opérateur d'assignation approprié.
        }
    }
}

;

