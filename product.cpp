#include "product.h"

#include <string>
Product::Product()
    : price(0.0), weight(0.0)
{
    for (int counter = 0; counter < 50; counter++)
        name[counter] = '\0';
}

void Product::setName(const std::string name_product) // установить имя товара
{
    name = name_product; // имя товара копируем в элемент данных класса
}

std::string Product::getName() const // возвратить имя товара
{
    return name;
}

void Product::setPrice(const double & pr) // установить стоимость 1 ед. товара
{
    price = (pr >= 0 ? pr : 0);
}

double Product::getPrice() const // возвратить стоимость 1 ед. товара
{
    return price;
}

void Product::setWeight(const double & wgh) // установить вес товара
{
    weight = wgh;
}

double Product::getWeight() const
{
    return weight;
}
