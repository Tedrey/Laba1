#include <string>
#include <iostream>
using namespace std;

struct tube
{
public:
    string name ="Default name";
    int length = 0;
    int diametr = 0;
    bool in_repair = 0;
    bool editable = 0;
    

void create() {
    editable = 1;
    system("cls");
    print();
    cout<<"Enter name of the tube: ";
    cin>>name;
    system("cls");
    print();
    do {
        cout<<"Enter the length of the "<<name<<" tube(cannot be 0):";
        cin>>length;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            length = 0;
        } 
        system("cls");
        print();
    } while (length == 0);
    system("cls");
    print();
    do {
        cout<<"Enter the diametr of the "<<name<<" tube(cannot be 0):";
        cin>>diametr;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            diametr = 0;
        } 
        system("cls");
        print();
    } while (diametr == 0);
    system("cls");
    print();
    do {
        cout<<"Enter the state of the "<<name<<" (In repairing - 1 Not under repair - 0): ";
        cin>>in_repair;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            in_repair = 0;
        } 
        system("cls");
        print();
    } while (in_repair == 0);
    
}

void state() {
    if (in_repair) {
        cout<<"Current status: In Repairing"<<"\n\n";
    }
    else {
        cout<<"Current status: Not under repair"<<"\n\n";
    }
}
void print() {
    
    cout<<"Tube name: '"<<name<<"'\n";
    cout<<"Tube length: "<<length<<"\n";
    cout<<"Diamert of the tube: "<<diametr<<"\n";
    state();
}

void edit() {
    bool flag = 0; // Флаг указывает, было ли изменено значение in_repair или нет
    if (editable) {
    do {
        cout<<"Enter New state of the tube"<<name<<" Current state is ";
        state();
        cout<<"\n"<<"(In repairing - 1 Not under repair - 0)\n";
        cin>>in_repair;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            in_repair = 0;
        } 
        else {
            flag = 0;
        }
        system("cls");
        
    } while (flag);
    
    }
    else {
        cout<<"You didn't created any of tubes. Try to Create a new or Load one from file.";
        cout<<"Enter any input to return into menu.\n";
        system("pause");
        
    }
}
};

struct cs
{
public:
    string name = "Default name";
    int amount = 0;
    int amount_inwork = -1;
    float fdc = 0.00;
    bool editable = 0;
    
    

void create() {
    editable = 1;
    bool workshop_flag = 0; // Этот флаг нужен для обозначения, вышел ли пользователь за рамки дозволенного при создании класса
    system("cls");
    print();
    cout<<"Enter name of the compressor station: ";
    cin>>name;
    system("cls");
    print();
    do {
        cout<<"Enter the amount of all workshops in "<<name<<" (cannot be 0):";
        cin>>amount;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            amount = 0;
        } 
        system("cls");
        print();
    } while (amount == 0);
    system("cls");
    print();
    do {
        if (workshop_flag == 1) {
            cout<<"!Amount of working workshops cannot be more than all workshops!\n\n";
        }
        cout<<"Enter the amount of working workshops of the "<<name<<": ";
        cin>>amount_inwork;
        if (amount_inwork > amount || amount_inwork < 0) {
            workshop_flag = 1;
        }
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            amount_inwork = -1;
        } 
        system("cls");
        
        print();
    } while (amount_inwork == -1);
    system("cls");
    print();
    do {
        cout<<"Enter fdc(efficiency) of '"<<name<<"' compressor station(float number like 3.14): ";
        cin>>fdc;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            fdc = 0.00;
        } 
        system("cls");
        print();
    } while (fdc == 0.00);
    
}
void print() {
    cout<<"Compressor station name: '"<<name<<"'\n";
    cout<<"Amount of workshops in "<<name<<" station: "<<amount<<"\n";
    cout<<"Amount of working workshops in "<<name<<" station: "<<amount_inwork<<"\n";
    cout<<"efficiency of "<<name<<" station: "<<fdc<<"\n";

}
void edit(){
    bool workbool = 0;
    bool flag = 0;
    if (editable) {
    do {
        cout<<"Enter 1 to stop 1 workshop or 0 to launch one."<<name<<" Currently "<<amount<<" in total, "<<amount_inwork<<" working.";
        cin>>workbool;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        } 
        else {
            if (workbool && amount_inwork >= 0) {
                amount_inwork--;
                flag = 0;
            }
            else if (!workbool && amount_inwork < amount){
                amount_inwork++;
                flag = 0;
            }
            else {
                cout<<"You didn't created any of compressor stations. Try to Create a new or Load one from file.";
                cout<<"Enter any input to return into menu.\n";
                system("pause");
            }
        }
        system("cls");
        } while (flag);
    }
};
