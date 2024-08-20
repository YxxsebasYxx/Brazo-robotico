Algoritmo sin_titulo
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
	si bici<=9 Entonces
		Escribir "Este es el precio de cada bicicleta si las unidades no superan las 9"
		Escribir precio1
		cantidad = bici*precio1
		Escribir "Gracias por su compra a nombre de ",name "  numero ", id
		Escribir "Subtotal: ", cantidad
		Escribir "Iva(16%): ", cantidad*(16/100)
		Escribir "Total: ",cantidad+cantidad*(16/100)
	FinSi
	si bici>=10 y bici<20
		Escribir "Este es el precio de cada bicicleta si las unidades no superan las 20"
		Escribir precio2
		cantidad = bici*precio2
		Escribir "Gracias por su compra a nombre de ",name " id: ", id
		Escribir "Subtotal: ", cantidad
		Escribir "Iva(16%): ", cantidad*(16/100)
		Escribir "Total: ",cantidad+cantidad*(16/100)
	Sino si bici>=20
			Escribir "Este es el precio de cada bicicleta si las unidades superan las 20"
			Escribir precio3
			cantidad = bici*precio3
			Escribir "Gracias por su compra a nombre de ",name "  numero ", id
			Escribir "Subtotal: ", cantidad
			Escribir "Iva(16%): ", cantidad*(16/100)
			Escribir "Total: ",cantidad+cantidad*(16/100)
		Fin Si
	FinSi
FinAlgoritmo
