//************************************************************************** 
//
// Programming Excerise 4   
// CLASS: COSC 1437.3S7 
// AUTHOR: TYLER ECHOLS 
// DATE: Jul 2017  
//
//************************************************************************** 

#ifndef PERSON_H 
#define PERSON_H 

#include <iostream>
using namespace std;

#include "String.h" 
#include "Name.h"
#include "Address.h"

class Person
{
public:
	Person();
	Person(const Person &);
	Person(const Name &, const Address &);
	~Person();
	Person &			Copy(const Person &);
	const	Name &	    getName() const;
	const	Address &	getAddress() const;
	bool				setName(const Name &);
	bool				setAddress(const Address &);
	Person &			operator =	(const Person &);

private:
	Name	name;
	Address address;
};

istream & operator >> (istream &, Person &);

ostream & operator << (ostream &, const Person &);

inline const Name & Person::getName() const
{
	return name;
}

inline const Address & Person::getAddress() const
{
	return address;
}


#endif



