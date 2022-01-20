#pragma once

#include <iostream>
#include <memory>

#include "CCar.h"

/// <summary>
/// ����� - ����������
/// </summary>
class CCustomer {
public:
	CCustomer(int cash);

	//������� ���� �� ��������� ������� - ����� ����
	void addCar(std::shared_ptr<CCar> car);

	//������� ���� �� ��������� ����
	std::shared_ptr<CCar> removeCar(int price);

	std::shared_ptr<CCar> getCar();

private:
	std::shared_ptr<CCar> car;

	int cash;
};