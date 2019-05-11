#pragma once

#include<string>
#include <iomanip>
#include<vector>
#include<algorithm>
#include"Amenities.h"

using namespace std;

class Client
{
protected:
	int deposite;
	string name;
	vector<Amenities*> servises;
	string sort;
public:
	Client();

	Client(int deposite, string name);

	Client(int deposite, string name, vector<Amenities*> servises);

	void SetName(string name);
	string GetName();

	virtual void SetDeposit(int deposite);
	int GetDeposite();

	void SetAmenities(vector<Amenities*> servises);
	void SetAmenitie(Amenities* servis);
	vector<Amenities*> GetAmenities();

	string GetSort();

	virtual~Client();
};



Client::Client()
{
	this->deposite = 0;
	this->name = "";
	this->sort = "usual";
}

Client::Client(int deposite, string name)
{
	this->deposite = deposite;
	this->name = name;
	this->sort = "usual";
}

Client::Client(int deposite, string name, vector<Amenities*> servises)
{
	this->deposite = deposite;
	this->name = name;
	this->servises = servises;
	this->sort = "usual";
}

void Client::SetName(string name)
{
	this->name = name;
}

string Client::GetName()
{
	return this->name;
}

void Client::SetDeposit(int deposite)
{
	this->deposite = deposite;
}

int Client::GetDeposite()
{
	return this->deposite;
}

void Client::SetAmenities(vector<Amenities*> servises)
{
	this->servises = servises;
}

void Client::SetAmenitie(Amenities* servis)
{
	servises.push_back(servis);

	this->deposite -= servis->GetCost();
}

vector<Amenities*> Client::GetAmenities()
{
	return this->servises;
}

string Client::GetSort()
{
	return this->sort;
}

Client::~Client()
{
	servises.clear();
	servises.shrink_to_fit();
}
