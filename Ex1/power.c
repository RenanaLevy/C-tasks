#define Exp 2.718281828 

double Exponent(int x){
    double ans = 1;
    if(x<0){
        for( ; x<0; x++){
            ans /=Exp;
        }
    }
    if(x>0){
        for( ; x>0; x--){
            ans *= Exp;
        }
    }
    return ans;
}

double Power(double x, int y){
    double p = 1;
    if(y<0){
        for( ; y<0; y++){
            p /=x;
        }
    }
    if(y>0){
        for( ; y>0; y--){
            p *= x;
        }
    }
    return p;
}
