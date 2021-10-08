// 1064. 평행사변형
// S5

#include <iostream>
#include <cmath>
using namespace std;

double Max(double a, double b, double c)
{
    double max = a;
    if (max < b)
    {
        if (b < c)
            max = c;
        else
            max = b;
    }
    else if (max < c)
        max = c;

    return max;
}

double Min(double a, double b, double c)
{
    double min = a;
    if (min > b)
    {
        if (b > c)
            min = c;
        else
            min = b;
    }
    else if (min > c)
        min = c;

    return min;
}

int main()
{
    int Ax, Ay, Bx, By, Cx, Cy;
    cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy;

    if ((By - Ay) * (Cx - Bx) == (Cy - By) * (Bx - Ax))
    {
        double temp = -1;
        cout << temp;
        return 0;
    }

    double a, b, c;

    a = sqrt(pow((Bx - Cx), 2) + pow((By - Cy), 2));
    b = sqrt(pow((Ax - Cx), 2) + pow((Ay - Cy), 2));
    c = sqrt(pow((Bx - Ax), 2) + pow((By - Ay), 2));

    double max = Max(a, b, c);
    double min = Min(a, b, c);
    
    cout << fixed;
    cout.precision(10);

    cout << 2 * (max - min);


    return 0;
}