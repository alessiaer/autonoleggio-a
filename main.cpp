#include <iostream>
#include<fstream>
#include<ctime>

#define auto_csv "auto.csv"
#define M 7
using namespace std;

struct s_veicolo
{
    string categoria;
    string marca;
    string modello;
    string colore;
    string giorni[7];
}veicolo[M];

void visualizzazione()
{
  ifstream fin ("auto.csv");

  string app;
  while(!fin.eof())
  {
       getline(fin,app);
       cout<<'\t'<<app<<endl;
  }

  fin.close();
}

void vett()
{
    ifstream fin ("auto.csv");
    int j=0;
    while( !fin.eof())
    {
        getline(fin, veicolo[j].categoria,',');
        getline(fin, veicolo[j].marca,',');
        getline(fin, veicolo[j].modello,',');
        getline(fin, veicolo[j].colore,',');
        for(int i=0; i<6; i++)
           getline(fin, veicolo[j].giorni[i],',');
        getline(fin, veicolo[j].giorni[6]);
        j++;
    }

     fin.close();
}

int conta()
{
    int y=0;
    string sos;
    fstream fin (auto_csv, ios::in);
    while(getline(fin, sos))
    {
        y++;
         getline(fin,sos);
    }

    fin.close();
    return y-1;
}


void selezione()
{
    ifstream fin(auto_csv);

    string cat, gio[7], app;
    int  t=0, g,s ;

    cout<<"scegli la categoria a cui sei interessato: " ;
    cin>>cat;
    cout<<"quanti giorni vorresti affittare l'auto? ";
    cin>>g;
    int vet[g];
    cout<<"\n 1=Lunedi\n 2=Martedi\n 3=Mercoledi\n 4=Giovedi\n 5=Venerdi\n 6=Sabato\n 7=Domenica\n";
    do{
        cout<<" scegli i giorni a cui sei interessato: ";
        cin>>s;
        vet[g]=s;
        g--;}
    while(g!=0);
    vett();

    while(!fin.eof())
    {
        if(cat==veicolo[t].categoria)
        {
            cout<<"ale non sei cosi tanto una fallita";
            for(int h=0; h<7; h++)
           {
            if(vet[t]==h) //&& veicolo[t].giorni[h]=="L")
            {
                //stampa la riga
                cout<<"ale non sei cosi tanto una fallita";
            }
        }
        }




        t++;
    }










  cout<<"le auto disponibili sono: \n";
    int p;
    cout<<"Quale vuoi prenotare? ";
    cin>>p;

    fin.close();
}



void modifica()
{
    int p;
    cout<<"Quale vuoi prenotare?";
    cin>>p;

   // getline(cin, veicolo.giorno)
   // int con=conta();
    ofstream fout( auto_csv);

    fout.close();
    visualizzazione();
}


int main()
{
    int s;
    do{
        cout<<"\n 1) Visualizza il catalogo delle auto \n 2) seleziona la categoria e i giorni che desidereresti\n ";
        cin>>s;

    switch(s)
    {
        case 1: visualizzazione();
                break;
        case 2: selezione();
                break;
        case 3: break;
    }

    }while(s!=2);
    return 0;
}
