#include "s21_matrix_test.h"

TEST(CalcComplements, Equals1) {
  // Arrange
  int size = 3;
  bool flags = true;
  S21Matrix First{size, size};
  S21Matrix Second{size, size};
  S21Matrix Res;

  // Act
  First(0, 0) = 1;
  First(0, 1) = 2;
  First(0, 2) = 3;
  First(1, 1) = 4;
  First(1, 2) = 2;
  First(2, 0) = 5;
  First(2, 1) = 2;
  First(2, 2) = 1;

  Second(0, 1) = 10;
  Second(0, 2) = -20;
  Second(1, 0) = 4;
  Second(1, 1) = -14;
  Second(1, 2) = 8;
  Second(2, 0) = -8;
  Second(2, 1) = -2;
  Second(2, 2) = 4;

  Res = First.CalcComplements();

  // Assert
  EXPECT_EQ(Res.EqMatrix(Second), flags);
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j) EXPECT_DOUBLE_EQ(Second(i, j), Res(i, j));
}

TEST(CalcComplements, Equals2) {
  // Arrange
  S21Matrix A{4, 4};
  S21Matrix Z{4, 4};
  S21Matrix X{4, 4};

  A(0, 0) = 112.0;
  A(0, 1) = 243.0;
  A(0, 2) = 3.0;
  A(0, 3) = -8.0;
  A(1, 0) = 47.0;
  A(1, 1) = 51.0;
  A(1, 2) = -66.0;
  A(1, 3) = 99.0;
  A(2, 0) = -74.0;
  A(2, 1) = 85.0;
  A(2, 2) = 97.0;
  A(2, 3) = 63.0;
  A(3, 0) = -13.0;
  A(3, 1) = 79.0;
  A(3, 2) = -99.0;
  A(3, 3) = -121.0;

  Z = A.CalcComplements();

  X(0, 0) = -2879514.0;
  X(0, 1) = -1236631.0;
  X(0, 2) = -1685096.0;
  X(0, 3) = 880697.0;
  X(1, 0) = 1162090.0;
  X(1, 1) = -714015.0;
  X(1, 2) = 4046255.0;
  X(1, 3) = -3901600.0;
  X(2, 0) = 4362897.0;
  X(2, 1) = -2049432.0;
  X(2, 2) = -532912.0;
  X(2, 3) = -1370781.0;
  X(3, 0) = 3412773.0;
  X(3, 1) = -1569493.0;
  X(3, 2) = 3144517.0;
  X(3, 3) = 1284666.0;

  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j) EXPECT_DOUBLE_EQ(Z(i, j), X(i, j));
}

TEST(CalcComplements, Equals3) {
  // Arrange
  int size = 4;
  bool flags = true;
  S21Matrix First{size, size};
  S21Matrix Second{size, size};
  S21Matrix Res{size, size};

  // Act
  First(0, 0) = -1.0;
  First(0, 1) = 2.0;
  First(0, 2) = 7.0;
  First(0, 3) = 9.0;
  First(1, 0) = 1.0;
  First(1, 1) = 0.0;
  First(1, 2) = 0.0;
  First(1, 3) = 0.0;
  First(2, 0) = 47.0;
  First(2, 1) = 13.0;
  First(2, 2) = 17.0;
  First(2, 3) = 21.0;
  First(3, 0) = 22.0;
  First(3, 1) = 7.0;
  First(3, 2) = 1.0;
  First(3, 3) = 3.0;

  Res(0, 0) = 0.0;
  Res(0, 1) = -30.0;
  Res(0, 2) = -108.0;
  Res(0, 3) = 106.0;
  Res(1, 0) = 138.0;
  Res(1, 1) = -726.0;
  Res(1, 2) = -1137.0;
  Res(1, 3) = 1061.0;
  Res(2, 0) = 0.0;
  Res(2, 1) = 12.0;
  Res(2, 2) = 57.0;
  Res(2, 3) = -47.0;
  Res(3, 0) = 0.0;
  Res(3, 1) = 6.0;
  Res(3, 2) = -75.0;
  Res(3, 3) = 57.0;

  Second = First.CalcComplements();

  // Assert
  EXPECT_EQ(Res.EqMatrix(Second), flags);
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j) EXPECT_DOUBLE_EQ(Second(i, j), Res(i, j));
}

