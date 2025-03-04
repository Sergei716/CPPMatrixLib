#include "s21_matrix_test.h"

TEST(GetValue, Equals1) {
  // Arrange
  int size = 4;
  int q = 1;
  S21Matrix First{size, size};

  // Act
  First.setGen();

  // Assert
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j) EXPECT_DOUBLE_EQ(First.getValue(i, j), q++);
}

TEST(GetValue, Equals2) {
  // Arrange
  int size = 4;
  int k = 32;
  S21Matrix Second{size, size};

  // Act
  Second.setAntiGen();

  // Assert
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j) EXPECT_DOUBLE_EQ(Second.getValue(i, j), k--);
}

TEST(SetValue, Equals3) {
  // Arrange
  int size = 4;
  int q = 1;
  int k = 1;
  S21Matrix First{size, size};

  // Act
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j) First.setValue(i, j, k++);

  // Assert
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j) EXPECT_DOUBLE_EQ(First(i, j), q++);
}

TEST(SetValue, Equals4) {
  // Arrange
  int size = 4;
  int k = 32;
  int q = 32;
  S21Matrix Second{size, size};

  // Act
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j) Second.setValue(i, j, k--);

  // Assert
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j) EXPECT_DOUBLE_EQ(Second(i, j), q--);
}

TEST(SetValue, Exception1) {
  // Arrange
  int size = 4;
  S21Matrix First{size, size};

  // Act

  // Assert
  EXPECT_ANY_THROW(First.setValue(-1, 0, 3));
}

TEST(SetValue, Exception2) {
  // Arrange
  int size = 4;
  S21Matrix First{size, size};

  // Act

  // Assert
  EXPECT_ANY_THROW(First.setValue(1, 4, 3));
}

TEST(GetValue, Exception1) {
  // Arrange
  int size = 4;
  S21Matrix Second{size, size};

  // Act

  // Assert
  EXPECT_ANY_THROW(Second.getValue(-1, 0));
}

TEST(GetValue, Exception2) {
  // Arrange
  int size = 4;
  S21Matrix Second{size, size};

  // Act

  // Assert
  EXPECT_ANY_THROW(Second.getValue(1, 5));
}