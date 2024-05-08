using namespace std;

class estacion
{
private:
    int Tiemposiguiente, Tiempoanterior;
    string Nombre;
    bool Transferencia =false;
    bool Vacio=false;
public:
    estacion(int *tiemposig, int *tiempoant, string *nombre);
    estacion();
    void SetNombre(string*nombre);
    void SetTiempoSiguiente(int* tiemposig);
    void SetTransferencia(bool*transfe);
    void SetTiempoAnterior(int* tiempoant);
    string GetNombre();
    int GetTiempoSiguiente();
    int GetTiempoAnterior();
    bool GetTransferencia();
    string NombreOriginal();
    bool EsVacio();
    ~estacion();
};
#endif // ESTACION_H