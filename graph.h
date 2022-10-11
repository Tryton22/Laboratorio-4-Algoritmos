const int NULL_EDGE = 0;
using namespace std; 

template <class T>
class GrafoTipo {
  public:
    GrafoTipo(T);
    ~GrafoTipo();
    void agregarvertice(T);
    void agregararista(T, T, T);
    T ValorEs(T, T);
    T IndiceEs(T*, T);
    bool EsVacio();
    bool EsLleno(); 
    T TamanioGrafo();
    void BusquedaPrimeroEnProfundidad(T);
    

 private:
    int numVertices;
    int maxVertices;

    T* vertices;
    int **aristas;
    bool* visitado;

};

//constructor
template <class T>
GrafoTipo<T>::GrafoTipo(T maxV){
   numVertices = 0;
   //num max de vertices asigando por usuario
   maxVertices = maxV;
   //instancia dinamica 
   vertices = new T[maxV];
   aristas = new int*[maxV];
 
   for(int i = 0; i < maxV; i++)
     aristas[i] = new int[maxV];

   visitado = new bool[maxV]; 
}

//constructor por defecto
template <class T>
GrafoTipo<T>::~GrafoTipo(){
   delete [] vertices;
 
   for(int i = 0; i < maxVertices; i++)
      delete [] aristas[i];
 
   delete [] aristas;
   delete [] visitado;
} 

template <class T>
void GrafoTipo<T>::agregarvertice(T vertice){
  //asigna valor 'vertice' a ultimo vertice de list vertices
   vertices[numVertices] = vertice;

  //aristas tienen valor null = 0
  //se agrega arista NULL
   for(int index = 0; index < numVertices; index++) {
     aristas[numVertices][index] = NULL_EDGE;
     aristas[index][numVertices] = NULL_EDGE;
   }
   
   numVertices++;
}

template <class T>
void GrafoTipo<T>::agregararista(T desdevertice, T avertice, T valor){
   T row, col;

   row = IndiceEs(vertices, desdevertice);
   col = IndiceEs(vertices, avertice);
   aristas[row][col] = valor;
}  

template <class T>
T GrafoTipo<T>::IndiceEs(T *vertices, T vertice){
  for(int i = 0; i < numVertices; i++){
      if (vertices[i] == vertice)
          // retorna indice de vertice
          return i;
  }

  return -1;
}

template <class T>
T GrafoTipo<T>::ValorEs(T desdevertice, T avertice){
   T row, col;

   row = IndiceEs(vertices, desdevertice);
   col = IndiceEs(vertices, avertice);
   
   return aristas[row][col];
}

template <class T>
bool GrafoTipo<T>::EsLleno(){
  if (numVertices == maxVertices)
      return true;
  
  return false;
}

template <class T>
bool GrafoTipo<T>::EsVacio(){
  if (numVertices == 0)
      return true;
  
  return false;
}

template <class T>
T GrafoTipo<T>::TamanioGrafo(){
  return numVertices;
}

template <class T>
void GrafoTipo<T>::BusquedaPrimeroEnProfundidad(T v){

    // marca el nodo actual como visitado
    // se imprime nodo
    visitado[v] = true;
    cout << v << "-";

    /*
    PSEUDOCODIGO


    indice = EsIndice(vertices, v);
    ciclo (subindice = 0; subindice < numVertices; subindice ++){
      si aristas[indice, subindice] != NULL_EDGE y subdindice no ha sido visitado
        // agrega arista a lista de aristas_deSalida de vertice evaluado
        // en un contenedor 'map', se inserta arista como key
        // valor asociado a key sera el subindice de arista respectiva
        
    }
    si longuitud aristas_deSalida > 1
      // se ingresa a lista de aristas_deSalida
      // se selecciona la arista de valor menor mediante comparacion
      // se eliminan elementos de mayor valor en lista aristas_deSalida y 'map'
      // queda un unico elemento en lista aristas_deSalida, mismo caso en 'map'
    
    aristas_salida se vacia
    map se vacia
    si longuitud aristas_deSalida != 0
        // se realiza recursion

  
    */   
    
}