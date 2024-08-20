Algoritmo sin_titulo
	contador_negativos = 0
    suma_impares = 0
    contador_impares = 0
	Definir num Como Entero
	Definir bool Como Logico
	bool = Verdadero
    Mientras bool Hacer
        Escribir "Ingrese un número (0 para salir):"
        Leer num
        Si num = 0 Entonces
			bool = Falso
        Fin Si
        
        Si num MOD 2 = 0 y num<> 0 Entonces
            Escribir "Número PAR"
        Sino si num<>0
				Escribir "Número IMPAR"
				suma_impares = suma_impares + num
				contador_impares = contador_impares + 1
			Fin Si
        Fin Si
		
        Si num > 0  Entonces
            Escribir "Número POSITIVO"
        SiNo si num<>0
				Escribir "Número NEGATIVO"
				contador_negativos = contador_negativos + 1
			Fin Si
        Fin Si
    Fin Mientras
	
    Si contador_impares > 0 Entonces
        promedio_impares = suma_impares / contador_impares
    Sino
        promedio_impares = 0
    Fin Si
	
    Escribir "Cantidad de números negativos: ", contador_negativos
    Escribir "Promedio de números impares: ", promedio_impares
	
FinAlgoritmo
