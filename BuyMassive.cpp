#include "Buy.h"
#include "BuyMassive.h"
#include <fstream>
using namespace std;

BuyMassive::BuyMassive()
    : products(nullptr),
    count(0),
    allocated(0)

{}
BuyMassive::BuyMassive(const BuyMassive& copy) {
    count = copy.count;
    products = new Buy[count];
    allocated = count;
    for (int i = 0; i < count; i++) {
        products[i] = copy.products[i];
    }
}
BuyMassive::~BuyMassive() {
    removeAll();
}
void BuyMassive::grow() {
    Buy* tmp = new Buy[count + 1];
    for (int i = 0; i < count; i++) {
        tmp[i] = products[i];
    }
    delete[] products;
    products = tmp;
    allocated += 1;
}
void BuyMassive::add(const Buy& obj) {
    if (count >= allocated) {
        grow();
    }
    products[count++] = obj;
}
void BuyMassive::remove(Buy& obj) {
    int ij = 0;
    for(int i = 0; i < count; i++)
        if (obj.getName() == products[i].getName() && obj.getPrice() == products[i].getPrice())
            ij=i;

    for (int j = ij; j < count - 1; j++) {
        products[j] = products[j + 1];
    }
    count--;
}
void BuyMassive::removeAll() {
    if (allocated) {
        delete[] products;
    }
    count = 0;
}
Buy BuyMassive::get(const int& i) {
    if (!(i < 0) && !(i > count)) {
        return products[i];
    }
}
int BuyMassive::size() {
    return count;
}
void BuyMassive::printInFile(const string& file) {
    ofstream fout;
    fout.open(file);
    for (int i = 0; i < count; i++) {;
        fout << products[i].getName() << endl <<
                products[i].getSumWeight() << products[i].getSumPrice() << endl;
        if (i != count - 1) {
            fout << endl;
        }
    }
}
void BuyMassive::getFromFile(const string& file) {
    ifstream fin;
    fin.open(file);
    while (!fin.eof()) {
        double tmpWeight,tmpPrice;
        std::string tmpName;
        fin >> tmpName >> tmpWeight >> tmpPrice;
        Buy car = Buy();
        add(car);
    }
}

double BuyMassive::getFullPrice(){
    double sum = 0;
    for(int i = 0; i<size(); i++)
        sum+=products[i].getSumPrice();
    return sum;
}
