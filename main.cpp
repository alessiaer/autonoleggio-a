#include <iostream>
#include<fstream>
#include<ctime>

#define auto_csv "auto.csv"
#define M 100
int grandezza=0;
using namespace std;

struct s_veicolo
{
    string categoria;
    string marca;
    string modello;
    string colore;
    string giorni[7];
    bool cont=false;
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
    string a;

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
        grandezza++;
    }

     fin.close();
}

void scambia()
{
    ofstream fout ("auto.csv");
    fout<<"";

    for(int k=0;k<grandezza; k++)
    {
        fout<<veicolo[k].categoria<<','<<veicolo[k].marca<<','<<veicolo[k].modello<<','<<veicolo[k].colore<<',';
           for(int i=0; i<6; i++)
           {
             fout<<veicolo[k].giorni[i]<<',';
           }

          if(k!=grandezza-1)
             fout<<veicolo[k].giorni[6]<<endl;
          else
            fout<<veicolo[k].giorni[6];
    }
    fout.close();
}
/*
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
    return y;
}*/

void selezione()
{
    ifstream fin(auto_csv);

    string cat, gio[7], app;
    int  g;
    int  vet[20], h=0;
    grandezza=0;
    vett();


    cout<<"scegli la categoria a cui sei interessato: " ;
    cin>>cat;
    cout<<"quanti giorni vorresti affittare l'auto? ";
    cin>>g;
    cout<<"\n 1=Lunedi\n 2=Martedi\n 3=Mercoledi\n 4=Giovedi\n 5=Venerdi\n 6=Sabato\n 7=Domenica\n";
    cout<<" scegli i giorni a cui sei interessato: \n";
    do{
        cout<<">>";
        cin>>vet[h];
        vet[h]=vet[h]-1;
        h++;
    }while(h<g);

int a=0;

    for(int c=0; c<grandezza; c++)
    {
      if(cat==veicolo[c].categoria)
      {
          for(int f=0; f<g; f++)
          {
              if(veicolo[c].giorni[vet[f]]==" L")
                a++;
          }

          if(a==h)
            veicolo[c].cont=true;
          else
            veicolo[c].cont=false;
      }
      else
        veicolo[c].cont=false;
      a=0;
    }

    cout<<"\n le auto disponibili sono: \n";
    for(int c=0; c<grandezza; c++)
    {

        if(veicolo[c].cont==true)
        {
          cout<<c<<") "<<veicolo[c].categoria<<','<<veicolo[c].marca<<','<<veicolo[c].modello<<','<<veicolo[c].colore<<',';
           for(int i=0; i<6; i++)
           {
             cout<<veicolo[c].giorni[i]<<',';
           }
          cout<<veicolo[c].giorni[6]<<endl;
        }
    }


    int p;
    cout<<"Quale vuoi prenotare? ";
    cin>>p;

    for(int f=0; f<g; f++)
         veicolo[p].giorni[vet[f]]=" A";

   scambia();

    fin.close();
}

/*
utilitaria, FIAT, Panda, rosso, L, L, L, A, A, A, A
utilitaria, KIA, Pikanto, bronzo, A, A, L, L, L, A, A
lusso, Mercedes, Classe 5, nero, L, L, L, L, L, A, A
sportiva, Lamborghini, Huracan, giallo, L, L, L, L, L, L, L
furgone, Ford, Transit, bianco, A, A, A, A, A, L, L
lusso, BMW, Serie 5, grigio metallizzato, L, L, L, L, L, A, A
utilitaria, Peugeot, 108, verde, L, A, L, L, L, A, L
*/


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

    }while(s!=3);
    return 0;
}
