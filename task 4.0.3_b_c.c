#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int numerator;
    unsigned int denominator;
} Rational;

int input(Rational *x)
{
    printf("Enter numerator denominator - ");
    scanf("%d", &x->numerator);
    scanf("%d", &x->denominator);
    return 0;
}

void print(const Rational x)
{
    printf("%d/%u\n", x.numerator, x.denominator);
}

Rational multiplication(Rational first, Rational second)
{
    Rational result;

    result.numerator = (int)(first.numerator * second.numerator);
    result.denominator = first.denominator * second.denominator;

    return result;
}

int compare(Rational first, Rational second)
{
    int num_first = first.numerator * second.denominator;
    int num_second = second.numerator * first.denominator;
    if(num_first == num_second) return 0;
    else if(num_first > num_second) return 1;
    else if(num_first < num_second) return 2;
}

int main()
{
    Rational a, b, mult;
    input(&a);
    input(&b);

    print(a);
    print(b);

    mult = multiplication(a, b);
    print(mult);
    printf("\n%d", compare(a, b));

    return 0;
}
