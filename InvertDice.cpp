#include <iostream>

void invertDice(unsigned long long a) {

    unsigned long long int maxPoints, minPoints{ 0 }, overMin{ 0 };
    maxPoints = a * 6;
    
    if (a > 6) {
        if (a % 6 == 0) {
            minPoints = a / 6;
        }
        else
        {
            overMin = a / 6;
            a = a % 6;
            minPoints = (7 - a) + overMin;
        }
    }
    else minPoints = (7 - a);

    std::cout << minPoints << " " << maxPoints << "\n";
}

int main()
{
    unsigned long long x;
    std::cin >> x;
    invertDice(x);
    return 0;
}
