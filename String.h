//************************************************************************** 
//
// Programming Excerise 4   
// CLASS: COSC 1437.3S7 
// AUTHOR: TYLER ECHOLS 
// DATE: Jul 2017  
//
//************************************************************************** 

#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

#ifdef WIN32
#define STRCMP_NO_CASE _strcmpi
#else
#define STRCMP_NO_CASE strcasecmp
#endif

class String
{
	//************* Exceptions *****
public:
	enum		Exceptions { IndexOutOfBounds };
	//************* Method Prototypes *****
public:
	explicit		String(const char * = "");
	String(const String &)				throw (...);
	virtual			~String()								throw ();
	int				Compare(const String &)		const	throw ();
	int				Compare(const char *)			const	throw ();
	String &		Concat(const String &)				throw (...);
	String &		Concat(const char *)					throw (...);
	String &		Copy(const String &)				throw (...);
	String &		Copy(const char *)					throw (...);
	ostream &		Display(ostream & = cout)		const	throw ();
	bool			GetAt(char &, int)			const	throw (...);
	bool			IsEmpty()						const	throw ();
	size_t			Length()						const	throw ();
	istream &		Read(istream & = cin)				throw (...);
	bool			SetAt(char, int)						throw (...);
	String &		ToLower()								throw ();
	String &		ToUpper()								throw ();
	operator bool()						const	throw ();
	operator const char *					()						const	throw ();
	String &		operator =				(const String &)				throw (...);
	String &		operator =				(const char *)					throw (...);
	bool			operator <				(const String &)		const	throw ();
	bool			operator <				(const char *)			const	throw ();
	bool			operator <=				(const String &)		const	throw ();
	bool			operator <=				(const char *)			const	throw ();
	bool			operator ==				(const String &)		const	throw ();
	bool			operator ==				(const char *)			const	throw ();
	bool			operator >=				(const String &)		const	throw ();
	bool			operator >=				(const char *)			const	throw ();
	bool			operator >				(const String &)		const	throw ();
	bool			operator >				(const char *)			const	throw ();
	bool			operator !=				(const String &)		const	throw ();
	bool			operator !=				(const char *)			const	throw ();
	String			operator &				(const String &)		const	throw (...);
	String			operator &				(const char *)			const	throw (...);
	String &		operator &=				(const String &)				throw (...);
	String &		operator &=				(const char *)					throw (...);
	char &			operator []				(int)							throw (...);
	char			operator []				(int)					const	throw (...);
private:
	bool			IsValidSubscript(int)					const	throw ();
	void			LocalCheckAndCopy(const char *)					throw (...);
	String &		LocalConcat(const char *)					throw (...);
	void			LocalCopy(const char *)					throw (...);
	String			NewConcat(const char *)			const	throw (...);
	static	char	ReadChar(istream & = cin)				throw ();
	operator char *							()						const	throw ();
	//************* Properties *****
private:
	char *	pChar;
	size_t	CharCount;
	size_t	MaxSize;
};

//************* Method Definitions *****

inline String::String(const char * p) : CharCount(0), MaxSize(0), pChar(0)
{
	LocalCopy(p);
}

inline String::String(const String & M)
{
	LocalCopy(M.pChar);
}

inline int String::Compare(const String & M) const
{
	return STRCMP_NO_CASE(pChar, M.pChar);
}

inline int String::Compare(const char * p) const
{
	return STRCMP_NO_CASE(pChar, p);
}

inline String & String::Concat(const String & M)
{
	return LocalConcat(M.pChar);
}

inline String & String::Concat(const char * p)
{
	return LocalConcat(p);
}

inline String & String::Copy(const String & M)
{
	return *this = M;
}

inline String & String::Copy(const char * p)
{
	return *this = p;
}

inline ostream & String::Display(ostream & out) const
{
	return out << pChar;
}

inline bool String::GetAt(char & c, int i) const
{
	if (IsValidSubscript(i))
	{
		c = pChar[i];
		return true;
	}
	else
		return false;
}

inline bool String::IsEmpty() const
{
	return Length() == 0;
}

inline bool String::IsValidSubscript(int i) const
{
	return (i >= 0) && (i < static_cast <int> (CharCount));
}

inline size_t String::Length() const
{
	return CharCount;
}

inline String String::NewConcat(const char * p) const
{
	String S(*this);
	S.Concat(p);
	return S;
}

inline String::operator bool() const
{
	return Length() > 0;
}

inline String::operator const char * () const
{
	return pChar;
}

inline String & String::operator = (const String & M)
{
	if (this != &M)
		LocalCheckAndCopy(M.pChar);
	else;
	return *this;
}

inline String & String::operator = (const char * p)
{
	LocalCheckAndCopy(p);
	return *this;
}

inline bool String::operator <	(const String & M) const
{
	return Compare(M) < 0;
}

inline bool String::operator <	(const char * p) const
{
	return Compare(p) < 0;
}

inline bool operator <	(const char * p, const String & S)
{
	return S.Compare(p) > 0;
}

inline bool String::operator <=	(const String & M) const
{
	return Compare(M) <= 0;
}

inline bool String::operator <=	(const char * p) const
{
	return Compare(p) <= 0;
}

inline bool operator <=	(const char * p, const String & S)
{
	return S.Compare(p) >= 0;
}

inline bool String::operator ==	(const String & M) const
{
	return Compare(M) == 0;
}

inline bool String::operator ==	(const char * p) const
{
	return Compare(p) == 0;
}

inline bool operator ==	(const char * p, const String & S)
{
	return S.Compare(p) == 0;
}

inline bool String::operator >=	(const String & M) const
{
	return Compare(M) >= 0;
}

inline bool String::operator >=	(const char * p) const
{
	return Compare(p) >= 0;
}

inline bool operator >=	(const char * p, const String & S)
{
	return S.Compare(p) <= 0;
}

inline bool String::operator >	(const String & M) const
{
	return Compare(M) > 0;
}

inline bool String::operator >	(const char * p) const
{
	return Compare(p) > 0;
}

inline bool operator >	(const char * p, const String & S)
{
	return S.Compare(p) < 0;
}

inline bool String::operator !=	(const String & M) const
{
	return Compare(M) != 0;
}

inline bool String::operator !=	(const char * p) const
{
	return Compare(p) != 0;
}

inline bool operator !=	(const char * p, const String & S)
{
	return S.Compare(p) != 0;
}

inline String String::operator & (const String & M) const
{
	return NewConcat(M.pChar);
}

inline String String::operator & (const char * p) const
{
	return NewConcat(p);
}

inline String operator & (const char * p, const String & S)
{
	String Temp(p);
	return Temp.Concat(S);
}

inline String &	String::operator &=	(const String & M)
{
	return Concat(M);
}

inline String &	String::operator &=	(const char * p)
{
	return Concat(p);
}

inline char & String::operator [] (int i)
{
	if (IsValidSubscript(i))
		return pChar[i];
	else
		throw IndexOutOfBounds;
}

inline char String::operator [] (int i) const
{
	return (*const_cast <String *> (this)).operator [] (i);
}

inline bool String::SetAt(char c, int i)
{
	if ((i >= 0) && (i < static_cast <int> (CharCount)))
	{
		pChar[i] = c;
		return true;
	}
	else
		return false;
}

inline ostream & operator << (ostream & out, const String & M)
{
	return M.Display(out);
}

inline istream & operator >> (istream & in, String & M)
{
	return M.Read(in);
}

#endif 



