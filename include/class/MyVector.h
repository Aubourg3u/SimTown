#pragma once
#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <string.h>

template <typename T>
class MyVector
{
    int size = 0;
    int buffersize = 8;

    T* buffer;

public:
    MyVector()
    {
        buffer = new T[buffersize];
    }

    MyVector(T* tab, int tab_size) {
        buffer = new T[tab_size];
        for( int i = 0; i < tab_size; i++ )
        {
            buffer[i] = tab[i];
        }
        size = tab_size;
    }

    ~MyVector()
    {
    }

    void push_back( T newElt )
    {
        if( size + 1 >= buffersize )
        {
            buffersize *= 2;
            T* newbuffer = new T[buffersize];
            memcpy( newbuffer, buffer, size );
            delete buffer;
            buffer = newbuffer;
        }
        buffer[size] = newElt;
        size++;
    }

    T pop_back()
    {
        return buffer[--size];
    }

    int get_size() {
        return size;
    }

    T at(int i) {
        return buffer[i];
    }

    void print(std::ostream& out) {
        out << "[ ";
        for( int i = 0; i < size; i++ )
        {
            out << buffer[i] << ( i + 1 == vect.get_size() ? "" : ", " );        
        }
        out << " ]" << std::endl; 
    }

};
    template<typename T>    

    std::ostream& operator<<( std::ostream& out, MyVector< T > vect )
    {
        out << "[ ";
        for( int i = 0; i < vect.get_size(); i++ )
        {
        out << vect.at( i ) << ( i + 1 == vect.get_size() ? "" : ", " );
        };
        out << " ]";
        return out;
    };

#endif