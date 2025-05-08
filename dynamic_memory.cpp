#include <iostream>
using namespace std;

int main()
{
    // enumerations are user-defined types that can hold any set of discrete value
    // they behave like integers starting from 0
    // enum Mood {HAPPY = 3, SAD = 1, ANXIOUS = 4, SLEEPY = 2};

    enum MealType
    {
        NO_PREF,
        REGULAR,
        LOW_FAT,
        VEGETARIAN
    };

    // structs are used to bundle similar data
    struct Passenger
    {
        string name;
        MealType mealPref;
        bool isFreqFlyer;
        string freqFlyerNo;
    };

    // different assignments in a struct
    Passenger pass = {"John Smith", VEGETARIAN, true, "293145"};
    pass.name = "Pocahontas";
    pass.mealPref = REGULAR;

    Passenger *p, *q;
    p = new Passenger();
    p->name = "Poccha";
    p->mealPref = REGULAR;
    p->isFreqFlyer = false;
    p->freqFlyerNo = "NONE";

    cout << p->name << endl;

    // used to delete any dynamically allocated memory
    delete p;

    char *buffer = new char[500];
    buffer[3] = 'a';
    cout << buffer[3] << endl;
    delete[] buffer;
}