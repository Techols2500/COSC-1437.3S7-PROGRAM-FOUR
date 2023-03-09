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

#include <memory.h> 

#include "String.h"

#ifndef	STRING_SIZE
#define	STRING_SIZE	50
#endif

String::~String()
{
	delete[] pChar;
}

#pragma warning (disable:4996)

istream & String::Read(istream & In)
{
	char			c;
	char *			pTemp;

	CharCount = 0;
	while (((c = ReadChar(In)) != '\n') && !In.eof())
	{
		pChar[CharCount++] = c;
		if (CharCount >= MaxSize)
		{
			pTemp = new char[(MaxSize += STRING_SIZE) + 1];
			memcpy(pTemp, pChar, CharCount);
			delete[] pChar;
			pChar = pTemp;
		}
		else;
	}
	pChar[CharCount] = '\0';
	return In;
}

char String::ReadChar(istream & in)
{
	return static_cast <char> (in.get());
}

String & String::LocalConcat(const char * p)
{
	CharCount += strlen(p);
	if (MaxSize < CharCount)
	{
		char * pTemp = new char[CharCount + 1];
		strcpy(pTemp, pChar);
		strcat(pTemp, p);
		delete[] pChar;
		pChar = pTemp;
		MaxSize = CharCount;
	}
	else
	{
		strncat(pChar, p, strlen(p));
		pChar[CharCount] = '\0';
	}
	return *this;
}

void String::LocalCheckAndCopy(const char * p)
{
	CharCount = strlen(p);
	if (CharCount > MaxSize)
	{
		delete[] pChar;
		MaxSize = CharCount;
		pChar = new char[CharCount + 1];
	}
	else;
	strcpy(pChar, p);
}

void String::LocalCopy(const char * p)
{
	CharCount = strlen(p);
	MaxSize = CharCount;
	pChar = new char[CharCount + 1];
	strcpy(pChar, p);
}

String & String::ToLower()
{
	for (int i = 0; pChar[i]; i++)
		pChar[i] = static_cast <char> (tolower(pChar[i]));
	return *this;
}

String & String::ToUpper()
{
	for (int i = 0; pChar[i]; i++)
		pChar[i] = static_cast <char> (toupper(pChar[i]));
	return *this;
}
