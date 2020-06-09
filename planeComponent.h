#ifndef PLANECOMPONENT_H
#define PLANECOMPONENT_H
#include <iostream>
#include <string>
#include <cstdlib>
#include "utilities.h"
#include "employee.h"

class employee;
class planeComponent : public Object {
  public:
    planeComponent();
    ~planeComponent();
    virtual void ready_check()=0;
    virtual void process(employee *emp)=0;
    virtual void setSecured()=0;
    virtual int allOk()=0;
    myString toString();
    void getReady();
  private:
};

class passengerCompartment : public planeComponent{

  public:
    passengerCompartment();
    ~passengerCompartment();
    void ready_check();
    void process(employee *emp);
    myString toString();
    int getSize();
    void setSecured();
    int allOk();
    void checkSec(); //axristi
  private:
    int size;
    int isSecured;
    int hasAnotherPC;
  };

  class privateCompartment : public planeComponent {
    public:
      privateCompartment();
      ~privateCompartment();
      virtual void ready_check()=0;
      virtual void process(employee * emp)=0;
      virtual void setSecured(){};
      virtual void setMaintained(){};
      virtual void setCleaned(){};
      virtual int allOk(){};
      myString toString();
      int getSize();
    private:
       int size;
  };

  class equipmentCompartment : public privateCompartment {
    public:
      equipmentCompartment();
      ~equipmentCompartment();
      void ready_check();
      myString toString();
      void process(employee * emp);
      void setSecured();
      void setMaintained();
      void setCleaned();
      //axristes einai
      void checkSec();
      void checkCl();
      void checkMaint();
      int allOk();

    private:
      int isSecured;
      int isCleaned;
      int isMaintained;

  };


class cargoBay : public privateCompartment {

  public:
    cargoBay();
    ~cargoBay();
    void ready_check();
    myString toString();
    void process(employee * emp);
    void setSecured();
    void setMaintained();
    void setCleaned();
    //axristes einai
    void checkSec();
    void checkCl();
    void checkMaint();
    int allOk();
  private:
    equipmentCompartment equipmentInCB;  //ο χωρος εμπορευμάτων περιλαμβάνει και έλαν Χώρο εξοπλισμού
    int isSecured;
    int isCleaned;
    int isMaintained;
};


#endif
