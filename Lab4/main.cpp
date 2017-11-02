/*
 * main.cpp
 *
 *  Created on: Oct 6, 2017
 *      Author: ryan
 */

/*	Ryan Gallamoza
 * 	TA: Eeshita Biswas
 * 	10/10/2017
 * 	This file contains all the functions for each problem in Lab 4
 */

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "HexNum.hpp"
#include "Matrix.hpp"

using namespace std;

string concatenateIthag(string s, int &len);
/*	Takes a string, and returns a new string with vowels replaced by "ithag" + vowel.
 * 	Parameters:
 * 	string s: Any string to be evaluated
 * 	int &len: Reference of integer, to be changed to length of new string
 */

int hexToDec(string hex, int len, int count, int result);
/*	Returns a decimal conversion of a given hexadecimal value.
 * 	Parameters:
 * 	string hex: Any hex number to be converted
 * 	int len: Length of the given string
 * 	int count: Keeps track of string index. Should be initialized to 0.
 * 	int result: Resulting decimal value. Should be initialized to 0.
 */

string decToHex(int num, string result);
/*	Returns a hexadecimal conversion of a given decimal value.
 * 	Parameters:
 * 	int num: Any decimal number to be converted
 * 	string result: Resulting hexadecimal value. Should be initialized to ""
 */

char **randMatrix(int *x, int *y);
/*	Returns pointer address to a matrix of characters (each value initialized to '0')
 * 	Parameters:
 * 	int *x: Pointer to an integer. To be changed to length of generated matrix.
 * 	int *y: Pointer to an integer. To be changed to width of generated matrix.
 */

void printMatrix(char **matrix, int x, int y);
/*	Prints given matrix.
 * 	Parameters:
 * 	char **matrix: Matrix to be printed.
 * 	int x: Length of the given matrix.
 * 	int y: Width of the given matrix.
 */

void fillMatrix(char **m, int x, int y);
/*	Fills five values of given matrix to 'X'.
 * 	Parameters:
 * 	char **matrix: Matrix to be modified.
 * 	int x: Length of the given matrix.
 * 	int y: Width of the given matrix.
 */

