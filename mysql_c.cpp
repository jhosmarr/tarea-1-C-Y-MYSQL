// mysql_c.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "cliente.h"
using namespace std;
int q_estado;

int main()
{
    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "Marroquin*5008", "db_empresa", 3306, NULL, 0);
    if (conectar) {
       // cout << "conexion Exitosa..." << endl;
       /*/string cliente;
        cout << "ingrese clientes:";
        cin >> clientes;
            /*string insert = "insert into clientes(clientes) values('" + cliente + "')";
        const char* i = insert.c_str();
        q_estado = mysql_query(conectar,i);
        if (!q_estado) {
            cout << "ingreso Exitosa..." << endl;
        }
        else {
            cout << "xxx Error al Ingresar xxx" << endl;
        }*/
        /string consulta = "select * from cliente";
        const char* c = consulta.c_str();
        q_estado = mysql_query(conectar, c);
        if (!q_estado) {
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado)){
                cout << fila[0] << "," << fila[1] << endl;
            }
        }
        else {
            cout << "xxx Error al consultar xxx" << endl;
        }
    }
    cliente c= cliente();
    c.leer();
    else {
        cout << "Error en la conexion..." << endl;
    }
 
    cout << "Hello World!\n";
    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
