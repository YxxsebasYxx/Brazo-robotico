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
			Escribir "VOCAL"
		    Si var = "a" o var="e" o var="o"
			  Escribir "De tipo vocal abierta"
		    SiNo
			  Escribir "De tipo vocal cerrada"
		  Finsi
	  SiNo si i=5 y carac<>carac_[1] y carac<>carac_[2] y carac<>carac_[3] y carac<>carac_[4] y carac<>carac_[5] Entonces
			Escribir "NO VOCAL" 
		  FinSi
	  FinSi
	FinPara
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
	
	Definir name Como Caracter
	Definir id,bici,precio1,precio2,precio3,cantidad Como real
	precio1= 1500000
	precio2= 1000000
	precio3 = 700000
	Escribir "Hola somos de la empresa YO TRABAJO LOS MALDITOS DOMINGOS"
	Escribir "Ingrese su nombre"
	Leer name
	Escribir "ahora su id"
	Leer id
	Escribir "Ingrese el numero de bicicletas que desee llevarse"
	leer bici
	Mientras bici<0 Hacer
		Escribir "Eso no tiene sentido"
		Leer bici
	FinMientras
	si bici<9 Entonces
		Escribir "Este es el precio de cada bicicleta si las unidades no superan las 9"
		Escribir precio1
		cantidad = bici*precio1
		Escribir "Gracias por su compra a nombre de ",name "  numero ", id
		Escribir "Subtotal: ", cantidad
		Escribir "Iva(16%): ", precio1*(16/100)
		Escribir "Total: ",cantidad+precio1*(16/100)
	FinSi
	si bici>=9 y bici<20
		Escribir "Este es el precio de cada bicicleta si las unidades no superan las 20"
		Escribir precio2
		cantidad = bici*precio2
		Escribir "Gracias por su compra a nombre de ",name " id: ", id
		Escribir "Subtotal: ", cantidad
		Escribir "Iva(16%): ", precio2*(16/100)
		Escribir "Total: ",cantidad+precio2*(16/100)
	Sino si bici>=20
			Escribir "Este es el precio de cada bicicleta si las unidades superan las 20"
			Escribir precio3
		cantidad = bici*precio3
		Escribir "Gracias por su compra a nombre de ",name "  numero ", id
		Escribir "Subtotal: ", cantidad
		Escribir "Iva(16%): ", precio3*(16/100)
		Escribir "Total: ",cantidad+precio3*(16/100)
		Fin Si
	FinSi
FinAlgoritmo
