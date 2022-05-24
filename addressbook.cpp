#include "addressbook.h"

AddressList::AddressList() {}

AddressList::AddressList(const Person& r, const vector<Person>& info) {
    owner = r;
    for (const auto& i : info) {
        information.push_back(i);
    }
}

AddressList::AddressList(const AddressList& r) {
    owner = r.owner;
    for (const auto& i : r.information) {
        information.push_back(i);
    }
}

void AddressList::Add(const Person& p) {
    // Добавить информацию о друге в адресную книгу
    // Сначала подтвердите, что он не существует: id + tele
    for (const auto& it : information) {
        if (p.m_id == it.m_id) {
            cout << "Идентификатор уже существует, добавление не удалось!\n";
            return;
        }
        else if (p.m_tele == it.m_tele) {
            cout << "Телефон уже существует, добавление не удалось!\n";
            return;
        }
    }
    information.push_back(p);
}

void AddressList::Delete() {
    string name;
    cout << "Имя: ";
    cin >> name;
    cout << "Найденная информация выглядит следующим образом: ";
    auto it = information.begin();
    vector <int> info; // Индекс хранилища
    for (int i(0); it != information.end(); ++it,++i) {
        if (it->m_name == name) info.push_back(i);
    }
    if (info.empty()) {
        cout << "Такого имени нет!\n";
        return;
    }
    for (const auto& i : info) {
        cout << i << ":\t" << information[i].m_id << '\t' << information[i].m_name
             << '\t' << information[i].m_tele << endl;
    }

    int ind;
    cout << "Введите нижний индекс (первый столбец) для удаления информации:";
    cin>>ind;
    for (const auto& i : info) {
        if (i == ind) {
            information.erase(information.begin() + i);
            return;
        }
    }
    cout << "Неверная информация ввода, удаление не удалось!\n";
}

void AddressList::Modify() {
    long id;
    cout << "ID：";
    cin >> id;

    auto it = information.begin();
    for (; it != information.end(); ++it) {
        if (it->m_id == id) {
            cout << "Найденная информация выглядит следующим образом: \n";
            cout << it->m_id << '\t' << it->m_name << '\t' << it->m_surname << '\t' << it->m_tele << endl;
            break;
        }
    }
    if (it == information.end()) {
        cout << "Такого ID нет!\n";
    } else {

        cout << "Изменить информацию: \n";

        string surname;
        string tele;
        int cho;
        cout << "1.Фамилия \n"
             << "2.Номер телефона\n"
             << "Ваш выбор: ";
        cin >> cho;
        switch (cho) {
            case 1:
                cout << "Новая фамилия:";
                cin >> surname;
                break;
            case 2:
                cout << "Новый номер:";
                cin >> surname;
                break;
        }

        char c;
        cout << "Подтвердить? <y / n>";
        cin >> c;
        if (c == 'y' || c == 'Y') {
            it->m_tele = tele;
        } else {
            cout << "Изменения не были сохранены \n";
        }
    }
}
void AddressList::Search(int cho) {
    int id;
    string name;
    string surname;
    string tele;
    auto it = information.begin();
    switch (cho) {
        case 1:
            cout << "Id:";
            cin >> id;
            cout << "Информация о поиске выглядит следующим образом: \n";
            for (it = information.begin(); it != information.end(); ++it) {
                if (it->m_id == id) {
                    cout << it->m_id << '\t' << it->m_name << '\t' << it->m_surname << '\t' << it->m_tele << endl;
                    break;
                }
            }
            break;
        case 2:
            cout << "Имя: ";
            cin >> name;
            cout << "Информация о поиске выглядит следующим образом: \n";
            for (it = information.begin(); it != information.end(); ++it) {
                if (it->m_name == name)
                    cout << it->m_id << '\t' << it->m_name << '\t' << it->m_surname << '\t' << it->m_tele << endl;
            }
            break;
        case 3:
            cout << "Фамилия: ";
            cin >> surname;
            cout << "Информация о поиске выглядит следующим образом: \n";
            for (it = information.begin(); it != information.end(); ++it) {
                if (it->m_surname == surname)
                    cout << it->m_id << '\t' << it->m_name << '\t' << it->m_surname << '\t' << it->m_tele << endl;
            }
            break;
        case 4:
            cout << "Номер телефона: ";
            cin >> tele;
            cout << "Информация о поиске выглядит следующим образом: \n";
            for (it = information.begin(); it != information.end(); ++it) {
                if (it->m_tele == tele) {
                    cout << it->m_id << '\t' << it->m_name << '\t' << it->m_surname << '\t' << it->m_tele << endl;
                    break;
                }
            }
            break;
        default:break;
    }
}
void AddressList::Print()const {
    cout << "Владелец: " << owner.m_name << " " << owner.m_surname << endl
         << "Номер телефона: " << owner.m_tele << endl;
    int n(information.size());
    cout << "Количество контактов: " << n << endl;
    for (int i(0); i < n; ++i) {
        cout << information[i].m_id << '\t' << information[i].m_surname << '\t' << information[i].m_name << endl;
    }
    while (1) {
        cout << endl << "Введите id: -1, чтобы прекратить просмотр \n";
        int id;
        cin >> id;
        if (id == -1) break;
        bool b(false);
        for (const auto& it : information) {
            if (id == it.m_id) {
                b = true;
                cout << it.m_id << '\t' << it.m_surname << '\t' << it.m_name << '\t' << it.m_tele << endl;
                break;
            }
        }
        if (!b) {
            cout << "Такого ID нет!" << endl;
        }
    }
}

