//************************************************************************** 
//
// Programming Excerise 4   
// CLASS: COSC 1437.3S7 
// AUTHOR: TYLER ECHOLS 
// DATE: Jul 2017  
//
//************************************************************************** 

#ifndef ADDRESS_H 
#define ADDRESS_H 

#include "String.h"

class Address
{
	//______________________ Methods _______________________________________
public:
	Address();
	Address(const Address &);
	Address(const String &, const String & = String(""), const String & = String(""), const String & = String(""));
	~Address();
	bool				Compare(const Address &) const;
	Address &	Copy(const Address &);


	const	String &	GetStreet() const;
	const	String &	GetCity() const;
	const	String &	GetState() const;
	const	String &	GetZip() const;

	bool				SetStreet(const String &);
	bool				SetCity(const String &);
	bool				SetState(const String &);
	bool				SetZip(const String &);

	Address &		operator =	(const Address &);
	bool			operator ==	(const Address &) const;
	bool			operator != (const Address &) const;
	//______________________ Properties _______________________________________
private:
	String		Street;
	String		City;
	String		State;
	String		Zip;
};

//______________________ Method Definitions _______________________________________
istream & operator >> (istream &, Address &);

ostream & operator << (ostream &, const Address &);



inline const String & Address::GetStreet() const
{
	return Street;
}

inline const String & Address::GetCity() const
{
	return City;
}


inline const String & Address::GetState() const
{
	return State;
}

inline const String & Address::GetZip() const
{
	return Zip;
}


inline bool Address:: operator != (const Address & L) const
{
	return Compare(L) != true;
}


#endif 


