//TresSeis
//Actividad 8
//Tiempo=04:30
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <clocale>
#include "Materia.h"
#include "Evaluacion.h"
#include "Tarea.h"
#include "Agenda.h"
#include "Util.h"
#include "Nota.h"
#include "AdministradorNota.h"
#include "InterFazAdministradorNota.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif // _WIN32
using namespace std;

#define NOMBRE_ARCHIVO "Actividad 5.txt"
#define NOMBRE_ARCHIVO_AGENDA "Actividad 6 Recordatorios.txt"
#define DELIMITADOR_CAMPOS '|'
#define SALTO_DE_LINEA "\n"
#define PORCENTAJE_TAREAS 7
#define PORCENTAJE_ACTIVIDADES 63
#define PORCENTAJE_EXAMENES 30
#define TOTAL_ASISTENCIAS 34
#define RETARDOS_POR_FALTA 3
#define TOTAL_TAREAS 10
#define TOTAL_ACTIVIDADES 9
#define TOTAL_EXAMENES 3
#define MINIMO_ASISTENCIA 80
#define MINIMA_CALIF 60
#define MINIMO_PORCENTAJE_ASISTENCIA 28.8
#define C_0 0
#define C_1 1
#define C_2 2
#define C_3 3
#define C_100 100
#define C_300 300
#define C_900 900
#define TEXTO_1 "primer"
#define TEXTO_2 "segundo"
#define TEXTO_3 "tercer"
#define MAX_MATERIAS 3
#define MAX_TAREAS_INICIAL 3
#define MAX_RECORDATORIOS_INICIAL 3

enum{EVALUACION_CURSO=C_1,GESTION_MATERIAS,CONTROL_TAREAS,CONTROL_AGENDA,NOTAS,SALIR};

enum {AGREGAR_MATERIA=C_1,LISTAR_MATERIA,MOSTRAR_DETALLES,MODIFICAR_MATERIA,ELIMINAR_MATERIA,
      GUARDAR,REGRESAR};

enum{MODIF_MATERIA=C_1,MODIF_NOMBRE,MODIF_ACRONIMO,MODIF_NOMBRE_PROFESOR,MODIF_DIAS,
MODIF_HORA_INICIO,MODIF_HORA_FIN,SALIR_MODIFICAR};

enum{AGREGAR_TAREA=C_1,LISTAR_TAREA,MOSTRAR_TAREA,MODIFICAR_TAREA,ELIMINAR_TAREA,GUARDAR_TAREA,
MENU_ANTERIOR};

enum{MODIFICAR_TAREA_COMPLETA=C_1,MODIFICAR_ASUNTO_TAREA,MODIFICAR_DESC_TAREA,
MODIFICAR_MATERIA_TAREA,SALIR_MODIFICAR_TAREA};

enum{AGREGAR_RECORDATORIO=C_1,LISTAR_RECORDATORIOS,MOSTRAR_DETALLES_RECORDATORIO,
MODIFICAR_RECORDATORIO,ELIMINAR_RECORDATORIO,GUARDAR_RECORDATORIOS,SALIR_MENU_RECORDATORIOS};

enum{MODIFICAR_RECORDATORIO_COMPLETO=C_1,MODIFICAR_ASUNTO_RECORDATORIO,MODIFICAR_TIPO_RECORDATORIO,
MODIFICAR_FECHA_RECORDATORIO,MODIFICAR_HORA_RECORDATORIO,SALIR_SUBMENU_RECORDATORIO};

int cuentaRegistros;
int cuentaTareas;
int cuentaRecordatorios;

Materia* materias[MAX_MATERIAS];
Tarea** tareas;
int maxTareas=MAX_TAREAS_INICIAL;
Agenda** recordatorios;
int maxRecordatorios=MAX_RECORDATORIOS_INICIAL;











ofstream archivo;
stringstream reporteRegistro;
string reporteRegistroStr;

int menu();
int menuGestionMateria();
void pausar();
void limpiarPantalla();
void evaluacionCurso();
void gestionMaterias();
void agregarMateria();
void capturaDatosMateria(string* nombre,string* acronimo,string* profesor,string* dias,int*
                         horaInicio,int* horaFin);
void imprimeMateria(int i);
void listarMaterias();
void mostrarDetallesMateria();
void modificarMateria();
void eliminarMateria();
void modificarMateriaCompleta(int opcion);
void modificarNombreMateria(int opcion);
void modificarAcronimoMateria(int opcion);
void modificarNombreProfesor(int opcion);
void modificarDiasMateria(int opcion);
void modificarHoraInicio(int opcion);
void modificarHoraFin(int opcion);
void guardarEnArchivo();
void controlTareas();
int menuControlTarea();
void agregarTarea();
void capturaDatosTarea(string* asunto,string* descripcion,string* materia);
void imprimeTarea(int i);
void listarTareas();
void mostrarTarea();
void modificarTarea();
int menuModificarTarea();
void modificarTareaCompleta(int i);
void modificarAsuntoTarea(int i);
void modificarDescripcionTarea(int i);
void modificarMateraTarea(int i);
void eliminarTarea();
void guardarTarea();

