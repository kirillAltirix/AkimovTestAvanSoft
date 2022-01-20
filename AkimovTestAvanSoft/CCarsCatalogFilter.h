#pragma once

#include "iostream"

#include "CCarsCatalog.h"


/// <summary>
/// Класс - фильтр для каталога
/// </summary>
class CCarsCatalogFilter {
public:

	CCarsCatalogFilter(std::shared_ptr< CCarsCatalog > carsCatalog);

	//Производит печать всех авто из каталога с учетом фильтров
	void print();
	void print(std::shared_ptr < CCar > car);

	void clearFilterPrice();
	void clearFilterMaxSpeed();
	void clearFilterColor();

	void clearFilters();

	void setFilterPriceMin(int minPrice);
	void setFilterPriceMax(int maxPrice);
	
	void setFilterMaxSpeedMin(int minMaxSpeed);
	void setFilterMaxSpeedMax(int maxMaxSpeed);

	bool addFilterColor(std::wstring color);

private:

	bool checkFilterPrice(int price);
	bool checkFilterMaxSpeed(int maxSpeed);
	bool checkFilterColor(CColorTypes color);

	std::pair<int, int> filterPrice;

	std::pair<int, int> filterMaxSpeed;

	std::vector< CColorTypes > filterColor;

	

public:
	//Печатает шапку для таблицы авто
	void printHeader();

private:
	std::shared_ptr< CCarsCatalog > carsCatalog;

};