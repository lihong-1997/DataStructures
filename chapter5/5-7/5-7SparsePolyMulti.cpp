#include "polynomialList.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v1 = { 8,12,6,9,1,0 };
    vector<int> v2 = { 3,17,1,14,2,7 };
    Polynomial poly1, poly2;
    CreatePoly(v1, poly1);
    CreatePoly(v2, poly2);
    cout << "poly1 " << poly1 << "  " << poly1.Size() << endl;
    cout << "poly2 " << poly2 << "  " << poly2.Size() << endl;

    Polynomial res, res1, res2;
    res = poly1 * poly2;
    cout << "O(MMN)    :" << res << "  " << res.Size() << endl;
    
    res1 = PolyMulti(poly1, poly2);
    cout << "O(MNlogMN):" << res1 << "  " << res1.Size() << endl;

    res2 = PolyMultiHash(poly1, poly2);
    cout << "O(MN)     :" << res2 << "  " << res2.Size() << endl;

    return 0;
}