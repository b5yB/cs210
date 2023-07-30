#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// create global variables for files and file data
ifstream fileIn;
ofstream fileOut;
char city[10];
float temp;

// function to take in farenheit temperature and return celcius temperature
float convertTemp(float f) {
	float c;

	c = (f - 32) * (5.0 / 9);

	return c; 
}

int main() {
	
	//attempt to open both files
	fileIn.open("FahrenheitTemperature.txt");
	fileOut.open("CelciusTemperature.txt");

	// block to run when fileIn successfully opened
	if (fileIn.is_open()) {

		//take in data until end of fileIn
		while (!fileIn.eof()) {
			fileIn >> city >> temp;

			// call the temperature conversion function
			temp = convertTemp(temp);

			// write city and converted temperature to fileOut if successfully opened
			if (fileOut.is_open()) {
				fileOut << city << " " << temp << endl;
			}

			//so we know when the program ends for fileOut not found
			else {
				cout << "fileOut not opened";
			}
		}
	}

	//so we know when the program ends for fileIn not found
	else {
		cout << "fileIn not found";
	}

	//close both files and end program
	fileIn.close();
	fileOut.close();
	return 0;
}


