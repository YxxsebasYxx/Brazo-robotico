Algoritmo sin_titulo
	Definir carac Como Caracter
	Escribir "Escriba aqui su caracter de preferencia"
	Dimension carac_[5]
	carac_[1] = "a"
	carac_[2] = "e"
	carac_[3] = "i"
	carac_[4] = "o"
	carac_[5] = "u"
	Leer carac 
	carac = Minusculas(carac)
	Para i=1 Hasta 5
		var = carac_[i]
		si var == carac Entonces
			Escribir "Tu caracter es una vocal"
		Si var = "a" o var="e" o var="o"
			Escribir "e tipo vocal abierta"
		SiNo
			Escribir "De vocal cerrada"
		Finsi
		FinSi
	FinPara
	contador_negativos = 0
    suma_impares = 0
    contador_impares = 0
	Definir n�mero Como Entero
	Definir bool Como Logico
	bool = Verdadero
    Mientras bool Hacer
        Escribir "Ingrese un n�mero (0 para salir):"
        Leer n�mero
        Si n�mero = 0 Entonces
			bool = Falso
        Fin Si
        
        Si n�mero MOD 2 = 0 y n�mero<> 0 Entonces
            Escribir "N�mero PAR"
        Sino 
            Escribir "N�mero IMPAR"
            suma_impares = suma_impares + n�mero
            contador_impares = contador_impares + 1
        Fin Si
		
        Si n�mero > 0 Entonces
            Escribir "N�mero POSITIVO"
        Sino
            Escribir "N�mero NEGATIVO"
            contador_negativos = contador_negativos + 1
        Fin Si
    Fin Mientras
	
    Si contador_impares > 0 Entonces
        promedio_impares = suma_impares / contador_impares
    Sino
        promedio_impares = 0
    Fin Si
	
    Escribir "Cantidad de n�meros negativos: ", contador_negativos
    Escribir "Promedio de n�meros impares: ", promedio_impares
FinAlgoritmo
