#include <iostream>
#include "../StaticLibSet/Set.h"
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    //Задача 3
    cout << "Задача 3";

    Set<char> set1;
    Set<char> set2;
    Set<char> set3;
    std::string str = "abracadabra";
    for (int i = 0; i < str.size(); i++)
    {
        if (!set1.contains(str[i]))
        {
			set1.add(str[i]);
		}
        else
        {
			set2.add(str[i]);
		}
	}

    set3 = set1.subtract(set2);

    //Вывести 
    cout << "Строка: " << str << endl;
    cout << "1. первое вхождение каждой буквы с сохранением их начального порядка : " << set1 << endl;
    cout << "2. все буквы, которые встречаются в строке не менее двух раз : " << set2 << endl;
    cout << "3. все буквы, которые встречаются только один раз : " << set3 << endl;
	

    //Задача 4
    /*Задано натуральное п. Найти все простые числа из промежутка [2; n] с помощью решета Эратосфена. Суть метода:
1. Записать все числа от 2 до п;
2. Оставить в записи первое простое число, т.е. 2, и вычеркнуть из записи все кратные ему (4, 6, 8, ...)
3. Оставить в записи первое простое число, т.е. 3, и вычеркнуть из записи все кратные ему (6, 9, 12, ...)
4. Оставить в записи первое простое число, т.е. 5, и вычеркнуть из записи все кратные ему... Повторять до конца последовательности.*/
    
    cout << endl << "Задача 4" << endl;
    int n;
	cout << "Введите число: ";
	cin >> n;
	Set<int> set4;
    for (int i = 2; i <= n; i++)
    {
		set4.add(i);
	}
    for (int i = 2; i <= n; i++)
    {
        if (set4.contains(i))
        {
            for (int j = i * i; j <= n; j += i)
            {
				set4.remove(j);
			}
		}
	}
	cout << "Простые числа от 2 до " << n << ": " << set4 << endl;

	return 0;   
    


}


