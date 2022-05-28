#include <iostream>

#include <vector>

#include <string>

#include <cstring>

#include <istream>

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
    Masini(string mar, int an, int pr, string mod, int cai) {

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

    friend istream& operator >> (istream& in, Masini& ob) {
        cout << "Marca : "; in >> ob.marca;
        cout << endl;

        cout << "An Fabricatie : "; in >> ob.an_fabricatie;
        cout << endl;
        while (ob.an_fabricatie < 0) {
            try {
                if (ob.an_fabricatie < 0)
                    throw (ob.an_fabricatie);
            }
            catch (int newval) {
                cout << endl << "Anul de fabricatie nu poate fi negativ. Va rugam introduceti o valoare pozitiva : " << endl;
                cin >> newval;
                ob.an_fabricatie = newval;

            }
        }

        cout << "Pret : "; in >> ob.pret;
        cout << endl;
        while (ob.pret < 0) {
            try {
                if (ob.pret < 0)
                    throw (ob.pret);
            }
            catch (int newval) {
                cout << endl << "Valoarea masinii nu poate fi negativa. Va rugam introduceti o valoare pozitiva : " << endl;
                cin >> newval;
                ob.pret = newval;

            }
        }

        cout << "Model : "; in >> ob.model;
        cout << endl;
        cout << "Putere : "; in >> ob.cai_putere;
        cout << endl;
        while (ob.cai_putere < 0) {
            try {
                if (ob.cai_putere < 0)
                    throw (ob.cai_putere);
            }
            catch (int newval) {
                cout << endl << "Valoarea masinii nu poate fi negativa. Va rugam introduceti o valoare pozitiva : " << endl;
                cin >> newval;
                ob.cai_putere = newval;

            }
        }
        return in;

    }

    friend ostream& operator << (ostream& out, Masini& ob) {
        cout << "Marca : ";
        out << ob.marca;
        cout << endl;
        cout << "An Fabricatie : ";
        out << ob.an_fabricatie;
        cout << endl;
        cout << "Pret : ";
        out << ob.pret;
        cout << endl;
        cout << "Model : ";
        out << ob.model;
        cout << endl;
        cout << "Cai Putere : ";
        out << ob.cai_putere;
        cout << endl;
        return out;

    }

    virtual void citire_m() {
        cout << "Introduceti anul de fabricatie al masinii : ";
        cin >> marca;
        cout << endl;
        cout << "Introduceti marca masinii : ";
        cin >> an_fabricatie;
        cout << endl;

        cout << "Introduceti pretul masinii : ";
        cin >> pret;
        cout << endl;

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

        cout << "Introduceti modelul masinii : ";
        cin >> model;
        cout << endl;

        cout << "Introduceti caii putere ai  masinii : ";
        cin >> cai_putere;
        cout << endl;

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
        cout << "Anul de fabricatie al masinii : ";
        cout << marca;
        cout << endl;
        cout << "Marca masinii : ";
        cout << an_fabricatie;
        cout << endl;
        cout << "Pretul masinii : ";
        cout << pret;
        cout << endl;
        cout << "Modelul masinii : ";
        cout << model;
        cout << endl;
        cout << "Caii putere ai  masinii : ";
        cout << cai_putere;
        cout << endl;

    }

    string get_marca() {
        return marca;
    }

    int get_an_fabricatie() {
        return an_fabricatie;
    }

    int get_pret() {
        return pret;
    }

    string get_model() {
        return model;
    }
    int get_cai_putere() {
        return cai_putere;
    }

    void set_marca(int marc) {
        marca = marc;
    }
    void set_an_fabricatie(int an_fabri) {
        an_fabricatie = an_fabri;
    }
    void set_pret(int pr) {
        pret = pr;
    }
    void set_model(string mod) {
        model = mod;
    }
    void set_cai_putere(int cai_p) {
        cai_putere = cai_p;
    }

};

class Masini_Hatch : public Masini {
public: Masini_Hatch() : Masini() {}
      Masini_Hatch(string mar, int an, int pr, string mod, int cai) : Masini(mar, an, pr, mod, cai) {}
      Masini_Hatch(Masini_Hatch& ob) : Masini(ob) {}

      friend istream& operator >> (istream& in, Masini_Hatch& ob) {
          in >> dynamic_cast <Masini&> (ob);
          return in;
      }

      friend ostream& operator << (ostream& out, Masini_Hatch& ob) {
          out << "Masina tip Hatch " << endl;
          out << dynamic_cast <Masini&> (ob);
          return out;
      }
      void citire_m() {
          Masini::citire_m();
      }
      void afisare_m() {
          Masini::afisare_m();
      }

};

class Masini_Cabrio : public Masini {
    string acoperis;
public:

    Masini_Cabrio() : Masini() {
        acoperis = "anonim";
    }
    Masini_Cabrio(string mar, int an, int pr, string mod, int cai, string ac) : Masini(mar, an, pr, mod, cai), acoperis(ac) {}

    Masini_Cabrio(Masini_Cabrio& ob) : Masini(ob) {
        acoperis = ob.acoperis;
    }

    friend istream& operator >> (istream& in, Masini_Cabrio& ob) {
        in >> dynamic_cast <Masini&> (ob);
        cout << "Tipul acoperisului : "; in >> ob.acoperis;
        cout << endl;
        return in;
    }

