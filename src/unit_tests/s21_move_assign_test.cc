#include "s21_matrix_test.h"

TEST(MoveAssignMatrix, Example1) {
  // Arrange
  int size = 3;
  int q = 1;
  S21Matrix First{size, size};
  S21Matrix Second{size, size};

  // Act
  First.setGen();
  std::swap(First, Second);

  // Assert
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j) EXPECT_DOUBLE_EQ(Second(i, j), q++);
}

TEST(MoveAssignMatrix, Example2) {
  // Arrange
  int size = 3;
  int q = 32;
  S21Matrix First{size, size};
  S21Matrix Second{size, size};

  // Act
  First.setAntiGen();
  std::swap(First, Second);

  // Assert
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j) EXPECT_DOUBLE_EQ(Second(i, j), q--);
}

TEST(MoveAssignMatrix, Example3) {
  // Arrange
  int size = 3;
  S21Matrix First{size, size};
  S21Matrix Second{size, size};

  // Act
  First(1, 1) = 156.32;
  std::swap(First, Second);

  // Assert
  EXPECT_DOUBLE_EQ(Second(1, 1), 156.32);
}