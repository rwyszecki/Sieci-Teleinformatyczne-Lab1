/*Robert Wyszecki
Sieci Teleinformatyczne
Laboratorium nr 1
data ostatniej aktualizacji 07.10 2016*/

#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <fstream>
#include "function.h"

using namespace std;

int main(){
	string startText;				//Zmienna pomocnicza przechowująca wczytany na początku tekst
	string startBinary;				//Zmienna przechowująca tekst startowy zapisany za pomocą kodu binarnego
	string demagedText;				//Zmienna przechowująca tekst startowy z błędem
	int menuChoice = 0;				//Zmienna pomocnicza do wyboru opcji błędu, w menu programu
	int bitChoice = 0;				//Zmienna pomocnicza do wyboru ilosci bitow CRC
	


	openStartFile(startText);							//Funkcja otwierająca plik tekstowy i przypisująca go do zmiennej "startText"
	saveBinaryFile(startText,startBinary);				//Funkcja zmieniająca tekst starttowy na kod binarny i zapisująca go do pliku i przypisująca go do zmiennej "startBinary"
	menu(&menuChoice, &bitChoice);						//menu programu
	demageText(menuChoice, startBinary, demagedText);	//funkcja uszkadzająca plik startowy
	bitParzystosci(startBinary, demagedText);			//funkcja sprawdzająca bit parzystosci
	sumaMod10(startBinary, demagedText);				//funkcja sprawdzajaca sume modulo 10
	CRC(bitChoice);

	system("pause");
	return 0;
}