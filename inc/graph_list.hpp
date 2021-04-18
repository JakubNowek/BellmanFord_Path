#ifndef graph_list_hpp
#define graph_list_hpp
#include "graph.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

/**
 * @brief struktura, opisuj�ca w�ze� ��cz�cy dwa wierzcho�ki
*/
struct listNode   
{
    int vertexSource;       //wierzcho�ek pocz�tkowy
    int vertexDestination;  //wierzcho�ek ko�cowy
    int weightNode;         //waga w�z�a
    listNode* nextNode;     //wska�nik na nast�pny w�ze� 
};

/**
 * @brief struktura modeluj�ca po�cie grafu w postaci listy s�siedztwa
*/
class GraphList:public Graph
{
    listNode **adjacencyList;

    public:
    GraphList(int vertices,double density):Graph(vertices,density) //konstruktor inicjuj�cy list�, gdy obliczamy ilo�� kraw�dzi z g�sto�ci
    {
        //tworzenie tablicy listy sasiedztwa
        this->adjacencyList = new listNode* [vertices];

        //wype�nianie tablicy pustymi miejscami
        for(int i = 0; i < vertices; i++)
            this->adjacencyList[i] = NULL;
    }
    GraphList(int vertices,int edges,double density):Graph(vertices,edges,density)
    {
        //tworzenie tablicy listy sasiedztwa
        this->adjacencyList = new listNode* [vertices];

        //wype�nianie tablicy pustymi miejscami
        for(int i = 0; i < vertices; i++)
            this->adjacencyList[i] = NULL;
    }
    GraphList(){}; //konstruktor domy�lny
    ~GraphList(); //destruktor

    void setAdjacencyList(int vertices)
    {
        //tworzenie tablicy listy sasiedztwa
        this->adjacencyList = new listNode* [vertices];

        //wype�nianie tablicy pustymi miejscami
        for(int i = 0; i < vertices; i++)
            this->adjacencyList[i] = NULL;
    }
    struct listNode* getListNode(int index){return this->adjacencyList[index];} //metoda zwracaj�ca element listy o danym indeksie
    struct listNode* createNode(int vertexSource, int vertexDestination, int weight); // metoda s�u��ca tworzeniu w�z��w
    void addEdge(int vertexSource, int vertexDestination, int weight);
    void fillGraph(); // metoda wype�niaj�ca graf
	void printfGraph(); // metoda wypisuj�ca zawarto�� grafu
    void cleanMemory(); // metoda opr�niaj�ca graf
};

#endif