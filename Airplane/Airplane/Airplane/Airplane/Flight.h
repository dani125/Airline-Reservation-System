#pragma once
#include <iostream>
#include <string>
#include "AircraftSeat.h"

using namespace std; 

const int totalSeat = 20;

class Flight:public AircraftSeat
{
public:
	Flight();
	~Flight();
	void setDeparture(string ); 
	string getDeparture();

	void setArrival(string);
	string getArrival();

	void setDepartTime(string );
	string getDepartTime();

	void setArrivalTime(string );
	string getArrivalTime();
	
	void setFlightNumber(int );
	int getFlightNumber();
	
	void setAircraftType(string );
	string  getAircraftType();

	void setFlighPoints(int);
	int getFlightPoints();

	void setSeats(); 
	void getSeats(); 

	string displayFlightInfo(); 

	void freeSeat(string); 
	void seatTaking(string );
	bool flightOverBook();
	string checkAvailability(string ); 
	
	
	
private: 
	string departure; 
	string arrival; 
	string departTime; 
	string arrivalTime; 
	int flightNumber; 
	string airCraftType;
	int flightPoints; 
	
	AircraftSeat allSeat[totalSeat];

	

	

	



};


