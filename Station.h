#pragma once
#include "stdafx.h"
#include "Node.h"

class Station : public Node
{
public:

	Station(std::string id, double fahrzeit)
		: Node(id), m_fahrzeit(fahrzeit) {}

	double getFahrzeit() { return m_fahrzeit; }

	void setFahrzeit(double fahrzeit) { m_fahrzeit = fahrzeit; }

private:

	double m_fahrzeit;

};
