#include "stdafx.h"
#include "Gui.h"

#include <iostream>
#include <deque>
#include "Verbindung.h"
#include "Station.h"
#include <limits>
#include <algorithm>
#include <iomanip>
#include <ctime>

//-----------------------------------------------------------------------------

void Gui::showUserMenu()
{
	std::cout
		<< "\nWelche Aktion soll ausgefuehrt werden: \n"
		<< "1 - Schnellsten Weg finden\n"
		<< "2 - Node anpassen\n"
		<< "3 - Programm verlassen\n"
		<< std::endl;
}


//-----------------------------------------------------------------------------

int Gui::getUserChoice(int min, int max)
{
	int user_input = 0;

	do {

		std::cout << "Eingabe: ";
		std::cin >> user_input;

		if (user_input < min || user_input > max) {
			std::cout << "Falsche eingabe!" << std::endl;
		}

	} while (user_input < min || user_input > max);

	return user_input;
}


//-----------------------------------------------------------------------------

Node* Gui::getNodeChoice()
{
	std::string nodeId;

	Node* node = NULL;

	do {
		std::cout << "Bitte eine Station angeben: ";
		std::cin >> nodeId;

		node = m_rNetz.findNode(nodeId);

		if (node == NULL) {
			std::cout << "Station nicht gefunden!" << std::endl;
		}

	} while (node == NULL);

	return node;
}


//-----------------------------------------------------------------------------

void Gui::fahrzeitAusgeben()
{
	std::cout << "Start - " << std::endl;
	Node* pSrcNode = getNodeChoice();
	std::cout << "Ziel - " << std::endl;
	Node* pDstNode = getNodeChoice();

	Station* pMeshNode = dynamic_cast<Station*>(pSrcNode);

	double abfahrtzeit;

	abfahrtzeit = getDeciFromTime();	//Abfahrtzeit. Eingabe wird in Decimal umgerechnet


										//----------------------
										//Zeit die vergeht zwichen der gewuenchten Abfahrtzeit und der Abfahrt des Zuges
	double x = abfahrtzeit;
	while (x >= 10) { x -= 10; }
	double fahrzeit = pMeshNode->getFahrzeit();
	if (x > fahrzeit) { fahrzeit += 10; }
	double delay = fahrzeit - x;
	//-------------------
	double time = abfahrtzeit;

	std::cout << "\n---------------------------------------" << std::endl;

	std::deque<Edge*> path1, path2;
	m_rNetz.findShortestPathDijkstra(path1, *pSrcNode, *pDstNode);		//kuerzeste Weg wird berechnet
	for (Edge* pPathEdge : path1) {
		Verbindung* pVerb = dynamic_cast<Verbindung*>(pPathEdge);
		std::cout << pVerb->toString() << std::endl;				//Ausgabe des kuerzesten Wegs
		time += pVerb->getFahrzeit();	//Fahrzeit
	}

	std::cout << std::endl;
	time += delay;
	getTimefromDeci(time);
	std::cout << "---------------------------------------" << std::endl;
}


//-----------------------------------------------------------------------------

void Gui::changeFahrzeit()
{
	Node* pNode = getNodeChoice();
	Station* pMeshNode = dynamic_cast<Station*>(pNode);

	double fahrzeit;
	std::cout << "Neuer Wert fuer Fahrtzeit1: ";
	std::cin >> fahrzeit;
	pMeshNode->setFahrzeit(fahrzeit);

}


double Gui::getDeciFromTime()			//Die Eingabe wird einfachshalber in Decimal umgerechnet.
{
	struct std::tm abFahrtzeit;
	do
	{
		std::cout << "Bitte Abfahrtzeit Eingeben (hh:mm): ";
		std::cin >> std::get_time(&abFahrtzeit, "%R");
		if (std::cin.fail())
		{
			std::cout << "Fehler mit der Eingabe, geben Sie die Abfahrtzeit im richtigen Format an (hh:mm)\n";
		}
	} while (std::cin.fail());
	int hour = abFahrtzeit.tm_hour;
	int minute = abFahrtzeit.tm_min;
	int timeDeci = (60 * hour) + minute;

	return timeDeci;
}

void Gui::getTimefromDeci(double timeDeci)	//Zeit wird fuer die Augabe zurueck in (hh:mm) Format umgewandelt
{
	int hour = 0;
	int minute;
	while (timeDeci >= 60)
	{
		timeDeci -= 60;
		hour++;
	}
	if (hour >= 24) { hour -= 24; }		//24std Format
	minute = timeDeci;
	if (minute < 10)
	{
		std::cout << "Ankunftzeit: " << hour << ":0" << minute << std::endl;
	}
	else
	{
		std::cout << "Ankunftzeit: " << hour << ":" << minute << std::endl;
	}
}

//-----------------------------------------------------------------------------
