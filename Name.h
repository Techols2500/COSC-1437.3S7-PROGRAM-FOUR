//************************************************************************** 
//
// Programming Excerise 4   
// CLASS: COSC 1437.3S7 
// AUTHOR: TYLER ECHOLS 
// DATE: Jul 2017  
//
//************************************************************************** 

#ifndef NAME_H 
#define NAME_H 

#include "String.h"

class Name
{
	//______________________ Methods _______________________________________
public:
	Name();
	Name(const Name &);
	Name(const String &, const String & = String(""), const String & = String(""));
	~Name();
	int					Compare(const Name &) const;
	Name &				Copy(const Name &);
	const	String &	GetFirst() const;
	const	String &	GetLast() const;
	const	String &	GetMiddle() const;
	bool				SetFirst(const String &);
	bool				SetLast(const String &);
	bool				SetMiddle(const String &);
	Name &				operator =	(const Name &);
	bool				operator ==	(const Name &) const;
	bool			operator < (const Name &) const;
	bool			operator <= (const Name &) const;
	bool			operator >  (const Name &) const;
	bool			operator >= (const Name &) const;
	bool			operator != (const Name &) const;
	//______________________ Methods _______________________________________
private:
	String		First;
	String		Middle;
	String		Last;
};

//______________________ Method Definitions _______________________________________
istream & operator >> (istream &, Name &);

ostream & operator << (ostream &, const Name &);

inline const String & Name::GetFirst() const
{
	return First;
}

inline const String & Name::GetMiddle() const
{
	return Middle;
}


inline const String & Name::GetLast() const
{
	return Last;
}



inline bool Name::operator == (const Name & N) const
{
	return Compare(N) == 0;
}

inline bool Name::operator < (const Name & N) const
{
	return Compare(N) < 0;
}

inline bool Name:: operator <= (const Name & N) const
{
	return Compare(N) <= 0;
}

inline bool Name:: operator > (const Name & N) const
{
	return Compare(N) > 0;
}

inline bool Name:: operator >= (const Name & N) const
{
	return Compare(N) >= 0;
}

inline bool Name:: operator != (const Name & N) const
{
	return Compare(N) != 0;
}



#endif