void controlAgenda();
int menuAgenda();
void agregarRecordatorio();
void capturaDatosRecordatorio(string* asunto,string* tipoRecordatorio,string* fecha,string* hora);
void mostrarRecordatorio();
void listarRecordatorios();
void mostrarDetallesRecordatorio();
void modificarRecordatorio();
int menuModificarRecordatorio();
void modificarRecordatorioCompleto(int i);
void modificarAsuntoRecordatorio(int i);
void modificarTipoRecordatorio(int i);
void modificarFechaRecordatorio(int i);
void modificarHoraRecordatorio(int i);
void eliminarRecordatorio();
void guardarAgendaEnArchivo();
void cargarRecordatorios();

InterfazAdministradorNota* interfazAdministradorNota=new InterfazAdministradorNota;

int main()
{

    bool seguirEjecutandoPrograma=true;
    int opcion;
    setlocale(LC_ALL, "");
    do{
        system(CLEAR);
        cout << "MENU PRINCIPAL" << endl << endl;
        cout << "1. Evaluacion de un Curso" << endl;
        cout << "2. Gestion de Materias" << endl;
        cout << "3. Control de Tareas" << endl;
        cout << "4. Agenda" << endl;
        cout << "5. Bloc de Notas" << endl;
        cout << "6. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        cin.get();
        switch(opcion)
        {
        case EVALUACION_CURSO:
            evaluacionCurso();
            break;
        case GESTION_MATERIAS:
            gestionMaterias();
            break;
        case CONTROL_TAREAS:
            controlTareas();
            break;
        case CONTROL_AGENDA:
            controlAgenda();
            break;
        case NOTAS:
            interfazAdministradorNota->menuAdminNota();
            break;
        case SALIR:
            cout << "Haz salido del programa..." << endl;
            seguirEjecutandoPrograma=false;
            break;
        default:
            cout << "Opción no válida..." << endl;
            pausar();
        }
    }
    while(seguirEjecutandoPrograma);
    delete[] tareas;
    delete[] recordatorios;
    delete interfazAdministradorNota;
    return 0;
}

int menu()
{
    int opcion;
    cout << "ACTIVIDAD 5" << endl << endl;
    cout << "1. Evaluacion del curso" << endl;
    cout << "2. Gestión de Materias" << endl;
    cout << "3. Gestion de tareas" << endl;
    cout << "4. Agenda" << endl;
    cout << "5. Salir" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    cin.get();
    return opcion;
}

int menuGestionMateria()
{
    int opcion;
    cout << "Gestion de materias" << endl << endl;
    cout << "1. Agregar materia" << endl;
    cout << "2. Listar materias" << endl;
    cout << "3. Mostrar detalles de una materia" << endl;
    cout << "4. Modificar una materia" << endl;
    cout << "5. Eliminar una materia" << endl;
    cout << "6. Guardar cambios" << endl;
    cout << "7. Regresar al menu anterior" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    cin.get();
    return opcion;
}

