#include <iostream>
#include "../StaticLibSet/Set.h"
#include <locale.h>

using namespace std;

int main()
{

    cout << "Task 3" << endl;

    Set<char> set1;
    Set<char> set2;
    Set<char> set3;
    cout << "Input string" << endl;
    std::string str;
    cin >> str;

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

    cout << "String: " << str << endl;
    cout << "1. the first occurrence of each letter, preserving their initial order : " << set1 << endl;
    cout << "2. all letters that appear at least twice in a string : " << set2 << endl;
    cout << "3. all letters that appear only once : " << set3 << endl;
	
    
    cout << endl << "Task 4" << endl;
    int n;
	cout << "Input number: ";
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
	cout << "Prime numbers from 2 to " << n << ": " << set4 << endl;

	return 0;   
    


}


