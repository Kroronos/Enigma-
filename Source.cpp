#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <stdlib.h>
#include <cstdlib>
using namespace std;
//Declare necessary classes for main
class cylinder {

private:
	//Disposable Aplhabets used in Cylinder generation
	vector<char> entryAlphabet = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W', 'X','Y','Z',
		'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w', 'x','y','z',
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', '!', '@', '#', '$', '?', '\'', '"', ':', ';', '-', '+', '=', ' ' };
	vector<char> exitAlphabet = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W', 'X','Y','Z',
		'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w', 'x','y','z',
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', '!', '@', '#', '$', '?', '\'', '"', ':', ';', '-', '+', '=', ' ' };

	//Entry sides represent the character passed through cylinder, while exitSides represent the character returned 
	vector<char> entrySides;
	vector<char> exitSides;
	string entryID;
	string exitID;
	//trueID representes the identification numbers of a complete cylinder with an ambersand between entry and exit side ids 
	string trueID;
	int timesRotated = 0;

public:
	//Contructor
	cylinder() {
		generateRandomIDCylinder();
		trueID = entryID + "&" + exitID;;
	}

	int getTimesRotated() {
		return timesRotated;
	}

	string getTrueID() {
		return trueID;
	}

	void generateRandomIDCylinder() {
		for (int i = 75; i >= 0; i--) {
			//Used for alphabet array access as well as to give a unique id to each cylinder
			int id;
			if (i != 0)
				id = rand() % (i+1);
			else
				id = 0;

			char rID = id;
			entrySides.push_back(entryAlphabet[id]);
			entryAlphabet.erase(entryAlphabet.begin() + id);
			entryID.push_back(rID);


		}
		for (int i = 75; i >= 0; i--) {
			int id;
			if (i != 0)
				id = rand() % (i+1);
			else
				id = 0;

			char rID = id;
			exitSides.push_back(exitAlphabet[id]);
			exitAlphabet.erase(exitAlphabet.begin() + id);
			exitID.push_back(rID);
		}

	}

	int matchingCharToEntrySideIndex(char a) {
		for (int i = 0; i < entrySides.size(); i++) {
			if (a == entrySides[i]) {
				return i;
			}
		}
		return -1; 
	}

	int matchingCharToExitSideIndex(char a) {
		for (int i = 0; i < exitSides.size(); i++) {
			if (a == exitSides[i]) {
				return i;
			}
		}
		return -1;
	}

	char matchingEntrySideIndexToChar(int a) {
		return entrySides[a];
	}


	char matchingExitSideIndexToChar(int a) {
		return exitSides[a];
	}

	void rotateCylinder() {
		char begin = exitSides[0];
		for (int i = 0; i < exitSides.size(); i++) {
			if (i != 75) {
				exitSides[i] = exitSides[i + 1];
			}
			else {
				exitSides[75] = begin;
			}
			
		}
		timesRotated++;
			
	}
};

class machine {

private:
	string name;
	int numberCylinders;
	vector<cylinder> cylinderComp;
	int cylinderRotationIncrement = 10;
	char alphabet[76] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W', 'X','Y','Z',
		'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w', 'x','y','z',
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', '!', '@', '#', '$', '?', '\'', '"', ':', ';', '-', '+', '=', ' '};
	char *plugboard[76];
public:

	machine(int a, string b) {
		name = b;
		initiatePlugboard();
		numberCylinders = a;
		createCylinders(a);
	}

	int getNumberCylinders() {
		return numberCylinders;
	}
	//Returns address of character array 
	char * getPlugboard() {
		return *plugboard;
	}
	
	string getName() {
		return name;
	}

	void setPlugboard(char a[]) {
		*plugboard = a;
	}

	int getCylinderRotationIncrement() {
		return cylinderRotationIncrement;
	}

	void setCylinderRotationIncrement(int a) {
		cylinderRotationIncrement = a; 
	}

