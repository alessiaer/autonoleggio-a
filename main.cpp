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
    char giorni[7];
}veicolo[M];

void visualizzazione()
{
  ofstream fout ("auto.csv");

  cout<<"Categoria, Marca, Modello, Colore, Lunedi, Martedi, Mercoledi, Giovedi, Venerdi, Sabato, Domenica"<<endl;
  fout<<"Categoria, Marca, Modello, Colore, Lunedì, Martedì, Mercoledì, Giovedì, Venerdì, Sabato, Domenica"<<endl;

  for(int i=0; i<M; i++)
   {
     cout<<veicolo[i].categoria<<',';
     fout<< veicolo[i].categoria<<',';

     cout<< veicolo[i].marca<<',';
     fout<< veicolo[i].marca<<',';

     cout<< veicolo[i].modello<<',';
     fout<< veicolo[i].modello<<',';

     cout<< veicolo[i].colore<<endl;
     fout<< veicolo[i].colore<<endl;
   }
  fout.close();
}

void inserimento()
{
    fstream fout ("auto.csv");
    cin.ignore();

     //categoria
     veicolo[0].categoria="utilitaria";
     veicolo[1].categoria="utilitaria";
     veicolo[2].categoria="lusso";
     veicolo[3].categoria="sportiva";
     veicolo[4].categoria="furgone";
     veicolo[5].categoria="lusso";
     veicolo[6].categoria="utilitaria";

     //marca
     veicolo[0].marca="FIAT";
     veicolo[1].marca="KIA";
     veicolo[2].marca="Mercedes";
     veicolo[3].marca="Lamborghini";
     veicolo[4].marca="Ford";
     veicolo[5].marca="BMW";
     veicolo[6].marca="Peugeot";

     //modello
     veicolo[0].modello="Panda";
     veicolo[1].modello="Pikanto";
     veicolo[2].modello="Classe 5";
     veicolo[3].modello="Huracan";
     veicolo[4].modello="Transit";
     veicolo[5].modello="Serie 5";
     veicolo[6].modello="Peugeot";

     //colore
     veicolo[0].colore="rosso";
     veicolo[1].colore="bronzo";
     veicolo[2].colore="nero";
     veicolo[3].colore="giallo";
     veicolo[4].colore="bianco";
     veicolo[5].colore="metallizzato";
     veicolo[6].colore="verde";

     //giorni
    /* veicolo[0].giorni{'L','L','L','A','A','A','A'};
       veicolo[1].giorni[]={'A','A','A','A','L','A','A'};
       veicolo[2].giorni[]={'L','L','L','L','L','A','A'};
       veicolo[3].giorni[]={'L','L','L','L','L','L','L'};
       veicolo[4].giorni[]={'A','A','A','A','A','L','L'};
       veicolo[5].giorni[]={'L','L','L','L','L','A','A'};
       veicolo[6].giorni[]={'L','A','L','L','L','A','L'};

*/

      visualizzazione();



fout.close();
}

void selezione()
{
    ifstream fin(auto_csv);

    string cat, gio[7], app;
    int t=0, g,s ;

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

  cout<<"le auto disponibili sono: \n";

   while(!fin.eof())
    {
        for(int h=0; h<7; h++)
        {

            if(vet[t]== h && veicolo[t].giorni[h]== 'L')
                {

                    getline(fin,app);
                    cout<<'\t'<<app<<endl; //agg var per fare 1)..
                    cout<<"\t_______________________________________\n";
                }
         }
       t++;
    }

    int p;
    cout<<"Quale vuoi prenotare? ";
    cin>>p;
    //controllare tipo menu? <aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

    fin.close();
}



int conta()
{
    int y=0;
    string sos;
    fstream fin (auto_csv, ios::in);
    while(getline(fin, sos))
          y++;
    fin.close();
    return y;
}


void modifica()
{
    cout<<"Quale vuoi prenotare?";
    cin>>p;

    getline(cin, veicolo.giorno)
    int con=conta();
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
        case 1: inserimento();
                break;
        case 2: selezione();
                break;
        case 3: break;
    }

    }while(s!=2);
    return 0;
}
