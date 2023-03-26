#include <iostream>
#include <string>
#include "person.h"
#ifndef CUSTOMER
#define CUSTOMER
using namespace std;

class customer : public person{

private:

int MechanicID;
appointment Appointment;


public:

void setMechanicID(int);

void setappointment(appointment);

int getMechanicID();

appointment getappointment();

bool operator  < (const customer &customer1);
bool operator  > (const customer &customer1);
bool operator == (const customer &customer1);

void print();
};

#endif