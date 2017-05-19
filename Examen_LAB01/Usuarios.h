
typedef struct {
    int idUsuario;
    char nombreUsuario[50];
    char Password[20];
    int flag;
    int calificacion;
}eUsuario;



/** \brief  Se marcan todas las posiciones del array como libres
 *          colocando en cada elmento el flag de flag en TRUE
 * \param eusuario* usuario Puntero al array de usuarios
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 */
int initUsuario(eUsuario* usuario, int length);
/** \brief  Busca en el array la primer posicion libre
 * \param eUsuario* usuario Puntero al array de usuarios
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (i del lugar libre) si Ok
 */
int buscarLugarLibreU(eUsuario* usuario, int length);
/** \brief  Agrega un usuario al  array de usuarios
 * \param eusuario* usuario Puntero al array de usuarios
 * \param length int Longitud del array
 * \param id el id que se ingresa pro consola
 * \param usuario* usuario, puntero  al  array  usuario
 * \param lengthU int Longitud del array usuario
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]   si no  se pudo  ingresar el dato - >0 si Ok
 *
 */
int addToArrayU(eUsuario* usuario, int length);
/** \brief  Busca y  muestra el el valor del  usuario  ingresando  un  idusuario y  una vez confirmado  el  usuario,  busca el  id del usuario
 * \param eusuario* usuario Puntero al array de usuarios
 * \param length int Longitud del array
 * \param id el id que se ingresa pro consola del  usuario
  * \param eUsuario* usuario Puntero al array de usuario
 * \return devuelve -1 si  no  lo  encontro, me devuerlve el id si  lo  encuentro
 */
int BuscarUsuarioPorID(eUsuario* usuario, int length,  int id);//devuelve -1 si  no  lo  encontro
/** \brief Pone el flag  en -1 para indicar que ese usuario se elimina
 * \param eusuario* usuario Puntero al array de usuarios
 * \param length int Longitud del array
 * \param id el id que se ingresa pro consola del  usuario
 * \return devuelve -1 si  no  lo  encontro, me devuerlve la 0 si   pudo eliminarse
 */
int ModificarUsuario(eUsuario* usuario, int length, int id);
/** \brief Pone el flag  en 2 para indicar que ese usuario se compro
 * \param eusuario* usuario Puntero al array de usuarios
 * \param length int Longitud del array
 * \param id el id que se ingresa pro consola del  usuario
 * \return devuelve -1 si  no  lo  encontro, me devuerlve la 0 si   pudo comprar
 */
int bajaUsuario(eUsuario* usuario, int length, int id);

void HarcodeoUsuarios(eUsuario* usuario, int length);
