const int NULL_EDGE = 0;
using namespace std; 

/* 

(40%) Se pide “transcribir” al español y con uso de “templates” la clase “GrafoTipo” 
(que ahora se llamará “GrafoTipo”), y probar su funcionamiento con la inserción de nodos y aristas.

*/
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

 private:
    T numVertices;
    T maxVertices;

    T* vertices;
    T **aristas;

    bool* marcas;
};

template <class T>
GrafoTipo<T>::GrafoTipo(T maxV){
   numVertices = 0;
   maxVertices = maxV;
   vertices = new T[maxV];
   aristas = new T*[maxV];
 
   for(T i = 0; i < maxV; i++)
     aristas[i] = new T[maxV];
 
   marcas = new bool[maxV];
}

template <class T>
GrafoTipo<T>::~GrafoTipo(){
   delete [] vertices;
 
   for(T i = 0; i < maxVertices; i++)
      delete [] aristas[i];
 
   delete [] aristas;
   delete [] marcas;
} 

template <class T>
void GrafoTipo<T>::agregarvertice(T vertice){
   vertices[numVertices] = vertice;

   for(T index = 0; index < numVertices; index++) {
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
T GrafoTipo<T>::ValorEs(T desdevertice, T avertice){
   T row, col;

   row = IndiceEs(vertices, desdevertice);
   col = IndiceEs(vertices, avertice);
   
   return aristas[row][col];
} 

template <class T>
T GrafoTipo<T>::IndiceEs(T *vertices, T vertice){
  for(T i = 0; i < numVertices; i++){
      if (vertices[i] == vertice)
          return i;
  }

  return -1;
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
