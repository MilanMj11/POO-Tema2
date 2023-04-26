#include "Character.h"
#include "Item.h"
#include <string.h>
/// #include <iostream>

Character::Character(){
    this->name = new char[1];
    this->faction = 0;
    this->balance = 0;
    this->power = 0;
    this->item_list = new Item[6];
    this->item_count = 0;
}

Character::Character(char* _name){ /// EXPLICIT !!
    size_t name_len = strlen(_name)+1;
    this->name = new char[name_len];
    strcpy(this->name, _name);
    this->faction = 0;
    this->balance = 0;
    this->power = 0;
    this->item_list = new Item[6];
    this->item_count = 0;
}

Character::Character(char* _name,int _balance,int _power){
    size_t name_len = strlen(_name)+1;
    this->name = new char[name_len];
    strcpy(this->name, _name);

    this->faction = 0;

    this->balance = _balance;
    this->power = _power;

    this->item_list = new Item[6];
    this->item_count = 0;
}

Character::Character(const Character &C){
    size_t name_len = strlen(C.name)+1;
    this->name = new char[name_len];
    strcpy(this->name,C.name);
    this->balance = C.balance;
    this->power = C.power;
    this->item_list = new Item[6];
    for(int i=0;i<=5;i++) /// Change with pointers
        this->item_list[i] = C.item_list[i];
    this->item_count = C.item_count;
}

Character::~Character(){
    delete[] this->name;
    delete[] this->item_list;
}

int Character::get_faction() const{
        return this->faction;
    }
void Character::set_faction(int new_faction){
    this->faction = new_faction;
}

char* Character::get_name() const{
    return this->name;
}
void Character::set_name(char *new_name){
    delete[] this->name;
    size_t len_new_name = strlen(new_name)+1;
    this->name = new char[len_new_name];
    strcpy(this->name,new_name);
}

int Character::get_balance() const{
    return this->balance;
}
void Character::set_balance(int new_balance){
    this->balance = new_balance;
}

int Character::get_power() const{
    return this->power;
}
void Character::set_power(int new_power){
    this->power = new_power;
}

int Character::get_item_count() const {
    return this->item_count;
}
void Character::set_item_count(int new_count){
    this->item_count = new_count;
}

Item* Character::get_item_list() const {
    return this->item_list;
}

void Character::buy_item(const Item &it){
    if(this->balance < it.get_price()){
        std::cout << "Error: Not enough balance" << '\n';
        return;
    }
    bool ok = this->add_item(it);
    if(ok==1)  /// Making sure I really buy it;
        this->balance -= it.get_price();
}
void Character::sell_item(const Item &it){
    bool ok = this->remove_item(it);
    if(ok==1)  /// Making sure I really sell it;
        this->balance += it.get_price();
}

int Character::add_item(const Item &it){
    if(this->item_count == 6){
        std::cout << "Error: Inventory full" << '\n';
        return -1;
        /// THROW EXCEPTION !!!!!!!!!!!!!!!!
    }
    this->item_list[item_count] = it;
    item_count += 1;
    this->power += it.get_power();
    return 1;
}

int Character::remove_item(const Item &it){
    int poz = -1, cnt = 0;
    Item list_aux[5];
    for(int i=0;i<item_count;i++){
        if(this->item_list[i] == it){
            poz = i;
            break;
        }
    }
    if(poz == -1){
        std::cout << "Error: Item does not exist in the inventory" << '\n';
        return -1;
        /// THROW EXCEPTION !!!!!!!!!!!!!
    }
    this->power -= it.get_power();
    for(int i=0;i<item_count;i++){
        if(i==poz) continue;
        list_aux[cnt++] = this->item_list[i];
    }
    delete[] this->item_list;
    this->item_list = new Item[5];
    for(int i=0;i<item_count;i++)
        this->item_list[i] = list_aux[i];
    item_count -= 1;
    return 1;
}

void Character::remove_all_items(){
    delete[] this->item_list;
    this->item_list = new Item[6];
}

Character& Character::operator=(const Character& rhs){
    this->remove_all_items();
    Item* rhs_item_list =rhs.get_item_list();
    int rhs_item_count = rhs.get_item_count();
    for(int i=0;i<rhs_item_count;i++){
        this->add_item(rhs_item_list[i]);
    }

    this->set_name(rhs.get_name());
    this->set_balance(rhs.get_balance());
    this->set_power(rhs.get_power());
    this->set_item_count(rhs.get_item_count());
    return *this; /// CAREFUL HERE TOO
}

bool Character::operator==(const Character& rhs) const{
    bool egalitate = strcmp(this->name,rhs.get_name())==0 and
                     this->balance == rhs.get_balance() and
                     this->power == rhs.get_power() and
                     this->item_count == rhs.get_item_count();
    if(egalitate == false)
        return false;
    bool ok[6] = {false};
    Item* List1 = this->item_list;
    Item* List2 = rhs.get_item_list();
    for(int i=0;i<this->item_count;i++) ok[i]=false;
    for(int i=0;i<this->item_count;i++){
        for(int j=0;j<this->item_count;j++){
            if(ok[j]==false and *(List1+i)==*(List2+j)){
                ok[j] = true;
            }
        }
    }
    for(int i=0;i<item_count;i++) {
        if(ok[i]==false) return false;
    }
    return true;
}

bool Character::operator!=(const Character& rhs) const{
    return !(*this==rhs);
}

std::ostream& operator<<(std::ostream &os, const Character &rhs){
    os << "Nume: " << rhs.get_name() << ',';
    os << "Credite: " << rhs.get_balance() << ',';
    os << "Putere: " << rhs.get_power() << ',';
    if(rhs.get_item_count()!=0){
        os << "Items: ";
        for(int i=0;i<rhs.get_item_count();i++){
            os <<  "'" << *(rhs.get_item_list()+i) << "'" << ',';
        }
    }
    os << "Numar iteme: " << rhs.get_item_count();
    return os;
}

std::istream& operator>>(std::istream &is,Character &rhs){
    is >> *rhs.name >> rhs.balance >> rhs.power;
    return is;
}