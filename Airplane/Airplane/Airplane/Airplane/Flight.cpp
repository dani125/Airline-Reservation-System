#include "Flight.h"
#include "AircraftSeat.h"


Flight::Flight()
{
}


Flight::~Flight()
{
}

void Flight::setDeparture(string departure)
{
	this->departure = departure; 
}

string Flight::getDeparture()
{
	return departure;
}

void Flight::setArrival(string arrival)
{
	this->arrival = arrival; 
}

string Flight::getArrival()
{
	return arrival;
}

void Flight::setDepartTime(string departTime)
{
	this->departTime = departTime; 
}

string Flight::getDepartTime()
{
	return departTime; 
}

void Flight::setArrivalTime(string arrivalTime)
{
	this->arrivalTime = arrivalTime;
}

string Flight::getArrivalTime()
{
	return arrivalTime;
}

void Flight::setFlightNumber(int flightNumber)
{
	this->flightNumber = flightNumber; 
}

int Flight::getFlightNumber()
{
	return flightNumber;
}

void Flight::setAircraftType(string airCraftType)
{
	this->airCraftType = airCraftType; 
	

}

string Flight::getAircraftType()
{
	return airCraftType;
}

void Flight::setFlighPoints(int flightPoints)
{
	this->flightPoints = flightPoints; 

}

int Flight::getFlightPoints()
{
	return flightPoints;
}

void Flight::setSeats( )
{
	allSeat->createSeats(airCraftType);
}

void Flight::getSeats()
{
	allSeat->showSeats(); 

}



void  Flight::seatTaking(string choosenSeat)
{
	
	
		for (int i = 0; i<totalRow; i++) {
			if (allSeat->rowA[i]== choosenSeat && allSeat->rowA[i]!="T") {
				allSeat->seatOccupied(allSeat->rowA, i);
				
			
			}
			else if (allSeat->rowB[i] == choosenSeat  && allSeat->rowB[i] != "T") {
				allSeat->seatOccupied(allSeat->rowB, i);

			}
			else if (allSeat->rowC[i] == choosenSeat  && allSeat->rowC[i] != "T" ) {
				allSeat->seatOccupied(allSeat->rowC, i);

			}
			else if (allSeat->rowD[i] == choosenSeat  && allSeat->rowD[i] != "T" ) {
				allSeat->seatOccupied(allSeat->rowD, i);

			}
		}

		
}










bool Flight::flightOverBook()
{
	int count = 0; 
	for (int i = 0; i < totalRow; i++) {
		if (airCraftType == "A") {
			if ((allSeat->rowA[i] == "T") && (allSeat->rowB[i] == "T") && (allSeat->rowC[i] == "T") && (allSeat->rowD[i] == "T")) {
				count++;
				if (count == 5) {
					return true; 
				}
			}
		}
	
		else  {
				if ((allSeat->rowA[i] == "T" )&& (allSeat->rowB[i] == "T") && (allSeat->rowC[i] == "T")) {
						count++;
					if (count == 5) {
					return true;
				}
			}
		}
	}
	return false; 
	
	
}

string Flight::checkAvailability(string choosenSeat)
{
	bool invalid=true; 
	while (invalid) {

		for (int i = 0; i < totalRow; i++) {
			if (allSeat->rowA[i] == choosenSeat && allSeat->rowA[i] !="T") {
				invalid = false; 
				goto end;

			}
			else if (allSeat->rowB[i] == choosenSeat && allSeat->rowB[i] != "T") {
				invalid = false;
				goto end;
			}
			else if (allSeat->rowC[i] == choosenSeat && allSeat->rowC[i] != "T") {
				invalid = false;
				goto end;
			}
			else if (allSeat->rowD[i] == choosenSeat && allSeat->rowD[i] != "T") {
				invalid = false;
				goto end;
			}

			
		}
		cout << "Invalid Input" << endl;
		cin >> choosenSeat;
	}
     end:; 
	return choosenSeat;
}

string Flight::displayFlightInfo()
{
	
	string allinfo= departure + " " + arrival + " " + departTime + " " + arrivalTime + " " + to_string(flightNumber) + " " + airCraftType + " " + to_string(flightPoints ) ;

	return allinfo; 

}

void Flight::freeSeat(string seat)
{//check second character if character is A,C,B,C use number for array 

		for (unsigned i = 0; i<seat.length(); ++i)	{
			int number = seat.at(0)-'0'; 
			switch (seat.at(1)) { 
			case'A':allSeat->rowA[number - 1] = seat; break; 
			case'B':allSeat->rowB[number - 1] = seat; break;
			case'C':allSeat->rowC[number - 1] = seat; break;
			case'D':allSeat->rowD[number - 1] = seat; break;
			
			
			}
				
		}
	
}







