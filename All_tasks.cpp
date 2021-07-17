#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <set>
#include <cstdlib>
#include <string>
#include <string.h>

using namespace std;

long long int toInt(string a)
{
    long long int res = 0;
        for (char i : a) {
            res *= 10;
            res += int(i) - 48;
        }
    return res;
}

long long int toTen(long long int a)
{
    long long int s = 0;
    for (long long int i = 0; a; i++)
    {
        s += long long int(a % 10 * pow(2.0, i));
        a /= 10;
    }
    //system("pause");
    return s;
}

long long int toBin(long long int v)
{
    if (v < 2)
        return v;
    else
        return toBin(v / 2) * 10 + v % 2;
}

int count_num(string a, char b)
{
    int c = 0;
    for (auto i : a)
    {
        if (i == b) c++;
    }
    return c;
}

//---------------------------------------------------------------- Task 1 ----------------------------------------------------------------

static set <int> array_1;

static int f_1(int a, int n)
{
    if (n > 7) return 0;
    if (n == 7) ::array_1.insert(a);
    int k = 1;
    int sl, pr;
    while (true)
    {
        if (sqrt(a + k) == float(int(sqrt(a + k))))
        {
            sl = int(sqrt(a + k));
            break;
        }
        k++;
    }
    while (true)
    {
        if (sqrt(a - k) == float(int(sqrt(a - k))))
        {
            pr = int(sqrt(a - k));
            break;
        }
        k++;
    }
    int f = a;
    int sc = 0;
    while (f != 0) {
        sc += f % 10;
        f /= 10;
    }
    f_1(a + 1, n + 1);
    if (sqrt(a) == float(int(sqrt(a))))
    {
        f_1(a + 1, n + 1);
    }
    else
    {
        f_1(a - pr + sl, n + 1);
    }
    f_1(a + sc, n + 1);
}

int task1()
{
    f_1(7, 0);
    int k = 0;
    for (auto i : ::array_1)
    {
        //cout << i << "\n";
        k += 1;
    }
    return k;
}

//---------------------------------------------------------------- Task 2 ----------------------------------------------------------------

static int f_2(int a, int b, int k)
{
    if (a > b or a == 222) return 0;
    if (a == b) return 1;
    if (a < b) {
        string s = to_string(a) + to_string(int(pow(a, 2)) % 3);
        return f_2(a + 1, b, k + 1) + f_2(a + (a - 1) - k % 16, b, k + 1) + f_2(toInt(s), b, k + 1);
    }
}

int task2()
{
    return f_2(123, 321, 0);
}

//---------------------------------------------------------------- Task 3 ----------------------------------------------------------------

static int f_3(int a, int b)
{
    if (a < b or a == 19) return 0;
    if (a == b) return 1;
    if (a > b) return f_3(a - 1, b) + f_3(a - 3, b) + f_3(a - 11, b);
}

int task3()
{
    return f_3(32, 25) * f_3(25, 16);
}

//---------------------------------------------------------------- Task 4 ----------------------------------------------------------------

static int f_4(int a, int b)
{
    if (a > b or a == 220) return 0;
    if (a == b) return 1;
    if (a < b) {
        string s = to_string(a) + to_string(a)[to_string(a).size()-1];
        return f_4(a + 1, b) + f_4(a * 2, b) + f_4(toInt(s), b);
    }
}

int task4()
{
    return f_4(3, 110) * f_4(110, 333);
}

//---------------------------------------------------------------- Task 5 ----------------------------------------------------------------

static int f_5(int a, int b)
{
    if (toTen(a) > toTen(b) or a == toBin(74)) return 0;
    if (toTen(a) == toTen(b)) return 1;
    int s;
    if (toTen(a) < toTen(b))
        if (count_num(to_string(a), '1') % 2 == 0)
            s = toInt(to_string(a) + "0");
        else
            s = toInt(to_string(a) + "1");
    return f_5(toBin(toTen(a) + 1), b) + f_5(toBin(toTen(a) * 3), b) + f_5(s, b);
}

int task5()
{
    return f_5(111, toBin(60)) * f_5(toBin(60), 1111111);
}

//---------------------------------------------------------------- Task 6 ----------------------------------------------------------------

static set <int> array_6;

static int f_6(int a, int n)
{
    if (n > 5) return 0;
    if (n == 5) ::array_6.insert(a);
    f_6(a + 1, n + 1);
    f_6(a * 3 / 2, n + 1);
    int t = 0;
    int f = a;
    int sc = 0;
    while (f != 0) {
        sc += f % 10;
        f /= 10;
    }
    f_6(a + sc * 4, n + 1);
}

int task6()
{
    f_6(7, 0);
    int k = 0;
    for (auto i : ::array_6)
    {
        //cout << i << "\n";
        k += 1;
    }
    return k;
}
//---------------------------------------------------------------- Task 7 ----------------------------------------------------------------

static set <long long int> array_7;

static long long int f_7(long long int a, int k)
{
    if (k > 15) return 0;
    if (k == 15) ::array_7.insert(a);
    f_7(toBin(toTen(a) - 1), k + 1);
    if (sqrt(toTen(a)) == long double(long long int(sqrt(toTen(a)))))
        f_7(toBin(long long int(sqrt(toTen(a)))), k + 1);
    if (to_string(a)[1] == '1')
        f_7(toInt(to_string(a).substr(1)), k + 1);
} 

int task7()
{
    string a;
    a = "100000000000000000";
    f_7(toInt(a), 0);
    int k = 0;
    for (auto i : ::array_7) 
    {
        //cout << i << "\n";
        k += 1;
    }
    //cout << k;
    return k;
}

//---------------------------------------------------------------- Main ----------------------------------------------------------------

int main()
{
    cout << "Task 1: " << task1() << "\n";
    cout << "Task 2: " << task2() << "\n";
    cout << "Task 3: " << task3() << "\n";
    cout << "Task 4: " << task4() << "\n";
    cout << "Task 5: " << task5() << "\n";
    cout << "Task 6: " << task6() << "\n";
    cout << "Task 7: " << task7() << "\n";
}