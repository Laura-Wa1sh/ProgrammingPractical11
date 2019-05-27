//
//  main.cpp
//  TestRevisionP11
//
//  Created by Laura Walsh on 06/05/2019.
//  Copyright © 2019 Laura Walsh. All rights reserved.
//

#include <iostream>
#include "matrix.hpp"
using namespace std;

int main1(){
    //A synamic array of N integer row pointrrs is created by using the so called "double pointer" syntax
    int N = 10;
    int M = 10;
    int ** a = new int*[N];
    
    //initialise each row pointer to its own dynamic array of M column integers
    for(int i =0; i< N; i++)
        a[i] = new int[M];
    
    //accessing the 2D array elements
    a[2][4] = 57;
    int b = a[3][8];
    
    cout << "Array at a[2][4] = " << a[2][4] << endl;
    cout << "Array at a[3][8]= " << b << endl;
    
    
    //delete the array:
    
    for(int i =0; i< N; i++) delete [] a[i];
    delete[] a;
    
    return 0;
}

int main(){
    // dimensions of a matrix
    int nRows = 3, nCols = 3;
    // create an interger matrix of nRows x nCols
    matrix<int> a(nRows, nCols);
    // set the matrix with random values
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            a[i][j] = rand() % 100;
    // print the matrix
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) cout << a[i][j] << " "; cout << endl;
    }
    cout << endl;
    // create two nRows x nCols double matrices
    matrix<double> x(nRows, nCols);
    x[0][0] = 1; x[0][1] = 2; x[0][2] = 3;
    x[1][0] = 0; x[1][1] = 1; x[1][2] = 4;
    x[2][0] = 5; x[2][1] = 6; x[2][2] = 0;
    matrix<double> y(nRows, nCols);
    y[0][0] = -24; y[0][1] = 18; y[0][2] = 5;
    y[1][0] = 20; y[1][1] = -15; y[1][2] = -4;
    y[2][0] = -5; y[2][1] = 4; y[2][2] = 1;
    // matrix addition: u = x + y
    matrix<double> u = x + y;
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) cout << u[i][j] << " "; cout << endl;
    }
    cout << endl;
    // matrix multiplication: v = x * y
    matrix<double> v = x * y;
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) cout << v[i][j] << " "; cout << endl;
    }
    cout << endl;
    return 0;
}
