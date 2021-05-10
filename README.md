# proyecto calculadora garfica
Esta calculadora es un proyecto de segundo semestre de mi carrera ingenieria en sistemas y computacion. ademas de hacer esta calculadora tambien se nos pidió hacerle una interfaz en consola que gestiona datos, como cuentas, historial y graficos; todo esto almacenado en archivos de texto plano.

Todo el proyecto fue hecho 100% en el lenguaje de programacion C por lo que se tuvo que requerir de algunas librerias un poco antiguas para el metodo grafico de la calucladora, por lo tanto debemos tener en cuenta algunos aspectos:
* el codigo solo funiona en un compilador de 32 bits.
* es necesario descargar las librerias conio.h y grapics.h.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
La calculadora, tiene la capacidad de graficar polinomios de cualquier grado en el rango que este se pida ser calculado, tambien es capaz de escalar este grafico para que se pueda ver adecuadamente en pantalla.

La calculadora reconoce todo lo que esté a la izquierda de una x como un coeficiente y a la derecha como un exponente.

La calculadora **no reconoce** :
* divisiones(/)
* logaritmos(ln,log)
* raices(sqrt)

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Para la interfaz por consola se necesitan 3 archivos de texto plano para ser usados como base de datos, los rachivos en concreto son:
* auxiliar.txt
* datos.txt
* historial.txt

Ademas de estos txt tenemos dos archivos cpp que es la extension con la que se guarda por defecto el codigo scrito en C. el primer archivo que es final.cpp es donde se encuentra almacenado todo lo relacionado con la calculadora y su parte grafica. el otro archivo que es interfaz.cpp como su nombre lo indica es la interfaz que se encarga de gestionar todo el menu por consola, almacenar los datos en los archivos de texto plano y tambien de leer estos mismo archivos para verificar ususarios y contraseñas.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Tambien tener en cuenta que es un proyecto que hice en mi primer año de estudio. por lo tanto hay mucho por mejorar en el codigo, en un futuro sacaré una version mejorada en c++. 

