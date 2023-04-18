#include <iostream>
#include <cstring>
#include "Vector.h"
#include <assert.h>
#include <cmath>

using namespace std;


Vector::Vector(int i)   // konktrutkors
{
   masivs = i;
   koord = new int[masivs];
   assert(koord != 0); //beidzam ja atmina nav izdaliita
   for (int i = 0; i < masivs; i++)
      koord[i] = 0;
}

Vector::Vector(const Vector &kopija)  // kopijas konktruktors = lai koordinates tiktu veidotas donamiski
{
   masivs = kopija.masivs;
   koord = new int[masivs];
   assert(koord != 0); //beidzam ja atmina nav izdaliita
   for (int i = 0; i < masivs; i++)
      koord[i] = kopija.koord[i];
}

Vector::~Vector()  // destruktors
{
   	delete [] koord;
}

double Vector::vgarums() const  // funkcija garuma aprekjinahanai pec formulas no interneta
{
	return sqrt(pow((koord[3] - koord[0]), 2) +
	pow((koord[4] - koord[1]), 2) +
	pow((koord[5] - koord[2]), 2));
}

ostream &operator << (ostream &output, const Vector &a)
{
	output << "Vektora garums = " << a.vgarums() << endl;  // izvada uzreiz vektora garumu
   	return output;
}

istream &operator >> (istream &input, Vector &a)  // vektora punktu ievade pa taisno masiivaa
{
   	for (int i = 0; i < a.masivs; i++)
    	input >> a.koord[i];
   	return input;
}


const Vector &Vector::operator = (const Vector &right)  // vertibu pieshkjirshana
{
   if (&right != this) //paarbauda vai nav tas pats masiivs, ja ir tas pats nekas nav jaadara
   {
      delete [] koord;
      koord = new int[masivs]; //atminas izdalisana masiiva koppijai
      assert(koord != 0);
   
      for (int i = 0; i < masivs; i++)
         koord[i] = right.koord[i];
         
      return *this; //lauj x = y = z 
   }
   return *this; //lauj x = y = z  
}


const Vector Vector::operator+(const Vector &right)   // vektoru saskatishana
{
   Vector koordtemp(masivs);
   for (int i = 0; i < masivs; i++)
      koordtemp.koord[i] = koord[i] + right.koord[i];
   return koordtemp; //lauj x + y = z
}

const Vector Vector::operator-(const Vector &right)  // vektoru atnjemshana
{
   Vector koordtemp(masivs);
   for (int i = 0; i < masivs; i++)
      koordtemp.koord[i] = koord[i] - right.koord[i];
   return koordtemp; //lauj x - y = z
}

const Vector Vector::operator * (const Vector &right)  // vektorialais reizinajums (formula no interneta)
{
   	Vector koordtemp(masivs);
    koordtemp.koord[0] = koord[1] * right.koord[2] - koord[2] * right.koord[1],
    koordtemp.koord[1] = koord[2] * right.koord[0] - koord[0] * right.koord[2],
    koordtemp.koord[2] = koord[0] * right.koord[1] - koord[1] * right.koord[0],
    koordtemp.koord[3] = koord[4] * right.koord[5] - koord[5] * right.koord[4],
    koordtemp.koord[4] = koord[5] * right.koord[3] - koord[3] * right.koord[5],
    koordtemp.koord[5] = koord[3] * right.koord[4] - koord[4] * right.koord[3];
   	return koordtemp; 
}


const Vector &Vector::operator += (const Vector &right)  //  nepiecieshams, lai varetu masivus saskaitit
{
   for (int i = 0; i < masivs; i++)
      koord[i] += right.koord[i];
   return *this; //lauj x = y = z
}

const Vector &Vector::operator -= (const Vector &right)  // nepiecieshams, lai masivus varetu atnjemt
{
   for (int i = 0; i < masivs; i++)
      koord[i] -= right.koord[i];
   return *this; //lauj x = y = z
}

const Vector &Vector::operator *= (const Vector &right)  // nepiecieshams, lai masivus varetu sarezinat
{
   for (int i = 0; i < masivs; i++)
      koord[i] *= right.koord[i];
   return *this; //lauj x = y = z
}

// taalaak metodes vektoru saliidzinaashanai.  Metodes sintakses ir lidzigas, atshkjiras tikai operatori
bool Vector::operator==(const Vector &ir) const
{
	if(vgarums() == ir.vgarums())
		return true;
	else
		return false;
}

bool Vector::operator!=(const Vector &ir) const
{
	if(vgarums() == ir.vgarums())
		return false;
	else
		return true;
}

bool Vector::operator>(const Vector &ir) const
{
	if(vgarums() > ir.vgarums())
		return true;
	else
		return false;
}

bool Vector::operator<(const Vector &ir) const
{
	if(vgarums() < ir.vgarums())
		return true;
	else
		return false;
}

bool Vector::operator>=(const Vector &ir) const
{
	if(vgarums() > ir.vgarums() || vgarums() == ir.vgarums())
		return true;
	else
		return false;
}

bool Vector::operator<=(const Vector &ir) const
{
	if(vgarums() < ir.vgarums() || vgarums() == ir.vgarums())
		return true;
	else
		return false;
}
