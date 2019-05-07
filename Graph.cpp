#include "stdafx.h"
#include "Graph.h"
#include <list>
#include <fstream>
#include <algorithm>
#include <limits>
#include <map>

//---------------------------------------------------------------------------------------------------------------------

Node* Graph::findNode(const std::string& id)
{
	// - soll einen Node mit der gegebenen id in m_nodes suchen
	for (std::list<Node*>::iterator it = m_nodes.begin(); it != m_nodes.end(); it++) {

		// - gibt den Pointer auf den Node zurück, wenn er gefunden wurde.
		if ((*it)->getID() == id) {
			return *it;
		}
	}

	// - gibt NULL zurück, falls kein Node mit der id gefunden wurde.
	return NULL;

	// TEST:
	// Testen Sie die Funktion, indem Sie indem Sie einen Graph mit ein paar Nodes und Edges in main.cpp erstellen
	// und anschließend ein paar Nodes im Graph suchen.
	// Prüfen Sie, ob der Node gefunden wurden und geben Sie die ID auf der Kommandozeile aus!
}


//---------------------------------------------------------------------------------------------------------------------

Node& Graph::addNode(Node* pNewNode)
{
	// Überprüfen Sie, ob schon ein Node mit der gegeben id im Graph vorhanden ist!
	if (findNode(pNewNode->getID()) != NULL) {
		throw "Node mit gleicher ID schon vorhanden!";
	}

	m_nodes.push_back(pNewNode);
	return *pNewNode;

	// Falls ja:
	//  - Exception werfen
	// Falls nein:
	//  - den neuen Node 'pNewNode' in m_nodes einfügen
	//  - Referenz auf den neuen Node zurück geben

	// TEST:
	// Testen Sie die Funktion, indem Sie indem Sie einen Graph mit ein paar Nodes in main.cpp erstellen
	// Testen Sie mit der Funktion 'findNode', ob die hinzugefügten Nodes im Graph vorhanden sind.
}


//---------------------------------------------------------------------------------------------------------------------

Edge& Graph::addEdge(Edge* pNewEdge)
{

	// - die neue Edge 'pNewEdge' in m_edges einfügen
	m_edges.push_back(pNewEdge);
	// - Referenz auf die neue Edge zurück geben

	// - Testen Sie ob der Source- und Destination-Node von 'pNewEdge' schon im Graph vorhanden ist.
	std::list<Node*>::iterator itSrc = std::find(
		m_nodes.begin(), m_nodes.end(), &pNewEdge->getSrcNode());
	if (itSrc == m_nodes.end()) {
		addNode(&pNewEdge->getSrcNode());
	}

	std::list<Node*>::iterator itDst = std::find(
		m_nodes.begin(), m_nodes.end(), &pNewEdge->getDstNode());
	if (itDst == m_nodes.end()) {
		addNode(&pNewEdge->getDstNode());
	}

	// -> fügen Sie diese Nodes hinzu, falls nicht (nutzen Sie dafür Graph::addNode)

	return *pNewEdge;

	// TEST:
	// Testen Sie die Funktion, indem Sie indem Sie einen Graph mit ein paar Nodes und Edges in main.cpp erstellen
	// Testen Sie mit der Funktion 'findEdges', ob die hinzugefügten Edges im Graph vorhanden sind.
}


//---------------------------------------------------------------------------------------------------------------------

Graph::~Graph()
{
	for (std::list<Edge*>::iterator itEdge = m_edges.begin(); itEdge != m_edges.end(); itEdge++) {
		// Speicher von Edge-Pointer freigeben
		delete *itEdge;
	}

	for (std::list<Node*>::iterator itNode = m_nodes.begin(); itNode != m_nodes.end(); itNode++) {
		delete *itNode;
	}
}


//---------------------------------------------------------------------------------------------------------------------

void Graph::remove(Node& rNode)
{
	// Sicherstellen, dass der gegebene Node Teil des Graphs ist
	std::list<Node*>::iterator itNode = std::find(m_nodes.begin(), m_nodes.end(), &rNode);
	if (itNode == m_nodes.end()) {
		throw "Node ist nicht Teil des Graphs!";
	}

	for (std::list<Edge*>::iterator it = m_edges.begin(); it != m_edges.end(); ) {

		if ((*it)->isConnectedTo(rNode)) {
			it = m_edges.erase(it);
			delete *it;
		}
		else {
			it++;
		}
	}

	m_nodes.erase(itNode);
	delete *itNode;

	// TEST:
	// Testen Sie die Funktion, indem Sie indem Sie einen Graph mit ein paar Nodes und Edges in main.cpp erstellen
	// und anschließend einzelne Nodes wieder löschen.
	// Testen Sie mit der Funktion 'findNode', ob die gelöschten Nodes noch im Graph vorhanden sind.
}


//---------------------------------------------------------------------------------------------------------------------

void Graph::remove(Edge& rEdge)
{
	std::list<Edge*>::iterator it = std::find(m_edges.begin(), m_edges.end(), &rEdge);
	if (it == m_edges.end()) {
		throw "Edge ist nicht Teil des Graphs!";
	}

	m_edges.erase(it);
	delete *it;

	// - der Pointer auf rEdge muss aus m_edges entfernt werden!
	// - der Pointer auf rEdge muss mit 'delete' freigegeben werden!

	// TEST:
	// Testen Sie die Funktion, indem Sie indem Sie einen Graph mit ein paar Nodes und Edges in main.cpp erstellen
	// und anschließend einzelne Edges wieder löschen.
	// Testen Sie mit der Funktion 'findEdges', ob die gelöschten Edges noch im Graph vorhanden sind.
}


