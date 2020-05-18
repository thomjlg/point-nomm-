#include"point.h"
#include<iostream>
#include<math.h>
using namespace std;


/*void point::Creer(void) 
{
	cout << "Saisir les coordonnees de votre point" << endl;
	cin >> x >> y;
}*/

point::point(float a, float b)
{
	x = a;
	y = b;
	
	//rajout exceptionnel de cout
	cout << "On a construit le point ";
	Affiche();
}

void point::Modifier_coord(float a, float b) 
{
	x = a;
	y = b;
}

void point::Affiche(void) const {
	cout << "(" << x << ", " << y << ")" << endl;
}

void point::Affiche(ostream& flux) const {
	flux << "(" << x << ", " << y << ")" << endl;
}

/*float point::dist(point a, point b)
{
	float resultat;
	float pointax, pointay, pointbx, pointby;
	pointax = a.Getx();
	pointay = a.Gety();
	pointbx = b.Getx();
	pointby = b.Gety();

	resultat = sqrt(((pointax - pointbx)*(pointax - pointbx)) + ((pointay - pointby)*(pointay - pointby)));
	return resultat;
}*/

float point::dist(const point &a)
{
	float resultat;
	resultat = sqrt((x - a.Getx())*(x - a.Getx()) + (y - a.Gety())*(y - a.Gety()));
	return resultat;
}

point point::Addition(const point& A) const {
	point res;
	res.x = A.x + x;
	res.y = A.y + y;
	return res;
}

point::~point(void)
{
	//a priori rien a faire
	//rajout exceptionnel cout
	cout << "destruction du point";
	Affiche();
	//on detruit dans l'ordre inverse de l'ordre de construction car on a une pile
}
												//  liste d'initialisation //
Point_nomme::Point_nomme(float x, float y, char n) :point(x, y), nom(n)
{
	nom = n;
}
//Premiere chose qu'on fait quand on veut construire un Poin-nomme est d'appeler le constructueur de la 
// classe point (Un Point_nomme est un point).

void Point_nomme::Affiche(void)
{
	cout << nom;
	point::Affiche();
}

void Point_nomme::Modifier_coord(float x, float y, char n)
{
	point::Modifier_coord(x, y);
	nom = n;
}

Point_nomme::~Point_nomme(void)
{
	cout << "Destruction du Point_nomme ";
	Affiche();
}










void cercle::Modifier(float x, point a)
{
	//float i, j;
	rayon = x;
	//cout << "2- Veuillez saisir les nouvelles coordonnees du centre" << endl;
	//cin >> i >> j;
	centre.Modifier_coord(a.Getx(), a.Gety());
}

void cercle::Affiche(void)
{
	aire = Aire();
	cout << "Le rayon du cercle est : " << rayon << " et son centre est";
	centre.Affiche();
	cout << " et son aire est de : " << aire << endl;
}

float cercle::Getrayon(void)
{
	cout << "Saisir le rayon" << endl;
	cin>>rayon;
	return rayon;
}










polygone::polygone(unsigned int n)
{
	nb = n;
	tab_pts = new point[nb];
	cout << "polygone de taille " << nb << " construit" << endl;

}

/*void polygone::Construire_poly(unsigned int n)
{
	nb = n;
	tab_pts = new point[nb];
	for (unsigned int i = 0; i < n; i++)
	{
		tab_pts[i].Creer();
		//En notation pointeur on aurait noté : 
		//(*(tab_pts+i)).Creer();
		// OU (tab_pts+i)->Creer();
	}
}*/

/*void polygone::Libere_memoire(void)
{
	delete[]tab_pts;
}*/

void polygone::Affiche(unsigned int n)
{
	n = nb;
	unsigned int i = 0;
	while(i<nb)
	{
		tab_pts[i].Affiche();
		i++;
	}
}

float polygone::Perimetre(unsigned int n)
{
	nb = n;
	unsigned int i = 0;
	float res = 0;
	while (i < nb-1)
	{
		//res = res + (tab_pts[i].dist(tab_pts[i], tab_pts[i + 1]));
		res = res + tab_pts[i].dist(tab_pts[i + 1]);
		i++;
	}
	//res = res + tab_pts[i].dist(tab_pts[nb - 1], tab_pts[0]);
	res = res + tab_pts[i - 1].dist(tab_pts[0]);
	return res;
}

polygone::~polygone(void)
{
	delete[]tab_pts;
	cout << endl;
	cout << "polygone de taille " << nb << " detruit" << endl;
}






////// declarer surcharge operateur + [en dehors de la classe] /////////////////
point operator+(const point& A, const point& B) {
	point res;
	res = A.Addition(B);
	return res;
}


////// surcharge operateur << //////////////////////////////////////////////////
ostream& operator<<(ostream & flux, const point&A) {
	A.Affiche(flux); //mais normalement Affiche() ne prend rien ?!
	return flux;
}