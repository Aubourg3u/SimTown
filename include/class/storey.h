#ifndef STOREY_H
#define STOREY_H

#include <iostream>

class Storey {
public:
    Storey();
    Storey(const Storey &rhs);
    ~Storey();
    Storey& operator=(const Storey &rhs);

    friend std::ostream& operator<<(std::ostream& out, const Storey& storey);

private:
    static int serial_number_;
    int uid_;
    int source_;
};

#endif // STOREY_H
