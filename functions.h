#include <time.h>

using namespace std;

// считывание
istream &operator >>(istream &h, superlong &a)
{
    string str;
    h >> str;
    a.get(str);
    return h;
}

// вывод
ostream &operator <<(ostream &h, superlong a)
{
    string str;
    a.give(str);
    h << str;
    return h;
}

// считать superlong
void superlong::get()
{
    string s;
    //cin >> s;
    (*this).get(s);
}

// получить superlong из строки s
void superlong::get(string s)
{
    if (s[0] != '-')
    {
        for (long long i = 0; i < s.length(); i++)
        {
            intArray[i] = s[s.length() - i - 1] - '0';
        }
        arrayLength = s.length();
    }
    else
    {
        sign = 0;
        for (long long i = 0; i < s.length(); i++)
        {
            intArray[i - 1] = s[s.length() - i] - '0';
        }
        arrayLength = s.length() - 1;
    }

    if (!arrayLength)
    {
        (*this).arrayLength++;
    }
    if (s == "-0")
        (*this).sign = 1;
}

// возвратить superlong
void superlong::give()
{
    string s;
    (*this).give(s);
    //cout << s;
}

// возвратить superlong в строку s
void superlong::give(string& s)
{
    s.clear();
    if (!(*this).sign)
        s += '-';
    for (long long i = (*this).length() - 1; i >= 0; i--)
        s += (*this)[i] + '0';
}

// возвратить длину superlong
long long superlong::length()
{
    return arrayLength;
}

// сделать из long long строку
template < class T >
string stringOfInt( T n)
{
    stringstream ss;
    string s;
    ss << n;
    ss >> s;
    return s;
}

// *СИСТЕМНОЕ* сдвинуть superlong на n разрядов
template < class T >
superlong superlong::shift( T n)
{
    superlong temp;
    temp.arrayLength = (*this).length();
    for (long long i = 0; i < (*this).length(); i++)
        temp[i + n] = (*this)[i];
    temp.arrayLength += n;
    return temp;
}

// возвратить модуль superlong
superlong superlong::abs()
{

    superlong temp1 = (*this);
    temp1.sign = 1;
    return temp1;
}

short& superlong::operator [](long long n)
{
    return ((*this).intArray[n]);
}

superlong superlong::operator +(superlong op2)
{
    superlong temp = (*this);
    if (temp.sign == op2.sign)
    {
        for (long long i = 0; i < max(op2.length(), temp.length()); i++)
        {
            temp[i] += op2[i];
            if (temp[i] > 9)
            {
                temp[i + 1] += temp[i] / 10;
                temp[i] %= 10;
            }
        }
        long long i = max(op2.length(), temp.length()) + 1;
        while ((temp[i] == 0) && (i != 0)) i--;
        temp.arrayLength = i + 1;
        return temp;
    }
    else if (temp.sign)
    {
        if (temp.abs() >= op2.abs())
        {
            for (long long i = 0; i < max(op2.length(), temp.length()); i++)
            {
                temp[i] -= op2[i];
                if (temp[i] < 0)
                {
                    temp[i + 1] -= 1;
                    temp[i] += 10;
                }
            }

            long long i = max(op2.length(), (*this).length()) + 1;
            while (!temp[i] && i != 0)
                i--;
            temp.arrayLength = i + 1;
            return temp;
        }
        else
        {
            temp.sign = 0;
            temp = op2.abs() + temp;
            temp.sign = 0;
            return temp;
        }
    }
    else
    {
        return (op2 + temp);
    }
}

superlong superlong::operator -(superlong op2)
{
    op2.sign = !op2.sign;
    return ((*this) + op2);
}

superlong superlong::operator *(superlong op2)
{
    superlong temp;
    for (long long j = 0; j < op2.length(); j++)
    {
        for (long long i = 0; i < (*this).length(); i++)
        {
            temp[i + j] += (*this)[i] * op2[j];
        }
    }
    temp.arrayLength = op2.length() + (*this).length() - 1;
    temp -= 1;
    temp += 1;
    if (((*this).sign != op2.sign) && (temp != 0))
        temp.sign = 0;
    else
        temp.sign = 1;
    return temp;
}

superlong superlong::operator /(superlong op2)
{
    if (op2.intArray)
    {
        long long j, t = 1;
        superlong rez, op1 = (*this), tempo = op2;
        while (op1 >= op2)
        {
            tempo = op2;
            j = -1;
            while (op1 >= tempo)
            {
                tempo = tempo.shift(1);
                j++;
            }
            tempo = tempo.shift(-1);
            if (t)
            {
                t = 0;
                rez.arrayLength = j + 1;
            }
            while (op1 >= tempo)
            {
                op1 = op1 - tempo;
                rez[j]++;
            }
        }
        rez = rez + 0;
        return rez;
    }
    else
    {
        superlong err;
        return err;
    }
}


bool superlong::operator ==(superlong op2)
{
    if ((*this).sign != op2.sign)
        return 0;
    for (long long i = 0; i < max((*this).length(), op2.length()); i++)
        if ((*this)[i] != op2[i])
            return 0;
    return 1;
}

bool superlong::operator >(superlong op2)
{
    if ((*this).sign == op2.sign)
    {
        if ((*this).length() > op2.length())
            return ((*this).sign == 1 ? 1 : 0);
        else if ((*this).length() < op2.length())
            return ((*this).sign == 1 ? 0 : 1);
        else
        {
            for (long long i = (*this).length() - 1; i >= 0; i--)
            {
                if ((*this)[i] > op2[i])
                    return ((*this).sign ? 1 : 0);
                else if ((*this)[i] < op2[i])
                    return ((*this).sign ? 0 : 1);
            }
            return 0;                                               /// ХЗ ЗАЧЕМ
        }
    }
    else
        return ((*this).sign ? 1 : 0);
}

bool superlong::operator <(superlong op2)
{
    return ((((*this) > op2) || ((*this) == op2)) ? 0 : 1);
}

bool superlong::operator <=(superlong op2)
{
    return ((*this) < op2 || (*this) == op2);
}

bool superlong::operator >=(superlong op2)
{
    return ((*this) > op2 || (*this) == op2);
}

bool superlong::operator !=(superlong op2)
{
    return (!((*this) == op2));
}

void superlong::operator ++()
{
    (*this) = (*this) + 1;
}

void superlong::operator --()
{
    (*this) = (*this) - 1;
}

void superlong::operator ++(int)
{
    (*this) = (*this) + 1;
}

void superlong::operator --(int)
{
    (*this) = (*this) - 1;
}
