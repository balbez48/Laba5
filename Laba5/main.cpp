#include "WorkFiles.h"


int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    WorkFiles obj;
    bool flag = true;
    std::cout << "Вариант 5. Номера заданий 1-6." << std::endl;
    while (flag) {

        
        int action = 0;
        std::cout << "\nВведите номер задания: ";
        std::cin >> action;

        if (action == -1) { break; }

        switch (action) {

          case 1: {
            int n = 0;
            bool f = 1;
            cout << "Введите количество элементов в бинарном файле: ";
            while (f) {
                std::cin >> n;
                if (n > 0) {
                    f = 0;
                }
                else {
                    std::cout << "Число должно быть положительным. Попробуйте снова: ";
                }
            }

            obj.CreateBinFile("1.txt", n);
            obj.Metod1("1.txt", "2.txt");
            break;
          }
          case 2: {
              int n1 = 0;
              bool f = 1;
              cout << "Введите количество элементов в бинарном файле: ";
              while (f) {
                  std::cin >> n1;
                  if (n1 > 0) {
                      f = 0;
                  }
                  else {
                      std::cout << "Число должно быть положительным. Попробуйте снова: ";
                  }
              }

              f = 1;
              int n2 = 0;
              cout << "Введите разменость матрицы: ";
              while (f) {
                  std::cin >> n2;
                  if (n1 > 0) {
                      f = 0;
                  }
                  else {
                      std::cout << "Число должно быть положительным. Попробуйте снова: ";
                  }
              }

              obj.CreateBinFile("1.txt", n1);
              obj.Metod2("1.txt", n2);
              break;
          }
          case 3: {
              obj.CreateBinFile3("1.txt");
              obj.Metod3("1.txt", "2.txt", 1000);
            break;
          }
          case 4: {
              int n1 = 0;
              bool f = 1;
              cout << "Введите количество элементов в текстовом файле: ";
              while (f) {
                  std::cin >> n1;
                  if (n1 > 0) {
                      f = 0;
                  }
                  else {
                      std::cout << "Число должно быть положительным. Попробуйте снова: ";
                  }
              }

              f = 1;
              int n2 = 0;
              cout << "Введите число b: ";
              while (f) {
                  std::cin >> n2;
                  if (n1 > 0) {
                      f = 0;
                  }
                  else {
                      std::cout << "Число должно быть положительным. Попробуйте снова: ";
                  }
              }

              obj.CreateTxtFile4("1.txt", n1);
              cout << "Нашлось ли вхождение числа b? " << (obj.Metod4("1.txt", n2) ? "true" : "false") << endl;
            break;
          }
          case 5: {
              int n1 = 0;
              bool f = 1;
              cout << "Введите длину строк в текстовом файле: ";
              while (f) {
                  std::cin >> n1;
                  if (n1 > 0) {
                      f = 0;
                  }
                  else {
                      std::cout << "Число должно быть положительным. Попробуйте снова: ";
                  }
              }

              f = 1;
              int n2 = 0;
              cout << "Введите число k: ";
              while (f) {
                  std::cin >> n2;
                  if (n1 > 0) {
                      f = 0;
                  }
                  else {
                      std::cout << "Число должно быть положительным. Попробуйте снова: ";
                  }
              }

              obj.CreateTxtFile5("1.txt", n1);
              obj.Metod5("1.txt", n2);
            break;
          }
          case 6: {
              obj.Metod6("text.txt", "NewText.txt");
            break;
          }
          default: {
            std::cout << "Такого метода нет" << std::endl;
            break;
          }
        }
    }

    return 0;
}