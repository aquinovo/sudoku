#include <vector>
#include <map>
#include <time.h> 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <cmath>
#include <queue>
#include <sys/time.h>
#include <fstream>

using namespace std;

int peor_memoria( map<int,float> heuristica_HM,int HMS){
  int mayor=heuristica_HM[0];
  int pos_mayor=0;

  for (int i = 1; i < HMS; ++i){
    if(heuristica_HM[i]>mayor){
      mayor=heuristica_HM[i];
      pos_mayor=i;
    }
  }

  return pos_mayor;
}

int mejor_memoria( map<int,float> heuristica_HM,int HMS){
  int menor=heuristica_HM[0];
  int pos_menor=0;

  for (int i = 1; i < HMS; ++i){
    if(heuristica_HM[i]<menor){
      menor=heuristica_HM[i];
      pos_menor=i;
    }
  }

  return pos_menor;
}


void imprimir_matriz(vector < vector<int> >  entrada){
  for (int i = 0; i < 9; ++i){
      for (int j = 0; j < 9; ++j)
        cout<<entrada[i][j]<<" ";
      cout<<endl;
  }
}

map<int, vector < vector <int> > > inicializar_memoria(vector < vector<int> > entrada,int HMS){
  map<int, vector < vector<int> > > HM;

  for (int i = 0; i < HMS; ++i){
    vector < vector<int> >temp=entrada;

    for (int j = 0; j < 9; ++j)
      for (int k = 0; k < 9; ++k)
        if(temp[j][k]==0)
          temp[j][k]=rand() % 9 + 1;

    HM[i]=temp;      
  }

  return HM;
}

float heuristica(vector < vector<int> > entrada){
    float z=0;
    float columna;
    float fila;
    float bloque;

    for (int i = 0; i < 9; ++i){
      columna=0;
      for (int j = 0; j < 9; ++j)
        columna+=entrada[i][j];
      z+=abs(columna-45);
    }

    for (int i = 0; i < 9; ++i){
      fila=0;
      for (int j = 0; j < 9; ++j)
        fila+=entrada[j][i];
      z+=abs(fila-45);
    }
     
    for (int i = 0; i < 9; i=i+3){
      for (int j = 0; j < 9; j=j+3){
        bloque=0;
        for (int k = i; k < i+3; ++k)
          for (int l = j; l < j+3; ++l)
            bloque+=entrada[k][l];
        z+=abs(bloque-45);  
      }   
    }

  return z;
}
map<int,float> evaluar_HM(map<int, vector < vector<int> > >HM ,int HMS){
    map<int,float> heuristica_HM;
    
    for (int i = 0; i < HMS; ++i)
      heuristica_HM[i]=heuristica(HM[i]);
    return heuristica_HM;
}