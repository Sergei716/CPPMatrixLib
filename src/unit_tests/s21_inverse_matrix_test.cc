#include "s21_matrix_test.h"

TEST(InverseMatrix, Equals1) {
  // Arrange
  S21Matrix A{3, 3};
  S21Matrix B;

  double test_1[1][3][3] = {{{2, 5, 7}, {6, 3, 4}, {5, -2, -3}}};

  double answer[3][3] = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};

  // Act
  for (int x = 0; x < 1; x++) {
    for (int y = 0; y < 3; y++) {
      for (int z = 0; z < 3; z++) {
        if (x == 0) A(y, z) = test_1[x][y][z];
      }
    }
  }
  B = A.InverseMatrix();

  // Assert
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_DOUBLE_EQ(answer[i][j], B(i, j));
    }
  }
}

TEST(InverseMatrix, Equals2) {
  // Arrange
  int res = 0;
  S21Matrix A(4, 4);
  S21Matrix Z(4, 4);
  S21Matrix X(4, 4);

  // Act
  A(0, 0) = -1.0;
  A(0, 1) = 2.0;
  A(0, 2) = 7.0;
  A(0, 3) = 9.0;
  A(1, 0) = 1.0;
  A(1, 1) = 0.0;
  A(1, 2) = 0.0;
  A(1, 3) = 0.0;
  A(2, 0) = 47.0;
  A(2, 1) = 13.0;
  A(2, 2) = 17.0;
  A(2, 3) = 21.0;
  A(3, 0) = 22.0;
  A(3, 1) = 7.0;
  A(3, 2) = 1.0;
  A(3, 3) = 3.0;

  X(0, 0) = 0.0;
  X(0, 1) = 1.0;
  X(0, 2) = 0.0;
  X(0, 3) = 0.0;
  X(1, 0) = -5.0 / 23.0;
  X(1, 1) = -121.0 / 23.0;
  X(1, 2) = 2.0 / 23.0;
  X(1, 3) = 1.0 / 23.0;
  X(2, 0) = -18.0 / 23.0;
  X(2, 1) = -379.0 / 46.0;
  X(2, 2) = 19.0 / 46.0;
  X(2, 3) = -25.0 / 46.0;
  X(3, 0) = 53.0 / 69.0;
  X(3, 1) = 1061.0 / 138.0;
  X(3, 2) = -47.0 / 138.0;
  X(3, 3) = 19.0 / 46.0;

  Z = A.InverseMatrix();
  res = X.EqMatrix(Z);

  // Assert
  EXPECT_EQ(res, true);
}

TEST(InverseMatrix, Equals3) {
  // Arrange
  const int size = 3;
  S21Matrix M{size, size};
  S21Matrix Res;
  S21Matrix Expected{size, size};

  // Act
  M(0, 0) = 2;
  M(0, 1) = 5;
  M(0, 2) = 7;
  M(1, 0) = 6;
  M(1, 1) = 3;
  M(1, 2) = 4;
  M(2, 0) = 5;
  M(2, 1) = -2;
  M(2, 2) = -3;

  Res = M.InverseMatrix();
  Expected(0, 0) = 1;
  Expected(0, 1) = -1;
  Expected(0, 2) = 1;
  Expected(1, 0) = -38;
  Expected(1, 1) = 41;
  Expected(1, 2) = -34;
  Expected(2, 0) = 27;
  Expected(2, 1) = -29;
  Expected(2, 2) = 24;

  // Assert
  EXPECT_EQ((Expected == Res), true);
}

TEST(InverseMatrix, Equals4) {
  // Arrange
  S21Matrix A{3, 3}, B{3, 3}, C{3, 3};

  // Act
  C(0, 0) = 44300.0 / 367429.0;
  C(0, 1) = -236300.0 / 367429.0;
  C(0, 2) = 200360.0 / 367429.0;
  C(1, 0) = 20600.0 / 367429.0;
  C(1, 1) = 56000.0 / 367429.0;
  C(1, 2) = -156483.0 / 367429.0;
  C(2, 0) = 30900.0 / 367429.0;
  C(2, 1) = 84000.0 / 367429.0;
  C(2, 2) = -51010.0 / 367429.0;

  A(0, 0) = 2.8;
  A(0, 1) = 1.3;
  A(0, 2) = 7.01;
  A(1, 0) = -1.03;
  A(1, 1) = -2.3;
  A(1, 2) = 3.01;
  A(2, 0) = 0;
  A(2, 1) = -3;
  A(2, 2) = 2;

  B = A.InverseMatrix();
  int res = B == C;
  EXPECT_EQ(res, 1);

  // Assert
  EXPECT_EQ(res, true);
}

TEST(InverseMatrix, Equals5) {
  // Arrange
  const int size = 3;
  S21Matrix M{size, size};
  S21Matrix Expected{size, size}, Res;

  // Act
  M(0, 0) = 2;
  M(0, 1) = 5;
  M(0, 2) = 7;
  M(1, 0) = 6;
  M(1, 1) = 3;
  M(1, 2) = 4;
  M(2, 0) = 5;
  M(2, 1) = -2;
  M(2, 2) = -3;

  Res = M.InverseMatrix();

  Expected(0, 0) = 1;
  Expected(0, 1) = -1;
  Expected(0, 2) = 1;
  Expected(1, 0) = -38;
  Expected(1, 1) = 41;
  Expected(1, 2) = -34;
  Expected(2, 0) = 27;
  Expected(2, 1) = -29;
  Expected(2, 2) = 24;

  // Assert
  EXPECT_EQ(Expected.EqMatrix(Res), true);
}

TEST(InverseMatrix, Exception) {
  // Arrange
  S21Matrix A;
  S21Matrix B;

  // Act

  // Assert
  EXPECT_ANY_THROW(B = A.InverseMatrix());
}