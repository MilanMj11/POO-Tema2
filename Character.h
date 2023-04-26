#ifndef OOP_CHARACTER_H
#define OOP_CHARACTER_H

#include <iostream>

class Item;
class Character {
private:
    char *name; /// Name of the character
    int faction; /// 1 Foc , 2 Apa , 3 Pamant , 4 Aer
    int balance; /// Money
    int power; /// The power of the character
    Item *item_list; /// List of Items that Character has ( maxim 6 )
    int item_count; /// Number of items that Character has};
public:
    Character();
    explicit Character(char* _name);
    Character(char* _name,int _balance,int _power);
    Character(const Character &C);

    virtual ~Character();

    int get_faction() const;
    void set_faction(int new_faction);

    char* get_name() const;
    void set_name(char *new_name);

    int get_balance() const;
    void set_balance(int new_balance);

    int get_power() const;
    void set_power(int new_power);

    int get_item_count() const;
    void set_item_count(int new_count);

    Item* get_item_list() const;

    void buy_item(const Item &it); /// AICI ARUNC EXCEPTII
    void sell_item(const Item &it); /// AICI ARUNC EXCEPTII

    int add_item(const Item &it);
    int remove_item(const Item &it);
    void remove_all_items();

    Character& operator=(const Character& rhs);
    bool operator==(const Character& rhs) const;
    bool operator!=(const Character& rhs) const;

    friend std::ostream& operator << (std::ostream &os, const Character &rhs);
    friend std::istream& operator >> (std::istream &is,Character &rhs);

    friend class Item;
};


#endif //OOP_CHARACTER_H
