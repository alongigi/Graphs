
#include <iostream>
#include "Vertice.h"
#include <exception>
using namespace std;

class undefinedVertice0:public exception {
	string message;
public:
	undefinedVertice0(string V1): message("Vertice "+V1+" undefined\n"){}
	const char* what() const throw(){
		return message.c_str();
	}
	virtual ~undefinedVertice0() throw() {}
};


class InvalidInput: public exception{
	const char* what() const throw(){
		return "Exception: Invalid Input\n";
	}
	//void Handle()const{cout<<"Exception: Invalid Input\n";};
};

class OutOfMemory: public exception{
	const char* what() const throw(){
			return "Exception Out of Memory\n";
		}
	//void Handle()const{cout<<"Exception Out of Memory\n";};
};

