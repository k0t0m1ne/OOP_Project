#include "buy.h"

Buy::Buy() // конструктор
    : sum(0), sum_price(0.0), sum_weight(0.0)
{
    // пустое тело конструктора
}

void Buy::setSum(const int &value) // установить количество покупаемого товара
{
    sum = (value >= 0 ? value : 0);
    sum_price = sum * getWeight() * getPrice(); // получаем стоимость всего товара
    sum_weight = sum * getWeight(); // получаем общий вес покупаемого товара
}

int Buy::getSum() const // возвратить количество покупаемого товара
{
    return sum;
}

double Buy::getSumPrice() const // возвратить цену за весь купленный товар
{
    return sum_price;
}

double Buy::getSumWeight() const // возвратить общий вес покупки
{
    return sum_weight;
}
