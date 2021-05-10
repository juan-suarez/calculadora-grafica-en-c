#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include "final.cpp"
time_t tiempoahora;
struct tm *mitiempo= localtime(&tiempoahora);
typedef struct //estructura para modulo de usuarios
{   
	char username[20] = "                   ";
	char password[20] = "                   ";
}cliente;
void guardar(char cadena[20],FILE* archivo){
	int i=0;
	while(i<20){
		if(cadena[i]==-1)
		i++;
		
		fputc(cadena[i],archivo);
		i++;
	}
	return;
}
void cambiarcontra(char usuario[20],char contra[20],FILE* archivo){
	int j;
	char nueva[20]="                   ";
	char valor;
	rewind(archivo);
	while(!feof(archivo)){
		for(j=0;j<20;j++){
			nueva[j]=fgetc(archivo);
		}
		if(	strcmp(nueva,usuario)==0){
			for(j=0;j<=20;j++){
				valor=contra[j]-2;
				fputc(valor,archivo);
				printf("1\n");
			}
		}
	}
	return ;
}
void borrarcontra(char usuario[20],FILE* archivo){
	int i=0,est=0,tam;
	char nueva[20];
	char valor;
	rewind(archivo);
	FILE* auxiliar = fopen ("auxiliar.txt","w");
	while(!feof(archivo)&&est!=1){
		for(i=0;i<20;i++){
			nueva[i]=fgetc(archivo);
		}
		if(	strcmp(nueva,usuario)==0){
			fwrite(nueva,1,20,auxiliar);
			for(i=0;i<20;i++){
				fgetc(archivo);
			}
		}
		else
			fwrite(nueva,1,20,auxiliar);
	}
	fclose(auxiliar);
	auxiliar = fopen ("auxiliar.txt","r");
	fseek(auxiliar,0,SEEK_END);
	tam=ftell(auxiliar);
	fseek(auxiliar,0,SEEK_SET);
	fclose(archivo);
	archivo=fopen("datos.txt","w");
	for(i=0;i<tam;i++){
		valor=fgetc(auxiliar);
		fputc(valor,archivo);
	}
	return ;
}
int buscarusu(char cadena[20],FILE* archivo){
	int i=0,est=0;
	char nueva[20];
	rewind(archivo);
	while(!feof(archivo)&&est!=1){
		for(i=0;i<20;i++){
			nueva[i]=fgetc(archivo);
		}
	if(	strcmp(nueva,cadena)==0)
		est=1;
	}
	return est;
}
void listar()
{
char caracter,caracter2;
printf("ingrese el ususario: ");
char usuario[20]="                   ";
char usuariosistema[20]="                   ";
FILE *archivo = fopen("historial.txt","r");
int a=0,b,combrobante=0,i=0;
scanf("%s",&usuario);

    for(a=0;a<20;a++)
          {
              usuariosistema[a]=fgetc(archivo);
       }
    if(strcmp(usuario,usuariosistema)==0)
          {
             while(b!=10&&!feof(archivo))
                {
                    caracter=fgetc(archivo);
                    printf("%c",caracter);
           }
       }

while(!feof(archivo))
   {
       caracter2=fgetc(archivo);
       if(caracter2==13)
          {
          	fgetc(archivo);
             for(a=0;a<20;a++)
          {
              usuariosistema[a]=fgetc(archivo);
       }
    if(strcmp(usuario,usuariosistema)==0)
          {
             while(b!=13&&!feof(archivo))
                {
                    caracter=fgetc(archivo);
                    printf("%c",caracter);
           }
       }
       }
	
    a=0;
   }

fclose(archivo);

return;

}

