#pragma once

#include<string>
#include <iomanip>

using namespace std;

class Amenities
{
protected:
	bool vip;
	string name;
	int cost;
public:
	Amenities();

	Amenities(string name, int cost);

	void SetName(string name);
	string GetName();

	void SetCost(int cost);
	int GetCost();

	bool IsVip();

	virtual ~Amenities();
};



Amenities::Amenities()
{
	this->name = "";
	this->cost = 0;
	this->vip = false;
}


Amenities::Amenities(string name, int cost)
{
	this->name = name;
	this->cost = cost;
	this->vip = false;
}

void Amenities::SetName(string name)
{
	this->name = name;
}

string Amenities::GetName()
{
	return this->name;
}

void Amenities::SetCost(int cost)
{
	this->cost = cost;
}

int Amenities::GetCost()
{
	return this->cost;
}

bool Amenities::IsVip()
{
	return this->vip;
}

Amenities::~Amenities()
{
}
