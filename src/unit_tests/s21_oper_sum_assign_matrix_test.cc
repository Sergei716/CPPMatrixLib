#include "s21_matrix_test.h"

TEST(SumAssignmentOperator, Exception1) {
  // Arrange
  int row = 5;
  int col = 3;
  S21Matrix First{row, row};
  S21Matrix Second{col, col};

  // Act

  // Assert
  EXPECT_ANY_THROW(First += Second);
}

TEST(SumAssignmentOperator, Exception2) {
  // Arrange
  int row = 5;
  int col = 9;
  S21Matrix First{row, col};
  S21Matrix Second{col, col};

  // Act

  // Assert
  EXPECT_ANY_THROW(First += Second);
}

TEST(SumAssignmentOperator, NotException1) {
  // Arrange
  int row = 5;
  int col = 9;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};

  // Act

  // Assert
  EXPECT_NO_THROW(First += Second);
}

TEST(SumAssignmentOperator, NotException2) {
  // Arrange
  int row = 5;
  int col = 3;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};

  // Act

  // Assert
  EXPECT_NO_THROW(First += Second);
}

TEST(SumAssignmentOperator, Equals1) {
  // Arrange
  int row = 3;
  int col = 3;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix ResultDefault{row, col};

  // Act
  First.setGen();
  Second.setAntiGen();

  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j)
      ResultDefault.setValue(i, j,
                             First.getValue(i, j) + Second.getValue(i, j));
  First += Second;

  // Assert
  EXPECT_EQ(First.EqMatrix(ResultDefault), true);
}

TEST(SumAssignmentOperator, Equals2) {
  // Arrange
  int row = 4;
  int col = 4;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix ResultDefault{row, col};

  // Act
  First.setFullValue(3);
  Second.setFullValue(4);
  ResultDefault.setFullValue(7);
  First += Second;

  // Assert
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j)
      EXPECT_DOUBLE_EQ(First.getValue(i, j), ResultDefault.getValue(i, j));
}

TEST(SumAssignmentOperator, Equals4) {
  // Arrange
  int row = 4;
  int col = 4;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix ResultDefault{row, col};

  // Act
  First.InitMatrix(1.0);
  Second.InitMatrix(1.0);
  First += Second;

  double val = 2;
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j) {
      ResultDefault.setValue(i, j, val);
      val += 2;
    }

  EXPECT_EQ(First.EqMatrix(ResultDefault), true);
}

TEST(SumAssignmentOperator, NotEquals1) {
  // Arrange
  bool flags = true;
  int row = 3;
  int col = 3;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix Result;

  // Act
  First += Second;

  // Assert
  flags = First.EqMatrix(Result);
  EXPECT_EQ(flags, false);
}

TEST(SumAssignmentOperator, NotEquals2) {
  // Arrange
  int row = 4;
  int col = 4;
  S21Matrix First{row, col};
  S21Matrix Second{row, col};
  S21Matrix ResultDefault{row, col};

  // Act
  First.InitMatrix(1.0);
  Second.InitMatrix(1.0);
  First += Second;

  double val = 2;
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j) {
      ResultDefault.setValue(i, j, val);
      val += 3;
    }

  EXPECT_NE(First.EqMatrix(ResultDefault), true);
}