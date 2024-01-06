#include <iostream>

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
                    if(n!=1)
                    {
                        cout<<"Podaj miejsce usuwanego elementu: ";
                        cin>>miejsce;
                    }
                    int* tmp = NULL;
                    cout<<n;
                    if(p != NULL)
                    {
                        for(int i=0;i<n-1;i++)
                        {
                            if(i >= miejsce)
                            {
                               tmp[i] = p[i+1];
                            }
                            else
                            {
                               tmp[i] = p[i];
                            }
                            cout<<tmp[i]<<endl;
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
                break;
            }
        case 6:
            {
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
