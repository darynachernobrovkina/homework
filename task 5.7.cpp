#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <tuple>

using namespace std;

tuple<double, int> find_first_number(string &str, int pos)
{
    char chararr[20];
    string contains_num;
    double number;
    int first_eq = str.find("=", pos);
    int probel = str.find(" ", pos);
    //cout << first_eq << " " << probel << endl;
    pos = probel;

    str.copy(chararr, probel-first_eq-1, first_eq+1);
    contains_num = chararr;

    stringstream mystream(contains_num);
    mystream >> number;

    return make_tuple(number, pos);
}

double find_numbers(string &s){
    int pos=0;
    double num, summ=0;
    for(int i=0; i<3; i++)
    {
        tie(num, pos) = find_first_number(s, pos);
        pos += 1;
        //cout << num << " " << pos << endl;
        summ += num;
    }
    return summ;
}

int main()
{
    string str;
    cout << "Enter string: ";
    getline(cin, str);
    cout << find_numbers(str);
    return 0;
}
