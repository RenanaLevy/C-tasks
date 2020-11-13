#include <stdio.h>
#include "myMath.h"

// f(x) = e^x + x^3 - 2
float foo1(double x){
    double e = Exponent(x);

    double p = Power(x, 3);

    float a = add(e, p);
    return sub(a, 2); 
}

// f(x) = 3x + 2x^2
float foo2(double x){
    double m1 = mul(x, 3);

    double p = Power(x, 2);
    double m2 = mul(p, 2);

    return add(m1, m2);
}

// f(x) = (4x^3)/5 -2x
float foo3(double x){
    double p = Power(x, 3);
    double m1 = mul(p, 4);
    double d = div(m1, 5);

    double m2 = mul(x, 2);

    return sub(d, m2);
}

int main(){
    double num;
    printf("Please insert a real number: \n");
    scanf("%lf", &num);

    float f1 = foo1(num);   
    printf("The value of f(x) = e^x + x^3 - 2 with x = %lf, is: %0.4f\n", num, f1);

    float f2 = foo2(num);
    printf("The value of f(x) = 3x + 2x^2 with x = %lf, is: %0.4f\n", num, f2);

    float f3 = foo3(num);
    printf("The value of f(x) = (4x^3)/5 - 2x with x = %lf, is: %0.4f\n", num, f3);

    return 0;
}
