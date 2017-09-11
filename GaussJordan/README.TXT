Eliezer Fernando Couoh Balam.
Jose Luis Avila Vela.



Programa 2 
GAUSSJORDAN


Lo primero que hace es leer la matriz del archivo input2.txt.
Este input2.txt es un archivo de tipo .txt que en su interior contiene como se define la matriz
con la que se va a trabajar y la cantidad de matrices a las que se les aplicara GaussJordan.
Al hacer la lectura, los datos que proporciona se leen de la siguiente manera:

Al leer el primer renglon se lee la cantidad de matrices con las que se trabajaran por separado. Es decir la cantidad
de matrices a las que se les aplicara el GaussJordan.

2		#esta primera indica el número de matrices en este caso son 2 matrices que leera
2 3		
4 2 -1 6	
3 -2 0 4 
3 3
2 3 1 5
3 4 -1 3
1 -2 1 7

En el segundo renglon comienza con la lectura del tamaño de la primera matriz
en este renglon se encontraran dos numeros, el primero proporciona el numero de las filas y el segundo 
lee el numero de las columnas.

2		
2 3		#estos dos menciona el número de filas y columnas(variables del sistema) respectivamente
4 2 -1 6	
3 -2 0 4 
3 3		#estos dos menciona el número de filas y columnas(variables del sistema) respectivamente
2 3 1 5
3 4 -1 3
1 -2 1 7


 Posteriormente lee el tercer renglon que empieza a realizar la lectura de los datos,
la cantidad de estos datos depende del numero de columnas que se haya proporcionado. Y el numero de renglones que se 
leeran depende del numero de filas proporcionadas. 

2		
2 3		
4 2 -1 6	#Datos del segundo sistema	
3 -2 0 4 	#Datos del segundo sistema
3 3
2 3 1 5		#Datos del segundo sistema
3 4 -1 3	#Datos del segundo sistema
1 -2 1 7	#Datos del segundo sistema

Despues de haber escaneado esta matriz, y si la cantidad de matrices
es diferente de uno, procede a leer el tamaño de la matriz y sus datos en el mismo orden que leyo los datos de la primera. 
Ira scaneando de la misma forma todas las matrices que le hayamos indicado que existan.


**es de suma inportancia recordar que el archivo input2.txt solo deben escribirse números, por lo que si se escriben algun caracter diferente a estos, el programa no lo aceptara, ya que estamos resolviendo sistemas y matrices**


por lo tanto el usuario devera introducir los datos de la manera ya mencionada en el archivo input2.txt y solo compilara el programa para obtener los resultados.


En los archivos podemos acceder entonces a conocer la matriz original(input2.txt) y la matriz resultante(output2.txt) despues de haber ejecutado el programa


**
el programa se puede ejecutar en el IDE de ZinjaI, o en el ejecutable pero se puede abrir en cualquier editor de texto el codigo en C.

el archivo output2.txt dara el resultado final de la eliminación gaussiana, es donde el usuario checa la salida del programa. 

**los archivos imput1.txt y output.txt deben estar dentro del mismo directorio
