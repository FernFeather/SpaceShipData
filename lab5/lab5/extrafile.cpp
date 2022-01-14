#include "extrafile.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;
using std::ofstream;
using std::ifstream;
using std::string;
using std::vector;

/*//////constructor//////*/
extrafile::extrafile(string _name, string _shipClass, int _length, int _shield, float _speed, vector<string>_weaponName, vector<int>_weaponStat, vector<float>_weaponConus)
{
	name = _name;
	shipClass = _shipClass;
	length = _length;
	shield = _shield;
	speed = _speed;

	weaponName = _weaponName;
	weaponStat = _weaponStat;
	weaponConus = _weaponConus;
}

//get
string extrafile::getName()
{
	return name;
}

string extrafile::getClass()
{
	return shipClass;
}

int extrafile::getLength()
{
	return length;
}

int extrafile::getShield()
{
	return shield;
}

int extrafile::getSpeed()
{
	return speed;
}

vector<int> extrafile::getWeaponStat()
{
	return weaponStat;
}

int extrafile::getMaxWepStat()
{
	if (weaponName.size() == 0)
	{
		return 0;
	}

	for (unsigned int i = 0; i < weaponStat.size(); i++)
	{
		if (weaponStat.at(i) > max)
		{
			max = weaponStat.at(i);
		}
	}
	return max;
}


int extrafile::getTotalWepStat()
{
	int total = 0;

	if (weaponName.size() == 0)
	{
		return 0;
	}

	for (unsigned int i = 0; i < weaponStat.size(); i++)
	{
		total += weaponStat.at(i);
	}

	return total;
}

//printWeapon
void extrafile::printWeapons()
{
	cout << "Armaments:" <<endl;

	if (weaponName.size() == 0)
	{
		cout << "Unarmed" << endl;
		return;
	}

	int  totalStat = 0;

	for (unsigned int i = 0; i < weaponName.size(); i++)
	{
		cout << weaponName.at(i) << ", " << weaponStat.at(i) << ", " << weaponConus.at(i) <<  endl;
		
		totalStat += weaponStat.at(i);
	}

	cout << "Total firepower: " << totalStat << endl;
}

int extrafile::getTotal()
{
	return total;
}

//print 
void extrafile::print()
{
	cout << endl;
	cout << "Name: " << name << endl;
	cout << "Class: " << shipClass << endl;
	cout << "Length: " << length << endl;
	cout << "Shield capacity: " << shield << endl;
	cout << "Maximum Warp: " << speed << endl;
	printWeapons();
}