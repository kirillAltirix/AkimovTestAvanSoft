#include "CCarsCatalog.h"

CCarsCatalog::CCarsCatalog(int carsNumber)
{

	for (int i = 0; i < carsNumber; i++) {

		int price = 100 + rand() % 900;
		int maxSpeed = (18 + rand() % 10) * 10;
		int color = rand() % 6;

		this->cars[i] = std::make_shared<CCar>(CCar(i, price, maxSpeed, color));
	}

}

std::map< int, std::shared_ptr< CCar > > CCarsCatalog::getCars()
{
	return this->cars;
}

void CCarsCatalog::remove(int uniqueId)
{
	this->cars.erase(uniqueId);
}

void CCarsCatalog::addCar(std::shared_ptr<CCar> car) 
{
	this->cars[car->getUniqueId()] = car;
}
