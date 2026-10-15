#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm> // Para std::swap

using namespace std;

//  BÚSQUEDA BINARIA (Divide y Vencerás)
template <typename T>
int BusquedaBinaria(const T& X, const vector<T>& V, int ini, int fin) {
    if (ini > fin) {
        return -1; // No se encuentra en el array
    }
    
    int medio = (ini + fin) / 2;
    
    if (V[medio] == X) {
        return medio;
    } 
    else if (V[medio] > X) {
        return BusquedaBinaria(X, V, ini, medio - 1);
    } 
    else {
        return BusquedaBinaria(X, V, medio + 1, fin);
    }
}


// QUICKSORT Y PARTICIÓN (Divide y Vencerás)

template <typename T>
int Partition(vector<T>& V, int ini, int fin) {
    T x = V[fin];
    int i = ini;
    
    for (int j = ini; j < fin; ++j) {
        if (V[j] <= x) {
            swap(V[i], V[j]);
            i++;
        }
    }
    swap(V[i], V[fin]);
    return i;
}

template <typename T>
void QuickSort(vector<T>& V, int ini, int fin) {
    if (ini < fin) {
        int pivot = Partition(V, ini, fin);
        QuickSort(V, ini, pivot - 1);
        QuickSort(V, pivot + 1, fin);
    }
}


//  FUNCIÓN PRINCIPAL (MAIN)
int main() {
   
    vector<int> V = {9, -4, 3, 6, 1, 5};

    cout << "Vector original: ";
    for (int val : V) cout << val << " ";
    cout << endl;

    // Medir tiempo con <chrono>
    auto inicio = chrono::high_resolution_clock::now();
    
    QuickSort(V, 0, V.size() - 1);
    
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duracion = fin - inicio;

    cout << "Vector ordenado: ";
    for (int val : V) cout << val << " ";
    cout << endl;
    
    cout << "Tiempo de ejecucion de QuickSort: " << duracion.count() << " ms" << endl;

  
    int elementoBuscado = 3;
    int posicion = BusquedaBinaria(elementoBuscado, V, 0, V.size() - 1);

    if (posicion != -1) {
        cout << "Elemento " << elementoBuscado << " encontrado en la posicion: " << posicion << endl;
    } else {
        cout << "Elemento " << elementoBuscado << " no encontrado en el vector." << endl;
    }

    return 0;
}

