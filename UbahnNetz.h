#pragma once

#include <C:\Users\Leonard\Desktop\ADK\Klausuren\klausur1\probeklausur1\Klausur1.2\Klausur1.2\Graph.h>
#include "stdafx.h"

class UbahnNetz : public Graph
{
public:

	UbahnNetz();

	void erstellenVerbindung(Node& rSrc, Node& rDst, double fahrzeit);
};


