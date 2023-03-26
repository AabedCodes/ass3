#include <iostream>
#include "mechanic.h"
#include "person.h"
#include "customer.h"
#include <string>
#include <fstream>
#include "mechanic.cpp"
#include "person.cpp"
#include "customer.cpp"


const int Size = 4; // Size of mechanics

void sort(customer customers[]){
    for (int i = 0; i < 14; i++)
    {
        for (int j = i+1; j < 15; j++)
        {
            if(customers[i] > customers[j]){swap(customers[i],customers[j]);}
        }
    }
}

string searchbyID(mechanic a[Size], int x ){
    for (int i=0; i<Size; i++){
        if (x == a[i].getID())
        return a[i].getname();}
}

template <typename T>               // This following segment of the code is a generic class "Queue" with basic function definitions such as
class Queue {                       // isEmpty, Push, Pop, and front.
public:
    Queue() : head(nullptr), tail(nullptr), size(0) {}
    ~Queue() { clear(); }
    
    void push(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    
    void pop() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        if (isEmpty()) {
            tail = nullptr;
        }
    }
    
    T& front() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }
        return head->value;
    }
    
    bool isEmpty() const {
        return size == 0;
    }
    
    int getSize() const {
        return size;
    }
    
    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }
    
private:
    struct Node {
        T value;
        Node* next;
        
        Node(const T& value) : value(value), next(nullptr) {}
    };
    
    Node* head;
    Node* tail;
    int size;
};



int main (){

Queue<customer> kobry;      // declaring arbitrary queue to later on hold the sorted customers according to their appointed times.

mechanic mechanics[Size] ;  //assuming only 4 mechanics
customer customers [15];    //assuming only 15 customers
ifstream x,y;
string Name = "";
int Age, Id, i=0;
int hours, mins, o=0;
appointment app, add;
add.hours = INT_MIN;
add.mins = INT_MIN;

x.open("Mechanics.txt"); 
y.open("Customers.txt"); 


while (!x.eof()){           //reading input data from mechanics file
    x>> Name >> Age >> Id;
    mechanics[i].setname(Name);
    mechanics[i].setAge(Age);
    mechanics[i].setID(Id);
    i++;
}

while (!y.eof()){                 // reading input data from customers file and checking the availability of mechanics.
    y>> Name >> Age >> hours >> mins;           // if a mechanic is available, an appointment is set
    app.hours = hours;                          // otherwise, we check other mechanics for availability
    app.mins = mins;                            // if all are not available, customer's appointment data and mechanic ID are set to
    customers[o].setname(Name);                 // INT_MIN and 0, respectively.
    customers[o].setAge(Age);
    int num=0;
    for (int l=0; l<Size; l++){
        if (mechanics[l].isavailable(app)){
        customers[o].setappointment(app);
        mechanics[l].setappointments(app);
        customers[o].setMechanicID(mechanics[l].getID());
        num++;
        break;
        }
    }
    if (num==0){
        customers[o].setappointment(add); // this sets all customers' appointments with cancelled appointments to a specific hour and min (INT MIN) 
        customers[o].setMechanicID(0);      // this sets their mechanical ID to 0 to be traceable later
        cout << "\n"<<"-Appointment for "<< customers[o].getname() << " was cancelled."<< endl;

    }
    o++;
};

cout << "Before Sorting: " << endl << endl;     // Before sorting

for (int j =0; j<15; j++){
    if (!customers[j].getMechanicID()==0){
    customers[j].print();
    cout <<"Customer is registered with "<< searchbyID(mechanics, customers[j].getMechanicID());
cout <<endl<< "Appointment Time:  " << customers[j].getappointment().hours<< ":" << customers[j].getappointment().mins<<endl<<endl;
}
else{
    cout << "Customer " << customers[j].getname() << " is not registered with any mechanic."<<endl;
}
}

sort(customers);                                // Sorting
cout << endl;



for (int j =0; j<15; j++){                      // Filling the Queue with the customers array
    if (!customers[j].getMechanicID()==0)       // This filters the customers who don't have mechanic appointments
    kobry.push(customers[j]);
    else
    cout << "Customer " << customers[j].getname() << " is not registered with any mechanic."<<endl;
    

}
cout << endl<<endl;


cout << "After Sorting: " << endl << endl;    // After Sorting
                                                
while(!kobry.isEmpty()){
kobry.front().print();
cout <<"Customer is registered with "<< searchbyID(mechanics, kobry.front().getMechanicID());
cout <<endl<< "Appointment Time:  " << kobry.front().getappointment().hours<< ":" << kobry.front().getappointment().mins<<endl;
kobry.pop();
cout << endl<<endl;
};

x.close();              //closing file
y.close();              //closing file

    return 0;
}