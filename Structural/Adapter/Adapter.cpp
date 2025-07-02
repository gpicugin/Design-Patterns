#include <QDebug>
#include <vector>

using namespace std;

class Servise
{
public:
    int workWithDataStd(vector<int> data)
    {
        int result = 0;

        for(int element : data)
            result += element;

        return result;
    }
    ~Servise() {}
};

class Client
{
public:
    int workWithDataQt(QVector<QString> data) { return 0;}
};

class Adapter : protected Servise, public Client
{
public:
    int workWithDataQt(QVector<QString> dataQt)
    {
        vector<int> dataStd;

        for (QString element : dataQt)
        {
            dataStd.push_back(element.toInt());
        }
        return workWithDataStd(dataStd);
    }
    ~Adapter() {}

};

int main()
{

    QVector<QString> dataQt = {"1", "2", "3"};
    vector<int> dataStd = {1,2,3};

    // Client*  client  = new Client();
    Servise* service = new Servise();
    Adapter* adapter = new Adapter();

    qDebug() << service->workWithDataStd(dataStd);
    qDebug() << adapter->workWithDataQt(dataQt);

    return 0;
}
