Algoritmo cuatro_numeros
	Definir pares, i,potencia Como Entero
	Definir  promedio Como Real
	Dimension num[4]
	Escribir "por favor escriba 4 numeros separados con un enter"
	Leer num[1], num[2], num[3], num[4]
	i =1
	Mientras  i <= 4 Hacer
		Si num[i] % 2 == 0 Entonces
			pares = pares +1
		FinSi
		i = i +1
	FinMientras
	i =1
	Limpiar Pantalla
	Escribir pares, " de los numeros son pares. Presiona una tecla para continuar"
	Esperar Tecla
	Limpiar Pantalla
	Si num[1] > num[2] Y num[1] > num[3] Y num[1] > num[4] Entonces
		Escribir "el mayor de los numeros es ", num[1]
	FinSi
	Si num[2] > num[1] Y num[2] > num[3] Y num[2] > num[4]  Entonces
		Escribir "el mayor de los numeros es ", num[2]	
	FinSi
	Si num[3] > num[1] Y num[3] > num[2] Y num[3] > num[4]  Entonces
		Escribir "el mayor de los numeros es ", num[3]	
	FinSi
	Si num[4] > num[1] Y num[4] > num[2] Y num[4] > num[3] Entonces
		Escribir "el mayor de los numeros es ", num[4]	
	FinSi
	Escribir "presione alguna tecla para continuar"
	Esperar Tecla
	Limpiar Pantalla
	si num[3] % 2 == 0 Entonces
		potencia = num[2]^2 
		Escribir "el cuadrado de su segundo numero es:", potencia
		Escribir "presione alguna tecla para continuar"
		Esperar Tecla
	FinSi
	Limpiar Pantalla
	si num[1] < num[4] Entonces
		Mientras  i <= 4 Hacer
			promedio = promedio+num[i]
			i = i +1
		FinMientras
		promedio = promedio/4
		Escribir "el promedio de sus datos es ", promedio
	FinSi
	Esperar 4 Segundos
	Limpiar Pantalla
	Escribir "El programa finalizó con exito"
FinAlgoritmo
