#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>


typedef struct empleados {
    char apellidos[30];
    char nombre[15];
    int  matricula;
    //char bufferRelleno[50000];
} tipoEmpleado;


void cargarRegistrosAleatorios(tipoEmpleado * empleados, int numEmpleados);
void cargarUnRegistro(tipoEmpleado * empleado);

void mostrarRegistro(tipoEmpleado empleado);
void mostrarRegistrosRef(tipoEmpleado ** refsEmpleados, int numEmpleados);
void mostrarRegistros(tipoEmpleado * empleados, int numEmpleados);

void ordenarRegistrosRefApellido(tipoEmpleado ** refsEmpleados, int numEmpleados);
void ordenarRegistrosApellido(tipoEmpleado * empleados, int numEmpleados);



void ordenarRegistrosRefNombre(tipoEmpleado ** refsEmpleados, int numEmpleados); 
void ordenarRegistrosNombre(tipoEmpleado *empleados, int numEmpleados); 
void ordenarRegistrosRefMatricula(tipoEmpleado ** refsEmpleados, int numEmpleados);
void ordenarRegistrosMatricula(tipoEmpleado *empleados, int numEmpleados);

int buscarRegistroNombre(char *nombre, tipoEmpleado *empleados, int numEmpleados); 
int buscarRegistroRefNombre(char *nombre, tipoEmpleado ** refsEmpleados,  int numEmpleados); 

void modificarRegistro(tipoEmpleado *empleado); 
#define NUM_EMPLEADOS   10


