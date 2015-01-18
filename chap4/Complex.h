#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include <iostream>

class Complex
{
private:
    float re;
    float im;
public:
    Complex(float x, float y);
    float Re() const;
    float Im() const;
    Complex& operator*=(const Complex& rhs);

    friend std::ostream& operator<<(std::ostream& t, const Complex& c);
};
#endif
