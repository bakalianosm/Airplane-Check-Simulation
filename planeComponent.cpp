#include <iostream>
#include <string>
#include <cstdlib>
#include "planeComponent.h"
using namespace std;


planeComponent::planeComponent(){
  cout<<"A new planeComponent has just made " << endl;
}

planeComponent::~planeComponent(){
  cout<<"A planeComponent is about to be destroyed" <<endl;
}

myString planeComponent::toString(){
  myString str("planeComponent , ");
  str.myConcat( Object::toString() );
  return str;
}
// ----------------------------passengerCompartment----------------------------
passengerCompartment::passengerCompartment(){
  isSecured=0;
  hasAnotherPC=rand()%2;

  //if (hasAnotherPC) new passengerCompartment;

  cout << "Constructing a passengerCompartment"<<"with iD = " <<getiD() <<endl;
}

passengerCompartment::~passengerCompartment(){
  cout << "A passengerCompartment is about to be destroyed" <<endl;
}


void passengerCompartment::ready_check(){
  if (isSecured) cout<<"passengerCompartment is OK !" << endl;
  else cout<<"passengerCompartment NOT OK" <<endl;
}


void passengerCompartment::process(employee *emp){
  cout << "Processing in passengerCompartment "<<endl;
  emp->workOn(this);
  cout<<endl;
}


myString passengerCompartment::toString(){
  myString str("passengerCompartment ,");
  str.myConcat(planeComponent::toString());
  return str;

}
int passengerCompartment::getSize(){
  return size;
}


void passengerCompartment::setSecured(){
  isSecured=1;
  cout<<"passengerCompartment now is secured " << endl;
}

void passengerCompartment::checkSec(){
  if (isSecured) cout<<"PASSENGER IS SECURED"<<endl;
  else cout<<"PASSENGER NOT SECURED"<<endl;
}

int passengerCompartment::allOk(){
  if (isSecured) return 1;
  else return 0;
}
// ----------------------------privateCompartment---------------------------------------
privateCompartment::privateCompartment(){
  size=101+ ( rand()%100 );
  cout << "Constructing a privateCompartment with size " << size <<endl;
}

privateCompartment::~privateCompartment(){
  cout << "A passengerCompartment is about to be destroyed" <<endl;
}

myString privateCompartment::toString(){
  myString str ("privateCompartment with size = " + to_string(size) + " , ");
  str.myConcat(planeComponent::toString() );
  return str;
}

int privateCompartment::getSize(){
  return size;
}

// ----------------------------equipmentCompartment----------------------------
equipmentCompartment::equipmentCompartment(){
  isSecured=0;
  isCleaned=0;
  isMaintained=0;
  cout << "An equipmentCompartment has just created " <<"with iD = " <<getiD()<< endl;
}
equipmentCompartment::~equipmentCompartment(){
  cout << "An equipmentCompartment is about to be destroyed " << endl;
}

void equipmentCompartment::ready_check(){

  if(isCleaned&&isSecured&&isMaintained) cout << "equipmentCompartment is OK" << endl;
  else cout<<"equipmentCompartment NOT OK" <<endl;
}

void equipmentCompartment::process(employee * emp){
  cout<<"Processing in equipmentCompartment  "<<endl;
  emp->workOn(this);
  cout<< endl;
}

myString equipmentCompartment::toString(){
  myString str("equipmentCompartment , ");
  str.myConcat( privateCompartment::toString() );
  return str;
}

void equipmentCompartment::setSecured(){
  isSecured=1;
  cout<<"equipmentCompartment is is Maintained"<<endl;
}

void equipmentCompartment::setCleaned(){
  isCleaned=1;
  cout<<"equipmentCompartment is Cleaned "<<endl;
}
void equipmentCompartment::setMaintained(){
  isMaintained=1;
  cout<<"equipmentCompartment is is Maintained"<<endl;
}

void equipmentCompartment::checkSec(){
  if (isSecured) cout <<"EQUIPMENT is secured"<<endl;
  else cout<<"EQUIPMENT NOT secured" <<endl;
}
void equipmentCompartment::checkCl(){
  if (isCleaned) cout <<"EQUIPMENT is Cleaned"<<endl;
  else cout<<"EQUIPMENT NOT Cleaned" <<endl;
}
void equipmentCompartment::checkMaint(){
  if (isMaintained) cout <<"EQUIPMENT is Maintained"<<endl;
  else cout<<"EQUIPMENT NOT maintained" <<endl;
}

int equipmentCompartment::allOk(){
  if(isSecured&&isCleaned&&isMaintained) return 1;
  else return 0;

}
// ----------------------------cargoBay------------------------------------

cargoBay::cargoBay(){
  isSecured=0;
  isCleaned=0;
  isMaintained=0;
  cout << "A cargo bay has just created " <<"with iD = " <<getiD()<< endl ;
}

cargoBay::~cargoBay(){

  cout << "A cargo bay is aboout to be destroyed " << endl ;
}

void cargoBay::ready_check() {
  if(isCleaned&&isSecured&&isMaintained) cout << "CargoBay is OK" << endl;
  else cout<<"CargoBay NOT OK" <<endl;

}

void cargoBay::process(employee * emp){
   cout<<"Processing in cargoBay " <<endl;
   emp->workOn(this);
  cout<< endl;
}
myString cargoBay::toString(){
  myString str("cargoBay , ");
  str.myConcat(privateCompartment::toString());
  return str;
}

void cargoBay::setSecured(){
  isSecured=1;
  cout<<"cargoBay is Secured"<<endl;
}
void cargoBay::setCleaned(){
  isCleaned=1;
  cout<<"cargoBay is Cleaned "<<endl;
}
void cargoBay::setMaintained(){
  isMaintained=1;
  cout<<"cargoBay is is Maintained"<<endl;
}

void cargoBay::checkSec(){
  if (isSecured) cout <<"CARGO BAY is secured"<<endl;
  else cout<<"CARGO BAY NOT secured" <<endl;
}
void cargoBay::checkCl(){
  if (isCleaned) cout <<"CARGO BAY is Cleaned"<<endl;
  else cout<<"CARGO BAY NOT Cleaned" <<endl;
}
void cargoBay::checkMaint(){
  if (isMaintained) cout <<"CARGO BAY is Maintained"<<endl;
  else cout<<"CARGO BAY NOT Maintained" <<endl;
}

int cargoBay::allOk(){
  if(isSecured&&isCleaned&&isMaintained) return 1;
  else return 0;

}
