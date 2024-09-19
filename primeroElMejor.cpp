#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

// Estructura para representar un nodo del árbol
struct Node {
    int position; // Posición actual del block
    int heuristic; // Valor heurístico (distancia a la meta)

    Node(int pos, int h) : position(pos), heuristic(h) {}
};

// Comparador para la cola de prioridad
struct CompareHeuristic {
    bool operator()(Node const& n1, Node const& n2) {
        return n1.heuristic > n2.heuristic; // Priorizar menor heurística
    }
};

// Función heurística que estima la distancia a la meta
int calcularHeuristica(int currentPosition, int targetPosition) {
    return abs(currentPosition - targetPosition); // Distancia absoluta
}

// Función para realizar la búsqueda heurística "Primero el Mejor"
void busquedaPrimeroElMejor(int startPosition, int targetPosition) {
    priority_queue<Node, vector<Node>, CompareHeuristic> pq; // Cola de prioridad
    pq.push(Node(startPosition, calcularHeuristica(startPosition, targetPosition))); // Agregar nodo inicial

    while (!pq.empty()) {
        Node current = pq.top(); // Obtener el nodo con menor heurística
        pq.pop();

        cout << "Visitando posición: " << current.position << " (Heurística: " << current.heuristic << ")" << endl;

        // Verificar si hemos alcanzado la posición objetivo
        if (current.position == targetPosition) {
            cout << "¡Posición objetivo alcanzada!" << endl;
            return;
        }

        // Generar movimientos posibles (simulando desplazamientos)
        for (int move : {-1, 1}) { // Movimientos hacia la izquierda y derecha
            int newPosition = current.position + move;
            int newHeuristic = calcularHeuristica(newPosition, targetPosition);
            pq.push(Node(newPosition, newHeuristic)); // Agregar nuevo nodo a la cola
        }
    }

    cout << "No se pudo alcanzar la posición objetivo." << endl;
}

int main() {
    int startPosition, targetPosition;

    cout << "Ingrese la posición inicial del block: ";
    cin >> startPosition;

    cout << "Ingrese la posición objetivo del block: ";
    cin >> targetPosition;

    busquedaPrimeroElMejor(startPosition, targetPosition); // Ejecutar búsqueda

    return 0;
}
