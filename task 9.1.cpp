#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int gcd(int a, unsigned b);

class Rational
{
private:
    int nominator;
    unsigned denominator;

public:
    Rational()
    {
        this->nominator = 0;
        this->denominator = 1;
    }
    Rational(int nom, unsigned den)
    {
        if (den == 0)
        {
            throw std::invalid_argument("Denominator received negative or '0' as value");
        }
        this->nominator = nom;
        this->denominator = den;
    }

    void setNominator(int nom)
    {
        this->nominator = nom;
    }

    void setDenominator(int denom)
    {
        if (denom == 0)
        {
            throw std::invalid_argument("Denominator received negative or '0' as value");
        }
        this->denominator = denom;
    }

    Rational operator+(int number)
    {
        Rational new_rat;
        new_rat.nominator = this->nominator + number * this->denominator;
        new_rat.denominator = this->denominator;
        return new_rat;
    }

    Rational operator+(Rational other)
    {
        Rational new_rat;
        new_rat.nominator = this->nominator * other.denominator + this->denominator * other.nominator;
        new_rat.denominator = this->denominator * other.denominator;
        return new_rat;
    }

    Rational operator-(int number)
    {
        Rational new_rat;
        new_rat.nominator = this->nominator - number * this->denominator;
        new_rat.denominator = this->denominator;
        return new_rat;
    }

    Rational operator-(Rational other)
    {
        Rational new_rat;
        new_rat.nominator = this->nominator * other.denominator - this->denominator * other.nominator;
        new_rat.denominator = this->denominator * other.denominator;
        return new_rat;
    }

    Rational operator*(int number)
    {
        Rational new_rat;
        new_rat.nominator = this->nominator * number;
        new_rat.denominator = this->denominator;
        return new_rat;
    }

    Rational operator*(Rational other)
    {
        Rational new_rat;
        new_rat.nominator = this->nominator * other.nominator;
        new_rat.denominator = this->denominator * other.denominator;
        return new_rat;
    }

    Rational operator/(int number)
    {
        Rational new_rat;
        new_rat.nominator = this->nominator;
        new_rat.denominator = this->denominator * number;
        return new_rat;
    }

    Rational operator/(Rational other)
    {
        Rational new_rat;
        new_rat.nominator = this->nominator * other.denominator;
        new_rat.denominator = this->denominator * other.nominator;
        return new_rat;
    }

    Rational reduce()
    {
        Rational rat;
        int podelit = gcd(this->nominator, this->denominator);
        int new_nom = this->nominator / podelit;
        unsigned new_denom = this->denominator / podelit;
        rat.nominator = new_nom;
        rat.denominator = new_denom;
        return rat;
    }

    friend void loadToFile(string filename, Rational &rat);
    friend std::ostream &operator<<(std::ostream &os, const Rational &str);
    friend std::istream &operator>>(std::istream &is, Rational &str);
};

void loadToFile(string filename, Rational &rat)
{
    ofstream file;
    file.open(filename, std::ios_base::app);
    if (file.fail())
    {
        cout << "There is no file named '" << filename << "'" << endl;
        return;
    }

    file << rat;
    file.close();
}

std::ostream &operator<<(std::ostream &os, const Rational &rat)
{
    return os << rat.nominator << " / " << rat.denominator << endl;
}

std::istream &operator>>(std::istream &is, Rational &rat)
{
    cout << "n/m = ";
    is >> rat.nominator >> rat.denominator;
    if (rat.denominator == 0)
    {
        throw std::invalid_argument("Denominator received negative or '0' as value");
    }
    return is;
}

int gcd(int a, unsigned b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    Rational first, second;
    Rational sum, mult, subst, div;
    bool again = false;

    do
    {
        try
        {
            cout << "Enter rationals: " << endl;
            again = false;
            cin >> first;
            cin >> second;
        }
        catch (invalid_argument inv)
        {
            cout << "Invalid denominator, please enter right values..." << endl;
            again = true;
        }
    } while (again);

    cout << endl;
    cout << "First - " << first;
    cout << "Second - " << second;
    sum = first + second;
    cout << "Sum -  " << sum;

    subst = first - second;
    cout << "Substraction -  " << subst;

    div = first / second;
    cout << "Division -  " << div;

    mult = first * second;
    cout << "Mult -  " << mult;

    mult = mult.reduce();
    cout << "Mult reduced -  " << mult;

    loadToFile("somefile.txt", sum);
    loadToFile("somefile.txt", subst);
    loadToFile("somefile.txt", div);
    loadToFile("somefile.txt", mult);

    return 0;
}