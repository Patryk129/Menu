#include <iostream>

using namespace std;

int Menu()
{
    int x;
    cout<<endl;
    cout<<"1. Dodaj element tablicy"<<endl;
    cout<<"2. Wstaw element tablicy"<<endl;
    cout<<"3. Usun element tablicy"<<endl;
    cout<<"4. Wyświetl elementy tablicy"<<endl;
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
                tmp = new int[n+1]; //tworzenie nowej tablicy (o jeden większej niż poprzednia)
                if(p != NULL) //jeżeli istnieje poprzednia tablica to:
                {
                    for(int i=0;i<n;i++)
                    {//przekopiuj zawartość poprzedniej tablicy do nowej
                        tmp[i] = p[i];
                    }
                    //usuń poprzednią tablicę
                    delete[] p;

                }
                cout<<"Podaj wartosc elementu tablicy: ";
                cin>>tmp[n];  //wstaw nową wartość do tablicy (na koniec)
                p = tmp; //przekopiuj adres nowej tablicy do wskaźnika p
                n++; //zwiększ ilość elementów tablicy o 1
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
            {
                int miejsce;
                cout<<"Podaj miejsce usuwanego elementu: ";
                cin>>miejsce;
                int* tmp = NULL;
                tmp = new int[n-1];
                if(p != NULL)
                {
                    for(int i=0;i<n;i++)
                    {
                        if(i==miejsce)
                        {
                            tmp[i] = p[i+1];
                        }
                        else if(i<miejsce)
                            tmp[i] = p[i+1];
                        else
                            tmp[i] = p[i+1];
                    }
                    delete[] p;
                }
                p = tmp;
                n--;
                break;
            }
        case 4:
            {
                cout<<"Zawartosc tablicy:"<<endl;
                for(int i=0;i<n-1;i++)
                {
                    cout<<p[i]<<", ";
                }
                cout<<p[n-1]<<".";
                cout<<endl;
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
