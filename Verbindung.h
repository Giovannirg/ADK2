#pragma once
#include "stdafx.h"
#include <C:\Users\Leonard\Desktop\ADK\Klausuren\klausur1\probeklausur1\Klausur1.2\Klausur1.2\Edge.h>
#include <C:\Users\Leonard\Desktop\ADK\Klausuren\klausur1\probeklausur1\Klausur1.2\Klausur1.2\Node.h>

class Verbindung : public Edge
{
public:

	Verbindung(Node& rSrc, Node& rDst, double fahrzeit) :
		Edge(rSrc, rDst), m_fahrzeit(fahrzeit) {}

	double getFahrzeit();

private:

	double m_fahrzeit;

};