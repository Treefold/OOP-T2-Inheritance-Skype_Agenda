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
    Persoana (int i = 0, string n = "");
    Persoana (const Persoana &other);
    ~Persoana ();
    friend istream& operator>> (istream &in, Persoana &p);
    friend ostream& operator<< (ostream &out, Persoana &p);
    Persoana& operator= (const Persoana &other);
    string getNume();
};
Persoana:: Persoana (int i /*= 0*/, string n /*= ""*/)
{
    id = i;
    nume = n;
}
Persoana:: Persoana (const Persoana &other)
{
    if (this != &other)
    {
        id = other.id;
        nume = other.nume;
    }
}
Persoana:: ~Persoana ()
{

}
istream& operator>> (istream &in, Persoana &p)
{
    return (in >> p.id >> p.nume);
}
ostream& operator<< (ostream &out, Persoana &p)
{
    return (out << "\nid - " << p.id << ", name - " <<  p.nume);
}
Persoana& Persoana:: operator= (const Persoana &other)
{
    if (this != &other)
    {
        id = other.id;
        nume = other.nume;
    }
    return *this;
}
string Persoana:: getNume()
{
    return nume;
}

class Abonat: public Persoana
{
    unsigned int nr_telefon;
public:
    Abonat (int i /*= 0*/, string n /*= ""*/, int nr /*= 0*/);// : Persoana (i, n);
    Abonat (const Abonat &other);// : Persoana (other);
    ~Abonat ();
    friend istream& operator>> (istream &in, Abonat &a);
    friend ostream& operator<< (ostream &out, Abonat &a);
    Abonat& operator= (const Abonat &other);
};
Abonat:: Abonat (int i = 0, string n = "", int nr = 0) : Persoana (i, n)
{
    nr_telefon = nr;
}
Abonat:: Abonat (const Abonat &other) : Persoana (other)
{
    if (this != &other)
    {
        nr_telefon = other.nr_telefon;
    }
}
Abonat:: ~Abonat ()
{

}
istream& operator>> (istream &in, Abonat &a)
{
    Persoana &p = a;
    in >> p;
    return (in >> a.nr_telefon);
}
ostream& operator<< (ostream &out, Abonat &a)
{
    Persoana &p = a;
    out << p;
    return (out << ", numar de telefon - " <<  a.nr_telefon);
}
Abonat& Abonat:: operator= (const Abonat &other)
{
    if (this != &other)
    {
        Persoana &p = *this;
        p = other;
        nr_telefon = other.nr_telefon;
    }
    return *this;
}

class Abonat_Skype: public Abonat
{
    unsigned int id_skype;
public:
    Abonat_Skype (int i /*= 0*/, string n /*= ""*/, int nr /*= 0*/, int is /*= 0*/);// : Abonat (i, n, nr);
    Abonat_Skype (const Abonat_Skype &other);// : Abonat (other);
    ~Abonat_Skype ();
    friend istream& operator>> (istream &in, Abonat_Skype &a);
    friend ostream& operator<< (ostream &out, Abonat_Skype &a);
    Abonat_Skype& operator= (const Abonat_Skype &other);
};
Abonat_Skype:: Abonat_Skype (int i = 0, string n = "", int nr = 0, int is = 0) : Abonat (i, n, nr)
{
    id_skype = is;
}
Abonat_Skype:: Abonat_Skype (const Abonat_Skype &other) : Abonat (other)
{
    if (this != &other)
    {
        id_skype = other.id_skype;
    }
}
Abonat_Skype:: ~Abonat_Skype ()
{

}
istream& operator>> (istream &in, Abonat_Skype &a)
{
    Abonat &p = a;
    return (in >> p >> a.id_skype);
}
ostream& operator<< (ostream &out, Abonat_Skype &a)
{
    Abonat &p = a;
    return (out << p << ", id skype - " <<  a.id_skype);
}
Abonat_Skype& Abonat_Skype:: operator= (const Abonat_Skype &other)
{
    if (this != &other)
    {
        Abonat &p = *this;
        p = other;
        id_skype = other.id_skype;
    }
    return *this;
}

