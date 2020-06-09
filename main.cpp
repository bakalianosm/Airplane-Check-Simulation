

#include <iostream>
#include <string>
//#include <crand>
#include <cstdlib>
#include <ctime>
#include "utilities.h"
#include "planeComponent.h"
#include "plane.h"
#include "employee.h"

// #include "object.h"
// #include "myString.h"
int main(void){

  srand(time(NULL));
  cout<<endl<<endl<<endl;



  Plane newPlane(" Superfortress " , 350 ) ;

  securityEmployee  sEmp("Michael");
  maintenanceEmployee mEmp("Sotiria");
  cleaningEmployee cEmp("Johnnie");

  sEmp.report();
  newPlane.process(&sEmp);

  mEmp.report();
  newPlane.process(&mEmp);

  cEmp.report();
  newPlane.process(&cEmp);

  cout<<endl<<endl;
  newPlane.ready_check();
  cout<<endl<<endl;



}
