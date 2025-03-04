#include "s21_matrix_test.h"

TEST(OperatorIndex, Equals1) {
  // Arrange
  int row = 3;
  int col = 4;
  int q = 1;
  S21Matrix First{row, col};

  // Act
  First.setGen();

  // Assert
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j) EXPECT_DOUBLE_EQ(First(i, j), q++);
}

TEST(OperatorIndex, Equals2) {
  // Arrange
  int row = 3;
  int col = 4;
  int q = 32;
  S21Matrix First{row, col};

  // Act
  First.setAntiGen();

  // Assert
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j) EXPECT_DOUBLE_EQ(First(i, j), q--);
}

TEST(OperatorIndex, Equals3) {
  // Arrange
  int row = 3;
  int col = 4;
  int q = 1;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};

  // Act
  First.setGen();
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j) Second(i, j) = q++;

  // Assert
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j) EXPECT_DOUBLE_EQ(First(i, j), Second(i, j));
}

TEST(OperatorIndex, Equals4) {
  // Arrange
  int row = 3;
  int col = 4;
  int q = 32;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};

  // Act
  First.setAntiGen();
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j) Second(i, j) = q--;

  // Assert
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j) EXPECT_DOUBLE_EQ(First(i, j), Second(i, j));
}

TEST(OperatorIndex, Exception1) {
  // Arrange
  int row = 3;
  int col = 4;
  S21Matrix First{row, col};

  // Act

  // Assert
  EXPECT_ANY_THROW(First(3, 0) = 33);
}

TEST(OperatorIndex, Exception2) {
  // Arrange
  int row = 3;
  int col = 4;
  S21Matrix First{row, col};

  // Act

  // Assert
  EXPECT_ANY_THROW(First(-1, 3) = 13);
}

TEST(ConstOperatorIndex, Equals1) {
  // Arrange
  int row = 2;
  int col = 2;
  int q = 1;
  S21Matrix First{row, col};

  // Act
  First(0, 0) = 1;
  First(0, 1) = 2;
  First(1, 0) = 3;
  First(1, 1) = 4;
  S21Matrix const Second = First;

  // Assert
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j) EXPECT_DOUBLE_EQ(Second(i, j), q++);
}

TEST(ConstOperatorIndex, Equals2) {
  // Arrange
  int row = 3;
  int col = 4;
  S21Matrix const First{row, col};

  // Act

  // Assert
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j) EXPECT_DOUBLE_EQ(First(i, j), 0);
}

TEST(ConstOperatorIndex, Exception1) {
  // Arrange
  int row = 3;
  int col = 4;
  S21Matrix const First{row, col};

  // Act

  // Assert
  EXPECT_ANY_THROW(First(3, 0));
}

TEST(ConstOperatorIndex, Exception2) {
  // Arrange
  int row = 2;
  int col = 2;
  S21Matrix First{row, col};

  // Act
  First(0, 0) = 1;
  First(0, 1) = 2;
  First(1, 0) = 3;
  First(1, 1) = 4;
  S21Matrix const Second = First;

  // Assert
  EXPECT_ANY_THROW(First(-1, 3));
}