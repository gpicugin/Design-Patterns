#include <QDebug>
#include <iostream>

using namespace std;

class Singleton
{
private:
    static Singleton* singleton;
    Singleton(){}
    Singleton(const Singleton&) = delete;
    Singleton& operator =(const Singleton&) = delete;
public:
    static Singleton* get() 
    {
        qDebug() << __PRETTY_FUNCTION__;
        if(singleton != nullptr)
            return singleton;
        else
        {
            qDebug() << "was created";
            singleton = new Singleton();
            return singleton;
        }
    }
    static void doSmth()
    {
        qDebug() << "do smth";
    }
    
    static void deleteSingleton()
    {
        qDebug() << __PRETTY_FUNCTION__;
        if(singleton != nullptr)
            delete singleton;
    }
};

Singleton* Singleton::singleton = nullptr; // Инициализация статического члена


int main()
{
    Singleton* single = Singleton::get();
    single = Singleton::get();
    single->doSmth();
    Singleton::deleteSingleton();
    return 0;
}