//---------------------------------------------------------------------------------------------------------------------

std::vector<Edge*> Graph::findEdges(const Node& rSrc, const Node& rDst)
{
	std::vector<Edge*> ret;

	// - findet alle edges, mit rSrc als Source-Node und rDst als Destination-Node.
	// - füge die Zeiger der Edges in den vector 'ret' ein.

	return ret;

	// TEST:
	// Testen Sie die Funktion, indem Sie indem Sie einen Graph mit ein paar Nodes und Edges in main.cpp erstellen
	// und anschließend ein paar Edges im Graph suchen.
	// Prüfen Sie, ob Edges gefunden wurden und geben Sie die gefunden Edges auf der Kommandozeile aus!
}


//---------------------------------------------------------------------------------------------------------------------


void Graph::saveAsDot(const std::string& rFilename)
{
	/*
	Kopieren Sie den Ordner ‚Peters\C23_Algorithmen_Programmierung\Tools\graphviz‘ im Dozentenserver auf ein lokales Laufwerk.

	Graphiz ist ein Tool, welches Graphen aus einer textuellen Beschreibung erzeugen kann.
	Betrachten Sie die Datei graph.dot.
	Formal ist die Datei folgendermaßen aufgebaut :

	digraph {
	concentrate = true
	<NODE_ID>;
	<NODE_ID>;
	<NODE_ID>;
	<EDGE_1>;
	<EDGE_2>;
	<EDGE_N>;
	}

	Starten Sie die Datei make.bat, damit Graphiz ein Bild des Graphen erstellt.
	Spielen Sie mit der Datei graph.dot herum und lassen Sie sich den Graph dazu generieren.


	Implementieren Sie nun die Funktion 'Graph::saveAsDot', damit sie eine Dot-Datei im angegebenen Dateipfad erzeugt!

	Hilfestellung:
	- Dateien speichern mit C++: http://www.cplusplus.com/reference/fstream/fstream/open/
	- Verwenden Sie die Funktionen Node::getID() und Edge::toString(), um die Einträge für die Nodes und Edges in der dot - Datei zu generieren.


	TEST:
	Testen Sie die Funktion, indem Sie indem Sie einen Graph in mit ein paar Nodes und Edges in main.cpp erstellen
	und anschließend eine dot-Datei generieren. Erstellen Sie ein Bild des Graphen mit Graphviz.

	*/


}


//---------------------------------------------------------------------------------------------------------------------

void Graph::findShortestPathDijkstra(std::deque<Edge*>& rPath, const Node& rSrcNode, const Node& rDstNode)
{

	std::map<Node*, DijkstraEntry> nodeTable;
	std::list<Node*> Q;

	Node* pSrc = findNode(rSrcNode.getID());
	Node* pDst = findNode(rDstNode.getID());

	if (pSrc == NULL || pDst == NULL)
		throw "Node liegt nicht im Graph!";

	/*
	for each vertex v in Graph:             // Initialization
	dist[v] ← INFINITY                  // Unknown distance from source to v
	prev[v] ← UNDEFINED                 // Previous node in optimal path from source
	add v to Q                          // All nodes initially in Q (unvisited nodes)
	*/
	for (Node* pNode : m_nodes) {
		Q.push_back(pNode);
		nodeTable[pNode] = { std::numeric_limits<double>::max(), NULL, NULL };
	}

	// dist[source] ← 0
	nodeTable[pSrc].dist = 0;

	// while Q is not empty:
	while (!Q.empty()) {

		// u ← vertex in Q with min dist[u]
		Node* u = Q.front();
		for (Node* pCurrentNode : Q) {
			if (nodeTable[pCurrentNode].dist < nodeTable[u].dist) {
				u = pCurrentNode;
			}
		}

		// Abbruchkriterium (while-Schleife verlassen)
		if (u == pDst) break;

		// remove u from Q
		Q.remove(u);

		// for each neighbor v of u:
		for (Edge* pOutEdge : u->getOutEdges()) {
			Node* v = &pOutEdge->getDstNode();

			// alt ← dist[u] + length(u, v)
			double newDistance = nodeTable[u].dist + pOutEdge->getWeight();

			DijkstraEntry& vEntry = nodeTable[v];
			// if alt < dist[v]:
			if (newDistance < vEntry.dist) {
				// dist[v] ← alt
				// prev[v] ← u
				vEntry.dist = newDistance;
				vEntry.prevNode = u;
				vEntry.prevEdge = pOutEdge;
			}
		}
	}

	// Pfad von hinten nach vorne aus der Tabelle rekonstruieren
	for (Node* pCurrentNode = pDst;
		nodeTable[pCurrentNode].prevEdge != NULL;
		pCurrentNode = nodeTable[pCurrentNode].prevNode) {

		rPath.push_front(nodeTable[pCurrentNode].prevEdge);
	}
}


//---------------------------------------------------------------------------------------------------------------------

