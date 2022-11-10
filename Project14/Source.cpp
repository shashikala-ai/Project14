//Three Dimension Coordinate Systems Converter
#include <iostream>
#include <math.h>
#include<cstring>
#include<cstdlib>

#define PI 3.1415926535897932384626433832795
#define FAC1 (180.0/PI)
#define FAC2 (PI/180.0)
using namespace std;

typedef struct
{
    double d1;
    double d2;
    double d3;
    string str;
    string str1[2];
    string str2[2];
    string str3[2];
    string str4[2];
} Coordinate;

class convt
{
private:
    Coordinate cr;//Cartesian (rectangular)
    Coordinate cc;//Cylinderical
    Coordinate cs;//Spherical
public:
    convt() {
        cr.str = "Cartesian coordinate system";
        cc.str = "Cylindrical coordinate system";
        cs.str = "Spherical coordinate system";
        //Cartesian
        cr.str1[0] = "x = ";
        cr.str2[0] = "y = ";
        cr.str3[0] = "z = ";
        cr.str1[1] = " Unit";
        cr.str2[1] = " Unit";
        cr.str3[1] = " Unit\n";
        cr.str4[2] = " Unitit\n";
        //Cylindrical
        cc.str1[0] = "Rho = ";
        cc.str2[0] = "Phi = ";
        cc.str3[0] = "z   = ";
        cc.str1[1] = " Unit";
        cc.str2[1] = " Degree";
        cc.str3[1] = " Unit\n";
        cc.str4[1] = "Unit\b";
        //Spherical
        cs.str1[0] = "R     = ";
        cs.str2[0] = "Theta = ";
        cs.str3[0] = "Phi   = ";
        cs.str1[1] = " Unit";
        cs.str2[1] = " Degree";
        cs.str3[1] = " Degree\n";
    }
    void setVarr(double x, double y, double z) { cr.d1 = x; cr.d2 = y; cr.d3 = z; }
    void setVarc(double x, double y, double z) { cc.d1 = x; cc.d2 = y; cc.d3 = z; }
    void setVars(double x, double y, double z) { cs.d1 = x; cs.d2 = y; cs.d3 = z; }


    void convertr_c()
    {
        //convert from Cartesian to Cylindrical
        cc.d1 = sqrtl(cr.d1 * cr.d1 + cr.d2 * cr.d2);//Rho
        cc.d2 = atan(cr.d2 / cr.d1);//Phi
        cc.d3 = cr.d3;//z
    }
    void convertc_s()
    {
        //Convert from cylinderical to spherical
        cs.d1 = sqrtl(cc.d1 * cc.d1 + cc.d3 * cc.d3);//r
        cs.d2 = atan(cc.d1 / cc.d3);//theta
        cs.d3 = atan((cc.d1 * sin(cc.d2)) / (cc.d1 * cos(cc.d2)));//phi
    }
    void converts_r()
    {
        //convert from spherical to cartesian
        cr.d1 = cs.d1 * sin(cs.d2) * cos(cs.d3);
        cr.d2 = cs.d1 * sin(cs.d2) * sin(cs.d3);
        cr.d3 = cs.d1 * cos(cs.d2);
    }
    friend void disp(convt&);
};
void disp(convt& conv)
{
    cout << endl << conv.cr.str << endl;//display rectangular
    cout << "-------------------------------\n";
    cout << conv.cr.str1[0] << conv.cr.d1 << conv.cr.str1[1] << endl;
    cout << conv.cr.str2[0] << conv.cr.d2 << conv.cr.str2[1] << endl;
    cout << conv.cr.str3[0] << conv.cr.d3 << conv.cr.str3[1] << endl;

    cout << conv.cc.str << endl;//display cylindrical
    cout << "-------------------------------\n";
    cout << conv.cc.str1[0] << conv.cc.d1 << conv.cc.str1[1] << endl;
    cout << conv.cc.str2[0] << FAC1 * conv.cc.d2 << conv.cc.str2[1] << endl;
    cout << conv.cc.str3[0] << conv.cc.d3 << conv.cc.str3[1] << endl;

    cout << conv.cs.str << endl;//display spherical
    cout << "-------------------------------\n";
    cout << conv.cs.str1[0] << conv.cs.d1 << conv.cs.str1[1] << endl;
    cout << conv.cs.str2[0] << FAC1 * conv.cs.d2 << conv.cs.str2[1] << endl;
    cout << conv.cs.str3[0] << FAC1 * conv.cs.d3 << conv.cs.str3[1] << endl << endl;
}
int main()
{
    convt con;
    double dx1, dx2, dx3;
    char ch;

    for (;;)
    {
        cout << "\nThree Dimension Coordinate Systems Converter" << endl;
        cout << "\n\t1) Rectangular Coordinate System (x, y, z) " << endl;
        cout << "\t2) Cylinderical Coordinate System (Rho, Phi, z)" << endl;
        cout << "\t3) Spherical Coordinate System (R, Theta, Phi)" << endl;
        cout << "\t4) Exit " << endl << endl;
        cout << "Hint: The used angles are in degrees" << endl << endl;
        cout << "Choose one option : ";
        cin >> ch;

        if (ch == '1' || ch == '2' || ch == '3')
        {
            cout << "\nEnter coordinates of the chosen system:";
            cout << "\nEnter 1st axis :";
            cin >> dx1;
            cout << "Enter 2nd axis :";
            cin >> dx2;
            cout << "Enter 3rd axis :";
            cin >> dx3;
            switch (ch)
            {
            case '1':
            {
                con.setVarr(dx1, dx2, dx3);
                con.convertr_c();
                con.convertc_s();
                disp(con);
                break;
            }
            case '2':
            {
                dx2 = dx2 * FAC2;
                con.setVarc(dx1, dx2, dx3);
                con.convertc_s();
                con.converts_r();
                disp(con);
                break;
            }
            case '3':
            {
                dx2 = dx2 * FAC2;
                dx3 = dx3 * FAC2;
                con.setVars(dx1, dx2, dx3);
                con.converts_r();
                con.convertr_c();
                disp(con);
                break;
            }
            }
        }
        else if (ch == '4')
            break;
        else
            cout << "Wrong number choosen. Try to choose right option :" << endl << endl;
    }
    return 0;
}