void final(){
	char* ecuacion=(char*)malloc(sizeof(ecuacion));
	char valor;
	char numero[5]="    ";
	char anio[4]="   ";
	char dia[3]=" ";
	char mes[2]=" ";
	char valr[2]=" ";
	int nn;
	float s=0,d1=0,d2=0;
	FILE* archivo=fopen("historial.txt","a+");
	FILE* nuevo=fopen("numeracion.txt","r");
	printf("por favor ingrese la ecuacion : ");
	scanf("%s",ecuacion);
	printf("datos del dominio-desde que valor de x quiere la grafica : ");
	scanf("%f",&d1);
	printf("datos del dominio-desde que valor de x quiere la grafica : ");
	scanf("%f",&d2);
	printf("ingrese la separacion de los puntos : ");
	scanf("%f",&s);
	itoa(mitiempo->tm_year+1950,anio,10);
	itoa(mitiempo->tm_mon+1,mes,10);
	itoa(mitiempo->tm_yday,dia,10);
	fputc(anio[0],archivo);
	fputc(anio[1],archivo);
	fputc(anio[2],archivo);
	fputc(anio[3],archivo);
	fputc('/',archivo);
	fputc(mes[0],archivo);
	fputc(mes[1],archivo);
	fputc('/',archivo);
	fputc(dia[0],archivo);
	fputc(dia[1],archivo);
	fputc(' ',archivo);
	for(int i=0;!feof(nuevo);i++){
		valor=fgetc(nuevo);
		if(valor!=-1)
		fputc(valor,archivo);
		numero[i]=valor;
	}
	fclose(nuevo);
    nuevo=fopen("numeracion.txt","w");
	nn=atoi(numero)+1;
	printf("%i , ",nn);
	itoa(nn,numero,10);
	printf("%s",numero);
	
	for(int i=0;i<strlen(numero);i++){
		fputc(numero[i],nuevo);
	}
	system("pause");
	fputc('.',archivo);
	for(int i=0;i<strlen(ecuacion);i++){
		valor=ecuacion[i];
		if(valor!=-1){
		fputc(valor,archivo);
		}
	}
	itoa(d1,valr,10);
	fputc('/',archivo);
	fputc(valr[0],archivo);
	fputc('/',archivo);
	itoa(d2,valr,10);
	fputc(valr[0],archivo);
	fputc('/',archivo);
	itoa(s,valr,10);
	fputc(valr[0],archivo);
	fputc('\n',archivo);
	grafica(ecuacion,d1,d2,s);
	getch();
	
}
void Eliminar(FILE* archivo,char usuario[20]){
	int i=0,est=0,tam;
	char nueva[20];
	char valor;
	rewind(archivo);
	FILE* auxiliar = fopen ("auxiliar.txt","w");
	while(!feof(archivo)&&est!=1){
		for(i=0;i<20;i++){
			nueva[i]=fgetc(archivo);
		}
		if(	strcmp(nueva,usuario)==0){
			for(i=0;i<20;i++){
				fgetc(archivo);
			}
		}
		else
			fwrite(nueva,1,20,auxiliar);
	}
	fclose(auxiliar);
	auxiliar = fopen ("auxiliar.txt","r");
	fseek(auxiliar,0,SEEK_END);
	tam=ftell(auxiliar)-20;
	fseek(auxiliar,0,SEEK_SET);
	archivo=fopen("datos.txt","w");
	for(i=0;i<tam;i++){
		valor=fgetc(auxiliar);
		fputc(valor,archivo);
	}
	return ;
}

void encriptar(char cadena[20],FILE* archivo){
	int i=0;
	while(i<20){
		if(cadena[i]==-1)
		i++;
		
		fputc(cadena[i]-2,archivo);
		i++;
	}
	return;
}
void menu(char nombre[20])//funcion del menu root, hay que hacer listado de ingresos
{   
  	FILE *archivo=fopen("historial.txt","a+");
  	FILE *nuevo=fopen("datos.txt","r+");
	char contra[20];
	int op=0;//variable disponible para la opcion
	
	system("cls");//borra lo que hay en pantalla
	printf("Aplicativo-Graficador-UTP\nMenu principal para usuario: %s\n\n",nombre);
    printf("0.salir del aplicativo\n");
    printf("1.Crear nuevo grafico\n");
    printf("2.Listar accesos \n");
    printf("3.Cambiar password \n\n");
    
    printf("opcion: ");
    scanf("%i",&op);
    if(op==1){
    	system("cls");
    	guardar(nombre,archivo);
    	final();
	}
	if(op==2){
		system("cls");
		char valor;
		printf("nombre          aa/mm/dd    n°    f(x)\n");
		FILE* historial=fopen("historial.txt","r");
		while(!feof(historial)){
			valor=fgetc(historial);
			printf("%c",valor);
		}
	}
	if(op==3){
		system("cls");
		printf("ingrese la nueva contraseña: ");
		scanf("%s",&contra);
		borrarcontra(nombre,nuevo);
		cambiarcontra(nombre,contra,nuevo);
		printf("\n\n\t\t --su contraseña ha sido cambiada con exito-- ");
	}
   // switch(op)
    //{
    //	case 0: exit(0);break;
    //	case 1:graficadora();break;
    //	case 2:system("cls");borrarGrafico();getchar();menu(nombre);break;
    //	case 3:system("cls");listarUsuario(nombre);getchar();menu(nombre);break;
      //  case 4:printf("4");break;
        //case 5:CambiarUsuario(nombre);break;
	//}
}

