#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "class.cpp"

using namespace std;

int main()
{   
    tube cur_tube;
    cs cur_cs;
    ofstream outf;
    ifstream inf;
    string readl, saved_tube, saved_cs;
    while (true)
    {
        system("cls"); 
        
        string choise;
        
        cout<<"Choose option"<<"\n"<<"1. Add tube "<<"\n"<<"2. Add Compress station "<<"\n"<<"3. Show list of objects "<<"\n"<<"4. Edit a tube "<<"\n"<<"5. Edit refunery "<<"\n"<<"6. Save all"<<"\n"<<"7. Load from file "<<"\n"<<"0. Exit"<<"\n";
        cout<<"In the case of entering don't have a command, you will have to enter again\n";
        cin>>choise;
        
        if (choise == "\n") 
        {
            cout<<"---"<<choise<<"---";
            break;
        }
        else 
        { 
            char answer = choise[0];
            switch(answer)
            {
                case '0':
                    exit(0);
                    return 0;
                    break;

                case '1':
                    cur_tube.create();  
                    break;

                case '2':
                    cur_cs.create();
                    break;

                case '3':
                    if (cur_tube.editable) 
                    {
                        cur_tube.print();
                    }
                    if (cur_cs.editable) 
                    {
                        cur_cs.print();
                    }
                    if (cur_tube.editable == 0 && cur_cs.editable == 0) 
                    {
                        cout<<"Seems like there is no objects to show. You can Create one or try to Load some in menu.\n";
                    }
                    system("pause");
                    break;
            
                case '4':
                    cur_tube.edit();  
                    break;

                case '5':
                    cur_cs.edit();
                    break;
                case '6':
                    outf.open("save.txt");
                    if (outf.is_open())
                    {
                        if (cur_tube.editable) 
                        {
                            outf<<"test*";
                            outf<<cur_tube.name<<' '<<cur_tube.length<<' '<<cur_tube.diametr<<' '<<cur_tube.in_repair<<' '<<cur_tube.editable<<'*';
                        }
                        else 
                        {
                            outf<<"test*";
                            outf<<'-'<<'*';
                        }
                        if (cur_cs.editable) 
                        {
                            outf<<cur_cs.name<<' '<<cur_cs.amount<<' '<<cur_cs.amount_inwork<<' '<<cur_cs.fdc<<' '<<cur_cs.editable; 
                        }
                        else 
                        {
                            outf<<'-';
                        }
                        if (cur_tube.editable == 0 && cur_cs.editable == 0) 
                        {
                            cout<<"Seems like you have no objects to save. You should Create some first.\n";
                        }
                    }
                    outf.close();
                    system("pause");
                    break;
                    
                case '7':
                    inf.open("save.txt");
                    getline(inf, readl, '*');
                    getline(inf, saved_tube, '*');
                    getline(inf, saved_cs, '*');

                    if(readl == "test" && saved_tube != "-" or saved_cs != "-")
                    {
                        cout << "Sucsessfully uploaded data!\n";
                        
                        if (saved_tube != "-")
                        {
                            istringstream stream_tube(saved_tube);
                            stream_tube>>cur_tube.name>>cur_tube.length>>cur_tube.diametr>>cur_tube.in_repair>>cur_tube.editable;
                        }
                        if (saved_cs != "-")
                        {
                            istringstream stream_cs(saved_cs);
                            stream_cs>>cur_cs.name>>cur_cs.amount>>cur_cs.amount_inwork>>cur_cs.fdc>>cur_cs.editable;
                        }
                        
                    }
                    else
                    {
                        cout<<"Looks like you have no saved objects. Try to Create a new one.\n";
                    }
                    inf.close();
                    system("pause");
                    break;

                default:
                    break;
            }
        }
    }
}