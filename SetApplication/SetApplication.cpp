#include <iostream>
#include "../StaticLibSet/Set.h"
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    //������ 3
    cout << "������ 3";

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

    //������� 
    cout << "������: " << str << endl;
    cout << "1. ������ ��������� ������ ����� � ����������� �� ���������� ������� : " << set1 << endl;
    cout << "2. ��� �����, ������� ����������� � ������ �� ����� ���� ��� : " << set2 << endl;
    cout << "3. ��� �����, ������� ����������� ������ ���� ��� : " << set3 << endl;
	

    //������ 4
    /*������ ����������� �. ����� ��� ������� ����� �� ���������� [2; n] � ������� ������ ����������. ���� ������:
1. �������� ��� ����� �� 2 �� �;
2. �������� � ������ ������ ������� �����, �.�. 2, � ���������� �� ������ ��� ������� ��� (4, 6, 8, ...)
3. �������� � ������ ������ ������� �����, �.�. 3, � ���������� �� ������ ��� ������� ��� (6, 9, 12, ...)
4. �������� � ������ ������ ������� �����, �.�. 5, � ���������� �� ������ ��� ������� ���... ��������� �� ����� ������������������.*/
    
    cout << endl << "������ 4" << endl;
    int n;
	cout << "������� �����: ";
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
	cout << "������� ����� �� 2 �� " << n << ": " << set4 << endl;

	return 0;   
    


}


