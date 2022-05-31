#ifndef OOPKURS_ADDRESSBOOK_H
#define OOPKURS_ADDRESSBOOK_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Person {
    int m_id;
    string m_name;
    string m_surname;
    string m_tele;

    Person& operator = (const Person& r) {
        if (this == &r) return *this;
        m_id = r.m_id;
        m_name = r.m_name;
        m_surname = r.m_surname;
        m_tele = r.m_tele;
        return *this;
    }
};

class AddressList {
private:
    Person owner;
    vector <Person> information;
public:
    AddressList();
    AddressList(const Person&, const vector<Person>& info = {});
    AddressList(const AddressList&);

    void Add (const Person &);
    void Delete ();
    void Modify ();
    void Search (int);
    void Print()const;
    void Save();
};


#endif //OOPKURS_ADDRESSBOOK_H
