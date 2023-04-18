#include <iostream>
#include <string>
#include "Vector.h"
#include <assert.h>

using namespace std;



int main()
{
	
	Vector A, B, C, D, E, F;  // dazhadi vektori prieksh funkciju demonstreshanas
	

	cout << "Ievadiet A vektora koordinates" << endl << "x1, y1, z1, x2, y2, z2" << endl;
	cin >> A;
	cout << A << endl;
	
	cout << "Ievadiet B vektora koordinates" << endl << "x1, y1, z1, x2, y2, z2" << endl;
	cin >> B;
	cout << B << endl;
	
	E = A * B;
	cout << "Vektoru A un B vektorialais rezinajums: " << E << endl;
	
	C = A + B;
	cout << "Vektoru A un B summa: " << C << endl;
	
	D = A - B;
	cout << "Vektoru A un B atnjemshana: " << D << endl;
	

	
	F = A;
	cout << "Vektors F ir vienads ar A: " << F << endl;
	
	cout << "Salidzinashanu demonstracijas. 1 = TRUE / 0 = FALSE" << endl;
	cout << (A == B) << endl;
	cout << (A != B) << endl;
	cout << (A > B) << endl;
	cout << (A < B) << endl;
	cout << (A >= B) << endl;
	cout << (A <= B) << endl;
	
	system("pause");
	return 0;
}
