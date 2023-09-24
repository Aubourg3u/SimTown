#pragma once
#ifndef MyVector
#define MyVector
#include <string.h>

template <typename T> 
class MyVector()
{
    int size = 0;
    int buffersize = 8;

    T* buffer;

public:
    MyVector()
    {
        buffer = new T[buffersize]
    }

    ~MyVector()
    {
        for( int i = 0; i < size; i++)
        {
            delete MyVector[i];
        }
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
        return buffer[size--];
    }
};

#endif MyVector