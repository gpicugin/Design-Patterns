#include <QDebug>
using namespace std;

class Warrior {
public :
    virtual void executeOrder() = 0;
    virtual ~Warrior() {};
};

class Squad : public Warrior {
private:
    QVector<Warrior*> warriors;
    void removeAll()            
    {
        foreach (Warrior* warrior, warriors) {
            delete warrior;
        }
        warriors.clear(); 
    }
public:
    void add(Warrior* warrior)  { warriors.push_back(warrior);}
    void remove(int index)      { warriors.remove(index); }
    void move(int a, int b)     { warriors.move(a, b); }
    void executeOrder() override 
    {
        for (Warrior* warrior : warriors) {
            warrior->executeOrder();
        }
    }
    virtual ~Squad() { removeAll(); }
};
class Soldier : public Warrior
{
    virtual void executeOrder() override { qDebug() << "Sir, yes Sir!!";}
    ~Soldier() { qDebug() << "soldier died...."; }
};

class Major : public Squad
{
public:
    Major() 
    {
        for(int i = 0; i < 4; i++)
            this->add(new Soldier); 
    }
    ~Major() {        
        qDebug() << "Major died...";
    }
};

class Captain : public Squad
{
public:
    Captain() 
    {
        for(int i = 0; i < 3; i++)
            this->add(new Major); 
    }
    ~Captain() {        
        qDebug() << "Captain died...";
    }
};

class General : public Squad
{
public:
    General() 
    {
        for(int i = 0; i < 2; i++)
            this->add(new Captain); 
    }
    ~General() {        
        qDebug() << "General died...";
    }
};

class General;



int main()
{
    Squad* squad = new Squad;
    General* general = new General;
    squad->add(general);
    squad->add(new Soldier);
    squad->executeOrder();
    delete squad;
    return 0;
}
