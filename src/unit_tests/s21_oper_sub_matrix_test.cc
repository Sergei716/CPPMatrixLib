#include "s21_matrix_test.h"

TEST(SubMatrixOperator, EqMatrix1) {
  // Arrange
  int row = 4;
  int col = 4;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix Third{row, col};
  S21Matrix Fourth;

  // Act
  First.InitMatrix(1.0);
  Second.InitMatrix(1.0);
  Fourth = First - Second;

  // Assert
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j)
      EXPECT_DOUBLE_EQ(Third.getValue(i, j), Fourth.getValue(i, j));
}

TEST(SubMatrixOperator, EqMatrix2) {
  // Arrange
  int row = 4;
  int col = 4;
  int number = 3;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix Third{row, col};
  S21Matrix Fourth;

  // Act
  First.setFullValue(number);
  Second.setFullValue(number);
  Fourth = First - Second;

  // Assert
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j)
      EXPECT_DOUBLE_EQ(Third.getValue(i, j), Fourth.getValue(i, j));
}

TEST(SubMatrixOperator, EqMatrix3) {
  // Arrange
  int row = 4;
  int col = 9;
  double number = -2;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix Third{14, 10};
  S21Matrix Fourth{3, 1};

  // Act
  First.setFullValue(number);
  Fourth = First - Second;
  Third.setFullValue(number);

  // Assert
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j)
      EXPECT_DOUBLE_EQ(Third.getValue(i, j), Fourth.getValue(i, j));
}

TEST(SubMatrixOperator, EqMatrix4) {
  // Arrange
  int row = 5;
  int col = 4;
  double number = -3;
  double number2 = 5.0;
  double result = -8.0;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix Third{row, col};
  S21Matrix Fourth;

  // Act
  First.setFullValue(number);
  Second.setFullValue(number2);
  Fourth = First - Second;
  Third.setFullValue(result);

  // Assert
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j)
      EXPECT_DOUBLE_EQ(Third.getValue(i, j), Fourth.getValue(i, j));
}

TEST(SubMatrixOperator, Exception1) {
  // Arrange
  int row = 4;
  int col = 5;
  S21Matrix First{row, col};
  S21Matrix Second{col, col};
  S21Matrix Third;

  // Act

  // Assert
  EXPECT_ANY_THROW(Third = First - Second);
}

TEST(SubMatrixOperator, Exception2) {
  // Arrange
  int row = 4;
  int col = 5;
  S21Matrix First{row, row};
  S21Matrix Second{row, col};
  S21Matrix Third;

  // Act

  // Assert
  EXPECT_ANY_THROW(Third = First - Second);
}

TEST(SubMatrixOperator, NotException1) {
  // Arrange
  int row = 5;
  int col = 8;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix Third;

  // Act

  // Assert
  EXPECT_NO_THROW(Third = First - Second);
}

TEST(SubMatrixOperator, NotException2) {
  // Arrange
  int row = 9;
  int col = 5;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix Third;

  // Act

  // Assert
  EXPECT_NO_THROW(Third = First - Second);
}