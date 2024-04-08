#include "Tablero.h"
#include <sstream>
#include <iostream>

using namespace std;

// Constructor por defecto de la clase Tablero.
Tablero::Tablero()
{
}

// Constructor con parámetros de la clase Tablero para inicializar un tablero con una altura, ancho y modo específicos.
Tablero::Tablero(int alturaTablero, int anchoTablero, bool modoDesarrollador)
{
    // Asignación de los valores de altura, ancho y modo del tablero a las variables miembro.
    this->alturaTablero = alturaTablero;
    this->anchoTablero = anchoTablero;
    this->modoDesarrollador = modoDesarrollador;

    int x, y;
    // Inicialización del tablero con celdas no minadas.
    for (y = 0; y < this->alturaTablero; y++)
    {
        vector<Celda> fila;
        for (x = 0; x < this->anchoTablero; x++)
        {
            fila.push_back(Celda(x, y, false));
        }
        this->contenidoTablero.push_back(fila);
    }
}

// Obtiene la altura del tablero.
int Tablero::getAlturaTablero()
{
    return this->alturaTablero;
}

// Establece una nueva altura para el tablero.
int Tablero::setAlturaTablero(int alturaTablero)
{
    this->alturaTablero = alturaTablero;
}

// Obtiene el ancho del tablero.
int Tablero::getAnchoTablero()
{
    return this->anchoTablero;
}

// Establece un nuevo ancho para el tablero.
int Tablero::setAnchoTablero(int anchoTablero)
{
    this->anchoTablero = anchoTablero;
}

// Obtiene el estado del modo desarrollador.
bool Tablero::getModoDesarrollador()
{
    return this->modoDesarrollador;
}

// Establece el estado del modo desarrollador.
bool Tablero::setModoDesarrollador(bool modoDesarrollador)
{
    this->modoDesarrollador = modoDesarrollador;
}

// Devuelve la representación gráfica de una mina o una celda en una coordenada específica.
string Tablero::getRepresentacionMina(int coordenadaX, int coordenadaY)
{
    Celda celdaTemporal = this->contenidoTablero.at(coordenadaY).at(coordenadaX);
    // Verifica si la celda debe mostrarse como mina o número de minas cercanas.
    if (celdaTemporal.getMinaDescubierta() || this->modoDesarrollador)
    {
        if (celdaTemporal.getMina())
        {
            return "*"; // Mina.
        }
        else
        {
            int cantidadCelda = this->minasCercanas(coordenadaY, coordenadaX);
            stringstream ss;
            ss << cantidadCelda;
            string cantidadCeldaString = ss.str();
            return cantidadCeldaString; // Número de minas cercanas.
        }
    }
    else
    {
        return "?"; // Celda no descubierta.
    }
}

// Calcula el número de minas cercanas a una celda dada.
int Tablero::minasCercanas(int filaTablero, int columnaTablero)
{
    int contadorTablero = 0;
    // Determina los límites de búsqueda de minas cercanas.
    int filaInicioTablero, filaFinTablero, columnaInicioTablero, columnaFinTablero;
    filaInicioTablero = max(filaTablero - 1, 0);
    filaFinTablero = min(filaTablero + 1, this->alturaTablero - 1);
    columnaInicioTablero = max(columnaTablero - 1, 0);
    columnaFinTablero = min(columnaTablero + 1, this->anchoTablero - 1);

    // Cuenta las minas en las celdas adyacentes.
    for (int m = filaInicioTablero; m <= filaFinTablero; m++)
    {
        for (int l = columnaInicioTablero; l <= columnaFinTablero; l++)
        {
            if (this->contenidoTablero.at(m).at(l).getMina())
            {
                contadorTablero++;
            }
        }
    }
    return contadorTablero;
}

// Imprime el separador del encabezado del tablero.
void Tablero::imprimirSeparadorEncabezado()
{
    for (int m = 0; m <= this->anchoTablero; m++)
    {
        cout << "----";
        if (m == this->anchoTablero - 1)
        {
            cout << "-";
        }
    }
    cout << "\n";
}

// Imprime el separador entre las filas del tablero.
void Tablero::imprimirSeparadorFilas()
{
    for (int m = 0; m <= this->anchoTablero; m++)
    {
        cout << (m == 0 ? "|---" : "+---");
        if (m == this->anchoTablero)
        {
            cout << "+";
        }
    }
    cout << "\n";
}

// Imprime el encabezado del tablero.
void Tablero::imprimirEncabezado()
{
    this->imprimirSeparadorEncabezado();
    cout << "|   ";
    for (int l = 0; l < this->anchoTablero; l++)
    {
        cout << "| " << l + 1 << " ";
        if (l == this->anchoTablero - 1)
        {
            cout << "|";
        }
    }
    cout << "\n";
}

// Imprime el tablero completo, incluyendo todas las celdas y separadores.
void Tablero::imprimir()
{
    this->imprimirEncabezado();
    this->imprimirSeparadorEncabezado();
    for (int y = 0; y < this->alturaTablero; y++)
    {
        cout << "| " << y + 1 << " ";
        for (int x = 0; x < this->anchoTablero; x++)
        {
            cout << "| " << this->getRepresentacionMina(x, y) << " ";
            if (x == this->anchoTablero - 1)
            {
                cout << "|";
            }
        }
        cout << "\n";
        this->imprimirSeparadorFilas();
    }
}

// Coloca una mina en una celda específica del tablero.
bool Tablero::colocarMina(int x, int y)
{
    return this->contenidoTablero.at(y).at(x).setMina(true);
}

// Marca una celda como descubierta, revelando si contiene una mina o no.
bool Tablero::descubrirMina(int x, int y)
{
    this->contenidoTablero.at(y).at(x).setMinaDescubierta(true);
    return this->contenidoTablero.at(y).at(x).getMina();
{
        return false;
    }

    // Si la celda no tiene una mina, retorna true (es seguro continuar).
    return true;
}

// Cuenta el número de celdas que no contienen minas y que aún no han sido descubiertas.
// Este valor es útil para determinar si el jugador ha ganado.
int Tablero::contarCeldasSinMinasYSinDescubrir()
{
    int x, y, contador = 0; // Inicializa un contador para las celdas.

    // Itera a través de todas las celdas del tablero.
    for (y = 0; y < this->alturaTablero; y++)
    {
        for (x = 0; x < this->anchoTablero; x++)
        {
            // Obtiene una celda temporal para la evaluación.
            Celda celdaTemporal = this->contenidoTablero.at(y).at(x);

            // Si la celda no ha sido descubierta y no contiene una mina,
            // incrementa el contador.
            if (!celdaTemporal.getMinaDescubierta() && !celdaTemporal.getMina())
            {
                contador++;
            }
        }
    }

    // Retorna el total de celdas sin minas y sin descubrir.
    // Este número ayuda a determinar si el jugador ha despejado todas las celdas sin minas.
    return contador;
}
