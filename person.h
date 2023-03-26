#ifndef PERSON
#define PERSON
#include <iostream>
#include <string>
using namespace std;



class person{
    protected:
    string name;
    int ID;
    int Age;

    public:
    person();
    void setname(string);
    void setID(int );
   void setAge(int );
    string getname();
    int getID();
    int getAge();
    virtual void print()=0;
};

struct appointment{
int hours;
int mins;
};

#endif