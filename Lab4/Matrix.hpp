/*
 * Matrix.hpp
 *
 *  Created on: Oct 11, 2017
 *      Author: ryan
 */

#ifndef MATRIX_HPP_
#define MATRIX_HPP_

class Matrix{

		char **matrix;	// Matrix of characters contained in Matrix class.
		int length;		// Corresponding length value of matrix
		int width;		// Corresponding width value of matrix

	public:
		Matrix();
		/*	Initializes a Matrix class with a NULL matrix, and length and width values initialized to 0.
		 */

		~Matrix();
		/*	Properly deletes matrix from heap.
		 */

		void randMatrix();
		/*	Sets pointer of a matrix of characters (each value initialized to '0') to the matrix field. Length
		 * 	and width fields are set to the generated values.
		 */

		void printMatrix();
		/*	Prints matrix contained in the class.
		 */

		void fillMatrix();
		/*	Fills five values of matrix contained in the class to 'X'.
		 */

		char getMatrix();
		/*	Returns matrix of characters contained in class.
		 */

		int getLength();
		/*	Returns length value contained in class.
		 */
		int getWidth();
		/*	Returns width value contained in class.
		 */
};

#endif /* MATRIX_HPP_ */
