#include "string.h"

int main()
{
String s1;
String s2("Hello");
String s3("World");

cout << "s1 = " << s1 << endl;
cout << "s2 = " << s2 << endl;
cout << "s3 = " << s3 << endl;

// Copy constructor
String s4(s2);
cout << "\nCopy : " << s4 << endl;

// Assignment
s1 = s3;
cout << "Assignment : " << s1 << endl;

// + operator
String s5 = s2 + s3;
cout << "Addition : " << s5 << endl;

// [] operator
cout << "s2[1] : " << s2[1] << endl;

// Comparison
cout << "\nComparisons\n";
cout << "s2 > s3  : " << (s2 > s3) << endl;
cout << "s2 < s3  : " << (s2 < s3) << endl;
cout << "s2 == s3 : " << (s2 == s3) << endl;

// Input
String s6;
cout << "\nEnter string : ";
cin >> s6;
cout << "You entered : " << s6 << endl;

// String functions
String a("Hello");
String b("World");

strcat(a,b);
cout << "\nstrcat : " << a << endl;

cout << "strcmp : " << strcmp(s2,s3) << endl;

strrev(a);
cout << "strrev : " << a << endl;

strupr(a);
cout << "strupr : " << a << endl;

strlwr(a);
cout << "strlwr : " << a << endl;

char *p = strstr(s5,s3);
if(p)
    cout << "strstr : " << p << endl;

cout << "strlen : " << strlen(s5) << endl;

return 0;

}

