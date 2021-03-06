/*
* True Reality Open Source Game and Simulation Engine
* Copyright � 2018 Acid Rain Studios LLC
*
* This library is free software; you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License as published by the Free
* Software Foundation; either version 3.0 of the License, or (at your option)
* any later version.
*
* This library is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
* details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
* @author Maxim Serebrennik
*/

#include "MatrixTests.h"

#include <iostream>

//////////////////////////////////////////////////////////////////////////
MatrixTests::MatrixTests()
{
}

//////////////////////////////////////////////////////////////////////////
MatrixTests::~MatrixTests()
{
}

/**
 * @fn  TEST_F(MatrixTests, CreateMatrix)
 *
 * @brief   Test the creation of a default Matrix.
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(MatrixTests, CreateMatrix)
{
    // Create a new matrix using the default constructor
    mTestMatrix = trBase::Matrix();

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrix.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrix(0, 0), 1.0);
    EXPECT_EQ(mTestMatrix(0, 1), 0.0);
    EXPECT_EQ(mTestMatrix(0, 2), 0.0);
    EXPECT_EQ(mTestMatrix(0, 3), 0.0);

    // Test the second row values
    EXPECT_EQ(mTestMatrix(1, 0), 0.0);
    EXPECT_EQ(mTestMatrix(1, 1), 1.0);
    EXPECT_EQ(mTestMatrix(1, 2), 0.0);
    EXPECT_EQ(mTestMatrix(1, 3), 0.0);

    // Test the third row values
    EXPECT_EQ(mTestMatrix(2, 0), 0.0);
    EXPECT_EQ(mTestMatrix(2, 1), 0.0);
    EXPECT_EQ(mTestMatrix(2, 2), 1.0);
    EXPECT_EQ(mTestMatrix(2, 3), 0.0);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrix(3, 0), 0.0);
    EXPECT_EQ(mTestMatrix(3, 1), 0.0);
    EXPECT_EQ(mTestMatrix(3, 2), 0.0);
    EXPECT_EQ(mTestMatrix(3, 3), 1.0);

}

/**
 * @fn  TEST_F(MatrixTests, CreateMatrix)
 *
 * @brief   Test the creation of a Matrix from raw input
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(MatrixTests, CreateMatrixFromNum)
{
    // Create a matrix 
    mTestMatrix = trBase::Matrix(   1.2, 1.3, 1.4, 0.5,
                                    1.6, 1.7, 1.8, 0.6,
                                    2.0, 2.1, 2.2, 0.7,
                                    2.4, 2.5, 2.6, 0.8);
    
    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrix.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrix(0, 0), 1.2);
    EXPECT_EQ(mTestMatrix(0, 1), 1.3);
    EXPECT_EQ(mTestMatrix(0, 2), 1.4);
    EXPECT_EQ(mTestMatrix(0, 3), 0.5);

    // Test the second row values
    EXPECT_EQ(mTestMatrix(1, 0), 1.6);
    EXPECT_EQ(mTestMatrix(1, 1), 1.7);
    EXPECT_EQ(mTestMatrix(1, 2), 1.8);
    EXPECT_EQ(mTestMatrix(1, 3), 0.6);

    // Test the third row values
    EXPECT_EQ(mTestMatrix(2, 0), 2.0);
    EXPECT_EQ(mTestMatrix(2, 1), 2.1);
    EXPECT_EQ(mTestMatrix(2, 2), 2.2);
    EXPECT_EQ(mTestMatrix(2, 3), 0.7);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrix(3, 0), 2.4);
    EXPECT_EQ(mTestMatrix(3, 1), 2.5);
    EXPECT_EQ(mTestMatrix(3, 2), 2.6);
    EXPECT_EQ(mTestMatrix(3, 3), 0.8);
}

/**
 * @fn  TEST_F(MatrixTests, CreateMatrixFromQuat)
 *
 * @brief   Test the creation of a Matrix from a quaternion.
 *
 * @param   parameter1  The first parameter.
 * @param   parameter2  The second parameter.
 */
