#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
int evaluar (int signos[],int coeficientes[],int exponentes[],float d1,float d2,float s,int p){
int i=0,res=0,contn=0,cont=0;
float c=0,y1=0;
for(c=d1;c<=d2;c=c+s){
		for(i=0;i<=p;i++){
			y1=y1+(coeficientes[i]*(pow(c,exponentes[i]))*signos[i]);
		}
	if(y1<0){
		res=1;
		contn++;
	}
	y1=0;
	cont++;
}
if(cont==contn){
	res=2;
}
return res;
}
int escalado1(int signos[],int coeficientes[],int exponentes[],float d1,float d2,int p){
	float a=0,b=0,esc=1;
	int i=0;
	while(i<=p){
		a=a+(coeficientes[i]*(pow(d1,exponentes[i]))*signos[p]);
		i++;
	}
	i=0;
	while(i<=p){
		b=b+(coeficientes[i]*(pow(d2,exponentes[i]))*signos[p]);
		i++;
	}
	a=a*100;
	b=b*100;
	if(fabs(a)>=fabs(b)){
		if(a<0&&b>0){
			while(fabs(a)>=fabs(b)&&fabs(a)/esc>300){
			esc=esc*5;
		}
		}
		else{
			while(fabs(a)>=fabs(b)&&fabs(a)/esc>650){
				esc=esc*5;
			}
		}
	}
	if(fabs(b)>fabs(a)){
		if(a<0&&b>0){
			while(fabs(b)>=fabs(a)&&fabs(a)/esc>300){
			esc=esc*5;
			}
		}
		else{
			while(fabs(b)>fabs(a)&&fabs(b)/esc>650){
				esc=esc*5;
			}
		}
	}
	return esc;
}
int escalado2(float d1,float d2){
	int esc=1;
	d1=d1*1000;
	d2=d2*1000;
	if(fabs(d1)>=fabs(d2)){
		if(d1<0&&d2>0){
			while(fabs(d1)/esc>500){
			esc=esc*2;
			}
		}
		else{
			while(fabs(d1)/esc>950){
				esc=esc*2;
			}
		}
	}
	else{
		if(d1<0&&d2>0){
			while(fabs(d1)/esc>500){
			esc=esc*2;
			}
		}
		else{
			while(fabs(d2)/esc>950){
				esc=esc*2;
			}
		}
	}
	return esc;
}
void graficos(int signos[],int coeficientes[],int exponentes[],float d1,float d2,float s,int p){
	initwindow(1000,700,"graficas");
	int e=0,esc1=0,esc2=0,i=0;
	float c=0,x1=0,y1=0,x2=0,y2=0,x=0,y=0,y3=0;
	char* ejex= (char*)malloc(sizeof(ejex));
	char* ejey=(char*)malloc(sizeof(ejey));
	e=evaluar (signos,coeficientes,exponentes,d1,d2,s,p);
	if(d1>=0&&d2>0){
		if(e==0){
			line(50,0,50,700);
			line(0,650,1000,650);
			x=50;
			y=650;
		}
		if(e==1){
			line(50,0,50,700);
			line(0,350,1000,350);
			x=50;
			y=350;
		}
		if(e==2){
			line(50,0,50,700);
			line(0,50,1000,50);
			x=50;
			y=50;
		}
	}
	if(d1<0&&d2<=0){
		if(e==0){
			line(950,0,950,700);
			line(0,650,1000,650);
			x=950;
			y=650;
		}
		if(e==1){
			line(950,0,950,700);
			line(0,350,1000,350);
			x=950;
			y=350;
		}
		if(e==2){
			line(950,0,950,700);
			line(0,50,1000,50);
			x=950;
			y=50;
		}
		//printf("%f \n",d1);
	}
	if(d1<0&&d2>0){
		if(e==0){
			line(500,0,500,700);
			line(0,650,1000,650);
			x=500;
			y=650;
		}
		if(e==1){
			line(500,0,500,700);
			line(0,350,1000,350);
			x=500;
			y=350;
		}
		if(e==2){
			line(500,0,500,700);
			line(0,50,1000,50);
			x=500;
			y=10;
		}
	}
	//printf("%f \n",d1);
	c=d1;
	x1=d1;
	esc1=escalado1(signos,coeficientes,exponentes,d1,d2,p);
	esc2=escalado2(d1,d2);
	for(i=0;i<=p;i++){
			y1=y1+(coeficientes[i]*(pow(c,exponentes[i]))*signos[i]);
		}
	y3=y1;
	itoa(y1,ejey,10);
	if(y1<0){
		y1=y1*-1;
	}
	if(x1<0){
		x1=x1*-1;
	}

	y1=(y1*100)/esc1;
	x1=(x1*1000)/esc2;
	if(y<350)
			y1=y+y1;
		else{
			if(y==350){
				if(y3<0){
					y1=y1+y;
				}
				else{
					y1=y-y1;
				}
			}
			else
				y1=y-y1;
		}
		if(x<500)
			x1=x+x1;
		else{
			if(x==500){
				if(c<0)
					x1=x-x1;
				else
					x1=x1+x;
				}
			else
			x1=x-x1;
		}	
		itoa(c,ejex,10);
		if(x==50&&y==650){
		outtextxy(x1,670,ejex);
		outtextxy(20,y1,ejey);
		}
		if(x==50&&y==350){
		outtextxy(x1,360,ejex);
		outtextxy(20,y1,ejey);
		}
		if(x==50&&y==50){
		outtextxy(x1,30,ejex);
		outtextxy(20,y1,ejey);
		}
		if(x==950&&y==650){
		outtextxy(x1,670,ejex);
		outtextxy(960,y1,ejey);
		}
		if(x==950&&y==350){
		outtextxy(x1,360,ejex);
		outtextxy(960,y1,ejey);
		}
		if(x==950&&y==50){
		outtextxy(x1,40,ejex);
		outtextxy(960,y1,ejey);
		}
		if(x==500&&y==350){
		outtextxy(x1,360,ejex);
		outtextxy(510,y1,ejey);
		}
		if(x==500&&y==650){
		outtextxy(x1,660,ejex);
		outtextxy(510,y1,ejey);
		}
		if(x==500&&y==50){
		outtextxy(x1,40,ejex);
		outtextxy(510,y1,ejey);
		}
	c=c+s;
	for(i=0;c<=d2;c=c+s){
		for(i=0;i<=p;i++){
			y2=y2+(coeficientes[i]*(pow(c,exponentes[i]))*signos[i]);
		}
		
		itoa(y2,ejey,10);
		y3=y2;
		x2=c;
		if(y2<0){
			y2=y2*-1;
		}
		if(x2<0){
			x2=x2*-1;
		}
		y2=(y2*100)/esc1;
		x2=(x2*1000)/esc2;
		
		if(y<350)
			y2=y+y2;
		else{
			if(y==350){
				if(y3<=0){
					y2=y2+y;
				}
				else{
					y2=y-y2;
				}
			}
			else
				y2=y-y2;
		}
		if(x<500)
			x2=x+x2;
		else{
			if(x==500){
				if(c<0)
					x2=x-x2;
				else
					x2=x2+x;
				}
			else
			x2=x-x2;
		}
		//printf("entro1 %f %f %f %f %f %i \n",c,x1,y1,x2,y2,p);
		printf("%s  / %s   /  %f   /  %f  \n" ,ejex,ejey,x1,y1);
		outtextxy(x1,y1,"x");
		outtextxy(x2,y2,"x");
		itoa(c,ejex,10);
		if(x==50&&y==650){
		outtextxy(x2,670,ejex);
		outtextxy(20,y2,ejey);
		}
		if(x==50&&y==350){
		outtextxy(x2,360,ejex);
		outtextxy(20,y2,ejey);
		}
		if(x==50&&y==50){
		outtextxy(x2,30,ejex);
		outtextxy(20,y2,ejey);
		}
		if(x==950&&y==650){
		outtextxy(x2,670,ejex);
		outtextxy(960,y2,ejey);
		}
		if(x==950&&y==350){
		outtextxy(x2,360,ejex);
		outtextxy(960,y2,ejey);
		}
		if(x==950&&y==50){
		outtextxy(x2,40,ejex);
		outtextxy(960,y2,ejey);
		}
		if(x==500&&y==350){
		outtextxy(x2,360,ejex);
		outtextxy(510,y2,ejey);
		}
		if(x==500&&y==650){
		outtextxy(x1,660,ejex);
		outtextxy(510,y1,ejey);
		}
		if(x==500&&y==50){
		outtextxy(x1,40,ejex);
		outtextxy(510,y1,ejey);
		}
		line(x1,y1,x2,y2);
		x1=x2;
		y1=y2;
		y2=0;
		x2=0;
	}
}
int finc(char* cadena,int f){
	int res=0;
	while(f<strlen(cadena)){
	f++;
	}
		f--;
	return f;
}
int proxx(char* cadena,int f){
	int res=f;
	while(cadena[f]!='x'&&f<strlen(cadena)&&res!=101){
	f++;
	res++;
	if(strlen(cadena)==f)
		res=101;
	}
	if(res==101)
		res=0;
		return res;
}
int proxsig(char* cadena,int f){
	int res=0;
	while(cadena[f]!='+'&&cadena[f]!='-'&&f<strlen(cadena)&&res!=101){
	f++;
	res++;
	if(strlen(cadena)==f)
		res=101;
	}
	if(res==101)
	res=0;
	return res;
}
char* extraer (char cadena[],int a,int b){
char* nueva=(char*)malloc(sizeof(nueva));
int i=0;
while(a<=b){
nueva[i]=cadena[a];
a++;
i++;
}
return nueva;
}
void grafica(char* cadena,int d1,int d2,float s){
int i=0,a=0,b=0,p=0,d=0;
int signos[20];
int coeficientes[20];
int exponentes[20];
if(cadena[0]=='-'){
	signos[p]=-1;
	if(cadena[1]=='x'){
		coeficientes[p]=1;
	}
	else{
	b=proxx(cadena,(i+1));
	a++;
	coeficientes[p]=coeficientes[p]=atoi(extraer(cadena,a,b));
	}
	i++;
}
else{
	if(cadena[0]=='x'){
		coeficientes[p]=1;
		signos[p]=1;
	}
	else{
		signos[p]=1;
		b=proxx(cadena,i);
		if(b==strlen(cadena))
		{
			coeficientes[p]=1;
			exponentes[p]=0;
		}
		else{
			coeficientes[p]=coeficientes[p]=atoi(extraer(cadena,a,b));
		}
	
		i++;
	}
}
for(;i<=strlen(cadena);i++){
	if(cadena[i]=='+')
	{
		p++;
		signos[p]=1;
		if(cadena[i+1]=='x'){
			coeficientes[p]=1;
		}
		else{
		a=i+1;
		b=proxx(cadena,i)-1;
		if(b==-1){
			coeficientes[p]=atoi(extraer(cadena,a,strlen(cadena)-1));
			exponentes[p]=0;	
		}
		else{
			coeficientes[p]=atoi(extraer(cadena,a,b));
			}
		}
	}
	if(cadena[i]=='-')
	{
		p++;
		signos[p]=-1;
		if(cadena[i+1]=='x'){
			coeficientes[p]=1;
		}
		else{
			a=i+1;
			b=proxx(cadena,i)-1;
			if(b==-1){
				coeficientes[p]=atoi(extraer(cadena,a,strlen(cadena)-1));
				exponentes[p]=0;	
			}
			else{
				coeficientes[p]=atoi(extraer(cadena,a,b));
			}
		}		
	}
	if(cadena[i]=='x')
	{
		if(cadena[i+1]=='+'||cadena[i+1]=='-'||strlen(cadena)==(i+1))
		{
			exponentes[p]=1;
			a=i+1;
		}
		else{
			a=i+1;
			b=(proxsig(cadena,i))+i;
			if(b==i){
				b=strlen(cadena)-1;
				exponentes[p]=atoi(extraer(cadena,a,b));
			}
			else{
			exponentes[p]=atoi(extraer(cadena,a,b));
			}
		}
	}
}
printf("%i %i %i %i %i %i \n",coeficientes[0],exponentes[0],signos[0],coeficientes[1],exponentes[1],signos[1]);
graficos(signos,coeficientes,exponentes,d1,d2,s,p);
return ;
}

