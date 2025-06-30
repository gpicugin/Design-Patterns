#include <iostream>
#include <QDebug>
using namespace std;

class Minivan {
public:
    virtual void goToFest() = 0;
    virtual ~Minivan() {qDebug() << "delete Base\n";}
};

class Sedan {
    void goToJob();
};

class Limousine {
    void goToParty();
};

class SportCar {
    void goToRace();
};

class AbstractFactory {
public:
    virtual Minivan*     createMinivan()     = 0;
    virtual Sedan*       createSedan()       = 0;
    virtual Limousine*   createLimousine()   = 0;
    virtual SportCar*    createSportCar()    = 0;
};

class MinivanLada : public Minivan {
    void goToFest() { qDebug() << "go to fest using lada minivan!\n"; }
    ~MinivanLada() { qDebug() << "delete minivan lada\n";}
};

class SedanLada : public Sedan {

};

class LimousineLada : public Limousine {

};

class SportCarLada : public SportCar {

};

class factoryLada : public AbstractFactory {
public:
    Minivan* createMinivan() { return new MinivanLada; }
    Sedan* createSedan() { return new SedanLada; }
    Limousine* createLimousine() { return new LimousineLada; }
    SportCar* createSportCar() { return new SportCarLada; }

};

int main()
{
    AbstractFactory* factory = new factoryLada;
    Minivan* van = factory->createMinivan();
    van->goToFest();
    delete van;
    delete factory;
    return 0;
}
