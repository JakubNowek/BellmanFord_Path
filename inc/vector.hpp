#ifndef vector_hpp
#define vector_hpp
#include <iostream>

/**
 * @brief klasa modelująca pojęcie wektora
*/
class vectorClass
{
    // wskaznik przechowujacy adres wektora
    int* array;

    //pojemność wektora
    int capacity;

    //liczba elementów obecnych obecnie w kontenerze
    int current;

    public:
   //kontruktor domyslny
    vectorClass() 
    { 
        array = new int[1]; 
        capacity = 1; 
        current = 0; 
    }
    //destruktor
    ~vectorClass()
    {
        delete [] array;
    }
    //metody
    void push(int data);
    void push(int data, int index);
    int getData(int index);
    void pop();
    int size();
    int getcapacity();
    void print(); 
};



#endif