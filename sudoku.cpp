#include  "funciones.cpp" 

vector < vector<int> > sudoku(vector < vector<int> > entrada,int iteraciones,int HMS,float HMCR,float PAR){
	vector < vector<int> > solucion,temp;
	map<int, vector < vector<int> > > HM;
	map<int, float > heuristica_HM;
	float hmcr,seleccion,valor_temp,pos_peor,peor,par;
   
    HM=inicializar_memoria(entrada,HMS);
    heuristica_HM=evaluar_HM(HM,HMS);
    
    for (int i = 0; i < iteraciones; ++i){
    	temp=entrada;
    	hmcr= (rand() % 99); hmcr/=100;
    	for (int j = 0; j < 9; ++j)
    		for (int k = 0; k < 9; ++k)
    			if(temp[j][k]==0){
    				if(hmcr<HMCR){
    				   par= (rand() % 99); par/=100;
    				   seleccion=rand() % HMS;
    				   temp[j][k]=HM[seleccion][j][k]; 	

    				   if(par<PAR && temp[j][k]!=1 && temp[j][k]!=9)
    				   		temp[j][k]++;
  
    				}else
    					temp[j][k]=rand() % 9 + 1;
    				
    			}
    	
    	valor_temp=heuristica(temp);
    	pos_peor=peor_memoria(heuristica_HM,HMS);
    	peor=heuristica(HM[pos_peor]);

    	if(valor_temp<peor){
    		HM[pos_peor]=temp;
    		heuristica_HM[pos_peor]=valor_temp;
    	}
    
    }

    return HM[mejor_memoria(heuristica_HM,HMS)];
} 



int main(){
	vector < vector<int> > solucion; 
    vector < vector<int> > entrada(9, vector<int> (9) );
    srand (time(NULL));


    for (int i = 0; i < 9; ++i)
    	for (int j = 0; j < 9; ++j)
    		cin>>entrada[i][j];
    
    cout<<"Entrada Solucion"<<endl;
    imprimir_matriz(entrada);
    cout<<endl;

    int iteraciones=30000, HMS=100; float HMCR=0.7, PAR=0.1;
    
    solucion=sudoku(entrada,iteraciones,HMS,HMCR,PAR); 
    cout<<endl<<"Solucion óptima: "<<endl;
    imprimir_matriz(solucion);
    cout<<endl<<"valor heuristico: "<<heuristica(solucion)<<endl;


	return 0;
}