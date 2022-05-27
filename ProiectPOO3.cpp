#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Masini {
	string marca;
	int an_fabricatie;
	int pret;
	string model;
	int cai_putere;

public:
	Masini() {
		marca = "anonim";
		an_fabricatie = 0;
		pret = 0;
		model = "anonim";
		cai_putere = 0;
	}
	Masini(string mar, int an, int pr, string mod, int cai)
	{

		marca = mar;
		an_fabricatie = an;
		pret = pr;
		model = mod;
		cai_putere = cai;

	}


	Masini(const Masini& ob) {
		marca = ob.marca;
		an_fabricatie = ob.an_fabricatie;
		pret = ob.pret;
		model = ob.model;
		cai_putere = ob.cai_putere;
	}

	friend istream& operator >> (istream& in, Masini& ob)
	{
		in >> ob.marca;
		in >> ob.an_fabricatie;
		in >> ob.pret;
		in >> ob.model;
		in >> ob.cai_putere;
		return in;

	}

	friend ostream& operator << (ostream& out, Masini& ob)
	{
		out << ob.marca;
		out << ob.an_fabricatie;
		out << ob.pret;
		out << ob.model;
		out << ob.cai_putere;
		return out;

	}


	virtual void citire_m() {
		cout << "Introduceti anul de fabricatie al masinii : "; cin >> marca; cout << endl;
		cout << "Introduceti marca masinii : "; cin >> an_fabricatie; cout << endl;

		cout << "Introduceti pretul masinii : "; cin >> pret; cout << endl;

		while (pret < 0) {
			try {
				if (pret < 0)
					throw (pret);
			}
			catch (int newval) {
				cout << endl << "Valoarea masinii nu poate fi negativa. Va rugam introduceti o valoare pozitiva : " << endl;
				cin >> newval;
				pret = newval;

			}
		}

		cout << "Introduceti modelul masinii : "; cin >> model; cout << endl;

		cout << "Introduceti caii putere ai  masinii : "; cin >> cai_putere; cout << endl;

		while (cai_putere < 0) {
			try {
				if (cai_putere < 0)
					throw (pret);
			}
			catch (int newval) {
				cout << endl << "Valoarea cailor putere nu poate fi negativa. Va rugam introduceti o valoare pozitiva : " << endl;
				cin >> newval;
				cai_putere = newval;

			}
		}


	}


	virtual void afisare_m() {
		cout << "Anul de fabricatie al masinii : "; cout << marca; cout << endl;
		cout << "Marca masinii : "; cout << an_fabricatie; cout << endl;
		cout << "Pretul masinii : "; cout << pret; cout << endl;
		cout << "Modelul masinii : "; cout << model; cout << endl;
		cout << "Caii putere ai  masinii : "; cout << cai_putere; cout << endl;

	}

	string get_marca() {
		return marca;
	}

	int get_an_fabricatie()
	{
		return an_fabricatie;
	}

	int get_pret()
	{
		return pret;
	}

	string get_model()
	{
		return model;
	}
	int get_cai_putere() {
		return cai_putere;
	}

	void set_marca(int marc)
	{
		marca = marc;
	}
	void set_an_fabricatie(int an_fabri)
	{
		an_fabricatie = an_fabri;
	}
	void set_pret(int pr)
	{
		pret = pr;
	}
	void set_model(string mod)
	{
		model = mod;
	}
	void set_cai_putere(int cai_p)
	{
		cai_putere = cai_p;
	}

};

int main() {
	Masini m, m1;
	cin >> m;
	cout << m;

	m1.citire_m();
	m1.afisare_m();
}