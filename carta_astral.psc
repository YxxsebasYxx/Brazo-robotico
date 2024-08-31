Algoritmo carta_astral
	Definir nombre, apellido, Ncompleto, ascendente,signo Como Caracter
	definir fecha, edad, dia, mes, año, hora, abiertas, cerradas, largo  Como entero
	Definir correct, adult como logico 
	repetir 
		correct=falso
		Escribir "Ingrese su fecha de nacimiento"
		escribir "En orden dia, mes y año"
		leer dia, mes, año
		si año<2024 y mes>=1 y mes<=12 Entonces
			si mes=2 entonces 
				si dia>=1 y dia<=28 entonces
					correct=Verdadero
				FinSi
			FinSi
			si mes=1 o mes=3 o mes=5 o mes=7 o mes=8 o mes=10 o mes=12 Entonces
				si dia>=1 y dia<=31 Entonces
					correct=Verdadero
				FinSi
			FinSi
			si mes=4 o mes=6 o mes=9 o mes=11 Entonces
				si dia>=1 y dia<=30 Entonces
					correct=Verdadero
				FinSi
			FinSi
		FinSi
		mientras correct=falso hacer 
			escribir "Fecha ingresada no valida o mal digitada"
			Escribir "Ingrese nuevamente su fecha de nacimiento"
			leer dia, mes, año
			si año<2024 y mes>=1 y mes<=12 Entonces
				si mes=2 entonces 
					si dia>=1 y dia<=28 entonces
						correct=Verdadero
					FinSi
				FinSi
				si mes==1 o mes==3 o mes==5 o mes==7 o mes==8 o mes==10 o mes=12 Entonces
					si dia>=1 y dia<=31 Entonces
						correct=Verdadero
					FinSi
				FinSi
				si mes==4 o mes==6 o mes==9 o mes==11 Entonces
					si dia>=1 y dia<=30 Entonces
						correct=Verdadero
					FinSi
				FinSi
			FinSi
		FinMientras
		Escribir "Ingrese su hora de nacimiento"
		Escribir "Formato 24 horas, ingresar número de o al 23"
		leer hora
		mientras hora<0 o hora>23 hacer
			Escribir "Hora ingresada no válida" 
			Escribir "Ingrese nuevamente su hora de nacimiento"
			leer hora
		FinMientras
		Escribir "Ingrese su edad"
		leer edad
		Mientras edad<=0 hacer 
			Escribir "edad no valida"
			Escribir "Ingrese nuevamente su edad"
			leer edad
		FinMientras
		si edad>=18 Entonces
			adult=Verdadero
		sino 
			adult=falso
		FinSi
	Hasta Que adult=verdadero
	
	//inicio del menu
	Escribir "ahora que verificamos tu edad dame tu nombre para poder hacer tu carta astral"
	Leer nombre
	Escribir "tambien tu apellido"
	Leer apellido
	
	Ncompleto = Concatenar(nombre, apellido)
	Dimension carac_[5]
	carac_[1] = "a"
	carac_[2] = "e"
	carac_[3] = "i"
	carac_[4] = "o"
	carac_[5] = "u"
	
	largo = Longitud(Ncompleto)
	Escribir largo
	Esperar Tecla
	
	Dimension letras[largo]
	
	Para i = 1 Hasta largo Hacer
		letras[i] = Subcadena(Ncompleto, i, i)
		letras[i]= Minusculas(letras[i])
		
		Para e = 1 Hasta 5 
			var = carac_[e]
			
			Si letras[i] == var y ((letras[i] == carac_[3]) o (letras[i] == carac_[5])) Entonces
				cerradas = cerradas + 1
			FinSi
			Si letras[i] == var y (letras[i] == carac_[1] o letras[i] == carac_[2] o letras[i] == carac_[4])  Entonces
				abiertas = abiertas + 1
			FinSi
		FinPara
	FinPara
	
	Escribir "su nombre tiene ", cerradas, " vocales cerradas y ", abiertas, " vocales abiertas"
	Segun mes Hacer
		1:
			Si dia <= 19 Entonces
				signo = "Capricornio"
			Sino
				signo = "Acuario"
			FinSi
		2:
			Si dia <= 18 Entonces
				signo = "Acuario"
			Sino
				signo = "Piscis"
			FinSi
		3:
			Si dia <= 20 Entonces
				signo = "Piscis"
			Sino
				signo = "Aries"
			FinSi
		4:
			Si dia <= 19 Entonces
				signo = "Aries"
			Sino
				signo = "Tauro"
			FinSi
		5:
			Si dia <= 20 Entonces
				signo = "Tauro"
			Sino
				signo = "Géminis"
			FinSi
		6:
			Si dia <= 20 Entonces
				signo = "Géminis"
			Sino
				signo = "Cáncer"
			FinSi
		7:
			Si dia <= 22 Entonces
				signo = "Cáncer"
			Sino
				signo = "Leo"
			FinSi
		8:
			Si dia <= 22 Entonces
				signo = "Leo"
			Sino
				signo = "Virgo"
			FinSi
		9:
			Si dia <= 22 Entonces
				signo = "Virgo"
			Sino
				signo = "Libra"
			FinSi
		10:
			Si dia <= 22 Entonces
				signo = "Libra"
			Sino
				signo = "Escorpio"
			FinSi
		11:
			Si dia <= 21 Entonces
				signo = "Escorpio"
			Sino
				signo = "Sagitario"
			FinSi
		12:
			Si dia <= 21 Entonces
				signo = "Sagitario"
			Sino
				signo = "Capricornio"
			FinSi
	FinSegun
	
	// Determinar el ascendente simple basado en la hora
	Si hora >= 6 Y hora < 8 Entonces
		ascendente = "Aries"
	FinSi
	Si hora >= 8 Y hora < 10 Entonces
		ascendente = "Tauro"
	FinSi
	Si hora >= 10 Y hora < 12 Entonces
		ascendente = "Géminis"
	FinSi
	Si hora >= 12 Y hora < 14 Entonces
		ascendente = "Cáncer"
	FinSi
	Si hora >= 14 Y hora < 16 Entonces
		ascendente = "Leo"
	FinSi
	Si hora >= 16 Y hora < 18 Entonces
		ascendente = "Virgo"
	FinSi
	Si hora >= 18 Y hora < 20 Entonces
		ascendente = "Libra"
	FinSi
	Si hora >= 20 Y hora < 22 Entonces
		ascendente = "Escorpio"
	FinSi
	Si hora >= 22 Y hora < 24 Entonces
		ascendente = "Sagitario"
	FinSi
	Si hora >= 0 Y hora < 2 Entonces
		ascendente = "Capricornio"
	FinSi
	Si hora >= 2 Y hora < 4 Entonces
		ascendente = "Acuario"
	FinSi
	Si hora >= 4 Y hora < 6 Entonces
		ascendente = "Piscis"
	FinSi
	
	Escribir "Tu signo zodiacal es: ", signo
	Escribir "Tu ascendente es: ", ascendente
FinAlgoritmo
