//
//  matrix.hpp
//  TestRevisionP11
//
//  Created by Laura Walsh on 06/05/2019.
//  Copyright © 2019 Laura Walsh. All rights reserved.
//

#ifndef matrix_hpp
#define matrix_hpp

#include <stdio.h>
#include<iostream>
using namespace std;

template<typename T> class matrix{
public:
    //constructor & destructor
    matrix(int n_rows, int n_cols);
    ~matrix();
    
    //copy constructor
    matrix(const matrix& o);
    
    //overload [] to return pointer to the i'th row of data
    T* operator[](int i);
    
    //overload + and * for matrices addition and mulitplication
    matrix operator+(const matrix& a);
    matrix operator*(const matrix& a);
    
private:
    //matrix dimensions and data
    int num_rows, num_cols;
    T** data;
    
};

template<typename T>matrix<T>::matrix(int n_rows, int n_cols):num_rows(n_rows),num_cols(n_cols){
    data = new T*[num_rows];
    for ( int i =0; i< num_rows; i++)
        data[i] = new T[num_cols];
}

template<typename T>matrix<T>::~matrix(){
    for(int i =0; i< num_rows; i++) delete [] data[i];
    delete[] data;
}

template<typename T>matrix<T>::matrix(const matrix& o){
    num_rows = o.num_rows;
    num_cols = o.num_cols;
    data = new T*[num_rows];
    for(int i =0; i< num_rows; i++){
        data[i] = new T[num_cols];
        for(int j=0;j< num_cols; j++)
            data[i][j] = o.data[i][j];
    }
}

template<typename T>T* matrix<T>::operator[](int i){
    return data[i];
}

template<typename T>matrix<T> matrix<T>::operator+(const matrix& a){
    //the two matrices being added must have the same size
    if(num_rows !=a.num_rows ||num_cols != a.num_cols){
        cout << "Error: different sized matrices being added " << endl;
        exit(1);
    }
    matrix<T> u(num_rows, a.num_cols);
    for(int i =0; i< num_rows; i++){
        for(int j =0; j< a.num_cols; j++){
            u[i][j] = data[i][j] + a.data[i][j];
        }
    }
    return u;
}

template<typename T>matrix<T> matrix<T>::operator*(const matrix& a){
    //two matrices can be multiplied only if the 1st matrix's num_cols = the 2nd matrix's num_rows
    if(num_cols != a.num_rows){
        cout << "error: the two matrices cannot be multipled " << endl;
        exit(1);
    }
    //the resulting matrix has the 1st matrix's num_rows and the 2nd matrix's num_cols
    matrix<T> v(num_rows, a.num_cols);
    for(int i =0; i< num_rows; i++){
        for(int j =0; j< a.num_cols; j++){
            v[i][j] = (T)0;
            for(int k =0; k< num_cols; k++)
                v[i][j] += data[i][k] * a.data[k][j];
        }
    }
    return v;
    
}
#endif /* matrix_hpp */
