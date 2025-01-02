#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Grafo {
private:
    int vertices;  // Numero de vertices
    list<int>* adyacencia;  // Lista de adyacencia para representar el grafo

public:
    // Constructor
    Grafo(int V) {
        vertices = V;
        adyacencia = new list<int>[V];
    }

    // Metodo para agregar una arista
    void agregarArista(int v, int w) {
        adyacencia[v].push_back(w);
    }

    // Busqueda en profundidad (DFS)
    void DFS(int inicio) {
        // Crear un vector para marcar los vertices visitados
        vector<bool> visitado(vertices, false);

        // Usamos un stack para almacenar los vertices a visitar
        stack<int> pila;

        // Iniciamos desde el vertice de inicio
        pila.push(inicio);

        while (!pila.empty()) {
            // Sacamos un vertice de la pila
            int v = pila.top();
            pila.pop();

            // Si el vertice no ha sido visitado
            if (!visitado[v]) {
                cout << v << " ";  // Imprimimos el vertice
                visitado[v] = true;
            }

            // Anadimos todos los vecinos no visitados
            for (auto adj : adyacencia[v]) {
                if (!visitado[adj]) {
                    pila.push(adj);
                }
            }
        }
    }

    // Busqueda en anchura (BFS)
    void BFS(int inicio) {
        // Crear un vector para marcar los vertices visitados
        vector<bool> visitado(vertices, false);

        // Usamos una cola para almacenar los vertices a visitar
        queue<int> cola;

        // Comenzamos con el vertice de inicio
        cola.push(inicio);
        visitado[inicio] = true;

        while (!cola.empty()) {
            // Sacamos un vertice de la cola
            int v = cola.front();
            cola.pop();

            cout << v << " ";  // Imprimimos el vertice

            // Anadimos todos los vecinos no visitados
            for (auto adj : adyacencia[v]) {
                if (!visitado[adj]) {
                    cola.push(adj);
                    visitado[adj] = true;
                }
            }
        }
    }
};

// Funcion principal
int main() {
    Grafo g(5);  // Creamos un grafo con 5 vertices

    // Agregar aristas
    g.agregarArista(0, 1);
    g.agregarArista(0, 2);
    g.agregarArista(1, 2);
    g.agregarArista(2, 0);
    g.agregarArista(2, 3);
    g.agregarArista(3, 3);

    cout << "Busqueda en profundidad (DFS) comenzando desde el vertice 2: ";
    g.DFS(2);  // Comenzar DFS desde el vertice 2
    cout << endl;

    cout << "Busqueda en anchura (BFS) comenzando desde el vertice 2: ";
    g.BFS(2);  // Comenzar BFS desde el vertice 2
    cout << endl;

    return 0;
}
