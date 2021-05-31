#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <random>

using namespace std;

string random_string(size_t length)
{
    string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string random_string;

    for (std::size_t i = 0; i < length; ++i)
    {
        int rnd = rand() % chars.length();
        random_string += chars[rnd+1];
    }

    return random_string;
}

void write_to_file(string fname, int n)
{
    srand(time(0));
    ofstream file(fname);
    for(int i=0; i<n; i++)
    {
        int len = rand() % 30;
        file << random_string(len) << endl;
    }
    file.close();
}

int main()
{
    string fname = "text.txt";
    ofstream out_odd("text_odd.txt");
    ofstream out_even("text_even.txt");
    string str;
    write_to_file(fname, 4);

    ifstream input(fname);
    while(getline(input, str))
    {
        int len = str.length();
        cout << str << "  len - " << len << endl;
        if(len % 2)
        {
            out_odd << str << endl;
        }
        else{
            out_even << str << endl;
        }
    }
    input.close();
    out_odd.close();
    out_even.close();
    return 0;
}