TEST_F(MatrixTests, CreateMatrixFromQuat)
{
    /*    
    a -b -c -d
    b  a -d  c
    c  d  a -b      <-> (a, d, c, d)
    d -c  b  a
    https://www.youtube.com/watch?v=3Ki14CsP_9k
    */

    // Create a test quaternion
    mTestQuat.Set(1.0, 0.0, 0.0, 0.0);

    // Create a matrix 
    mTestMatrix = trBase::Matrix(mTestQuat);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrix.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrix(0, 0), 1.0);
    EXPECT_EQ(mTestMatrix(0, 1), 0.0);
    EXPECT_EQ(mTestMatrix(0, 2), 0.0);
    EXPECT_EQ(mTestMatrix(0, 3), 0.0);

    // Test the second row values
    EXPECT_EQ(mTestMatrix(1, 0), 0.0);
    EXPECT_EQ(mTestMatrix(1, 1), 1.0);
    EXPECT_EQ(mTestMatrix(1, 2), 0.0);
    EXPECT_EQ(mTestMatrix(1, 3), 0.0);

    // Test the third row values
    EXPECT_EQ(mTestMatrix(2, 0), 0.0);
    EXPECT_EQ(mTestMatrix(2, 1), 0.0);
    EXPECT_EQ(mTestMatrix(2, 2), 1.0);
    EXPECT_EQ(mTestMatrix(2, 3), 0.0);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrix(3, 0), 0.0);
    EXPECT_EQ(mTestMatrix(3, 1), 0.0);
    EXPECT_EQ(mTestMatrix(3, 2), 0.0);
    EXPECT_EQ(mTestMatrix(3, 3), 1.0);

    std::cout << "Getting strange results....need to check the math...didnt read the paper yet" << std::endl;
    std::cout << mTestMatrix << std::endl; 
    // http://www.mrelusive.com/publications/papers/SIMD-From-Quaternion-to-Matrix-and-Back.pdf
    
    // Create a test quaternion
    mTestQuat.Set(0.0, 1.0, 0.0, 0.0);
    
    // Create a matrix 
    mTestMatrix = trBase::Matrix(mTestQuat);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrix.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrix(0, 0), 0.0);
    EXPECT_EQ(mTestMatrix(0, 1), -1.0);
    EXPECT_EQ(mTestMatrix(0, 2), 0.0);
    EXPECT_EQ(mTestMatrix(0, 3), 0.0);

    // Test the second row values
    EXPECT_EQ(mTestMatrix(1, 0), 1.0);
    EXPECT_EQ(mTestMatrix(1, 1), 0.0);
    EXPECT_EQ(mTestMatrix(1, 2), 0.0);
    EXPECT_EQ(mTestMatrix(1, 3), 0.0);

    // Test the third row values
    EXPECT_EQ(mTestMatrix(2, 0), 0.0);
    EXPECT_EQ(mTestMatrix(2, 1), 0.0);
    EXPECT_EQ(mTestMatrix(2, 2), 0.0);
    EXPECT_EQ(mTestMatrix(2, 3), -1.0);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrix(3, 0), 0.0);
    EXPECT_EQ(mTestMatrix(3, 1), 0.0);
    EXPECT_EQ(mTestMatrix(3, 2), 1.0);
    EXPECT_EQ(mTestMatrix(3, 3), 0.0);

    // Create a test quaternion 
    mTestQuat.Set(0.0, 0.0, 1.0, 0.0);
    
    // Create a matrix 
    mTestMatrix = trBase::Matrix(mTestQuat);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrix.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrix(0, 0), 0.0);
    EXPECT_EQ(mTestMatrix(0, 1), 0.0);
    EXPECT_EQ(mTestMatrix(0, 2), -1.0);
    EXPECT_EQ(mTestMatrix(0, 3), 0.0);

    // Test the second row values
    EXPECT_EQ(mTestMatrix(1, 0), 0.0);
    EXPECT_EQ(mTestMatrix(1, 1), 0.0);
    EXPECT_EQ(mTestMatrix(1, 2), 0.0);
    EXPECT_EQ(mTestMatrix(1, 3), 1.0);

    // Test the third row values
    EXPECT_EQ(mTestMatrix(2, 0), 1.0);
    EXPECT_EQ(mTestMatrix(2, 1), 0.0);
    EXPECT_EQ(mTestMatrix(2, 2), 0.0);
    EXPECT_EQ(mTestMatrix(2, 3), 0.0);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrix(3, 0), 0.0);
    EXPECT_EQ(mTestMatrix(3, 1), -1.0);
    EXPECT_EQ(mTestMatrix(3, 2), 0.0);
    EXPECT_EQ(mTestMatrix(3, 3), 0.0);


    // Create a test quaternion
    mTestQuat.Set(0.0, 0.0, 0.0, 1.0);
    
    // Create a matrix 
    mTestMatrix = trBase::Matrix(mTestQuat);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrix.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrix(0, 0), 0.0);
    EXPECT_EQ(mTestMatrix(0, 1), 0.0);
    EXPECT_EQ(mTestMatrix(0, 2), 0.0);
    EXPECT_EQ(mTestMatrix(0, 3), -1.0);

    // Test the second row values
    EXPECT_EQ(mTestMatrix(1, 0), 0.0);
    EXPECT_EQ(mTestMatrix(1, 1), 0.0);
    EXPECT_EQ(mTestMatrix(1, 2), -1.0);
    EXPECT_EQ(mTestMatrix(1, 3), 0.0);

    // Test the third row values
    EXPECT_EQ(mTestMatrix(2, 0), 0.0);
    EXPECT_EQ(mTestMatrix(2, 1), 1.0);
    EXPECT_EQ(mTestMatrix(2, 2), 0.0);
    EXPECT_EQ(mTestMatrix(2, 3), 0.0);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrix(3, 0), 1.0);
    EXPECT_EQ(mTestMatrix(3, 1), 0.0);
    EXPECT_EQ(mTestMatrix(3, 2), 0.0);
    EXPECT_EQ(mTestMatrix(3, 3), 0.0);


    // Create a test quaternion
    mTestQuat.Set(2.3, 3.4, 5.6, 7.8);
    
    // Create a matrix 
    mTestMatrix = trBase::Matrix(mTestQuat);

    // Test if the matrix is valid
    EXPECT_EQ(mTestMatrix.Valid(), true);

    // Test the first row values
    EXPECT_EQ(mTestMatrix(0, 0), 2.3);
    EXPECT_EQ(mTestMatrix(0, 1), -3.4);
    EXPECT_EQ(mTestMatrix(0, 2), -5.6);
    EXPECT_EQ(mTestMatrix(0, 3), -7.8);

    // Test the second row values
    EXPECT_EQ(mTestMatrix(1, 0), 3.4);
    EXPECT_EQ(mTestMatrix(1, 1), 2.3);
    EXPECT_EQ(mTestMatrix(1, 2), -7.8);
    EXPECT_EQ(mTestMatrix(1, 3), 5.6);

    // Test the third row values
    EXPECT_EQ(mTestMatrix(2, 0), 5.6);
    EXPECT_EQ(mTestMatrix(2, 1), 7.8);
    EXPECT_EQ(mTestMatrix(2, 2), 2.3);
    EXPECT_EQ(mTestMatrix(2, 3), -3.4);

    // Test the fourth row values
    EXPECT_EQ(mTestMatrix(3, 0), 7.8);
    EXPECT_EQ(mTestMatrix(3, 1), -5.6);
    EXPECT_EQ(mTestMatrix(3, 2), 3.4);
    EXPECT_EQ(mTestMatrix(3, 3), 2.3);
}