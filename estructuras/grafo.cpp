#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Grafo {
private:
    int vertices;  // Número de vértices
    list<int>* adyacencia;  // Lista de adyacencia para representar el grafo

public:
    // Constructor
    Grafo(int V) {
        vertices = V;
        adyacencia = new list<int>[V];
    }

    // Método para agregar una arista
    void agregarArista(int v, int w) {
        adyacencia[v].push_back(w);
    }

    // Búsqueda en profundidad (DFS)
    void DFS(int inicio) {
        // Crear un vector para marcar los vértices visitados
        vector<bool> visitado(vertices, false);

        // Usamos un stack para almacenar los vértices a visitar
        stack<int> pila;

        // Iniciamos desde el vértice de inicio
        pila.push(inicio);

        while (!pila.empty()) {
            // Sacamos un vértice de la pila
            int v = pila.top();
            pila.pop();

            // Si el vértice no ha sido visitado
            if (!visitado[v]) {
                cout << v << " ";  // Imprimimos el vértice
                visitado[v] = true;
            }

            // Añadimos todos los vecinos no visitados
            for (auto adj : adyacencia[v]) {
                if (!visitado[adj]) {
                    pila.push(adj);
                }
            }
        }
    }

    // Búsqueda en anchura (BFS)
    void BFS(int inicio) {
        // Crear un vector para marcar los vértices visitados
        vector<bool> visitado(vertices, false);

        // Usamos una cola para almacenar los vértices a visitar
        queue<int> cola;

        // Comenzamos con el vértice de inicio
        cola.push(inicio);
        visitado[inicio] = true;

        while (!cola.empty()) {
            // Sacamos un vértice de la cola
            int v = cola.front();
            cola.pop();

            cout << v << " ";  // Imprimimos el vértice

            // Añadimos todos los vecinos no visitados
            for (auto adj : adyacencia[v]) {
                if (!visitado[adj]) {
                    cola.push(adj);
                    visitado[adj] = true;
                }
            }
        }
    }
};

// Función principal
int main() {
    Grafo g(5);  // Creamos un grafo con 5 vértices

    // Agregar aristas
    g.agregarArista(0, 1);
    g.agregarArista(0, 2);
    g.agregarArista(1, 2);
    g.agregarArista(2, 0);
    g.agregarArista(2, 3);
    g.agregarArista(3, 3);

    cout << "Busqueda en profundidad (DFS) comenzando desde el vertice 2: ";
    g.DFS(2);  // Comenzar DFS desde el vértice 2
    cout << endl;

    cout << "Busqueda en anchura (BFS) comenzando desde el vertice 2: ";
    g.BFS(2);  // Comenzar BFS desde el vértice 2
    cout << endl;

    return 0;
}