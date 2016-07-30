//#define Max 3
#define Max 20

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <conio.h>
#include <windows.h>

using namespace std;

int n=0, aux=0, optn=0, high=0, setwAux=0, count=0;
char optnChar;
bool optnBool, auxBool, found;
string auxString;
int rtaLiq[4] = {25000, 30000, 40000, 50000};
int patrim[4] = {100000, 200000, 250000, 300000};
int valorUC[4] = {100, 200, 250, 300};
string nameMate[11] = {"C\240lculo","Ingl\202s","Geometr\241a","F\241sica","Programaci\242n","Estad\241stica","Redes","Compiladores","Circuitos","Tesis","Nada"};
string codeMate[11] = {"CAL121",    "ING131",    "GEO141",       "FIS211",    "PRO231",          "EST241",         "RED311","COM321",       "CIR341",    "TES411","Nada"};
int UCMate[11] = {4,2,3,3,4,2,4,4,4,4,0};
int mateInsc[Max][3];
int tablaInt[Max][6];
string tabla[Max][2];
string tabl2[Max][2];
//int userInscMate[Max];
string tablaOrd[Max][2];

namespace patch {
	template <typename T>
	std::string to_string(const T& n) {
		std::ostringstream stm;
		stm << n;
		return stm.str();
	}
	int string_to_int(const string &str) {
		stringstream ss;
		ss << str;
		int value;
		ss >> value;
		return value;
	}
	int numDigits(int numEvaluate = 0) {
		int amount = 0;
		do {
			++amount;
			numEvaluate /= 10;
		} while(numEvaluate);
		return amount;
	}
}

string up(string str) {
	for(int i=0; i<str.length(); i++)
		str[i] = toupper(str[i]);
	return str;
}

void header() {
	cout << "============================================================================" << endl;
	cout << "\t\t\t\17 Universidad del Sol \17" << endl << endl;
	cout << "\t\t    Hecho por: Guillermo Fern\240ndez" << endl;
	cout << "\t\t\t   C.I.: 23.751.818" << endl;
	cout << "\t\t     email: fguille94@outlook.com" << endl;
	cout << "============================================================================" << endl;
}

char menu() {
	cout << "\t\tMen\243 principal" << endl;
	cout << "============================================================================" << endl;
	cout << "\t<1> Inscribir Alumno" << endl;
	cout << "\t<2> Buscar Alumno" << endl;
	cout << "\t<3> Listado General" << endl;
	cout << "\t<4> Listado por Materia" << endl;
	cout << "\t<5> Modificar Datos de Alumno" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "\t<0> Salir del Sistema" << endl;
	cout << "============================================================================" << endl;
	cout << "\tIngrese su opci\242n = ";
	optnChar = getch();
	return optnChar;
}

void error(int code) {
	cout << "\t\tError " << code << ": ";
	if(code==401) {
		cout << "Opci\242n err\242nea" << endl;
		cout << "----------------------------------------------------------------------------" << endl;
		cout << "Por favor ingrese una de las opciones presentes en el men\243 principal" << endl << endl;
	} else if(code==402) {
		cout << "Datos insufucientes" << endl;
		cout << "----------------------------------------------------------------------------" << endl;
		cout << "Por favor ingrese estudiantes a la base de datos antes de" << endl;
		cout << "inicializar una b\243squeda" << endl << endl;
	} else if(code==403) {
		cout << "Cupos agotados" << endl;
		cout << "----------------------------------------------------------------------------" << endl;
		cout << "No es posible inscribir m\240s estudiantes ya que se han agotado" << endl;
		cout << "los cupos disponibles" << endl << endl;
	} else if(code==404) {
		cout << "Error title" << endl;
		cout << "----------------------------------------------------------------------------" << endl;
		cout << "Advice" << endl << endl;
	} else if(code==405) {
		cout << "Error title" << endl;
		cout << "----------------------------------------------------------------------------" << endl;
		cout << "Advice" << endl << endl;
	} else if(code==406) {
		cout << "Error title" << endl;
		cout << "----------------------------------------------------------------------------" << endl;
		cout << "Advice" << endl << endl;
	}
}