	int getAlphabetArrayIndex(char a) {
		int ia;
		int arrayIA;

		if (islower(a) != 0) {
			ia = a;
			arrayIA = ia - 71;
		}

		if (isupper(a) != 0) {
			ia = a;
			arrayIA = ia - 65;
		}

		if (isdigit(a) != 0) {
			int i = a;
			arrayIA = i + 4;

		}

		if ((islower(a) == 0) && (isupper(a) == 0) && (isdigit(a) == 0)) {
			if (a == '.') {
				arrayIA = 62;
			}
			if (a == '!') {
				arrayIA = 63;
			}

			if (a == '@') {
				arrayIA = 64;
			}

			if (a == '#') {
				arrayIA = 65;
			}

			if (a == '$') {
				arrayIA = 66;
			}

			if (a == '?') {
				arrayIA = 67;
			}

			if (a == '\'') {
				arrayIA = 68;
			}

			if (a == '"') {
				arrayIA = 69;
			}

			if (a == ':') {
				arrayIA = 70;
			}

			if (a == ';') {
				arrayIA = 71;
			}

			if (a == '-') {
				arrayIA = 72;
			}

			if (a == '+') {
				arrayIA = 73;
			}

			if (a == '=') {
				arrayIA = 74;
			}

			if (a == '/' || a == ' ') {
				arrayIA = 75;
			}

		}
		return arrayIA;
	}

	void createCylinders(int a) {
		for (int i = 0; i < a; i++) {
			cylinderComp.push_back(cylinder());
		}
	}

	string alterPlugboard(char a, char b) {
		 //Convert char into int that correspond to alphabet array
		 
		 int arrayIA = getAlphabetArrayIndex(a);
		 int arrayIB = getAlphabetArrayIndex(b);
		 
		 char c = alphabet[arrayIA];
		 char d = alphabet[arrayIB];

		 int arrayIC = getAlphabetArrayIndex(c);
		 int arrayID = getAlphabetArrayIndex(d);

		
		 char e = *plugboard[arrayIA];
		 char f = *plugboard[arrayIB];

		 int arrayIE = getAlphabetArrayIndex(e);
		 int arrayIF = getAlphabetArrayIndex(f);

		 char g = *plugboard[arrayIE];
		 char h = *plugboard[arrayIF];

		 int arrayIG = getAlphabetArrayIndex(g);
		 int arrayIH = getAlphabetArrayIndex(h);


		 // @TODO Reassign variables that each is assigned to
		 // If if a is assigned to 1 and b is assigned to $ then after a = b and b = a set 1 = $ and $ = 1
		 plugboard[arrayIA] = &alphabet[arrayIB];
		 plugboard[arrayIB] = &alphabet[arrayIA];
		 plugboard[arrayIC] = &alphabet[arrayID];
		 plugboard[arrayID] = &alphabet[arrayIC];
	     plugboard[arrayIE] = &alphabet[arrayIF];
		 plugboard[arrayIF] = &alphabet[arrayIE];
		 plugboard[arrayIG] = &alphabet[arrayIH];
		 plugboard[arrayIH] = &alphabet[arrayIG];

		 string returned;
		 returned.push_back(e);
		 returned.push_back(f);
		 return returned;

		 

	} 

	void printTruePlugboard() {
		for (int i = 0; i < 76; i++) {
			cout << alphabet[i];
			cout << " = " << *plugboard[i] << endl;
		}
	}

	void initiatePlugboard() {
		for (int i = 75; i >= 0; i--) {
			plugboard[i] = &alphabet[abs(i - 75)];
		}
	}

	string encodeMessage(string a) {
		a = cylinderPass(a);
		a = plugboardPass(a);
		return a;
	}

	string decodeMessage(string a) {
		a = plugboardPass(a);
		a = reverseCylinderPass(a); 
		return a; 
	}

	string reverseCylinderPass(string a) {
		string reverseCylinderEncoded;
		return reverseCylinderEncoded;
	}

