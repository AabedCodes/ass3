#include <iostream>
#include <string>
#include "customer.h"


void customer::setMechanicID(int x){
  MechanicID = x;}

void customer::setappointment(appointment app){
  Appointment.hours = app.hours;
  Appointment.mins = app.mins;
  ;}

int customer::getMechanicID(){
  return MechanicID;}

appointment customer::getappointment(){
  return Appointment;}


bool customer::operator == (const customer &customer1)
{
	if((customer1.Appointment.hours == Appointment.hours)&&(customer1.Appointment.mins == Appointment.mins))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool customer::operator > (const customer &customer1)
{
	if((Appointment.hours > customer1.Appointment.hours)||((Appointment.hours == customer1.Appointment.hours)&&(Appointment.mins > customer1.Appointment.mins)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool customer::operator < (const customer &customer1)
{
	if((Appointment.hours < customer1.Appointment.hours)||((Appointment.hours == customer1.Appointment.hours)&&(Appointment.mins < customer1.Appointment.mins)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void customer::print(){
  cout << "Name of Custoemr: "<< name <<endl;
  cout << "Age: "<< Age << endl;}
