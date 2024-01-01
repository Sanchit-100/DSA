#include <iostream>
#include <map>
using namespace std;

int main()
{

    map<string, int> menu;
    menu.insert(make_pair("Dosa", 60));

    pair<string, int> p;
    p.first = "Pizza";
    p.second = 100;
    menu.insert(p);

    menu["Burger"] = 50;

    // Search
    auto it = menu.find("Pizza");
    if (it != menu.end())
    {
        cout << "Price is " << menu["Pizza"] << endl;
    }
    else
        cout << "Not present in stock" << endl;

    // Another way to search
    // count method counts the no of occurences of a particular
    // key in the map.
    // Now since the map stores unique values only once,
    // it will give output only as 1 or 0

    // Search
    if (menu.count("Pizza"))
    {
        cout << "Price is " << menu["Pizza"] << endl;
    }
    else
        cout << "Item out of stock" << endl;

    for (auto it : menu)
    {
        cout << it.first << ":" << it.second << endl;
    }

    // Erase the object
    menu.erase("Pizza");
    cout<<"NEW PRICES"<<endl;
    for (auto it = menu.begin(); it != menu.end(); it++)
    {
        cout << (*it).first<< ":" << (*it).second << endl;
    }

    return 0;
}