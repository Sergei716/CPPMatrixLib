#include "s21_matrix_test.h"

TEST(MulMatrix, Exception1) {
  // Arrange
  double val = 9.9;
  int row = 3;
  int col = 4;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  First.setFullValue(val);
  Second.setFullValue(val);

  // Act

  // Assert
  EXPECT_ANY_THROW(First.MulMatrix(Second));
}

TEST(MulMatrix, Exception2) {
  // Arrange
  double val = 9.9;
  int row = 3;
  int col = 4;
  S21Matrix First{col, col};
  S21Matrix Second{row, row};
  First.setFullValue(val);
  Second.setFullValue(val);

  // Act

  // Assert
  EXPECT_ANY_THROW(First.MulMatrix(Second));
}

TEST(MulMatrix, NotException1) {
  // Arrange
  double val = 9.9;
  int row = 8;
  int col = 4;
  S21Matrix First{row, col};
  S21Matrix Second{col, col};
  First.setFullValue(val);
  Second.setFullValue(val);

  // Act

  // Assert
  EXPECT_NO_THROW(First.MulMatrix(Second));
}

TEST(MulMatrix, NotException2) {
  // Arrange
  double val = 9.9;
  int row = 3;
  int col = 3;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  First.setFullValue(val);
  Second.setFullValue(val);

  // Act

  // Assert
  EXPECT_NO_THROW(First.MulMatrix(Second));
}

TEST(MulMatrix, Equals1) {
  // Arrange
  int row = 4, col = 4;
  double val = 3;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};

  // Act
  First.setFullValue(val);
  Second.setFullValue(val);
  First.MulMatrix(Second);

  // Assert
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j) ASSERT_DOUBLE_EQ(First.getValue(i, j), 36);
}

TEST(MulMatrix, Equals2) {
  // Arrange
  S21Matrix Temp{3, 2};
  S21Matrix Temp2{2, 3};
  S21Matrix ResultDefault{3, 3};

  // Act
  Temp.setGen();
  Temp2.setGen();

  ResultDefault.setValue(0, 0, 9);
  ResultDefault.setValue(0, 1, 12);
  ResultDefault.setValue(0, 2, 15);
  ResultDefault.setValue(1, 0, 19);
  ResultDefault.setValue(1, 1, 26);
  ResultDefault.setValue(1, 2, 33);
  ResultDefault.setValue(2, 0, 29);
  ResultDefault.setValue(2, 1, 40);
  ResultDefault.setValue(2, 2, 51);

  Temp.MulMatrix(Temp2);

  // Assert
  EXPECT_EQ(Temp.EqMatrix(Temp2), Temp2.EqMatrix(Temp));
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      EXPECT_DOUBLE_EQ(ResultDefault.getValue(i, j), Temp.getValue(i, j));
}

TEST(MulMatrix, Equals3) {
  // Arrange
  S21Matrix Temp{2, 3};
  S21Matrix Temp2{3, 2};
  S21Matrix ResultDefault{2, 2};

  // Act
  Temp.setGen();
  Temp2.setGen();

  ResultDefault.setValue(0, 0, 22);
  ResultDefault.setValue(0, 1, 28);
  ResultDefault.setValue(1, 0, 49);
  ResultDefault.setValue(1, 1, 64);

  Temp.MulMatrix(Temp2);

  // Assert
  EXPECT_EQ(Temp.EqMatrix(Temp2), Temp2.EqMatrix(Temp));
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      EXPECT_DOUBLE_EQ(ResultDefault.getValue(i, j), Temp.getValue(i, j));
}

TEST(MulMatrix, Equals4) {
  S21Matrix Temp{4, 4};
  S21Matrix Temp2{4, 4};
  S21Matrix ResultDefault{4, 4};

  Temp.setGen();
  Temp2.setGen();

  ResultDefault.setValue(0, 0, 90.0);
  ResultDefault.setValue(0, 1, 100.0);
  ResultDefault.setValue(0, 2, 110.0);
  ResultDefault.setValue(0, 3, 120.0);

  ResultDefault.setValue(1, 0, 202.0);
  ResultDefault.setValue(1, 1, 228.0);
  ResultDefault.setValue(1, 2, 254.0);
  ResultDefault.setValue(1, 3, 280.0);

  ResultDefault.setValue(2, 0, 314.0);
  ResultDefault.setValue(2, 1, 356.0);
  ResultDefault.setValue(2, 2, 398.0);
  ResultDefault.setValue(2, 3, 440.0);

  ResultDefault.setValue(3, 0, 426.0);
  ResultDefault.setValue(3, 1, 484.0);
  ResultDefault.setValue(3, 2, 542.0);
  ResultDefault.setValue(3, 3, 600.0);

  Temp.MulMatrix(Temp2);
  EXPECT_EQ(Temp.EqMatrix(Temp2), Temp2.EqMatrix(Temp));
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      EXPECT_DOUBLE_EQ(ResultDefault.getValue(i, j), Temp.getValue(i, j));
}

TEST(MulMatrix, Equals5) {
  // Arrange
  S21Matrix Temp{4, 2};
  S21Matrix Temp2{2, 4};
  S21Matrix ResultDefault{4, 4};
  bool flags = false;

  ResultDefault.setValue(0, 0, -25.0);
  ResultDefault.setValue(0, 1, -34.0);
  ResultDefault.setValue(0, 2, -43.0);
  ResultDefault.setValue(0, 3, -52.0);

  ResultDefault.setValue(1, 0, -13.0);
  ResultDefault.setValue(1, 1, -18.0);
  ResultDefault.setValue(1, 2, -23.0);
  ResultDefault.setValue(1, 3, -28.0);

  ResultDefault.setValue(2, 0, -1.0);
  ResultDefault.setValue(2, 1, -2.0);
  ResultDefault.setValue(2, 2, -3.0);
  ResultDefault.setValue(2, 3, -4.0);

  ResultDefault.setValue(3, 0, 11.0);
  ResultDefault.setValue(3, 1, 14.0);
  ResultDefault.setValue(3, 2, 17.0);
  ResultDefault.setValue(3, 3, 20.0);

  // Act
  Temp.InitMatrix(-5.0);
  Temp2.InitMatrix(1.0);
  Temp.MulMatrix(Temp2);
  flags = Temp.EqMatrix(ResultDefault);

  // Assert
  EXPECT_EQ(flags, true);
  EXPECT_EQ(Temp.EqMatrix(Temp2), Temp2.EqMatrix(Temp));
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      EXPECT_DOUBLE_EQ(ResultDefault.getValue(i, j), Temp.getValue(i, j));
}