int rentaLiquida() {
	for(int i=0; i<4; i++) {
		cout << "\t<" << (i+1)<< "> " << rtaLiq[i] << endl;
	}
	cout << "Ingrese su opci\242n: ";
	do {
		optnChar = getch();
	} while(optnChar<49 || optnChar>52);
	cout << optnChar;
	optn = optnChar - 49;
	return optn;
}

int patrimonio() {
	for(int i=0; i<4; i++) {
		cout << "\t<" << (i+1)<< "> " << patrim[i] << endl;
	}
	cout << "Ingrese su opci\242n: ";
	do {
		optnChar = getch();
	} while(optnChar<49 || optnChar>52);
	cout << optnChar;
	optn = optnChar - 49;
	return optn;
}

int inscMat(int i) {
	auxBool=true;
	cout << "============================================================================" << endl;
	cout << "Seleccione la materia \43" << i+1 << " a inscribir:" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "\t <\43> | UC | C\242digo | Nombre" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	for(int i=0; i<10; i++) {
		setwAux = patch::numDigits(i+1);
		if(setwAux==1) {
			setwAux=2;
		} else if(setwAux==2) {
			setwAux=0;
		}
		cout << "\t" << setw(setwAux) << right << "<" << i+1 << "> | " << setw(2) << UCMate[i] << " | " << left << setw(5) << codeMate[i] << " | " << nameMate[i] << endl;
	}
	cout << "----------------------------------------------------------------------------" << endl;
	do {
		do {
			cout << "Ingrese su opci\242n: ";
			cin >> optn;
			cin.ignore();
		} while(optn<1 || optn>10);
		cout << "Haz seleccionado " << nameMate[optn-1] << ". Es la opci\242n correcta? (S/N)" << endl;
		cout << "Respuesta: ";
		do {
			optnChar = toupper(getch());
			if(optnChar=='S') {
				cout << "S\241 lo es!" << endl;
				optnBool = false;
				auxBool = false;
			} else if(optnChar=='N') {
				cout << "No lo es!" << endl;
				optnBool = true;
				auxBool = false;
			} else {
				auxBool = true;
			}
		} while(auxBool);
	} while(optnBool);
	return optn-1;
}

