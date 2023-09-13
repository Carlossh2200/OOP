//TresSeis
//Actividad 4
//Tiempo=1:30
#include <iostream>
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif // _WIN32

using namespace std;

struct Materia{
    string nombre,acronimo,diasSemana;
    short horaInicio,HoraFinalizacion;
};

//Declaracion y definicion de constantes
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








int main()
{
    Materia materia;
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
    cout << "Presione entrar para continuar..." << endl;
    cin.get();
    cout << "Cuantas faltas tuviste en el curso? ";
    cin >> cantidadFalta;
    cin.get();
    cout << "Cuantos retardos tuviste en el curso? ";
    cin >> cantidadRetardo;
    cin.get();
    cout << "Cuantas tareas realizaste? ";
    cin >> cantidadTarea;
    cin.get();
    for(int i=C_0;i<TOTAL_ACTIVIDADES;i++){
        cout << "Cuanto obtuviste en la actividad #" << i+C_1 << "? ";
        cin >> calificacionActividades[i];
     }
    for(int i=C_0;i<TOTAL_EXAMENES;i++){
        cout << "Cuanto obtuviste en el " << textoExamen[i] << " examen parcial? ";
        cin >> calificacionExamenes[i];
    }
    for(int i=C_0;i<TOTAL_ACTIVIDADES;i++){
        acumuladorActividad+=calificacionActividades[i];
    }
    for(int i=C_0;i<TOTAL_EXAMENES;i++){
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
    calificacionAprobatoria= (calificacionFinal>=MINIMA_CALIF) ? "Calificacion aprobatoria" :
    "Calificacion no aprobatoria";
    //Salida de datos
    cout << "Presiona entrar para continuar..." << endl;
    cin.get();
    system(CLEAR);
    cout << "Evaludador de curso v1.0 - " << materia.nombre << " (" << materia.acronimo <<") " <<
    materia.diasSemana << " " << materia.horaInicio << "-" << materia.HoraFinalizacion << endl <<
    endl;
    cout << "Tareas    Actividades    Examenes" << endl;
    cout << " " <<porcentajeTareas << "       " << porcentajeActividad << "          "
    << porcentajeExamen << endl;
    cout << "Total de asistencias=        " << asistencias << endl;
    cout << "Porcentaje de asistencias=   " << porcentajeAsistencia;
    if (asistencias>=MINIMO_PORCENTAJE_ASISTENCIA){
        cout << " Tiene derecho" << endl;
    }
    else{
        cout << " NO tiene derecho" << endl;
    }
    cout << "Calificacion Final=          " << calificacionFinal << "  " << calificacionAprobatoria;
    if (asistencias>=MINIMO_PORCENTAJE_ASISTENCIA && calificacionFinal>=MINIMA_CALIF){
        cout << endl << "Alumn@ aprobado!" << endl;
    }
    else{
        cout << endl << "Alumn@ no aprobado." << endl;
    }
    cout << "Presione entrar para terminar..." << endl;
    cin.get();
    return 0;
}
