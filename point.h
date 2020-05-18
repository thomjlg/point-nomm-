class point {
protected:
	float x;
	float y;
public:
	point(float = 0, float = 0); //CONSTRUCTEUR le compliateur en cree un si il n'y en a pas
	//void Creer(void);
	void Modifier_coord(float a = 0, float b = 0); //parametre par defaut
	// 3 appels possibles sur un point A
	// A.Modifier_coord();     a=0 et b=0
	// A.Modifier_coord(3);    a=3 et b=0
	// A.Modifier_coord(3,4);  a=3 et b=4
	// Mais pas A.Modifier_coord( ,7); INTERDIT
	virtual void Affiche(void) const;
	void Affiche(ostream& flux) const;
	float Getx(void) const { return x; };
	float Gety(void) const { return y; };
	//float dist(point, point);
	float dist(const point &);
	point Addition(const point&) const;
	virtual ~point(void); //DESTRUCTEUR
};



class Point_nomme :public point
{
private:
	char nom;
public:
	Point_nomme(float x = 0, float y = 0, char n = 'O');
	virtual ~Point_nomme(void);
	virtual void Affiche(void);
	void Modifier_coord(float x, float y, char n);
	char Getnom(void)const { return nom; };

};



class cercle {
private:
	point centre;
	float rayon;
	float aire;
public:
	void Modifier(float x, point A);
	float Aire(void) { return 3.14159265*rayon*rayon; };
	//Une methode definie lors de sa declaraton est consideree comme une methode inline
	void Affiche(void);
	float Getrayon(void);
};



class polygone {
private:
	unsigned int nb;
	point*tab_pts;
public:
	polygone(unsigned int = 3);
	//void Construire_poly(unsigned int n = 3);
	//Si on ne met rien, il prend par defaut n=3
	float Perimetre(unsigned int n = 3);
	//void Libere_memoire(void);
	void Affiche(unsigned int n = 3);
	~polygone(void);
};


////// declarer surcharge operateur + [en dehors de la classe] /////////////////
point operator+(const point&, const point&);		//operator+(A, B) <=> A + B

////// surcharge operateur << //////////////////////////////////////////////////
ostream& operator<<(ostream & flux, const point&);