void evaluacionCurso()
{
    MateriaEvaluacion materia;
    //Declaracion de variables (a usar para entrada de datos)
    short cantidadFalta,cantidadRetardo,cantidadTarea,calificacionActividades[TOTAL_ACTIVIDADES],
          calificacionExamenes[TOTAL_EXAMENES];
    //Declaracion de variables (a usar para computos)
    float porcentajeActividad,porcentajeExamen,calificacionFinal,
          asistencias,auxiliarAsistencia,porcentajeAsistencia,auxiliarActividad,acumuladorActividad,
          auxiliarExamen,acumuladorExamen,porcentajeTareas;
    string calificacionAprobatoria;
    string textoExamen[TOTAL_EXAMENES];
    textoExamen[C_0]=TEXTO_1;
    textoExamen[C_1]=TEXTO_2;
    textoExamen[C_2]=TEXTO_3;
    //Entrada de datos
    cout << "Dame el nombre de la materia a evaluar: ";
    getline(cin, materia.nombre);
    cout << "Dame el acronimo de la materia: ";
    cin >> materia.acronimo;
    cin.get();
    cout << "Dame los dias de la semana en que se imparte la materia: ";
    cin >> materia.diasSemana;
    cin.get();
    cout << "Dame la hora de inicio de la clase: ";
    cin >> materia.horaInicio;
    cin.get();
    cout << "Dame la hora de fin de la clase: ";
    cin >> materia.HoraFinalizacion;
    cin.get();
    pausar();
    cout << "Cuántas faltas tuviste en el curso? ";
    cin >> cantidadFalta;
    cin.get();
    cout << "Cuántos retardos tuviste en el curso? ";
    cin >> cantidadRetardo;
    cin.get();
    cout << "Cuántas tareas realizaste? ";
    cin >> cantidadTarea;
    cin.get();
    for(int i=C_0; i<TOTAL_ACTIVIDADES; i++)
    {
        cout << "Cuánto obtuviste en la actividad #" << i+C_1 << "? ";
        cin >> calificacionActividades[i];
    }
    for(int i=C_0; i<TOTAL_EXAMENES; i++)
    {
        cout << "Cuánto obtuviste en el " << textoExamen[i] << " examen parcial? ";
        cin >> calificacionExamenes[i];
    }
    for(int i=C_0; i<TOTAL_ACTIVIDADES; i++)
    {
        acumuladorActividad+=calificacionActividades[i];
    }
    for(int i=C_0; i<TOTAL_EXAMENES; i++)
    {
        acumuladorExamen+=calificacionExamenes[i];
    }
    //Computo de actividades
    auxiliarActividad=(acumuladorActividad*C_100)/C_900;
    porcentajeActividad=(auxiliarActividad*PORCENTAJE_ACTIVIDADES)/C_100;
    //Computo de examenes parciales
    auxiliarExamen=(acumuladorExamen*C_100)/C_300;
    porcentajeExamen=(auxiliarExamen*PORCENTAJE_EXAMENES)/C_100;
    //Computo de asistencias
    auxiliarAsistencia=cantidadRetardo%C_3;
    asistencias=TOTAL_ASISTENCIAS-auxiliarAsistencia-cantidadFalta;
    porcentajeAsistencia=(asistencias*C_100)/TOTAL_ASISTENCIAS;
    //Computo de tareas
    porcentajeTareas=(cantidadTarea*PORCENTAJE_TAREAS)/TOTAL_TAREAS;
    //Computo de puntos finales
    calificacionFinal=porcentajeTareas+porcentajeActividad+porcentajeExamen;
    calificacionAprobatoria= (calificacionFinal>=MINIMA_CALIF) ? "Calificación aprobatoria" :
                             "Calificación no aprobatoria";
    //Salida de datos
    pausar();
    system(CLEAR);
    cout << "Evaludador de curso v1.0 - " << materia.nombre << " (" << materia.acronimo <<") " <<
         materia.diasSemana << " " << materia.horaInicio << "-" << materia.HoraFinalizacion <<
         endl << endl;
    cout << "Tareas    Actividades    Examenes" << endl;
    cout << " " <<porcentajeTareas << "       " << porcentajeActividad << "          "
         << porcentajeExamen << endl;
    cout << "Total de asistencias=        " << asistencias << endl;
    cout << "Porcentaje de asistencias=   " << porcentajeAsistencia;
    if (asistencias>=MINIMO_PORCENTAJE_ASISTENCIA)
    {
        cout << " Tiene derecho" << endl;
    }
    else
    {
        cout << " NO tiene derecho" << endl;
    }
    cout << "Calificación Final=          " << calificacionFinal << "  " << calificacionAprobatoria;
    if (asistencias>=MINIMO_PORCENTAJE_ASISTENCIA && calificacionFinal>=MINIMA_CALIF)
    {
        cout << endl << "Alumn@ aprobado!" << endl;
    }
    else
    {
        cout << endl << "Alumn@ no aprobado." << endl;
    }
    pausar();
}

void gestionMaterias()
{
    bool seguirEjecutandoModulo=true;
    do
    {
        system(CLEAR);
        switch(menuGestionMateria())
        {
        case AGREGAR_MATERIA:
            agregarMateria();
            break;
        case LISTAR_MATERIA:
            listarMaterias();
            break;
        case MOSTRAR_DETALLES:
            mostrarDetallesMateria();
            break;
        case MODIFICAR_MATERIA:
            modificarMateria();
            break;
        case ELIMINAR_MATERIA:
            eliminarMateria();
            break;
        case GUARDAR:
            guardarEnArchivo();
            break;
        case REGRESAR:
            seguirEjecutandoModulo=false;
            break;
        default:
            cout << "Opcion no valida..." << endl;
        }
    }
    while(seguirEjecutandoModulo);
}

void capturaDatosMateria(string* nombre,string* acronimo,string* profesor,string* dias,int*
                         horaInicio,int* horaFin)
{
    cout << "Dame el nombre de la materia: ";
    getline(cin, *nombre);
    cout << "Dame el acronimo de la materia: ";
    getline(cin, *acronimo);
    cout << "Dame el nombre del profesor: ";
    getline(cin, *profesor);
    cout << "Dame los dias en que se imparte la materia: ";
    getline(cin, *dias);
    cout << "Dame la hora de inicio de clase: ";
    cin >> *horaInicio;
    cin.get();
    cout << "Dame la hora de fin de clase: ";
    cin >> *horaFin;
    cin.get();
}

void agregarMateria()
{
    string nombre,acronimo,profesor,dias;
    int horaInicio,horaFin;
    capturaDatosMateria(&nombre,&acronimo,&profesor,&dias,&horaInicio,&horaFin);
    materias[cuentaRegistros]=new Materia(nombre,acronimo,profesor,dias,horaInicio,horaFin);
    cuentaRegistros++;
}

void capturaDatosTarea(string* asunto,string* descripcion,string* materia){
    cout << "Dame el asunto: ";
    getline(cin, *asunto);
    cout << "Dame la descripcion: ";
    getline(cin, *descripcion);
    cout << "Dame la materia: ";
    getline(cin, *materia);
}

