#include <iostream>
#include <string>
#include <cstdlib>
#include "utilities.h"
using namespace std;


Object::Object(){
  iD=in_id++;
  cout << "Object has just created" << endl;
}


Object::~Object(){
  iD=in_id--;
  cout << "Object has just destroyed" << endl;
}

myString Object::toString(){
  myString str("Object with iD = " +  to_string(iD) + "\n") ;
  return str;
}

int Object::getiD(){
  return iD;
}

int Object::compare_identical(const Object& ob) {
	if (this == &ob)
		return 1;
	else  return 0;
}
myString::myString(const string str){
  buffer=str;
}


int myString::myLength(){
  return buffer.length();
}

void myString::myClear(){
  buffer.clear();
}

//------------------------------MYSTRING----------------------------------------
void myString::myPrint(){
  cout<<buffer<<endl;
}
void myString::myConcat(const myString& str){
buffer=buffer+ (str.buffer);
}

char myString::myAt(int i ){
  char c= buffer.at(i);
  return c;
}

void myString::myUpdateAt(int i , const char c ){
  buffer[i]=c;
}

string myString::getBuffer(){
  return buffer;
}
