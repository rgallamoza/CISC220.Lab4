/*
 * HexNum.cpp
 *
 *  Created on: Oct 6, 2017
 *      Author: ryan
 */

#include "HexNum.hpp"
#include <math.h>

HexNum::HexNum(int x){
	integer = x;
	hex = decToHex(x,"");
}

HexNum::HexNum(string s){
	hex = s;
	integer = hexToDec(s,s.length(),0,0);
}

int HexNum::hexToDec(string h, int len, int count, int result){
	switch(h[len-1]){
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

string HexNum::decToHex(int num, string result){
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

void HexNum::setInteger(int x){
	integer = x;
	hex = decToHex(x,"");
}

void HexNum::setHex(string s){
	hex = s;
	integer = hexToDec(s,s.length(),0,0);
}

int HexNum::getInteger(){
	return integer;
}

string HexNum::getHex(){
	return hex;
}
