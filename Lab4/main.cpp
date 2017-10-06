/*
 * main.cpp
 *
 *  Created on: Oct 6, 2017
 *      Author: ryan
 */

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "HexNum.hpp"
using namespace std;

string concatenateIthag(string s, int &len);
int hexToDec(string hex, int len, int count, int result);
string decToHex(int num, string result);

int main(){
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
