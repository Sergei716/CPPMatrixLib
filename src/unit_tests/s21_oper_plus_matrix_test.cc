#include "s21_matrix_test.h"

TEST(PlusOperator, Exception1) {
  // Arrange
  int row = 5;
  int col = 3;
  S21Matrix First{row, row};
  S21Matrix Second{col, col};
  S21Matrix Third{col, col};

  // Act

  // Assert
  EXPECT_ANY_THROW(Third = First + Second);
}

TEST(PlusOperator, Exception2) {
  // Arrange
  int row = 5;
  int col = 9;
  S21Matrix First{row, col};
  S21Matrix Second{col, col};
  S21Matrix Third{row, col};

  // Act

  // Assert
  EXPECT_ANY_THROW(Third = First + Second);
}

TEST(PlusOperator, NotException1) {
  // Arrange
  int row = 5;
  int col = 9;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix Third{row, col};

  // Act

  // Assert
  EXPECT_NO_THROW(Third = First + Second);
}

TEST(PlusOperator, NotException2) {
  // Arrange
  int row = 5;
  int col = 3;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix Third{row, col};

  // Act

  // Assert
  EXPECT_NO_THROW(Third = First + Second);
}

TEST(PlusOperator, Equals1) {
  // Arrange
  int row = 3;
  int col = 3;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix Third{row, col};
  S21Matrix ResultDefault{row, col};

  // Act
  First.setGen();
  Second.setAntiGen();

  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j)
      ResultDefault.setValue(i, j,
                             First.getValue(i, j) + Second.getValue(i, j));
  Third = First + Second;

  // Assert
  EXPECT_EQ(Third.EqMatrix(ResultDefault), true);
}

TEST(PlusOperator, Equals2) {
  // Arrange
  int row = 4;
  int col = 4;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix Third{row, col};
  S21Matrix ResultDefault{row, col};

  // Act
  First.setFullValue(3);
  Second.setFullValue(4);
  ResultDefault.setFullValue(7);
  Third = First + Second;

  // Assert
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j)
      EXPECT_DOUBLE_EQ(Third.getValue(i, j), ResultDefault.getValue(i, j));
}

TEST(PlusOperator, Equals4) {
  // Arrange
  int row = 4;
  int col = 4;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix Third{row, col};
  S21Matrix ResultDefault{row, col};

  // Act
  First.InitMatrix(1.0);
  Second.InitMatrix(1.0);
  Third = First + Second;

  double val = 2;
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j) {
      ResultDefault.setValue(i, j, val);
      val += 2;
    }

  EXPECT_EQ(Third.EqMatrix(ResultDefault), true);
}

TEST(PlusOperator, NotEquals1) {
  // Arrange
  bool flags = true;
  int row = 3;
  int col = 3;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix Third{row, col};
  S21Matrix Result;

  // Act
  Third = First + Second;

  // Assert
  flags = Third.EqMatrix(Result);
  EXPECT_EQ(flags, false);
}

TEST(PlusOperator, NotEquals2) {
  // Arrange
  int row = 4;
  int col = 4;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix Third{row, col};
  S21Matrix ResultDefault{row, col};

  // Act
  First.InitMatrix(1.0);
  Second.InitMatrix(1.0);
  Third = First + Second;

  double val = 2;
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j) {
      ResultDefault.setValue(i, j, val);
      val += 3;
    }

  EXPECT_NE(Third.EqMatrix(ResultDefault), true);
}