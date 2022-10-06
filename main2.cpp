#include <iostream> 
#include "graph.h" 

/* (40%) Se pide “transcribir” al español y con uso de “templates” la clase “GraphType” 
(que ahora se llamará “GrafoTipo”), y probar su funcionamiento con la inserción de nodos y aristas.


*/

using namespace std; 

int main() { 
    GrafoTipo<int> x(10); 

    cout << "Vació? " << x.EsVacio() << " - " << x.TamanioGrafo() << endl;
    
    x.agregarvertice(10);
    x.agregarvertice(20);
    cout << "\nVació? " << x.EsVacio() << " - " << x.TamanioGrafo() << endl;
    x.agregararista(10, 20, 100);
    cout << "Peso: " << x.ValorEs(10, 20) << endl;
    x.agregarvertice(30);
    cout << "\nVació? " << x.EsVacio() << " - " << x.TamanioGrafo() << endl;
    x.agregararista(10, 30, 200);
    cout << "Peso: " << x.ValorEs(10, 30) << endl;
    
} 