int
main(void)
{
    tipoEmpleado regEmpleados[NUM_EMPLEADOS], unEmpleado;
    tipoEmpleado *regEmpleadosRef[NUM_EMPLEADOS];
    int i;
    clock_t tiempoInicial, tiempoFinal;
    char nombreBuscar[15];
    int nRegistro;
    
    
    
    cargarRegistrosAleatorios(regEmpleados, NUM_EMPLEADOS);
    
    mostrarRegistros(regEmpleados, NUM_EMPLEADOS);
    
    printf("\n\n Jugando con un único registro: \n");
    unEmpleado = regEmpleados[2];
    mostrarRegistro(unEmpleado);
    mostrarRegistro(regEmpleados[2]);
    mostrarRegistros(&unEmpleado, 1);
    
    //    cargarUnRegistro(&unEmpleado);
    //    printf("\n\nEl registrocargado es: \n");
    //    mostrarRegistro(unEmpleado);
    //    printf("\ny el registro regEmpleados[2] es: \n");
    //    mostrarRegistro(regEmpleados[2]);
    
    for (i = 0; i < NUM_EMPLEADOS; i++)
	    regEmpleadosRef[i] = &regEmpleados[i];
    


    printf("d888888P  88888888b .d88888b  d888888P .d88888b  \n");
    printf("   88     88        88.   \"'    88    88.   \"' \n");
    printf("   88    a88aaaa    `Y88888b.    88    `Y88888b. \n");
    printf("   88     88              `8b    88          `8b \n");
    printf("   88     88        d8'   .8P    88    d8'   .8P \n");
    printf("   dP     88888888P  Y88888P     dP     Y88888P  \n");
    printf("ooooooooooooooooooooooooooooooooooooooooooooooooo\n");


    printf("\n\nValores no clasificados (a través matriz punteros): \n");
    mostrarRegistrosRef(regEmpleadosRef, NUM_EMPLEADOS);
    
    tiempoInicial = tiempoFinal = clock ();
    ordenarRegistrosRefApellido(regEmpleadosRef, NUM_EMPLEADOS);
    tiempoFinal = clock ();
    
    
    printf("\n\nValores clasificados (a través matriz punteros): \n");
    printf("Tiempo tardado: %f\n",(tiempoFinal-tiempoInicial)/(double)CLOCKS_PER_SEC);
    mostrarRegistrosRef(regEmpleadosRef, NUM_EMPLEADOS);
    
    printf("\n\nAhora valores no clasificados matriz de registros original: \n");
    mostrarRegistros(regEmpleados, NUM_EMPLEADOS);
    
    tiempoInicial = tiempoFinal = clock ();
    ordenarRegistrosApellido(regEmpleados, NUM_EMPLEADOS);
    tiempoFinal = clock ();
    
    printf("\n\nAhora valores clasificados matriz de registros original: \n");
    printf("Tiempo tardado: %f\n",(tiempoFinal-tiempoInicial)/(double)CLOCKS_PER_SEC);
    mostrarRegistros(regEmpleados, NUM_EMPLEADOS);

    ordenarRegistrosRefNombre( regEmpleadosRef,NUM_EMPLEADOS);
    printf("\n\nAhora vemos los registros ordenados por nombre por vector de punteros:\n");
    printf("Tiempo tardado: %f\n",(tiempoFinal-tiempoInicial)/(double)CLOCKS_PER_SEC);
    mostrarRegistrosRef(regEmpleadosRef,NUM_EMPLEADOS);

    ordenarRegistrosNombre(regEmpleados,NUM_EMPLEADOS);
    printf("\n\nAhora vemos los registros ordenados por nombre en el vector de struct:\n");
    printf("Tiempo tardado: %f\n",(tiempoFinal-tiempoInicial)/(double)CLOCKS_PER_SEC);
    mostrarRegistros(regEmpleados,NUM_EMPLEADOS);

    ordenarRegistrosRefMatricula(regEmpleadosRef,NUM_EMPLEADOS);
    printf("\n\nAhora vemos los registros ordenados por matricula en el vector de punteros:\n");
    printf("Tiempo tardado: %f\n",(tiempoFinal-tiempoInicial)/(double)CLOCKS_PER_SEC);
    mostrarRegistrosRef(regEmpleadosRef,NUM_EMPLEADOS);

    ordenarRegistrosMatricula(regEmpleados,NUM_EMPLEADOS);
    printf("\n\nAhora vemos los registros ordenados por matricula en el vector de struct:\n");
    printf("Tiempo tardado: %f\n",(tiempoFinal-tiempoInicial)/(double)CLOCKS_PER_SEC);
    mostrarRegistros(regEmpleados,NUM_EMPLEADOS);

    printf("\n\nAhora vemos la búsqueda de un nombre:\n");
    printf("Introduce el nomre a buscar: ");
    scanf(" %s",nombreBuscar);
    nRegistro= buscarRegistroNombre(nombreBuscar, regEmpleados, NUM_EMPLEADOS);

    printf("\n\nAhora vemos la búsqueda de un nombre por punteros:\n");
    printf("Introduce el nomre a buscar: ");
    scanf(" %s",nombreBuscar);
    nRegistro=buscarRegistroRefNombre(nombreBuscar, regEmpleadosRef,  NUM_EMPLEADOS); 


    printf(" 888888ba   888888ba   .88888.   .88888.   888888ba   .d888888  8888ba.88ba  \n");
    printf(" 88    `8b  88    `8b d8'   `8b d8'   `88  88    `8b d8'    88  88  `8b  `8b \n");
    printf("a88aaaa8P' a88aaaa8P' 88     88 88        a88aaaa8P' 88aaaaa88a 88   88   88\n");
    printf(" 88         88   `8b. 88     88 88   YP88  88   `8b. 88     88  88   88   88\n");
    printf(" 88         88     88 Y8.   .8P Y8.   .88  88     88 88     88  88   88   88 \n");
    printf(" dP         dP     dP  `8888P'   `88888'   dP     dP 88     88  dP   dP   dP \n");
    printf("ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n");

    printf("VISUALIZACION DE DATOS:\n");
    mostrarRegistros(regEmpleados,NUM_EMPLEADOS);
    printf("Introduce el nomre a buscar: ");
    scanf(" %s",nombreBuscar);
    nRegistro= buscarRegistroNombre(nombreBuscar, regEmpleados, NUM_EMPLEADOS);
    modificarRegistro(&regEmpleados[nRegistro-1]); 
    mostrarRegistros(regEmpleados,NUM_EMPLEADOS);
    

    return 0;
}

void
cargarRegistrosAleatorios(tipoEmpleado * empleados, int numEmpleados)
{
    int i;
    static char apellidos [][15] = {"ALONSO","ALVAREZ","ARBESU",
        "DOMINGUEZ","FERNANDEZ","FLORIANO",
        "GONZALEZ","GOMEZ","GUTIERREZ",
        "MARTIN", "MORO", "PEREZ","TURRION",
        "ZAMBRANO"};
    static char nombres [][15] = {"ALVARO","ARSENIO","DOMINGO",
        "FELIPE","FATIMA","FABIAN",
        "GONZALO","PEDRO","PATRICIA",
        "TOMAS", "ZOILO"};
    int numApellidos = sizeof(apellidos)/15;
    int numNombres = sizeof(nombres)/15;
    char buffer[5];
    
    srandom(time(NULL));
    for (i = 0; i < numEmpleados; i++) {
        sprintf(empleados[i].apellidos,"%s %s",apellidos[random() % numApellidos],
                apellidos[random() % numApellidos]);
        sprintf(empleados[i].nombre,"%s",nombres[random() % numNombres]);
        sprintf(buffer,"%c%c%c%c",(char)('0' + random() % 10),
                (char)('0' + random() % 10),
                (char)('0' + random() % 10),
                (char)('0' + random() % 10));
        empleados[i].matricula = atoi(buffer);
    }



}


