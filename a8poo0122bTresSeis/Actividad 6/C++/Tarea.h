#ifndef TAREA_H_INCLUDED
#define TAREA_H_INCLUDED
#include <string>

#define ASUNTO_POR_DEFECTO "Practica 5 POO"
#define DESCRIPCION_POR_DEFECTO "Realizar la practica 5 jueves"
#define MATERIA_POR_DEFECTO "POO"
#define MINIMO_CARACTER_ASUNTO 1
#define MAXIMO_CARACTER_ASUNTO 25
#define MINIMO_CARACTER_DESCRIPCION 1
#define MAXIMO_CARACTER_DESCRIPCION 40
#define MINIMO_CARACTER_MATERIA 1
#define MAXIMO_CARACTER_MATERIA 5

using namespace std;

class Tarea{
private:
    string asunto;
    string descripcion;
    string materia;
public:
    Tarea(string asunto,string descripcion,string materia){
        this->asunto=ASUNTO_POR_DEFECTO;
        this->descripcion=DESCRIPCION_POR_DEFECTO;
        this->materia=MATERIA_POR_DEFECTO;
        fijaAsunto(asunto);
        fijaDescripcion(descripcion);
        fijaMateria(materia);
    }
    bool fijaAsunto(string a){
        if (a.length()>=MINIMO_CARACTER_ASUNTO && a.length() <=MAXIMO_CARACTER_ASUNTO){
            asunto=a;
            return true;
        }
        else{
            return false;
        }
    }
    bool fijaDescripcion(string d){
        if (d.length()>=MINIMO_CARACTER_DESCRIPCION && d.length()<=MAXIMO_CARACTER_DESCRIPCION){
            descripcion=d;
            return true;
        }
        else{
            return false;
        }
    }
    bool fijaMateria(string m){
        if (m.length()>=MINIMO_CARACTER_MATERIA && m.length()<=MAXIMO_CARACTER_MATERIA){
            materia=m;
            return true;
        }
        else{
            return false;
        }
    }
    string dameAsunto(){
        return asunto;
    }
    string dameDescripcion(){
        return descripcion;
    }
    string dameMateria(){
        return materia;
    }
};
#endif // TAREA_H_INCLUDED
