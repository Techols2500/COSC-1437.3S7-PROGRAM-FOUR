//************************************************************************** 
//
// Programming Excerise 4   
// CLASS: COSC 1437.3S7 
// AUTHOR: TYLER ECHOLS 
// DATE: Jul 2017  
//
//**************************************************************************   

#include <iostream> 

using namespace std;

#include "Person.h"

Person::Person()
{

}

Person::Person(const Person & p)
{
	name = p.name;
	address = p.address;
}

Person::Person(const Name & n, const Address & a)
{
	name = n;
	address = a;
}

Person::~Person()
{

}

Person & Person::Copy(const Person & p)
{
	name = p.name;
	address = p.address;
	return *this;
}

bool Person::setName(const Name & n)
{
	name = n;
	return true;
}

bool Person::setAddress(const Address & a)
{
	address = a;
	return true;
}

Person & Person::operator = (const Person & p)
{
	name = p.name;
	address = p.address;
	return *this;
}

istream & operator >> (istream & in, Person & p)
{
	Name tempName;
	Address tempAddress;

	in >> tempName;
	p.setName(tempName);
	in >> tempAddress;
	p.setAddress(tempAddress);
	return in;
}

ostream & operator << (ostream & out, const Person & p)
{
	out << p.getName() << " , " << p.getAddress() << endl;
	return out;
}