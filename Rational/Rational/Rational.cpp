#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>

using namespace std;

int GCD(int a, int b)
{
    int result{ 1 };

    while (a != b)
    {
        if ((a % 2 == 0) && (b % 2 == 0)) { result <<= 1; a >>= 1; b >>= 1; continue; }
        if ((a % 2 == 0) && (b % 2 != 0)) { a >>= 1; continue; }
        if ((a % 2 != 0) && (b % 2 == 0)) { b >>= 1; continue; }
        if ((a % 2 != 0) && (b % 2 != 0))
        {
            if (a > b) { a -= b; }
            if (a < b) { b -= a; }
            continue;
        }
    }
    result *= a;
    return result;
}

class Rational {
public:
    Rational() // конструктор по умолчанию
        :num{ 0 }, denom{ 1 }
    {}

    Rational(int numerator, int denominator)
    {
        if (numerator == 0)
        {
            num = 0;
            denom = 1;
        }
        else
        {
            int delitel = GCD(abs(numerator), abs(denominator));
            if (((numerator < 0) && (denominator < 0)) || ((numerator > 0) && (denominator < 0)))
            {
                num = -numerator / delitel;
                denom = -denominator / delitel;
            }

            if (((numerator < 0) && (denominator > 0)) || ((numerator > 0) && (denominator > 0)))
            {
                num = numerator / delitel;
                denom = denominator / delitel;
            }
        }
    }

    int Numerator() const {
        return num;
        // Реализуйте этот метод
    }

    int Denominator() const {
        return denom;
        // Реализуйте этот метод
    }

    friend std::istream& operator>> (std::istream& in, Rational& rat);

private:
    int num = 0;
    int denom = 1;
    // Добавьте поля
};

bool operator==(const Rational& left, const Rational& right)
{
    return ((left.Numerator() == right.Numerator()) && (left.Denominator() == right.Denominator()));
}

Rational operator+(const Rational& left, const Rational& right)
{
    int Newn = left.Numerator() * right.Denominator() + right.Numerator()* left.Denominator();
    int Newd = left.Denominator() * right.Denominator();

    return Rational(Newn,Newd);
}

Rational operator-(const Rational& left, const Rational& right)
{
    int Newn = left.Numerator() * right.Denominator() - right.Numerator() * left.Denominator();
    int Newd = left.Denominator() * right.Denominator();

    return Rational(Newn, Newd);
}

Rational operator*(const Rational& left, const Rational& right)
{
    int Newn = left.Numerator() * right.Numerator();
    int Newd = left.Denominator() * right.Denominator();

    return Rational(Newn, Newd);
}

Rational operator/(const Rational& left, const Rational& right)
{
    int Newn = left.Numerator() * right.Denominator();
    int Newd = left.Denominator() * right.Numerator();

    return Rational(Newn, Newd);
}

// Реализуйте для класса Rational операторы ==, + и -

std::ostream& operator<< (std::ostream& out, const Rational& rat)
{
    out << rat.Numerator() << '/' << rat.Denominator();
    return out;
}

std::istream& operator>> (std::istream& in, Rational& rat)
{
    int cnt{ 0 };
    char ch;
    if ((in >> ch)&&(ch!='/'))
    {   
        ++cnt;
        std::string chisl;
        bool flag = false;
        

        while (!in.eof())
        {
            ch = in.get();
            if (ch == '/') { flag = true; break; }
            else { ++cnt; }
        }

        if (!flag) return in;

        in.seekg(-cnt-1, std::fstream::cur);

        ch = in.get();

        while (ch != '/')
        {
            chisl += ch;
            ch=in.get();
        }

        

        std::string znam;

        while ((ch!=' ')&&(!in.eof()))
        {
            ch = in.get();
            znam += ch;
        }

        znam.pop_back();
        


        if (znam != "") { rat.denom = stoi(znam); }
        else { return in; }

        rat.num = stoi(chisl);

        int delitel = GCD(abs(rat.num), abs(rat.denom));

        rat.num /= delitel;
        rat.denom /= delitel;
    }

    return in;
}