void imprimeMateria(int i)
{
    cout << "Nombre de la materia: " << materias[i]->dameNombre() << endl;
    cout << "Acronimo:             " << materias[i]->dameAcronimo() << endl;
    cout << "Profesor:             " << materias[i]->dameNombreProfesor() << endl;
    cout << "Dias:                 " << materias[i]->dameDias() << endl;
    cout << "Hora Inicio:          " << materias[i]->dameHoraInicio() << endl;
    cout << "Hora Fin:             " << materias[i]->dameHoraFin() << endl;
}

void listarMaterias(){
    if (cuentaRegistros>C_0){
        for(int i=C_0;i<cuentaRegistros;i++){
        cout << "Registro Numero " << i+1 << endl;
        imprimeMateria(i);
        cout << endl;
    }
    }
    else{
        cout << "No hay registros que listar..." << endl;
    }
    pausar();
}

void mostrarDetallesMateria(){
    int opcion;
    if (cuentaRegistros>C_0){
        cout << "Indica el registro a mostrar 1 a (" << cuentaRegistros <<") :";
        cin >> opcion;
        opcion--;
        cin.get();
        imprimeMateria(opcion);
    }
    else{
        cout << "No hay registros que mostrar..." << endl;
    }
    pausar();
}

int menuModificarMateria(){
    int opcionMenu;
    cout << "MENU PARA MODIFICAR MATERIA " << endl;
    cout << "1) Modificar materia completa" << endl;
    cout << "2) Modificar nombre de la materia" << endl;
    cout << "3) Modificar acrónimo de la materia" << endl;
    cout << "4) Modificar nombre de profesor" << endl;
    cout << "5) Modificar dias de la materia" << endl;
    cout << "6) Modificar hora de inicio de la materia" << endl;
    cout << "7) Modificar hora de fin de la materia" << endl;
    cout << "8) Salir del menu modificar" << endl;
    cout << "Opci�n: ";
    cin >> opcionMenu;
    cin.get();
    return opcionMenu;
}

void modificarMateria(){
    bool seguirEjecutandoMenu=true;
    int opcion;
    if (cuentaRegistros>C_0){
        listarMaterias();
        cout << "Dime el numero de registro que quieres modificar (1 a " <<
        cuentaRegistros << ") :";
        cin >> opcion;
        opcion--;
        cin.get();
    do{
        system(CLEAR);
        switch(menuModificarMateria()){
            case MODIF_MATERIA:
                modificarMateriaCompleta(opcion);
                break;
            case MODIF_NOMBRE:
                modificarNombreMateria(opcion);
                break;
            case MODIF_ACRONIMO:
                modificarAcronimoMateria(opcion);
                break;
            case MODIF_NOMBRE_PROFESOR:
                modificarNombreProfesor(opcion);
                break;
            case MODIF_DIAS:
                modificarDiasMateria(opcion);
                break;
            case MODIF_HORA_INICIO:
                modificarHoraInicio(opcion);
                break;
            case MODIF_HORA_FIN:
                modificarHoraFin(opcion);
                break;
            case SALIR_MODIFICAR:
                cout << "Haz salido del menú modificar..." << endl;
                seguirEjecutandoMenu=false;
                break;
            default:
                cout << "Opción no valida..." << endl;
                pausar();
        }
    } while(seguirEjecutandoMenu);
    }
    else{
        cout << "No hay registros que modificar..." << endl;
    }
    pausar();
}

void modificarMateriaCompleta(int opcion){
    string nombre,acronimo,profesor,dias;
    int horaInicio,horaFin;
    capturaDatosMateria(&nombre,&acronimo,&profesor,&dias,&horaInicio,&horaFin);
    materias[opcion]->fijaNombre(nombre);
    materias[opcion]->fijaAcronimo(acronimo);
    materias[opcion]->fijaProfesor(profesor);
    materias[opcion]->fijaDias(dias);
    materias[opcion]->fijaHoraInicio(horaInicio);
    materias[opcion]->fijaHoraFin(horaFin);
}

void modificarNombreMateria(int opcion){
    string nuevoNombre;
    cout << "Dame el nuevo nombre de la materia: ";
    getline(cin, nuevoNombre);
    materias[opcion]->fijaNombre(nuevoNombre);
    cout << "Nombre modificado con exito! " << endl;
    pausar();
}

void modificarAcronimoMateria(int opcion){
    string nuevoAcronimo;
    cout << "Dame el nuevo acronimo de la materia: ";
    getline(cin, nuevoAcronimo);
    materias[opcion]->fijaAcronimo(nuevoAcronimo);
    cout << "Acr�nimo modificado con exito!" << endl;
    pausar();
}

void modificarNombreProfesor(int opcion){
    string nuevoNombreProfesor;
    cout << "Dame el nuevo nombre del profesor: ";
    getline(cin, nuevoNombreProfesor);
    materias[opcion]->fijaProfesor(nuevoNombreProfesor);
    cout << "Nombre de profesor modificado con �xito!" << endl;
    pausar();
}

