#include "addressbook.h"

int main() {
    setlocale(LC_ALL, "Russian");
    Person p;
    {
        p.m_id = 0;
        p.m_name = "Дарья";
        p.m_surname = "Квашнина";
        p.m_tele = "9371828003";
    }
    int I = 1;
    AddressList addr(p);
    {
        cout << "0.Выход\n"
             << "1.Добавить\n"
             << "2.Удалить\n"
             << "3.Изменить\n"
             << "4.Поиск\n"
             << "5.Просмотр\n"
             << endl;
    }
    int cho2;
    bool b(true);
    while (b) {
        int cho;
        int id;
        string name;
        string surname;
        string tele;

        cout << "Ваш выбор: ";
        cin >> cho;
        switch (cho) {
            case 0:
                b = false;
                break;
            case 1:
                cout << "Добавить информацию: " << "Фамилия: ";
                cin >> surname;
                cout << "Имя: ";
                cin >> name;
                cout << "Номер телефона: ";
                cin >> tele;
                id = I++;
                {
                    p.m_id = id;
                    p.m_name = name;
                    p.m_surname = surname;
                    p.m_tele = tele;
                }
                addr.Add(p);
                break;
            case 2:
                cout << "Удалить информацию: ";
                addr.Delete();
                break;
            case 3:
                cout << "Изменить информацию: ";
                addr.Modify();
                break;
            case 4:
                cout << "Поиск информации "
                     << "1.ID\n"
                     << "2.Имя\n"
                     << "3.Фамилия\n"
                     << "4.Номер телефона\n";
                cout << "Ваш выбор: ";
                cin >> cho2;
                addr.Search(cho2);
                break;
            case 5:
                cout << "Просмотр информации\n";
                addr.Print();
                break;
            default:break;
        }
        cout << endl;
    }
    return 0;
}


