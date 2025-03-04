#include "s21_matrix_test.h"

TEST(SubMatrixAssignOperator, EqMatrix1) {
  // Arrange
  int row = 4;
  int col = 4;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix Third{row, col};

  // Act
  First.InitMatrix(1.0);
  Second.InitMatrix(1.0);
  First -= Second;

  // Assert
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j)
      EXPECT_DOUBLE_EQ(Third.getValue(i, j), First.getValue(i, j));
}

TEST(SubMatrixAssignOperator, EqMatrix2) {
  // Arrange
  int row = 4;
  int col = 4;
  int number = 3;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix Third{row, col};

  // Act
  First.setFullValue(number);
  Second.setFullValue(number);
  First -= Second;

  // Assert
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j)
      EXPECT_DOUBLE_EQ(Third.getValue(i, j), First.getValue(i, j));
}

TEST(SubMatrixAssignOperator, EqMatrix3) {
  // Arrange
  int row = 4;
  int col = 9;
  double number = -2;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix Third{row, col};

  // Act
  First.setFullValue(number);
  First -= Second;
  Third.setFullValue(number);

  // Assert
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j)
      EXPECT_DOUBLE_EQ(Third.getValue(i, j), First.getValue(i, j));
}

TEST(SubMatrixAssignOperator, EqMatrix4) {
  // Arrange
  int row = 5;
  int col = 4;
  double number = -3;
  double number2 = 5.0;
  double result = -8.0;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix Third{row, col};

  // Act
  First.setFullValue(number);
  Second.setFullValue(number2);
  First -= Second;
  Third.setFullValue(result);

  // Assert
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j)
      EXPECT_DOUBLE_EQ(Third.getValue(i, j), First.getValue(i, j));
}

TEST(SubMatrixAssignOperator, Exception1) {
  // Arrange
  int row = 4;
  int col = 5;
  S21Matrix First{row, col};
  S21Matrix Second{col, col};

  // Act

  // Assert
  EXPECT_ANY_THROW(First -= Second);
}

TEST(SubMatrixAssignOperator, Exception2) {
  // Arrange
  int row = 4;
  int col = 5;
  S21Matrix First{row, row};
  S21Matrix Second{row, col};

  // Act

  // Assert
  EXPECT_ANY_THROW(First -= Second);
}

TEST(SubMatrixAssignOperator, NotException1) {
  // Arrange
  int row = 5;
  int col = 8;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};

  // Act

  // Assert
  EXPECT_NO_THROW(First -= Second);
}

TEST(SubMatrixAssignOperator, NotException2) {
  // Arrange
  int row = 9;
  int col = 5;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};

  // Act

  // Assert
  EXPECT_NO_THROW(First -= Second);
}