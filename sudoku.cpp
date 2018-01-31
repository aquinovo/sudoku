#include  "funciones.cpp"



vector < vector<int> > sudoku(vector < vector<int> > entrada,int iteraciones,int HMS,float HCMR,float PAR){
	vector < vector<int> > solucion;
	map<int, vector < vector<int> > > HM;
	map<int, float > heuristica_HM;
   
    HM=inicializar_memoria(entrada,HMS);
    heuristica_HM=evaluar_HM(HM,HMS);
    

    for (int i = 0; i < HMS; ++i){
    	imprimir_matriz(HM[i]);
    	cout<<endl;
    	cout<<heuristica_HM[i]<<endl;
    }

    return solucion;
} 



int main(){
    vector < vector<int> > entrada(9, vector<int> (9) );


    for (int i = 0; i < 9; ++i)
    	for (int j = 0; j < 9; ++j)
    		cin>>entrada[i][j];

    imprimir_matriz(entrada);
    cout<<endl;

    int iteraciones=300, HMS=50; float HMCR=0.7, PAR=0.1;
    


    sudoku(entrada,iteraciones,HMS,HMCR,PAR); 
    	
	return 0;
}