    friend ostream& operator << (ostream& out, Masini_Cabrio& ob) {
        out << "Masina tip Cabrio " << endl;
        out << dynamic_cast <Masini&> (ob);
        cout << " Tipul acoperisului : ";
        out << ob.acoperis;
        cout << endl;
        return out;
    }
    void citire_m() {
        Masini::citire_m();
        cout << "Tipul acoperisului : ";
        cin >> acoperis;
        cout << endl;
    }
    void afisare_m() {
        Masini::afisare_m();
        cout << "Tipul acoperisului : " << acoperis;
        cout << endl;
    }

};
class Masini_Supersport : public Masini {
public: Masini_Supersport() : Masini() {}
      Masini_Supersport(string mar, int an, int pr, string mod, int cai) : Masini(mar, an, pr, mod, cai) {}
      Masini_Supersport(Masini_Hatch& ob) : Masini(ob) {}

      friend istream& operator >> (istream& in, Masini_Supersport& ob) {
          in >> dynamic_cast <Masini&> (ob);
          return in;
      }

      friend ostream& operator << (ostream& out, Masini_Supersport& ob) {
          out << "Masina tip SuperSport " << endl;
          out << dynamic_cast <Masini&> (ob);
          return out;
      }
      void citire_m() {
          Masini::citire_m();
      }
      void afisare_m() {
          Masini::afisare_m();
      }
};

template < typename T >
class expozitie {
    static int nr_masini;
    static vector < T > v_masini;
public:
    expozitie() {}
    expozitie(T ob) {
        nr_masini++;
    }

    template < typename U >
    friend ostream& operator << (ostream& in, expozitie < U >& ob);
    template < typename U >
    friend istream& operator >> (istream& out, expozitie < U >& ob);

    ~expozitie() {
        v_masini.~vector<T>();
    }
};

template < typename T >
vector < T > expozitie < T > ::v_masini;
template < typename T >
int expozitie < T > ::nr_masini = 0;

//////////////////////citire
template < typename U >
istream& operator >> (istream& in, expozitie < U >& ob) {
    U obiect; in >> obiect;
    return in;
}

//////////////////////afisare
template < typename U >
ostream& operator << (ostream& out, expozitie < U >& ob) {

    int i = 0;
    for (typename vector < U > ::iterator it = expozitie < U > ::v_masini.begin(); it != expozitie < U > ::v_masini.end(); ++it) {
        out << "Masina: " << i << endl;
        out << it << endl;
        i++;

    }
    return out;
}

template < >
class expozitie < Masini_Supersport > {
    static int nr_mas_exp_sp;
    static int nr_mas_vandute;
    static vector < Masini_Supersport* > stoc;
    static vector < Masini_Supersport* > vandute;
    Masini_Supersport mss;

public: expozitie < Masini_Supersport >() {}
      
      

};

void citire_masini(int nr, vector < Masini* >& v, expozitie < Masini_Hatch >& hatch, expozitie < Masini_Cabrio >& cabrio, expozitie < Masini_Supersport >& supersport) {

    int i = 0;
    int ok = 0;
    do {
        int optiune;
        cout << "Ce masina doriti sa adaugati la expozitie? :  ";
        cin >> optiune;
        i++;

        if (optiune == 1) {
            Masini_Cabrio* mcb = new Masini_Cabrio;
            cin >> *mcb;
            v.push_back(mcb);
        }

        if (optiune == 2) {
            Masini_Hatch* mh = new Masini_Hatch;
            cin >> *mh;
            v.push_back(mh);

        }

        if (optiune == 3) {
            Masini_Supersport* mss = new Masini_Supersport;
            cin >> *mss;
            v.push_back(mss);
        }

    } while (i < nr);
}

void afisare_masini(vector < Masini* > v, expozitie < Masini_Hatch > hatch, expozitie < Masini_Cabrio > cabrio, expozitie < Masini_Supersport > supersport) {
    int i = 0;
    for (vector < Masini* > ::iterator it = v.begin(); it != v.end(); it++) {
        cout << "----------------Masina : " << i << " ----------------" << endl;

        if (typeid(**it) == typeid(Masini_Hatch))
            cout << "Masina de tip HATCH" << endl;

        else if (typeid(**it) == typeid(Masini_Supersport))
            cout << "Masina de tip SuperSport" << endl;

        else if (typeid(**it) == typeid(Masini_Cabrio))
            cout << "Masina de tip Cabrio" << endl;

        cout << **it;

        i++;
    }

}

/// <summary>
/// Am implementat design Pattern-ul singleton , prin Clasa menu. Avem aici un constructor privat si unic, deoarece nu am avea vreodata nevoie de mai mult de 1 meniu. 
/// </summary>

class Menu {
    static  Menu* instance;
    string  data;

    // Private constructor so that no objects can be created.
    Menu() {
        data = "null";
    }

public:
    static  Menu* getInstance() {
        if (!instance)
            instance = new  Menu;
        return instance;
    }

    string getData() {
        return this->data;
    }

    void setData(string data) {
        this->data = data;
    }
};

Menu* Menu::instance = 0;

int main() {
    vector < Masini* > v;
    int nr;

    expozitie < Masini_Hatch > ht;
    expozitie < Masini_Cabrio > cb;
    expozitie < Masini_Supersport > ss;

    cout << "Introduceti numarul de masini :  ";
    cin >> nr;
    cout << endl;


    Menu *s = s->getInstance();
    s->setData("Ce masina doriti sa adaugati la expozitie?\n 1.Hatch \n 2.Cabrio \n3.SuperSport");
    cout << s->getData() << endl;
   

    citire_masini(nr, v, ht, cb, ss);

    afisare_masini(v, ht, cb, ss);

    return 0;

}