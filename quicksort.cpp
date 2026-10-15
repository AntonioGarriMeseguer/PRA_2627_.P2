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


int main()
{
    std::vector<int> enteros = {8, 3, 1, 7, 0, 10, 2};
    std::cout << "Original: ";
    for (int x : enteros)
        std::cout << x << ' ';
    if (!enteros.empty())
        QuickSort(enteros, 0, static_cast<int>(enteros.size()) - 1);
    std::cout << "\nOrdenado: ";
    for (int x : enteros)
        std::cout << x << ' ';
    int indiceInt = BusquedaBinaria(7, enteros, 0, static_cast<int>(enteros.size()) - 1);
    std::cout << "\nBusqueda de 7: " << indiceInt << "\n\n";


    std::vector<float> reales = {3.5f, 1.2f, 8.7f, 2.4f, 5.1f};
    std::cout << "Original: ";
    for (float x : reales)
        std::cout << x << ' ';
    if (!reales.empty())
        QuickSort(reales, 0, static_cast<int>(reales.size()) - 1);
    std::cout << "\nOrdenado: ";
    for (float x : reales)
        std::cout << x << ' ';
    int indiceFloat = BusquedaBinaria(2.4f, reales, 0, static_cast<int>(reales.size()) - 1);
    std::cout << "\nBusqueda de 2.4: " << indiceFloat << "\n\n";
	
    std::vector<char> caracteres = {'d', 'a', 'z', 'c', 'b'};
    std::cout << "Original: ";
    for (char x : caracteres)
        std::cout << x << ' ';
    if (!caracteres.empty())
        QuickSort(caracteres, 0,
                  static_cast<int>(caracteres.size()) - 1);
    std::cout << "\nOrdenado: ";
    for (char x : caracteres)
        std::cout << x << ' ';
    int indiceChar = BusquedaBinaria('c', caracteres, 0, static_cast<int>(caracteres.size()) - 1);
    std::cout << "\nBusqueda de 'c': " << indiceChar << '\n';

    return 0;
}

