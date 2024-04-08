#include "Celda.h"
#include <iostream>
using namespace std;

Celda::Celda()
{
}

// Constructor con parámetros
Celda::Celda(int coordenadaX, int coordenadaY, bool estadoMina)
{
    // Inicializa las coordenadas y el estado de la mina
    this->coordenadaX = coordenadaX;
    this->coordenadaY = coordenadaY;
    this->mina = estadoMina;
    this->minaDescubierta = false;
}

// Métodos para establecer y obtener las coordenadas X e Y
int Celda::setCoordenadaX(int coordenadaX)
{
    this->coordenadaX = coordenadaX;
}
int Celda::getCoordenadaX()
{
    return this->coordenadaX;
}
int Celda::setCoordenadaY(int coordenadaY)
{
    this->coordenadaY = coordenadaY;
}
int Celda::getCoordenadaY()
{
    return this->coordenadaY;
}

// Métodos para establecer y obtener el estado de la mina
bool Celda::setMina(bool estadoMina)
{
    // Si ya hay una mina, no se puede cambiar el estado
    if (this->getMina())
    {
        return false;
    }
    else{
        this->mina = estadoMina;
        return true;
    }
}
bool Celda::getMina()
{
    return this->mina;
}

// Métodos para establecer y obtener si la mina ha sido descubierta
bool Celda::setMinaDescubierta(bool minaDescubierta)
{
    this->minaDescubierta = minaDescubierta;
}
bool Celda::getMinaDescubierta()
{
    return this->minaDescubierta;
}

// Método para imprimir la información de la celda
void Celda::imprimirCelda()
{
    cout << "Celda en " << this->coordenadaX << ", " << this->coordenadaY << " con mina? " << this->mina << "\n";
}

