#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define NUM_MESES  12
#define NUM_COMERCIALES	30

//definici�n de struct tipoComercial 


//prototipo de la funci�n calcularPromedios
struct tipoComercial{
	char nombre[80];
	char nif[10];
	int ventas[NUM_MESES];

};

void cargarRegistrosAleatorios(struct tipoComercial *comerciales, int numComerciales);
int calcularPromedios(struct tipoComercial *comerciales,int numComerciales, float *promediosComerciales,float *promediosMeses);






int
main (void)
{
    struct tipoComercial comerciales[NUM_COMERCIALES];
	float promediosComerciales[NUM_COMERCIALES], promediosMeses[NUM_MESES];
	int num, pos, numReg, res, i, j;
	
	//do-while para solicitar el n�mero de cormerciales-->num
	do{
		printf("Numero de comerciales: ");
		scanf("%d",&num);
	}while(num<=0);
    
	cargarRegistrosAleatorios(comerciales,num);
    printf("\nLos comerciales son: %d\n", num);
    for (i = 0; i < num; i++){
		printf("Reg: %10s -> %-30s\n",comerciales[i].nif,comerciales[i].nombre);
		printf("Ventas: ");
		for (j = 0; j < NUM_MESES; j++) {
			printf("\t%5d", comerciales[i].ventas[j]);
		}
		printf("\n");
    }
    
	//llamada a la funci�n calcularPromedios y recoger el valor en la variable res
	res= calcularPromedios(comerciales,NUM_COMERCIALES,promediosComerciales,promediosMeses);	
	printf("\nPromedios por comerciales: \n");
	for(i = 0; i < num; i++){
		printf("Reg: %10s -> %-30s\n",comerciales[i].nif,comerciales[i].nombre);
		printf("Ventas: ");
		for (j = 0; j < NUM_MESES; j++) {
			printf("\t%5d", comerciales[i].ventas[j]);
		}
		printf("\n");
		printf("Promedio comercial: %6.2f\n", promediosComerciales[i]);
	}
	
	for(i = 0; i < NUM_MESES; i++){
		printf("Mes: %d promedio: %6.2f\n", i + 1, promediosMeses[i]);
	}

	printf("\nEl resultado es: %d\n",res);
	
	return 0;
}


/*define la funci�n calcularPromedios*/



void
cargarRegistrosAleatorios(struct tipoComercial *comerciales, int numComerciales)
{
    int i,j;
	static char letras[] = {'T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F', 'P', 'D', 'X', 'B', 'N', 'J', 'Z', 'S', 'Q', 'V', 'H', 'L', 'C', 'K', 'E'};
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
   	
    
    srandom(time(NULL));
    for (i = 0; i < numComerciales; i++) {
        sprintf(comerciales[i].nombre,"%s %s",nombres[random() % numNombres],
                apellidos[random() % numApellidos]);
		for (j = 0; j < 8; j++) {
			sprintf(&(comerciales[i].nif[j]),"%c",(char)('0'+random()%10));
		}
		int temp = atoi(comerciales[i].nif);
		sprintf(&(comerciales[i].nif[8]),"%c",letras[temp%23]);						
        for (j = 0; j < NUM_MESES; j++) {
			comerciales[i].ventas[j] = random()%15 + 1;
		}
    }
}

int 
calcularPromedios(struct tipoComercial *comerciales,int numComerciales, float *promediosComerciales,float *promediosMeses)
{	
	int i;
	int j;
	float promediosComercialesI=0;
	float promedioMesesI=0;


	if(comerciales==NULL)
		return -1;
	if(numComerciales<=0)
		return -2;
	if(promediosComerciales== NULL || promediosMeses == NULL)
		return -3;

	//calculamos el promedio de los comerciales
	//cada comercial tiene un promedio

	for(i=0;i<numComerciales;i++){

		for(j=0;j<NUM_MESES;j++){
			promediosComercialesI += comerciales[i].ventas[j];
		}

		promediosComercialesI/=NUM_MESES;
		promediosComerciales[i]=promediosComercialesI;
		promedioMesesI=0;
	}

	//calculamos el promedio de los meses
	for(i=0;i<NUM_MESES;i++){
		for(j=0;j<numComerciales;j++){
			promedioMesesI+= comerciales[j].ventas[i];
		}
		
		prinf("\n\n");
		printf("%f\n",promedioMesesI);
		promedioMesesI/=(float)numComerciales;
		printf("%f\n",promedioMesesI);
		printf("\n\n");
		promediosMeses[i]=promedioMesesI;
		promedioMesesI=0;
	}
	return 0;
}
