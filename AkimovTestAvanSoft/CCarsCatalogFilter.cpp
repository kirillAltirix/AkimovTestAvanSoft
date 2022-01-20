#include "CCarsCatalogFilter.h"

CCarsCatalogFilter::CCarsCatalogFilter(std::shared_ptr<CCarsCatalog> carsCatalog)
{
	this->carsCatalog = carsCatalog;

	clearFilters();
}

void CCarsCatalogFilter::print()
{
	printHeader();

	for (auto& car : this->carsCatalog->getCars()) {
		print(car.second);
	}
}

void CCarsCatalogFilter::print(std::shared_ptr<CCar> car)
{

	int id = car->getUniqueId();
	int price = car->getPrice();
	int maxSpeed = car->getMaxSpeed();
	CColorTypes color = car->getColorEnum();

	if (!checkFilterMaxSpeed(maxSpeed))
		return;
	if (!checkFilterPrice(price))
		return;
	if (!checkFilterColor(color))
		return;

	std::wcout
		<< car->getUniqueId() << L"    "
		<< car->getPrice() << L"      "
		<< car->getMaxSpeed() << L"     "
		<< car->getColor() << std::endl;
}

void CCarsCatalogFilter::clearFilterPrice()
{
	this->filterPrice = std::make_pair(INT_MIN, INT_MAX);
}

void CCarsCatalogFilter::clearFilterMaxSpeed()
{
	this->filterMaxSpeed = std::make_pair(INT_MIN, INT_MAX);
}

void CCarsCatalogFilter::clearFilterColor()
{
	this->filterColor.clear();
}

void CCarsCatalogFilter::clearFilters()
{
	clearFilterPrice();
	clearFilterMaxSpeed();
	clearFilterColor();
}

void CCarsCatalogFilter::setFilterPriceMin(int minPrice)
{
	this->filterPrice.first = minPrice;
}

void CCarsCatalogFilter::setFilterPriceMax(int maxPrice)
{
	this->filterPrice.second = maxPrice;
}

void CCarsCatalogFilter::setFilterMaxSpeedMin(int minMaxSpeed)
{
	this->filterMaxSpeed.first = minMaxSpeed;
}

void CCarsCatalogFilter::setFilterMaxSpeedMax(int maxMaxSpeed)
{
	this->filterMaxSpeed.second = maxMaxSpeed;
}

bool CCarsCatalogFilter::addFilterColor(std::wstring color)
{
	int colorId = CColor::getColorByName(color);

	if (colorId != -1) {
		this->filterColor.push_back(static_cast<CColorTypes>(colorId));
		return true;
	}

	return false;
}

bool CCarsCatalogFilter::checkFilterPrice(int price)
{
	if (this->filterPrice.first <= price &&
		price <= this->filterPrice.second)
		return true;
	return false;
}

bool CCarsCatalogFilter::checkFilterMaxSpeed(int maxSpeed)
{
	if (this->filterMaxSpeed.first <= maxSpeed &&
		maxSpeed <= this->filterMaxSpeed.second)
		return true;
	return false;
}

bool CCarsCatalogFilter::checkFilterColor(CColorTypes color)
{
	if (this->filterColor.empty())
		return true;

	for (auto& colorType : this->filterColor) {
		if (color == colorType)
			return true;
	}

	return false;
}

void CCarsCatalogFilter::printHeader()
{
	std::wcout
		<< L"ID " << L" "
		<< L"PRICE " << L" "
		<< L"MAX SPEED " << L" "
		<< L"COLOR" << std::endl;
}
