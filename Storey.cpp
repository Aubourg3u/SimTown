#include<iostream>

class Storey {

	public:
		Storey() : source_ (serial_number_),uid_ ( serial_number_ ) {
			serial_number_ +=1;
			std::cout << " Storey::Storey() : id "<< uid_<< " at " << this << std::endl;
		};

		Storey(const Storey &rhs) : source_ (rhs.source_), uid_ ( serial_number_ ) {
			serial_number_++;
			std::cout << " Storey::Storey( const &rhs = id : " << rhs.uid_ << " ), uid = " << uid_ << " at " << this << std::endl;	
		};
		
		~Storey() {
			std::cout << " Storey::~Storey at " << this << std::endl;
		};

		Storey& operator=( const Storey &rhs) {
			if (this != &rhs) {
		 		std::cout << " Storey::operator= (rhs uid = " << rhs.uid_ << " ) , uid = " << uid_ << " at " << this << std::endl;
				source_ = rhs.source_;
				uid_ = serial_number_;
				serial_number_ +=1;
			}
			return *this;
		};

		friend std::ostream& operator<< (std::ostream& out, const Storey& storey);
	
	private:
		static int serial_number_; // variable globale sort of
		int uid_;
		int source_;

};

int Storey::serial_number_ = 1;

std::ostream& operator<<(std::ostream& out, const Storey& storey){
	//not a member function =, friend to access private informations
	out << " --Storey " << &storey << " : id = " << storey.uid_ << " source : " << storey.source_ <<" , NFT = " << storey.source_;
	return out;
}

