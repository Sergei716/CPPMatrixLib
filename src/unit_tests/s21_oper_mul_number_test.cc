#include "s21_matrix_test.h"

TEST(MulNumberOperator, Equals1) {
  // Arrange
  int row = 4;
  int col = 4;
  double number = 3.0;
  double value = 3.0;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix ResultDefault{row, col};

  // Act
  First.InitMatrix(1.0);
  Second = First * number;

  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j) {
      ResultDefault.setValue(i, j, value);
      value += 3;
    }

  // Assert
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j)
      EXPECT_DOUBLE_EQ(Second.getValue(i, j), ResultDefault.getValue(i, j));
}

TEST(MulNumberOperator, Equals2) {
  // Arrange
  int row = 4;
  int col = 4;
  double number = 3.0;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};

  // Act
  First.setFullValue(1.0);
  Second = First * number;

  // Assert
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j)
      EXPECT_DOUBLE_EQ(Second.getValue(i, j), number);
}

TEST(MulNumberOperator, Equals3) {
  // Arrange
  int row = 4;
  int col = 4;
  double number = 3.0;
  double value = 3.0;
  double result = number * value;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};

  // Act
  First.setFullValue(value);
  Second = First * number;

  // Assert
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j)
      EXPECT_DOUBLE_EQ(Second.getValue(i, j), result);
}

TEST(MulNumberOperator, NotEquals1) {
  // Arrange
  int row = 4;
  int col = 4;
  double number = 3.0;
  double value = 3.0;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};

  // Act
  First.setFullValue(value);
  Second = First * number;

  // Assert
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j) EXPECT_NE(Second.getValue(i, j), 10);
}

TEST(MulNumberOperator, Equals4) {
  // Arrange
  int row = 4;
  int col = 4;
  double number = 5.0;
  double value = 5.0;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix ResultDefault{row, col};

  // Act
  First.InitMatrix(1.0);
  Second = First * number;

  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j) {
      ResultDefault.setValue(i, j, value);
      value += 5;
    }

  // Assert
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j)
      EXPECT_DOUBLE_EQ(Second.getValue(i, j), ResultDefault.getValue(i, j));
}

TEST(MulNumberOperator, NotEquals2) {
  // Arrange
  int row = 4;
  int col = 4;
  double number = 3.0;
  double value = 3.0;
  S21Matrix First{row, col};
  S21Matrix Third{row, col};

  // Act
  First.setFullValue(value);
  Third = First * number;

  // Assert
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j) EXPECT_NE(Third.getValue(i, j), 12);
}

TEST(MulNumberOperator, Equals5) {
  // Arrange
  int row = 4;
  int col = 4;
  double number = 4.0;
  double value = 3.0;
  double result = number * value;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix Third;

  // Act
  First.setFullValue(value);
  Third = First * number;

  // Assert
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j)
      EXPECT_DOUBLE_EQ(Third.getValue(i, j), result);
}

TEST(MulNumberOperator, Equals6) {
  // Arrange
  int row = 4;
  int col = 4;
  double number = 40.0;
  double value = 32.0;
  double result = number * value;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix Third{row, col};

  // Act
  First.setFullValue(value);
  Third = First * number;

  // Assert
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j)
      EXPECT_DOUBLE_EQ(Third.getValue(i, j), result);
}