#include <iostream>
#include <string>
#include <cstdlib>
#include "plane.h"
Plane::Plane(string in_title , int in_capacity){
  title=in_title;
  capacity=in_capacity;
  passengerCompartmentNum=1+rand()%5;
  passComp=new passengerCompartment*[passengerCompartmentNum];
  isReady=0;
  

  for (int i=0 ; i<passengerCompartmentNum ; i++){

    passComp[i]=new passengerCompartment();
  }
  cout<<"A new PLANE has just created" << endl;
}

Plane::~Plane(){
  cout<<"A PLANE has just destroyed" <<endl;
}

void Plane::process(employee* pr_emp){
  cargoB.process(pr_emp);

  for (int i=0 ; i<3 ; i++) eqComp[i].process(pr_emp);
  //cout<<"Has" << this->passengerCompartmentNum <<"passengerCompartments"<<endl;
  for (int i=0 ; i<passengerCompartmentNum ; i++) passComp[i]->process(pr_emp);
}



void Plane::ready_check(){
  this->beReady();
  if (isReady) cout<<"Plane ready to take off!" <<endl;
  else cout<<"Plane NOT ready to take off!" <<endl;

}
myString Plane::toString(){
  myString str("Plane with name " + title + " and capacity : " + to_string(capacity)+ " with " +to_string(passengerCompartmentNum)  + " passengerCompartments , ");
  str.myConcat(Object::toString());
  return str;
}


                  // ---accessors

int Plane::getNum(){
  return passengerCompartmentNum;
}

cargoBay* Plane::returnCB(){
  cargoBay* cb;
  cb=&cargoB;
  return cb;
}

equipmentCompartment* Plane::returnEC(){
  return eqComp ;
}

passengerCompartment** Plane::returnPC(){
  return passComp;
}

void  Plane::beReady(){
  int limit=this->passengerCompartmentNum;
  int cargoCheck=0,passCompCheck=0,equipCompCheck=0;
  if (cargoB.allOk()) cargoCheck=1; //cargo is ready
  //cout<<"cargoCheck = " <<cargoCheck <<endl;
  for(int i=0 ; i<3 ; i++){
    if (eqComp[i].allOk()) {
      equipCompCheck=1;
      continue;
    }
    else equipCompCheck=0;
    break;
  }
  //cout<<"equipCompCheck = " <<equipCompCheck <<endl;
   //equipment is READY
  for(int i=0 ; i<limit ; i++){
    if(passComp[i]->allOk())  {
      passCompCheck=1;
      continue;
    }
    else passCompCheck=0;
  }
  //cout<<"passCompCheck = " <<passCompCheck <<endl;

  if (cargoCheck&&equipCompCheck&&passCompCheck) this->isReady= 1;
  else this->isReady= 0;
}
