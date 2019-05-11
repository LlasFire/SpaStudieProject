#pragma once
#include "Client.h"
#include"VipAmenities.h"

class VipClient :
	public Client
{
public:
	const double bonus = 5;
	const double cashback = 3;

	VipClient();

	VipClient(int deposite, string name);

	VipClient(int deposite, string name, vector<Amenities*> servises);

	void SetDeposit(int deposite);

	void SetAmenitie(VipAmenities* servis);

	virtual~VipClient();
};



VipClient::VipClient():
	Client() 
{
	this->sort = "VIP";
}

VipClient::VipClient(int deposite, string name) :
	Client(deposite, name)
{
	this->sort = "VIP";
}

VipClient::VipClient(int deposite, string name, vector<Amenities*> servises) :
	Client(deposite, name, servises)
{
	this->sort = "VIP";
}


void VipClient::SetDeposit(int deposite)
{
	this->deposite = (int)(deposite * (bonus / 100) );
}

void VipClient::SetAmenitie(VipAmenities* servis)
{
	servises.push_back(servis);

	this->deposite -= servis->GetCost();

	deposite += (int)(servis->GetCost() * (cashback / 100));
}

VipClient::~VipClient() 
{
	servises.clear();
	servises.shrink_to_fit();
}

