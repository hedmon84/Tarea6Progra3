#ifndef EVALUADOR_H
#define EVALUADOR_H

#include "Pais.h"
#include "NodoNario.h"
#include <iostream>       // std::cin, std::cout
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
using namespace std;

void evaluar();
void escribir(string nombre_archivo, Pais*gato, int posicion);
Pais* leer(string nombre_archivo, int posicion);
int contarHispanohablantes(string nombre_archivo);
set<int> getNumerosFibonacci(int cantidad);
int contarMayusculas(stack<char> a,queue<char> b);
int contarLLavesRepetidas(multimap<string,string>mi_multimapa);
bool existe(NodoNario* raiz,int buscado);
void buscarYReemplazar(NodoNario* raiz, int buscado, int reemplazo);
vector<char> obtenerSecuencia();

#endif // EVALUADOR_H
