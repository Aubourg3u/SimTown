#ifndef STOREY_H
#define STOREY_H

#include <iostream>

class Storey {
public:
    // Default constructor for the 'Storey' class.
    Storey();

    // Copy constructor for the 'Storey' class.
    Storey(const Storey& rhs);

    // Destructor for the 'Storey' class.
    ~Storey();

    // Assignment operator overload for the 'Storey' class.
    Storey& operator=(const Storey& rhs);

    // Friend function to overload the '<<' operator for 'Storey' objects.
    friend std::ostream& operator<<(std::ostream& out, const Storey& storey);

private:
    static int serial_number_; // Static member variable to track serial numbers.
    int uid_;                 // Unique identifier for each 'Storey' object.
    int source_;              // A source identifier for 'Storey' objects.
};

#endif // STOREY_H
