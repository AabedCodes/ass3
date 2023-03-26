#ifndef MECHANIC
#define MECHANIC
#include <iostream>
#include "person.h"


class mechanic : public person{
private:
int counter;
appointment apps[24]; //assume a max of 24 appointments per day

public:
mechanic();

bool isavailable(appointment);


void setcounter(int );

void setappointments(appointment );

int getcounter();

appointment getappointment();
void print();
};



#endif