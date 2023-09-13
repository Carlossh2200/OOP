#ifndef NOTA_H_INCLUDED
#define NOTA_H_INCLUDED
#define DESCRIPCION_POR_DEFECTO_NOTA "Hola"
using namespace std;

class Nota{
string descripcion;













public:
    Nota(){
        this->descripcion=DESCRIPCION_POR_DEFECTO_NOTA;
    }
    Nota(string descripcion){
        if (fijaDescripcion(descripcion)){
            this->fijaDescripcion(descripcion);
        }
        else{
            this->fijaDescripcion(DESCRIPCION_POR_DEFECTO_NOTA);
        }

    }
    bool fijaDescripcion(string d){
        if (d.length() >1 && d.length() <=70){
            descripcion=d;
            return true;
        }
        else{
            return false;
        }
    }

    string dameDescripcion(){
        return descripcion;
    }
};

#endif // NOTA_H_INCLUDED
