/**
    Tema de laborator nr.2:
        Cerinte comune tuturor temelor:
            1. toate clase vor conține obligatoriu constructori de inițializare, parametrizati și de copiere,
                destructor, iar operatorii >>, <<, = să fie supraincarcati
            2. ilustrarea conceptelor de moștenire și functii virtuale (pure – unde se considera mai natural)
            3. citirea informațiilor complete a n obiecte, memorarea și afisarea acestora
        Cerinte specifice temei 18:
            Se dau urmatoarele clase:
                - Clasa Persoana(id, nume)
                - Clasa Abonat:Persoana(nr_telefon)
                - Clasa Abonat_Skype: Abonat (id_skype)
                - Clasa Abonat_Skype_Romania (adresa_mail) : Abonat_Skype
                - Clasa Abonat_Skype_Extern(tara) : Abonat_Skype
            Sa se construiasca clasa Agenda ce contina o lista de abonati si sa se supraincarce operatorul [ ]
                (indexare)care returneaza abonatul cu numele precizat .
            Clasele derivate trebuie sa contina constructori parametrizati prin care sa se evidentieze
                transmiterea parametrilor catre constructorul din clasa de baza si destructori

    * datele au fost generate cu ajutorul: mockaroo.com
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Persoana
{
    unsigned int id;
    string nume;
public:
    Persoana (int i = 0, string n = "") {id = i; nume = n;}
    Persoana (const Persoana &other) {if (this != &other) {id = other.id; nume = other.nume;}}
    /// ~Persoana () {}
    friend istream& operator>> (istream &in, Persoana &p) {return (in >> p.id >> p.nume);}
    friend ostream& operator<< (ostream &out, Persoana &p) {return (out << "\nid - " << p.id << ", name - " <<  p.nume);}
    Persoana& operator= (const Persoana &other) {if (this != &other) {id = other.id; nume = other.nume;} return *this;}
    string getNume() {return nume;}
};

class Abonat: public Persoana
{
    unsigned int nr_telefon;
public:
    Abonat (int i = 0, string n = "", int nr = 0) : Persoana (i, n) {nr_telefon = nr;}
    Abonat (const Abonat &other) : Persoana (other) {if (this != &other) {nr_telefon = other.nr_telefon;}}
    /// ~Abonat () : Persoana () {}
    friend istream& operator>> (istream &in, Abonat &a) {Persoana &p = a; in >> p; return (in >> a.nr_telefon);}
    friend ostream& operator<< (ostream &out, Abonat &a) {Persoana &p = a; out << p; return (out << ", numar de telefon - " <<  a.nr_telefon);}
    Abonat& operator= (const Abonat &other) {if (this != &other) {Persoana &p = *this; p = other; nr_telefon = other.nr_telefon;} return *this;}
};

class Abonat_Skype: public Abonat
{
    unsigned int id_skype;
public:
    Abonat_Skype (int i = 0, string n = "", int nr = 0, int is = 0) : Abonat (i, n, nr) {id_skype = is;}
    Abonat_Skype (const Abonat_Skype &other) : Abonat (other) {if (this != &other) {id_skype = other.id_skype;}}
    /// ~Abonat_Skype () : Abonat () {}
    friend istream& operator>> (istream &in, Abonat_Skype &a) {Abonat &p = a; return (in >> p >> a.id_skype);}
    friend ostream& operator<< (ostream &out, Abonat_Skype &a) {Abonat &p = a; return (out << p << ", id skype - " <<  a.id_skype);}
    Abonat_Skype& operator= (const Abonat_Skype &other) {if (this != &other) {Abonat &p = *this; p = other; id_skype = other.id_skype;} return *this;}
};

class Abonat_Skype_Romania: public Abonat_Skype
{
    string adresa_mail;
public:
    Abonat_Skype_Romania (int i = 0, string n = "", int nr = 0, int is = 0, string a = "") : Abonat_Skype (i, n, nr, is) {adresa_mail = a;}
    Abonat_Skype_Romania (const Abonat_Skype_Romania &other) : Abonat_Skype (other) {if (this != &other) {adresa_mail = other.adresa_mail;}}
    /// ~Abonat_Skype_Romania () : Abonat_Skype () {}
    friend istream& operator>> (istream &in, Abonat_Skype_Romania &a) {Abonat_Skype &p = a; return (in >> p >> a.adresa_mail);}
    friend ostream& operator<< (ostream &out, Abonat_Skype_Romania &a) {Abonat_Skype &p = a; return (out << p << ", adresa de mail - " <<  a.adresa_mail);}
    Abonat_Skype_Romania& operator= (const Abonat_Skype_Romania &other) {if (this != &other) {Abonat_Skype &p = *this; p = other; adresa_mail = other.adresa_mail;} return *this;}
    string getInfo () {return adresa_mail;}
};

class Abonat_Skype_Extern: public Abonat_Skype
{
    string tara;
public:
    Abonat_Skype_Extern (int i = 0, string n = "", int nr = 0, int is = 0, string t = "") : Abonat_Skype (i, n, nr, is) {tara = t;}
    Abonat_Skype_Extern (const Abonat_Skype_Extern &other) : Abonat_Skype (other) {if (this != &other) {tara = other.tara;}}
    /// ~Abonat_Skype_Extern () : Abonat_Skype () {}
    friend istream& operator>> (istream &in, Abonat_Skype_Extern &a) {Abonat_Skype &p = a; return (in >> p >> a.tara);}
    friend ostream& operator<< (ostream &out, Abonat_Skype_Extern &a) {Abonat_Skype &p = a; return (out << p << ", tara - " <<  a.tara);}
    Abonat_Skype_Extern& operator= (const Abonat_Skype_Extern &other) {if (this != &other) {Abonat_Skype &p = *this; p = other; tara = other.tara;} return *this;}
    string getInfo () {return tara;}
};

class Abonat_Skype_: public Abonat_Skype /// retine un Abonat_Skype_Romania sau un Abonat_Skype_Extern
{
    string key, info;
public:
    Abonat_Skype_  (int i = 0, string n = "", int nr = 0, int is = 0, string k = "", string inf = "") : Abonat_Skype (i, n, nr, is) {key = k; info = inf;}
    Abonat_Skype_ (const Abonat_Skype_ &other) : Abonat_Skype (other) {if (this != &other) {key = other.key; info = other.info;}}
    Abonat_Skype_ (Abonat_Skype_Romania &other) : Abonat_Skype (other) {key = "adresa de mail"; info = other.getInfo();}
    Abonat_Skype_ (Abonat_Skype_Extern &other) : Abonat_Skype (other) {key = "tara"; info = other.getInfo();}
    /// ~Abonat_Skype_ () : Abonat_Skype () {}
    friend istream& operator>> (istream &in, Abonat_Skype_ &a) {Abonat_Skype &p = a; in >> p; return (in >> a.key >> a.info);}
    friend ostream& operator<< (ostream &out, Abonat_Skype_ &a) {Abonat_Skype &p = a; out << p; return (out << ", " << a.key <<" - " <<  a.info);}
    Abonat_Skype_& operator= (const Abonat_Skype_ &other) {if (this != &other) {Abonat_Skype &p = *this; p = other; key = other.key; info = other.info;} return *this;}
    Abonat_Skype_& operator= (Abonat_Skype_Romania &other) {Abonat_Skype &p = *this; p = other; key = "adresa de mail"; info = other.getInfo(); return *this;}
    Abonat_Skype_& operator= (Abonat_Skype_Extern &other) {Abonat_Skype &p = *this; p = other; key = "tara"; info = other.getInfo(); return *this;}
};

class Agenda
{
    Abonat_Skype_ info;
    Agenda *next;
public:
    Agenda (Abonat_Skype_ &i, Agenda *n = NULL) {info = i; next = n;}
    Agenda (Abonat_Skype_Romania &i, Agenda *n = NULL) {info = i; next = n;}
    Agenda (Abonat_Skype_Extern &i, Agenda *n = NULL) {info = i; next = n;}
    Agenda (Agenda *other);
    ~Agenda () {if (this) {delete this->next;}}
    Agenda& operator= (Agenda *other);
    friend istream& operator>> (istream &in, Agenda &a) {return (in >> a.info);}
    friend istream& operator>> (istream &in, Agenda* &a);
    friend ostream& operator<< (ostream &out, Agenda &a) {return (out << a.info);}
    friend ostream& operator<< (ostream &out, Agenda* &a) {return (a == NULL) ? out : (out << *a << a->next);}
    Agenda* operator[] (string index) {return (this == NULL || this->info.getNume() == index) ? this : (*this->next)[index];}
    Abonat_Skype_& getInfo () {return info;}
};

Agenda:: Agenda (Agenda *other) {
    if (other != NULL) {
        this->info = other->info;
        this->next = (other->next == NULL) ? NULL : new Agenda (other->next);
    }
    else {
        this->next = NULL;
        Abonat_Skype_ a;
        info = a;
    }
}

Agenda& Agenda:: operator= (Agenda *other) {
    if (this == NULL) {return *this;}
    else {delete this->next;}
    if (other != NULL) {
        this->info = other->info;
        this->next = (other->next == NULL) ? NULL : new Agenda (other->next);
    }
    else {
        Abonat_Skype_ a;
        this->info = a;
        this->next = NULL;
    }
    return *this;
}

istream& operator>> (istream &in, Agenda* &a) {
    delete a;
    a = NULL;
    int nr, ne;
    in >> nr >> ne;
    Abonat_Skype_Romania r;
    Abonat_Skype_Extern e;
    while (nr-- > 0) {
        in >> r;
        a = new Agenda (r, a);
    }
    while (ne-- > 0) {
        in >> e;
        a = new Agenda (e, a);
    }
    return in;
}

int main()
{
    ifstream in ("date.in");
    if (in == NULL) {cout << "fisierul de citire \"date.in\" nu a fost gasit"; return 0;}

    Agenda *a = NULL, *p;
    in >> a;
    in.close();
    cout << a << "\n";

    p = (*a)["k"];
    if (p != NULL) cout << *p;
    else {cout << "\nNot Found";}
    p = (*a)["c"];
    if (p != NULL) cout << *p;
    else {cout << "\nNot Found";}
    delete a;
    return 0;
}
