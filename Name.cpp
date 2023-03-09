//************************************************************************** 
//
// Programming Excerise Final Project   
// CLASS: COSC 1437.3S7 
// AUTHOR: TYLER ECHOLS 
// DATE: Aug 2017 
//
//************************************************************************** 

#include "Name.h" 


Name::Name()
{
}

Name::Name(const Name & X)
{
	First = X.First;
	Middle = X.Middle;
	Last = X.Last;

}

Name::Name(const String & F, const String & M, const String & L)
{
	First = F;
	Last = L;
	Middle = M;
}

Name::~Name()
{
}

Name & Name::Copy(const Name & X)
{
	First = X.First;
	Middle = X.Middle;
	Last = X.Last;
	return *this;
}


int Name::Compare(const Name & X) const
{
	int	result;

	result = Last.Compare(X.Last);
	if (result == 0)
	{
		result = First.Compare(X.First);
		if (result == 0)
		{
			result = Middle.Compare(X.Middle);
		}
	}

	return result;
}

bool Name::SetFirst(const String & F)
{
	First = F;
	return true;
}

bool Name::SetMiddle(const String & M)
{
	Middle = M;
	return true;

}

bool Name::SetLast(const String & L)
{
	Last = L;
	return true;

}

Name & Name::operator = (const Name & X)
{
	First = X.First;
	Middle = X.Middle;
	Last = X.Last;
	return *this;
}

istream & operator >> (istream & in, Name & X)
{
	String	temp;

	in >> temp;
	X.SetFirst(temp);
	in >> temp;
	X.SetMiddle(temp);
	in >> temp;
	X.SetLast(temp);
	return in;
}

ostream & operator << (ostream & out, const Name & X)
{
	out << X.GetFirst() << " " << X.GetMiddle() << " " << X.GetLast();
	return out;
}




