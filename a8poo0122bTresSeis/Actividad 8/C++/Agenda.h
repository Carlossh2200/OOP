#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

class Agenda{
    string asunto;
    string tipo;
    string fecha;
    string hora;




















public:
    Agenda(string asunto,string tipo,string fecha,string hora){
        this->fijaAsunto(asunto);
        this->fijaTipo(tipo);
        this->fijaFecha(fecha);
        this->fijaHora(hora);
    }
    void fijaAsunto(string a){
        asunto=a;
    }
    void fijaTipo(string t){
        tipo=t;
    }
    void fijaFecha(string f){
        fecha=f;
    }
    void fijaHora(string n){
        hora=n;
    }
    string dameAsunto(){
        return asunto;
    }
    string dameTipo(){
        return tipo;
    }
    string dameFecha(){
        return fecha;
    }
    string dameHora(){
        return hora;
    }
};

#endif // AGENDA_H_INCLUDED
