#include "funch.h"


int main()
{
Hora h1(86399), h2(3601), h3;
cout << "h1 debe decir 23:59:59 - dice: <" << h1 << ">" << endl;
cout << "h2 debe decir 1:0:1 - dice: <" << h2 << ">" << endl;
h3 = h1 + h2;
cout << "h3 debe decir 1:0:0 - dice: <" << h3 << ">" << endl;
Hora h4(172799), h5(h3);
cout << "h4 debe decir 0:0:0 - dice: <" << ++h4 << ">" << endl;
cin >> h4;
cout << h4;
return 0;
}