void
cargarUnRegistro(tipoEmpleado * empleado)
{   
    printf("Escribe el nombre del empleado:\n");
    gets(empleado->nombre);

    printf("Escribe el el apellido del empleado\n");
    gets(empleado->apellidos);

    printf("Introduzca la matricula\n");
    scanf("%d",&empleado->matricula);

    /*
     * Esta función recibe un ÚNICO REGISTRO de tipo tipoEmpleado
     * y el alumno debe escribir el código necesario para que
     * se pidan los datos necesarios por pantalla y cargar
     * los campos del registro con los datos introducidos 
     * por teclado por el usuario
     */
    
}

//FUNCIONES DE MOSTRAR
void
mostrarRegistro(tipoEmpleado empleado)
{
    printf("DATOS DEL EMPLEADO\n");
    printf("Nombre: %s Apellidos: %s Matricula: %d\n",empleado.nombre,empleado.apellidos,empleado.matricula);

    /*
     * Esta función muestra por pantalla y en una única línea 
     * los datos almacenados en los campos del registro
     * recibido
     */
}


void
mostrarRegistros(tipoEmpleado * empleados, int numEmpleados)
{   

    int i;

    for(i=0;i<numEmpleados;i++){
        printf("EMPLEADO NUMERO %d ",i+1);
        printf("Nombre: %s ",empleados[i].nombre);
        printf("Apellidos: %s ",empleados[i].apellidos);
        printf("Matricula: %d ",empleados[i].matricula);
        printf("\n");
    }


    /*
     * Esta función recibe un vector de registros de tipoEmpleado
     * de tamaño numEmpleados, y muestra por pantalla el contenido
     * de los campos de todos los registros de dicho vector, un 
     * registro por línea
     */
    
}

void
mostrarRegistrosRef(tipoEmpleado ** refsEmpleados, int numEmpleados)
{   
    int i;

    for(i=0;i<numEmpleados;i++){
        printf("EMPLEADO NUMERO %d ",i+1);
        printf("Nombre: %s ",refsEmpleados[i]->nombre);
        printf("Apellidos: %s ",refsEmpleados[i]->apellidos);
        printf("Matricula: %d ",refsEmpleados[i]->matricula);
        printf("\n");
    }
    

    /*
     * Esta función recibe un vector de  punteros a registros de
     * tipoEmpleado, de tamaño numEmpleados (el vector), y muestra por pantalla
     * el contenido de los campos de todos los registros referenciados
     * por los punteros del vector, mostrando un registro por línea
     */
}



//FUNCIONES DE ORDENAR
void
ordenarRegistrosApellido(tipoEmpleado * empleados, int numEmpleados)
{
    int i,j;
    tipoEmpleado temp;
    
    for (i = 0; i < numEmpleados - 1 ; i++) {
        for (j = numEmpleados-1; j > i; j--) {
            if ((strcmp(empleados[j].apellidos, empleados[j - 1].apellidos)) < 0) {
                temp = empleados[j];
                empleados[j] = empleados[j - 1];
                empleados[j - 1] = temp;
            }
        }
    }
}


void
ordenarRegistrosNombre(tipoEmpleado *empleados, int numEmpleados){
    int i,j;
    tipoEmpleado temp;
    
    for (i = 0; i < numEmpleados - 1 ; i++) {
        for (j = numEmpleados-1; j > i; j--) {
            if ((strcmp(empleados[j].nombre, empleados[j - 1].nombre)) < 0) {
                temp = empleados[j];
                empleados[j] = empleados[j - 1];
                empleados[j - 1] = temp;
            }
        }
    }

}


void 
ordenarRegistrosMatricula(tipoEmpleado *empleados, int numEmpleados){
    int i,j;
    tipoEmpleado temp;
    
    for (i = 0; i < numEmpleados - 1 ; i++) {
        for (j = numEmpleados-1; j > i; j--) {
            if (empleados[j].matricula < empleados[j - 1].matricula) {
                temp = empleados[j];
                empleados[j] = empleados[j - 1];
                empleados[j - 1] = temp;
            }
        }
    }


}


