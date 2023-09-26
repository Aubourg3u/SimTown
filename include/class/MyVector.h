#pragma once
#ifndef MYVECTOR_H
<<<<<<< HEAD
#    define MYVECTOR_H
#    include <iostream>>
#    include <string.h>
    == == == =
#    define MYVECTOR_H
#    include <string.h>

#    include <iostream>
    >>>>>>> 872c350( feat( residents )
                     : added residents to floreys )

        template < typename T >
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

    MyVector( T* tab, int tab_size )
    {
        buffer = new T[tab_size];
        for( int i = 0; i < tab_size; i++ )
        {
            buffer[i] = tab[i];
        }
        size = tab_size;
    }

    ~MyVector() {}

    void grow()
    {
        buffersize *= 2;
        T* newbuffer = new T[buffersize];
        memcpy( newbuffer, buffer, size );
        delete buffer;
        buffer = newbuffer;
    }

    void push_back( T newElt )
    {
        if( size + 1 >= buffersize )
        {
            grow();
        }
        buffer[size] = newElt;
        size++;
    }

    T pop_back()
    {
        return buffer[--size];
    }

    int get_size()
    {
        return size;
    }

    T at( int i )
    {
        return buffer[i];
    }

    void print( std::ostream& out )
    {
        out << "[ ";
        for( int i = 0; i < size; i++ )
        {
            out << buffer[i] << ( i + 1 == size ? "" : ", " );
        }
        out << " ]" << std::endl;
    }

    T* operator=( const T* rhs )
    {
        T* temp_buffer = new T[rhs.buffersize];
        for( int i = 0; i < rhs.size; i++ )
        {
            temp_buffer[i] = rhs.buffer[i];
        }
        delete buffer;
        buffer = temp_buffer;
    }
};
template < typename T >

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
