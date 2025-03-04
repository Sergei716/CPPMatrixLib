#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(1), cols_(1) {
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; ++i) matrix_[i] = new double[cols_];
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; ++i) matrix_[i] = new double[cols_];
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; ++i) matrix_[i] = new double[cols_];

  for (int i = 0; i != rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] = other.matrix_[i][j];
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this == &other) return *this;
  for (int i = 0; i < rows_; ++i) {
    delete[] matrix_[i];
  }
  delete[] matrix_;

  rows_ = other.rows_;
  cols_ = other.cols_;

  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; ++i) matrix_[i] = new double[cols_];

  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] = other.matrix_[i][j];

  return *this;
}

S21Matrix::S21Matrix(S21Matrix&& other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) {
  if (this == &other) return *this;
  std::swap(matrix_, other.matrix_);
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
  return *this;
}

S21Matrix::~S21Matrix() {
  for (int i = 0; i < rows_; ++i) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
}

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  bool flags = true;
  if (other.rows_ != rows_ || other.cols_ != cols_) flags = false;
  for (int i = 0; i < rows_ && flags; ++i)
    for (int j = 0; j < cols_ && flags; ++j)
      if (std::fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-7) flags = false;
  return flags;
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  return this->EqMatrix(other);
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] *= num;
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::out_of_range(
        "The number of columns of the first matrix is not \
				equal to the number of rows of the second matrix.");
  }
  S21Matrix Res{rows_, other.cols_};
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < other.cols_; ++j)
      for (int k = 0; k < other.rows_; ++k)
        Res.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
  *this = Res;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range("Different matrix dimensions.");
  }
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] += other.matrix_[i][j];
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range("Different matrix dimensions.");
  }
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] -= other.matrix_[i][j];
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double value) {
  this->MulNumber(value);
  return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix Res(*this);
  Res.MulMatrix(other);
  return Res;
}

S21Matrix S21Matrix::operator*(const double value) const {
  S21Matrix Res(*this);
  Res.MulNumber(value);
  return Res;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix Res(*this);
  Res.SumMatrix(other);
  return Res;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix Res(*this);
  Res.SubMatrix(other);
  return Res;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);
  return *this;
}

double& S21Matrix::operator()(int row, int col) {
  if (rows_ <= row || cols_ <= col || col < 0 || row < 0)
    throw std::out_of_range("Incorrect input, index is out of range");
  return matrix_[row][col];
}

const double& S21Matrix::operator()(int row, int col) const {
  if (rows_ <= row || cols_ <= col || col < 0 || row < 0)
    throw std::out_of_range("Incorrect input, index is out of range");
  return matrix_[row][col];
}

S21Matrix S21Matrix::Transpose() const {
  S21Matrix Res{cols_, rows_};
  for (int i = 0; i < cols_; ++i)
    for (int j = 0; j < rows_; ++j) Res.matrix_[i][j] = matrix_[j][i];

  return Res;
}

void S21Matrix::FindMinor(S21Matrix& other, int skip_row, int skip_col,
                          int size) const {
  for (int i = 0, row = 0; row < size; ++row) {
    for (int j = 0, col = 0; col < size; ++col) {
      if (row != skip_row && col != skip_col) {
        other.matrix_[i][j] = matrix_[row][col];
        j++;
        if (j == size - 1) {
          j = 0;
          i++;
        }
      }
    }
  }
}

double S21Matrix::FindAlg(int size) const {
  double res = 0;
  if (size == 1) res = matrix_[0][0];

  S21Matrix Tmp{size, size};
  int sign = 1;
  for (int i = 0; i < size; ++i) {
    this->FindMinor(Tmp, 0, i, size);
    res += sign * matrix_[0][i] * Tmp.FindAlg(size - 1);
    sign = -sign;
  }
  return res;
}

S21Matrix S21Matrix::CalcComplements() const {
  if (rows_ != cols_) throw std::out_of_range("The matrix is not square.");
  S21Matrix Res(rows_, cols_);
  if (rows_ == 1)
    Res.matrix_[0][0] = 1;
  else {
    S21Matrix Tmp{rows_, cols_};
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        this->FindMinor(Tmp, i, j, rows_);
        int sign = ((i + j) % 2 == 0) ? 1 : -1;
        Res.matrix_[i][j] = sign * Tmp.FindAlg(rows_ - 1);
      }
    }
  }
  return Res;
}

double S21Matrix::Determinant() const {
  double result = 0.0;
  if (rows_ != cols_) {
    throw std::out_of_range("The matrix is not square.");
  }
  if (rows_ == 1) {
    result = matrix_[0][0];
  } else {
    result = this->FindAlg(rows_);
  }

  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  double d = this->Determinant();
  if (d == 0) throw std::out_of_range("Matrix determinant is 0");
  S21Matrix Result{rows_, cols_};
  S21Matrix Tmp = this->CalcComplements();
  S21Matrix Tran = Tmp.Transpose();
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < rows_; ++j)
      Result.matrix_[i][j] = Tran.matrix_[i][j] / d;

  return Result;
}

void S21Matrix::setGen() {
  int q = 1;
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] = q++;
}

void S21Matrix::InitMatrix(double value) {
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; value += 1.0, ++j) matrix_[i][j] = value;
}

void S21Matrix::setAntiGen() {
  int q = 32;
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] = q--;
}

void S21Matrix::setFullValue(double value) {
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] = value;
}

void S21Matrix::setValue(int rows, int cols, double value) {
  if (rows < 0 || rows >= rows_ || cols < 0 || cols >= cols_)
    throw std::out_of_range("Incorrect input, index is out of range");
  matrix_[rows][cols] = value;
}

double S21Matrix::getValue(int rows, int cols) const {
  if (rows < 0 || rows >= rows_ || cols < 0 || cols >= cols_)
    throw std::out_of_range("Incorrect input, index is out of range");
  return matrix_[rows][cols];
}
