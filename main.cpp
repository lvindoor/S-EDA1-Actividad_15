#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Opciones Menu */
enum {
    AGREGAR_FINAL = 1,
    MOSTRAR,
    INICIALIZAR,
    FRENTE,
    ULTIMO,
    ORDENAR,
    INSERTAR,
    ELIMINAR,
    ELIMINAR_ULTIMO,
    SALIR
};

int main() {

    vector<string> cadenas; // declaramos vector
    int opc; // creamos una opcion para el menu
    string tempCadena; // una cadena temporal
    size_t p; // declaramos una variable de tipo posición
    bool continueProgram = true; // comenzamos el menu ciclico

    do {

        cout << endl;
        cout << "\t--------------------------------------------" << endl;
        cout << "\t                  MENU                     " << endl;
        cout << "\t--------------------------------------------" << endl << endl;
        cout << "\t1-. Agregar al Final" << endl;
        cout << "\t2-. Mostrar" << endl;
        cout << "\t3-. Inicializar" << endl;
        cout << "\t4-. Frente" << endl;
        cout << "\t5-. Ultimo" << endl;
        cout << "\t6-. Ordenar" << endl;
        cout << "\t7-. Insertar" << endl;
        cout << "\t8-. Eliminar" << endl;
        cout << "\t9-. Eliminar Ultimo" << endl;
        cout << "\t10-. Salir" << endl;
        cout << endl << "\topcion : ";
        cin >> opc; cin.ignore();
        
        /* Evaluamos */
        switch(opc) {

        case AGREGAR_FINAL:
            cout << "\tCadena: "; // pedimos cadena
            getline(cin,tempCadena); // guardamos en cadena temporal
            
            cadenas.push_back(tempCadena); // agregamos al vector
            break;
        
        case MOSTRAR:
            cout << endl;
            for (size_t i = 0; i < cadenas.size(); i++) { // Recorremos vector
                if(i == 0) { // ¿Si es primera posicion?
                    cout << "\t"; // imprimimos un tab
                }
                cout << cadenas[i] << ", "; // mostramos en posicion i
            }
            cout << endl;
            break;

        case INICIALIZAR:
            size_t n; // creamos una variable de tamaño

            cout << "\tDimension de vector : ";
            cin >> n; cin.ignore(); // guardamos el nuevo tamaño
            cout << "\tInicializar con : ";
            getline(cin,tempCadena); // guardamos la cadena a inicializar

            cadenas = vector<string>(n, tempCadena); // declaramos el cambio en el vector
            break;

        case FRENTE:
            if (cadenas.empty()) { // ¿Cadena vacia?
                cout << "\tvector esta vacio" << endl;
            } else {
                cout << "\tValor : " << cadenas.front() << endl; // imprimir el frente
            }
            break;
        
        case ULTIMO:
            if (cadenas.empty()) { // ¿Cadena vacia?
                cout << "\tvector esta vacio" << endl;
            } else {
                cout << "\tValor : " << cadenas.back() << endl; // imprimir el ultimo
            }
            break;
        
        case ORDENAR:
            // sort(cadenas.begin(), cadenas.end()); // ordenación: simple
            sort(cadenas.begin(), cadenas.end(), greater<string>()); // ordenación: como ordenar (greater = descendente)
            break;

        case INSERTAR:

            cout << "\tPosicion a insertar : ";
            cin >> p; cin.ignore();
            cout << "\tCadena : ";
            getline(cin,tempCadena);

            if (p >= cadenas.size()) { // ¿Posición valida?
                cout << "\tposicion no valida" << endl;
            } else { 
                cadenas.insert(cadenas.begin()+p, tempCadena); // insertamos en p
            }
            break;

        case ELIMINAR:
            cout << "\tPosicion para eliminar : ";
            cin >> p; cin.ignore();

            if (p >= cadenas.size()) { // ¿Posición valida?
                cout << "\tposicion no valida" << endl;
            } else {
                cadenas.erase(cadenas.begin()+p); // eliminamos en p
            }
            break;

        case ELIMINAR_ULTIMO:
            if (cadenas.empty()) { // ¿Esta vacio?
                cout << "\tvector esta vacio" << endl;
            } else {
                cadenas.pop_back(); // eliminamos el ultimo
            }
            break;

        case SALIR:
            continueProgram = false; // cerramos ciclo
            break;

        default:
            cout << "\tOpcion Invalida" << endl;
            break;
        }
    } while (continueProgram);

    return 0;
}