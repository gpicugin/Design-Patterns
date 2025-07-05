#include <QDebug>
#include <vector>
using namespace std;

struct Color {
    int r, g, b;
};
struct Point
{
    int x, y;
    Color color;
};

struct Rect
{
    Point center;
    int width, height;
};

struct Circ
{
    Point center;
    int radius;
};

class iDrawer //realisation
{
public:
    virtual void drawPoint(Point p) = 0;
    virtual void drawPoints(std::vector<Point> points) = 0;
    
};

class DrawerLinux : public iDrawer
{
public:
    virtual void drawPoint(Point p)                     override { qDebug() << "draw point Linux"; }
    virtual void drawPoints(std::vector<Point> points)  override { qDebug() << "draw few points Linux";}

};

class DrawerMAC : public iDrawer
{
public:
    virtual void drawPoint(Point p)                     override { qDebug() << "draw point MAC"; }
    virtual void drawPoints(std::vector<Point> points)  override { qDebug() << "draw few points MAC";}
};

class DrawerWindows : public iDrawer
{
public:
    virtual void drawPoint(Point p)                     override { qDebug() << "draw point Windows"; }
    virtual void drawPoints(std::vector<Point> points)  override { qDebug() << "draw few points Windows";}
};

class Figure // abstraction
{
public:
    iDrawer* m_drawer;
    Figure(iDrawer* drawer) { m_drawer = drawer; }
    ~Figure() {}
    virtual void draw() = 0;
};

class Rectangle : protected Figure
{
private:
    Rect m_rect;
    std::vector<Point> rectToPoints()
    {
        qDebug() << __PRETTY_FUNCTION__;
        return std::vector<Point>({ {1,2, 3}, {0,0,0} });
    }
    
public:
    Rectangle(Rect rect, iDrawer* drawer) : Figure(drawer) { m_rect = rect; }    
    virtual void draw() override
    {
        qDebug() << __PRETTY_FUNCTION__;
        m_drawer->drawPoints(rectToPoints());
    }
};

class Circle : protected Figure
{
private:
    Circ m_circ;
    std::vector<Point> circToPoints()
    {
        qDebug() << __PRETTY_FUNCTION__;
    }
public:
    Circle(Circ circle, iDrawer* drawer) : Figure(drawer) { m_circ = circle; }
    
    virtual void draw() override
    {
        m_drawer->drawPoints(circToPoints());
    }
};

int main()
{
    Rect rect;
    DrawerLinux* drawerLinux = new DrawerLinux;
    Rectangle rectangleLinux(rect, drawerLinux);
    rectangleLinux.draw();

    return 0;
}
