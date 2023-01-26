#include <iostream>
#include<fstream>
#include<ctime>

#define auto_csv "auto.csv"
#define M 100
int grandezza=0;
int posizione[M];
using namespace std;

struct s_veicolo
{
    string categoria;
    string marca;
    string modello;
    string colore;
    string lun;
    string mar;
    string mer;
    string gio;
    string ven;
    string sab;
    string dom;
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
    getline(fin,a);
    getline(fin,a);

    while( !fin.eof())
    {
        getline(fin, veicolo[j].categoria,',');
        getline(fin, veicolo[j].marca,',');
        getline(fin, veicolo[j].modello,',');
        getline(fin, veicolo[j].colore,',');
        getline(fin, veicolo[j].lun,',');
        getline(fin, veicolo[j].mar,',');
        getline(fin, veicolo[j].mer,',');
        getline(fin, veicolo[j].gio,',');
        getline(fin, veicolo[j].ven,',');
        getline(fin, veicolo[j].sab,',');
        getline(fin, veicolo[j].dom);
        j++;
        grandezza++;
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
    return y;
}

void stampa()
{

    for(int c=0; c<grandezza; c++)
    {
        cout<<veicolo[c].categoria<<','<<veicolo[c].marca<<','<<veicolo[c].modello<<','<<veicolo[c].colore<<','<<veicolo[c].lun<<','<<veicolo[c].mar<<','<<veicolo[c].mer<<','<<veicolo[c].gio<<','<<veicolo[c].ven<<','<<veicolo[c].sab<<','<<veicolo[c].dom<<endl;
    }
}




void selezione()
{
    ifstream fin(auto_csv);

    string cat, gio[7], app;
    int  g;
    int f=0, a=0, b=0;


    cout<<"scegli la categoria a cui sei interessato: " ;
    cin>>cat;
    cout<<"quanti giorni vorresti affittare l'auto? ";
    cin>>g;
    int vet[20], h=0;
    cout<<"\n 1=Lunedi\n 2=Martedi\n 3=Mercoledi\n 4=Giovedi\n 5=Venerdi\n 6=Sabato\n 7=Domenica\n";
    cout<<" scegli i giorni a cui sei interessato: \n";
    do{
        cout<<">>";
        cin>>vet[h];
        h++;}
    while(h<g);


    vett();
    //stampa();


    for(int c=0; c<grandezza; c++)
    {
      if(cat==veicolo[c].categoria)
      {
        while(f<g)
        {
            switch(vet[f])
            {

                case 1: if(veicolo[c].lun==" L" )
                        a++;
                        break;

                case 2: if(veicolo[c].mar==" L")
                        a++;
                        break;

                case 3: if(veicolo[c].mer ==" L")
                        a++;
                        break;

                case 4: if(veicolo[c].gio ==" L")
                        a++;
                        break;

                 case 5: if(veicolo[c].ven ==" L")
                         a++;
                         break;

                 case 6: if(veicolo[c].sab ==" L")
                         a++;break;

                 case 7: if(veicolo[c].dom ==" L")
                         a++;break;


            }

            f++;
         cout<<a<<endl;

        }


     }
  }


     /*  if(a=g)
        {


         while(b<g)
        {
         switch(vet[b])
            {
                case 1: if(veicolo[c].lun==" L")
                        {
                            cout<<veicolo[c].categoria<<','<<veicolo[c].marca<<','<<veicolo[c].modello<<','<<veicolo[c].colore<<','<<veicolo[c].lun<<','<<veicolo[c].mar<<','<<veicolo[c].mer<<','<<veicolo[c].gio<<','<<veicolo[c].ven<<','<<veicolo[c].sab<<','<<veicolo[c].dom<<endl;
                            veicolo[c].lun=" A";
                        }
                        break;

                case 2: if(veicolo[c].mar==" L")
                        {
                            cout<<veicolo[c].categoria<<','<<veicolo[c].marca<<','<<veicolo[c].modello<<','<<veicolo[c].colore<<','<<veicolo[c].lun<<','<<veicolo[c].mar<<','<<veicolo[c].mer<<','<<veicolo[c].gio<<','<<veicolo[c].ven<<','<<veicolo[c].sab<<','<<veicolo[c].dom<<endl;
                            veicolo[c].mar=" A";
                        }
                         break;

                case 3: if(veicolo[c].mer ==" L")
                        {
                            cout<<veicolo[c].categoria<<','<<veicolo[c].marca<<','<<veicolo[c].modello<<','<<veicolo[c].colore<<','<<veicolo[c].lun<<','<<veicolo[c].mar<<','<<veicolo[c].mer<<','<<veicolo[c].gio<<','<<veicolo[c].ven<<','<<veicolo[c].sab<<','<<veicolo[c].dom<<endl;
                            veicolo[c].mar=" A";
                        }
                        break;

                case 4: if(veicolo[c].gio ==" L")
                        {
                            cout<<veicolo[c].categoria<<','<<veicolo[c].marca<<','<<veicolo[c].modello<<','<<veicolo[c].colore<<','<<veicolo[c].lun<<','<<veicolo[c].mar<<','<<veicolo[c].mer<<','<<veicolo[c].gio<<','<<veicolo[c].ven<<','<<veicolo[c].sab<<','<<veicolo[c].dom<<endl;
                            veicolo[c].mar=" A";
                        }
                        break;

                 case 5: if(veicolo[c].ven ==" L")
                        {
                            cout<<veicolo[c].categoria<<','<<veicolo[c].marca<<','<<veicolo[c].modello<<','<<veicolo[c].colore<<','<<veicolo[c].lun<<','<<veicolo[c].mar<<','<<veicolo[c].mer<<','<<veicolo[c].gio<<','<<veicolo[c].ven<<','<<veicolo[c].sab<<','<<veicolo[c].dom<<endl;
                            veicolo[c].mar=" A";
                        }
                        break;

                 case 6: if(veicolo[c].sab ==" L")
                        {
                            cout<<veicolo[c].categoria<<','<<veicolo[c].marca<<','<<veicolo[c].modello<<','<<veicolo[c].colore<<','<<veicolo[c].lun<<','<<veicolo[c].mar<<','<<veicolo[c].mer<<','<<veicolo[c].gio<<','<<veicolo[c].ven<<','<<veicolo[c].sab<<','<<veicolo[c].dom<<endl;
                            veicolo[c].mar=" A";
                        }
                        break;

                 case 7: if(veicolo[c].dom ==" L")
                        {
                            cout<<veicolo[c].categoria<<','<<veicolo[c].marca<<','<<veicolo[c].modello<<','<<veicolo[c].colore<<','<<veicolo[c].lun<<','<<veicolo[c].mar<<','<<veicolo[c].mer<<','<<veicolo[c].gio<<','<<veicolo[c].ven<<','<<veicolo[c].sab<<','<<veicolo[c].dom<<endl;
                            veicolo[c].mar=" A";
                        }
                        break;
            }
            b++;
        }
        }*/



  cout<<"le auto disponibili sono: \n";
  cout<<"non ci sono auto che soddisfano i requisiti scelti  \n";

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
