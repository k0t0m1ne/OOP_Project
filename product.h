#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
class Product
{
private:
    std::string name; // имя товара
    double price, // цена
           weight; // вес 1 ед.
public:
    Product(); // конструктор

    void setName(const std::string); // установить имя товара
    std::string getName() const; // возвратить имя товара

    void setPrice(const double &); // установить цену товара
    double getPrice() const; // возвратить цену товара

    void setWeight(const double &); // установить вес 1 ед. товара
    double getWeight() const; // возвратить вес 1 ед. товара
};

#endif  //PRODUCT_H
