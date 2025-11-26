#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <ctime>
#include <cstdlib>
#include <cctype>
using namespace std;
#pragma once

struct Toy {
	char name[50];
	double price;
	int min_age;
	int max_age;
};

class WorkFiles {
public:
	int CreateBinFile(std::string file1, int n);
	int Metod1(std::string file1, std::string file2);
	int Metod2(std::string file1, int n);
	int CreateBinFile3(std::string file1);
	int Metod3(std::string file1, int k);
	int CreateTxtFile4(std::string file1, int n);
	int Metod4(std::string file1, int b);
	int CreateTxtFile5(std::string file1, int n);
	int Metod5(std::string file1, int k);
	int Metod6(std::string file1, std::string file2);

	//1. Из исходного файла получить новый файл, исключив повторные вхождения чисел. 
	//2. Скопировать элементы заданного файла в квадратную матрицу размером n×n (если элементов 
	//файла недостает, заполнить оставшиеся элементы матрицы нулями).Заменить все строки
	//таблицы на строку с максимальным произведением элементов.
	//3. Файл содержит сведения об игрушках: название игрушки, ее стоимость в рублях и возрастные 
	//границы(например, игрушка может предназначаться для детей от двух до пяти лет).Получить
	//название игрушек, цена которых не превышает k руб.и которые подходят детям 5 лет.
	//4. Для заданного файла возвратить true, если он содержит заданное число b, и false в противном случае.
	//5. Вычислить сумму элементов, которые кратны заданному числу k. 
	//6. Переписать в другой файл строки, в которых нет цифр. 
};