	string cylinderPass(string a) {
		string cylinderEncoded; 
		vector<cylinder> resetCylinderPosition = cylinderComp;
		for (int i = 0; i < a.size(); i++) {
			char toBeEncoded = a[i];
			char encoded = cylinderPartialPass(toBeEncoded);
			cylinderEncoded.push_back(encoded);
		}

		cylinderComp = resetCylinderPosition;
		return cylinderEncoded;
	}

	char cylinderPartialPass(char a) {
		for (int i = 0; i < cylinderComp.size(); i++) {
			int access = cylinderComp[i].matchingCharToEntrySideIndex(a);
			a = cylinderComp[i].matchingExitSideIndexToChar(access);
		}
		cylinderComp[0].rotateCylinder();
		for (int j = 0; j < cylinderComp.size(); j++) {
			if (j != 0) {
				if (cylinderComp[j - 1].getTimesRotated() % cylinderRotationIncrement == 0) {
					cylinderComp[j].rotateCylinder();
				}
			}
		}
		return a; 
	}

	string plugboardPass(string a) {
		string plugboardEncoded;
		for (int i = 0; i < a.length(); i++) {
			char checkedChar = a[i];
			checkedChar = *plugboard[findInAlphabet(checkedChar)];
			plugboardEncoded.push_back(checkedChar);
		}
		return plugboardEncoded;
	}

	int findInAlphabet(char a) {
		for (int i = 0; i < 76; i++) {
			if (a == alphabet[i]) {
				return i;
			}
		}
		return 0;
	}
};



int listMachines(vector<machine> a) {
	cout << endl;
	if (size(a) == 0) {
		cout << "There doesn't seem to be a machine here. Perhaps you need to build one. \n" << endl;
		return 1;
	}

	for (int i = 0; i < size(a); i++) {
		machine retrieved = a[i];
		cout << i + 1 << ". " << retrieved.getName() << "(" << retrieved.getNumberCylinders() << " cylinders" << ")" << endl;
	}
	cout << endl;
	return 0;
}

