#include <iostream>
#include <list>
#include <fstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "Pais.h"
#include "Evaluador.h"
#include "NodoNario.h"

using namespace std;

//Escribe "pais" en un achivo con nombre "nombre_archivo" en la posicion "posicion"
//Nota: Se deben poder agregar varios registros en un solo archivo
int tregistro = 25;
void escribir(string nombre_archivo, Pais*pais, int posicion)
{
    ofstream out (nombre_archivo.c_str(),ios::in|ios::out);
    if(!out.is_open())
    {
        out.open(nombre_archivo.c_str());
    }
    out.seekp(posicion*tregistro);
    out.write(pais->nombre.c_str(),20);
    out.write((char*)&pais->habitantes,4);
    out.write((char*)&pais->hablan_espanol,1);

    out.close();
}

//Devuelve un pais previamente escrito (con la funcion escribir()) en el archivo con nombre "nombre_archivo" en la posicion "posicion"
//Nota: Se deben poder leer varios registros de un archivo
Pais* leer(string nombre_archivo, int posicion)
{
    char nombre[20];
    int habitantes;
    bool hablanesp;

    ifstream in(nombre_archivo.c_str());
    in.seekg(posicion*tregistro);

    in.read(nombre,20);
    in.read((char*)&habitantes,4);
    in.read((char*)&hablanesp,1);

    in.close();

    Pais *pais = new Pais(nombre, habitantes,hablanesp);
    return pais;

}

//Devuelve suma de habitantes de paises que hablan espanol en el archivo con nombre "nombre_archivo"
//Nota: Los registros se deben de haber guardado previamente con la funcion escribir()
int contarHispanohablantes(string nombre_archivo)
{
    bool hablanesp;
    int habitantes;
    int total = 0 ;

    ifstream in(nombre_archivo.c_str());
    in.seekg(0,ios::end);
    int tam=in.tellg();
    in.seekg(0);
    while (in.tellg()<tam)
    {
        in.seekg(20,ios::cur);
        in.read((char*)&habitantes,4);
        in.read((char*)&hablanesp,1);
        if(hablanesp == true)
        {
            total+=habitantes;
        }
    }

    in.close();
    return total;

}

//Devuelve un set que contenga los numeros fibonacci.
//La cantidad de numeros que contiene se determina por el parametro "cantidad"
set<int> getNumerosFibonacci(int cantidad)
{
    int anterior1=0,anterior2=0;;

    set<int>respuesta;
    for(int i=0;i<cantidad;i++){
        if(i==0){
            respuesta.insert(0);
        }
        else if(i==1){
            respuesta.insert(1);
            anterior1=1;
        }
        else{
            int num=anterior1+anterior2;
            respuesta.insert(num);
            anterior2=anterior1;
            anterior1=num;
        }
    }

    return respuesta;
}

//Devuelve la cantidad de letras mayusculas presentes en "a" y "b"
int contarMayusculas(stack<char> a,queue<char> b)
{
    int total = 0;
    while(!a.empty())
    {
        if((int)a.top() >= 65 && (int)a.top() <= 90)
        {
            total++;
            a.pop();
        }
        else
            a.pop();
    }

    while(!b.empty())
    {
        if((int)b.front() >= 65 && (int)b.front()<= 90)
        {
            total++;
            b.pop();
        }
        else
            b.pop();
    }
    return total;
}

//Devuelve la cantidad de llaves repetidas en "mi_multimapa"
//Nota: No devuelve la cantidad de repeticines
int contarLLavesRepetidas(multimap<string,string> mi_multimapa)
{
    map<string,string> mi_mapa;
    for(multimap<string,string>::iterator i= mi_multimapa.begin(); i!= mi_multimapa.end(); i++)
    {
        pair<string,string>par_actual = *i;
        mi_mapa [par_actual.first] = par_actual.second;
    }
    int repetidas = (mi_multimapa.size() - mi_mapa.size());
    return repetidas;
}

//Devuelve true si y solo si "buscado" existe en el arbol nario "raiz"
bool existe(NodoNario* raiz,int buscado)
{
    if(raiz == NULL)
        return false;
    if(raiz -> valor == buscado){
        return true;
    }else{
        for(int hijo = 0; hijo < raiz -> hijos.size(); hijo ++){
            bool b = existe(raiz -> hijos[hijo], buscado);
            if(b){
                return true;
            }
        }
    }
    return false;
}

//Busca el valor "buscado" en el arbol "raiz" y lo reemplaza con "reemplazo"
void buscarYReemplazar(NodoNario* raiz, int buscado, int reemplazo)
{
    if(raiz == NULL)
        return;
    if(raiz -> valor == buscado){
        raiz -> valor = reemplazo;
    }else{
        for(int hijo = 0; hijo < raiz -> hijos.size(); hijo ++){
            bool b = existe(raiz -> hijos[hijo], buscado);
            if(b){
                raiz -> hijos[hijo] -> valor = reemplazo;
            }
        }
    }
}

//Devuelve un vector que contenga la siguiente secuencia binaria:
//00000001
//00000010
//00000100
//00001000
//00010000
//00100000
//01000000
//10000000
vector<char> obtenerSecuencia()
{
    vector<char>respuesta;
    respuesta.push_back(1);
    respuesta.push_back(2);
    respuesta.push_back(4);
    respuesta.push_back(8);
    respuesta.push_back(16);
    respuesta.push_back(32);
    respuesta.push_back(64);
    respuesta.push_back(128);
    return respuesta;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

