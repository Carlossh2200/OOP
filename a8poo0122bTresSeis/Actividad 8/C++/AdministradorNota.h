#ifndef ADMINISTRADORNOTA_H_INCLUDED
#define ADMINISTRADORNOTA_H_INCLUDED
#define NOMBRE_ARCHIVO_GUARDAR_NOTAS "Actividad 8 Notas.txt"
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Nota.h"
#include "Util.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif // _WIN32

class AdministradorNota{
    static constexpr int MAX_NOTAS=3;
    Nota** notas;
    int maxNotas;
    int cuentaNotas;


















public:
    AdministradorNota(){
        maxNotas=MAX_NOTAS;
        notas=new Nota*[maxNotas];
        cuentaNotas=0;
    }
    int dameCuentaNotas(){
        return cuentaNotas;
    }
    int dameMaxNotas(){
        return maxNotas;
    }
    void agrandarArreglo(){
        Nota** temp=new Nota*[maxNotas=cuentaNotas+1];
        for(int i=0;i<cuentaNotas;i++){
            temp[i]=notas[i];
        }
        delete[] notas;
        notas=temp;
    }
    void agregar(string descripcion){
        notas[cuentaNotas]=new Nota(descripcion);
        cuentaNotas++;
    }
    void modificar(int i,string descripcion){
        notas[i]->fijaDescripcion(descripcion);
    }
    string dameDescripcionNota(int i){
        return notas[i]->dameDescripcion();
    }

    void eliminar(int i){
        delete notas[i];
        for(cuentaNotas--;i<cuentaNotas;i++){
            notas[i]=notas[i+1];
        }
    }

    void guardar(){
        ofstream archivoNotas;
        stringstream archivoNotasStringStream;
        string archivoNotasString;
        archivoNotas.open(NOMBRE_ARCHIVO_GUARDAR_NOTAS);
        if (archivoNotas.is_open()){
        for(int i=0;i<cuentaNotas;i++){
            archivoNotasStringStream << notas[i]->dameDescripcion();
        }
        archivoNotasString=archivoNotasStringStream.str();
        archivoNotas << archivoNotasString;
        archivoNotas.close();
        }
    }

};

#endif // ADMINISTRADORNOTA_H_INCLUDED