int main(){
	srand(time(NULL));

	cout << "Problem 1:" << endl;

	cout << "Test 1:" << endl;
	string s1 = "Cat";
	int l1 = 3;
	concatenateIthag(s1,l1); // Expected: cithagat, 8
	cout << "New l1: " << l1 << endl;

	cout << "Test 2:" << endl;
	string s2 = "Cover";
	int l2 = 5;
	concatenateIthag(s2,l2); // Expected: cithagovithager, 15
	cout << "New l2: " << l2 << endl;

	cout << "Test 3:" << endl;
	string s3 = "Balsamic";
	int l3 = 8;
	concatenateIthag(s3,l3); // Expected: bithagalsithagamithagic, 23
	cout << "New l3: " << l3 << endl;

	cout << "************************************************************" << endl;

	cout << "Problem 2:" << endl;

	cout << "Test 1:" << endl;
	string hex1 = "75BCD15";
	cout << hexToDec(hex1,7,0,0) << endl; // Expected: 123456789

	cout << "Test 2:" << endl;
	string hex2 = "6A4C";
	cout << hexToDec(hex2,4,0,0) << endl; // Expected: 27212

	cout << "Test 3:" << endl;
	string hex3 = "ABCDEF";
	cout << hexToDec(hex3,6,0,0) << endl; // Expected: 11259375

	cout << "************************************************************" << endl;

	cout << "Problem 3:" << endl;

	cout << "Test 1:" << endl;
	int dec1 = 123456789;
	cout << decToHex(dec1,"") << endl; // Expected: 75BCD15

	cout << "Test 2:" << endl;
	int dec2 = 27212;
	cout << decToHex(dec2,"") << endl; // Expected: 6A4C

	cout << "Test 3:" << endl;
	int dec3 = 11259375;
	cout << decToHex(dec3,"") << endl; // Expected: ABCDEF

	cout << "************************************************************" << endl;

	cout << "Problem 4:" << endl;

	cout << "Test 1:" << endl;
	HexNum hn1 = HexNum(123456789);
	cout << hn1.getInteger() << endl; // Expected: 123456789
	cout << hn1.getHex() << endl; // Expected: 75BCD15

	cout << "Test 2:" << endl;
	HexNum hn2 = HexNum(123456789);
	hn2.setInteger(27212);
	cout << hn2.getInteger() << endl; // Expected: 27212
	cout << hn2.getHex() << endl; // Expected: 6A4C

	cout << "Test 3:" << endl;
	HexNum hn3 = HexNum(123456789);
	hn3.setHex("ABCDEF");
	cout << hn3.getInteger() << endl; // Expected: 11259375
	cout << hn3.getHex() << endl; // Expected: ABCDEF

	cout << "Test 4:" << endl;
	HexNum hn4 = HexNum("75BCD15");
	cout << hn4.getInteger() << endl; // Expected: 123456789
	cout << hn4.getHex() << endl; // Expected: 75BCD15

	cout << "Test 5:" << endl;
	HexNum hn5 = HexNum("75BCD15");
	hn5.setHex("6A4C");
	cout << hn5.getInteger() << endl; // Expected: 27212
	cout << hn5.getHex() << endl; // Expected: 64AC

	cout << "Test 6:" << endl;
	HexNum hn6 = HexNum("75BCD15");
	hn6.setInteger(11259375);
	cout << hn6.getInteger() << endl; // Expected: 11259375
	cout << hn6.getHex() << endl; // Expected: ABCDEF

	cout << "************************************************************" << endl;

	cout << "Problem 5:" << endl;

	cout << "Test 1:" << endl;
	int x1 = 0;
	int y1 = 0;
	char **m1;

	m1 = randMatrix(&x1,&y1);

	cout << "x value: " << x1 << endl; //Expecting x1 to hold some value between 3 and 10 (excluding 10)
	cout << "y value: " << y1 << endl; //Expecting y1 to hold some value between 3 and 10 (excluding 10)

	cout << "Before:" << endl;
	printMatrix(m1,x1,y1); // Expecting a matrix of 0's

	cout << "After:" << endl;
	fillMatrix(m1,x1,y1);
	printMatrix(m1,x1,y1); // Expecting a matrix of 0's, and five X's

	cout << "Test 2:" << endl;
	int x2 = 0;
	int y2 = 0;
	char **m2;

	m2 = randMatrix(&x2,&y2);

	cout << "x value: " << x2 << endl; //Expecting x2 to hold some value between 3 and 10 (excluding 10)
	cout << "y value: " << y2 << endl; //Expecting y2 to hold some value between 3 and 10 (excluding 10)

	cout << "Before:" << endl;
	printMatrix(m2,x2,y2); // Expecting a matrix of 0's

	cout << "After:" << endl;
	fillMatrix(m2,x2,y2);
	printMatrix(m2,x2,y2); // Expecting a matrix of 0's, and five X's

	cout << "Test 3:" << endl;
	int x3 = 0;
	int y3 = 0;
	char **m3;

	m3 = randMatrix(&x3,&y3);

	cout << "x value: " << x3 << endl; //Expecting x3 to hold some value between 3 and 10 (excluding 10)
	cout << "y value: " << y3 << endl; //Expecting y3 to hold some value between 3 and 10 (excluding 10)

	cout << "Before:" << endl;
	printMatrix(m3,x3,y3); // Expecting a matrix of 0's

	cout << "After:" << endl;
	fillMatrix(m3,x3,y3);
	printMatrix(m3,x3,y3); // Expecting a matrix of 0's, and five X's

	cout << "************************************************************" << endl;

	cout << "Problem 6:" << endl;

	cout << "Test 1:" << endl;
	Matrix mc1 = Matrix();
	cout << "Length,Width Before:" << endl;
	cout << mc1.getLength() << "," << mc1.getWidth() << endl;
	mc1.randMatrix();
	cout << "Length,Width After:" << endl;
	cout << mc1.getLength() << "," << mc1.getWidth() << endl;
	cout << "Array Before:" << endl;
	mc1.printMatrix();
	cout << "Array After:" << endl;
	mc1.fillMatrix();
	mc1.printMatrix();

	cout << "Test 2:" << endl;
	Matrix mc2 = Matrix();
	cout << "Length,Width Before:" << endl;
	cout << mc2.getLength() << "," << mc2.getWidth() << endl;
	mc2.randMatrix();
	cout << "Length,Width After:" << endl;
	cout << mc2.getLength() << "," << mc2.getWidth() << endl;
	cout << "Array Before:" << endl;
	mc2.printMatrix();
	cout << "Array After:" << endl;
	mc2.fillMatrix();
	mc2.printMatrix();

	cout << "Test 3:" << endl;
	Matrix mc3 = Matrix();
	cout << "Length,Width Before:" << endl;
	cout << mc3.getLength() << "," << mc3.getWidth() << endl;
	mc3.randMatrix();
	cout << "Length,Width After:" << endl;
	cout << mc3.getLength() << "," << mc3.getWidth() << endl;
	cout << "Array Before:" << endl;
	mc3.printMatrix();
	cout << "Array After:" << endl;
	mc3.fillMatrix();
	mc3.printMatrix();

	return 0;
}

