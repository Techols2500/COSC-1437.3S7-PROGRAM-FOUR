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


#include "Name.h" 
#include "Address.h"
#include "Person.h" 
#include "String.h" 


void main()
{
	Name n1;
	Name n2(String("William"), String("Tyler"), String("Echols"));
	Name n3(String("Kamen"), String("Rider"), String("Ex-Aid"));
	Name n4(n2);
	Name n5;
	Name n6;


	cout << "TESTING NAMES" << endl;
	//copy
	n6.Copy(n3);
	cout << "Testing the copy method: " << endl;
	cout << "Should be \"Kamen Rider Ex-Aid\": " << n6 << endl;

	//compare
	cout << "\nTesting the compare method: " << endl;
	cout << "Should be true(0): " << n2.Compare(n4) << endl;
	cout << "Should be false(not zero): " << n4.Compare(n3) << endl;

	//Getters and Setters
	cout << "\nTesting Getters and Setters: " << endl;
	n1.SetFirst(String("Fire"));
	cout << "SetFirst & GetFirst: Should be \"Fire\": " << n1.GetFirst() << endl;
	n1.SetMiddle(String("Wall"));
	cout << "SetMiddle & GetMiddle: Should be \"Wall\": " << n1.GetMiddle() << endl;
	n1.SetLast(String("Dragon"));
	cout << "SetLast & GetLast: Should be \"Dragon\": " << n1.GetLast() << endl;

	// = operator
	cout << "\nTesting the = operator: " << endl;
	n5 = n2;
	cout << "Should be \"William Tyler Echols\": " << n2.GetFirst() << " " << n2.GetMiddle() << " " << n2.GetLast() << endl;

	// == operator
	cout << "\nTesting the == operator: " << endl;
	cout << "Should be true (1): " << (n4 == n2) << endl;
	cout << "Should be false (0): " << (n2 == n3) << endl;


	// << operator
	cout << "\nTesting the << operator" << endl;
	cout << "Should be \"Fire Wall Dragon\": " << n1 << endl;

	// >> operator
	cout << "\nTesting the >> operator" << endl;
	cout << "Please enter a name: ";
	cin >> n5;
	cout << "Should match what you entered above:\n" << n5 << endl;

	//TESTING ADDRESSES
	//constructors
	Address a1;
	Address a2(String("2634 Custer Parkway"), String("Richardson"), String("Texas"), String("75080"));
	Address a3(String("2200 W University Dr"), String("McKinney"), String("Texas"), String("75071"));
	Address a4(a2);
	Address a5;
	Address a6;

	cout << "\n\n\nTESTING ADDRESSES" << endl;

	//copy
	a6.Copy(a3);
	cout << "Testing the copy method: " << endl;
	cout << "Should be \" 2200 W University Dr, McKinney, TX 75071\": " << a6 << endl;

	//compare
	cout << "\nTesting the compare method: " << endl;
	cout << "Should be true(1): " << a2.Compare(a4) << endl;
	cout << "Should be false(0): " << a4.Compare(a3) << endl;

	//Getters and Setters
	cout << "\nTesting Getters and Setters: " << endl;
	a1.SetStreet(String("9700 Wade Blvd"));
	cout << "SetStreet & GetStreet: Should be \"9700 Wade Blvd\": " << a1.GetStreet() << endl;
	a1.SetCity(String("Frisco"));
	cout << "SetCity & GetCity: Should be \"Frisco\": " << a1.GetCity() << endl;
	a1.SetState(String("Texas"));
	cout << "SetState & GetState: Should be \"Texas\": " << a1.GetState() << endl;
	a1.SetZip(String("75035"));
	cout << "SetZip & GetZip: Should be \"75035\": " << a1.GetZip() << endl;

	// = operator
	cout << "\nTesting the = operator: " << endl;
	a5 = a2;
	cout << "Should be \"2634 Custer Parkway, Richardson, Texas, 75080\": " << a2.GetStreet() << " " << a2.GetCity() << ", " << a2.GetState() << " " << a2.GetZip() << endl;

	// == operator
	cout << "\nTesting the == operator: " << endl;
	cout << "Should be true (1): " << (a4 == a2) << endl;
	cout << "Should be false (0): " << (a2 == a3) << endl;

	// << operator
	cout << "\nTesting the << operator" << endl;
	cout << "Should be \"9700 Wade Blvd, Frisco, TX 75035\": " << a1 << endl;

	// >> operator
	cout << "\nTesting the >> operator" << endl;
	cout << "Please enter an address: ";
	cin >> a5;
	cout << "Should match what you entered above:\n" << a5 << endl;

	//TESTING PERSON
	//constructors
	Person p1;
	Person p2(n2, a3);
	Person p3(n3, a2);
	Person p4(p2);
	Person p5;
	Person p6;

	//Getters and Setters
	cout << "\nTesting Getters and Setters: " << endl;
	p1.setName(n1);
	cout << "SetName & GetName: Should be \"Fire Wall Dragon\": " << p1.getName() << endl;
	p1.setAddress(a1);
	cout << "SetAddress & GetAddress: Should be \"9700 Wade Blvd, Frisco, TX 75035\": " << p1.getAddress() << endl;

	p6.Copy(p1);
	cout << "\nTesting the copy method: " << endl;
	cout << "Should be \"Fire Wall Dragon, 9700 Wade Blvd, Frisco, TX 75035\": " << p6 << endl;

	//= operator
	cout << "\nTesting the = operator: " << endl;
	p5 = p2;
	cout << "Should be \"William Tyler Echols, 2200 W University Dr, McKinney, TX 75071\": " << p5.getName() << ", " << p5.getAddress() << endl;

	//<< operator
	cout << "\nTesting the << operator" << endl;
	cout << "Should be \"Kamen Rider Ex-Aid, 2200 W University Dr, McKinney, TX 75071\": " << p3 << endl;

	// >> operator
	cout << "\nTesting the >> operator" << endl;
	cout << "Please enter a person: ";
	cin >> p5;
	cout << "Should match what you entered above:\n" << p5 << endl;

}