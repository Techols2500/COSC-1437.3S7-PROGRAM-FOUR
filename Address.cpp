//************************************************************************** 
//
// Programming Excerise 4   
// CLASS: COSC 1437.3S7 
// AUTHOR: TYLER ECHOLS 
// DATE: Jul 2017  
//
//**************************************************************************  
#include "Address.h" 

Address::Address()
{
}

Address::Address(const Address & L)
{
	Street = L.Street;
	City = L.City;
	State = L.State;
	Zip = L.Zip;
}

Address::Address(const String & S, const String & C, const String & St, const String & Z)
{
	Street = S;
	City = C;
	State = St;
	Zip = Z;
}

Address::~Address()
{
}

Address & Address::Copy(const Address & L)
{
	Street = L.Street;
	City = L.City;
	State = L.State;
	Zip = L.Zip;
	return *this;
}

bool Address::Compare(const Address & L) const
{
	int	result;

	result = Street.Compare(L.Street);
	if (result == 0)
	{
		result = City.Compare(L.City);
		if (result == 0)
		{
			result = State.Compare(L.State);
			if (result == 0)
			{
				result = Zip.Compare(L.Zip);
			}
		}
	}
	if (result == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Address::SetStreet(const String & S)
{
	Street = S;
	return true;
}

bool Address::SetCity(const String & C)
{
	City = C;
	return true;
}

bool Address::SetState(const String & St)
{
	State = St;
	return true;
}

bool Address::SetZip(const String & Z)
{
	Zip = Z;
	return true;
}


Address & Address::operator = (const Address & L)
{
	Street = L.Street;
	City = L.City;
	State = L.State;
	Zip = L.Zip;

	return *this;
}

bool Address::operator == (const Address & L) const
{
	if ((Street == L.Street) && (City == L.City) && (State == L.State) && (Zip == L.Zip))
	{
		return true;
	}
	else
	{
		return false;
	}
}

istream & operator >> (istream & in, Address & L)
{
	String	temp;

	in >> temp;
	L.SetStreet(temp);
	in >> temp;
	L.SetCity(temp);
	in >> temp;
	L.SetState(temp);
	in >> temp;
	L.SetZip(temp);
	return in;
}

ostream & operator << (ostream & out, const Address & L)
{
	out << L.GetStreet() << " " << L.GetCity() << ", " << L.GetState() << " " << L.GetZip();
	return out;
}

