#include <iostream>
#include <string>
#include "person.h"
using namespace std;

person::person(){
  name = "";
  ID =0;
  Age = 0;}

string person::getname(){
  return name;}

int person::getID(){
  return ID;}

int person::getAge(){
  return Age;}

void person::setname(string x){
  name = x;}

void person::setID(int x){
  ID = x;}

void person::setAge(int x){
  Age = x;}





