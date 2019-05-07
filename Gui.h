#pragma once
#include "stdafx.h"
#include "UbahnNetz.h"

class Gui
{

public:

	Gui(UbahnNetz& rNetwork) : m_rNetz(rNetwork) {}

	void showUserMenu();

	int getUserChoice(int min, int max);

	void fahrzeitAusgeben();

	void changeFahrzeit();

	double getDeciFromTime();

	void getTimefromDeci(double timeDeci);

private:

	Node* getNodeChoice();

	UbahnNetz& m_rNetz;

};
