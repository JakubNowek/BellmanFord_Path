#include "graph_matrix.hpp"

GraphMatrix::~GraphMatrix()
{
    //usuwamy kolumny
    for(int i = 0; i < this->verticesGraph; i++)
        delete [] this->adjacencyMatrix[i];

    //usuwamy cala tablice 
    delete[] this->adjacencyMatrix;    
}

void GraphMatrix::addEdge(int vertexSource,int vertexDestination,int weight)
{
    this->adjacencyMatrix[vertexSource][vertexDestination].push(weight);
    //jesli mamy graf nieskierowany to:
    this->adjacencyMatrix[vertexDestination][vertexSource].push(weight);
}

void GraphMatrix::removeEdge(int vertexSource, int vertexDestination)
{
    //jesli krawedz nie istnieje
    if(this->adjacencyMatrix[vertexSource][vertexDestination].size() == 0)
        return;

    this->adjacencyMatrix[vertexSource][vertexDestination].pop();
    //jesli mamy graf nieskierowany
    this->adjacencyMatrix[vertexDestination][vertexSource].pop();    
}

int GraphMatrix::getSizeMatrix(int i, int j)
{
    return this->adjacencyMatrix[i][j].size();
}

int GraphMatrix::getWeightMatrix(int i, int j, int k)
{
    return this->adjacencyMatrix[i][j].getData(k);
}

void GraphMatrix::fillGraph()
{
    srand(time(NULL));
    int vertexSource;
    int vertexDestination;
    int weight;
    for(int i = 0; i < this->edgesGraph; i++)
    {
        //usuwamy przypadek jesli wylosowalby te same wierzcholki zeby nie bylo petli w grafie
        do{
            vertexSource = rand() % this->verticesGraph;
            vertexDestination = rand() % this->verticesGraph;
        }while(vertexSource == vertexDestination);
        int weight = rand() % 1000;
        addEdge(vertexSource,vertexDestination,weight);  
    }
}

void GraphMatrix::printfGraph()
{
    for(int i = 0; i < this->verticesGraph; i++)
    {
        for(int j = 0; j < this->verticesGraph; j++)
        {
            std::cout << "Dla wierzcholka od " << i << " " << j << " wagi wynosza: ";
            this->adjacencyMatrix[i][j].print();
        }
        std:: cout << std::endl;    
    }
}


///*funkcja eksperymentalna ktora bedzie wyswietlac wylosowany graf w takiej formie w jakiej umiemy wczytywac graf*/
//void GraphMatrix::printfGraph()
//{
//    std::cout << "Dla grafu ilosc krawedzi wynosi: "<< this->edgesGraph; //x1
//
//    std::cout << "Dla grafu  ilosc wierzcholkow wynosi: "<< this->verticesGraph;//x1
//
//    std::cout << "Dla grafu  wierzcholek startowy to: " << 1 << std::endl;//x1
//
//
//    for (int i = 0; i < this->verticesGraph; i++)
//    {
//        for (int j = 0; j < this->verticesGraph; j++)
//        {
//
//            std::cout << "Dla grafu: wierzcholek poczatkowy: "<<i;
//
//            std::cout << " wierzcholek koncowy: "<<j;
//
//            std::cout << " waga wynosi: ";
//            this->adjacencyMatrix[i][j].print();
//        }
//        std::cout << std::endl;
//    }
//}