void
ordenarRegistrosRefApellido(tipoEmpleado ** refsEmpleados, int numEmpleados)
{   
    int i,j;
    tipoEmpleado *temp;
    
    for (i = 0; i < numEmpleados - 1 ; i++) {
        for (j = numEmpleados-1; j > i; j--) {
            if ((strcmp(refsEmpleados[j]->apellidos, refsEmpleados[j - 1]->apellidos)) < 0) {
                temp = refsEmpleados[j];
                refsEmpleados[j] = refsEmpleados[j - 1];
                refsEmpleados[j - 1] = temp;
            }
        }
    }

        /*
         * Esta función es análoga a la función ordenarRegistrosApellido
         * pero con la diferencia que en vez de recibir un vector de 
         * registros, recibe un vector de punteros a registros. La función
         * utiliza el mismo algoritmo de ordenación (burbuja) para ordenar
         * pero en vez de ordenar los registros, se ordenará el vector
         * de punteros, utilzando la información del campo apellidos
         * del registro apuntado. 
         */
    
}

void ordenarRegistrosRefNombre(tipoEmpleado ** refsEmpleados, int numEmpleados){
    int i,j;
    tipoEmpleado *temp;
    for (i = 0; i < numEmpleados - 1 ; i++) {
        for (j = numEmpleados-1; j > i; j--) {
            if ((strcmp(refsEmpleados[j]->nombre, refsEmpleados[j - 1]->nombre)) < 0) {
                temp = refsEmpleados[j];
                refsEmpleados[j] = refsEmpleados[j - 1];
                refsEmpleados[j - 1] = temp;
            }
        }
    }


}

void ordenarRegistrosRefMatricula(tipoEmpleado ** refsEmpleados, int numEmpleados){
    int i,j;
    tipoEmpleado *temp;
    for (i = 0; i < numEmpleados - 1 ; i++) {
        for (j = numEmpleados-1; j > i; j--) {
            if (refsEmpleados[j]->matricula < refsEmpleados[j - 1]->matricula ) {
                temp = refsEmpleados[j];
                refsEmpleados[j] = refsEmpleados[j - 1];
                refsEmpleados[j - 1] = temp;
            }
        }
    }
}


//BUSQUEDAS

int 
buscarRegistroNombre(char *nombre, tipoEmpleado *empleados, int numEmpleados)
{
    int i;
    int flag=1;


    for(i=0;nombre[i]!='\0';i++){
        nombre[i]= toupper(nombre[i]);
    }
     
    for(i=0;i<numEmpleados && flag;i++){

        if(strcmp(nombre,empleados[i].nombre) == 0 ){ //no ponemos *nombre ya que es cadena de caracteres
            printf("REGISTRO ENCONTRADO\n");
            printf("Nombre: %s ",empleados[i].nombre);
            printf("Apellidos %s ",empleados[i].apellidos);
            printf("Matricula %d \n",empleados[i].matricula);
            flag=0;
        }

        //printf("BUCLE: %d",i);

    }
    if (flag==1)
            printf("NO SE ENCONTRO EL REGISTRO\n");
    
    //printf("%d\n",i);
        return i;


}

int 
buscarRegistroRefNombre(char *nombre, tipoEmpleado ** refsEmpleados,  int numEmpleados)
{
    int i;
    int flag=1;


    for(i=0;nombre[i]!='\0';i++){
        nombre[i]= toupper(nombre[i]);
    }
     
    for(i=0;i<numEmpleados && flag;i++){

        if(strcmp(nombre,refsEmpleados[i]->nombre) == 0 ){ //no ponemos *nombre ya que es cadena de caracteres
            printf("REGISTRO ENCONTRADO\n");
            printf("Nombre: %s ",refsEmpleados[i]->nombre);
            printf("Apellidos %s ",refsEmpleados[i]->apellidos);
            printf("Matricula %d ",refsEmpleados[i]->matricula);
            flag=0;
        }

        //printf("BUCLE: %d",i);

    }
    if (flag==1)
            printf("NO SE ENCONTRO EL REGISTRO\n");

        return i;


}

void 
modificarRegistro(tipoEmpleado *empleado)
{
    printf("DATOS ACTUALES: \n");
    printf("Nombre: %s \n",empleado->nombre);
    printf("Apellidos: %s \n",empleado->apellidos);
    printf("Matricula: %d \n",empleado->matricula);
    printf("=======================================\n");
    printf("Introduce nuevo nombre: ");
    scanf(" %s",empleado->nombre);
    printf("Introduce nuevo apellido: ");
    scanf(" %s",empleado->apellidos);
    printf("Introduce nueva matricula: ");
    scanf("%d",&empleado->matricula);
} 