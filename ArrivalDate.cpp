/*
    You have to calculate what time it would be after you travel on a train. 
    Input file has current time (HH:MM) and time of your travel (Hours < 120 and Minutes < 59).
*/

#include <iostream>
#include <string>
#include <list>

int main()
{
    long int currentHours{ 0 }, currentMinutes{ 0 };
    int hourTimeWay, minuteTimeWay;
    std::string currentTime;
    char sym;

    std::cin >> currentTime; // Entering current time in "HH:MM" format

    for (int i = 0; i < 2; i++) { // Getting two first symbols from currentTime as hours
        int mult = 1;
        if (i % 2 == 0) mult = 10;
        sym = currentTime.at(i);
        currentHours = currentHours + ((sym - '0') * mult);
        
    }

    for (int i = 3; i < 5; i++) { // Getting two last symbols from currentTime as minutes
        int mult = 1;
        if (i % 2 != 0) mult = 10;
        sym = currentTime.at(i);
        currentMinutes = currentMinutes + ((sym - '0') * mult);
    }
    
    std::cin >> hourTimeWay; // Entering hours and minutes of the route
    std::cin >> minuteTimeWay;
    currentMinutes += minuteTimeWay; // Adding their values to current time
    currentHours += hourTimeWay;

    if (currentMinutes > 59) //
    {
        currentMinutes %= 60;
        currentHours++;
    }

    if (currentHours > 23) {
        currentHours %= 24;
    }
    
    if (currentHours < 10) std::cout << '0';
    std::cout << currentHours << ":";
    if (currentMinutes < 10) std::cout << '0';
    std::cout << currentMinutes << "\n";
    
}
