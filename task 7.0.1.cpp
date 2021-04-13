#include <iostream>
#include <string>

using namespace std;

int gcd(int a, unsigned b);

class Rational
{
private:
    int nominator;
    unsigned denominator;
public:
    void show()
    {
        cout << this->nominator << "/" << this->denominator << endl;
    }

    int input()
    {
        cout << "n/m = ";
        cin >> this->nominator >> this->denominator;
    }

    Rational()
    {
        this->nominator = 0;
        this->denominator = 1;
    }
    Rational(int nom, unsigned den)
    {
        this->nominator = nom;
        this->denominator = den;
    }

    Rational add(Rational other)
    {
        Rational new_rat;
        new_rat.nominator = this->nominator * other.denominator + this->denominator * other.nominator;
        new_rat.denominator = this->denominator * other.denominator;
        return new_rat;
    }

    Rational multiply(Rational other)
    {
        Rational new_rat;
        new_rat.nominator = this->nominator * other.nominator;
        new_rat.denominator = this->denominator * other.denominator;
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

};

int gcd(int a, unsigned b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
}

int main()
{
    Rational first, second, sum;

    first.input();
    second.input();

    first.show();
    second.show();
    sum = first.add(second);
    sum.show();

    sum = first.multiply(second);
    sum.show();

    sum = sum.reduce();
    sum.show();

    return 0;
}