int main() {
	cout << "Welcome to Enigma++ \n";
	char *death[1];
	int userSelection = 0;
	vector<machine> listOfMachines;
	listOfMachines.reserve(4);
	while (userSelection != 7) {
		int creationSelection = 0;
		cout << "What would you like to do? \n";
		cout << "1. Use an Enigma Machine \n";
		cout << "2. Build an Enigma Machine \n";
		cout << "3. Clone an existing Enigma Machine \n";
		cout << "4. Change the settings of an Enigma Machine \n";
		cout << "5. Export an Enigma Machine \n";
		cout << "6. Import an Enigma Machine \n";
		cout << "7. Exit \n";

		cin >> userSelection;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (userSelection == 1) {
			string message;
			message.reserve(140);
			int verification = 0;
			while (creationSelection == 0 && verification == 0) {
				cout << "What machine would you like to use? \n";
				verification = listMachines(listOfMachines);
				if (verification == 0) {
					cin >> creationSelection;
					creationSelection = abs(creationSelection);
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (creationSelection == 0 || creationSelection > size(listOfMachines)) {
						cout << "Please enter a valid selection. \n";
						cout << endl;
					}
				}
			}

			if (verification == 0) {
				cout << listOfMachines[creationSelection - 1].getName() << " selected. \n";
				creationSelection = 0;
				cout << "Would you like to encode or decode a message? \n" << endl;
				cout << "1. Encode \n";
				cout << "2. Decode \n";
				cin >> creationSelection;
				creationSelection = abs(creationSelection);
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				while (creationSelection < 1 || creationSelection > 2) {
					cout << "Invalid selection. Please make a valid selection. \n" << endl;
					cout << "1. Encode \n";
					cout << "2. Decode \n";
					cin >> creationSelection;
					creationSelection = abs(creationSelection);
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				//Encode a message : Cylinder pathing -> Plugboard swapping
				if (creationSelection == 1) {
					cout << "\n" << "Please type in your message. \n";
					getline(cin, message);

					string encodedMessage = listOfMachines[creationSelection - 1].encodeMessage(message);
					cout << "\n" << encodedMessage << "\n" << endl;
				}

				//Decode a message : Plugboard reverse conversion -> Reverse cylinder 
				if (creationSelection == 2) {
					cout << "\n" << "Please type in your message. \n";
					getline(cin, message);



				}
			}
		}

		if (userSelection == 2) {
			creationSelection = 0;
			string name = "";
			while (creationSelection == 0) {
				cout << "What would you like to name this machine? \n";
				getline(cin, name);
				cout << "How many cylinders do you want your machine to have? \n";


				cin >> creationSelection;
				cin.clear();
				creationSelection = abs(creationSelection);
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				if (creationSelection == 0) {
					cout << "Please enter a valid selection. \n";
					while (creationSelection == 0) {
						cin >> creationSelection;
						cin.clear();
						creationSelection = abs(creationSelection);
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}
			}
			machine createdMachine(creationSelection, name);
			listOfMachines.push_back(createdMachine);
		}

		if (userSelection == 3) {
	
		}

		if (userSelection == 4) {
			int validation = 0;
			while (creationSelection == 0 && validation == 0) {
				cout << "Which machine needs its settings changed? \n";
				validation = listMachines(listOfMachines);
				if (validation == 0) {
					cin >> creationSelection;
					creationSelection = abs(creationSelection);
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}

				if (creationSelection == 0 || creationSelection > size(listOfMachines)) {
					cout << "Please enter a valid selection. \n";
					cout << endl;
				}
			}
			if (validation == 0) {
				cout << listOfMachines[creationSelection - 1].getName() << " has been selected. \n";
				machine displayMachine = listOfMachines[creationSelection - 1];
				int reference = creationSelection - 1;
				creationSelection = 0;

				while (creationSelection != 5) {
					cout << "What would you like to do? \n";
					cout << "1. Change the plugboard. \n";
					cout << "2. Change rate at which cylinders rotate. \n";
					cout << "5. Exit. \n";
					cin >> creationSelection;
					creationSelection = abs(creationSelection);
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					if (creationSelection == 1) {
						displayMachine.printTruePlugboard();
						cout << "Which variables would you like to make equivalent to one another in the plugboard? \n";
						char a;
						char b;
						cout << "Type / to access space \n";
						cout << "First variable? \n";
						cin >> a;
						cin.clear();
						cout << "Second variable? \n";
						cin >> b;
						cin.clear();
						string transcience = displayMachine.alterPlugboard(a, b);
						char e = transcience[0];
						int f = transcience[1];
						displayMachine.alterPlugboard(e, f);
						listOfMachines[reference].setPlugboard(displayMachine.getPlugboard());
					}

					if (creationSelection == 2) {
						cout << "A cylinder rotates after the previous cylinder has rotated " << displayMachine.getCylinderRotationIncrement() << " times. \n";
						int rotationChange = 0;
						cout << "How many times should the previous cylinder rotate before the next cylinder rotates?";
						cin >> rotationChange;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');

						while (rotationChange == 0 || rotationChange < 0) {
							cout << "Please enter a positive integer.";
							cin >> rotationChange;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
						displayMachine.setCylinderRotationIncrement(rotationChange);
					}
				}
			}

		}

		if (userSelection == 5) {
			cout << "Select a machine? \n";
			listMachines(listOfMachines);
		}

		if (userSelection == 6) {
			cout << "How would you like to export your machine? \n" << "1. Plain-Text Code? \n" << "2. Text File? \n";
			cout << "What machine would you like to use? \n";
			listMachines(listOfMachines);
		}

		if (userSelection < 1 || userSelection > 7) {
			cout << "An incorrect input has been detected. Please enter a valid input. \n";
		}
	}

	return 0;
}

