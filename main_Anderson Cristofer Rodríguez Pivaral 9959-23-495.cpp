#include <iostream> //permite imprimir valores por pantalla
#include <unistd.h> //permite la implementaci�n de ciertas funciones especiales del sistema
#include "Juego.h" //Se declaran los atributos de la clase y las firmas de los m�todos pero no con sus detalles
#include "Config.h" //Se declaran los atributos de la clase y las firmas de los m�todos pero no con sus detalles

using namespace std;//

int main()
{
    //Se definen las constantes
    const int FILASTABLERO = 5;
    const int COLUMNASTABLERO = 5;
    const int MINASENTABLERO = 3;
    const bool MODODESARROLLADOR = true;
    const int VIDASTABLERO = 3;
    //creaci�n de objeto llamado configuraci�nJuego de la clase Config, que almacena la configuraci�n del juego y los par�metros que recibe
    Config configuracionJuego(FILASTABLERO, COLUMNASTABLERO, MINASENTABLERO, MODODESARROLLADOR, VIDASTABLERO);
    //creaci�n de objeto llamado juego de la clase Juego, que recibe tres par�metros que se crean mediante a llamadas a los m�todos
    Juego juego(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero());
    srand(getpid());//se usa para la generaci�n de n�meros aleatorios utilizando el ID del proceso actual (PID) como semilla.
    //se declaran variables
    int opciones;
    bool repetir = true;
    do //ciclo que se ejecuta al menos una vez su bloque repetitivo
    {
        system("cls"); //limpiar pantalla
        //Imprime en pantalla los textos que se encuentran entre comillas, como una especie de men� para el juego
        cout << "\n\n\t\tBUSCA MINAS -Menu-" << endl; // \n sirve para saltar lineas
        cout << "\t\t-------------------"<< endl; // \t es un tabulador
        cout << "\t\t1. Configuaracion del Juego" << endl;
        cout << "\t\t2. Iniciar el Juego" << endl;
        cout << "\t\t3. Salir del Juego" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;
        switch (opciones) //estructura para validar las opciones
        {
        case 1: // cuando el valor sea 1
            {
                configuracionJuego.menuConfiguracion();//se llama al m�todo menuConfiguracion() del ojeto configuracionJuego
                break;
            }
        case 2: //cuando el valor sea 2
            {
                //toma tres argumentos: el n�mero de filas del tablero, el n�mero de columnas del tablero  y el modo de desarrollador del tablero
              	Juego juegoTemporal(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero());
                juegoTemporal.iniciar();//Se llama al m�todo iniciar() del objeto juegoTemporal.

                system("pause");//sirve para detener temporalmente la ejecuci�n del programa y esperar a que el usuario presione una tecla antes de continuar.
                break;
            }
        case 3: repetir = false; //cuando el valor sea 3 se saldr� del ciclo
                break;
        }
    } while (repetir); //complemento del do
    system("cls"); //limpiar pantalla
    return 0;
}
