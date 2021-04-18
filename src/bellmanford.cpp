#include "bellmanford.hpp"

void SaveArrayFile(int distanceArray[],int preArray[], int size, int vertexSource)
{
    std::fstream file; //zmienna do ktorej bedziemy zapisywac do pliku
    //otwieramy plik
    file.open("droga.txt", std::ios::out|std::ios::trunc); //było std::ios::app zamiast trunc
    file << "Dla wierzcholka startowego: " << vertexSource << std::endl;
	for(int i = 0; i < size; i++)
    {
		file <<"Do wierzcholka: " << i << " koszt wynosi $ " << distanceArray[i] << " " << std::endl;
	}
	file << std::endl;

    // Tworzymy prosty stos
    int* arrayOfVertices = new int[size];
    int ptr = 0;

    for (int i = 0; i < size; i++)
    {
        file << "Dla wierzcholka (do wierzcholka) " <<i << " : najktrotsza droga prowadzi przez wierzcholki: ";
        // Wierzchołki ścieżki umieszczamy na stosie
        for(int x = i; x !=-1 ; x = preArray[x])
            arrayOfVertices[ptr++] = x; // w kolejności od ostatniego do pierwszego

        while(ptr) // Wierzchołki ze stosu drukujemy
        {
            file << arrayOfVertices[--ptr] << " "; // w kolejności od pierwszego do ostatniego
        }
        file << std::endl;
    }
    file.close(); // zamykanie pliku

    delete[] arrayOfVertices; //usunięcie pomocniczego stosu

}

//algorytm bellmana forda służący do przeszukiwania 100 list sasiedztwa
void bellmanfordList(GraphList &graph, int vertexSource)
{
    listNode* tmpNode;                  //węzeł pomocniczy
    int totalVertices = graph.getV();   //liczba wierzchołków grafu
    int totalEdges = graph.getE();      //liczba krawędzi grafu

    //tablica przechowuje odległość od wierzchołka startowego do pozostałych wierzchołków
    int *distanceArray = new int[totalVertices];

    //tablica zapisujaca poprzedni uklad
    int *preArray = new int[totalVertices];

    //wypelnianie tablicy wg algorytmu Bellmana-Forda
    //wszystkim wierzchołkom przypissujemy wartość "nieskończoność" i zerujemy tablicę pomocniczą 
    for (int i = 0; i < totalVertices; i++)
    {
        distanceArray[i] = INFINITY;
        preArray[i] = 0;
    }

    //wyznaczamy startowy wierzchołek
    distanceArray[vertexSource] = 0;

    //relaksacja krawedzi
    for(int i = 1; i <= totalVertices - 1; i++) // petla relaksacji
        for(int j = 0; j < totalVertices; j++) //przechodzenie kolejno po wierzchołkach
            for(tmpNode = graph.getListNode(j); tmpNode; tmpNode=tmpNode->nextNode)
            {
        	    if((distanceArray[tmpNode->vertexSource] != INFINITY) && (distanceArray[tmpNode->vertexDestination] > distanceArray[tmpNode->vertexSource] + tmpNode->weightNode))
        	    {
				    distanceArray[tmpNode->vertexDestination] = distanceArray[tmpNode->vertexSource] + tmpNode->weightNode;
				    preArray[tmpNode->vertexDestination] = tmpNode->vertexSource;
			    }
            }
		
    // Wykrywanie cyklu ujemnego - nie można znaleźć najktótszych dróg
   for(int i = 0; i < totalVertices; i++)
        for(tmpNode = graph.getListNode(i); tmpNode; tmpNode=tmpNode->nextNode)
        {
		    if((distanceArray[tmpNode->vertexSource] != INFINITY) && (distanceArray[tmpNode->vertexDestination] > distanceArray[tmpNode->vertexSource] + tmpNode->weightNode))
            {
			    std::cout << "Negatywny cykl zostal wykryty!" << std::endl;
			    return;
		    }
	    }

    // usunięcie tablic pomocniczych
    delete [] distanceArray;
    delete [] preArray;

}

//funkcja działająca identycznie, jak bellmanfordList, zapisująca wyniki działania algorytmu do pliku
void bellmanfordListFile(GraphList &graph, int vertexSource)
{   

    listNode* tmpNode;                  //węzeł pomocniczy
    int totalVertices = graph.getV();   //liczba wierzchołków grafu
    int totalEdges = graph.getE();      //liczba krawędzi grafu

    //tablica przechowuje odległość od wierzchołka startowego do pozostałych wierzchołków
    int* distanceArray = new int[totalVertices];

    //tablica zapisujaca poprzedni uklad
    int* preArray = new int[totalVertices];

    //wypelnianie tablicy wg algorytmu Bellmana-Forda
    //wszystkim wierzchołkom przypissujemy wartość "nieskończoność" i zerujemy tablicę pomocniczą 
    for (int i = 0; i < totalVertices; i++)
    {
        distanceArray[i] = INFINITY;
        preArray[i] = -1;
    }

    //wyznaczamy startowy wierzchołek
    distanceArray[vertexSource] = 0;

    //relaksacja krawedzi
    for(int i = 1; i <= totalVertices - 1; i++) // petla relaksacji
        for(int j = 0; j < totalVertices; j++) //przechodzenie kolejno po wierzchołkach
            for(tmpNode = graph.getListNode(j); tmpNode; tmpNode=tmpNode->nextNode)
            {
        	    if((distanceArray[tmpNode->vertexSource] != INFINITY) && (distanceArray[tmpNode->vertexDestination] > distanceArray[tmpNode->vertexSource] + tmpNode->weightNode))
        	    {
				    distanceArray[tmpNode->vertexDestination] = distanceArray[tmpNode->vertexSource] + tmpNode->weightNode;
				    preArray[tmpNode->vertexDestination] = tmpNode->vertexSource;
			    }
            }
		   
    // Wykrywanie cyklu ujemnego - nie można znaleźć najktótszych dróg
   for(int i = 0; i < totalVertices; i++)
        for(tmpNode = graph.getListNode(i); tmpNode; tmpNode=tmpNode->nextNode)
        {
		    if((distanceArray[tmpNode->vertexSource] != INFINITY) && (distanceArray[tmpNode->vertexDestination] > distanceArray[tmpNode->vertexSource] + tmpNode->weightNode))
            {
			    std::cout << "Negatywny cykl zostal wykryty!" << std::endl;
			    return;
		    }
	    }

    //zapisanie tablicy do pliku
	SaveArrayFile(distanceArray,preArray, totalVertices, vertexSource);

    // usunięcie tablic pomocniczych
    delete [] distanceArray;
    delete [] preArray;

}

