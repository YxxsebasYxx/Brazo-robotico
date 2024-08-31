Algoritmo sin_titulo
	Definir carac Como Caracter
	Escribir "ahora que verificamos tu edad dame tu nombre para poder hacer tu carta astral"
	Leer  nombre
	Escribir "tambien tu apellido"
	leer apellido
	Ncompleto= Concatenar(nombre,apellido)
	Dimension carac_[5]
	carac_[1] = "a"
	carac_[2] = "e"
	carac_[3] = "i"
	carac_[4] = "o"
	carac_[5] = "u"
	largo =Longitud(Ncompleto)
	largo = convertiranumero("5")
	Escribir largo
	Esperar Tecla
	Dimension letras[largo]
	para i=1 Hasta i=largo Hacer
		
		
	FinPara
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
FinAlgoritmo