void menuRoot(char usuario[20])//funcion del menu root
{   
  FILE *archivo=fopen("usuarios.dat","r+");
	int op=0;//variable disponible para la opcion
	
	system("cls");//borra lo que hay en pantalla
	printf("Aplicativo-Graficador-UTP\nMenu principal para usuario: root\n\n");
    printf("0.salir del aplicativo\n");
    printf("1.Crear nuevo usuario\n");
    printf("2.Borrar usuario\n");
    printf("3.Listar accesos todos los usuarios\n");
    printf("4.Cambiar password del usuario root\n");
    printf("5.Cambiar password de un usuario\n\n");
    
    printf("opcion: ");
    scanf("%i",&op);
    if(op==0){
    	return ;
	}
    if(op==1){
    	cliente usua;
    	char caracter;
    	char comprobante[20]="                   ";
    	int i=0,la;
    	FILE* dats = fopen("datos.txt","a+");
    	system("CLS");
    	printf("ingrese el nombre ususario: ");
		scanf("%s",&usua.username);
		printf("ingrese la contraseña del usuario nuevo: ");
		caracter = _getch();
        while (i < 10 && caracter != 13) 
		{
            if (caracter != 8) 
			{
                usua.password[i] = caracter;
                i++;
                printf("*");
            } 
			else
			 {
                la= strlen(usua.password); /* Longitud actual */
                if (la > 0) 
				{
                    printf("\b \b");//se devuelve dos campos
                    usua.password[la - 1] = '\0';
                    i++;
                }
            }
            caracter = _getch();
       }
       printf("\n valide la contraseña : ");
		caracter = _getch();
		i=0;
        while (i < 10 && caracter != 13) 
		{
            if (caracter != 8) 
			{
                comprobante[i] = caracter;
                i++;
                printf("*");
            } 
			else
			 {
                la= strlen(comprobante); /* Longitud actual */
                if (la > 0) 
				{
                    printf("\b \b");//se devuelve dos campos
                    comprobante[la - 1] = '\0';
                    i++;
                }
            }
            caracter = _getch();
       }
       if(strcmp(comprobante,usua.password)==0){
       		guardar(usua.username,dats);
	    	encriptar(usua.password,dats);
	    	fclose(dats);
	    	printf("\n\t--el usuario ha sido registrado con exito--");
	    	sleep(3);
   	    	system("CLS");
   	    	menuRoot(usuario);
	   }
	   else{
	   	printf("\n\t\t--las contraseñas no son correctas--");
	   	sleep(2);
	   	menuRoot(usuario);
	   }
        
    	
	}
	if(op==2){
		char usuario[20];
		FILE* dats = fopen("datos.txt","r");
		system("cls");
		printf("usuario que desea borrar: ");
		scanf("%s",&usuario);
		if(buscarusu(usuario,dats)==1)
		{
			Eliminar(dats,usuario);
			printf("\n --el usuario ha sido eliminado-- \n");
		}
		else
			printf("\n --usuario no encontrado -- \n");
			
		sleep(5);
		menuRoot(usuario);
	}
	if(op==3){
		system("cls");
		char valor;
		printf("nombre          aa/mm/dd    n°    f(x)\n");
		FILE* historial=fopen("historial.txt","r");
		while(!feof(historial)){
			valor=fgetc(historial);
			printf("%c",valor);
		}
	}
	if(op==4){
		FILE* nuevo=fopen("historial.txt","r");
		cliente usuar;
		system("cls");
		printf("ingrese la nueva contraseña: ");
		scanf("%s",&usuar.password);
		borrarcontra(usuario,nuevo);
		cambiarcontra(usuario,usuar.password,nuevo);
		printf("\n\n\t\t --su contraseña ha sido cambiada con exito-- ");
	}
	if(op==5){
		FILE* nuevo=fopen("historial.txt","r");
		cliente usuar;
		system("cls");
		printf("ingrese el usuario: ");
		scanf("%s",&usuar.username);
		printf("ingrese la nueva contraseña: ");
		scanf("%s",&usuar.password);
		borrarcontra(usuar.username,nuevo);
		cambiarcontra(usuar.username,usuar.password,nuevo);
		printf("\n\n\t\t --su contraseña ha sido cambiada con exito-- ");
	}
   // switch(op)
    //{
    //	case 0:exit(0);break;
    //	case 1:CrearUsuario();break;
    //	case 2:EliminarUsuario();break;
    //	case 3:system("cls");printf("usuario: "); scanf("%s",&u);listarUsuario(u);getchar();menuRoot();break;
      //  case 4:system("cls");listar();menuRoot();break;
    	//case 5:printf("5");break;
        //case 6:CambiarRoot();break;
        //case 7:cambiarUsuario();break;
	//}
	return ;
}
void entrar(){
	cliente usu;
	char comprobante[20]="                   ";
	char caracter;
	int i=0,la=0;
	FILE* dats = fopen("datos.txt","a+");
	printf("\t\t\t\t\t---APLICATIVO-GRAFICADORA-UTP---\n\n");
	printf("ingrese el ususario: ");
	scanf("%s",&usu.username);
	printf("ingrese la contraseña: ");
	caracter = _getch();
        while (i < 10 && caracter != 13) 
		{
            if (caracter != 8) 
			{
                usu.password[i] = caracter;
                i++;
                printf("*");
            } 
			else
			 {
                la= strlen(usu.password); /* Longitud actual */
                if (la > 0) 
				{
                    printf("\b \b");//se devuelve dos campos
                    usu.password[la - 1] = '\0';
                    i++;
                }
            }
            caracter = _getch();
       }
       int tamanio=0;
       fseek(dats,0,SEEK_END);
       tamanio=ftell(dats);
	if(strcmp(usu.username,"root")==0){
		if(tamanio==0){
			printf("\n valide la contraseña: ");
			caracter = _getch();
			i=0;
        while (i < 10 && caracter != 13) 
		{
            if (caracter != 8) 
			{
                comprobante[i] = caracter;
                i++;
                printf("*");
            } 
			else
			 {
                la= strlen(comprobante); /* Longitud actual */
                if (la > 0) 
				{
                    printf("\b \b");//se devuelve dos campos
                    comprobante[la - 1] = '\0';
                    i++;
                }
            }
            caracter = _getch();
       }
			if(strcmp(comprobante,usu.password)==0){
				guardar(usu.username,dats);
				encriptar(usu.password,dats);
				fclose(dats);
				printf("\n\t\t\t--se ha registrado con exito-- ");
				sleep(2);
				menuRoot(usu.username);
			}
			else{
				printf("\n --las contraseñas no son iguales--\n");
				sleep(2);
				system("cls");
				entrar();
			}
			
		}
		else{
			char contra[20]="                   ";
			fseek(dats,20,SEEK_SET);
			for(i=0;i<=20;i++){
				caracter = fgetc(dats)+2;
				contra[i]=caracter;
			}
			if(strcmp(usu.password,contra)==0)	
				menuRoot(usu.username);
			else{
				printf("\n --contraseña erronea-- \n\t\t\t");
				sleep(2);
				system("CLS");
				entrar();
			}
		}
		
	}
	else{
		if(buscarusu(usu.username,dats)==1){
			char contra[20]="                   ";
			for(i=0;i<=20;i++){
				caracter = fgetc(dats)+2;
				contra[i]=caracter;
			}
			if(strcmp(usu.password,contra)==0)
				menu(usu.username);
			else{
				printf("\n --contraseña erronea-- ");
				sleep(2);
				system("cls");
				entrar();
				}
		}
		else{
		printf("\n usuario no encontrado \n ");
		sleep(2);
		system("cls");
		entrar();
		}
	}
}
int main(){
	printf("%d/%d/%d",(mitiempo->tm_year)+1950,mitiempo->tm_mon+1,mitiempo->tm_mday);
	entrar();
}
