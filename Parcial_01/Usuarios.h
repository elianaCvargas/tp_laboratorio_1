
typedef struct {
    int idUsuario;
    char nombreUsuario[50];
    char Password[20];
    int flag;
    //int cantProductos;
}eUsuario;

int initUsuario(eUsuario* usuario, int length);
int buscarLugarLibreU(eUsuario* usuario, int length);
int addToArrayU(eUsuario* usuario, int length);
int BuscarUsuarioPorID(eUsuario* usuario, int length,  int id);//devuelve -1 si  no  lo  encontro
int ModificarUsuario(eUsuario* usuario, int length, int id);
int bajaUsuario(eUsuario* usuario, int length, int id);