int main() {
    {
        {
            const Rational r(3, 10);
            if (r.Numerator() != 3 || r.Denominator() != 10) {
                cout << "Rational(3, 10) != 3/10" << endl;
                return 1;
            }
        }

        {
            const Rational r(8, 12);
            if (r.Numerator() != 2 || r.Denominator() != 3) {
                cout << "Rational(8, 12) != 2/3" << endl;
                return 2;
            }
        }

        {
            const Rational r(-4, 6);
            if (r.Numerator() != -2 || r.Denominator() != 3) {
                cout << "Rational(-4, 6) != -2/3" << endl;
                return 3;
            }
        }

        {
            const Rational r(4, -6);
            if (r.Numerator() != -2 || r.Denominator() != 3) {
                cout << "Rational(4, -6) != -2/3" << endl;
                return 3;
            }
        }

        {
            const Rational r(0, 15);
            if (r.Numerator() != 0 || r.Denominator() != 1) {
                cout << "Rational(0, 15) != 0/1" << endl;
                return 4;
            }
        }

        {
            const Rational defaultConstructed;
            if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
                cout << "Rational() != 0/1" << endl;
                return 5;
            }
        }

        cout << "OK" << endl;
    }

    {
        {
            Rational r1(4, 6);
            Rational r2(2, 3);
            bool equal = r1 == r2;
            if (!equal) {
                cout << "4/6 != 2/3" << endl;
                return 1;
            }
        }

        {
            Rational a(2, 3);
            Rational b(4, 3);
            Rational c = a + b;
            bool equal = c == Rational(2, 1);
            if (!equal) {
                cout << "2/3 + 4/3 != 2" << endl;
                return 2;
            }
        }

        {
            Rational a(5, 7);
            Rational b(2, 9);
            Rational c = a - b;
            bool equal = c == Rational(31, 63);
            if (!equal) {
                cout << "5/7 - 2/9 != 31/63" << endl;
                return 3;
            }
        }

        cout << "OK" << endl;
    }

    {
        {
            Rational a(2, 3);
            Rational b(4, 3);
            Rational c = a * b;
            bool equal = c == Rational(8, 9);
            if (!equal) {
                cout << "2/3 * 4/3 != 8/9" << endl;
                return 1;
            }
        }

        {
            Rational a(5, 4);
            Rational b(15, 8);
            Rational c = a / b;
            bool equal = c == Rational(2, 3);
            if (!equal) {
                cout << "5/4 / 15/8 != 2/3" << endl;
                return 2;
            }
        }

        cout << "OK" << endl;
    }

    {
        {
            ostringstream output;
            output << Rational(-6, 8);
            if (output.str() != "-3/4") {
                cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
                return 1;
            }
        }

        {
            istringstream input("5/7");
            Rational r;
            input >> r;
            bool equal = r == Rational(5, 7);
            if (!equal) {
                cout << "5/7 is incorrectly read as " << r << endl;
                return 2;
            }
        }

        {
            istringstream input("");
            Rational r;
            bool correct = !(input >> r);
            if (!correct) {
                cout << "Read from empty stream works incorrectly" << endl;
                return 3;
            }
        }

        {
            istringstream input("5/7 10/8");
            Rational r1, r2;
            input >> r1 >> r2;
            bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
            if (!correct) {
                cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
                return 4;
            }

            input >> r1;
            input >> r2;
            correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
            if (!correct) {
                cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
                return 5;
            }
        }

        {
            istringstream input1("1*2"), input2("1/"), input3("/4");
            Rational r1, r2, r3;
            input1 >> r1;
            input2 >> r2;
            input3 >> r3;
            bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
            if (!correct) {
                cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                     << r1 << " " << r2 << " " << r3 << endl;

                return 6;
            }
        }

        cout << "OK" << endl;
    }


    return 0;
}
