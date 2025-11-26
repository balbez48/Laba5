#include "WorkFiles.h"

// для 1 и 2 задания
int WorkFiles::CreateBinFile(std::string file1, int n)
{
	ofstream f1(file1, ios::binary, ios::trunc);
	int num = 0;

	if (!f1.is_open()) {
		cout << "error" << endl;
		return 1;
	}

	for (int i = 0; i < n; i++) {
		num = rand() % 10;
		cout << num << " ";
		f1.write((char*)&num, sizeof(num));
	}
	cout << endl;

	f1.close();
	return 0;

}

// для 3 задания
int WorkFiles::CreateBinFile3(std::string file1)
{
	ofstream f1(file1, ios::binary);
	if (!f1.is_open()) {
		cout << "error" << endl;
		return 1;
	}

	Toy toys[] = {
		{"Конструктор", 450.50, 3, 10},
		{"Мяч", 299.99, 1, 7},
		{"Кукла", 850.75, 2, 8},
		{"Пазл", 150.00, 4, 12},
		{"Машинка", 199.50, 1, 5},
		{"Настольная игра", 1200.00, 5, 14},
		{"Кубики", 89.90, 1, 4},
		{"Радиоуправляемая машина", 2500.00, 5, 12},
		{"Мягкая игрушка", 350.25, 0, 3},
		{"Лего", 1800.00, 4, 10}
	};

	int toy_count = sizeof(toys) / sizeof(toys[0]);

	// Записываем игрушки в бинарный файл
	for (int i = 0; i < toy_count; i++) {
		f1.write((char*)&toys[i], sizeof(Toy));
	}

	f1.close();

	cout << "Создан файл с " << toy_count << " игрушками:" << endl;
	for (int i = 0; i < toy_count; i++) {
		cout << toys[i].name << " - " << toys[i].price << " руб., возраст: "
			<< toys[i].min_age << "-" << toys[i].max_age << " лет" << endl;
	}

	return 0;
}

//для 4 задания
int WorkFiles::CreateTxtFile4(std::string file1, int n)
{
	ofstream f1(file1, ios::trunc);
	int num = 0;

	if (!f1.is_open()) {
		cout << "error" << endl;
		return 1;
	}

	for (int i = 0; i < n; i++) {
		num = rand() % 10;
		cout << num << " ";
		f1 << num << endl;
	}
	cout << endl;

	f1.close();
	return 0;

}

//для 5 задания
int WorkFiles::CreateTxtFile5(std::string file1, int n)
{
	ofstream f1(file1, ios::trunc);
	int num = 0;

	if (!f1.is_open()) {
		cout << "error" << endl;
		return 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			num = rand() % 10;
			cout << num << " ";
			f1 << num << " ";
		}
		cout << endl;
		f1 << endl;
	}


	f1.close();
	return 0;

}


//1. Из исходного файла получить новый файл, исключив повторные вхождения чисел.
int WorkFiles::Metod1(std::string file1, std::string file2)
{
	ifstream f1(file1, ios::binary);
	ofstream f2(file2, ios::binary);
	vector<int> all_nums;
	int num = 0;

	if (!f1.is_open()) {
	  cout << "error" << endl;
	  return 1;
	}

	if (!f2.is_open()) {
	  cout << "error" << endl;
	  return 1;
	}

	while (f1.read((char*)&num, sizeof(num))) {
	  all_nums.push_back(num);
	}

	cout << "результат: ";
	set<int> uniq_nums(all_nums.begin(), all_nums.end());
	for (int num : uniq_nums) {
		cout << num << " ";
		f2.write((char*)&num, sizeof(num));
	}
	cout << endl;

	f1.close();
	f2.close();
	return 0;
}

