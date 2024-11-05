#include <iostream>

class matrix {
private:
  int m;
  int n;
  int** data;

public:
  // Конструктор с размерами матрицы
  matrix(int m, int n) : m(m), n(n) {
    data = new int* [m];
    for (int i = 0; i < m; ++i) {
      data[i] = new int[n]();
    }
  }

  // Конструктор копирования
  matrix(const matrix& other) : m(other.m), n(other.n) {
    data = new int* [m];
    for (int i = 0; i < m; ++i) {
      data[i] = new int[n];
      for (int j = 0; j < n; ++j) {
        data[i][j] = other.data[i][j];
      }
    }
  }

  // Деструктор
  ~matrix() {
    for (int i = 0; i < m; ++i) {
      delete[] data[i];
    }
    delete[] data;
  }

  // Метод для получения количества строк
  int getRows() const {
    return m;
  }

  // Метод для получения количества столбцов
  int getCols() const {
    return n;
  }

  // Метод для заполнения матрицы значением
  void fill(int value) {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        data[i][j] = value;
      }
    }
  }

  // Метод для изменения размеров матрицы
  void resize(int newM, int newN) {
    int** newData = new int* [newM];
    for (int i = 0; i < newM; ++i) {
      newData[i] = new int[newN]();
    }
    for (int i = 0; i < std::min(m, newM); ++i) {
      for (int j = 0; j < std::min(n, newN); ++j) {
        newData[i][j] = data[i][j];
      }
    }
    for (int i = 0; i < m; ++i) {
      delete[] data[i];
    }
    delete[] data;
    data = newData;
    m = newM;
    n = newN;
  }

  // Метод для вывода матрицы (просто так)
  void print() const {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        std::cout << data[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }
};

int main() {
  matrix mat(3, 3);
  mat.fill(5);
  mat.print();
  std::cout << "Resizing matrix to 2x4..." << std::endl;
  mat.resize(2, 4);
  mat.print();
  std::cout << "Rows: " << mat.getRows() << ", Columns: " << mat.getCols() << std::endl;
  matrix matCopy = mat;
  std::cout << "Copied matrix:" << std::endl;
  matCopy.print();
  return 0;
}
