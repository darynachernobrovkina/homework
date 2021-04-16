#include <iostream>
#include <string>

using namespace std;

int count_words(string str, string to_find)
{
    int counter=0;
    int word_len = to_find.length();
    for(int i=0; i<str.length(); i++)
    {
        string sub = str.substr(i, word_len);
        if(sub == to_find)
            counter++;
        //cout << sub << endl;
    }
    //cout << endl;
    return counter;
}

string delete_words(string str, int n)
{
    string word="";
    string new_string;
    int space=0;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i] == ' ' || i == str.length()-1)
        {
            if(i == str.length()-1)
                word.push_back(str[i]);

            int counted = count_words(str, word);
            if(counted != n){
                //cout << word << " was met " << counted << " times" << endl;
                new_string += word + " ";
            }
            //cout << word << endl;
            word="";
        }
        else
        {
            word.push_back(str[i]);
        }

    }
    return new_string;
}


int main()
{
    int n;
    string str;
    string new_string;
    cout << "Enter string: ";
    getline(cin, str);
    cout << "Enter n: ";
    cin >> n;
    cout <<  endl;
    new_string = delete_words(str, n);
    cout << endl << new_string;

    return 0;
}
