#ifndef _EQUASIONS_H_
#define _EQUASIONS_H_

#include <cmath>
class LinearEquasion
{
protected:
    double *p;

public:
    LinearEquasion()
    {
        this->p = new double[2];
    }

    LinearEquasion(double *arr)
    {
        this->p = new double[2];
        for(int i=0; i<2; i++)
        {
            this->p[i] = arr[i];
        }
    }

    LinearEquasion(const LinearEquasion &equas)
    {
        this->p = new double[2];
        for(int i=0; i<2; i++)
        {
            this->p[i] = equas.p[i];
        }
    }

    LinearEquasion operator=(const LinearEquasion &equas)
    {
        this->p = new double[2];
        for(int i=0; i<2; i++)
        {
            this->p[i] = equas.p[i];
        }
    }

    virtual ~LinearEquasion()
    {
        delete[] this->p;
    }

    double solve()
    {
        return -(this->p[1] / this->p[0]);
    }

    int set(size_t k, double value)
    {
        if(k > 1 || k < 0)
        {
            throw std::invalid_argument( "received wrong value" );
        }
        this->p[k] = value;
    }

    double get(size_t k)
    {
        if(k > 1 || k < 0)
        {
            throw std::invalid_argument( "received wrong value" );
        }
        return this->p[k];
    }

    void show()
    {
        if(this->p[1] > 0)
        {
            std::cout << this->p[0] << "x + " << this->p[1] << " = 0" << std::endl;
        }
        else{
            std::cout << this->p[0] << "x - " << abs(this->p[1]) << " = 0" << std::endl;
        }
    }

    //friend writeFile(std::string fname, const LinearEquasion &equas);
    //friend readFile(std::string fname, LinearEquasion &equas);
};

class QuadraticEquasion: public LinearEquasion
{
public:
    explicit QuadraticEquasion()
    {
        this->p = new double[3];
    }

    explicit QuadraticEquasion(double *arr)
    {
        this->p = new double[3];
        for(int i=0; i<3; i++)
        {
            this->p[i] = arr[i];
        }
    }

    explicit QuadraticEquasion(const QuadraticEquasion &equas)
    {
        this->p = new double[3];
        for(int i=0; i<3; i++)
        {
            this->p[i] = equas.p[i];
        }
    }

    QuadraticEquasion operator=(const QuadraticEquasion &equas)
    {
        this->p = new double[3];
        for(int i=0; i<3; i++)
        {
            this->p[i] = equas.p[i];
        }
    }

    virtual ~QuadraticEquasion()
    {
        delete[] this->p;
    }

    double *solve()
    {
        double *res = new double[3];
        double a = this->p[0];
        double b = this->p[1];
        double c = this->p[2];
        double discriminant = b*b - 4*a*c;
        //std::cout << a << " " << b << " " << c << " Discr : " << discriminant << std::endl;
        if(discriminant > 0)
        {
            res[0] = 2;
            res[1] = (-b + sqrt(discriminant)) / (2*a);
            res[2] = (-b - sqrt(discriminant)) / (2*a);
        }
        else if(discriminant == 0)
        {
            res[0] = 1;
            res[1] = -b / (2*a);
            res[2] = 0;
        }
        else
        {
            res[0] = 0;
            res[1] = 0;
            res[2] = 0;
        }
        return res;
    }

    int set(size_t k, double value)
    {
        if(k > 2 || k < 0)
        {
            throw std::invalid_argument( "received wrong value" );
        }
        this->p[k] = value;
    }

    double get(size_t k)
    {
        if(k > 2 || k < 0)
        {
            throw std::invalid_argument( "received wrong value" );
        }
        return this->p[k];
    }


    void show()
    {
        std::cout << this->p[0] << "x^2";
        if(this->p[1] > 0)
        {
            std::cout << " + " << this->p[1] << "x";
        }
        else
        {
            std::cout << " - " << abs(this->p[1]) << "x";
        }
        if(this->p[2] > 0)
        {
            std::cout << " + " << this->p[2] << " = 0" << std::endl;
        }
        else
        {
            std::cout << " - " << abs(this->p[2]) << " = 0" << std::endl;
        }
    }
};

class BiquadraticEquasion: public QuadraticEquasion
{
public:
    using QuadraticEquasion::QuadraticEquasion;

    virtual ~BiquadraticEquasion()
    {
        delete[] this->p;
    }

    BiquadraticEquasion operator=(const BiquadraticEquasion &equas)
    {
        this->p = new double[3];
        for(int i=0; i<3; i++)
        {
            this->p[i] = equas.p[i];
        }
    }

    double *solve()
    {
        double *res = new double[5];
        double *quadres = QuadraticEquasion::solve();
        if(quadres[0] == 0)
        {
           res[0] = 0;
        }
        else if(quadres[0] == 1)
        {
            if(quadres[1] > 0)
            {
               res[0] = 2;
               res[1] = sqrt(quadres[1]);
               res[2] = -sqrt(quadres[1]);
            }
            else{
               res[0] = 0;
            }
        }
        else{
            if(quadres[1] > 0)
            {
               res[0] = 2;
               res[1] = sqrt(quadres[1]);
               res[2] = -sqrt(quadres[1]);
               if(quadres[2] > 0)
               {
                   res[0] = 4;
                   res[3] = sqrt(quadres[2]);
                   res[4] = -sqrt(quadres[2]);
               }
            }
            else{
               res[0] = 0;
            }
        }
        //return quadres;
        return res;
    }

    void show()
    {
        std::cout << this->p[0] << "x^4";
        if(this->p[1] > 0)
        {
            std::cout << " + " << this->p[1] << "x^2";
        }
        else
        {
            std::cout << " - " << abs(this->p[1]) << "x";
        }
        if(this->p[2] > 0)
        {
            std::cout << " + " << this->p[2] << " = 0" << std::endl;
        }
        else
        {
            std::cout << " - " << abs(this->p[2]) << " = 0" << std::endl;
        }
    }
};


#endif // _LinearEquasion_H_
