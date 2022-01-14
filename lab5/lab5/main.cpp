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

	int coolShip = -1;
	int big = INT_MIN;
	int small = INT_MAX;

	if (option == 1)
	{
		for (unsigned int i = 0; i < ships.size(); i++)
		{
			ships.at(i).print();
		}
	}

	if (option == 2)
	{
		for (unsigned int i = 0; i < ships.size(); i++)
		{
			if (big < ships.at(i).getMaxWepStat())
			{
				big = ships.at(i).getMaxWepStat();
				coolShip = i;
			}

		}

		ships.at(coolShip).print();
	}

	if (option == 3)
	{
		for (unsigned int i = 0; i < ships.size(); i++)
		{
			if (big < ships.at(i).getTotalWepStat())
			{
				big = ships.at(i).getTotalWepStat();
				coolShip = i;
			}

		}

		ships.at(coolShip).print();
	}

	if (option == 4)
	{
		for (unsigned int i = 0; i < ships.size(); i++)
		{
			if ((ships.at(i).getTotalWepStat() != 0) && (small > ships.at(i).getTotalWepStat()))
			{
				small = ships.at(i).getMaxWepStat();
				coolShip = i;
			}

		}

		ships.at(coolShip).print();
	}

	if (option == 5)
	{
		for (unsigned int i = 0; i < ships.size(); i++)
		{
			if (ships.at(i).getTotalWepStat() == 0)
			{
				ships.at(i).print();
			}

		}
	}

	return 0;


}

void read1(string filePath, vector<extrafile>& ships)
{
	ifstream inFile(filePath, ios_base::binary);

	unsigned int shipCount;
	;

	inFile.read((char*)&shipCount, sizeof(shipCount));

	for (unsigned int i = 0; i < shipCount; i++)
	{
		//1. input name
		////1a. read length name
		int length;
		inFile.read((char*)&length, sizeof(length));
		////1b. array of chars of that size
		char* buffer = new char[length];
		////1c read into that array
		inFile.read(buffer, length);
		////1d copy into string
		string name = buffer;
		////1e. delete array
		delete[] buffer;

		//--------------------------------------------------//

		//2. input shipClass
		inFile.read((char*)&length, sizeof(length));
		buffer = new char[length];
		inFile.read(buffer, length);
		string shipClass = buffer;
		delete[] buffer;

		//--------------------------------------------------//

		//3. input shiplength
		short shiplength;
		inFile.read((char*)&shiplength, sizeof(shiplength));

		//--------------------------------------------------//

		//4. input shield
		int shield;
		inFile.read((char*)&shield, sizeof(shield));

		//--------------------------------------------------//

		//5.  input speed
		float speed;
		inFile.read((char*)&speed, sizeof(speed));

		//--------------------------------------------------//

		unsigned int weaponCount;
		inFile.read((char*)&weaponCount, sizeof(shipCount));

		vector<string>weaponName;
		vector<int> weaponStat;
		vector<float> weaponConus;

		for (unsigned int i = 0; i < weaponCount; i++)
		{

			//--------------------------------------------------//

			//6. weapon Name
			inFile.read((char*)&length, sizeof(length));
			buffer = new char[length];
			inFile.read(buffer, length);
			string weaponNames = buffer;
			delete[] buffer;

			weaponName.push_back(weaponNames);

			//--------------------------------------------------//

			//weapon pwr
			int weaponPwr;
			inFile.read((char*)&weaponPwr, sizeof(weaponPwr));
			weaponStat.push_back(weaponPwr);

			//--------------------------------------------------//

			//weapon consume
			float weaponUsed;
			inFile.read((char*)&weaponUsed, sizeof(weaponUsed));
			weaponConus.push_back(weaponUsed);
		}

		//--------------------------------------------------//

		//construct a ship
		extrafile ship(name, shipClass, shiplength, shield, speed, weaponName, weaponStat, weaponConus);
		ships.push_back(ship);
	}

}
