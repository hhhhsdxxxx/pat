#include <iostream>
#include <math.h>

using namespace std;

long long gcd(long long a, long long b){
    long long x = a>0 ? a:(-a);
    long long y = b>0 ? b:(-b);
    long long re = 1;
    // cout << x << " " << y << endl;
    if(y>x){
      long long temp = x;
      x = y;
      y = temp;
    }
    while(y != 0){
      re = y;
      x = x%y;
      y = x;
      x = re;
    }
    // cout << re << endls;
    return re;
}

long long print_num(long long a, long long b){
    long long k = gcd(a, b);
    // cout << "k: " << k << endl;
    bool isfu = false;
    if(k != 1){
        a /= k;
        b /= k;
    }
    if(a < 0)
        isfu = true;
    long long x = a/b;
    // cout << "a: " << a << " b: " << b << endl;
    // cout << "x: " << x << endl;
    if(x != 0)
        a = abs(a%b);
    if(isfu)
        cout << "(";
    if(x != 0)
        cout << x;
    if(a != 0){
        if(x != 0)
            cout << " ";
        cout << a << "/" << b;
    }
    else{
        if(x == 0)
            cout << "0";
    }
    if(isfu)
        cout << ")";
    return k;
}



int main(int argc, char const *argv[])
{
    long long a1, b1, a2, b2, k1, k2, q1, p1;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    char op[4] = {'+', '-', '*', '/'};
    for(int i = 0; i < 4; i++){
        k1 = print_num(a1, b1);
        // cout << k1 << endl;
        cout << " " << op[i] << " ";
        k2 = print_num(a2, b2);
        cout << " = ";
        if(k1 != 1){
            a1 /= k1;
            b1 /= k1;
        }
        if(k2 != 1){
            a2 /= k2;
            b2 /= k2;
        }
        switch(op[i]){
            case '+':
            q1 = a1*b2 + a2*b1;
            p1 = b1 * b2;
            print_num(q1, p1);
            cout << endl;
            break;
            case '-':
            q1 = a1*b2 - a2*b1;
            // cout << q1 << endl;
            p1 = b1 * b2;
            print_num(q1, p1);
            cout << endl;
            break;
            case '*':
            q1 = a1*a2;
            p1 = b1*b2;
            print_num(q1, p1);
            cout << endl;
            break;
            case '/':
            if(a2 == 0)
                cout << "Inf" << endl;
            else{
                q1 = a1 * b2;
                p1 = a2 * b1;
                if(p1 < 0){
                    p1 = -p1;
                    q1 = -q1;
                }
                print_num(q1, p1);
                cout << endl;
            }
            break;
            default:
            break;
        }
    }

    return 0;
}