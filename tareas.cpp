#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Tarea {
    string descripcion;
    bool completada;

    Tarea(string desc) {
        descripcion = desc;
        completada = false;
    }
};

// Función para mostrar el menú
void mostrarMenu() {
    cout << "\n--- Menu de Gestion de Tareas ---" << endl;
    cout << "1. Agregar nueva tarea" << endl;
    cout << "2. Ver todas las tareas" << endl;
    cout << "3. Marcar tarea como completada" << endl;
    cout << "4. Eliminar tareas completadas" << endl;
    cout << "5. Salir" << endl;
    cout << "Selecciona una opcion: ";
}

// Función para agregar una nueva tarea
void agregarTarea(vector<Tarea>& tareas) {
    cout << "\nIntroduce la descripcion de la tarea: ";
    string desc;
    cin.ignore();
    getline(cin, desc);
    tareas.push_back(Tarea(desc));
    cout << "Tarea agregada exitosamente.\n";
}

// Función para mostrar todas las tareas
void mostrarTareas(const vector<Tarea>& tareas) {
    if (tareas.empty()) {
        cout << "\nNo hay tareas registradas.\n";
        return;
    }

    cout << "\n--- Lista de Tareas ---" << endl;
    for (size_t i = 0; i < tareas.size(); ++i) {
        cout << i + 1 << ". " << tareas[i].descripcion;
        if (tareas[i].completada) {
            cout << " (Completada)";
        }
        cout << endl;
    }
}

// Función para marcar una tarea como completada
void completarTarea(vector<Tarea>& tareas) {
    mostrarTareas(tareas);
    if (tareas.empty()) return;

    cout << "\nSelecciona el numero de la tarea que quieres marcar como completada: ";
    int indice;
    cin >> indice;

    if (indice > 0 && indice <= tareas.size()) {
        tareas[indice - 1].completada = true;
        cout << "Tarea marcada como completada.\n";
    } else {
        cout << "Indice invalido.\n";
    }
}

// Función para eliminar tareas completadas
void eliminarTareasCompletadas(vector<Tarea>& tareas) {
    auto it = tareas.begin();
    while (it != tareas.end()) {
        if (it->completada) {
            it = tareas.erase(it);
        } else {
            ++it;
        }
    }
    cout << "\nTareas completadas eliminadas.\n";
}

int main() {
    vector<Tarea> tareas;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarTarea(tareas);
                break;
            case 2:
                mostrarTareas(tareas);
                break;
            case 3:
                completarTarea(tareas);
                break;
            case 4:
                eliminarTareasCompletadas(tareas);
                break;
            case 5:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida. Intenta nuevamente.\n";
        }

    } while (opcion != 5);

    return 0;
}
