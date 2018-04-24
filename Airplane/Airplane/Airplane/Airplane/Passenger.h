#pragma once
#include "Flight.h"
#include <string>
using namespace std; 

class Passenger
{
public:
	Passenger();
	~Passenger();
	void setName(string); 
	string getName() const; 
	void setLastName(string ); 
	string getLastName();
	void setPhoneNumber(string ); 
	string getPhoneNumber();
	void setFlightInfo(Flight); 
	
	void setSeatPassenger(string); 
	string getSeatPassenger();
	int getPassengFlightNumber(); 
	string boardingPass(); 
	
	
	bool operator==(const Passenger &rhs) const;
	
private: 
	string firstName; 
	string lastName; 
	string phoneNumber; 
	Flight flight; 
	string seatPassenger; 

};

