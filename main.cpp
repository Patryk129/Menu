#include <iostream>
#include <fstream>

using namespace std;

int Menu()
{
    int x;
    cout<<"1"<<endl;
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
                tmp = new int[n+1];
                if(p != NULL)
                {
                    for(int i=0;i<n;i++)
                    {
                        tmp[i] = p[i];
                    }
                    delete[] p;

                }
                cout<<"Podaj wartosc elementu tablicy: ";
                cin>>tmp[n];
                p = tmp;
                delete[] tmp;
                n++;
                break;
            }
        case 2:
            {
                int miejsce = 0;
                int wartosc = 0;
                int * tmp = NULL;
                tmp = new int[n+1];
                if(n!=0)
                {
                    ///do{
                    cout<<"Podaj miejsce nowego elementu: ";
                    cin>>miejsce;
                    if(miejsce>n || miejsce<0)
                    {
                        cout<<"Podano niepoprawne miejsce"<<endl;
                        break;
                    }
                }
                     /// }while(miejsce>n || miejsce<0);
                cout<<"Podaj wartosc elementu tablicy: ";
                cin>>wartosc;
                if(p != NULL)
                {
                    for(int i=0;i<n+1;i++)
                    {
                        if(i==miejsce)
                            tmp[i] = wartosc;
                        else if(i<miejsce)
                            tmp[i] = p[i];
                        else if(i>miejsce)
                            tmp[i] = p[i-1];
                    }
                    delete[] p;
                }
                else
                {
                    tmp[0] = wartosc;
                }
                p = tmp;
                delete[] tmp;
                n++;
                break;
            }
        case 3:
            {
                if(p == NULL )
                {
                    cout<<"Tablica jest pusta."<<endl;
                    break;
                }
                else
                {
                    int miejsce = 0;
                    int * tmp = NULL;
                    tmp = new int[n-1];
                    if(p != NULL)
                    {
                        cout<<"Podaj miejsce usuwanego elementu: ";
                        cin>>miejsce;
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
                    delete[] tmp;
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
                if(p != NULL)
                {
                    fstream fout;
                    fout.open("test.txt",ios::out);
                    if(fout.is_open())
                    {
                        for(int i=0;i<n-1;i++)
                        {
                          fout<<p[i]<<" ";
                        }
                        fout<<p[n-1];//<<".";
                        fout.close();
                        cout<<"Zapisano pomyslnie!"<<endl;
                    }
                }
                else
                {
                    cout<<"Tablica jest pusta"<<endl;
                }
                break;
            }
        case 6://dane musza byc oddzielone od siebie spacja
            {
                fstream fin;
                p = NULL;
                fin.open("test.txt",ios::in);
                if(fin.is_open())
                {
                    int liczba;
                    cout<<"Podaj ilosc danych wejsciowych: ";
                    cin>>n;
                    int * tmp = NULL;
                    tmp = new int[n];
                    int i=0;
                    while(fin >> liczba)
                    {
                        ///cout<<liczba<<endl;
                        if(i<n)
                        {
                            tmp[i] = liczba;
                            i++;
                        }

                    }
                     p = tmp;
                     delete[] tmp;
                     cout<<"Wczytano dane!"<<endl;
                }
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
