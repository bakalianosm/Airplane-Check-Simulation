#include <iostream>
#include <string>
#include <cstdlib>
#include "utilities.h"
#include "planeComponent.h"
#include "employee.h"

class Plane : public Object {
  public:
    Plane(string in_title , int in_capacity );
    ~Plane();
    void process(employee* pr_emp);
    void ready_check();
    myString toString();
    int getNum();
    cargoBay* returnCB();
    equipmentCompartment* returnEC();
    passengerCompartment** returnPC();
    void beReady();
  private:
    string title;
    int capacity;
    cargoBay cargoB;
    equipmentCompartment eqComp[3];
    passengerCompartment **passComp;
    int passengerCompartmentNum;
    int isReady;
};
