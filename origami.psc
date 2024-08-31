Algoritmo sin_titulo
	Definir hojita_cuadrada Como Cadena
	Escribir 'para realizar un dragon de origami necesitas una hoja cuadrada'
	Leer hojita_cuadrada
	Mientras terinado==falso Hacer
		Si hojita_cuadrada=='lista' Entonces
			Escribir 'junta una esquina superior con su contraria inferior, formando un triángulo'
			Si TRIANGULO==hecho Entonces
				Escribir 'desdoblelo hasta obtener el cuadrado, y ver una diagonal en el centro'
				Si hoja=='desdoblada' Entonces
					Escribir 'girala, 90, grados, a, la, izquierda'
					Escribir 'junta una esquina superior con su contraria inferior, formando un triángulo'
					Si TRIANGULO==hecho Entonces
						Escribir 'desdoblelo hasta obtener el cuadrado, y ver una diagonal en el centro'
						Si hoja=='desdoblada' Entonces
							Escribir 'pon la hoja al revez (el frente hacia atras)'
							Escribir 'ahora doblela por la mitad formando un rectángulo, juntando ambas esquinas inferiores con las superiores'
							Si rectangulo=='hecho' Entonces
								Escribir 'desdoblelo'
								Si papel=='desdoblado' Entonces
									Escribir 'gire 90'
									Escribir 'haga otro rectangulo igual al anterior'
									Si rectangulo=='hecho' Entonces
										Escribir 'desdoblelo'
										Si papel='desdoblado' Entonces
											Escribir 'trata dejuntar las lineas diagonales en el centro de manera que las puntas se junten y el papel forme un rombo'
											Si rombo=='formado' Entonces
												Escribir 'ahora ubica las puntas abajo '
												Escribir 'leva las aristas inferiores hasta la linea del medio.unicamente las dos de encima'
												Si aristas=='dobladas' Entonces
													Escribir 'repite los dos pasos en la otra cara de la hoja'
													Si cara1==cara2 Entonces
														Escribir 'ahora dobla el triangulo que se formó en la prte superior hacia abajo en ambas caras para marcar una linea'
														Si aristas==desdobladas Y triangulo_superior==marcado Entonces
															Escribir 'levanta la punta superior hasta que quede perpendicular a la linea del triángulo anteriormente formado'
															Escribir 'desdobla las aristas'
															Si punta=='levantada' Entonces
																Escribir 'ahora mete las esquinas laterales hacia la linea del medio'
																Escribir ' obtendras un rombo más alto'
																Si ROMBO_PEQUENO=='formado' Entonces
																	Escribir 'repite esto en la otra cara'
																	Si repetido=='si' Entonces
																		Escribir 'doble la arista superior derecha sobre la linea horizontal'
																		Escribir 'desdobla y repite con la superior izquierda, al desdoblar verás una x sobre la linea horizontal'
																		Si 'x sobre linea horizontal' Entonces
																			Escribir 'Dobla ambas esquinas superiores de la x hacia la interseccion de la lineas horizontal y vertical'
																			Escribir 'repite esto del otro lado'
																			Escribir 'de esta forma quedan dos picos hacia los lados'
																			Si esquinas_A_y_B=='centro' Y picos==2 Entonces
																				Escribir 'mueve los picos hacia uno de los lados y del lado contrario separa las esquinas formando otro diamante'
																				Si diamante_lateral=='formado' Entonces
																					Escribir 'sube la punta inferior hasta que con ayuda de la linea horizontal se forme un triángulo grande'
																					Si triangulo_grande=='formado' Entonces
																						Escribir 'dobla las esquinas inferiores hacia la linea central del triángulo, formando un rombo pequeño'
																						Escribir 'marca bien los pliegues'
																						Si ROMBO_PEQUENO=='hecho' Entonces
																							Escribir 'desdoblalas y baja la punta hasta que quede en el mismo ángulo que el triangulo central de toda la figura'
																							Escribir 'mientras bajas junta las esquinas formadas en los dobleces anteriores, de este modo se forma un triangulo mas puequeño similar al central'
																							Si TRIANGULO_PEQUENO=='logrado' Entonces
																								Escribir 'mueve los picos hacia este lado y y repite del lado que falta hasta tener algo parecido a 3 montaañas'
																								Si MONTANA_IZQ==MONTANA_DER Entonces
																									Escribir 'esconde las puntas de las montañas laterales dentro de si mismas (hazlo en ambas caras a la derecha y a la izquierda)'
																									Si puntas=='esconidas' Entonces
																										Escribir 'dobla las esquinas inferiores del triángulo central en direccion a la mitad hasta donde te lo permita'
																										Escribir 'deberia de queda rmirando un poco por debajo dellado inferior del triangulo (son las patas)'
																										Si patas=='formadas' Entonces
																											Escribir 'recuerdas los picos que hemos estado moviendo por todos lados?'
																											Escribir 'doblalos en diagonal hacia una misma direccion ten en cuenta que la esquina inferior se ubica en la mitad del triangulo central'
																											Si alas=='formadas' Entonces
																												Escribir 'por ultimo. desde el lado contrario de donde doblaste las alas'
																												Escribir 'presiona por abajo del minitriangulo doblandolo dentro de si hasta que quede vertical'
																												Escribir 'y cerca de la punta empujalo hacia abajo otra vez dentro de si misma, finalizamos con devolver la punta hacia arriba para terminar asi la cabeza'
																												Si cabeza=='logrado' Entonces
																													Escribir 'flicidades has completado el dragon de origami'
																												SiNo
																													Escribir 'este paso es algo complicado asi que busca la forma de un hocico'
																												FinSi
																												terminado = verdadero
																											SiNo
																												Escribir 'intenta otra vez'
																											FinSi
																										SiNo
																											Escribir 'trata de doblarla un poco más'
																										FinSi
																									SiNo
																										Escribir 'puedes ayudarte abriendo la esquina inferior del triángulo central'
																									FinSi
																								SiNo
																									Escribir 'si lo hiciste con una puedes con la otra'
																								FinSi
																							SiNo
																								Escribir 'puede ser algo complicado, no te rindas'
																							FinSi
																						SiNo
																							Escribir 'mira bien la linea vertical'
																						FinSi
																					SiNo
																						Escribir 'ubica bien la linea horizontal '
																					FinSi
																				SiNo
																					Escribir 'revisa desde todos los lados'
																				FinSi
																			SiNo
																				Escribir 'si los picos quedan juntos no hay problema vas bien'
																			FinSi
																		SiNo
																			Escribir 'marca bien los dobleces y recuerda que horizontal es de izquierda a derecha'
																		FinSi
																	SiNo
																		Escribir 'forma de nuevo el rombo alto'
																	FinSi
																SiNo
																	Escribir 'revisa bien los pasos'
																FinSi
															SiNo
																Escribir 'que parezca un recipiente'
															FinSi
														SiNo
															Escribir 'desdobla hasta obtener el rombo otra vez'
														FinSi
													SiNo
														Escribir 'unicamente dobla las aristas del oro lado de la hoja'
													FinSi
												SiNo
													Escribir 'intentalo otra vez'
												FinSi
											SiNo
												Escribir 'se que es complicado pero intentalo de nuevo'
											FinSi
										SiNo
											Escribir 'desdoblelo pues'
										FinSi
									SiNo
										Escribir 'solo abra el papel otra vez'
									FinSi
								SiNo
									Escribir 'ole pero eso era super simple'
								FinSi
							SiNo
								Escribir 'es simple tu puedes '
							FinSi
						SiNo
							Escribir 'que estas esperando'
						FinSi
					SiNo
						Escribir 'ya lo hiciste antes repitelo y ya'
					FinSi
				SiNo
					Escribir 'desdoblela ser humano'
				FinSi
			SiNo
				Escribir 'papi hacé el triangulo'
			FinSi
		SiNo
			Escribir 've manito y con que lo vas a hacer'
		FinSi
	FinMientras
FinAlgoritmo
