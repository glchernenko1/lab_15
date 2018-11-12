//
// Лабораторная работа №14. Абстрактные типы данных. Стек
// main.cpp
//
#include "stack.h"

#include <ctime>
#include <iostream>

using namespace std;

int main()
{
  //  test_d_stack::run();
	// утечка ((
    d_stack s;

	
	
    time_t start = clock() ;

    const int MAX_N = 1000;
    int n = MAX_N;   
    while (n > 0) {        
        int m = 0;
        while (m < MAX_N) {
            s.push(rand());
            m++;
        }
		//cout << s;
        while (m > 0) {
            s.pop();
            m--;
        }
        n--;
    }
    time_t end = clock();
    double seconds = (end - start) * 1.0 / CLOCKS_PER_SEC;
    cout << seconds << endl;
    
	l_stack d;
	start = clock();
	
	 n = MAX_N;
	while (n > 0) {
		int m = 0;
		while (m < MAX_N) {
			d.push(rand());
			m++;
		}
		//cout << d;
		while (m > 0) {
			d.pop();
			m--;
		}
		n--;
	}
	 end = clock();
	 seconds = (end - start) * 1.0 / CLOCKS_PER_SEC;
	cout <<endl<< seconds << endl;

   // _CrtDumpMemoryLeaks();
    system("pause");
    return 0;
}