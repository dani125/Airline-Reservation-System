#include "AircraftSeat.h"



AircraftSeat::AircraftSeat()
{
	
}


AircraftSeat::~AircraftSeat()
{
}

AircraftSeat AircraftSeat ::createSeats(string airGraftType)
{
	AircraftSeat seat;
	for (int i = 0; i<totalRow; i++) {
		if (airGraftType == "A") {
			
			this->rowA[i] =to_string(i + 1) + "A";
			
			this->rowB[i] = to_string(i + 1) + "B";
			
			this->rowC[i] = to_string(i + 1) + "C";
			
			this->rowD[i] = to_string(i + 1) + "D";
		
			
			
			
			
		}
		else {
			rowA[i] = to_string(i + 1) + "A";
			
			rowB[i] = to_string(i + 1) + "B";
			
			rowC[i] = to_string(i + 1) + "C";
		
			
		}
	}
	return seat;
}




void AircraftSeat::showSeats()
{
	for (int i = 0; i<totalRow; i++) {
		if (rowD[i].empty()) {
			cout << rowA[i]<< " | " << " X " << " | " << rowB[i] << " | " << rowC[i]<<endl ;
		
		
		}
		else { 
			cout << rowA[i] << " | " << rowB[i] << " | " << " X " << " | " << rowC[i] << " | " << rowD[i] << endl;
		
		}
	}

}

string *AircraftSeat::seatOccupied(string *row, int i)
{
	row[i] = "T";
	return row;
	delete row; 
}



