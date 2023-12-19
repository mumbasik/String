// String.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
class Contacts {
    char* fi;
    int workphone;
    int homephone;
    int phone;
    char* info;

public:
    Contacts() : fi(nullptr), workphone(0), homephone(0), phone(0), info(nullptr) {

    }
       
   
    
    Contacts(const char* name, int work, int home, int phone, const char* inf) {
        fi = new char[strlen(name) + 1];
        strcpy_s(fi, strlen(name) + 1, name);
        workphone = work;
        homephone = home;
        this->phone = phone;
        info = new char[strlen(inf) + 1];
        strcpy_s(info, strlen(inf) + 1, inf);
    }
    void Check() {
        if (fi != nullptr) {
            delete[] fi;
        }
    }
    void Cheak() {
        if (info != nullptr) {
            delete[] info;
        }
    }
    void Cout() {
        if (fi == nullptr && info == nullptr) {
            cout << "Nothing" << endl;
            return;
        }
        cout << "Fio: " << fi << "\n";
        cout << "Workphone: " << workphone << "\n";
        cout << "Homephone: " << homephone << "\n";
        cout << "Contact phone: " << phone << "\n";
        cout << "Information: " << info << "\n";
    }

    ~Contacts() {

    }

};

void Print(Contacts* fio) {
    for (int i = 0; i < 3; i++) {
        fio[i].Cout();
    }
}
void addStudents(Contacts ar[], int size) {
    Contacts* arr = new Contacts[size + 1];

    for (int i = 0; i < size; i++) {
        arr[i] = ar[i];
    }
    arr[size] = Contacts("Ilushenko, Nikita, Andreevich", 453535, 654654654, 456465, "Best student");
    for (int i = 0; i < size + 1; i++) {
        arr[i].Cout();
    }

    delete[] arr;
}
void deleteStudents(Contacts ar[], int size, int delcont) {
    Contacts* arr = new Contacts[size - 1];

    for (int i = 0; i < size; i++) {
        arr[i] = ar[i];
    }
    int i = delcont + 1;
    while (i < size) {
        arr[i - 1] = ar[i];
        i++;
    }
    for (int i = 0; i < size; i++) {
        arr[i].Cout();
    }
    delete[] arr;
    size--;
}
class MyString {
    char* st;
    static int amount;

public:
    MyString() {
        st = new char[80]();
        amount++;
    }

    MyString(int size) {
        st = new char[size + 1];
        amount++;
    }

    void String(const char* ad) {
        
        st = new char[strlen(ad) + 1];
        strcpy_s(st, strlen(ad) +1, ad);
    }

    static int GetAmount() {
        return amount;
    }

    void Print() {
        cout << "String: " << st << endl;
        cout << "Amount: " << amount << endl;
    }

    ~MyString() {
        delete[] st;
        amount--;
    }
};

int MyString::amount = 0;
int main()
{
   

    
  
    //N2
    MyString obj;
    MyString obj2(100);
    MyString obj3;
    obj3.String("Andrey");
    
    obj3.GetAmount();
    
    obj3.Print();
   //N1
    int size = 3;
    int delcont = 1;
    Contacts* fio = new  Contacts[size];
    fio[0] = Contacts("Ivanov, Ivan, Ivanovich ", 654646456, 232312342, 34897789, "Graphic designer for 10 years");
    fio[1] = Contacts("Pertov, Anatoly, Sergeevich ", 658465409, 43278974, 342423, "Engineer in Microsoft");
    fio[2] = Contacts("Lyakhovetskyi, Leonid, Leonidovich ", 34243243, 9650806, 214124, "Best mentor in computer academy IT-STEP");
    Print(fio);
    addStudents(fio, size);
    deleteStudents(fio, size, delcont);
    delete[] fio;

}

