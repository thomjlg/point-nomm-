#include"point.h"
#include<iostream>;
using namespace std;

int main()
{
	/*point A;
	cout << "Test pour le point A" << endl;
	A.Creer();
	A.Affiche();
	A.Modifier_coord();
	A.Affiche();
	A.Modifier_coord(3);
	A.Affiche();
	A.Modifier_coord(3, 4);
	A.Affiche();*/

	/*cout << "Test pour le cercle" << endl;
	point centre;
	centre.Creer();
	centre.Affiche();

	cercle c;
	float rayon;
	rayon = c.Getrayon();
	c.Modifier(rayon, centre);
	c.Affiche();*/


	/*polygone triangle;
	float peri;
	triangle.Construire_poly(); //sans parametres car la valeur par defaut est 3
	triangle.Affiche();
	peri = triangle.Perimetre();
	cout << "Le perimetre est egal a : " << peri << endl;
	triangle.Libere_memoire();*/

	/*point o;
	point a(1);
	point b(0, 1);
	o.Affiche();
	a.Affiche();
	b.Affiche();
	cout << "Distance entre ";
	a.Affiche();
	cout << " et ";
	b.Affiche();
	cout << " = " << a.dist(b);
	cout << endl;*/

	/*polygone triangle;
	cout << endl;
	polygone carre(4);
	cout << endl;
	polygone ngone(50);
	cout << endl;*/


	/*
	Point_nomme O;
	Point_nomme A(1, 1, 'A');
	Point_nomme B(3, 4);
	cout << "Distance entre : ";
	A.Affiche();
	B.Affiche();
	cout << A.dist(B) << endl;
	cout << B.dist(A) << endl;
	*/
	/*
	int i;
	point * tp[4];
	for (i = 0; i < 4; i++) {
		if (i % 2 == 0) {
			tp[i] = new point(0, i);
		}
		else {
			tp[i] = new Point_nomme(i, 0, 'A' + i);
		}
	}
	for (i = 0; i < 4; i++) {
		tp[i]->Affiche();
	}
	for (i = 0; i < 4; i++) {
		delete tp[i];
	}
	*/

	point B(-2, 9);
	point A(3, 7);
	point res;
	res= A.Addition(B);
	res = A + B;
	res.Affiche();
	return 0;
}