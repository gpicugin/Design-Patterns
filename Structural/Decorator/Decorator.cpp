#include <QDebug>


class iWeapon {
public:
    virtual void doDamage() = 0;
};

class SimpleWeapon : public iWeapon {
public:
    virtual void doDamage() override { qDebug() << "do damage"; }
};

class CompositeWeapon : public iWeapon
{
protected:
    iWeapon* m_weapon;
public: 
    CompositeWeapon(iWeapon* weapon) { m_weapon = weapon; }
    virtual void doDamage() override { m_weapon->doDamage(); }
};

class ThrustWeapon : public CompositeWeapon
{
public:
    ThrustWeapon(iWeapon* weapon) : CompositeWeapon(weapon) { }
    virtual void doDamage() override { qDebug() << "trust!!"; m_weapon->doDamage(); }
};

class HitWeapon : public CompositeWeapon
{
public:
    HitWeapon(iWeapon* weapon) : CompositeWeapon(weapon) { }
    virtual void doDamage() override { qDebug() << "hit!!"; m_weapon->doDamage(); }
};

class CutWeapon : public CompositeWeapon
{
public:
    CutWeapon(iWeapon* weapon) : CompositeWeapon(weapon) { }
    virtual void doDamage() override { qDebug() << "cut!!"; m_weapon->doDamage(); }
};


int main()
{
    SimpleWeapon* stick = new SimpleWeapon();    
    CompositeWeapon* weapon = new CompositeWeapon(stick);
    CompositeWeapon* knife = new CutWeapon(weapon);
    CompositeWeapon* smallSword = new HitWeapon(knife);
    CompositeWeapon* longSword = new ThrustWeapon(smallSword);

    longSword->doDamage();
    
    return 0;
}
