#pragma once
#include "buy.h"
#include <iostream>
class BuyMassive
{
private:
    Buy *products;
    int count;
    int allocated;
    void grow();
public:
    BuyMassive();
    BuyMassive(const BuyMassive&);
    ~BuyMassive();
    void add(const Buy& obj);
    void remove(Buy& obj);
    void removeAll();
    Buy get(const int&);
    int size();
    void printInFile(const std::string&);
    void getFromFile(const std::string&);
    double getFullPrice();
};

