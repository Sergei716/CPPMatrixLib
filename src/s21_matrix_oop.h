#ifndef S21Matrix_SRC_S21_MATRIX_OOP_H_
#define S21Matrix_SRC_S21_MATRIX_OOP_H_

#include <cmath>
#include <iostream>
#include <new>

class S21Matrix {
 public:
  S21Matrix();
  S21Matrix(int rows, int cols);

  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);

  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other);

  ~S21Matrix();

  bool operator==(const S21Matrix& other) const;
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator*(const double value) const;
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double value);
  void MulMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  bool EqMatrix(const S21Matrix& other) const;
  double& operator()(int row, int col);
  const double& operator()(int row, int col) const;
  S21Matrix Transpose() const;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix();
  void FindMinor(S21Matrix& other, int skip_row, int skip_col, int size) const;
  double FindAlg(int size) const;

  void setFullValue(double value);
  void setValue(int rows, int cols, double value);
  double getValue(int rows, int cols) const;

  void InitMatrix(double value);
  void setGen();
  void setAntiGen();

 private:
  int rows_, cols_;
  double** matrix_;
};

#endif  // S21Matrix_SRC_S21_MATRIX_OOP_H_
