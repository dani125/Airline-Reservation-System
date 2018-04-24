#pragma once
#include <iostream>
#include <string>
#include <iomanip> 


using namespace std;

const int totalRow = 5;
class AircraftSeat
{
public:
	AircraftSeat();
	~AircraftSeat();
	AircraftSeat createSeats(string );
	void showSeats();
	string *seatOccupied(string *, int);
	
	
//private: 
	string rowA[totalRow];
	string rowB[totalRow];
	string rowC[totalRow];
	string rowD[totalRow];

};

