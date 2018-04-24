#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <list>
#include <functional>
#include "Flight.h"
#include "Passenger.h"

using namespace std; 

const string fileName = "flightInfo.txt";
const string filePassenger = "listOfPassenger.txt";
const string cities = "listOfCities.txt"; 

void displayPassegerFlight(list<Passenger>, list<Flight>);
void displayAllFlights(list<Flight>);
void displayAllPassenger(list<Passenger>);
void mainMenu(list<Flight>, list<Passenger>);
void bookReservation(list<Flight>, list<Passenger>);
void displayAllcities(list<string>);
void displayFlightScheduleSorting(list<Flight>, list<Passenger>);
void cancelReservation(list<Flight>, list<Passenger>);
void displayPassengersFlightandSeat(list<Flight>, list<Passenger>);
list<Flight> readFileFlightSchedule(); 
void readFilePassegerInfo(list<Flight>);
void writeToFile( list<Passenger>);

int showsimilarFlights(list<Flight>allflights, int flightNumber, string arrival, string departure);
list<string>allCities(); 

bool greaterArrival( Flight& rhs,  Flight &rhs1){return rhs.getArrival() > rhs1.getArrival();}

bool greaterAircraftNumber(Flight& rhs, Flight &rhs1){return rhs.getFlightNumber() > rhs1.getFlightNumber();}

bool departureTime(Flight& rhs, Flight &rhs1){return rhs.getDepartTime() > rhs1.getDepartTime();}

bool arrivalTime(Flight& rhs, Flight &rhs1){return rhs.getArrivalTime() > rhs1.getArrivalTime();}

bool greaterAircraftType(Flight& rhs, Flight &rhs1){return rhs.getAircraftType() > rhs1.getAircraftType();}

bool greaterFlightPoints(Flight& rhs, Flight &rhs1){return rhs.getFlightPoints()> rhs1.getFlightPoints();}

bool departure(Flight& rhs, Flight &rhs1){return rhs.getDeparture()>rhs1.getDeparture();}

bool sortBySeat(Passenger & passenger1, Passenger &passenger12){return passenger1.getSeatPassenger()>passenger12.getSeatPassenger();}

bool sortByName(Passenger & passenger1, Passenger &passenger12){return passenger1.getName()>passenger12.getName();}

int main() {
	
	list<Flight>allflights = readFileFlightSchedule();
	readFilePassegerInfo(allflights);//read file for passenger and goes to main menu 
	
	system("pause");
	return 0;
}

void mainMenu(list<Flight>allflights, list<Passenger>allPassengers) {

	char answer = ' ';
	list<string>listOfCities = allCities();//read file available cities 
	while (answer != 'H' || tolower('H')) {
		cout << "A.Book a new reservation" << endl <<
			"B.Cancel a reservation" << endl <<
			"C.Display boarding pass for a passenger" << endl <<
			"D.Display flight schedule (sorted by any field)" << endl <<
			"E.Display available cities (sorted by name or code)" << endl <<
			"F.List passengers on a given flight and seat assignments (sorted by name or seat)" << endl <<
			"G.Save list of passenger" << endl<<
			"H.Exit" << endl;
		cin >> answer;

		if (answer == 'A' || answer == 'a') { bookReservation(allflights, allPassengers); }
		else if (answer == 'B' || answer == 'b') { cancelReservation(allflights, allPassengers); }
		else if (answer == 'C' || answer == 'c') {  displayPassegerFlight(allPassengers, allflights); }
		else if (answer == 'D' || answer == 'd') { displayFlightScheduleSorting(allflights, allPassengers); }
		else if (answer == 'E' || answer == 'e') { displayAllcities( listOfCities);	}
		else if (answer == 'F' || answer == 'f') { displayAllFlights(allflights);  displayPassengersFlightandSeat(allflights, allPassengers); }
		else if (answer == 'G' || answer == 'g') { cout << "List of Passengers have been save" << endl;  writeToFile(allPassengers); }
		else if(answer == 'H' || answer == 'h') { writeToFile(allPassengers); exit(0); }
		else {
			cout << "Invalid input. Choose A-H" << endl; 
			cin >> answer; 
		}
	}
}

