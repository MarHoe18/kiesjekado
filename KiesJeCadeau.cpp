#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>

using namespace std;

void electronica(string& deelnemer, int& leeftijd, float& budget, string& kadolijst);
void gezondheid(string& deelnemer, int& leeftijd, float& budget, string& kadolijst);
void koken(string& deelnemer, int& leeftijd, float& budget, string& kadolijst);
void lijstDeelnemers();
void kiesKado(string& deelnemer, int& leeftijd, float& budget, string& kadolijst);
void deelname();
void lijstDeelnemers(string& deelnemer, int& leeftijd, float& budget, string& kadolijst);

void kiesKado(string& deelnemer, int& leeftijd, float& budget, string& kadolijst) {
	int keus;

	while (budget >= 20) {
		system("cls");
		cout << kadolijst << endl;
		cout << "Beschikbaar budget: " << budget << endl << endl;

		cout << "U heeft de keus uit de volgende categorien om een kado te kiezen:\n\n";
		cout << "Kies 1 voor de categorie Electronica\n";
		cout << "Kies 2 voor de categorie Gezondheid\n";
		cout << "Kies 3 voor de categorie Koken\n\n";

		cout << "Maak uw keus: ";
		cin >> keus;

		switch (keus) {
		case 1:
			electronica(deelnemer, leeftijd, budget, kadolijst);
			break;

		case 2:
			gezondheid(deelnemer, leeftijd, budget, kadolijst);
			break;

		case 3:
			koken(deelnemer, leeftijd, budget, kadolijst);
			break;

		default:
			cout << "verkeerde keus..\n";
			system("pause");
			system("cls");
			deelname();
		}
	}

	// op dit moment is het budget op, wat te doen
	system("cls");
	cout << "\nU heeft uw budget goed besteed. Maak uw keuze om verder te gaan..\n\n";
	cout << "Gekozen cadeaus: " << kadolijst << endl;
	cout << "Beschikbaar budget: " << budget << endl << endl;

	// hier de gegevens wegschrijven
	fstream f("kadolijst.txt", f.out | f.app);
	f << deelnemer << ", " << leeftijd << " jaar oud heeft gekozen voor: " <<
		kadolijst << endl;

	// dan, hoe verder..
	cout << "Kies 1 voor volgende deelnemer.. ";
	cout << "\nKies 2 voor de lijst met deelnemers.. ";
	cout << "\nKies 3 om te stoppen\n\n";
	cout << "Uw keus: ";
	cin >> keus;
	if (keus == 3)
		exit(0);
	else if (keus == 2)
		lijstDeelnemers(deelnemer, leeftijd, budget, kadolijst);
	else {
		kadolijst = "";
		deelname();
	}
}

void deelname() {
	string deelnemer;
	int leeftijd;
	float budget = 0;
	string kadolijst = " ";

	system("cls");
	cout << "Geachte deelnemer,\n\nIn deze applicatie heeft u de mogelijkheid een kado uit te kiezen. ";
	cout << "\n\nWat is uw naam? \n";
	cin >> deelnemer;
	cout << "\nEn wat is uw leeftijd? \n";
	cin >> leeftijd;

	if ((leeftijd > 18) && (leeftijd < 70)) {
		budget = leeftijd * 2;
		cout << "Hallo " << deelnemer << ", uw budget voor kado keuze is: " <<
			budget << " euro" << endl << endl;
		kiesKado(deelnemer, leeftijd, budget, kadolijst);
	}
	else {
		cout << "ongeldige leeftijd..";
		system("pause");
		system("cls");
		deelname();
	}

}

void electronica(string& deelnemer, int& leeftijd, float& budget, string& kadolijst) {
	string elec[] = { "wekkerradio", "platenspeler", "drone" };
	float prijzen[] = { 20, 50, 75 };

	system("cls");
	cout << "In de categorie Electronica heb je de keus uit de volgende items:\n\n";
	int keus;
	for (int x = 0; x < 3; x++) {
		cout << x + 1 << ". " << elec[x] << endl;
	}

	cout << "\nWelk kado kies je? ";
	cin >> keus;

	// eerst de controle of het budget toereikend is..
	if (budget < prijzen[keus - 1]) {
		cout << "Uw budget is niet toereikend voor dit kado. Maak een andere keus..";
		system("pause");
		electronica(deelnemer, leeftijd, budget, kadolijst);
	}
	else {
		budget -= prijzen[keus - 1];
		kadolijst += elec[keus - 1] + "; ";
	}
}

void gezondheid(string& deelnemer, int& leeftijd, float& budget, string& kadolijst) {
	string gezheid[] = { "bloeddrukmeter", "stappenteller", "sauna-ticket" };
	float prijzen[] = { 50, 20, 75 };

	system("cls");
	cout << "In de categorie Electronica heb je de keus uit de volgende items:\n\n";
	int keus;
	for (int x = 0; x < 3; x++) {
		cout << x + 1 << ". " << gezheid[x] << endl;
	}

	cout << "\nWelk kado kies je? ";
	cin >> keus;

	if (budget < prijzen[keus - 1]) {
		cout << "Uw budget is niet toereikend voor dit kado. Maak een andere keus..";
		system("pause");
		gezondheid(deelnemer, leeftijd, budget, kadolijst);
	}
	else {
		budget -= prijzen[keus - 1];
		kadolijst += gezheid[keus - 1] + "; ";
	}
}

void koken(string& deelnemer, int& leeftijd, float& budget, string& kadolijst) {
	string kookitems[] = { "messenset", "mixer", "hapjespan" };
	float prijzen[] = { 80, 45, 20 };

	system("cls");
	cout << "In de categorie Electronica heb je de keus uit de volgende items:\n\n";
	int keus;
	for (int x = 0; x < 3; x++) {
		cout << x + 1 << ". " << kookitems[x] << endl;
	}

	cout << "\nWelk kado kies je? ";
	cin >> keus;

	if (budget < prijzen[keus - 1]) {
		cout << "Uw budget is niet toereikend voor dit kado. Maak een andere keus..";
		system("pause");
		koken(deelnemer, leeftijd, budget, kadolijst);
	}
	else {
		budget -= prijzen[keus - 1];
		kadolijst += kookitems[keus - 1] + "; ";
	}
}

void lijstDeelnemers(string& deelnemer, int& leeftijd, float& budget,
	string& kadolijst) {
	system("cls");
	cout << "De lijst van deelnemers: " << endl << endl;

	string deelnemers;
	ifstream leesBestand("kadolijst.txt");
	while (getline(leesBestand, deelnemers)) {
		cout << deelnemers << endl;
	}
	cout << endl << endl;
	leesBestand.close();
	system("pause");
	deelname();
}

int main() {
	system("cls");
	deelname();
	system("pause >> null");
}