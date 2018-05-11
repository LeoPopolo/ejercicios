/** \brief funcion que valida que el caracter ingresado sea letra o no
 *
 * \param caracter a validar
 * \return 0 si es digito 1 si no lo es
 *
 */

int validarLetra(char opcion[]);

/** \brief funcion que valida la cantidad de productos ingresada
 *
 *  \return la cantidad validada
 *
 */

int ingresoCantVal();

/** \brief funcion del menu principal
 *
 * \return el case a elegir
 *
 */

int menu();

/** \brief funcion que posiciona el cursor en una posicion del eje x,y
 *
 * \param coordenada x
 * \param coordenada y
 * \return void
 *
 */

void gotoxy(int x,int y);

/** \brief funcion del submenu opcion 4 (informar)
 *
 * \return el case a elegir
 *
 */

int menuOpcion4();

/** \brief funcion del submenu opcion 5 (listar)
 *
 * \return el case a elegir
 *
 */
int menuOpcion5();
