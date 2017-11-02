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

		int integer;	// Corresponding decimal value
		string hex;		// Corresponding hexadecimal value

		int hexToDec(string hex, int len, int count, int result);
		/*	Helper function used to find the decimal conversion of a given hexadecimal value.
		 * 	Parameters:
		 * 	string hex: Any hex number to be converted
		 * 	int len: Length of the given string
		 * 	int count: Keeps track of string index. Should be initialized to 0.
		 * 	int result: Resulting decimal value. Should be initialized to 0.
		 */

		string decToHex(int num, string result);
		/*	Helper function used to find the hexadecimal conversion of a given decimal value.
		 * 	Parameters:
		 * 	int num: Any decimal number to be converted
		 * 	string result: Resulting hexadecimal value. Should be initialized to ""
		 */

	public:
		HexNum(int x);
		/*	Initialzes a HexNum based on a given decimal value and its corresponding hexadecimal value.
		 */

		HexNum(string s);
		/*	Initialzes a HexNum based on a given hexadecimal value and its corresponding decimal value.
		 */

		int getInteger();
		/*	Returns decimal value in HexNum.
		 */

		string getHex();
		/*	Returns hexadecimal value in HexNum.
		 */

		void setInteger(int x);
		/*	Sets decimal value to the given integer and changes hexadecimal field to its corresponding value.
		 * 	Parameters:
		 * 	int x: Decimal value to be set in HexNum
		 */

		void setHex(string s);
		/*	Sets hexadecimal value to the given string and changes decimal field to its corresponding value.
		 * 	Parameters:
		 * 	string s: Hexadecimal value to be set in HexNum
		 */
};



#endif /* HEXNUM_HPP_ */