void insc() {
	high = 0;
	if(n<Max) {
		for(int l=0; l<3; l++) {
			mateInsc[n][l] = -1;
		}
		cout << "\t\tInscribir Alumno \43" << n+1 << endl;
		cout << "============================================================================" << endl;
		cout << "Ingrese el primer nombre y primer apellido del estudiante:" << endl;
		do {
			getline(cin,auxString);
		} while(auxString.empty());
		tabla[n][1] = up(auxString);
		cout << endl << "Ingrese la c\202dula de identidad del estudiante: ";
		do {
			do {
				cin >> aux;
				cin.ignore();
				if(aux<999999 || aux>99999999) {
					cout << "El rango aceptado esta comprendido entre 999.999 y 99.999.999" << endl << endl;
					cout << "Ingrese la c\202dula de identidad del estudiante: ";
				}
			} while(aux<999999 || aux>99999999);
			tabla[n][0] = patch::to_string(aux);
			for(int m=0; m<n; m++) {
				if(tabla[n][0] == tabla[m][0]) {
					found = true;
					cout << "La c\202dula de identidad ingresada ya existe" << endl << endl;
					cout << "Ingrese la c\202dula de identidad del estudiante: ";
					break;
				} else {
					found = false;
				}
			}
		} while(found);
		aux = 0;
		cout << endl << "Seleccione el aproximado a su Renta L\241quida de la siguiente lista:" << endl;
		aux = rentaLiquida();
		tablaInt[n][3] = aux;
		aux = 0;
		cout << endl << endl << "Seleccione el aproximado a su Patrimonio de la siguiente lista:" << endl;
		aux = patrimonio();
		tablaInt[n][4] = aux;
		aux = 0;
		cout << endl << endl << "Procesando datos . . ." << endl;
		if(tablaInt[n][3] > tablaInt[n][4]) {
			high = tablaInt[n][3];
		} else {
			high = tablaInt[n][4];
		}
		tablaInt[n][1] = high;
		system("pause");
		system("cls");
		header();
		cout << "\t\tInscribir Alumno \43" << n+1 << endl;
		cout << "============================================================================" << endl;
		cout << "Nombre y Apellido: " << tabla[n][1] << endl;
		cout << "C\202dula de Identidad: " << tabla[n][0] << endl;
		cout << "Valor de UC: " << valorUC[tablaInt[n][1]] << endl;
		for(int i=0; i<3; i++) {
			do {
				aux = inscMat(i);
				for(int k=0; k<=i; k++) {
					if(mateInsc[n][k]==aux) {
						cout << "============================================================================" << endl;
						cout << "Materia no ha sido inscrita porque ya lo est\240" << endl;
						optnBool = true;
						break;
					} else {
						optnBool = false;
					}
				}
			} while(optnBool);
			mateInsc[n][i] = aux;
			tablaInt[n][2] = i+1;
			tablaInt[n][0] += UCMate[aux];
			cout << "----------------------------------------------------------------------------" << endl;
			if(i==0) {
				cout << i+1 << " materia inscrita: UC C\242digo Nombre" << endl << endl;
				setwAux = 22;
			} else {
				cout << i+1 << " materias inscritas: UC C\242digo Nombre" << endl << endl;
				setwAux = 24;
			}
			for(int j=0; j<i+1; j++) {
				cout << right << setw(setwAux) << UCMate[mateInsc[n][j]] << " " << codeMate[mateInsc[n][j]] << "  " << nameMate[mateInsc[n][j]] << endl;
			}
			cout << "Materia inscrita: " << nameMate[mateInsc[n][i]] << endl;
			cout << "UC de " << nameMate[mateInsc[n][i]] << ": " << UCMate[mateInsc[n][i]] << endl;
			cout << "Total de UC inscritas: " << tablaInt[n][0] << endl;
			aux = 0;
			cout << "----------------------------------------------------------------------------" << endl;
			if(i<2) {
				cout << endl << "Deseas inscribir otra materia (S/N)?" << endl;
				cout << "Respuesta: ";
				do {
					optn = toupper(getch());
					if(optn=='S') {
						cout << "S\241 lo deseo!" << endl;
						auxBool = false;
					} else if(optn=='N') {
						cout << "No lo deseo!" << endl;
						auxBool = false;
						if(i>=0) {
							mateInsc[n][2] = 10;
							if(i==0) {
								mateInsc[n][1] = 10;
							}
						}
					} else {
						auxBool = true;
					}
				} while(auxBool);
				if(optn=='N') {
					if(i>=0) {
						mateInsc[n][2] = 10;
						if(i==0) {
							mateInsc[n][1] = 10;
						}
					}
					break;
				}
			}
			cout << endl;
		}
		tablaInt[n][5] = (valorUC[tablaInt[n][1]]*tablaInt[n][0])+260;
		cout << "Materias inscritas: " << tablaInt[n][2] << endl;
		cout << "La inscripci\242n de materias ha sido completada" << endl << endl;
		n++;
		aux=0;
	} else {
		error(403);
	}
}

int selecBuscAlum() {
	auxString = "";
	cout << "Ingrese la C.I. del Alumno: ";
	//do {
		cin >> aux;
		cin.ignore();
	//} while(aux<999999 || aux>99999999);
	auxString = patch::to_string(aux);
	for(int i=0; i<n; i++) {
		if(auxString==tabla[i][0]) {
			optn = i;
			found = true;
			break;
		} else {
			found = false;
		}
	}
	if(!found) {
		cout << "Estudiante no encontrado!" << endl;
	}
	return optn;
}