TEST(CalcComplements, Equals4) {
  // Arrange
  S21Matrix A{4, 4};
  S21Matrix Z{4, 4};
  S21Matrix X{4, 4};

  // Act
  A(0, 0) = 112.0;
  A(0, 1) = 243.0;
  A(0, 2) = 3.0;
  A(0, 3) = -8.0;
  A(1, 0) = 47.0;
  A(1, 1) = 51.0;
  A(1, 2) = -66.0;
  A(1, 3) = 99.0;
  A(2, 0) = -74.0;
  A(2, 1) = 85.0;
  A(2, 2) = 97.0;
  A(2, 3) = 63.0;
  A(3, 0) = -13.0;
  A(3, 1) = 79.0;
  A(3, 2) = -99.0;
  A(3, 3) = -121.0;

  Z = A.CalcComplements();

  X(0, 0) = -2879514.0;
  X(0, 1) = -1236631.0;
  X(0, 2) = -1685096.0;
  X(0, 3) = 880697.0;
  X(1, 0) = 1162090.0;
  X(1, 1) = -714015.0;
  X(1, 2) = 4046255.0;
  X(1, 3) = -3901600.0;
  X(2, 0) = 4362897.0;
  X(2, 1) = -2049432.0;
  X(2, 2) = -532912.0;
  X(2, 3) = -1370781.0;
  X(3, 0) = 3412773.0;
  X(3, 1) = -1569493.0;
  X(3, 2) = 3144517.0;
  X(3, 3) = 1284666.0;

  // Assert
  EXPECT_EQ(Z.EqMatrix(X), true);
}

TEST(CalcComplements, Exception1) {
  // Arrange
  S21Matrix A{3, 4};
  S21Matrix Z{3, 4};
  S21Matrix X{3, 4};

  // Act
  A(0, 0) = 112.0;
  A(0, 1) = 243.0;
  A(0, 2) = 3.0;
  A(0, 3) = -8.0;
  A(1, 0) = 47.0;
  A(1, 1) = 51.0;
  A(1, 2) = -66.0;
  A(1, 3) = 99.0;
  A(2, 0) = -74.0;
  A(2, 1) = 85.0;
  A(2, 2) = 97.0;
  A(2, 3) = 63.0;

  X(0, 0) = -2879514.0;
  X(0, 1) = -1236631.0;
  X(0, 2) = -1685096.0;
  X(0, 3) = 880697.0;
  X(1, 0) = 1162090.0;
  X(1, 1) = -714015.0;
  X(1, 2) = 4046255.0;
  X(1, 3) = -3901600.0;
  X(2, 0) = 4362897.0;
  X(2, 1) = -2049432.0;
  X(2, 2) = -532912.0;
  X(2, 3) = -1370781.0;

  // Assert
  EXPECT_ANY_THROW(Z = A.CalcComplements());
}

TEST(CalcComplements, NotException1) {
  // Arrange
  S21Matrix A{4, 4};
  S21Matrix Z{4, 4};
  S21Matrix X{4, 4};

  // Act
  A(0, 0) = 112.0;
  A(0, 1) = 243.0;
  A(0, 2) = 3.0;
  A(0, 3) = -8.0;
  A(1, 0) = 47.0;
  A(1, 1) = 51.0;
  A(1, 2) = -66.0;
  A(1, 3) = 99.0;
  A(2, 0) = -74.0;
  A(2, 1) = 85.0;
  A(2, 2) = 97.0;
  A(2, 3) = 63.0;
  A(3, 0) = -13.0;
  A(3, 1) = 79.0;
  A(3, 2) = -99.0;
  A(3, 3) = -121.0;

  // Assert
  EXPECT_NO_THROW(Z = A.CalcComplements());
}

TEST(CalcComplements, Equals5) {
  // Arrange
  S21Matrix First;
  S21Matrix Second{3, 3};

  // Act
  Second = First.CalcComplements();

  // Assert
  EXPECT_DOUBLE_EQ(Second(0, 0), 1);
}