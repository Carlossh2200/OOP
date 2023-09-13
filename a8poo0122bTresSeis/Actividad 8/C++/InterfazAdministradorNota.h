#ifndef MENUADMINISTRADORNOTA_H_INCLUDED
#define MENUADMINISTRADORNOTA_H_INCLUDED

#include <fstream>
#include <sstream>
#include "AdministradorNota.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif // _WIN32

using namespace std;

class InterfazAdministradorNota{
static constexpr int C_0=0;
static constexpr int C_1=1;
enum{AGREGAR_NOTA=C_1,LISTAR_NOTA,MOSTRAR_NOTA,MODIFICAR_NOTA,ELIMINAR_NOTA,GUARDAR_NOTAS,
SALIR_NOTAS};
enum{MODIFICAR_DESCRIPCION_NOTA=C_1,SALIR_MENU_MODIFICAR_NOTA};
AdministradorNota* administradorNota;
















public:
    InterfazAdministradorNota(){
    administradorNota=new AdministradorNota;
    }
    void menuAdminNota(){
        bool seguirEjecutandoMenu=true;
        do{
            system(CLEAR);
            int opcion;
            cout << "1. Agregar nota" << endl;
            cout << "2. Listar notas" << endl;
            cout << "3. Mostrar detalles de una nota" << endl;
            cout << "4. Modificar una nota" << endl;
            cout << "5. Eliminar nota" << endl;
            cout << "6. Guardar cambios" << endl;
            cout << "7. Regresar al menu anterior" << endl;
            cout << "Opcion: ";
            cin >> opcion;
            cin.get();
            switch(opcion){
            case AGREGAR_NOTA:
                this->agregarNota();
                break;
            case LISTAR_NOTA:
                this->listarNotas();
                break;
            case MOSTRAR_NOTA:
                this->pedirCualNotaMostrar();
                break;
            case MODIFICAR_NOTA:
                this->menuModificarNota();
                break;
            case ELIMINAR_NOTA:
                this->eliminarNota();
                break;
            case GUARDAR_NOTAS:
                this->guardarNotasEnArchivo();
                break;
            case SALIR_NOTAS:
                seguirEjecutandoMenu=false;
                break;
            default:
                cout << "Opcion no valida..." << endl;
            }
        }while(seguirEjecutandoMenu);
};

        void capturarDatos(string* descripcion){
                cout << "Dame la descripcion: ";
                getline(cin, *descripcion);
            }

        void agregarNota(){
            string descripcion;
            cout << "Alta de nota" << endl;
            if (administradorNota->dameCuentaNotas()==administradorNota->dameMaxNotas()){
                administradorNota->agrandarArreglo();
            }
            else{
                capturarDatos(&descripcion);
                administradorNota->agregar(descripcion);
            }
        }

        void mostrarNota(int i){
            cout << "Registro " << i+C_1 << endl;
            cout << "Descripcion: " << administradorNota->dameDescripcionNota(i) << endl;
        }

        void listarNotas(){
            if (administradorNota->dameCuentaNotas()>C_0){
                for(int i=C_0;i<administradorNota->dameCuentaNotas();i++){
                    mostrarNota(i);
                }
            }
            else{
                cout << "No hay notas que listar" << endl;
            }
            pausar();
        }

        void pedirCualNotaMostrar(){
            int opcion;
            cout << "Que nota quieres mostrar (1 a " << administradorNota->dameCuentaNotas() <<
             ") :";
            cin >> opcion;
            opcion--;
            cin.get();
            this->mostrarNota(opcion);
            pausar();
        }

        void menuModificarNota(){
            int notaAModificar;
            int opcionMenuModificarNota;
            bool seguirEjecutandoSubMenu=true;
            if (administradorNota->dameCuentaNotas()>C_0){
                cout << "Modificar Nota" << endl << endl;
                cout << "Que nota quieres modificar (1 a " << administradorNota->dameCuentaNotas()
                << ") :";
                cin >> notaAModificar;
                notaAModificar--;
                cin.get();
                do{
                    cout << "Menu modificar nota" << endl;
                    cout << "1. Modificar descripcion" << endl;
                    cout << "2. Salir" << endl;
                    cout << "Opcion:";
                    cin >> opcionMenuModificarNota;
                    cin.get();
                    switch(opcionMenuModificarNota){
                    case MODIFICAR_DESCRIPCION_NOTA:
                        this->modificarDescripcionNota(notaAModificar);
                        break;
                    case SALIR_MENU_MODIFICAR_NOTA:
                        seguirEjecutandoSubMenu=false;
                        break;
                    default:
                        cout << "Opcion no valida" << endl;
                    }
                }while(seguirEjecutandoSubMenu);

            }
            else{
                cout << "No hay notas que modificar." << endl;
            }
            pausar();
        }

        void modificarDescripcionNota(int i){
            string nuevaDescripcion;
            cout << "Dame la nueva descripcion: ";
            getline(cin,nuevaDescripcion);
            administradorNota->modificar(i,nuevaDescripcion);

        }

        void eliminarNota(){
            int opcion;
            if (administradorNota->dameCuentaNotas()>C_0){
                cout << "Que nota quieres elimnar (1 a " << administradorNota->dameCuentaNotas()
                << ") :";
                cin >> opcion;
                opcion--;
                cin.get();
                administradorNota->eliminar(opcion);
                cout << "Nota eliminada." << endl;
            }
            else{
                cout << "No hay notas para eliminar" << endl;
            }
            pausar();
        }

        void guardarNotasEnArchivo(){
            if (administradorNota->dameCuentaNotas()>C_0){
                administradorNota->guardar();
            }
            else{
                cout << "No hay notas que guardar" << endl;
            }
            pausar();
        }
};

#endif // MENUADMINISTRADORNOTA_H_INCLUDED
