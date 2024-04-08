#include <iostream>
#include <unistd.h>
//Gestiona la configuraci�n del tablero
#include "Config.h"
using namespace std;

//inicializa los atributos con los valores proporcionados.
Config::Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero)
{
    //representa el n�mero de filas del tablero.
    this->filasTablero = filasTablero;
    // representa el n�mero de columnas del tablero.
    this->columnasTablero = columnasTablero;
    // representa el n�mero de minas en el tablero.
    this->minasTablero = minasTablero;
    // indica si el juego est� en modo desarrollador o no.
    this->modoDesarrolladorTablero = modoDesarrolladorTablero;
    // representa el n�mero de vidas del jugador.
    this->vidasTablero = vidasTablero;
}
//muestra un men� para que el jugador pueda configurar los par�metros del juego.
void Config::menuConfiguracion()
{
    int opciones;
    int valorIngresado;
    bool repetir = true;
    do
    {
        system("cls");
        cout << "\n\n\t\tCONFIGURACION ACTUAL -Menu-" << endl;
        cout << "\t\t-------------------"<< endl;
        cout << "\t\t1. Filas del Tablero ----> " << this->getfilasTablero() << endl;
        cout << "\t\t2. Columnas del Tablero -> " << this->getcolumnasTablero() << endl;
        cout << "\t\t3. Minas del Tablero ----> " << this->getminasTablero() << endl;
        cout << "\t\t4. Modo del Juego -------> " << this->getmodoDesarrolladorTablero() << endl;
        cout << "\t\t5. Vidas del Jugador ----> " << this->getvidasTablero() << endl;
        cout << "\t\t6. Regresar al menu general" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;
        if (opciones!=6)
        {
            cout << "\n\tIngrese el valor que desea cambiar: ";
            cin >> valorIngresado;
        }
        switch (opciones)
        {
        case 1:
            {
                this->setfilasTablero(valorIngresado);
                cout << "Filas del Tablero actualizadas" << endl;
                break;
            }
        case 2:
            {
                this->setcolumnasTablero(valorIngresado);
                cout << "Columnas del Tablero actualizadas" << endl;
                break;
            }
        case 3:
            {
                this->setminasTablero(valorIngresado);
                cout << "Minas del Tablero actualizadas" << endl;
                break;
            }
        case 4:
            {
                this->setmodoDesarrolladorTablero(valorIngresado);
                cout << "Modo del Juego actualizado" << endl;
                break;
            }
        case 5:
            {
                this->setvidasTablero(valorIngresado);
                cout << "Vidas del Juego actualizadas" << endl;
                break;
            }
        case 6: repetir = false;
                break;
        }
        system("pause");
    } while (repetir);
}
//M�todo que devuelve el n�mero de filas del tablero.
int Config::getfilasTablero()
{
    return this->filasTablero;
}
// M�todo que establece el n�mero de filas del tablero.
int Config::setfilasTablero(int filasTablero)
{
    this->filasTablero=filasTablero;
}
//devuelve el n�mero de columnas del tablero.
int Config::getcolumnasTablero()
{
    return this->columnasTablero;
}
//establece el n�mero de columnas del tablero.
int Config::setcolumnasTablero(int columnasTablero)
{
    this->columnasTablero=columnasTablero;
}
//devuelve el n�mero de minas del tablero.
int Config::getminasTablero()
{
    return this->minasTablero;
}
//establece el n�mero de minas del tablero.
int Config::setminasTablero(int minasTablero)
{
    this->minasTablero=minasTablero;
}
//devuelve si el juego est� en modo desarrollador o no.
bool Config::getmodoDesarrolladorTablero()
{
    return this->modoDesarrolladorTablero;
}
//M�todo que establece si el juego est� en modo desarrollador o no
bool Config::setmodoDesarrolladorTablero(bool modoDesarrolladorTablero)
{
    this->modoDesarrolladorTablero=modoDesarrolladorTablero;
}
//M�todo que devuelve el n�mero de vidas del jugador.
int Config::getvidasTablero()
{
    return this->vidasTablero;
}
//M�todo que establece el n�mero de vidas del jugador.
int Config::setvidasTablero(int vidasTablero)
{
    this->vidasTablero=vidasTablero;
}


