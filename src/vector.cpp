#include "vector.hpp"

void vectorClass::push(int data)
{

    // jeżeli ilość elementów jest równa pojemności wektora,
    // musimy podwoić ilosc rezerwowanego miejsca
    if (current == capacity)
    { 
        int* temp = new int[2 * capacity]; 
  
        //kopiowanie elementow w starej tablicy do nowej
        for (int i = 0; i < capacity; i++)
            temp[i] = array[i]; 
  
        // usuwanie poprzedniej tablicy
        delete[] array; 
        capacity *= 2; 
        array = temp; 
    } 
    // dodawanie nowej danej 
    array[current] = data; 
    current++;  
}

// funckja dodajaca element dla dowolnego indeksu
void vectorClass::push(int data, int index) 
{ 
  
    //jeśli indeks jest równy pojemności to funkcja
    //ta jest taka sama jak zdefiniowany powyżej push
    if (index == capacity) 
        push(data); 
    else
        array[index] = data; 
}

// funkcja zwracajaca element dla danego indeksu
int vectorClass::getData(int index) 
{ 
    // podany indeks musi byc mniejszy niz rozmiar tablicy 
    if (index < current) 
        return array[index];
    else
    {
        std::cout <<"Wykroczono poza zakres kontenera!!!";
        return 0;
    }    
} 
  
// funkcja usuwa ostatni element wektora
void vectorClass::pop() 
{ 
    array[current] = NULL;
    current--; 
}
  
// funkcja zwraca rozmiar wektora 
int vectorClass::size() 
{ 
    return current; 
} 
  
// funkcja zwraca pojemnosc wektora (ile miejsca zajmuje w pamieci) 
int vectorClass::getcapacity() 
{ 
    return capacity; 
} 
  
// funkcja wypisuje zawartosc wektora 
void vectorClass::print() 
{ 
    for (int i = 0; i < current; i++)
    {
        std::cout << " (" << array[i] << ")";
    }
    /*std::cout << std::endl;  */    
} 