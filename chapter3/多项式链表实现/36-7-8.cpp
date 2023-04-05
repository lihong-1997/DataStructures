#include "polynomialList.h"
#include <iostream>
#include<windows.h>  

using namespace std;

int main55()
{
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;

	Polynomial poly1, poly2;
	cin >> poly1;
	cin >> poly2;
	cout << poly1 << '\n' << poly2 << endl;
	cout << "poly1+poly2: " << poly1 + poly2 << endl;
	cout << "poly1*poly2: " << poly1 * poly2 << endl;

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	cout << "poly1**3: " << polypower(poly1, 10) << endl;
	QueryPerformanceCounter(&nEndTime);
	LONGLONG time = (nEndTime.QuadPart - nBeginTime.QuadPart) * 1000000 / nFreq.QuadPart;
	cout << "time1(us):" << time << endl;

	QueryPerformanceCounter(&nBeginTime);
	cout << "poly1**3: " << polypower2(poly1, 10) << endl;
	QueryPerformanceCounter(&nEndTime);
	time = (nEndTime.QuadPart - nBeginTime.QuadPart) * 1000000 / nFreq.QuadPart;
	cout << "time2(us):" << time << endl;

	return 0;
}