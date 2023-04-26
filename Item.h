#ifndef OOP_ITEM_H
#define OOP_ITEM_H

#include <iostream>

class Character;

class Item {
private:
    char* name; /// Name of the item
    char* description; /// Description of what item does
    int price; /// Price of the item
    int power; /// Power of the item
    int faction; /// 1 Foc , 2 Apa , 3 Pamant , 4 Aer
public:
    Item();
    Item(char* _name, char* _description, int _price, int _power,int _faction);
    Item(const Item &it);
    virtual ~Item();

    const char *get_name() const;
    void set_name(char *new_name);

    const char* get_description() const;
    void set_description(char* new_description);

    int get_faction() const;
    void set_faction(int new_faction);

    int get_price() const;
    void set_price(int new_price);

    int get_power() const;
    void set_power(int new_power);

    Item& operator=(const Item& rhs);

    bool operator==(const Item& rhs) const;

    bool operator!=(const Item& rhs) const;

    friend std::ostream& operator << (std::ostream &os, const Item &rhs);
    friend std::istream& operator >> (std::istream &is,Item &rhs);
    friend Character;
};

#endif //OOP_ITEM_H
