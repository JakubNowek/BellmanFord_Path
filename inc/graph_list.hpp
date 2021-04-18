#ifndef graph_list_hpp
#define graph_list_hpp
#include "graph.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

/**
 * @brief struktura, opisuj¹ca wêze³ ³¹cz¹cy dwa wierzcho³ki
*/
struct listNode   
{
    int vertexSource;       //wierzcho³ek pocz¹tkowy
    int vertexDestination;  //wierzcho³ek koñcowy
    int weightNode;         //waga wêz³a
    listNode* nextNode;     //wskaŸnik na nastêpny wêze³ 
};

/**
 * @brief struktura modeluj¹ca poêcie grafu w postaci listy s¹siedztwa
*/
class GraphList:public Graph
{
    listNode **adjacencyList;

    public:
    GraphList(int vertices,double density):Graph(vertices,density) //konstruktor inicjuj¹cy listê, gdy obliczamy iloœæ krawêdzi z gêstoœci
    {
        //tworzenie tablicy listy sasiedztwa
        this->adjacencyList = new listNode* [vertices];

        //wype³nianie tablicy pustymi miejscami
        for(int i = 0; i < vertices; i++)
            this->adjacencyList[i] = NULL;
    }
    GraphList(int vertices,int edges,double density):Graph(vertices,edges,density)
    {
        //tworzenie tablicy listy sasiedztwa
        this->adjacencyList = new listNode* [vertices];

        //wype³nianie tablicy pustymi miejscami
        for(int i = 0; i < vertices; i++)
            this->adjacencyList[i] = NULL;
    }
    GraphList(){}; //konstruktor domyœlny
    ~GraphList(); //destruktor

    void setAdjacencyList(int vertices)
    {
        //tworzenie tablicy listy sasiedztwa
        this->adjacencyList = new listNode* [vertices];

        //wype³nianie tablicy pustymi miejscami
        for(int i = 0; i < vertices; i++)
            this->adjacencyList[i] = NULL;
    }
    struct listNode* getListNode(int index){return this->adjacencyList[index];} //metoda zwracaj¹ca element listy o danym indeksie
    struct listNode* createNode(int vertexSource, int vertexDestination, int weight); // metoda s³u¿¹ca tworzeniu wêz³ów
    void addEdge(int vertexSource, int vertexDestination, int weight);
    void fillGraph(); // metoda wype³niaj¹ca graf
	void printfGraph(); // metoda wypisuj¹ca zawartoœæ grafu
    void cleanMemory(); // metoda opró¿niaj¹ca graf
};

#endif