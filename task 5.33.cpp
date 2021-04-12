#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Date{
    int day;
    int month;
    int year;
};

bool compare_dates(struct Date first, struct Date second)
{
    if(first.year > second.year){
        return true;
    }
    else if(first.year < second.year){
        return false;
    }
    if(first.month > second.month){
        return true;
    }
    else if(first.month < second.month){
        return false;
    }
    if(first.day > second.day){
        return true;
    }
    else if(first.day < second.day){
        return false;
    }
    else return true;
}

struct Date string_to_date(string str)
{
    struct Date date;
    date.day = stoi(str.substr(1, 2));
    date.month = stoi(str.substr(4, 2));
    date.year = stoi(str.substr(7, 4));
    return date;
}

string date_to_string(struct Date date)
{
    string day, month, year;
    if(date.day < 10)
        day = "0" + to_string(date.day);
    else day = to_string(date.day);
    if(date.month < 10)
        month = "0" + to_string(date.month);
    else month = to_string(date.month);
    year = to_string(date.year);
    return day + "/" + month + "/" + year;
}


int parse_dates(string str, string filename)
{
    ofstream output(filename);
    struct Date max_date={1, 1, 2006};
    struct Date min_date={1, 1, 2006};
    char delimiter=',';
    int len = str.length();
    int start=0;
    for(int i=0; i<=len; i++)
    {
        if(str[i]==delimiter || i == len)
        {
            string datestr = str.substr(start, i-start);
            struct Date date = string_to_date(datestr);
            //cout << date.day << " " << date.month << " " << date.year << " " << endl;
            cout << date_to_string(date) << endl;
            if(start == 0)
            {
                max_date = date;
                min_date = date;
            }
            if(compare_dates(date, max_date))
            {
                max_date = date;
            }
            if(compare_dates(min_date, date))
            {
                min_date = date;
            }
            start = i+1;
        }
    }
    cout << "Max: " << date_to_string(max_date) << endl << endl;
    cout << "Min: " << date_to_string(min_date) << endl << endl;
    output << "Max: " << date_to_string(max_date) << endl;
    output << "Min: " << date_to_string(min_date);
    output.close();
    return 0;
}


int main()
{
    ifstream input("dates.txt");
    string str;
    cout << "Dates: " << endl;
    while(getline(input, str)){
        parse_dates(str, "maxmin.txt");
    }
    input.close();
    return 0;
}