void modificarDiasMateria(int opcion){
    string nuevoDiaMateria;
    cout << "Dame los nuevos dias de la materia: ";
    getline(cin, nuevoDiaMateria);
    materias[opcion]->fijaDias(nuevoDiaMateria);
    cout << "Dias modificado con éxito!" << endl;
    pausar();
}

void modificarHoraInicio(int opcion){
    int nuevaHoraInicio;
    cout << "Dame la nueva hora de inicio: ";
    cin >> nuevaHoraInicio;
    cin.get();
    materias[opcion]->fijaHoraInicio(nuevaHoraInicio);
    cout << "Hora de inicio modificada con éxito! " << endl;
    pausar();
}

void modificarHoraFin(int opcion){
    int nuevaHoraFin;
    cout << "Dame la nueva hora de fin: ";
    cin >> nuevaHoraFin;
    cin.get();
    materias[opcion]->fijaHoraFin(nuevaHoraFin);
    cout << "Hora de fin modificada con éxito! " << endl;
    pausar();
}

void eliminarMateria(){
    int i;
    if (cuentaRegistros>C_0){
        listarMaterias();
        cout << "¿Qué registro deseas eliminar? (1 a " << cuentaRegistros << ") :";
        cin >> i;
        i--;
        cin.get();
        delete materias[i];
        for(cuentaRegistros--;i<cuentaRegistros;i++){
            materias[i]=materias[i+C_1];
        }
        cout << "Registro eliminado con exito!" << endl;
    }
    else{
        cout << "No hay registros para eliminar..." << endl;
    }
    pausar();
}

void guardarEnArchivo(){
    if (cuentaRegistros>C_0){
        for(int i=C_0;i<cuentaRegistros;i++){
        reporteRegistro << "Registro Numero " << i+C_1 << endl;
        reporteRegistro << "Nombre de la materia: " << materias[i]->dameNombre() << endl;
        reporteRegistro << "Acronimo:             " << materias[i]->dameAcronimo() << endl;
        reporteRegistro << "Profesor:             " << materias[i]->dameNombreProfesor() << endl;
        reporteRegistro << "Dias:                 " << materias[i]->dameDias() << endl;
        reporteRegistro << "Hora Inicio:          " << materias[i]->dameHoraInicio() << endl;
        reporteRegistro << "Hora Fin:             " << materias[i]->dameHoraFin() << endl;
        reporteRegistro << endl;
    }
    reporteRegistroStr=reporteRegistro.str();
    archivo.open(NOMBRE_ARCHIVO);
    archivo << reporteRegistroStr;
    archivo.close();
    }
    else{
        cout << "No hay registros que listar..." << endl;
    }
    cout << "Archivo guardado con éxito!" << endl;
    pausar();
}

int menuControlTarea(){
    int opcion;
    cout << "1. Agregar tarea" << endl;
    cout << "2. Listar tareas" << endl;
    cout << "3. Mostrar detalles de una tarea" << endl;
    cout << "4. Modificar detalles de una tarea" << endl;
    cout << "5. Eliminar tarea" << endl;
    cout << "6. Guardar cambios" << endl;
    cout << "7. Regresar al menu anterior" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    cin.get();
    return opcion;
}

void controlTareas(){
    tareas=new Tarea*[maxTareas];
    bool seguirEjecutandoModulo=true;
    do{
        system(CLEAR);
        switch(menuControlTarea()){
        case AGREGAR_TAREA:
            agregarTarea();
            break;
        case LISTAR_TAREA:
            listarTareas();
            break;
        case MOSTRAR_TAREA:
            mostrarTarea();
            break;
        case MODIFICAR_TAREA:
            modificarTarea();
            break;
        case ELIMINAR_TAREA:
            eliminarTarea();
            break;
        case GUARDAR_TAREA:
            guardarTarea();
            break;
        case MENU_ANTERIOR:
            seguirEjecutandoModulo=false;
            break;
        default:
            cout << "Opcion no valida..." << endl;
            pausar();
        }
    }while(seguirEjecutandoModulo);
}

void guardarTarea(){
    cout << "En construccion :) " << endl;
    pausar();
}

void agregarTarea(){
    string asunto,descripcion,materia;
    Tarea** temp;
    cout << "ALTA DE TAREA" << endl;
    if (cuentaTareas==maxTareas){
        temp=new Tarea*[maxTareas=cuentaTareas+1];
        for(int i=C_0;i<cuentaTareas;i++){
            temp[i]=tareas[i];
        }
        delete[] tareas;
        tareas=temp;
    }
    capturaDatosTarea(&asunto,&descripcion,&materia);
    tareas[cuentaTareas]=new Tarea(asunto,descripcion,materia);
    cuentaTareas++;
}

void listarTareas(){
    if (cuentaTareas>0){
        for(int i=0;i<cuentaTareas;i++){
            imprimeTarea(i);
        }
    }
    else{
        cout << "No hay tareas que listar..." << endl;
    }
    pausar();
}

