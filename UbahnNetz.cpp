#include "stdafx.h"
#include "UbahnNetz.h"

#include "Station.h"
#include "Verbindung.h"

UbahnNetz::UbahnNetz()
{
	//U1, U4, U7, U8
	Node& r1 = addNode(new Station("Nollendorfplatz", 7));
	Node& r2 = addNode(new Station("Viktoria-Luise-Platz", 9));
	Node& r3 = addNode(new Station("Bayerischer-Platz", 10));
	Node& r4 = addNode(new Station("Rathaus-Schoeneberg", 2));
	Node& r5 = addNode(new Station("Innsbrucker-Platz", 3));
	Node& r6 = addNode(new Station("Hermannstr.", 2));
	Node& r7 = addNode(new Station("Leinestr.", 3));
	Node& r8 = addNode(new Station("Boddinstr.", 5));
	Node& r9 = addNode(new Station("Hermannplatz", 6));
	Node& r10 = addNode(new Station("Schoenleinstr.", 8));
	Node& r11 = addNode(new Station("Kottbusser-Tor", 10));
	Node& r12 = addNode(new Station("Moritzplatz", 2));
	Node& r13 = addNode(new Station("Heinrich-Heine-Str.", 3));
	Node& r14 = addNode(new Station("Jannowitzbruecke", 5));
	Node& r15 = addNode(new Station("Alexanderplatz", 6));
	Node& r16 = addNode(new Station("Weinmeisterstr.", 8));
	Node& r17 = addNode(new Station("RosenthalerPlatz", 0));
	Node& r18 = addNode(new Station("Bernauer-Str.", 1));
	Node& r19 = addNode(new Station("Voltstr.", 3));
	Node& r20 = addNode(new Station("Gesundbrunnen", 4));
	Node& r21 = addNode(new Station("Pankstr.", 6));
	Node& r22 = addNode(new Station("Osloer-Str.", 7));
	Node& r23 = addNode(new Station("Franz-Neumann-Platz", 9));
	Node& r24 = addNode(new Station("Residenzstr.", 1));
	Node& r25 = addNode(new Station("Paracelsus-Bad", 2));
	Node& r26 = addNode(new Station("Lindauer-Allee", 3));
	Node& r27 = addNode(new Station("Karl-Bonhoeffer", 5));
	Node& r28 = addNode(new Station("Rathaus-Reinickendorf", 7));
	Node& r29 = addNode(new Station("Wittenau", 8));
	Node& r30 = addNode(new Station("Warschauer-Str.", 7));
	Node& r31 = addNode(new Station("Schlesisches-Tor", 9));
	Node& r32 = addNode(new Station("Goerlitzer-Bahnhof", 10));
	Node& r33 = addNode(new Station("Prinzenstr.", 3));
	Node& r34 = addNode(new Station("Hallesches-Tor", 5));
	Node& r35 = addNode(new Station("Moeckernbruecke", 7));
	Node& r36 = addNode(new Station("Gleisdreieck", 8));
	Node& r37 = addNode(new Station("Kurfürstenstr.", 10));
	Node& r38 = addNode(new Station("Wittenbergplatz", 4));
	Node& r39 = addNode(new Station("Kurfuerstendamm", 6));
	Node& r40 = addNode(new Station("Uhlandstr.", 7));
	Node& r41 = addNode(new Station("Rudow", 1));
	Node& r42 = addNode(new Station("Neukoelln", 3));
	Node& r43 = addNode(new Station("Mehringdamm", 5));
	Node& r44 = addNode(new Station("Yorkstr.", 4));
	Node& r45 = addNode(new Station("Kleistpark", 10));
	Node& r46 = addNode(new Station("Berlinerstr.", 2));
	Node& r47 = addNode(new Station("Rathaus-Spandau", 5));

	erstellenVerbindung(r1, r2, 2);
	erstellenVerbindung(r2, r3, 1);
	erstellenVerbindung(r3, r4, 2);
	erstellenVerbindung(r4, r5, 1);
	erstellenVerbindung(r6, r7, 1);
	erstellenVerbindung(r7, r8, 2);
	erstellenVerbindung(r8, r9, 1);
	erstellenVerbindung(r9, r10, 2);
	erstellenVerbindung(r10, r11, 2);
	erstellenVerbindung(r11, r12, 2);
	erstellenVerbindung(r12, r13, 1);
	erstellenVerbindung(r13, r14, 2);
	erstellenVerbindung(r14, r15, 1);
	erstellenVerbindung(r15, r16, 2);
	erstellenVerbindung(r16, r17, 2);
	erstellenVerbindung(r17, r18, 1);
	erstellenVerbindung(r18, r19, 2);
	erstellenVerbindung(r19, r20, 1);
	erstellenVerbindung(r20, r21, 2);
	erstellenVerbindung(r21, r22, 1);
	erstellenVerbindung(r22, r23, 2);
	erstellenVerbindung(r23, r24, 2);
	erstellenVerbindung(r24, r25, 1);
	erstellenVerbindung(r25, r26, 1);
	erstellenVerbindung(r26, r27, 2);
	erstellenVerbindung(r27, r28, 2);
	erstellenVerbindung(r28, r29, 1);
	erstellenVerbindung(r30, r31, 2);
	erstellenVerbindung(r31, r32, 1);
	erstellenVerbindung(r32, r11, 2);
	erstellenVerbindung(r11, r33, 1);
	erstellenVerbindung(r33, r34, 2);
	erstellenVerbindung(r34, r35, 2);
	erstellenVerbindung(r35, r36, 1);
	erstellenVerbindung(r36, r37, 2);
	erstellenVerbindung(r37, r1, 2);
	erstellenVerbindung(r1, r38, 2);
	erstellenVerbindung(r38, r39, 2);
	erstellenVerbindung(r39, r40, 1);
	erstellenVerbindung(r41, r42, 2);
	erstellenVerbindung(r42, r9, 1);
	erstellenVerbindung(r9, r43, 3);
	erstellenVerbindung(r43, r35, 2);
	erstellenVerbindung(r35, r44, 2);
	erstellenVerbindung(r44, r45, 1);
	erstellenVerbindung(r45, r3, 1);
	erstellenVerbindung(r3, r46, 2);
	erstellenVerbindung(r46, r47, 1);



}

void UbahnNetz::erstellenVerbindung(Node& rSrc, Node& rDst, double fahrzeit)
{
	addEdge(new Verbindung(rSrc, rDst, fahrzeit));
	addEdge(new Verbindung(rDst, rSrc, fahrzeit));
}
