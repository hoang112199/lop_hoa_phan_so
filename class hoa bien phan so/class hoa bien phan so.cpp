#include<iostream>

using namespace std;

class PS
{
private:
	int a, b;
public:
    friend ostream& operator<< (ostream& os, PS p)
    {
        os << p.a << "/" << p.b;
        return os;
    }
    friend istream& operator>>	(istream& is, PS& p)
    {
        cout << "\nTu va Mau: ";
        is >> p.a >> p.b;
        return is;
    }
    static int ucln(int x, int y)
    {
        if (y == 0)return x;
        return ucln(y, x % y);
    }
    static PS rutgon(PS p)
    {
        int m = ucln(p.a, p.b);
        p.a = p.a / m;
        p.b = p.b / m;
        return p;
    }
	friend PS operator+(PS p1, PS p2)
	{
        PS p;
        int g = p1.b;
        int h = p2.b;
        p1.a = p1.a * h;
        p1.b = p1.b * h;
        p2.a = p2.a * g;
        p2.b = p2.b * g;
        p.a = p1.a + p2.a;
        p.b = p1.b;
        p = rutgon(p);
        return p;
	}
    friend PS operator-(PS p1, PS p2)
    {
        PS p;
        int g = p1.b;
        int h = p2.b;
        p1.a = p1.a * h;
        p1.b = p1.b * h;
        p2.a = p2.a * g;
        p2.b = p2.b * g;
        p.a = p1.a - p2.a;
        p.b = p1.b;
        p = rutgon(p);
        return p;
    }
    friend PS operator*(PS p1, PS p2)
    {
        PS p;
        p.a = p1.a * p2.a;
        p.b = p1.b * p2.b;
        p = rutgon(p);
        return p;
    }
    friend PS operator/(PS p1, PS p2)
    {
        PS p;
        p.a = p1.a * p2.b;
        p.b = p1.b * p2.a;
        p = rutgon(p);
        return p;
    }

};
int main()
{
    PS p, q, z, u, v;

    PS s;

    cout << "\nNhap cac phan so p, q, z, u, v\n";

    cin >> p >> q >> z >> u >> v;

    s = (p - q * z) / (u + v);

    cout << "\n Phan so s = " << s;
}
