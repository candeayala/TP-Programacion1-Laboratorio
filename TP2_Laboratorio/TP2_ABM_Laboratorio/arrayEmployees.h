#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
#define TRUE 0
#define FALSE -1

typedef struct{
char name[20];
char lastName[20];
int id;
float salary;
int sector;
int isEmpty;

}eEmployee;


    /** \brief To indicate that all positions in the array are empty,
 * this function puts the flag (isEmpty) as a TRUE value
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(eEmployee* lista, int len);


    /** \brief Obtains free slot from the index.
 *
 * \param eEmployee list
 * \param int len, array lenght
 *
 * \return int Return (-1) if Error [invalid length or NULL pointer] - (i) if it succeded
 */
int toFindFreeSlot(eEmployee* lista, int len);



/** \brief Menu that indicates "Alta, Modificacion, Baja y Salir"
 *
 * \param void
 * \return int options "alta, modificacion, baja y salir"
 *
 */
int menu();


    /** \brief Adds in an existing list of employees the values received as parameters
 * in the first empty position
 *
 * \param list of employees*
 * \param lenght int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if it gives error [invalid length, NULL pointer or out of
free space] - (0) if it succeded
*/
int addEmployee(eEmployee* lista, int len, int id, char* name, char* lastName, float salary, int sector);


    /** \brief Finds an employee by Id and returns the array position
 *
 * \param list employee*
 * \param lenght int
 * \param id int
 * \return employee index position or (-1) if [invalid length or NULL pointer]
 */
int findEmployeeById(eEmployee* lista, int len, int id);

    /** \brief Erase an employee by calling the Id
 *
 * \param list Employee*
 * \param lenght int
 * \param id int
 * \return int Return (-1) if it gives error[Invalid length or NULL pointer] - (0) if it succeded
 *
 */
int eraseEmployee(eEmployee* lista, int len, int id);

    /** \brief Modifies an employee's data
 *
 * \param list sEmployee*
 * \param len int
 * \param id int
 * \return
 *
 */
int modifyEmployee(eEmployee* lista, int len, int id);

    /** \brief Prints the data of ONE employee
 *
 * \param list eEmployee*
 * \param index int (locates the employee by id)
 * \return
 */
int printEmployee(eEmployee* lista, int index);

    /** \brief Prints the data of a list of employees
 *
 * \param list eEmployee*
 * \param int lenght
 * \return prints the list of employees.
 */
int printEmployees(eEmployee* lista, int len);


    /** \brief Calculates the average
 *
 * \param list eEmployee*
 * \param int lenght
 * \return
 *
 */
int getAverageSalary(eEmployee* lista, int len);

/** \brief Returns the order selected
 *
 * \return int [0] - DOWN // [1] UP
 *
 */
int getOrder();

/** \brief Sort the elements in the array in alphabetic order
 *
 * \param list Employee*
 * \param lenght int
 * \param order int [1] to indicate ascendant or [0] to indicate descendant
 * \return int Return (-1) if Error [Invalid length or NULL pointer]
 *
 */
int sortEmployees(eEmployee* lista, int len, int order);


#endif
