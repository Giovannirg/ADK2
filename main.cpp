//Projektarbeit von Gio Rodríguez s0556233 und Leonard Berresheim s0556126

#include "stdafx.h"
#include <C:\Users\Leonard\Desktop\ADK\Klausuren\klausur1\probeklausur1\Klausur1.2\Klausur1.2\Graph.h>

#include "UbahnNetz.h"
#include "Station.h"
#include "Gui.h"

int main()
{
	UbahnNetz netz;

	Gui gui(netz);

	int choice = 0;

	do {

		gui.showUserMenu();
		choice = gui.getUserChoice(1, 3);

		switch (choice) {
		case 1:
			gui.fahrzeitAusgeben();
			break;

		case 2:
			gui.changeFahrzeit();
			break;
		}


	} while (choice != 3);

	return 0;
}


