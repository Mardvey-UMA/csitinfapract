#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double x){
    return log(4 - x*x);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << fixed << setprecision(6);
    double  a, b, h, m = 0.00000999;
    cout << "‚Ά¥¤¨β¥ §­ η¥­¨ο A B ¨ θ £ h:\n";
    cin >> a >> b >> h;
    while (a <= (b + m)){
        if (abs(a) >= 2 - m){
            cout << a << "\tundefined" << endl;
        }else{
            cout << a << "\t" << f(a) << endl;
        }
        a+=h;
    }
    //’¥αβ
    //‚Ά®¤ -2.5 2.8 1.06
    //-2.500000       undefined
    //-1.440000       0.655653
    //-0.380000       1.349527
    //0.680000        1.263449
    //1.740000        -0.027988
    //2.800000        undefined
    //‚Ά®¤ 0.45 3.79 1.6
    //0.450000	1.334343
    //2.050000	undefined
    //3.650000	undefined
    //‚Ά®¤ -2 2 -0.1
    //-2.000000       undefined
    //-1.900000       -0.941609
    //-1.800000       -0.274437
    //-1.700000       0.104360
    //-1.600000       0.364643
    //-1.500000       0.559616
    //-1.400000       0.712950
    //-1.300000       0.837248
    //-1.200000       0.940007
    //-1.100000       1.026042
    //-1.000000       1.098612
    //-0.900000       1.160021
    //-0.800000       1.211941
    //-0.700000       1.255616
    //-0.600000       1.291984
    //-0.500000       1.321756
    //-0.400000       1.345472
    //-0.300000       1.363537
    //-0.200000       1.376244
    //-0.100000       1.383791
    //0.000000        1.386294
    //0.100000        1.383791
    //0.200000        1.376244
    //0.300000        1.363537
    //0.400000        1.345472
    //0.500000        1.321756
    //0.600000        1.291984
    //0.700000        1.255616
    //0.800000        1.211941
    //0.900000        1.160021
    //1.000000        1.098612
    //1.100000        1.026042
    //1.200000        0.940007
    //1.300000        0.837248
    //1.400000        0.712950
    //1.500000        0.559616
    //1.600000        0.364643
    //1.700000        0.104360
    //1.800000        -0.274437
    //1.900000        -0.941609
    //2.000000        undefined
    //‚Ά®¤ -2.5 -2 0.01
    //-2.500000       undefined
    //-2.490000       undefined
    //-2.480000       undefined
    //-2.470000       undefined
    //-2.460000       undefined
    //-2.450000       undefined
    //-2.440000       undefined
    //-2.430000       undefined
    //-2.420000       undefined
    //-2.410000       undefined
    //-2.400000       undefined
    //-2.390000       undefined
    //-2.380000       undefined
    //-2.370000       undefined
    //-2.360000       undefined
    //-2.350000       undefined
    //-2.340000       undefined
    //-2.330000       undefined
    //-2.320000       undefined
    //-2.310000       undefined
    //-2.300000       undefined
    //-2.290000       undefined
    //-2.280000       undefined
    //-2.270000       undefined
    //-2.260000       undefined
    //-2.250000       undefined
    //-2.240000       undefined
    //-2.230000       undefined
    //-2.220000       undefined
    //-2.210000       undefined
    //-2.200000       undefined
    //-2.190000       undefined
    //-2.180000       undefined
    //-2.170000       undefined
    //-2.160000       undefined
    //-2.150000       undefined
    //-2.140000       undefined
    //-2.130000       undefined
    //-2.120000       undefined
    //-2.110000       undefined
    //-2.100000       undefined
    //-2.090000       undefined
    //-2.080000       undefined
    //-2.070000       undefined
    //-2.060000       undefined
    //-2.050000       undefined
    //-2.040000       undefined
    //-2.030000       undefined
    //-2.020000       undefined
    //-2.010000       undefined
    //-2.000000       undefined
}