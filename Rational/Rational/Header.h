#ifndef Rational_H
#define Rational_H

#include <ostream>
#include <istream>

class Rational
{
private:
    long int num; //числитель
    long int denom; //знаменатель    
public:   
    //Конструкторы
    Rational();
    Rational(long int num, long int denom);
    Rational(long int num);

    void CutBack();
    
    //Перегрузка операций
    Rational operator+ (const Rational & right) const;
    Rational operator- (const Rational & right) const;
    Rational operator* (const Rational & right) const;

    friend std::ostream& operator<< (std::ostream& left, const Rational& right);
    friend std::istream& operator>> (std::istream& in, Rational& right);
    friend Rational operator* (const long int left, const Rational& right);
};

long int gcd(size_t a, size_t b);
#endif //Rational_H
