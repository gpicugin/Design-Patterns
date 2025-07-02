#include <iostream>
#include <vector>
#include <QDebug>
using namespace std;

class iSword {
public:
    virtual iSword* clone() = 0;
    virtual void damaged() = 0;
    virtual ~iSword() { qDebug() << __PRETTY_FUNCTION__; }
};

class SmallSword : public iSword
{

private:
    int damage;
public:
    SmallSword() : damage(1) {}
    SmallSword(const SmallSword& smallSword) {
        damage = smallSword.damage;
    }
    
    ~SmallSword() {qDebug() << __PRETTY_FUNCTION__; }
    
    iSword* clone() {
        return new SmallSword(*this);
    }
    
    void damaged() {
        qDebug() << "SmallSword hits by " << damage;
    }
}; 

class Longsword : public iSword
{
private:
    int damage;

public:
    Longsword() : damage(2) {}
    Longsword(const Longsword& Longsword) {
        damage = Longsword.damage;
    }
    iSword* clone() {
        return new Longsword(*this);
    }
    
    void damaged() {
        qDebug() << "Longsword hits by " << damage;
    }
};

class Zweihander : public iSword
{
private:
    int damage;

public:
    Zweihander() : damage(3) {}
    Zweihander(const Zweihander& Zweihander) {
        damage = Zweihander.damage;
    }
    iSword* clone() {
        return new Zweihander(*this);
    }
    
    void damaged() {
        qDebug() << "Longsword hits by " << damage;
    }
}; 

int main()
{
    vector<iSword*> swords;
    SmallSword smallSword;
    Longsword longSword;
    Zweihander zweihander;
    swords.push_back(smallSword.clone());
    swords.push_back(longSword.clone());
    swords.push_back(zweihander.clone());
    
    for (iSword* sword : swords)
    {
        sword->damaged();        
    }

    return 0;
}
