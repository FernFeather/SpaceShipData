#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <climits>
using std::ofstream;
using std::ifstream;
using std::string;
using std::vector;

class extrafile
{
	//ships
	//object variables
	string name;
	string shipClass;
	int length;
	int shield;
	float speed;
	int total;


	int max = INT_MIN;
	int min = INT_MAX;


	//weapon information
	int maxValue = 0;
	vector<int> shipWeapons;

	//vectors
	vector<string>weaponName;
	vector<int> weaponStat;
	vector<float> weaponConus;

public:

	//constructor//
	extrafile(string _name, string _shipClass, int _length, int _shield, float _speed, vector<string>_weaponName, vector<int>_weaponStat, vector<float>_weaponConus);

	//get
	string getName();
	string getClass();
	int getLength();
	int getShield();
	int getSpeed();
	int getTotal();
	vector<int> getWeaponStat();

	int getMaxWepStat();
	int getTotalWepStat();

	//printWeapon
	void printWeapons();

	//print 
	void print();

};
