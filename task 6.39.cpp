#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

int count_words(string str)
{
    int space=-1;
    int counter=0;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i] == ' ' || i == str.length()-1)
        {
            if(i - space < 2)
            {
                space = i;
                continue;
            }
            counter += 1;
            space = i;
        }
    }
    return counter;
}

string distribute_words(string str, int max_len)
{
    string new_string="", word;
    double spaces;
    int words_count = count_words(str);
    int spaces_count = words_count - 1;

    spaces = (double(max_len - str.length())) / spaces_count;
    if(spaces == 0)
        spaces = 1;

    int len_without_spaces = str.length() - spaces_count;
    int new_len_with_spaces = len_without_spaces + (int)spaces * spaces_count;
    //cout << "spaces: " << spaces << " Len: " << str.length() << " Wt-spaces: " << len_without_spaces << " New len: " << new_len_with_spaces << endl;

    int sapces_left = max_len - new_len_with_spaces;
    //cout << "Ne hvataet - " << sapces_left << endl;

    istringstream stream(str);
    while (stream >> word)
    {
        if(sapces_left)
        {
            new_string += word + string((int)spaces+1, ' ');
            sapces_left -= 1;
        }
        else{
            new_string += word + string((int)spaces, ' ');
        }
    }
    rtrim(new_string);
    return new_string;
}

int main()
{
    string str;
    int len, max_len=0;
    ifstream input("file.txt");
    ofstream output("file_out.txt");
    while(getline(input, str))
    {
        len = str.length();
        if(len > max_len)
            max_len = len;
    }
    input.close();

    ifstream input_again("file.txt");
    while(getline(input_again, str))
    {
        string new_str = distribute_words(str, max_len);
        cout << new_str << " " << new_str.length() << endl << endl;
        output << new_str << endl;
    }

    cout << endl << max_len;

    input_again.close();
    output.close();
    return 0;
}
