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
    
    for (int i = 0; i < 9; ++i){
      for (int j = 0; j < 9; ++j)
        z+=entrada[i][j];
      z-=45;
    }

    for (int i = 0; i < 9; ++i){
      for (int j = 0; j < 9; ++j)
        z+=entrada[j][i];
        
      z-=45;
    }
     
    for (int i = 0; i < 9; i=i+3){
      for (int j = 0; j < 9; j=j+3){
        for (int k = i; k < i+3; ++k)
          for (int l = j; l < j+3; ++l)
            z+=entrada[k][l];
        z-=45;  
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