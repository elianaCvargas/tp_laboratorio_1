
typedef struct {
    int idProducto;
    int idUsuario;
    //eUsuario idUsuario2;
    char nombreProducto[50];
    float precio;
    int stock;
    int cantidadVendida;
    int flag;
}eProducto;
/** \brief  Se marcan todas las posiciones del array como libres
 *          colocando en cada elmento el flag de flag en TRUE
 *
 * \param eProducto* producto Puntero al array de productos
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */
int initProducto(eProducto* producto, int length);
/** \brief  Busca en el array la primer posicion libre
 * \param eProducto* producto Puntero al array de productos
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (index del lugar libre) si Ok
 *
 */

int buscarLugarLibreP(eProducto* producto, int length);
/** \brief  Agrega un producto al  array de productos
 * \param eProducto* producto Puntero al array de productos
 * \param length int Longitud del array
 * \param id el id que se ingresa pro consola
 * \param usuario* usuario, puntero  al  array  usuario
 * \param lengthU int Longitud del array usuario
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]   si no  se pudo  ingresar el dato - >0 si Ok
 *
 */
int addToArrayP(eProducto* producto, int lengthP, int id, eUsuario* usuario,int lengthU);
/** \brief  Busca el el valor del  producto  ingresando  un  id
 * \param eProducto* producto Puntero al array de productos
 * \param length int Longitud del array
 * \param id el id que se ingresa pro consola
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]   si no  se pudo  ingresar el dato - id si Ok
 *
 */
int BuscarProductoPorID(eProducto* producto, int length,  int id);//devuelve -1 si  no  lo  encontro, me devuerlve el id si  lo  encuentro
/** \brief  Busca y  muestra el el valor del  producto  ingresando  un  idusuario y  una vez confirmado  el  usuario,  busca el  id del producto
 * \param eProducto* producto Puntero al array de productos
 * \param length int Longitud del array
 * \param id el id que se ingresa pro consola del  usuario
  * \param eUsuario* usuario Puntero al array de usuario
 * \return devuelve -1 si  no  lo  encontro, me devuerlve el id si  lo  encuentro
 */
int BuscarYMostrarPorIDP(eProducto* usuarioP, int length,int id, eUsuario* usuario, int lengthU);//devuelve -1 si  no  lo  encontro, me devuerlve el id si  lo  encuentro
/** \brief  Busca  del  producto  ingresando  un  idProducto
 * \param eProducto* producto Puntero al array de productos
 * \param length int Longitud del array
 * \param id el id que se ingresa pro consola del  producto
  * \param eUsuario* usuario Puntero al array de usuario
 * \return devuelve -1 si  no  lo  encontro, me devuerlve la posicion si  lo  encuentro
 */
int BuscarPosicionPorIDP(eProducto* producto, int length,  int id);
/** \brief  Modifica el  producto  con el  id que ingresa el usuario
 * \param eProducto* producto Puntero al array de productos
 * \param length int Longitud del array
 * \param id el id que se ingresa pro consola del  producto
 * \return devuelve -1 si  no  lo  encontro, me devuerlve la 0 si   pudo modificarse
 */
int ModificarProducto(eProducto* producto, int length, int idP/*,eUsuario* usuario, int lengthU,int idU*/);
/** \brief Pone el flag  en -1 para indicar que ese producto se elimina
 * \param eProducto* producto Puntero al array de productos
 * \param length int Longitud del array
 * \param id el id que se ingresa pro consola del  producto
 * \return devuelve -1 si  no  lo  encontro, me devuerlve la 0 si   pudo eliminarse
 */
int DeleteProducto(eProducto* producto, int length, int idP/*,eUsuario* usuario, int lengthU,int idU*/);
/** \brief Pone el flag  en 2 para indicar que ese producto se compro
 * \param eProducto* producto Puntero al array de productos
 * \param length int Longitud del array
 * \param id el id que se ingresa pro consola del  producto
 * \return devuelve -1 si  no  lo  encontro, me devuerlve la 0 si   pudo comprar
 */
//int ComprarProducto(eProducto* producto, int length, int idP/*,eUsuario* usuario, int lengthU,int idU*/);
int ComprarProducto(eProducto* producto, int length, int idP, eUsuario* usuario, int lengthU);
/** \brief  Busca  del  producto  ingresando  un  idProducto si  lo  encuentra,  muestro  sus datos
 * \param eProducto* producto Puntero al array de productos
 * \param length int Longitud del array
 * \param id el id que se ingresa pro consola del  producto
  * \param eUsuario* usuario Puntero al array de usuario
 * \
 */
void mostrarProductosUsuarios(eProducto producto, eUsuario usuario, int lengthU, int idU);
/** \brief muestro  la lista de todos los productos que esten  dados de alta (flag =1)
 * \param eProducto* producto Puntero al array de productos
 * \param length int Longitud del array
  * \param eUsuario* usuario Puntero al array de usuario
 * \param lenghtU longitud del  array
 */
void MostrarListaProductos(eProducto* producto,  int length, eUsuario* usuario, int lengthU);

void HarcodeoProductos(eProducto* producto, int length);

int BuscarYMostrarProducto(eProducto* producto, int length,int id);

