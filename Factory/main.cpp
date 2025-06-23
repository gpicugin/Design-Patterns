#include <iostream>

using namespace std;

class iDelivier {
				public:
								virtual void deliver() = 0;
								virtual ~iDelivier() {cout << "delete base\n";};
};

class Сourier : public iDelivier {
				public:
								void deliver() {
												cout << "courier\n";
								}
};

class Car : public iDelivier {
				public:
								void deliver() {
												cout << "Car\n";
								}
				~Car() { cout << "delete car\n"; }
};

class SpaceShip : public iDelivier {
				public:
								void deliver() {
												cout << "space ship\n";
								}
};


class iCompany {
				public:
								void deliver() {
												iDelivier* delivier = createDelivier();
												delivier->deliver();
												delete delivier;
								}
				private:
								virtual	iDelivier* createDelivier() = 0;
};

class Amazon : public iCompany {
				public:

				private: 
								iDelivier* createDelivier(){ return new Car;}
};

class Apple : public iCompany {
				private: 
								iDelivier* createDelivier(){ return new Сourier;}
};

class SpaceX : public iCompany {
				private: 
								iDelivier* createDelivier(){ return new SpaceShip;}
};


int main()
{

				Amazon amazon;
				amazon.deliver();

				return 0;
}
