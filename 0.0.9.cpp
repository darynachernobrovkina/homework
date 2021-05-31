#include <iostream>

using namespace std;

int main()
{
    float x, second_degree, fourth_degree, fifth, eights_degree, sixths_degree, nineth_degree;
    float twelfth, fifteen, twenty_fourth, twenty_eight, sixteen;
    float thirty_two, sixty_four;
    cout << "Enter x value: ";
    cin >> x;

    second_degree = x * x; // 1 multiplication
    fourth_degree = second_degree * second_degree; //  task |1|, 2 multiplications

    sixths_degree = fourth_degree * second_degree; // task |2|, 3 multiplications

    eights_degree = fourth_degree * fourth_degree; // 3 multiplications
    nineth_degree = eights_degree * x; // task |3|, 4 multiplications

    fifth = fourth_degree * x; // 3 multiplications
    fifteen = fifth * fifth * fifth; // task |4|, 5 multiplications

    twelfth = sixths_degree * sixths_degree; // 4 multiplications
    twenty_fourth = twelfth * twelfth; // 5 multiplications
    twenty_eight = twenty_fourth * fourth_degree; // task |5|, 6 multiplications

    sixteen = eights_degree * eights_degree; // 4 multiplications
    thirty_two = sixteen * sixteen; // 5 multiplications
    sixty_four = thirty_two * thirty_two; // task |6|, 6 multiplications

    cout << "X^4 - " << fourth_degree << endl;
    cout << "X^6 - " << sixths_degree << endl;
    cout << "X^9 - " << nineth_degree << endl;
    cout << "X^15 - " << fifteen << endl;
    cout << "X^28 - " << twenty_eight << endl;
    cout << "X^64 - " << sixty_four << endl;

    return 0;
}