class Abonat_Skype_Romania: public Abonat_Skype
{
    string adresa_mail;
public:
    Abonat_Skype_Romania (int i /*= 0*/, string n /*= ""*/, int nr /*= 0*/, int is /*= 0*/, string a /*= ""*/);// : Abonat_Skype (i, n, nr, is);
    Abonat_Skype_Romania (const Abonat_Skype_Romania &other);// : Abonat_Skype (other);
    ~Abonat_Skype_Romania ();
    friend istream& operator>> (istream &in, Abonat_Skype_Romania &a);
    friend ostream& operator<< (ostream &out, Abonat_Skype_Romania &a);
    Abonat_Skype_Romania& operator= (const Abonat_Skype_Romania &other);
    string getInfo ();
};
Abonat_Skype_Romania:: Abonat_Skype_Romania (int i = 0, string n = "", int nr = 0, int is = 0, string a = "") : Abonat_Skype (i, n, nr, is)
{
    adresa_mail = a;
}
Abonat_Skype_Romania:: Abonat_Skype_Romania (const Abonat_Skype_Romania &other) : Abonat_Skype (other)
{
    if (this != &other)
    {
        adresa_mail = other.adresa_mail;
    }
}
Abonat_Skype_Romania:: ~Abonat_Skype_Romania ()
{

}
istream& operator>> (istream &in, Abonat_Skype_Romania &a)
{
    Abonat_Skype &p = a;
    return (in >> p >> a.adresa_mail);
}
ostream& operator<< (ostream &out, Abonat_Skype_Romania &a)
{
    Abonat_Skype &p = a;
    return (out << p << ", adresa de mail - " <<  a.adresa_mail);
}
Abonat_Skype_Romania& Abonat_Skype_Romania:: operator= (const Abonat_Skype_Romania &other)
{
    if (this != &other)
    {
        Abonat_Skype &p = *this;
        p = other;
        adresa_mail = other.adresa_mail;
    }
    return *this;
}
string Abonat_Skype_Romania:: getInfo ()
{
    return adresa_mail;
}

class Abonat_Skype_Extern: public Abonat_Skype
{
    string tara;
public:
    Abonat_Skype_Extern (int i /*= 0*/, string n /*= ""*/, int nr /*= 0*/, int is /*= 0*/, string t /*= ""*/);// : Abonat_Skype (i, n, nr, is);
    Abonat_Skype_Extern (const Abonat_Skype_Extern &other);// : Abonat_Skype (other);
    ~Abonat_Skype_Extern ();
    friend istream& operator>> (istream &in, Abonat_Skype_Extern &a);
    friend ostream& operator<< (ostream &out, Abonat_Skype_Extern &a);
    Abonat_Skype_Extern& operator= (const Abonat_Skype_Extern &other);
    string getInfo ();
};
Abonat_Skype_Extern:: Abonat_Skype_Extern (int i = 0, string n = "", int nr = 0, int is = 0, string t = "") : Abonat_Skype (i, n, nr, is)
{
    tara = t;
}
Abonat_Skype_Extern:: Abonat_Skype_Extern (const Abonat_Skype_Extern &other) : Abonat_Skype (other)
{
    if (this != &other)
    {
        tara = other.tara;
    }
}
Abonat_Skype_Extern:: ~Abonat_Skype_Extern ()
{

}
istream& operator>> (istream &in, Abonat_Skype_Extern &a)
{
    Abonat_Skype &p = a;
    return (in >> p >> a.tara);
}
ostream& operator<< (ostream &out, Abonat_Skype_Extern &a)
{
    Abonat_Skype &p = a;
    return (out << p << ", tara - " <<  a.tara);
}
Abonat_Skype_Extern& Abonat_Skype_Extern:: operator= (const Abonat_Skype_Extern &other)
{
    if (this != &other)
    {
        Abonat_Skype &p = *this;
        p = other;
        tara = other.tara;
    }
    return *this;
}
string Abonat_Skype_Extern:: getInfo ()
{
    return tara;
}

class Abonat_Skype_: public Abonat_Skype /// Abonat_Skype_Romania / Abonat_Skype_Extern
{
    string key, info;
public:
  /// methods implementation will be released after getting my mark
};

class Agenda
{
    Abonat_Skype_ info;
    Agenda *next;
public:
    /// methods implementation will be released after getting my mark
}; 

int main()
{
    ifstream in ("date.in");
    if (in == NULL)
    {
        cout << "fisierul de citire \"date.in\" nu a fost gasit";
        return 0;
    }

    Agenda *a = NULL, *p;
    in >> a;
    in.close();
    cout << a << "\n";

    p = (*a)["k"];
    if (p != NULL)
        cout << *p;
    else
    {
        cout << "\nNot Found";
    }
    cout << p;
    p = (*a)["h"];
    if (p != NULL)
        cout << *p;
    else
    {
        cout << "\nNot Found";
    }
    cout << p;
    delete a;
    return 0;
}