void imprimeTarea(int i){
    cout << "Registro " << i+C_1 << endl;
    cout << "Asunto: " << tareas[i]->dameAsunto() << endl;
    cout << "Descripcion: " << tareas[i]->dameDescripcion() << endl;
    cout << "Materia: " << tareas[i]->dameMateria() << endl << endl;
}

void mostrarTarea(){
    int opcion;
    if (cuentaTareas>C_0){
        cout << "MOSTRAR TAREA" << endl;
        cout << "Que registro quieres ver? (1 a " << cuentaTareas << ") :";
        cin >> opcion;
        opcion--;
        cin.get();
        imprimeTarea(opcion);
    }
    pausar();
}

void modificarTarea(){
    bool seguirEjecutandoModulo=true;
    int opcion;
    if (cuentaTareas>C_0){
        listarTareas();
        cout << endl << "�Qu� registro quieres modificar? (1 a " << cuentaTareas << ") :";
        cin >> opcion;
        opcion--;
        cin.get();
        do
        {
            switch(menuModificarTarea())
            {
            case MODIFICAR_TAREA_COMPLETA:
                modificarTareaCompleta(opcion);
                break;
            case MODIFICAR_ASUNTO_TAREA:
                modificarAsuntoTarea(opcion);
                break;
            case MODIFICAR_DESC_TAREA:
                modificarDescripcionTarea(opcion);
                break;
            case MODIFICAR_MATERIA_TAREA:
                modificarMateraTarea(opcion);
                break;
            case SALIR_MODIFICAR_TAREA:
                cout << "Haz salido del menu modificar tarea..." << endl;
                pausar();
                seguirEjecutandoModulo=false;
                break;
            default:
                cout << "Opcion no valida..." << endl;
            }
        }
        while(seguirEjecutandoModulo);
    }
}

int menuModificarTarea(){
    int opcionMenu;
    cout << "MENU PARA MODIFICAR TAREA " << endl;
    cout << "1) Modificar tarea completa" << endl;
    cout << "2) Modificar asunto de la tarea" << endl;
    cout << "3) Modificar descripcion de la tarea" << endl;
    cout << "4) Modificar materia a la que pertenece la tarea" << endl;
    cout << "5) Salir del menu modificar" << endl;
    cout << "Opci�n: ";
    cin >> opcionMenu;
    cin.get();
    return opcionMenu;
}

void modificarTareaCompleta(int i){
    string nuevoAsunto,nuevaDescripcion,nuevaMateria;
    cout << "Dame el asunto de la tarea: ";
    getline(cin, nuevoAsunto);
    cout << "Dame la nueva descripcion de la tarea: ";
    getline(cin, nuevaDescripcion);
    cout << "Dame la nueva materia a la que pertenece esta materia: ";
    getline(cin,nuevaMateria);
    tareas[i]->fijaAsunto(nuevoAsunto);
    tareas[i]->fijaDescripcion(nuevaDescripcion);
    tareas[i]->fijaMateria(nuevaMateria);
    cout << "�Registro modificado con exito!" << endl;
    pausar();
}

void modificarAsuntoTarea(int i){
    string nuevoAsunto;
    cout << "Dame el asunto modificado para esta tarea: ";
    getline(cin, nuevoAsunto);
    tareas[i]->fijaAsunto(nuevoAsunto);
    cout << "�Asunto modificado con �xito!" << endl;
    pausar();
}

void modificarDescripcionTarea(int i){
    string nuevaDescripcion;
    cout << "Dame la nueva descripcion para esta tarea: ";
    getline(cin, nuevaDescripcion);
    tareas[i]->fijaDescripcion(nuevaDescripcion);
    cout << "�Descripcion modificada con �xito!"<< endl;
    pausar();
}

void modificarMateraTarea(int i){
    string nuevaTarea;
    cout << "Dame la nueva materia para esta tarea: ";
    getline(cin, nuevaTarea);
    tareas[i]->fijaMateria(nuevaTarea);
    cout << "�Materia modificada con �xito!" << endl;
    pausar();
}

void eliminarTarea(){
    int i;
    if (cuentaTareas>C_0){
    listarTareas();
    cout << "�Qu� registro quieres eliminar (1 a " << cuentaTareas << ") :";
    cin >> i;
    i--;
    cin.get();
    delete tareas[i];
    for(cuentaTareas--;i<cuentaRegistros;i++){
        tareas[i]=tareas[i+C_1];
    }
    cout << "Registro eliminado con �xito." << endl;
    }
    else{
        cout << "No hay tareas que borrar" << endl;
    }
    pausar();
}

int menuAgenda(){
    int opcion;
    cout << "AGENDA" << endl << endl;
    cout << "1. Agregar recordatorio" << endl;
    cout << "2. Listar recordatorios" << endl;
    cout << "3. Mostrar detalles de un recordatorio" << endl;
    cout << "4. Modificar un recordatorio" << endl;
    cout << "5. Eliminar un recordatorio" << endl;
    cout << "6. Guardar cambios" << endl;
    cout << "7. Regresar al menu anterior" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    cin.get();
    return opcion;
}

