#include <iostream>
#include "HashMap_class.h"
using namespace std;

int main()
{
    HashMap<int> menu;

    menu.insert("Burger", 40);
    menu.insert("Pepsi", 10);
    menu.insert("BurgerPizza", 25);
    menu.insert("Noodles", 12);
    menu.insert("Coke", 70);

    // menu.print();
    // cout << endl;

    cout<<"Price of Pepsi "<<menu["Pepsi"]<<endl;

    menu["Pepsi"]=100;

    cout<<"Price of Pepsi "<<menu["Pepsi"]<<endl;

    menu["Sandwich"]=50;
    // auto p = menu.search("Noodles");
    // if (p == NULL)
    // {
    //     cout << "Item not found" << endl;
    // }
    // else cout << "Price of item is " << *p<<endl;;

    // menu.erase("Pepsi");

    // cout << endl;

    menu.print();
    return 0;
}