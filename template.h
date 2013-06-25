#include <string>
#include <fstream>

using namespace std;

#define N 20001

int div( char *, char *, char *, char * );

template < class T >
superlong operator +( T n, superlong op2)
{
    superlong temp;
    temp = op2 + n;
    return (temp);
}

template< class T >
superlong operator -( T n, superlong op2)
{
    superlong temp;
    temp = op2 - n;
    return (temp);
}

template< class T >
superlong operator *( T n, superlong op2)
{
    superlong temp;
    temp = op2 * n;
    return (temp);
}

template< class T >
superlong operator /( T n, superlong op2)
{
    superlong temp = n;
    temp = temp / op2;
    return (temp);
}

template < class T >
superlong operator %(superlong op1, T op2)
{
    char *a  = new char [N];
    char *b  = new char [N];
    char *res = new char [N];
    char *rem = new char [N];;
    string str;
    superlong c;

    op1.give( str );
    strcpy( a, str.c_str() );
    op2.give( str );
    strcpy( b, str.c_str() );

    div(a,b,res,rem);

    c.get( rem );

    free(a);
    free(b);
    free(res);
    free(rem);

    return c;
}

template < class T >
void operator +=(superlong& op1, T op2)
{
    op1 = op1 + op2;
}

template < class T >
void operator -=(superlong& op1, T op2)
{
    op1 = op1 - op2;
}

template < class T >
void operator *=(superlong& op1, T op2)
{
    op1 = op1 * op2;
}

template < class T >
void operator /=(superlong& op1, T op2)
{
    op1 = op1 / op2;
}

template < class T >
void operator %=(superlong& op1, T op2)
{
    op1 = op1 % op2;
}

template < class T >
bool operator ==( T op1, superlong op2)
{
    superlong temp = op1;
    return (temp == op2);
}

template < class T >
bool operator !=( T op1, superlong op2)
{
    superlong temp = op1;
    return (temp != op2);
}

template < class T >
bool operator >( T op1, superlong op2)
{
    superlong temp = op1;
    return (temp > op2);
}

template < class T >
bool operator <( T op1, superlong op2)
{
    superlong temp = op1;
    return (temp < op2);
}

template < class T >
bool operator >=( T op1, superlong op2)
{
    superlong temp = op1;
    return (temp >= op2);
}

template < class T >
bool operator <=( T op1, superlong op2)
{
    superlong temp = op1;
    return (temp <= op2);
}

// возводит (*this) в степень op2 ( this ^ op2)
template < class T, class M >
superlong pow( M op1, T op2)
{
    superlong rez = 1;
    for (long long i = 0; i < op2 ; i++)
    {
        rez *= op1;
    }
    rez -= 1;
    rez += 1;
    return rez;
}