//2. Скопировать элементы заданного файла в квадратную матрицу размером n×n (если элементов 
//файла недостает, заполнить оставшиеся элементы матрицы нулями).Заменить все строки
//таблицы на строку с максимальным произведением элементов.
int WorkFiles::Metod2(std::string file1, int n)
{
	ifstream f1(file1, ios::binary);
	if (!f1.is_open()) {
		cout << "error" << endl;
		return 1;
	}

	vector<int> data;
	int num = 0;
	while (f1.read((char*)&num, sizeof(num))) {
		data.push_back(num);
	}
	f1.close();

	vector<vector<int>> matrix(n, vector<int>(n, 0));

	int index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (index < data.size()) {
				matrix[i][j] = data[index];
				index++;
			}
		}
	}

	cout << "Результат до преобразования:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	int max_str = 0;
	int max_prod = 1;

	for (int i = 0; i < n; i++) {
		int prod = 1;
		for (int j = 0; j < n; j++) {
			prod *= matrix[i][j];
		}
		if (prod > max_prod) {
			max_prod = prod;
			max_str = i;
		}
	}

	for (int i = 0; i < n; i++) {
		if (i != max_str) {
			matrix[i] = matrix[max_str];
		}
	}

	cout << "Результат после нахождения макс строки:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;


}



//3. Файл содержит сведения об игрушках: название игрушки, ее стоимость в рублях и возрастные 
//границы(например, игрушка может предназначаться для детей от двух до пяти лет).Получить
//название игрушек, цена которых не превышает k руб.и которые подходят детям 5 лет.
int WorkFiles::Metod3(std::string file1, std::string file2, int k)
{
	ifstream f1(file1, ios::binary);
	ofstream f2(file2, ios::trunc);

	if (!f1.is_open()) {
		cout << "error" << endl;
		return 1;
	}

	if (!f2.is_open()) {
		cout << "error" << endl;
		return 1;
	}

	vector<string> suitable_toys;
	Toy toy;

	cout << "Поиск игрушек до " << k << " руб. для детей 5 лет:" << endl;

	while (f1.read((char*)&toy, sizeof(Toy))) {
		if (toy.price <= k && toy.min_age <= 5 && toy.max_age >= 5) {
			suitable_toys.push_back(toy.name);
			f2 << toy.name << endl;

			cout << "Найдено: " << toy.name << " - " << toy.price
				<< " руб., возраст: " << toy.min_age << "-" << toy.max_age << " лет" << endl;
		}
	}

	f1.close();
	f2.close();

	return 0;
}



//4. Для заданного файла возвратить true, если он содержит заданное число b, и false в противном случае.
int WorkFiles::Metod4(std::string file1, int b)
{
	ifstream f1(file1);
	int num = 0;

	if (!f1.is_open()) {
	  cout << "error" << endl;
	  return 1;
	}

	while (f1 >> num) {
	  if (num == b) {
		f1.close();
		return true;
	  }
	}
	f1.close();
	return false;
}


//5. Вычислить сумму элементов, которые кратны заданному числу k.
int WorkFiles::Metod5(std::string file1, int k)
{
	ifstream f1(file1);
	if (!f1.is_open()) {
		cout << "error" << endl;
		return 1;
	}

	int sum = 0;
	int num = 0;
	int cnt = 0;

	cout << "Числа кратные " << k << ": ";

	while (f1 >> num) {
		if (num % k == 0) { 
			sum += num;
			cnt++;
			cout << num << " ";
		}
	}

	f1.close();

	cout << endl;
	cout << "Найдено кратных чисел: " << cnt << endl;
	cout << "Сумма чисел кратных " << k << ": " << sum << endl;

	return 0;
}

//6. Переписать в другой файл строки, в которых нет цифр. 
int WorkFiles::Metod6(std::string file1, std::string file2)
{
	ifstream f1(file1);
	ofstream f2(file2, ios::trunc);
	string str = "";
	

	if (!f1.is_open()) {
		cout << "error" << endl;
		return 1;
	}

	if (!f2.is_open()) {
		cout << "error" << endl;
		return 1;
	}

	bool flag = 1;
	while (f1 >> str) {
		flag = 1;
		for (int i = 0; i < str.length(); i++) {
			if (isdigit(str[i])) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			cout << "Записанная в файл строка: " << str << endl;
			f2 << str << endl;
		}
	}

	f1.close();
	f2.close();
	return 0;
}
