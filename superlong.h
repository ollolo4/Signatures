/**
    superlong.h - библиотека, которая позволяет объявлять переменные типа soperlong
    и работать с ними как с любыми другими переменными. Единственное их отличие от
    остальных    целочисленных типов - увеличенная длина. Числа типа superlong могут
    содержать в себе до SMAX разрядов. К числам данного типа применимы любые операции
    для работы с целочисленными типами.
    Дополнительные функции:
        * возведение a в степень b. T и M - челочисленные типы (включая superlong)
            pow (T a, M b);
        * длина - количество разрядов в числе a (superlong)
            a.length();
        * возвратить число a (superlong) в str (string)
            a.give(str);
        * записать в a (superlong) число из str (string)
            a.get(str);
**/

#define SMAX 20000

using namespace std;

template < class T > string stringOfInt( T n);
class superlong
{
private:
    long long arrayLength; // длина числа
    short intArray[SMAX]; // массив, содержащий SUPERLONG
    bool sign; // 1 - число положительное, 0 - отрицательное
public:
    superlong()
    {
        arrayLength = 1;
        for (long long i = 0; i < SMAX + 1; i++) intArray[i] = 0;
        sign = 1;
    }
    superlong(string s)
    {
        arrayLength = 1;
        for (long long i = 0; i < SMAX + 1; i++) intArray[i] = 0;
        sign = 1;
        (*this).get(s);
    }
    superlong(const char* c)
    {
        arrayLength = 1;
        string s;
        for (long long i = 0; i < SMAX + 1; i++) intArray[i] = 0;
        sign = 1;
        while (*c)
        {
            s += *c;
            c++;
        }
        (*this).get(s);
    }
    superlong(long long n)
    {
        arrayLength = 1;
        for (long long i = 0; i < SMAX + 1; i++) intArray[i] = 0;
        sign = 1;
        (*this).get(stringOfInt(n));
    }
    superlong(long n)
    {
        arrayLength = 1;
        for (long long i = 0; i < SMAX + 1; i++) intArray[i] = 0;
        sign = 1;
        (*this).get(stringOfInt(n));
    }
    superlong(int n)
    {
        arrayLength = 1;
        for (long long i = 0; i < SMAX + 1; i++) intArray[i] = 0;
        sign = 1;
        (*this).get(stringOfInt(n));
    }
    superlong(char n)
    {
        arrayLength = 1;
        for (long long i = 0; i < SMAX + 1; i++) intArray[i] = 0;
        sign = 1;
        (*this).get(stringOfInt(n - '0'));
    }
    ~superlong()
    {
        delete []intArray;
    }

    void get();
    void get(string s);
    void give();
    void give(string& s);
    long long length();
    superlong abs();
    template < class T > superlong shift( T n);


short& operator [] (long long n);

superlong operator +(superlong op2);
superlong operator -(superlong op2);
superlong operator *(superlong op2);
superlong operator /(superlong op2);

void operator --();
void operator ++();
void operator --(int);
void operator ++(int);

bool operator ==(superlong op2);
bool operator !=(superlong op2);
bool operator >=(superlong op2);
bool operator <=(superlong op2);
bool operator >(superlong op2);
bool operator <(superlong op2);

};


template < class T >
superlong operator +( T n, superlong op2);

template < class T >
superlong operator -( T n, superlong op2);

template < class T >
superlong operator *( T n, superlong op2);

template < class T >
superlong operator /( T n, superlong op2);

template < class T >
superlong operator %(superlong op1, T op2);

template < class T >
void operator +=(superlong& op1, T op2);

template < class T >
void operator -=(superlong& op1, T op2);

template < class T >
void operator *=(superlong& op1, T op2);

template < class T >
void operator /=(superlong& op1, T op2);

template < class T >
void operator %=(superlong& op1, T op2);

template < class T >
bool operator ==( T op1, superlong op2);

template < class T >
bool operator !=( T op1, superlong op2);

template < class T >
bool operator <( T op1, superlong op2);

template < class T >
bool operator >( T op1, superlong op2);

template < class T >
bool operator <=( T op1, superlong op2);

template < class T >
bool operator >=( T op1, superlong op2);

template < class T, class M >
superlong pow( M op1, T op2);

#include <sstream>
#include "functions.h"
#include "template.h"
#include "crypto.h"