string concatenateIthag(string s, int &len){
	string result = "";
	int newlen = 0;

	for(int i=0;i<len;i++){
		if(s[i] == 'a'||s[i] =='e'||s[i] =='i'||s[i] =='o'||s[i] =='u'||s[i] =='y'){
			result += "ithag" + string(1,s[i]);
			newlen += 6;
		}
		else if(s[i] == 'A'||s[i] =='E'||s[i] =='I'||s[i] =='O'||s[i] =='U'||s[i] =='Y'){
			result += "ithag" + string(1,tolower(s[i]));
			newlen += 6;
		}
		else if(isupper(s[i])){
			result += string(1,tolower(s[i]));
			newlen += 1;
		}
		else{
			result += string(1,s[i]);
			newlen += 1;
		}
	}

	len = newlen;

	cout << result << endl;
	cout << newlen << endl;

	return result;
}

int hexToDec(string hex, int len, int count, int result){
	switch(hex[len-1]){
	case '1':
		result+=1*(int)(pow(16,count)+.5);
		break;
	case '2':
		result+=2*(int)(pow(16,count)+.5);
		break;
	case '3':
		result+=3*(int)(pow(16,count)+.5);
		break;
	case '4':
		result+=4*(int)(pow(16,count)+.5);
		break;
	case '5':
		result+=5*(int)(pow(16,count)+.5);
		break;
	case '6':
		result+=6*(int)(pow(16,count)+.5);
		break;
	case '7':
		result+=7*(int)(pow(16,count)+.5);
		break;
	case '8':
		result+=8*(int)(pow(16,count)+.5);
		break;
	case '9':
		result+=9*(int)(pow(16,count)+.5);
		break;
	case 'A':
		result+=10*(int)(pow(16,count)+.5);
		break;
	case 'B':
		result+=11*(int)(pow(16,count)+.5);
		break;
	case 'C':
		result+=12*(int)(pow(16,count)+.5);
		break;
	case 'D':
		result+=13*(int)(pow(16,count)+.5);
		break;
	case 'E':
		result+=14*(int)(pow(16,count)+.5);
		break;
	case 'F':
		result+=15*(int)(pow(16,count)+.5);
		break;
	}

	if(len==1){
		return result;
	}
	else{
		return hexToDec(hex,len-1,count+1,result);
	}
}

string decToHex(int num, string result){
	switch(num%16){
	case 0:
		result = '0' + result;
		break;
	case 1:
		result = '1' + result;
		break;
	case 2:
		result = '2' + result;
		break;
	case 3:
		result = '3' + result;
		break;
	case 4:
		result = '4' + result;
		break;
	case 5:
		result = '5' + result;
		break;
	case 6:
		result = '6' + result;
		break;
	case 7:
		result = '7' + result;
		break;
	case 8:
		result = '8' + result;
		break;
	case 9:
		result = '9' + result;
		break;
	case 10:
		result = 'A' + result;
		break;
	case 11:
		result = 'B' + result;
		break;
	case 12:
		result = 'C' + result;
		break;
	case 13:
		result = 'D' + result;
		break;
	case 14:
		result = 'E' + result;
		break;
	case 15:
		result = 'F' + result;
		break;
	}

	if(num/16==0){
		return result;
	}
	else{
		return decToHex(num/16,result);
	}
}

char **randMatrix(int *x, int *y){
	int length = rand() % 7 + 3;
	int width = rand() % 7 + 3;

	*x = length;
	*y = width;

	char **matrix;
	matrix = new char*[length];

	for(int i=0;i<length;i++){
		matrix[i] = new char[width];

		for(int j=0;j<width;j++){
					matrix[i][j] = '0';
		}
	}

	return matrix;

	for(int i=0;i<length;i++){
		delete [] matrix[i];
	}
	delete [] matrix;
}

void printMatrix(char **matrix, int x, int y){
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void fillMatrix(char **m, int x, int y){
	int targetx, targety;
	for(int i=0;i<5;i++){
		addx:
		targetx = rand()%x;
		targety = rand()%y;
		if(m[targetx][targety]=='0'){
			m[targetx][targety] = 'X';
		}
		else{
			goto addx;
		}
	}
}
