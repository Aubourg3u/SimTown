#include </mnt/c/Caumon/building.cpp>

class Street : public Building
{
public:
    Street( int id, int streetId );
    ~Street();
    t private : int streetId_;
};

Street::Street( int id, int streetId ) : Building( id ), streetId_( streetId )
{
    std::cout << "Street::Street(" << id << ", " << streetId << ")"
              << std::endl;
}

Street::~Street()
{
    std::cout << "~Street " << streetId_ << std::endl;
}
