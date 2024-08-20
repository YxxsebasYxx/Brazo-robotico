Algoritmo sin_titulo
	Definir num1, num2, num3, p,hip, L, A, B, b2, h, area Como Real
	Definir opc, añonacido,mesnacido,dianacido,edad, añoact, mesact, diaact Como Entero
	Definir switch Como Logico
	switch = Verdadero
	Mientras switch Hacer
		Escribir "seleccione la opcion de su preferencia."
		Escribir "1. calcular el perímetro de un triángulo escaleno"
		Escribir "2. calcular la hipotenusa de un triángulo rectángulo"
		Escribir "3. calcular el area de un trapecio"
		Escribir "4. saber si es menor de edad con base en su fecha de nacimiento"
		Escribir "9. salir de la aplicación"
		Leer opc
		Segun opc Hacer
			1:
				Limpiar Pantalla
				Escribir "por favor dame los 3 lados de tu triángulo escaleno"
				Leer num1, num2, num3
				si (num1 >0 O num2> 0 o num3>0) Y  (num1 <> num2 o num1 <> num3 o num2 <> num3)Entonces
					p = num1+num2+num3
					Escribir "el perímetro de su triángulo es: ", p
				SiNo
					Escribir "los números deben ser mayores a 0 y no pueden ser iguales"
				FinSi
			2:
				Limpiar Pantalla
				Escribir "dame el largo y el ancho de tu triángulo."
				Leer L,A
				si (L > A) Y (A>=1 Y A<=30) Y L>0 Entonces
					hip = Raiz((L^2)+(A^2))
					Escribir "La hipotenusa de tu triángulo es: ", hip
				SiNo
					Escribir " tenga en cuenta que largo debe ser el mayor y ancho entre 1 y 30"
				FinSi
			3:
				Limpiar Pantalla
				Escribir "dame las bases 1 y 2 y la altura "
				Leer B,b2,h
				si (B>b2) Y (h>b2 Y h<B) Y (B>0 Y b2>0 Y h>0) Entonces
					area = ((B+b2)*h)/2
					Escribir "El area del trapecio dado es: ", area
				SiNo
					Escribir "Error. La base 1 debe ser mayor a la 2, los datos deben ser positivos y la altura debe ser un valor entre las bases "
				FinSi
			4:
				Escribir "dame el año, mes y dia actual"
				Leer añoact, mesact, diaact
				
				si  ((diaact >=1) Y (diaact <=31)) Y ((mesact >= 1) Y (mesact<=12)) Entonces
					Escribir "Ingrese el año, mes y dia en el que nacio recuerde que debe ser menor a la fecha actual"
					Leer añonacido, mesnacido, dianacido	
				SiNo
					Escribir "la fecha actual no es posible"
				FinSi
				Si (añonacido < añoact) Y ((mesnacido >= 1) Y (mesnacido<=12)) Y ((dianacido >=1) Y (dianacido <=31))  Entonces
					edad = añoact - añonacido
					Si ((mesnacido == 1) O (mesnacido == 3) O (mesnacido == 5) O (mesnacido == 7) O (mesnacido == 8) O (mesnacido == 10) O (mesnacido == 12)) Entonces
						si  ((dianacido >=1) Y (dianacido <=31) )  Entonces
							Si  ((mesnacido>mesact) O ((mesnacido==mesact) Y (dianacido>diaact))) Entonces
								edad=edad-1
							FinSi
						FinSi
					FinSi
					Si ((dianacido >=1) Y (dianacido <=30)) Y ((mesnacido == 4) O (mesnacido == 6) O (mesnacido == 9) O (mesnacido == 11))  Entonces
						si  ((dianacido >=1) Y (dianacido <=30) )  Entonces
							Si  ((mesnacido>mesact) O ((mesnacido==mesact) Y (dianacido>diaact))) Entonces
								edad=edad-1
							FinSi
						FinSi
						
					FinSi
					Si(mesnacido == 2)  Entonces
						si  ((dianacido >=1) Y (dianacido <=28) )  Entonces
							Si  ((mesnacido>mesact) O ((mesnacido==mesact) Y (dianacido>diaact))) Entonces
								edad=edad-1
							FinSi
						FinSi
					FinSi
					si edad>=18  Entonces
						Limpiar Pantalla
						Escribir "usted es mayor de edad"
					SiNo
						Limpiar Pantalla
						Escribir "usted es menor de edad"
					FinSi
				SiNo
					Escribir "las fechas están mal"
				FinSi
			9:
				switch = Falso
			De Otro Modo:
				Escribir " La opccion no es válida"
		FinSegun
		Escribir "presione algo para continuar" 
		Esperar Tecla
	FinMientras
	Escribir "el programa terminó"
	Esperar 2 Segundos
FinAlgoritmo