//algorytm bellmana forda służący do przeszukiwania 100 macierzy sasiedztwa
void bellmanfordMatrix(GraphMatrix &graph, int vertexSource)
{

    int totalVertices = graph.getV();   //liczba wierzchołków grafu
    int totalEdges = graph.getE();      //liczba krawędzi grafu

    //tablica przechowuje odległość od wierzchołka startowego do pozostałych wierzchołków
    int* distanceArray = new int[totalVertices];

    //tablica zapisujaca poprzedni uklad
    int* preArray = new int[totalVertices];

    //wypelnianie tablicy wg algorytmu Bellmana-Forda
    //wszystkim wierzchołkom przypissujemy wartość "nieskończoność" i zerujemy tablicę pomocniczą 
    for (int i = 0; i < totalVertices; i++)
    {
        distanceArray[i] = INFINITY;
        preArray[i] = 0;
    }

    //wyznaczamy startowy wierzchołek
    distanceArray[vertexSource] = 0; 

    //relaksacja krawedzi
    for(int h = 1; h <=totalVertices-1; h++)
        for(int i = 0; i < totalVertices; i++)
            for(int j = 0; j < totalVertices; j++)
                for(int k = 0; k < graph.getSizeMatrix(i,j); k++)
                {
                    if (distanceArray[i] != INFINITY && distanceArray[j] > distanceArray[i] + graph.getWeightMatrix(i,j,k))
                    {
                        distanceArray[j] = distanceArray[i] + graph.getWeightMatrix(i,j,k);
                        preArray[j] = i;
                    }
                }

    // Wykrywanie cyklu ujemnego - nie można znaleźć najktótszych dróg
   for(int i = 0; i < totalVertices; i++)
        for(int j = 0; j < totalVertices; j++)
            for(int k = 0; k < graph.getSizeMatrix(i,j); k++)
            {
		        if((distanceArray[i] != INFINITY) && (distanceArray[j] > distanceArray[i] + graph.getWeightMatrix(i,j,k)))
                {
			        std::cout << "Negatywny cykl zostal wykryty do wierzolka docelowego: " << j << std::endl;
			        return;
		        }
	        }

    // usunięcie tablic pomocniczych
    delete [] distanceArray;
    delete [] preArray;  

}

//funkcja działająca identycznie, jak bellmanfordMatrix, zapisująca wyniki działania algorytmu do pliku
void bellmanfordMatrixFile(GraphMatrix &graph, int vertexSource)
{
    int totalVertices = graph.getV();   //liczba wierzchołków grafu
    int totalEdges = graph.getE();      //liczba krawędzi grafu

    //tablica przechowuje odległość od wierzchołka startowego do pozostałych wierzchołków
    int* distanceArray = new int[totalVertices];

    //tablica zapisujaca poprzedni uklad
    int* preArray = new int[totalVertices];

    //wypelnianie tablicy wg algorytmu Bellmana-Forda
    //wszystkim wierzchołkom przypissujemy wartość "nieskończoność" i zerujemy tablicę pomocniczą 
    for (int i = 0; i < totalVertices; i++)
    {
        distanceArray[i] = INFINITY;
        preArray[i] = -1;
    }

    //wyznaczamy startowy wierzchołek
    distanceArray[vertexSource] = 0; 

    //relaksacja krawedzi
    for(int h = 1; h <=totalVertices-1; h++)
        for(int i = 0; i < totalVertices; i++)
            for(int j = 0; j < totalVertices; j++)
                for(int k = 0; k < graph.getSizeMatrix(i,j); k++)
                {
                    if (distanceArray[i] != INFINITY && distanceArray[j] > distanceArray[i] + graph.getWeightMatrix(i,j,k))
                    {
                        distanceArray[j] = distanceArray[i] + graph.getWeightMatrix(i,j,k);
                        preArray[j] = i;
                    }
                }

    // Wykrywanie cyklu ujemnego - nie można znaleźć najktótszych dróg
   for(int i = 0; i < totalVertices; i++)
        for(int j = 0; j < totalVertices; j++)
            for(int k = 0; k < graph.getSizeMatrix(i,j); k++)
            {
		        if((distanceArray[i] != INFINITY) && (distanceArray[j] > distanceArray[i] + graph.getWeightMatrix(i,j,k)))
                {
			        std::cout << "Negatywny cykl zostal wykryty do wierzolka docelowego: " << j << std::endl;
			        return;
		        }
	        }

    //zapisanie tablicy do pliku
	SaveArrayFile(distanceArray,preArray, totalVertices, vertexSource);

    // usunięcie tablic pomocniczych
    delete [] distanceArray;
    delete [] preArray;      

}