#pragma once
#include <iostream>
#include <string>
#include "CCarsCatalog.h"
#include "CCustomer.h"
#include "CCarsCatalogFilter.h"

//Класс - основное приложение
class CApp {
public:
	CApp() = default;

	bool parse(std::wstring inputString);

private:

	std::shared_ptr<CCarsCatalog> carsCatalog;
	std::unique_ptr<CCustomer> customer;
	std::unique_ptr<CCarsCatalogFilter> catalogFilter;
};