// 3 sem  lab 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include<locale.h>

using namespace std;

class xxx
{
	double chislo;
	double f[3];
public:
	xxx(){};
	xxx(double ch) : chislo(ch) {}; 
	xxx(double i, double j, double k) { f[0] = i; f[1] = j; f[2] = k; };
	xxx operator++();
	xxx operator++(int);
	xxx operator+(xxx&a);
	xxx operator=(xxx);
	xxx operator==(xxx);
	xxx operator*(xxx&a);
	friend xxx operator--(xxx& ref);
	friend xxx operator--(xxx& ref, int d);
	friend xxx operator==( xxx& d1, double value);
	friend ostream& operator<<(ostream& os, const xxx& dt);
	friend xxx operator+(double value, const xxx& d1);
	friend xxx operator+(const xxx& d1,double value);
	double operator[](int i) 
	{
		return f[i]+5;
	}
	double operator()(int i)
	{
		return f[i] ;
	}
	operator int() { return chislo; }
	friend void print1(xxx m);
	friend void print2(xxx m,int i);
	friend void print3(xxx m, int i);

};

xxx xxx::operator++()      // перегрузка операции ++A

{
	chislo += 5;
	return *this;

}
xxx xxx::operator++(int)  // перегрузка операции A++
{
	xxx x;
	x.chislo += 5;
	return *this;
}
xxx xxx::operator+(xxx &m)
{
	return xxx(chislo + m.chislo + 10);
}
xxx xxx::operator*(xxx& m)
{
	return xxx(chislo * m.chislo);
}
xxx xxx::operator=(xxx m)

{
	chislo = -m.chislo;
	return *this;
}
xxx xxx::operator==(xxx m)
{
	chislo = m.chislo;
	return *this;
}
xxx operator--(xxx& ref)
{
	ref.chislo-=5;
	return ref;
}
xxx operator--(xxx& ref, int d)
{
	ref.chislo -= 5;
	return ref;
}
xxx operator+(double value, const xxx& d1)
{
	return xxx(d1.chislo + value);
}
xxx operator+(const xxx& d1, double value)
{
	return xxx(d1.chislo + value);
}
ostream& operator<<(ostream& os, const xxx& dt)
{
	os  << "||" << dt.chislo << "||";
	return os;
}
xxx operator==(xxx& d1, double value)
{
	d1.chislo= value;
	return d1;
}
void print1(xxx m)
{
	cout << "\n\nchislo = " << m.chislo ;
}
void print2(xxx m,int i)
{
	cout << "\n\nchislo[] = " << m[i];
}
void print3(xxx m, int i)
{
	cout << "\n\nchislo() = " << m(i);
}
int main()
{

	xxx m(80.9),a(50.1),b,k(1,2,3),c,x(9.0),z(8.1),d,l(3),p(2),i(2);
	double n = 7.9;
    int qqq;
	cout << "\nOperator = :";
	b = a;
	print1(b);
	cout << "\n\nOperator [] :";
	print2(k, 2);
	cout << "\n\nOperator () :";
	cout << k(1);
	cout << "\n\nOperator ++A :";
	++m;
	print1(m);
	cout << "\n\nOperator A++ :";
	m++;
	print1(m);
	cout << "\n\nOperator + :";
	c = x + z;
	print1(c);
	cout << "\n\nOperator == :";
	c == x;
	print1(c);

	cout << "\n\nOperator --A :";
	--x;
	print1(x);
	cout << "\n\nOperator A-- :";
	x--;
	print1(x);
	cout << "\n\nOperator + :";
	z=z + n;
	print1(z);
	cout << "\n\nOperator == :";
	z ==n;
	print1(z);
	cout << "\n\nOperator << :";
	cout << z;
	cout << "\n\nclass->double << :";
	qqq = z;
	cout << qqq;
	cout <<"\n\nxxx:";
	d = l * p++;
	cout<<"\n" << d;
	b= l * ++i;
	cout << "\n" << b;
	int aaa = 2;
	int bbb = 3;
	int ccc;
	ccc = aaa* bbb++;
	cout << ccc;
	return 0;
}
