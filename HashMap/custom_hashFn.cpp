#include <iostream>
#include <unordered_map>

// In this program, we are creating a mark_list between students and
// their marks.
// But we can't directly use the STL unordered map, coz we have created a custom
// Student class.

// So, essentially, we are creating mapping between Student object and its marks

using namespace std;

class Student
{
public:
    string firstname;
    string lastname;
    string roll;

    // constructor for student class
    Student(string f, string l, string r)
    {
        firstname = f;
        lastname = l;
        roll = r;
    }

    // We need to define the operator overloading of ==
    // Like how do we want the system to check if the key is equal or not

    bool operator==(const Student s) const
    {
        return roll == s.roll;
    }
};

// We now have to define our custom HashFn
// Since the system doesn't know how to hash the member of datatype "Student"

class HashFn
{
public:
    // overloading the () operator
    int operator()(const Student s) const
    {
        return s.firstname.length() + s.lastname.length();

        // Note that this HashFn is actually not good, coz any two students
        // whose length of names is same will collide...

        // And definitely those who have same name will definitely collide.
    }
};

int hasher(const Student s)
{
    return s.firstname.length() + s.lastname.length();
}

int main()
{
    unordered_map<Student, int, decltype (&hasher)> mark_list;

    Student s1("Rahul", "Kumar", "123");
    Student s2("Prateek", "Narang", "000");
    Student s3("Sanchit", "Maini", "23480");
    Student s4("Claire", "Rowan", "234");

    mark_list[s1] = 90;
    mark_list[s2] = 200;
    mark_list[s3] = 150;
    mark_list[s4] = 500;

    for (auto it : mark_list)
    {
        cout << it.first.firstname << "->" << it.second << endl;
    }
    return 0;
}