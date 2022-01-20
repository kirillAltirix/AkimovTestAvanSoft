#include "CCustomer.h"

CCustomer::CCustomer(int cash) :
	cash(cash)
{
}

void CCustomer::addCar(std::shared_ptr<CCar> car)
{
	if (car->getPrice() > this->cash)
		std::wcout << L"Customer: \"Car is too expensive, I can't afford that one\"";
	else {
		this->cash -= car->getPrice();
		this->car = car;
	}
}

std::shared_ptr<CCar> CCustomer::removeCar(int price)
{
	auto returnCar = this->car;

	this->car = nullptr;
	this->cash += price;

	return returnCar;
}

std::shared_ptr<CCar> CCustomer::getCar()
{
	return this->car;
}
