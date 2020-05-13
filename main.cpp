#include <iostream>
#include <cmath>

#define pi 3.14159625

using namespace std;


double difr(double x, double y)
{
    
}


double result(double x_st, double y_st, double x_end, double y_end)
{
    double difference = 1000000;
    if (y_end > y_st)
    {
        for (double angle = 0; angle < 900; angle++)
        {
            angle = angle/10;
            angle = angle*pi/180;

            double x = x_st;
            double y = y_st;
            double n0 = difr(x, y);
            while (x != x_end)
            {
                double n = difr(x, y);
                y += x*(sin(angle)*(n0/n)/(sqrt(1-(sin(angle)*(n0/n))^2)));
                
                x += 0.001;
            }
            
            if ((y - y_end) < difference)
            {
                difference = y - y_end;
            }

        }
    }
    else 
    {
        for (double angle = 0; angle < 900; angle++)
        {
            angle = angle/10;
            angle = angle*pi/180;

            double x = x_st;
            double y = y_st;
            double n0 = difr(x, y);
            while (x != x_end)
            {
                double n = difr(x, y);
                y -= x*(sin(angle)*(n0/n)/(sqrt(1-(sin(angle)*(n0/n))^2)));
                
                x += 0.001;
            }
            
            if ((y - y_end) < difference)
            {
                difference = y - y_end;
            }

        }
    }

    return difference;
}


int main()
{
    double x, y, x1, y1;

    cin >> x >> y >> x1 >> y1;

    cout << result(x, y, x1, y1);

    return 0;
}