#include "P2_Bellman.h"

/* udostępnienie nazw z przestrzeni std */
using std::cout;
using std::endl;
using std::cin;

int main()
{
    double density; //zmienna przechowująca gęstośc grafu
    int vertices;
    int edges;
    int vertexSource, vertexDestination, weight;
    //int choice_graph = 0;
    char choice[2] = " "; //tablica znakow zapisujaca wybor uzytkownika poziom 1
    std::fstream file; //zmienna plikowa potrzebna do wczytywania danych z pliku

    cout << "Algorytm Bellmana-Forda - Badanie czasu: " << endl;

    while (choice[0] != '0') 
    {
        cout << "\nJaki rodzaj grafu chcesz zbadac: " << endl;
        cout << "1. 100 grafow jako listy sasiedztwa " << endl;
        cout << "2. 100 grafow jako macierze sasiedztwa: " << endl;
        cout << "3. Wczytaj graf z pliku jako lista sasiedztwa: " << endl;
        cout << "4. Wczytaj graf z pliku jako macierz sasiedztwa: " << endl;
        cout << "0. Ewakuacja!!! " << endl << endl;
        cout << "Twoj wybor : ";
        cin >> choice[0];
        cin.ignore(100000, '\n');
        switch (choice[0])
        {
        case '1':
        {
            //pobieramy parametry grafu
            cout << "Podaj ilosc wierzcholkow grafu: ";
            cin >> vertices;
            cin.ignore(100000, '\n');
            cout << "Podaj gestosc grafu w zakresie ( 0,100% ] : ";
            cin >> density;
            density = density / 100.0;
            cin.ignore(100000, '\n');

            //dynamiczna tablica grafow
            GraphList* graphlist;
            graphlist = new GraphList[SIZE];

            //ustawiamy parametry grafu
            for (int i = 0; i < SIZE; i++)
            {
                graphlist[i].setDensity(density);
                graphlist[i].setEdges(vertices, density);
                graphlist[i].setVertices(vertices);
            }

            //ustawiamy dynamicznie liste
            for (int i = 0; i < SIZE; i++)
                graphlist[i].setAdjacencyList(vertices);

            //wypelniamy graf losowymi krawedziami o losowych wierzcholkach
            for (int i = 0; i < SIZE; i++)
                graphlist[i].fillGraph();

            //czas przed wyszukaniem najkrotszej drogi
            auto time_start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < SIZE; i++)
                bellmanfordList/*File*/(graphlist[i], 0);
            auto time_end = std::chrono::high_resolution_clock::now();

            /****---- zliczanie czasu ----****/

            /*czas trwania zmiennoprzecinkowego*/
            std::chrono::duration<double, std::milli> algorithmTime_ms = time_end - time_start;
            // integralny czas trwania: wymaga czasu duration_cast
            auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_start);
            /* zamiana calkowitego czasu na mniejsza jednostke
            nie potrzebny duration_cast */
            std::chrono::duration<long, std::micro> int_usec = int_ms;

            /****---- koniec zliczania czasu ----****/

            //cout << "algorithm took " << algorithmTime_ms.count() << " ms, "
            //    << "or " << int_ms.count() << " whole milliseconds "
            //    << "(which is " << int_usec.count() << " whole microseconds)" << endl;
            cout << endl << "Czas pracy algorytmu " << algorithmTime_ms.count() / 1000.0 << " sekund. " << endl;
            cout << "Sredni czas analizy jednego grafu " << algorithmTime_ms.count() / 1000.0/SIZE << " sekund. " << endl;

            delete[] graphlist;
            choice[0] = ' ';
            break;
        }
        case '2':
        {
            //pobieramy parametry grafu
            cout << "Podaj ilosc wierzcholkow grafie: ";
            cin >> vertices;
            cin.ignore(100000, '\n');
            cout << "Podaj gestosc grafu w zakresie ( 0,100% ] : ";
            cin >> density;
            density = density / 100.0;
            cin.ignore(100000, '\n');

            //dynamiczna tablica grafow
            GraphMatrix* graphmatrix;
            graphmatrix = new GraphMatrix[SIZE];

            //ustawiamy parametru grafu
            for (int i = 0; i < SIZE; i++)
            {
                graphmatrix[i].setDensity(density);
                graphmatrix[i].setVertices(vertices);
                graphmatrix[i].setEdges(vertices, density);
            }

            //ustawiamy dynamicznie macierz
            for (int i = 0; i < SIZE; i++)
                graphmatrix[i].setAdjacencyMatrix(vertices);

            //wypelniamy graf losowymi krawedziami o losowych wagach
            for (int i = 0; i < SIZE; i++)
                graphmatrix[i].fillGraph();

            //czas przed wyszukaniem najkrotszej drogi
            auto time_start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < SIZE; i++)
                bellmanfordMatrix/*File*/(graphmatrix[i], 0);
            auto time_end = std::chrono::high_resolution_clock::now();

            /****---- zliczanie czasu ----****/

            /*czas trwania zmiennoprzecinkowego*/
            std::chrono::duration<double, std::milli> algorithmTime_ms = time_end - time_start;
            // integralny czas trwania: wymaga czasu duration_cast
            auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_start);
            /* zamiana calkowiego czasu na mniejsza jednostke
            nie potrzebny duration_cast */
            std::chrono::duration<long, std::micro> int_usec = int_ms;

            /****---- koniec zliczania czasu ----****/

            cout << endl << "Czas pracy algorytmu " << algorithmTime_ms.count() / 1000.0 << " sekund. " << endl;
            cout << "Sredni czas analizy jednego grafu " << algorithmTime_ms.count() / 1000.0/SIZE << " sekund. " << endl;
            //wyswietnie jednego ze 100 utworzonych nstancji grafu 
            // graphmatrix[0].printfGraph();

            delete[] graphmatrix;
            choice[0] = ' ';
            break;
        }
        case '3':
        {
            //otwieramy plik
            file.open("data.txt", std::ios::in);
            //sprawdzamy czy plik istnieje
            if (file.good() == false)
            {
                cout << "Plik nie istnieje: ";
                exit(0);
            }
            //odczytujemy z pliku parametry plikow
            file >> edges;
            file >> vertices;
            file >> density;
            //zamykamy plik
            //tworzymy graf z podanymi parametrami
            GraphList graph(vertices, edges, density);
            //wczytujemy krawedzie
            for (int i = 0; i < graph.getE(); i++)
            {
                file >> vertexSource;
                file >> vertexDestination;
                file >> weight;
                graph.addEdge(vertexSource, vertexDestination, weight);
            }
            //zamykamy plik
            file.close();
            graph.printfGraph();
            bellmanfordListFile(graph, 0);
            choice[0] = ' ';
            break;
        }
        case '4':
        {
            //otwieranie pliku z którego będą wczytywane dane
            file.open("data.txt", std::ios::in);
            //sprawdzamy czy plik istnieje
            if (file.good() == false)
            {
                cout << "Plik nie istnieje :( ";
                exit(0);
            }
            //odczytywanie parametrów grafu : ilość krawędzi, ilość wierzchołków, gęstość 
            file >> edges;
            file >> vertices;
            file >> density;
            //tworzenie grafu z podanymi parametrami i danymi wczytanymi z kolejnych linijek pliku
            GraphMatrix graph(vertices, edges, density);
            for (int i = 0; i < graph.getE(); i++)
            {
                file >> vertexSource;
                file >> vertexDestination;
                file >> weight;
                graph.addEdge(vertexSource, vertexDestination, weight);
            }
            file.close(); //zamykanie pliku
            graph.printfGraph(); // wypisywanie połączeń grafu
            bellmanfordMatrixFile(graph, 0);
            choice[0] = ' ';
            break;
        }
        case '0': {choice[0] = ' '; return 0; break; }
        default:
        {
            cout << "Nie ma takiej opcji w menu: " << endl;
            choice[0] = ' ';
        }

        }
    }
    return 0;
}
