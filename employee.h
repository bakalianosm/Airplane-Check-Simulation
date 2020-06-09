#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include <cstdlib>
#include "utilities.h"
// #include "object.h"
// #include "myString.h"
#include "planeComponent.h"
class passengerCompartment;
class equipmentCompartment;
class cargoBay;

class employee : public Object{
  public:
      employee(string in_name);
      ~employee();
      string getName();
      virtual void report()=0;
      virtual void workOn(passengerCompartment* pass_comp){};
      virtual void workOn(equipmentCompartment* eq_comp ){};
      virtual void workOn(cargoBay *c_bay)=0;
      myString toString();
  private:
      string name;

};

class securityEmployee : public employee {
  public:
    securityEmployee(string emp_name);
    ~securityEmployee();
    void report();
    myString toString();
    void workOn(passengerCompartment *pass_comp);
    void workOn(equipmentCompartment *eq_comp);
    void workOn(cargoBay *c_bay);
  private:
};

class maintenanceEmployee : public employee {
  public:
    maintenanceEmployee(string emp_name);
    ~maintenanceEmployee();
    void report();
    myString toString();
    void workOn(equipmentCompartment* eq_comp );
    void workOn(cargoBay *c_bay);
  private:
};


class cleaningEmployee : public employee {
  public:
    cleaningEmployee(string emp_name);
    ~cleaningEmployee();
    void report();
    myString toString();
    void workOn(equipmentCompartment* eq_comp );
    void workOn(cargoBay *c_bay);
  private:
};

#endif
