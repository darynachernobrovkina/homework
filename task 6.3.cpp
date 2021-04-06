#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool sl_word(string &s){
    bool start_tag;
    int counter_start=0;
    int counter_end=0;
    for(size_t i=0; i<=s.length(); i++)
    {
        string buf;
        buf = s.substr(i, 4);
        if(buf == "<td>")
        {
            cout << "Zdarowa" << endl;
            start_tag = true;
            counter_start += 1;
        }
        else{
            buf = s.substr(i, 5);
            if(start_tag && buf == "</td>"){
                cout << "Close tag found" << endl;
                start_tag = false;
                counter_end += 1;
            }
        }
    }
    return start_tag || (counter_start != counter_end);
}

int main()
{
    ifstream File("file.txt");
    string str;
    bool only_start_tag;
    while (getline (File, str)) {
        only_start_tag = sl_word(str);
    }
    if(only_start_tag)
    {
        cout << "Not enough end tags";
    }
    return 0;
}
