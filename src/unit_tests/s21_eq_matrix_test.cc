#include "s21_matrix_test.h"

TEST(EqMatrix, Equals1) {
  // Arrange
  double val = 3.3;
  int size = 3;
  bool flags1 = false;
  bool flags2 = false;
  S21Matrix First{size, size};
  S21Matrix Second{size, size};
  First.setFullValue(val);
  Second.setFullValue(val);

  // Act
  flags1 = First.EqMatrix(Second);
  flags2 = Second.EqMatrix(First);

  // Assert
  EXPECT_TRUE(flags1);
  EXPECT_TRUE(flags2);
}

TEST(EqMatrix, Equals2) {
  // Arrange
  double val = 3.3;
  int row = 4;
  int cols = 5;
  bool flags1 = false;
  bool flags2 = false;
  S21Matrix First{row, cols};
  S21Matrix Second{row, cols};
  First.setFullValue(val);
  Second.setFullValue(val);

  // Act
  flags1 = First.EqMatrix(Second);
  flags2 = Second.EqMatrix(First);

  // Assert
  EXPECT_TRUE(flags1);
  EXPECT_TRUE(flags2);
}

TEST(EqMatrix, Equals3) {
  // Arrange
  double val = 0.0;
  int row = 13;
  int cols = 5;
  bool flags1 = false;
  bool flags2 = false;
  S21Matrix First{row, cols};
  S21Matrix Second{row, cols};
  First.setFullValue(val);
  Second.setFullValue(val);

  // Act
  flags1 = First.EqMatrix(Second);
  flags2 = Second.EqMatrix(First);

  // Assert
  EXPECT_TRUE(flags1);
  EXPECT_TRUE(flags2);
}

TEST(EqMatrix, Equals4) {
  // Arrange
  int row = 13;
  int cols = 5;
  bool flags1 = false;
  bool flags2 = false;
  S21Matrix First{row, cols};
  S21Matrix Second{row, cols};

  // Act
  flags1 = First.EqMatrix(Second);
  flags2 = Second.EqMatrix(First);

  // Assert
  EXPECT_TRUE(flags1);
  EXPECT_TRUE(flags2);
}

TEST(EqMatrix, NotEquals1) {
  // Arrange
  int row = 4;
  int cols = 4;
  bool flags1 = false;
  bool flags2 = false;
  S21Matrix First{row, cols};
  S21Matrix Second{row, cols};

  // Act
  First.setFullValue(3.5);
  Second.setFullValue(3.6);
  flags1 = First.EqMatrix(Second);
  flags2 = Second.EqMatrix(First);

  // Assert
  EXPECT_FALSE(flags1);
  EXPECT_FALSE(flags2);
}

TEST(EqMatrix, NotEquals2) {
  // Arrange
  int row = 5;
  int cols = 4;
  bool flags1 = false;
  bool flags2 = false;
  S21Matrix First{row, cols};
  S21Matrix Second{cols, cols};

  // Act
  First.setFullValue(3.5);
  Second.setFullValue(3.5);
  flags1 = First.EqMatrix(Second);
  flags2 = Second.EqMatrix(First);

  // Assert
  EXPECT_FALSE(flags1);
  EXPECT_FALSE(flags2);
}

TEST(EqMatrix, NotEquals3) {
  // Arrange
  int row = 5;
  int cols = 13;
  bool flags1 = false;
  bool flags2 = false;
  S21Matrix First{row, cols};
  S21Matrix Second{cols, cols};

  // Act
  First.setFullValue(3.5);
  Second.setFullValue(3.8);
  flags1 = First.EqMatrix(Second);
  flags2 = Second.EqMatrix(First);

  // Assert
  EXPECT_FALSE(flags1);
  EXPECT_FALSE(flags2);
}

TEST(EqMatrix, NotEquals4) {
  // Arrange
  int row = 5;
  int cols = 5;
  bool flags1 = false;
  bool flags2 = false;
  S21Matrix First{row, cols};
  S21Matrix Second{row, cols};

  // Act
  First.setFullValue(3.3);
  Second.setFullValue(3.5);
  flags1 = First.EqMatrix(Second);
  flags2 = Second.EqMatrix(First);

  // Assert
  EXPECT_FALSE(flags1);
  EXPECT_FALSE(flags2);
}

TEST(EqMatrix, NotEquals5) {
  // Arrange
  int row = 5;
  int cols = 5;
  bool flags1 = false;
  bool flags2 = false;
  S21Matrix First{row, cols};
  S21Matrix Second{row, cols};

  // Act
  First.setFullValue(3.5);
  First.setValue(2, 3, 3.6);
  Second.setFullValue(3.5);
  flags1 = First.EqMatrix(Second);
  flags2 = Second.EqMatrix(First);

  // Assert
  EXPECT_FALSE(flags1);
  EXPECT_FALSE(flags2);
}

TEST(EqMatrix, Equals6) {
  // Arrange
  int row = 5;
  int cols = 5;
  bool flags1 = false;
  bool flags2 = false;
  S21Matrix First{row, cols};
  S21Matrix Second{row, cols};

  // Act
  First.setFullValue(3.5);
  Second.setFullValue(3.5);
  flags1 = First.EqMatrix(Second);
  flags2 = Second.EqMatrix(First);

  // Assert
  EXPECT_TRUE(flags1);
  EXPECT_TRUE(flags2);
}

TEST(EqMatrix, Equals7) {
  // Arrange
  int row = 5;
  int cols = 10;
  bool flags1 = false;
  bool flags2 = false;
  S21Matrix First{row, cols};
  S21Matrix Second{row, cols};

  // Act
  First.setFullValue(1.5);
  Second.setFullValue(1.5);
  flags1 = First.EqMatrix(Second);
  flags2 = Second.EqMatrix(First);

  // Assert
  EXPECT_TRUE(flags1);
  EXPECT_TRUE(flags2);
}

TEST(EqMatrix, Equals8) {
  // Arrange
  int row = 10;
  int cols = 10;
  bool flags1 = false;
  bool flags2 = false;
  S21Matrix First{row, cols};
  S21Matrix Second{row, cols};

  // Act
  First.setFullValue(1.5);
  Second.setFullValue(1.5);
  flags1 = First.EqMatrix(Second);
  flags2 = Second.EqMatrix(First);

  // Assert
  EXPECT_TRUE(flags1);
  EXPECT_TRUE(flags2);
}

TEST(EqMatrix, NotEquals7) {
  // Arrange
  int row = 5;
  int cols = 10;
  bool flags1 = false;
  bool flags2 = false;
  S21Matrix First{row, cols};
  S21Matrix Second{row, cols};

  // Act
  First.setFullValue(2.5);
  Second.setFullValue(1.5);
  flags1 = First.EqMatrix(Second);
  flags2 = Second.EqMatrix(First);

  // Assert
  EXPECT_FALSE(flags1);
  EXPECT_FALSE(flags2);
}

TEST(EqMatrix, NotEquals6) {
  // Arrange
  int row = 10;
  int cols = 10;
  bool flags1 = false;
  bool flags2 = false;
  S21Matrix First{row, cols};
  S21Matrix Second{row, cols};

  // Act
  First.setFullValue(1.5);
  First.setValue(2, 4, 6.3);
  Second.setFullValue(1.5);
  flags1 = First.EqMatrix(Second);
  flags2 = Second.EqMatrix(First);

  // Assert
  EXPECT_FALSE(flags1);
  EXPECT_FALSE(flags2);
}