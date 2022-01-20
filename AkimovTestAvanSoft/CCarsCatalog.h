#pragma once
#include <vector>
#include <map>
#include <memory>
#include <cmath>

#include "CCar.h"


class CCarsCatalog {
public:
	CCarsCatalog(int carsNumber);

	std::map< int, std::shared_ptr< CCar > > getCars();

	void remove(int uniqueId);
	void addCar(std::shared_ptr< CCar >);

private:

	std::map< int, std::shared_ptr< CCar > > cars;
};
