#include <iostream>
#include <string>
#include <cstdlib>
#include "employee.h"

employee::employee(string in_name){
  name=in_name;
  cout<<"We just hire a new employee with name: " <<name << endl;
}

employee::~employee(){
  cout<<"We just fire employee with name: " << name << endl;
}
string employee::getName(){
  return name;
}

myString employee::toString(){
  myString str(" employee , ");
  str.myConcat(Object::toString());
  return str;
}
// ---------------------------securityEmployee-------------------------------------
securityEmployee::securityEmployee(string emp_name):employee(emp_name){
  cout<<"The new's securityEmployee's name is " << emp_name << " and has just hired" <<endl;
}

securityEmployee::~securityEmployee(){
  cout<<"Firing an employee" <<endl;
}

void securityEmployee::report(){
  cout << "It's time for SECURITY employee to give a report" << endl;
  cout << "...everything about security is OK"<<endl;
}


myString securityEmployee::toString(){
  myString str("securityEmployee with name " + getName() + " , ");
  str.myConcat(employee::toString());
  return str;
}

void securityEmployee::workOn(passengerCompartment* pass_comp){
  pass_comp->setSecured();
  cout<<"\t\t\t\tA SECURITY worked on passengerCompartment and proof that this compartment is READY"<<endl;;
}
void securityEmployee::workOn(equipmentCompartment* eq_comp){
  eq_comp->setSecured();
  cout<<"\t\t\t\tA SECURITY worked on equipmentCompartment and proof that this compartment is READY"<<endl;
}
void securityEmployee::workOn(cargoBay* c_bay){
  c_bay->setSecured();
  cout<<"\t\t\t\tA SECURITY worked on cargoBay and proof that this compartment is READY"<<endl;
}



// --------------------------------maintenanceEmployee--------------------------------

maintenanceEmployee::maintenanceEmployee(string emp_name):employee(emp_name){
  cout<<"The new's maintenanceEmployee's name is " << emp_name << " and has just hired" <<endl;
}



maintenanceEmployee::~maintenanceEmployee(){
  cout<<"Firing an employee" <<endl;
}

void maintenanceEmployee::report(){
  cout << "It's time for MAINTENANCE employee to give a report" << endl;
  cout << "...everything about maintenance is OK"<<endl;

}

myString maintenanceEmployee::toString(){
  myString str("maintenanceEmployee with name " + getName() + " , ");
  str.myConcat(employee::toString());
  return str;
}

void maintenanceEmployee::workOn(equipmentCompartment *eq_comp){
  eq_comp->setMaintained();
  cout<< "\t\t\t\tA maintenance Employee is working on EQUIPMENT compartment" <<endl;

}

void maintenanceEmployee::workOn(cargoBay *c_bay){
  c_bay->setMaintained();
  cout<<"\t\t\t\t\tA maintenanceEmployee is working on CARGO BAY compartment" <<endl;

}


 // ----------------------------cleaningEmployee------------------------------------


cleaningEmployee::cleaningEmployee(string emp_name):employee(emp_name){
   cout<<"The new's cleaningEmployee's name is " << emp_name << " and has just hired" <<endl;
}


cleaningEmployee::~cleaningEmployee(){
   cout<<"Firing an employee" <<endl;
}

void cleaningEmployee::report(){
   cout<<"It's time for cleaning employee to give a report"<<endl;
   cout<<"...everything about clean is OK."<<endl;
}

myString cleaningEmployee::toString(){
  myString str("cleaningEmployee with name " + getName() + " , ");
  str.myConcat(employee::toString());
  return str;
}


void cleaningEmployee::workOn(equipmentCompartment *eq_comp){
  eq_comp->setCleaned();
  cout << "A cleaning employee is working on EQUIPMENT compartment " <<endl;
}

void cleaningEmployee::workOn(cargoBay *c_bay){
  c_bay->setCleaned();
   cout<< "A cleaning employee is working on CARGO BAY compartment" << endl;

}
