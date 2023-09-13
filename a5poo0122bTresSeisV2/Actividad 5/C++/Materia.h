#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED

using namespace std;

class Materia
{
private:
    string nombre;
    string acronimo;
    string profesor;
    string dias;
    int horaInicio;
    int horaFin;





public:
    Materia(string nombre,string acronimo,string profesor,string dias,int horaInicio,int horaFin)
    {
        this->nombre=nombre;
        this->acronimo=acronimo;
        this->profesor=profesor;
        this->dias=dias;
        this->horaInicio=horaInicio;
        this->horaFin=horaFin;
    }
    void fijaNombre(string n)
    {
        nombre=n;
    }
    void fijaAcronimo(string a)
    {
        acronimo=a;
    }
    void fijaProfesor(string p)
    {
        profesor=p;
    }
    void fijaDias(string d)
    {
        dias=d;
    }
    void fijaHoraInicio(int h)
    {
        horaInicio=h;
    }
    void fijaHoraFin(int h)
    {
        horaFin=h;
    }
    string dameNombre()
    {
        return nombre;
    }
    string dameAcronimo()
    {
        return acronimo;
    }
    string dameNombreProfesor()
    {
        return profesor;
    }
    string dameDias()
    {
        return dias;
    }
    int dameHoraInicio()
    {
        return horaInicio;
    }
    int dameHoraFin()
    {
        return horaFin;
    }
};

#endif // MATERIA_H_INCLUDED
