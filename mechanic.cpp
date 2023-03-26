
#include "mechanic.h"


mechanic:: mechanic(){
  counter = 0;
}

bool mechanic::isavailable(appointment ap){ //incomplete
int f=0;
  for (int i = 0; i < counter+1; i++)
  {
    if(apps[i].hours==ap.hours&&apps[i].mins==ap.mins){f++;i=counter;}
  }
  if(f==0){return 1;}
  else{
    return 0;}
}


void mechanic::setcounter(int x){
  counter = x;}

void mechanic::setappointments(appointment app){
  apps[counter].hours = app.hours;
  apps[counter].mins = app.mins;
  counter++;

}

int mechanic::getcounter(){
  return counter;}

appointment mechanic::getappointment(){
  return apps[counter];
}
void mechanic::print(){
  cout << "Name is : "<< name<< endl;
  cout << "ID is : "<< ID;
  
}


