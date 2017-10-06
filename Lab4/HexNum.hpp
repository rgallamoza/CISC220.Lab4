/*
 * HexNum.hpp
 *
 *  Created on: Oct 6, 2017
 *      Author: ryan
 */

#ifndef HEXNUM_HPP_
#define HEXNUM_HPP_
#include <iostream>
using namespace std;

class HexNum{
	private:
		int integer;
		string hex;

	public:
		HexNum(int x);
		HexNum(string s);

		int hexToDec(string hex, int len, int count, int result);
		string decToHex(int num, string result);

		int getInteger();
		string getHex();

		void setInteger(int x);
		void setHex(string s);
};



#endif /* HEXNUM_HPP_ */
