/*
 * Matrix.cpp
 *
 *  Created on: Oct 11, 2017
 *      Author: ryan
 */

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Matrix.hpp"
using namespace std;

Matrix::Matrix(){
	matrix = NULL;
	length = 0;
	width = 0;
}

Matrix::~Matrix(){
	for(int i=0;i<length;i++){
		delete [] matrix[i];
	}
	delete [] matrix;
}

void Matrix::randMatrix(){
	length = rand() % 7 + 3;
	width = rand() % 7 + 3;

	matrix = new char*[length];

	for(int i=0;i<length;i++){
		matrix[i] = new char[width];

		for(int j=0;j<width;j++){
					matrix[i][j] = '0';
		}
	}


}

void Matrix::printMatrix(){
	for(int i=0;i<length;i++){
		for(int j=0;j<width;j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void Matrix::fillMatrix(){
	int targetx, targety;
	for(int i=0;i<5;i++){
		addx:
		targetx = rand()%length;
		targety = rand()%width;
		if(matrix[targetx][targety]=='0'){
			matrix[targetx][targety] = 'X';
		}
		else{
			goto addx;
		}
	}
}

char Matrix::getMatrix(){
	return **matrix;
}

int Matrix::getLength(){
	return length;
}

int Matrix::getWidth(){
	return width;
}