void busc() {
	if(n>0) {
		cout << "\t\tBuscar Alumno" << endl;
		cout << "============================================================================" << endl;
		optn = selecBuscAlum();
		if(found) {
			system("cls");
			header();
			cout << "\t\tB\243squeda de Alumno" << endl;
			cout << "============================================================================" << endl;
			cout << "Nombre: " << tabla[optn][1] << endl;
			cout << "C.I.: " << tabla[optn][0] << endl;
			cout << "----------------------------------------------------------------------------" << endl;
			cout << "Renta L\241quida  |  Patrimonio  |  UC Inscritas  |  Matr\241cula  |  Valor UC" << endl;
			cout << right << setw(13) << rtaLiq[tablaInt[optn][3]] << "  |  " << setw(10) << patrim[tablaInt[optn][4]] << "  |  " << setw(12) << tablaInt[optn][0];
			cout << right << "  |  " << setw(9) << tablaInt[optn][5] << "  |  " << setw(8) << valorUC[tablaInt[optn][1]] << endl;
			cout << "----------------------------------------------------------------------------" << endl;
			cout << "Materias Inscritas (" << tablaInt[optn][2] << "):" << endl;
			cout << "\tUC\tC\242digo\tNombre" << endl;
			cout << "----------------------------------------------------------------------------" << endl;
			for(int i=0; i<3; i++) {
				if(mateInsc[optn][i]!=10) {
					cout << "\t" << UCMate[mateInsc[optn][i]] << "\t" << codeMate[mateInsc[optn][i]] << "\t" << nameMate[mateInsc[optn][i]] << endl;
				}
			}
			cout << "----------------------------------------------------------------------------" << endl;
		}
	} else {
		error(402);
	}
}

void listGen() {
	if(n>0) {
		cout << "\t\tListado General" << endl;
		cout << "============================================================================" << endl;
		cout << left << "  \43 " << setw(11) << "| C.I." << setw(31) << "| Nombre y Apellido" << endl;
		cout << "----------------------------------------------------------------------------" << endl;
		for(int i=0; i<n; i++) {
			tablaOrd[i][0] = tabla[i][0];
			tablaOrd[i][1] = tabla[i][1];
		}
		for (int i=0; i<(n-1); i++) {
			for (int j=0; j<(n-1); j++) {
				if (tablaOrd[j][1] > tablaOrd[j+1][1]) {
					auxString = tablaOrd[j][0];
					tablaOrd[j][0] = tablaOrd[j+1][0];
					tablaOrd[j+1][0] = auxString;
					//names
					auxString = tablaOrd[j][1];
					tablaOrd[j][1] = tablaOrd[j+1][1];
					tablaOrd[j+1][1] = auxString;
				}
			}
		}
		for(int i=0; i<n; i++) {
			cout << setw(3) << right << i+1 << " |" << setw(9) << right << tablaOrd[i][0] << " | " << setw(30) << left << tablaOrd[i][1] << endl;
		}
		cout << "----------------------------------------------------------------------------" << endl;
		cout << left << "Total de estudiantes inscritos: " << n << endl;
	} else {
		error(402);
	}
}

int selectMate() {
	auxBool=true;
	cout << "Se mostrar\240n los alumnos inscritos en la materia seleccionada" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	cout << " <\43> UC C\242digo Nombre" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	for(int i=0; i<10; i++) {
		setwAux = patch::numDigits(i+1);
		if(setwAux==1) {
			setwAux=2;
		} else if(setwAux==2) {
			setwAux=0;
		}
		cout << setw(setwAux) << right << "<" << i+1 << ">  " << UCMate[i] << " " << codeMate[i] << "  " << nameMate[i] << endl;
	}
	cout << "----------------------------------------------------------------------------" << endl;
	do {
		cout << "Ingrese su opci\242n: ";
		cin >> optn;
		cin.ignore();
	} while(optn<1 || optn>10);
	return optn-1;
	cout << "============================================================================" << endl;
}

