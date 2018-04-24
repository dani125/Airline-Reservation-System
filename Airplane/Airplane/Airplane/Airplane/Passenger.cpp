#include "Passenger.h"
#include "Flight.h"


Passenger::Passenger()
{
}


Passenger::~Passenger()
{
}

void Passenger::setName(string firstName)
{
	this->firstName = firstName;
}

string Passenger::getName()const
{
	return firstName;
}

void Passenger::setLastName(string lastName)
{
	this->lastName = lastName; 
}

string Passenger::getLastName()
{
	return lastName; 
}

void Passenger::setPhoneNumber(string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

string Passenger::getPhoneNumber()
{
	return phoneNumber;
}

void Passenger::setFlightInfo(Flight flight)
{
	this->flight = flight; 
}



void Passenger::setSeatPassenger(string seatPassenger)
{
	this->seatPassenger = seatPassenger; 
}

string Passenger::getSeatPassenger()
{
	return seatPassenger; 
}

int Passenger::getPassengFlightNumber()
{
	return flight.getFlightNumber();
}



string Passenger::boardingPass()
{
	string boardingInfo = firstName + " "+lastName + " "+phoneNumber+" " + seatPassenger +" "+ flight.displayFlightInfo();
	
	return boardingInfo;
}

bool Passenger::operator==(const Passenger & rhs) const
{
	return firstName ==rhs.getName();
}






