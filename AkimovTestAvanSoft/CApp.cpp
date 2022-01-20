#include "CApp.h"

bool CApp::parse(std::wstring inputString)
{
    if (inputString == L"exit") {
        std::wcout << L"Bye!\n";
        return false;
    }
    else if (inputString == L"start") {

        if (!this->carsCatalog)
            this->carsCatalog = std::make_shared<CCarsCatalog>(CCarsCatalog(rand() % 11));
        if (!this->customer)
            this->customer = std::make_unique<CCustomer>(CCustomer(1000));
        if (!this->catalogFilter && this->carsCatalog)
            this->catalogFilter = std::make_unique<CCarsCatalogFilter>(CCarsCatalogFilter(this->carsCatalog));
        else {
            std::wcout << L"You can start only once!" << std::endl;
        }

        return true;
    }
    else if (inputString == L"print") {
        this->catalogFilter->print();
    }
    else if (inputString.find(L"buy") != std::wstring::npos) {
        try {
            int uniqueId = std::stoi(inputString.substr(3, inputString.size() - 3));

            customer->addCar(this->carsCatalog->getCars().at(uniqueId));

            this->carsCatalog->remove(uniqueId);
        }
        catch (...) {
            std::wcout << L"Incorrect command, check spaces, tabs and try again!" << std::endl;
        }
        return true;
    }
    else if (inputString == L"print mine") {
        if (this->customer->getCar()) {
            this->catalogFilter->printHeader();
            this->catalogFilter->print(this->customer->getCar());
        }
        else
            std::wcout << L"You have no car yet!" << std::endl;
    }
    else if (inputString == L"sell") {
        try {
            if (this->customer->getCar()) {
                auto carPrice = this->customer->getCar()->getPrice();

                this->carsCatalog->addCar(customer->removeCar(carPrice));
            }
            else
            {
                std::wcout << L"You have no car yet!" << std::endl;
            }
        }
        catch (...) {
            std::wcout << L"Incorrect command, check spaces, tabs and try again!" << std::endl;
        }
        return true;
    }
    else if (inputString.find(L"set filter max speed min ") != std::wstring::npos) {
        try {
            int filter = std::stoi(inputString.substr(24, inputString.size() - 24));

            this->catalogFilter->setFilterMaxSpeedMin(filter);
        }
        catch (...) {
            std::wcout << L"Incorrect command, check spaces, tabs and try again!" << std::endl;
        }
        return true;
    }
    else if (inputString.find(L"set filter max speed max ") != std::wstring::npos) {
        try {
            int filter = std::stoi(inputString.substr(24, inputString.size() - 24));

            this->catalogFilter->setFilterMaxSpeedMax(filter);
        }
        catch (...) {
            std::wcout << L"Incorrect command, check spaces, tabs and try again!" << std::endl;
        }
        return true;
    }
    else if (inputString.find(L"set filter price min ") != std::wstring::npos) {
        try {
            int filter = std::stoi(inputString.substr(21, inputString.size() - 21));

            this->catalogFilter->setFilterPriceMin(filter);
        }
        catch (...) {
            std::wcout << L"Incorrect command, check spaces, tabs and try again!" << std::endl;
        }
        return true;
    }
    else if (inputString.find(L"set filter price max ") != std::wstring::npos) {
        try {
            int filter = std::stoi(inputString.substr(21, inputString.size() - 21));

            this->catalogFilter->setFilterPriceMax(filter);
        }
        catch (...) {
            std::wcout << L"Incorrect command, check spaces, tabs and try again!" << std::endl;
        }
        return true;
    }
    else if (inputString.find(L"add filter color ") != std::wstring::npos) {
        try {
            std::wstring filter = inputString.substr(17, inputString.size() - 17);

            this->catalogFilter->addFilterColor(filter);
        }
        catch (...) {
            std::wcout << L"Incorrect command, check spaces, tabs and try again!" << std::endl;
        }
        return true;
    }
    else if (inputString == L"clear filter max speed") {
        this->catalogFilter->clearFilterMaxSpeed();
    }
    else if (inputString == L"clear filter price") {
        this->catalogFilter->clearFilterPrice();
    }
    else if (inputString == L"clear filter color") {
        this->catalogFilter->clearFilterColor();
    }
    else if (inputString == L"clear filters") {
        this->catalogFilter->clearFilters();
    }
    else if (inputString == L"help") {
        std::wcout << L"\"start\"                             -  to start the game" << std::endl;
        std::wcout << L"\"print\"                             -  to print the list of available cars" << std::endl;
        std::wcout << L"\"print mine\"                        -  to print your car" << std::endl;
        std::wcout << L"\"buy [ID]\"                          -  to buy the car with id = [ID]" << std::endl;
        std::wcout << L"\"sell\"                              -  to sell your car" << std::endl;
        std::wcout << L"\"set filter max speed min [MIN]\"    -  set max speed filter value" << std::endl;
        std::wcout << L"\"set filter max speed max [MAX]\"    -  set max speed filter value" << std::endl;
        std::wcout << L"\"set filter price min [MIN]\"        -  set price filter value" << std::endl;
        std::wcout << L"\"set filter price max [MAX]\"        -  set price filter value" << std::endl;
        std::wcout << L"\"add filter color [COLOR]\"          -  add color to color filter (E.g: Yellow)" << std::endl;
        std::wcout << L"\"clear filter max speed\"            -  clears the max speed filter" << std::endl;
        std::wcout << L"\"clear filter price\"                -  clears the price filter" << std::endl;
        std::wcout << L"\"clear filter color\"                -  clears the color filter" << std::endl;
        std::wcout << L"\"clear filters\"                     -  clears all filters" << std::endl;
        std::wcout << L"\"help\"                              -  to see all supported commands" << std::endl;
    }
    else {
        std::cout << "Incorrect command, check help" << std::endl;
        return true;
    }
}
