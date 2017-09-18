#include "Evaluador.h"

string getPrimerElemento(queue<string> mi_cola);

bool estaEncendido(char byte, int pos)
{
char mascara = 1;
mascara = mascara << pos;
return byte&mascara;
}

bool compareSets(set<int>s1, set<int>s2)
{
    if(s1.size()!=s2.size())
        return false;
    set<int>::iterator j =s2.begin();
    for(set<int>::iterator i=s1.begin();i!=s1.end();i++)
    {
        if(*i!=*j)
            return false;
        j++;
    }
    return true;
}

bool compareSets(stack<char>s1, stack<char>s2)
{
    if(s1.size()!=s2.size())
        return false;
    while(!s1.empty())
    {
        if(s1.top()!=s2.top())
            return false;
        s1.pop();
        s2.pop();
    }
    return true;
}

void evaluar()
{
    int nota = 0;

    escribir("archivo_evaluador1",new Pais("Honduras",1000,true),1);
    escribir("archivo_evaluador1",new Pais("Francia",2000,false),0);
    escribir("archivo_evaluador1",new Pais("Ecuador",1500,true),2);


    cout<<"Ejercicio escribir() y leer():\t\t";
    bool correcto = true;

    if(  (leer("archivo_evaluador1",0)->nombre == "Francia"
       && leer("archivo_evaluador1",1)->nombre == "Honduras"
       && leer("archivo_evaluador1",2)->nombre == "Ecuador"
       && leer("archivo_evaluador1",0)->habitantes == 2000
       && leer("archivo_evaluador1",1)->habitantes == 1000
       && leer("archivo_evaluador1",2)->habitantes == 1500
       && leer("archivo_evaluador1",0)->hablan_espanol == false
       && leer("archivo_evaluador1",1)->hablan_espanol == true
       && leer("archivo_evaluador1",2)->hablan_espanol == true
       )==false)
    {
        correcto=false;
    }

    escribir("archivo_evaluador2",new Pais("China",4000,false),0);
    escribir("archivo_evaluador2",new Pais("Argentina",3000,true),1);

    if(  (leer("archivo_evaluador2",0)->nombre == "China"
       && leer("archivo_evaluador2",1)->nombre == "Argentina"
       && leer("archivo_evaluador2",0)->habitantes == 4000
       && leer("archivo_evaluador2",1)->habitantes == 3000
       && leer("archivo_evaluador2",0)->hablan_espanol == false
       && leer("archivo_evaluador2",1)->hablan_espanol == true
       )==false)
    {
        correcto=false;
    }

    if(correcto)
    {
        nota+=4;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Ejercicio contarBuenas():\t\t";
    if(contarHispanohablantes("archivo_evaluador1")==2500
       &&contarHispanohablantes("archivo_evaluador2")==3000
       )
    {
        nota+=3;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    set<int>s1;
    s1.insert(0);
    s1.insert(1);
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(5);

    set<int>s2;
    s2.insert(0);
    s2.insert(1);
    s2.insert(1);
    s2.insert(2);
    s2.insert(3);
    s2.insert(5);
    s2.insert(8);
    s2.insert(13);
    s2.insert(21);
    s2.insert(34);

    set<int>s3;
    s3.insert(0);

    cout<<"Ejercicio getNumerosFibonacci():\t";
    if(compareSets(getNumerosFibonacci(6),s1)
       && compareSets(getNumerosFibonacci(10),s2)
       && compareSets(getNumerosFibonacci(1),s3)
       )
    {
        nota+=4;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }


    queue<char>q1;//3
    q1.push('A');
    q1.push('b');
    q1.push('G');
    q1.push('X');

    queue<char>q2;//1
    q2.push('a');
    q2.push('b');
    q2.push('c');
    q2.push('D');
    q2.push('r');

    stack<char>sq1;//2
    sq1.push('X');
    sq1.push('w');
    sq1.push('e');
    sq1.push('R');

    stack<char>sq2;//0
    sq2.push('a');
    sq2.push('s');
    sq2.push('d');

    cout<<"Ejercicio contarMayusculas():\t\t";

    if(contarMayusculas(sq1,q1)==5
       && contarMayusculas(sq2,q1)==3
       && contarMayusculas(sq1,q2)==3
       && contarMayusculas(sq2,q2)==1
       )
    {
        nota+=3;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Ejercicio contarLLavesRepetidas():\t";

    multimap<string,string>m1;
    m1.insert(pair<string,string>("x","a"));
    m1.insert(pair<string,string>("x","b"));
    m1.insert(pair<string,string>("y","c"));

    multimap<string,string>m2;
    m2.insert(pair<string,string>("A","1"));
    m2.insert(pair<string,string>("B","2"));
    m2.insert(pair<string,string>("C","3"));

    multimap<string,string>m3;
    m3.insert(pair<string,string>("A","1"));
    m3.insert(pair<string,string>("B","1"));
    m3.insert(pair<string,string>("B","1"));
    m3.insert(pair<string,string>("B","1"));
    m3.insert(pair<string,string>("C","1"));
    m3.insert(pair<string,string>("C","1"));
    m3.insert(pair<string,string>("D","1"));

    if(contarLLavesRepetidas(m1)==1
       && contarLLavesRepetidas(m2)==0
       && contarLLavesRepetidas(m3)==3
       )
    {
        nota+=3;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Ejercicio existe():\t\t\t";

    NodoNario *nb1 = new NodoNario(1);
    nb1->agregar(2);
    nb1->agregar(3);
    nb1->agregar(4);

    nb1->hijos[0]->agregar(5);

    nb1->hijos[1]->agregar(6);
    nb1->hijos[1]->agregar(7);

    nb1->hijos[0]->hijos[0]->agregar(8);


    if(existe(nb1,1)
        && existe(nb1,2)
        && existe(nb1,5)
        && existe(nb1,3)
        && !existe(nb1,9)
        && existe(nb1,8)
        && !existe(nb1,10)
       )
    {
        nota+=3;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Ejercicio buscarYReemplazar():\t\t";

    buscarYReemplazar(nb1,2,20);
    buscarYReemplazar(nb1,1,96);
    buscarYReemplazar(nb1,8,777);

    if(nb1->hijos[0]->valor==20
       && nb1->valor==96
       && nb1->hijos[0]->hijos[0]->hijos[0]->valor==777
       )
    {
        nota+=3;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Ejercicio obtenerSecuencia():\t\t";
    if(obtenerSecuencia().size()==8
        && obtenerSecuencia()[1]==2
        && obtenerSecuencia()[2]==4
        && obtenerSecuencia()[6]==64
        && obtenerSecuencia()[7]==-128
       )
    {
        nota+=3;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<endl<<"Nota: "<<nota<<"/20"<<endl;
}
