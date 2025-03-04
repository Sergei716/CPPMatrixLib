#include "s21_matrix_test.h"

TEST(Determinant, Equals1) {
  // Arrange
  int size = 3;
  S21Matrix A{size, size};
  S21Matrix B{size, size};
  S21Matrix C{size, size};
  S21Matrix D{5, 5};
  double A_result = 0.0;
  double B_result = 0.0;
  double C_result = 0.0;
  double D_result = 0.0;

  double test_1[3][3][3] = {{{1350.717, 250.7127, 340.77},
                             {450.707, 520.717, 660.77},
                             {770.707, 840.717, 9750.77}},

                            {{191.709, 2920.797, 3920.707},
                             {491.709, 590.7097, 690.797},
                             {791.71, 890.71, 990.71}},

                            {{1901.757, 291.705, 3901.71},
                             {491.75, 5901.705, 6901.75},
                             {7901.775, 8901.7050, 99001.75}}};

  double test_2[1][5][5] = {{{13, 25, 30, 25, 30},
                             {45, 52, 60, 50, 66},
                             {77, 84, 97, 84, 97},
                             {77, 84, 97, 84, 97},
                             {77, 84, 97, 84, 97}}};

  double answer_1 = 5125994629.3762889999;
  //  double answer_2 = 52361913.725383565; // for linux
  double answer_2 = 52361913.725383349;
  double answer_3 = 831152331541.16470493;
  double answer_4 = 0;

  // Act
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      for (int z = 0; z < 3; z++) {
        if (x == 0) A(y, z) = test_1[x][y][z];
        if (x == 1) B(y, z) = test_1[x][y][z];
        if (x == 2) C(y, z) = test_1[x][y][z];
      }
    }
  }
  for (int x = 0; x < 1; x++) {
    for (int y = 0; y < 5; y++) {
      for (int z = 0; z < 5; z++) {
        if (x == 0) D(y, z) = test_2[x][y][z];
      }
    }
  }

  A_result = A.Determinant();
  B_result = B.Determinant();
  C_result = C.Determinant();
  D_result = D.Determinant();

  // Assert

  EXPECT_DOUBLE_EQ(A_result, answer_1);
  EXPECT_DOUBLE_EQ(B_result, answer_2);
  EXPECT_DOUBLE_EQ(C_result, answer_3);
  EXPECT_DOUBLE_EQ(D_result, answer_4);
}

TEST(Determinant, Equals2) {
  // Arrange
  S21Matrix Result1{3, 3};
  double result2 = 0.0;

  // Act
  Result1(0, 0) = 1;
  Result1(0, 1) = 2;
  Result1(0, 2) = 3;

  Result1(1, 0) = 4;
  Result1(1, 1) = 5;
  Result1(1, 2) = 6;

  Result1(2, 0) = 7;
  Result1(2, 1) = 8;
  Result1(2, 2) = 9;

  double expected_result = 0;
  result2 = Result1.Determinant();

  // Assert
  EXPECT_DOUBLE_EQ(expected_result, result2);
}

TEST(Determinant, Zero) {
  // Arrange
  double determ = 0.0;
  S21Matrix A{8, 8};

  // Act
  A.InitMatrix(1.0);
  determ = A.Determinant();

  // Assert
  EXPECT_DOUBLE_EQ(determ, 0.0);
}

TEST(Determinant, Exception1) {
  // Arrange
  S21Matrix A{3, 8};

  // Act
  A.InitMatrix(1.0);

  // Assert
  EXPECT_ANY_THROW(A.Determinant());
}

TEST(Determinant, NotException1) {
  // Arrange
  int size = 3;
  S21Matrix A{size, size};
  S21Matrix B{size, size};
  S21Matrix C{size, size};
  S21Matrix D{5, 5};

  double test_1[3][3][3] = {{{1350.717, 250.7127, 340.77},
                             {450.707, 520.717, 660.77},
                             {770.707, 840.717, 9750.77}},

                            {{191.709, 2920.797, 3920.707},
                             {491.709, 590.7097, 690.797},
                             {791.71, 890.71, 990.71}},

                            {{1901.757, 291.705, 3901.71},
                             {491.75, 5901.705, 6901.75},
                             {7901.775, 8901.7050, 99001.75}}};

  double test_2[1][5][5] = {{{13, 25, 30, 25, 30},
                             {45, 52, 60, 50, 66},
                             {77, 84, 97, 84, 97},
                             {77, 84, 97, 84, 97},
                             {77, 84, 97, 84, 97}}};

  // Act
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      for (int z = 0; z < 3; z++) {
        if (x == 0) A(y, z) = test_1[x][y][z];
        if (x == 1) B(y, z) = test_1[x][y][z];
        if (x == 2) C(y, z) = test_1[x][y][z];
      }
    }
  }
  for (int x = 0; x < 1; x++) {
    for (int y = 0; y < 5; y++) {
      for (int z = 0; z < 5; z++) {
        if (x == 0) D(y, z) = test_2[x][y][z];
      }
    }
  }

  // Assert

  EXPECT_NO_THROW(A.Determinant(););
  EXPECT_NO_THROW(B.Determinant(););
  EXPECT_NO_THROW(C.Determinant(););
  EXPECT_NO_THROW(D.Determinant(););
}
