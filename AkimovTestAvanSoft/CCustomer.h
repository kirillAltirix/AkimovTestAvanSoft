#pragma once

#include <iostream>
#include <memory>

#include "CCar.h"

/// <summary>
/// Класс - покупатель
/// </summary>
class CCustomer {
public:
	CCustomer(int cash);

	//Покупка авто со списанием средств - ценой авто
	void addCar(std::shared_ptr<CCar> car);

	//Продажа авто за некоторую цену
	std::shared_ptr<CCar> removeCar(int price);

	std::shared_ptr<CCar> getCar();

private:
	std::shared_ptr<CCar> car;

	int cash;
};