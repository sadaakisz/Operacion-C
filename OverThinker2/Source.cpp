#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>
#include <functional>
using namespace std;
using namespace System;


auto imprimir = [](string a) {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
		_sleep(1);
	}
	cout << " ";
};

int escenario(string nombreArchivo) {
	ifstream f(nombreArchivo);
	string line, num;
	bool swt = 0;
	char res;
	bool swt2 = 1;
	if (!f.is_open()) {
		cout << "El archivo no se logro abrir\n";
		return 0;
	}
	while (f >> line) {

		stringstream ss(line);
		while (getline(ss, num, '$')) {
			if (line == "-" || line == "&") _sleep(1);
			else if (swt2 == 1) imprimir(num);
		}
		if (line == "$"&&swt2 == 1) {
			cout << endl << endl;
			_sleep(80);
			if (swt == 1) {
				cin >> res, swt = 0;
				if (res == 's' || res == 'S') swt2 = 0;
				else if (res == 'n' || res == 'N') swt2 = 1;
			}
			Console::ForegroundColor = ConsoleColor::White;
		}

		else {
			if (line == "-") {
				Console::ForegroundColor = ConsoleColor::Green;
			}
			else
				if (line == "*") {
					Console::ForegroundColor = ConsoleColor::DarkCyan;
				}
				else if (line == "#") {
					Console::ForegroundColor = ConsoleColor::Red;
					swt = 1;
				}
				else if (line == "~") {
					if (swt2 == 0) swt2 = 1;
					else if (swt2 == 1) swt2 = 0;
					Console::ForegroundColor = ConsoleColor::Yellow;
				}
				else if (line == "&") {
					Console::ForegroundColor = ConsoleColor::Magenta;
				}
		}

	}
	f.close();
}


int main() {
	setlocale(LC_ALL, "spanish");
	//escenario("Introduccion.txt");
	
	escenario("Z0Persona 01.txt");


	/*ifstream f("Introducción.txt");
	string line, num;
	bool swt = 0;
	char res;
	bool swt2 = 1;
	if (!f.is_open()) {
		cout << "El archivo no se logro abrir\n";
		return 0;
	}
	while (f >> line) {
		
			stringstream ss(line);
			while (getline(ss, num, '$')) {
				if (line == "-"||line=="&") _sleep(1);
				else if (swt2==1) imprimir(num);
			}
			if (line == "$"&&swt2==1) {
				cout << endl << endl;
				_sleep(80);
				if (swt == 1) {
					cin >> res, swt = 0;
					if (res == 's' || res == 'S') swt2 = 0;
					else if (res == 'n' || res == 'N') swt2 = 1;
				}
				Console::ForegroundColor = ConsoleColor::White;
			}
			
			else{
				if (line == "-") {
					Console::ForegroundColor = ConsoleColor::Green;
				}
				else
					if (line == "*") {
						Console::ForegroundColor = ConsoleColor::DarkCyan;
					}	
					else if (line == "#") {
						Console::ForegroundColor = ConsoleColor::Red;
						swt = 1;
					}
					else if (line == "~") { 
						if (swt2 == 0) swt2 = 1; 
						else if (swt2 == 1) swt2 = 0;
						Console::ForegroundColor = ConsoleColor::Yellow;
					}
					else if (line == "&") {
						Console::ForegroundColor = ConsoleColor::Magenta;
					}
				}
		
	}

	f.close();*/
	_getch();
	return 0;
}
