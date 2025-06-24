#include <iostream>

using namespace std;

class Builder {
private:
				/* same things */
				virtual void setTable()  = 0;
				virtual void setPC()				 = 0;
				virtual void setChair()  = 0;
				/* differrent things */
				virtual void setMonitor() = 0;
				virtual void setPaper()			= 0;
				virtual void setPhone()	  = 0;
				virtual void setCalc()			 = 0;
				/* final */
public:
				virtual void build()				 = 0;
				virtual ~Builder() { cout << "destructor of builder \n"; };

};

class Programmer {

};

class Engineer;
class Boss;
class Accountant;

class ProgrammerBuilder : public Builder 
{
private:
				Programmer* programmer;
public:
				void setTable() { };
				void setPC() { };
				void setChair() { };
				void setMonitor() { };
				void setPaper() { };
				void setPhone() { };
				void setCalc() { };
				
				void build() {
								setTable();
								setPC();
								setChair();
								setMonitor();
				}
				
				Programmer* getResult() {
								programmer = new Programmer();
								return programmer;
				};
				
				~ProgrammerBuilder() {
								delete programmer;
								cout << "destructor of ProgrammerBuilder \n";
				};
};

class EngineerBuilder;
class BossBuilder;
class AccountantBuilder;

class Director {
private:
				Builder* m_builder;
public:
				Director(Builder* builder) { m_builder = builder; };
};


int main()
{
				ProgrammerBuilder* pB = new ProgrammerBuilder();
				Director director(pB);
				pB->build();
				delete pB;
				return 0;
}
