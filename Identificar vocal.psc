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
FinAlgoritmo