void controlAgenda(){
    if (!cuentaRecordatorios) {
        recordatorios=new Agenda*[maxRecordatorios];
    }
    bool seguirEjecutandoModulo=true;
    do{
        system(CLEAR);
        switch(menuAgenda()){
        case AGREGAR_RECORDATORIO:
            agregarRecordatorio();
            break;
        case LISTAR_RECORDATORIOS:
            listarRecordatorios();
            break;
        case MOSTRAR_DETALLES_RECORDATORIO:
            mostrarDetallesRecordatorio();
            break;
        case MODIFICAR_RECORDATORIO:
            modificarRecordatorio();
            break;
        case ELIMINAR_RECORDATORIO:
            eliminarRecordatorio();
            break;
        case GUARDAR_RECORDATORIOS:
            guardarAgendaEnArchivo();
            break;
        case SALIR_MENU_RECORDATORIOS:
            seguirEjecutandoModulo=false;
            break;
        default:
            cout << "Opcion no valida" << endl;
            pausar();
        }
    }while(seguirEjecutandoModulo);
}

void capturaDatosRecordatorio(string* asunto,string* tipo,string* fecha,string* hora){
    cout << "Dame el asunto del recordatorio: ";
    getline(cin, *asunto);
    cout << "Dame el tipo de recordatorio: ";
    getline(cin, *tipo);
    cout << "Dame la fecha: ";
    getline(cin, *fecha);
    cout << "Dame la hora: ";
    getline(cin, *hora);
}

void agregarRecordatorio(){
    string asunto,tipo,fecha,hora;
    Agenda** temp;
    cout << "ALTA DE RECORDATORIO" << endl;
    if (cuentaRecordatorios==maxRecordatorios){
        temp=new Agenda*[maxRecordatorios=cuentaRecordatorios+C_1];
        for(int i=C_0;i<cuentaRecordatorios;i++){
            temp[i]=recordatorios[i];
        }
        delete[] recordatorios;
        recordatorios=temp;
    }
    capturaDatosRecordatorio(&asunto,&tipo,&fecha,&hora);
    recordatorios[cuentaRecordatorios]=new Agenda(asunto,tipo,fecha,hora);
    cuentaRecordatorios++;
}

void mostrarRecordatorio(int i){
    cout << cuentaRecordatorios << endl;
    cout << "Recordatorio #" << i+C_1 << endl;
    cout << "Asunto: " << recordatorios[i]->dameAsunto() << endl;
    cout << "Tipo: " << recordatorios[i]->dameTipo() << endl;
    cout << "Fecha: " << recordatorios[i]->dameFecha() << endl;
    cout << "Hora: " << recordatorios[i]->dameHora() << endl;
}

void listarRecordatorios(){
    if (cuentaRecordatorios>C_0){
        for(int i=0;i<cuentaRecordatorios;i++){
            mostrarRecordatorio(i);
        }
    }
    else{
        cout << "No hay recordatorios que mostrar." << endl;
    }
    pausar();
}

void mostrarDetallesRecordatorio(){
    int opcion;
    if (cuentaRecordatorios>C_0){
        cout << "Que recordatorio quieres mostrar (1 a " << cuentaRecordatorios << ") :";
        cin >> opcion;
        cin.get();
        opcion--;
        mostrarRecordatorio(opcion);
    }
    else{
        cout << "No hay recordatorios que mostrar." << endl;
    }
    pausar();
}

int menuModificarRecordatorio(){
    int opcion;
    cout << "1. Modificar Recordatorio por completo" << endl;
    cout << "2. Modificar asunto" << endl;
    cout << "3. Modificar tipo" << endl;
    cout << "4. Modificar fecha" << endl;
    cout << "5. Modificar hora" << endl;
    cout << "6. Salir de este menu" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    cin.get();
    return opcion;
}

void modificarRecordatorio(){
    bool seguirEjecutandoSubMenu=true;
    int opcion;
    if (cuentaRecordatorios>C_0){
        cout << "Que registro quieres modificar (1 a " << cuentaRecordatorios << ") :";
        cin >> opcion;
        cin.get();
        opcion--;
        do{
            system(CLEAR);
            switch(menuModificarRecordatorio()){
            case MODIFICAR_RECORDATORIO_COMPLETO:
                modificarRecordatorioCompleto(opcion);
                break;
            case MODIFICAR_ASUNTO_RECORDATORIO:
                modificarAsuntoRecordatorio(opcion);
                break;
            case MODIFICAR_TIPO_RECORDATORIO:
                modificarTipoRecordatorio(opcion);
                break;
            case MODIFICAR_FECHA_RECORDATORIO:
                modificarFechaRecordatorio(opcion);
                break;
            case MODIFICAR_HORA_RECORDATORIO:
                modificarHoraRecordatorio(opcion);
                break;
            case SALIR_SUBMENU_RECORDATORIO:
                seguirEjecutandoSubMenu=false;
                break;
            default:
                cout << "Opcion no valida" << endl;
            }
        }while(seguirEjecutandoSubMenu);
    }
    else{
        cout << "No hay recordatorios por modificar" << endl;
    }
    pausar();
}

