#include "Item.h"
#include <string.h>
#include <iostream>

Item::Item(){
    /// eventual "initializam" totul cu valori nule;
    this-> name = new char[1];
    this->description = new char[1];
    this->price = -1;
    this->power = -1;
    this->faction = -1;
}
Item::Item(char* _name, char* _description, int _price, int _power,int _faction){

    size_t name_len = strlen(_name)+1;
    this->name = new char[name_len];
    strcpy(this->name,_name);

    size_t description_len = strlen(_description)+1;
    this->description = new char[description_len];
    strcpy(this->description,_description);

    this-> price = _price;
    this-> power = _power;
    this-> faction = _faction;
}
Item::Item(const Item &it){

    size_t name_len = strlen(it.name)+1;
    this->name = new char[name_len];
    strcpy(this->name,it.name);

    size_t description_len = strlen(it.description)+1;
    this->description = new char[description_len];
    strcpy(this->description,it.description);

    this-> price = it.price;
    this-> power = it.power;
    this-> faction = it.faction;
}
Item::~Item(){
    delete[] name;
    delete[] description;
}

const char* Item::get_name() const{
    return this->name;
}

void Item::set_name(char* new_name){
    delete[] this->name;
    size_t new_name_len = strlen(new_name)+1;
    this->name = new char[new_name_len];
    strcpy(this->name,new_name);
}

const char* Item::get_description() const{
    return this->description;
}

void Item::set_description(char* new_description){
    delete[] this->description;
    size_t new_description_len = strlen(new_description)+1;
    this->description = new char[new_description_len];
    strcpy(this->description,new_description);
}

int Item::get_faction() const{
    return this->faction;
}
void Item::set_faction(int new_faction){
    this->faction = new_faction;
}

int Item::get_price() const{
    return this->price;
}
void Item::set_price(int new_price){
    this->price = new_price;
}

int Item::get_power() const{
    return this->power;
}
void Item::set_power(int new_power){
    this->power = new_power;
}

Item& Item::operator=(const Item& rhs){
    this->set_name(rhs.name);
    this->set_description(rhs.description);
    this->price = rhs.price;
    this->power = rhs.power;
    this->faction = rhs.faction;
    return *this;
}

bool Item::operator==(const Item& rhs) const{
    return strcmp(this->name, rhs.name)==0 and
           strcmp(this->description, rhs.description)==0 and
           this->price == rhs.price and
           this->power == rhs.power;
}

bool Item::operator!=(const Item& rhs) const{
    return !(strcmp(this->name, rhs.name)==0 and
             strcmp(this->description, rhs.description)==0 and
             this->price == rhs.price and
             this->power == rhs.power);
}

std::ostream& operator << (std::ostream &os, const Item &rhs){
    os << rhs.get_name() << ", ";
    os << rhs.get_description() << ", ";
    os << rhs.get_price() << " Credits" << ", ";
    os << rhs.get_power() << " Power" << ", ";
    os << "Faction " << rhs.get_faction();
    return os;
}
std::istream& operator >> (std::istream &is,Item &rhs){
    is >> *rhs.name >> *rhs.description >> rhs.price >> rhs.power >> rhs.faction;
    return is;
}