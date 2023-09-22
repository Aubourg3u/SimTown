#include<iostream>
#include</mnt/c/Caumon/building.cpp>
#ifndef Storey
#define Storey
#endif

int main( int argc, char** argv ) {
  Building Building1(1,2);
  Building Building2(2,3);
  Building2 = Building1;
  
  Building2.print(std::cout);

  int size = 0;
  std::cout << " Welcome to SimTown, please enter the street size." << std::endl;
  std::cin >> size;

  Building** street_adress =new Building*[size];
  std::cout << "Street adress : " << street_adress << std::endl;
 
  Building* street = new Building[size];

  for (int id_b =0; id_b< size; id_b++) {
    street_adress[id_b] = new Building(id_b);
    street[id_b] = *(street_adress[id_b]);
  }

  {  
  Building* street_TH = new Building[size+1];
  for (int i =0; i < size; i++) {
  	street_TH[i] = street[i];
  }
  delete[] street;
  size+=1;
  street = street_TH;
  }
  {
  Building Town_Hall(666);
  street[size-1] = Town_Hall;
  }
  for (int i =0; i< size; i++) {
	 if (street_adress[i] != nullptr) {
		street_adress[i]->print(std::cout);
	 }
  }

  delete[] street_adress; 
  delete[] street;
  return 0; // Normal termination
} 