void modificarRecordatorioCompleto(int i){
    string asunto,tipo,fecha,hora;
    cout << "Dame el nuevo asunto: ";
    getline(cin, asunto);
    cout << "Dame el nuevo tipo: ";
    getline(cin, tipo);
    cout << "Dame la nueva fecha: ";
    getline(cin, fecha);
    cout << "Dame la nueva hora: ";
    getline(cin, hora);
    recordatorios[i]->fijaAsunto(asunto);
    recordatorios[i]->fijaTipo(tipo);
    recordatorios[i]->fijaFecha(fecha);
    recordatorios[i]->fijaHora(hora);
    cout << "Registro modificado con exito!" << endl;
    pausar();
}

void modificarAsuntoRecordatorio(int i){
    string nuevoAsunto;
    cout << "Dame el nuevo asunto: ";
    getline(cin, nuevoAsunto);
    recordatorios[i]->fijaAsunto(nuevoAsunto);
    cout << "Asunto modificado con exito!" << endl;
    pausar();
}

void modificarTipoRecordatorio(int i){
    string nuevoTipo;
    cout << "Dame el nuevo tipo: ";
    getline(cin, nuevoTipo);
    recordatorios[i]->fijaTipo(nuevoTipo);
    cout << "Tipo modificado con exito!" << endl;
    pausar();
}

void modificarFechaRecordatorio(int i){
    string nuevaFecha;
    cout << "Dame la nueva fecha: ";
    getline(cin, nuevaFecha);
    recordatorios[i]->fijaFecha(nuevaFecha);
    cout << "Fecha modificada con exito!" << endl;
    pausar();
}

void modificarHoraRecordatorio(int i){
    string nuevaHora;
    cout << "Dame la nueva hora: ";
    getline(cin, nuevaHora);
    recordatorios[i]->fijaHora(nuevaHora);
    cout << "Hora modificada con exito!" << endl;
    pausar();
}

void eliminarRecordatorio(){
    int i;
    if (cuentaRecordatorios>C_0){
        cout << "Que registro quieres eliminar (1 a " << cuentaRecordatorios << ") :";
        cin >> i;
        cin.get();
        i--;
        for(cuentaRecordatorios--;i<cuentaRecordatorios;i++){
            recordatorios[i]=recordatorios[i+C_1];
        }
        cout << "Registro eliminado!" << endl;
    }
    else{
        cout << "No hay recordatorios para eliminar" << endl;
    }
    pausar();
}

void guardarAgendaEnArchivo(){
    ofstream archivoAgenda;
    stringstream ss;
    string archivoAgendaStr;
    archivoAgenda.open(NOMBRE_ARCHIVO_AGENDA);
    if (archivoAgenda.is_open()){
        archivoAgenda << cuentaRecordatorios << SALTO_DE_LINEA;
        for(int i=C_0;i<cuentaRecordatorios;i++){
            ss << recordatorios[i]->dameAsunto() << DELIMITADOR_CAMPOS
            << recordatorios[i]->dameTipo() << DELIMITADOR_CAMPOS
            << recordatorios[i]->dameFecha() << DELIMITADOR_CAMPOS
            << recordatorios[i]->dameHora() << SALTO_DE_LINEA;
        }
        archivoAgendaStr=ss.str();
        archivoAgenda << archivoAgendaStr;
        cout << "Archivo guardado con exito!" << endl;
        archivoAgenda.close();
    }
    else{
        cout << "No se pudo abrir el archivo." << endl;
    }
    pausar();
}

void cargarRecordatorios(){
    ifstream archivoAgenda;
    string cadena,subcadena;
    archivoAgenda.open(NOMBRE_ARCHIVO_AGENDA, ios::in);
    if (archivoAgenda.is_open()){
        string cuentaRecordatoriosStr;
        getline(archivoAgenda, cuentaRecordatoriosStr);
        cuentaRecordatorios=stoi(cuentaRecordatoriosStr);
        recordatorios = new Agenda*[cuentaRecordatorios];
        cout << "Cargando " << cuentaRecordatorios << " recordatorios..." << endl;
        for (int i = 0; getline(archivoAgenda, cadena) && i < cuentaRecordatorios; i++) {
            stringstream ss(cadena);
            string asunto = "", tipo = "", fecha = "", hora = "";
            getline(ss, asunto, DELIMITADOR_CAMPOS);
            getline(ss, tipo, DELIMITADOR_CAMPOS);
            getline(ss, fecha, DELIMITADOR_CAMPOS);
            getline(ss, hora);
            recordatorios[i] = new Agenda(asunto,tipo,fecha,hora);
            cout << "Cargando recordatorio: " << recordatorios[i]->dameAsunto() << endl;
        }
        pausar();
        archivoAgenda.close();
    }
    else{
        cout << "No se pudo cargar el archivo" << endl;
    }
}
