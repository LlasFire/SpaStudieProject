#pragma once
#include "Amenities.h"
class VipAmenities :
	public Amenities
{
public:
	VipAmenities();

	VipAmenities(string name, int cost);

	virtual ~VipAmenities();
};



VipAmenities::VipAmenities(): Amenities()
{
	this->vip = true;
}

VipAmenities::VipAmenities(string name, int cost) : Amenities(name, cost) 
{
	this->vip = true;
}

VipAmenities::~VipAmenities() {}