void listMate() {
	if(n>0) {
		count = 0;
		found = false;
		cout << "\t\tListado por Materia" << endl;
		cout << "============================================================================" << endl;
		aux = selectMate();
		system("cls");
		header();
		cout << "\t\tListado por Materia" << endl;
		cout << "|==aux="<<aux<<"==|==count="<<count<<"==|==a="<<found<<"==|===================================" << endl;
		for(int i=0; i<n; i++) {
			if(mateInsc[i][0]==aux) {
				found = true;
				tabl2[i][0] = tabla[i][0];
				tabl2[i][1] = tabla[i][1];
				count++;
			}
			if(mateInsc[i][1]==aux) {
				found = true;
				tabl2[i][0] = tabla[i][0];
				tabl2[i][1] = tabla[i][1];
				count++;
			}
			if(mateInsc[i][2]==aux) {
				found = true;
				tabl2[i][0] = tabla[i][0];
				tabl2[i][1] = tabla[i][1];
				count++;
			}
		}
		cout << "materias inscritas[1,2,3]" << endl;
		cout << "# 123" << endl;
		for(int i=0; i<n; i++) {
			cout << i << " " << mateInsc[i][0] << mateInsc[i][1] << mateInsc[i][2] << endl;
		}
		if(found) {
			cout << "\tEstudiantes inscritos en " << nameMate[aux] << endl;
			cout << "----------------------------------------------------------------------------" << endl;
			cout << left << "  \43 " << setw(11) << "| C.I." << setw(31) << "| Nombre y Apellido" << endl;
			cout << "----------------------------------------------------------------------------" << endl;
			for(int i=0; i<count; i++) {
				cout << setw(3) << right << i+1 << " |" << setw(9) << right << tabl2[i][0] << " | " << setw(30)<<left << tabl2[i][1] <<endl;
			}
			cout << "----------------------------------------------------------------------------" << endl;
			cout << left << "Total de estudiantes inscritos: " << count << endl;
		} else {
			cout << "No hay alumnos inscritos en " << nameMate[aux] << endl;
		}
	} else {
		error(402);
	}
}