list<Flight> readFileFlightSchedule() {

	list<Flight>allflights;

	ifstream file(fileName.c_str());
	string departure;
	string arrival;
	string departTime;
	string arrivalTime;
	int flightNumber;
	string airCraftType;
	int flightPoints;
	string dummyLine;
	getline(file, dummyLine);
	while (file >> departure >> arrival >> departTime >> arrivalTime >> flightNumber >> airCraftType >> flightPoints)
	{
		Flight flight;
		flight.setDeparture(departure);
		flight.setArrival(arrival);
		flight.setDepartTime(departTime);
		flight.setArrivalTime(arrivalTime);
		flight.setFlightNumber(flightNumber);
		flight.setAircraftType(airCraftType);
		flight.setSeats();
		flight.setFlighPoints(flightPoints);
		allflights.push_back(flight);
	}
	return allflights;
}
void readFilePassegerInfo(list<Flight>allFlights)
{
	list<Passenger>allPassengers;

	ifstream file(filePassenger.c_str());
	string firstName; 
	string lastName; 
	string phoneNumber; 
	string from; 
	string to;
	string hourArrival; 
	string hourdeparture; 
	int flightNumber; 
	string aircraftType; 
	int flightPoints; 
	string seat; 
	
	while (file >> firstName >> lastName >> phoneNumber >>seat>> from >> to >>hourdeparture >> hourArrival>>flightNumber>> aircraftType>> flightPoints){
		Passenger passenger;
		passenger.setName(firstName);
		passenger.setLastName(lastName);
		passenger.setPhoneNumber(phoneNumber);
		
		for (Flight &flights : allFlights) {

			if (flights.getFlightNumber()== flightNumber)  {
				passenger.setSeatPassenger(seat);
				flights.seatTaking(seat);
				flights.getDeparture();
				flights.getArrival();
				flights.getDepartTime();
				flights.getArrivalTime();
				flights.getFlightNumber();
				flights.getAircraftType();
				flights.getFlightPoints();
				passenger.setFlightInfo(flights);
				allPassengers.push_back(passenger);
				//use to not go back to reading all object on list 
				goto end; 
			}
		}
		
			end:;
	}
	mainMenu(allFlights, allPassengers);
}
void bookReservation(list<Flight>allflights, list<Passenger>allPassengers) {

	string chooseSeat;
	int flightNumber;
	string name;
	string lastName;
	string phonenumber;
	string arrival;
	string departure;
	
	cout << "Enter name" << endl;
	cin >> name;
	cout << "Enter last name" << endl;
	cin >> lastName;
	cout << "Enter phone number" << endl;
	cin >> phonenumber;
	
	Passenger newPassenger;
	newPassenger.setName(name);
	newPassenger.setLastName(lastName);
	newPassenger.setPhoneNumber(phonenumber);
	displayAllFlights(allflights);
	cout << "Enter flight Number" << endl;
	cin >> flightNumber;
	for (Flight &flights : allflights) {
	
		 if (flights.getFlightNumber() == flightNumber) {
			 if (flights.flightOverBook()) {
				 cout << "Flight is Book" << endl;
				 arrival = flights.getArrival();
				 departure = flights.getDeparture();
				 flightNumber = showsimilarFlights(allflights, flightNumber, arrival, departure);


			 }
			 else {

				 flights.getSeats();
				 cout << "Choose seat " << endl;
				 cin >> chooseSeat;
				 chooseSeat = flights.checkAvailability(chooseSeat);
				flights.seatTaking(chooseSeat);
				 newPassenger.setSeatPassenger(chooseSeat);

				 newPassenger.setFlightInfo(flights);
				 allPassengers.push_back(newPassenger);
			 }
		   	
	
		}
	
	}
	mainMenu(allflights, allPassengers);
}
//show similar flight and return new flight number
int showsimilarFlights(list<Flight>allflights, int flightNumber, string arrival, string departure) {
	cout << "Flight with similar Destination" << endl; 
	int newflightNumber = flightNumber; 
	for (Flight &flights : allflights) {
		if (flights.getArrival() == arrival && flights.getDeparture() == departure &&  flights.getFlightNumber() != flightNumber) {
			cout << flights.displayFlightInfo() << endl;


		}
	}
	while (newflightNumber == flightNumber) {
		cout << "Cannot be flight "<<flightNumber<< "Enter a new Flight number";
		cin >> newflightNumber;
	}

	return newflightNumber;
}



void cancelReservation(list<Flight>allflights, list<Passenger>allPassengers) {
	
	string firstName; 
	string lastName; 

	cout << "Enter first Name\n"; 
	cin >> firstName; 
	cout << "Enter last Name\n"; 
	cin >> lastName; 
	
	while (!allPassengers.empty()) {
		for (Passenger &passenger : allPassengers) {
			
				//get passenger name and last number iterate through flight list if flight number matches number to flight number remove passenger and update seat
				if ((passenger.getName() == firstName) && (passenger.getLastName()==lastName)) {
					for (Flight &flight : allflights) {
						if ( passenger.getPassengFlightNumber()== flight.getFlightNumber()) {
							flight.freeSeat(passenger.getSeatPassenger());
							allPassengers.remove(passenger);

							cout << "Reservation has been cancel" << endl;
							mainMenu(allflights, allPassengers);
						}
					}
					
					
				}
		}
		
	}
	
	mainMenu(allflights, allPassengers);
}





