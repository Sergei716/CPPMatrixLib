#include "s21_matrix_test.h"

TEST(Transpose, Equals1) {
  // Arrange
  int rows = 3;
  int cols = 3;
  S21Matrix First{rows, cols};
  S21Matrix Second{cols, rows};
  S21Matrix Res;

  // Act
  First.setValue(0, 2, 3);
  First.setValue(0, 1, 1);
  First.setValue(0, 0, 2);
  First.setValue(1, 2, -2);
  First.setValue(1, 1, 4);
  First.setValue(1, 0, 0);
  First.setValue(2, 2, 6);
  First.setValue(2, 1, 5);
  First.setValue(2, 0, -3);

  Second.setValue(0, 2, -3);
  Second.setValue(0, 1, 0);
  Second.setValue(0, 0, 2);
  Second.setValue(1, 2, 5);
  Second.setValue(1, 1, 4);
  Second.setValue(1, 0, 1);
  Second.setValue(2, 2, 6);
  Second.setValue(2, 1, -2);
  Second.setValue(2, 0, 3);

  Res = First.Transpose();

  // Assert
  for (int i = 0; i < cols; ++i)
    for (int j = 0; j < rows; ++j) EXPECT_DOUBLE_EQ(Second(i, j), Res(i, j));
}

TEST(Transpose, Equals2) {
  // Arrange
  int rows = 3;
  int cols = 3;
  S21Matrix First{rows, cols};
  S21Matrix Second{cols, rows};
  S21Matrix Res;

  // Act
  First.InitMatrix(1);

  Second.setValue(0, 2, 7);
  Second.setValue(0, 1, 4);
  Second.setValue(0, 0, 1);
  Second.setValue(1, 2, 8);
  Second.setValue(1, 1, 5);
  Second.setValue(1, 0, 2);
  Second.setValue(2, 2, 9);
  Second.setValue(2, 1, 6);
  Second.setValue(2, 0, 3);

  Res = First.Transpose();

  // Assert
  for (int i = 0; i < cols; ++i)
    for (int j = 0; j < rows; ++j) EXPECT_DOUBLE_EQ(Second(i, j), Res(i, j));
}

TEST(Transpose, Equals3) {
  // Arrange
  int rows = 4;
  int cols = 4;
  S21Matrix First{rows, cols};
  S21Matrix Second{cols, rows};
  S21Matrix Res;

  // Act
  First.InitMatrix(1);

  Second.setValue(0, 3, 13);
  Second.setValue(0, 2, 9);
  Second.setValue(0, 1, 5);
  Second.setValue(0, 0, 1);

  Second.setValue(1, 3, 14);
  Second.setValue(1, 2, 10);
  Second.setValue(1, 1, 6);
  Second.setValue(1, 0, 2);

  Second.setValue(2, 3, 15);
  Second.setValue(2, 2, 11);
  Second.setValue(2, 1, 7);
  Second.setValue(2, 0, 3);

  Second.setValue(3, 3, 16);
  Second.setValue(3, 2, 12);
  Second.setValue(3, 1, 8);
  Second.setValue(3, 0, 4);
  Res = First.Transpose();

  // Assert
  for (int i = 0; i < cols; ++i)
    for (int j = 0; j < rows; ++j) EXPECT_DOUBLE_EQ(Second(i, j), Res(i, j));
}

TEST(Transpose, Equals4) {
  // Arrange
  int rows = 4;
  int cols = 4;
  S21Matrix First{rows, cols};
  S21Matrix Second{cols, rows};
  S21Matrix Res;

  // Act
  First.InitMatrix(1);

  Second(0, 3) = 13;
  Second(0, 2) = 9;
  Second(0, 1) = 5;
  Second(0, 0) = 1;

  Second(1, 3) = 14;
  Second(1, 2) = 10;
  Second(1, 1) = 6;
  Second(1, 0) = 2;

  Second(2, 3) = 15;
  Second(2, 2) = 11;
  Second(2, 1) = 7;
  Second(2, 0) = 3;

  Second(3, 3) = 16;
  Second(3, 2) = 12;
  Second(3, 1) = 8;
  Second(3, 0) = 4;

  Res = First.Transpose();

  // Assert
  for (int i = 0; i < cols; ++i)
    for (int j = 0; j < rows; ++j) EXPECT_DOUBLE_EQ(Second(i, j), Res(i, j));
}

TEST(Transpose, Equals5) {
  // Arrange
  int rows = 2;
  int cols = 4;
  S21Matrix First{rows, cols};
  S21Matrix Second{cols, rows};
  S21Matrix Res;

  // Act
  First(0, 0) = 7;
  First(0, 1) = 8;
  First(0, 2) = 9;
  First(0, 3) = 3;

  First(1, 0) = 4;
  First(1, 1) = 5;
  First(1, 2) = 6;
  First(1, 3) = 7;

  Second(0, 0) = 7;
  Second(0, 1) = 4;
  Second(1, 0) = 8;
  Second(1, 1) = 5;
  Second(2, 0) = 9;
  Second(2, 1) = 6;
  Second(3, 0) = 3;
  Second(3, 1) = 7;

  Res = First.Transpose();

  // Assert
  for (int i = 0; i < cols; ++i)
    for (int j = 0; j < rows; ++j) EXPECT_DOUBLE_EQ(Second(i, j), Res(i, j));
}

TEST(Transpose, NotEquals1) {
  // Arrange
  int rows = 2;
  int cols = 4;
  bool flags = true;
  S21Matrix First{rows, cols};
  S21Matrix Second{cols, rows};
  S21Matrix Res;

  // Act
  First.InitMatrix(1);
  Second.InitMatrix(1);
  Res = First.Transpose();
  flags = First == Second;

  // Assert
  EXPECT_NE(flags, true);
}

TEST(Transpose, NotEquals2) {
  // Arrange
  int rows = 2;
  int cols = 4;
  bool flags = true;
  S21Matrix First{rows, cols};
  S21Matrix Second{cols, rows};
  S21Matrix Res;

  // Act
  First.InitMatrix(1);
  Second.InitMatrix(1);
  Res = First.Transpose();
  flags = First == Second;

  // Assert
  EXPECT_EQ(flags, false);
}

TEST(Transpose, NotEquals3) {
  // Arrange
  int rows = 2;
  int cols = 4;
  S21Matrix First{rows, cols};
  S21Matrix Second{cols, rows};
  S21Matrix Res;

  // Act
  First.InitMatrix(1);
  Second.InitMatrix(1);
  Res = First.Transpose();

  // Assert
  EXPECT_NE(First.EqMatrix(Second), true);
}

TEST(Transpose, NotEquals4) {
  // Arrange
  int rows = 2;
  int cols = 4;
  S21Matrix First{rows, cols};
  S21Matrix Second{cols, rows};
  S21Matrix Res;

  // Act
  First.InitMatrix(1);
  Second.InitMatrix(1);
  Res = First.Transpose();

  // Assert
  EXPECT_EQ(First.EqMatrix(Second), false);
}