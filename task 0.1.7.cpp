#include <iostream>>
#include <string>

using namespace std;

int main()
{
    string digits;
    int first, second;
    unsigned int sum;
    cout << "Enter 20 digits in one line - ";
    cin >> digits;
    first = stoi(digits.substr(0, 10));
    second = stoi(digits.substr(10, 10));
    sum = first + second;
    cout << "First number - " << first << endl;
    cout << "Second number - " << second << endl;

    cout << "Their sum - " << sum;

    return 0;
}