void otro() {
	if(n>0) {
		cout << "\t\tModificar datos de Alumno" << endl;
		cout << "============================================================================" << endl;
		optn = selecBuscAlum();
		if(found) {
			system("cls");
			header();
			cout << "\t\tAlumno seleccionado: " << tabla[optn][1] << endl;
			cout << "============================================================================" << endl;
			cout << "\t<1> Nombre y Apellido" << endl;
			cout << "\t<2> C\202dula de Identidad" << endl;
			/*cout << "\t<3> " << endl;
			cout << "\t<4> Materias Inscritas" << endl;*/
			cout << "----------------------------------------------------------------------------" << endl;
			cout << "Campo a Modificar: ";
			do {
				optnChar = getch();
			} while(optnChar<49 || optnChar>50);
			switch(optnChar) {
				case '1':
					cout << "Nombre y Apellido" << endl;
					cout << "Ingrese el nuevo nombre:" << endl;
					do {
						getline(cin,auxString);
					} while(auxString.empty());
					tabla[optn][1] = up(auxString);
					cout << "----------------------------------------------------------------------------" << endl;
					cout << "Nombre modificado!" << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					Sleep(200);
					break;
				case '2':
					cout << "C\202dula de Identidad" << endl;
					cout << "Ingrese la nueva C.I.:" << endl;
					do {
						cin >> aux;
					} while(aux<999999 || aux>99999999);
					cin.ignore();
					tabla[optn][0] = patch::to_string(aux);
					aux = 0;
					cout << "----------------------------------------------------------------------------" << endl;
					cout << "C\202dula de Identidad modificada!" << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
					/*case '3':
						cout << "Patrimonio" << endl;
						cout << "needs to be finished" << endl;
						break;
					case '4':
						cout << "Materias Inscritas" << endl;
						for(int i=0; i<3; i++) {
							do {
								aux = inscMat(i);
								for(int k=0; k<=i; k++) {
									if(mateInsc[optn][k]==aux) {
										cout << "============================================================================" << endl;
										cout << "Materia no ha sido inscrita porque ya lo est\240" << endl;
										optnBool = true;
										break;
									} else {
										optnBool = false;
									}
								}
							} while(optnBool);
							mateInsc[optn][i] = aux;
							tablaInt[optn][2] = i+1;
							tablaInt[optn][0] += UCMate[aux];
							cout << "----------------------------------------------------------------------------" << endl;
							if(i==0) {
								cout << i+1 << " materia inscrita: UC C\242digo Nombre" << endl << endl;
								setwAux = 22;
							} else {
								cout << i+1 << " materias inscritas: UC C\242digo Nombre" << endl << endl;
								setwAux = 24;
							}
							for(int j=0; j<i+1; j++) {
					cout << right << setw(setwAux) << UCMate[mateInsc[optn][j]] << " " << codeMate[mateInsc[optn][j]] << "  " << nameMate[mateInsc[optn][j]] <<endl;
							}
							cout << "Materia inscrita: " << nameMate[mateInsc[optn][i]] << endl;
							cout << "UC de " << nameMate[mateInsc[optn][i]] << ": " << UCMate[mateInsc[optn][i]] << endl;
							cout << "Total de UC inscritas: " << tablaInt[optn][0] << endl;
							aux = 0;
							cout << "----------------------------------------------------------------------------" << endl;
							if(i<2) {
								cout << endl << "Deseas inscribir otra materia (S/N)?" << endl;
								cout << "Respuesta: ";
								do {
									optn = toupper(getch());
									if(optn=='S') {
										cout << "S\241 lo deseo!" << endl;
										auxBool = false;
									} else if(optn=='N') {
										cout << "No lo deseo!" << endl;
										auxBool = false;
										if(i>=0) {
											mateInsc[optn][2] = 10;
											if(i==0) {
												mateInsc[optn][1] = 10;
											}
										}
									} else {
										auxBool = true;
									}
								} while(auxBool);
								if(optn=='N') {
									if(i>=0) {
										mateInsc[optn][2] = 10;
										if(i==0) {
											mateInsc[optn][1] = 10;
										}
									}
									break;
								}
							}
							cout << endl;
						}
						tablaInt[optn][5] = valorUC[tablaInt[optn][1]]*tablaInt[optn][0];
						cout << "Materias inscritas: " << tablaInt[optn][2] << endl;
						cout << "La inscripci\242n de materias ha sido completada" << endl << endl;
						aux=0;
						break;*/
			}
		}
	} else {
		error(402);
	}
}

main() {
	do {
		system("cls");
		header();
		optnChar = menu();
		system("cls");
		switch(optnChar) {
			case '1':
				header();
				insc();
				system("pause");
				break;
			case '2':
				header();
				busc();
				system("pause");
				break;
			case '3':
				header();
				listGen();
				system("pause");
				break;
			case '4':
				header();
				listMate();
				system("pause");
				break;
			case '5':
				header();
				otro();
				system("pause");
				break;
			case '0':
				header();
				cout << "\334\334\334" << endl;
				cout << "\333  \333     " << endl;
				cout << "\333\376\376   \334   \334  \334\334\334\334" << endl;
				cout << "\333  \333   \337\334\337   \333\376\376\376" << endl;
				cout << "\337\337\337     \337    \337\337\337\337" << endl;
				Sleep(200);
				break;
			default:
				header();
				error(401);
				system("pause");
		}
	} while(optnChar!='0');
}
