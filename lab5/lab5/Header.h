#include "extrafile.h"
#include <iomanip>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <climits>
using namespace std;
using std::vector;


void read1(string filePath, vector<extrafile>& ships);

int main()
{
	vector<extrafile> ships;
	vector<string> wepName;
	vector<int> weapPwr;
	vector<float> powerConsume;

	cout << "Which file(s) to open?\n";
	cout << "1. friendlyships.shp" << endl;
	cout << "2. enemyships.shp" << endl;
	cout << "3. Both files" << endl;
	int option;
	cin >> option;

	/*======= Load data from file(s) =======*/
	if (option == 1)
	{
		read1("friendlyships.shp", ships);
	}
	if (option == 2)
	{
		read1("enemyships.shp", ships);
	}
	if (option == 3)
	{
		read1("friendlyships.shp", ships);
		read1("enemyships.shp", ships);
	}

	/* Load files here */

	cout << "1. Print all ships" << endl;
	cout << "2. Starship with the strongest weapon" << endl;
	cout << "3. Strongest starship overall" << endl;
	cout << "4. Weakest ship (ignoring unarmed)" << endl;
	cout << "5. Unarmed ships" << endl;

	cin >> option;

	/* Work your magic here */

	return 0;
}

void read1(string filePath, vector<extrafile>& ships)
{
	ifstream inFile(filePath, ios_base::binary);

	unsigned int shipCount;
	unsigned int weaponCount;
	vector<string>weaponName;
	vector<int> weaponStat;
	vector<float> weaponConus;

	inFile.read((char*)&shipCount, sizeof(shipCount));

	for (unsigned int i = 0; i < shipCount; i++)
	{
		int temp;
	}

	if (inFile.is_open())
	{
		//read the Data
		string line;
		getline(inFile, line); //ignore first line

		// Get information
		while (getline(inFile, line))
		{
			istringstream stream(line);

			int numberID;
			string theme;
			string name;
			int minifig;
			int pieces;
			double price;

			string tempID;
			string tempFig;
			string tempPiece;
			string tempPrice;

			getline(stream, tempID, ',');
			numberID = stoi(tempID);

			getline(stream, theme, ',');

			getline(stream, name, ',');

			getline(stream, tempFig, ',');
			minifig = stoi(tempFig);

			getline(stream, tempPiece, ',');
			pieces = stoi(tempPiece);

			getline(stream, tempPrice);
			price = stod(tempPrice);

			extrafile legos(numberID, theme, name, minifig, pieces, price);
			legosets.push_back(legos);
		}
	}
	else
	{
		cout << "file not open" << endl;
	}

}
#pragma once
