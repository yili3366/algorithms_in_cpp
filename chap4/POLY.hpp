#ifndef __POLY_HPP_
#define __POLY_HPP_

template <class Number>
class POLY
{
private:
    int n;
    Number *a;

public:
    POLY<Number>(Number c, int N);
    float eval(float x) const;

//    friend POLY<Number> operator+(POLY<Number> &p, POLY<Number> &q);
//    friend POLY<Number> operator*(POLY<Number> &p, POLY<Number> &q);

    template<typename T>
    friend POLY<T> operator+(POLY<T> &p, POLY<T> &q);

    template<typename T>
    friend POLY<T> operator*(POLY<T> &p, POLY<T> &q);

    template<typename T>
    friend std::ostream& operator<<(std::ostream& t, const POLY<T>& p);
};

template <typename Number>
POLY<Number>::POLY(Number c, int N)
{
    a = new Number[N + 1];
    n = N + 1;
    a[N] = c;

    for (int i = 0; i < N; i++)
        a[i] = 0;
}

template <typename Number>
float POLY<Number>::eval(float x) const
{
    double t = 0.0;

    for (int i = n-1; i >= 0; i--)
        t = t * x + a[i];

    return t;
}

//template <typename Number>
//POLY<Number> POLY<Number>::operator+(POLY<Number> &p, POLY<Number> &q)
template <typename T>
POLY<T> operator+(POLY<T> &p, POLY<T> &q)
{
    POLY<T> t(0, p.n>q.n ? p.n-1 : q.n-1);

    for (int i = 0; i < p.n; i++)
        t.a[i] += p.a[i];

    for (int j = 0; j < q.n; j++)
        t.a[j] += q.a[j];

    return t;
}

//template <typename Number>
//POLY<Number> POLY<Number>::operator*(POLY<Number> &p, POLY<Number> &q)
template <typename T>
POLY<T> operator*(POLY<T> &p, POLY<T> &q)
{
    POLY<T> t(0, (p.n-1)+(q.n-1));

    for (int i = 0; i < p.n; i++)
        for (int j = 0; j < q.n; j++)
            t.a[i+j] += p.a[i]*q.a[j];

    return t;
}

template<typename T>
std::ostream& operator<<(std::ostream& t, const POLY<T> &p)
{
    for (int i = 0; i < p.n; i++) {
        t << p.a[i];
    }
    return t;
}
#endif
