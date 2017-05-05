
typedef struct {
    int idProducto;
    int idUsuario;
    char nombreProducto[50];
    int precio;
    int stock;
    int cantUsuarios;
    int flag;
}eProducto;

int initProducto(eProducto* producto, int length);
int buscarLugarLibreP(eProducto* producto, int length);
int addToArrayP(eProducto* producto, int lengthP, int id, eUsuario* usuario,int lengthU);
