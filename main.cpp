#include <iostream>
#include <fstream>

using namespace std;

int Menu()
{
    int x;
    cout<<endl;
    cout<<"1. Dodaj element tablicy"<<endl;
    cout<<"2. Wstaw element tablicy"<<endl;
    cout<<"3. Usun element tablicy"<<endl;
    cout<<"4. Wyœwietl elementy tablicy"<<endl;
    cout<<"5. Zapisz do pliku"<<endl;
    cout<<"6. Wczytaj z pliku"<<endl;
    cout<<"7. Wyjscie z programu"<<endl;
    cin>>x;
    cout<<endl;
    return x;
}

int main()
{
    int m;
    int *p = NULL;
    int n = 0;
    while(true)
    {
        m = Menu();
        switch(m)
        {
        case 7:
            {
                return 0;
            }
        case 1:
            {
                int * tmp = NULL;
                tmp = new int[n+1]; //tworzenie nowej tablicy (o jeden wiêkszej ni¿ poprzednia)
                if(p != NULL) //je¿eli istnieje poprzednia tablica to:
                {
                    for(int i=0;i<n;i++)
                    {//przekopiuj zawartoœæ poprzedniej tablicy do nowej
                        tmp[i] = p[i];
                    }
                    //usuñ poprzedni¹ tablicê
                    delete[] p;

                }
                cout<<"Podaj wartosc elementu tablicy: ";
                cin>>tmp[n];  //wstaw now¹ wartoœæ do tablicy (na koniec)
                p = tmp; //przekopiuj adres nowej tablicy do wskaŸnika p
                n++; //zwiêksz iloœæ elementów tablicy o 1
                break;
            }
        case 2:
            {
                int miejsce;//miejsce
                int * tmp = NULL;
                tmp = new int[n+1];
                if(p != NULL)
                {
                    for(int i=0;i<n;i++)
                    {
                        tmp[i] = p[i];
                    }
                    delete[] p;

                }
                if(n!=0)
                {
                    do{
                        cout<<"Podaj miejsce nowego elementu: ";
                        cin>>miejsce;
                    }while(miejsce>n);
                }
                if(miejsce<n)
                {
                    int* tmp2 = new int[n+1];
                    for(int i=0;i<n+1;i++)
                    {
                        if(i==miejsce)
                        {
                            tmp2[i] = 0;
                            tmp2[i+1]=tmp[i];
                        }
                        else if(i<miejsce)
                            tmp2[i] = tmp[i];
                        else
                            tmp2[i+1]=tmp[i];
                    }
                    tmp = tmp2;
                }
                cout<<"Podaj wartosc elementu tablicy: ";
                cin>>tmp[miejsce];
                p = tmp;
                n++;
                break;
            }
        case 3:
            {//nie dziala jeszcze
            /*
                if(n==0)
                {
                    cout<<"Tablica jest pusta."<<endl;
                }
                else
                {
                    int miejsce;
                    cout<<"Podaj miejsce usuwanego elementu: ";
                    cin>>miejsce;
                    int* tmp = NULL;
                    tmp = new int[n];
                    if(p != NULL)
                    {
                        for(int i=0;i<n;i++)
                        {
                            if(i==miejsce)
                            {
                                tmp[i] = p[i+1];
                            }
                            else if(i<miejsce)
                                tmp[i] = p[i];
                            else if(i<n-1)
                                tmp[i]=0;
                            else
                                tmp[i] = p[i+1];
                        }
                        delete[] p;
                    }
                    p = tmp;
                    n--;
                }

                break;
                */
                 if(n==0)
                {
                    cout<<"Tablica jest pusta."<<endl;
                    break;
                }
                else
                {
                    int miejsce = 0;
                    int * tmp = NULL;
                    tmp = new int[n-1];
                    if(n!=1)
                    {
                        cout<<"Podaj miejsce usuwanego elementu: ";
                        cin>>miejsce;
                    }
                    if(p != NULL)
                    {
                        for(int i=0;i<n-1;i++)
                        {
                            if(i < miejsce)
                            {

                               tmp[i] = p[i];
                            }
                            else
                            {
                               tmp[i] = p[i+1];
                            }
                        }
                    }
                    delete[] p;
                    p = tmp;
                    n--;
                    break;
                }
            }
        case 4:
            {
                if(n==0)
                {
                    cout<<"Tablica jest pusta."<<endl;
                }
                else
                {
                    cout<<"Zawartosc tablicy:"<<endl;
                    for(int i=0;i<n-1;i++)
                    {
                        cout<<p[i]<<", ";
                    }
                    cout<<p[n-1]<<"."<<endl;;
                    cout<<"Tablica ma "<<n<<" elementow."<<endl;
                }
                break;
            }
        case 5:
            {
                //zapis danych do pliku
                fstream fout;
                fout.open("test.txt",ios::out);
                if(fout.is_open())
                {
                    for(int i=0;i<n-1;i++)
                    {
                      fout<<p[i]<<", ";
                    }
                    fout<<p[n-1]<<".";
                    fout.close();
                }
                break;
            }
        case 6:
            {
                fstream fin;
                fin.open("test.txt",ios::in);
                if(fin.is_open())
                {
                    string tekstout;
                    getline(fin,tekstout);
                    fin.close();
                    int liczby[]={0,1,2,3,4,5,6,7,8,9};
                    cout << tekstout <<endl;
                    cout << tekstout.length() <<endl;
                    for(int i=0;i<tekstout.length();i++)
                    {
                        for(int j=0;j<10;j++)
                        {
                          if(tekstout[i]==liczby[j])
                          {
                            cout<<tekstout[i]<<endl;
                            p[i]=tekstout[i];
                          }
                        }
                    }
                    /*
                    int liczby[]={0,1,2,3,4,5,6,7,8,9};
                    for(int i=0;i<tekstout.length();i++)
                    {
                        int x = 0;
                        for(int j=0;j<10;j++)
                        {
                            if(tekstout[i]==liczby[j])
                            {
                                for(int k=0;j<10;j++)
                                {
                                    if(tekstout[i+1]==liczby[k])
                                    {
                                        cout<<tekstout[i]<<tekstout[i+1]<<endl;
                                        int dwa = tekstout[i]*10+tekstout[i+1];
                                        p[x]= dwa;
                                        i++;
                                    }
                                    else
                                    {
                                        cout<<tekstout[i]<<endl;
                                        p[x]=tekstout[i];
                                    }
                                }
                            }
                        }
                        x++;
                    }
                    */
                }
                //wczytanie danych z pliku
                break;
            }
        default:
            {
                cout<<"Nieprawidlowa opcja"<<endl;
                break;
            }

        }
    }

    return 0;
}
