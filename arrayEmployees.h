#ifndef EMPLOYEES_H_INCLUDED
#define EMPLOYEES_H_INCLUDED


typedef struct{
    int id;
    char name[20];
    char lastName[20];
    float salary;
    int sector;
    int isEmpty;  // 1 vacia 0 cargada
} eEmployee;

#endif // EMPLOYEES_H_INCLUDED

/** \brief  Para indicar que todas las posiciones de la matriz est‡n vac’as,
 * esta funci—n pone la bandera (isEmpty) en 1 en todas las posiciones.
 * \param lista de arrays de empleados
 * \param tama–o maximo de la lista
 * \return nt retorna -1 en de no inicializar y 0 en caso exitoso
 */
int initEmployees(eEmployee employees[],int tam);

/** \brief  Me imprime el listado de los empleados dados de alta
 * \param lista de arrays de empleados
 * \param tama–o maximo de la lista
 * \return int retorna -1 en caso de error o de lista vacia y 0 en caso que muestre la lista
 *
 */
int printEmployees(eEmployee employees[], int tam);

/** \brief  Me imprime 1 solo empleado con sus campos correspondientes
 * \param Un empleado de la lista de los dados de alta
 * \return no retorna nada
 *
 */
void printEmployee(eEmployee employee);

/** \brief Me permite dar de alta un empleado completando sus campos por el usuario
 * \param lista de arrays de empleados
 * \param tama–o maximo de la lista
 * \param numero de legajo del empleado
 * \return int retorna -1 en caso de error y 0 en caso de alta exitosa
 *
 */
int addEmployee(eEmployee employees[], int tam, int id);

/** \brief Busca el primer lugar libre para dar de alta un empleado nuevo
 * \param lista de arrays de empleados
 * \param tama–o maximo de la lista
 * \return int retorna -1 en caso de error y sino retorna el indice libre
 *
 */
int searchFreePlace(eEmployee employees[],int tam);

/** \brief Busca empleados por su id
 * \param lista de arrays de empleados
 * \param tama–o maximo de la lista
 * \param id del empleado
 * \return int retorna -1 en caso de error y sino retorna el id del empleado
 *
 */
int findEmployeeById(eEmployee employees[], int tam, int id);

/** \brief Me borra un empleado de la lista
 * \param lista de arrays de empleados
 * \param tama–o maximo de la lista
 * \return int retorna -1 en caso de error, 0 en caso de baja exitosa o 2 si
 * el usuario cancela la baja
 *
 */
int removeEmployee(eEmployee employees[], int tam);

/** \brief valida que no ingresemos una opcion que no este en el menu
 * \param entero a evaluar
 * \return int retorna 1 en caso que sea una opcion valida y 0 en caso opcion invalida
 *
 */
int validarOpcion(int a);

/** \brief Me permite modificar los campos de un empleado
 * \param lista de arrays de empleados
 * \param tama–o maximo de la lista
 * \return int retorna 1 en caso de error, 0 en caso de modificacion exitosa o 2 si
 * el usuario cancela la modificacion
 *
 */
int modificarEmpleado(eEmployee employees[], int tam);

/** \brief valida que no ingresemos un sector de la empresa que no exista
 * \param entero a evaluar
 * \return int retorna 1 en caso que sea una opcion valida y 0 en caso opcion invalida
 *
 */
int validarSector(int a);

/** \brief valida que no ingresemo un salario nulo o negativo
 * \param entero a evaluar
 * \return int retorna 1 en caso que sea una opcion valida y 0 en caso opcion invalida
 *
 */
int validarSalario(int a);

/** \brief Me ordena la lista de empleados alfabeticamente por el apellido
 * \param lista de arrays de empleados
 * \param tama–o maximo de la lista
 * \return int retorna 1 en caso de error, 0 en caso de ordenamiento exitoso
 *
 */
int sortEmployeeByName(eEmployee employees[], int tam);

/** \brief Me ordena la lista de empleados de menos a mayor por numero de sector
 * \param lista de arrays de empleados
 * \param tama–o maximo de la lista
 * \return int retorna 1 en caso de error, 0 en caso de ordenamiento exitoso
 *
 */
int sortEmployeeBySector(eEmployee employees[], int tam);

/** \brief Acumula el total de sueldos de todos los empleados de la empresa
 * \param lista de arrays de empleados
 * \param tama–o maximo de la lista
 * \return float retorna el total de sueldos
 */
float totalSueldos(eEmployee employees[], int tam);

/** \brief Calcula el promedio de sueldos de la empresa
 * \param lista de arrays de empleados
 * \param tama–o maximo de la lista
 * \return float retorna el promedio de sueldos
 */
float promedioSueldos(eEmployee employees[], int tam);

/** \brief Acumula el total de empleados que cobran mas que la media
 * \param lista de arrays de empleados
 * \param tama–o maximo de la lista
 * \return int retorna la cantidad de empleados que cobran mas que la media
 */
int cobranMasQuePromedio(eEmployee employees[], int tam);


/** \brief valida el ingreso de cadena de caracteres
 * \param cadena de caracteres
 * \return int retorna 1 si es una cadena valida o 0 en caso de cadena invalida
 */
int validarCadena(char cadena[]);
