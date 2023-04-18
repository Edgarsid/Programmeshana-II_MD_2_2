#ifndef VECTOR_H
#define VECTOR_H
#include <cstring>
#include <assert.h>


using namespace std;

class Vector		    // klase Vector								
{
	friend ostream &operator<<(ostream &, const Vector &);   // izvades parslogoshana
   	friend istream &operator>>(istream &, Vector &);   // izvades parslogoshana
   	
public:							
   	Vector(int = 6);   // konstruktors ar 6 punktuem
   	Vector(const Vector&);   // kopijas konstruktors
 	~Vector();   // destruktors
 	double vgarums() const;   // funkcija vektora garuma aprekjinam
 	
 	// operatoru parslogoshana:
	const Vector &operator=(const Vector &);
	const Vector &operator+=(const Vector &);	
	const Vector &operator-=(const Vector &);
	const Vector &operator*=(const Vector &);
	const Vector operator+(const Vector &);
	const Vector operator-(const Vector &);
	const Vector operator*(const Vector &);
	bool operator==(const Vector &) const;	
	bool operator!=(const Vector &) const;	
	bool operator>(const Vector &) const;	
	bool operator<(const Vector &) const;
	bool operator>=(const Vector &) const;	
	bool operator<=(const Vector &) const;		

private:												
	int masivs;  // vektoru garuma masivs, kur glabajas koordinates
	int *koord;   // vektora koordinates vertiba
	int *koordtemp;  // pagaidu vertiba
};

#endif