list<string> allCities()
{
	list<string>allcities; 
	
	ifstream file(cities.c_str());
	string abbr;
	string nameOfCity;
	string city; 
	

	while (file >> abbr ) {
		getline(file, nameOfCity);
		city = abbr + " "+nameOfCity; 
		allcities.push_back(city);


	}
	return allcities;
}

void displayFlightScheduleSorting(list<Flight>allFlights, list<Passenger>allPassengers) {

	int answer=0;
	
	while (answer != 8) {
		cout << "1.sort by departure\n" <<
				"2.sort by arrival\n" <<
				"3.sort by departure Time\n" <<
				"4.sort by arrival time\n" <<
				"5.sort by flight number\n" <<
				"6.sort by aircraft type\n" <<
				"7.sort by frequent flyer points\n" <<
				"8.main Menu\n" <<
			    "Choose a number" << endl;
	            cin >> answer;


		if (answer == 1) {
			allFlights.sort(departure);
			displayAllFlights(allFlights);
		}
		else if (answer == 2) {
			allFlights.sort(greaterArrival);
			displayAllFlights(allFlights);
		}
		else if (answer == 3) {
			allFlights.sort(departureTime);
			displayAllFlights(allFlights);
		}
		else if (answer == 4) {
			allFlights.sort(arrivalTime);
			displayAllFlights(allFlights);
		}
		else if (answer == 5) {
			allFlights.sort(greaterAircraftNumber);
			displayAllFlights(allFlights);
		}

		else if (answer == 6) {
			allFlights.sort(greaterAircraftType);
			displayAllFlights(allFlights);
		}
		else if (answer == 7) {
			allFlights.sort(greaterFlightPoints);
			displayAllFlights(allFlights);
		}
		else if (answer == 8) {
			break;
		}
		else {
			cout << "Invalid input. Choose a number 1-8" << endl;
			cin >> answer;
		}
		
	}
		
}


	
void displayPassegerFlight(list<Passenger>allPassengers, list<Flight>allFlights) {
	string firstName; 
	string lastName;
	displayAllPassenger(allPassengers);
		cout << "Please enter first name\n"; 
		cin >> firstName; 
		cout << "Enter Last Name\n";
		cin >> lastName; 
		for (Passenger &passenger : allPassengers) {


			if ((passenger.getName() == firstName) && (passenger.getLastName() == lastName)) {
				cout << passenger.boardingPass() << endl << endl; ;
				mainMenu(allFlights, allPassengers);
			}
			
		}
		cout << "Passenger not found" << endl;
	

}

void displayPassengersFlightandSeat(list<Flight>allFlights, list<Passenger>allPassengers) {
		int flightNumber;
		int answer; 
		cout << "Enter flight number\n";
		cin >> flightNumber;
		cout << "1.Sort By Name" <<
			   "2.Sort By Seat" <<
	         	"3.Back To Main Menu" << endl;
		cin >> answer; 
		if (answer==1) {
			allPassengers.sort(sortByName);
			for (Passenger &passenger : allPassengers) {
					cout << passenger.getName() << " " << passenger.getLastName() << " " << passenger.getSeatPassenger() << " " <<  endl;
			}
		}
		else if (answer == 2) {
			allPassengers.sort(sortBySeat);
			for (Passenger &passenger : allPassengers) {
				cout << passenger.getName() << " " << passenger.getLastName() << " " << passenger.getSeatPassenger() << " " << endl;
			}
		}
}

void writeToFile( list<Passenger>allPassengers)
{
	ofstream writeToFile;
	writeToFile.open(filePassenger.c_str());
	
	for (Passenger &passenger : allPassengers) {

		writeToFile << passenger.boardingPass() << endl; 
	}
	writeToFile.close();
}

void displayAllFlights(list<Flight>allflights) {
	for (Flight &flights : allflights) {
		cout << flights.displayFlightInfo() << endl;
	}
}

void displayAllPassenger(list<Passenger>allPassengers) {

	for (Passenger &passenger : allPassengers) {
		cout << passenger.boardingPass() << endl;
	}

}

void displayAllcities(list<string> cities) {

	for (list<string>::iterator it = cities.begin(); it != cities.end(); ++it) {
		cities.sort();
		cout << ' ' << *it << endl;

	}
}