#ifndef graph_hpp
#define graph_hpp
#include <cstdlib>

//abstakcyjna klasa graf

/**
 * @brief klasa modeluj�ca poj�cie grafu
 * 
 * klasa ma charakter wirtualny, poniewa� nie jest bezpo�rednio u�ywana,
 * tylko dziedzicz� z niej inne klasy, kt�re s� dalej rozwijane
*/
class Graph
{
    protected:
    int verticesGraph; // liczba wierzcholkow grafu
    int edgesGraph; //liczba krawedzi grafu
    double densityGraph; //gestosc grafu

    public:
    int getV() { return verticesGraph;} // metoda pozwalaj�ca pozyska� liczb� wierzcho�k�w
    int getE() { return edgesGraph;} // metoda pozwalaj�ca pozyska� liczb� kraw�dzi
    double getDensity() {return densityGraph;} // metoda pozwalaj�ca pozyska� g�sto�� grafu
    void setVertices(int vertices){ this->verticesGraph = vertices;}
    void setEdges(int vertices,double density){ this->edgesGraph = (density*(vertices-1)*vertices)/2;}
    void setDensity(double density){this->densityGraph = density;}
    Graph(){}; // konstruktor domy�lny
    virtual ~Graph(){}; //destruktor
    Graph(int vertices,double density) // konstruktor grafu 
    {
        this->verticesGraph = vertices;
        this->densityGraph = density;
        this->edgesGraph = (density*(vertices-1)*vertices)/2; 
    }
    Graph(int vertices,int edges,double density) //przeci��enie konstruktora grafu, gdy odane zostaj� kraw�dzie
    {
        this->verticesGraph = vertices;
        this->densityGraph = density;
        this->edgesGraph = edges; 
    }
    virtual void fillGraph() = 0; 
    virtual void printfGraph() = 0;
};

#endif