#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double celsius, fahrenheit;

    cout << "Enter Temperature (C): ";
    cin>>celsius;
    fahrenheit = (9.0/5.0) * celsius + 32;
    cout << "Temperature (F): ";
    cout << fixed << setprecision(2) << fahrenheit << endl;
}