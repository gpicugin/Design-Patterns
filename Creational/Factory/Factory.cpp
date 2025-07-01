#include <iostream>
#include <QDebug>

using namespace std;

enum delivierType {
    courier = 0,
    car,
    spaceShip    
};

class iDelivier {
    public:
        virtual void deliver() = 0;
        virtual ~iDelivier() { qDebug() << "delete base delivier"; };
};

class Сourier : public iDelivier {
    public:
        void deliver() {
            qDebug() << "courier";
        }
    ~Сourier() { qDebug() << "delete courier"; }
};

class Car : public iDelivier {
    public:
        void deliver() {
            qDebug() << "Car\n";
        }
        ~Car() { qDebug() << "delete car\n"; }
};

class SpaceShip : public iDelivier {
    public:
        void deliver() {
            qDebug() << "space ship\n";
        }
    ~SpaceShip() { qDebug() << "delete spaceShip\n"; }
};



class iCompany {
    public:
        void deliver(enum delivierType del) {
            iDelivier* delivier = createDelivier(del);
            delivier->deliver();
            delete delivier;
        }
    virtual ~iCompany() { qDebug() << "delete base company";}
    private:
        virtual	iDelivier* createDelivier(enum delivierType) = 0;
};

class Amazon : public iCompany {
public:
    ~Amazon() { qDebug() << "delete Amazon";}

private:
    iDelivier* createDelivier(enum delivierType delivier)
    { 
        qDebug() << __PRETTY_FUNCTION__;
        switch (delivier) 
        {
        case delivierType::courier :
        {
            return new Сourier;
            break;
        }
        case delivierType::car :
        {
            return new Car;                
            break;
        }
        case delivierType::spaceShip :
        {
            return new SpaceShip;        
            break;
        }
        default:
        {
            return new Сourier;
            break;
        }
        }
    }
};

class Apple : public iCompany 
{
    private:
    iDelivier* createDelivier(enum delivierType delivier)
    { 
        switch (delivier) {
            case delivierType::courier :
            {
                return new Сourier;
                break;
            }
            case delivierType::car :
            {
                return new Car;                
                break;
            }
            case delivierType::spaceShip :
            {
                return new SpaceShip;        
                break;
            }
            default:
            {
                return new Сourier;
                break;
            }
        }
    }
};

class SpaceX : public iCompany 
{
    private:
    iDelivier* createDelivier(enum delivierType delivier)
    { 
        switch (delivier) 
        {
            case delivierType::courier :
            {
                return new Сourier;
                break;
            }
            case delivierType::car :
            {
                return new Car;                
                break;
            }
            case delivierType::spaceShip :
            {
                return new SpaceShip;        
                break;
            }
            default:
            {
                return new Сourier;
                break;
            }
        }
    }
};


int main()
{
    Amazon amazon;
    amazon.deliver(delivierType::car);
    return 0;
}
