#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
static int in_id=0;

class myString;
class Object {
  public:
    Object();
    ~Object();
    int compare_equal(const Object& ob);
    int compare_identical(const Object &ob);
    Object clone (const Object& ob);

    myString toString();
    int getiD();
  private:
      int iD;
      string description;
};


class myString : public Object {
  public:
    myString(const string str);
    int myLength();
    void myClear();
    void myPrint();
    void myConcat(const myString& str);
    char myAt(int i);
    void myUpdateAt(int i , const char c);
    string getBuffer();
  private:
    string buffer;
  };


#endif
