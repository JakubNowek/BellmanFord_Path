#ifndef graph_hpp
#define graph_hpp
#include <cstdlib>

//abstakcyjna klasa graf

/**
 * @brief klasa modeluj¹ca pojêcie grafu
 * 
 * klasa ma charakter wirtualny, poniewa¿ nie jest bezpoœrednio u¿ywana,
 * tylko dziedzicz¹ z niej inne klasy, które s¹ dalej rozwijane
*/
class Graph
{
    protected:
    int verticesGraph; // liczba wierzcholkow grafu
    int edgesGraph; //liczba krawedzi grafu
    double densityGraph; //gestosc grafu

    public:
    int getV() { return verticesGraph;} // metoda pozwalaj¹ca pozyskaæ liczbê wierzcho³ków
    int getE() { return edgesGraph;} // metoda pozwalaj¹ca pozyskaæ liczbê krawêdzi
    double getDensity() {return densityGraph;} // metoda pozwalaj¹ca pozyskaæ gêstoœæ grafu
    void setVertices(int vertices){ this->verticesGraph = vertices;}
    void setEdges(int vertices,double density){ this->edgesGraph = (density*(vertices-1)*vertices)/2;}
    void setDensity(double density){this->densityGraph = density;}
    Graph(){}; // konstruktor domyœlny
    virtual ~Graph(){}; //destruktor
    Graph(int vertices,double density) // konstruktor grafu 
    {
        this->verticesGraph = vertices;
        this->densityGraph = density;
        this->edgesGraph = (density*(vertices-1)*vertices)/2; 
    }
    Graph(int vertices,int edges,double density) //przeci¹¿enie konstruktora grafu, gdy odane zostaj¹ krawêdzie
    {
        this->verticesGraph = vertices;
        this->densityGraph = density;
        this->edgesGraph = edges; 
    }
    virtual void fillGraph() = 0; 
    virtual void printfGraph() = 0;
};

#endif