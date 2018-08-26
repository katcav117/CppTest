//
//  chaos.c
//  
//
//  Created by Kathleen Cavanagh on 1/20/18.
//

#include <stdio.h>
#include <math.h>

//define complex TYPE
typedef struct complex_num{
    double i,j; //real and imaginary component
}Complex;

void CalcC(double a, double b, double N, double M, Complex *c){
    c->i = (a/N * 3.5) - 2.5;
    c->j = (b/M -.5) * 2;
}

void AddComplex(Complex *c1, Complex *c2, Complex *result){
    //c1 is a pointer whose value is complex
    result->i = c1->i + c2->i;
    result->j = c1->j + c2->j;
}

void SquareComplex(Complex *c, Complex *result){
    double re = (c->i)*(c->i) - (c->j)*(c->j);
    double com = 2.0*(c->i)*(c->j);
    result-> i = re;
    result-> j = com;
}

double GetMagnitude(Complex *c){
    return sqrt((c->i)*(c->i) + (c->j)*(c->j));
}

int main(){
    int N, M;
    scanf("%i %i", &N, &M);//essentially says put this value into this memory address
    for(int i = 0; i< M; i++){ //rows
        for (int j = 0; j< N; j++){ //columns
            Complex c;
            CalcC(j, i, N, M, &c);
            Complex Z = {.i = 0, .j = 0};
            for(int k = 0; k<500; k++){
                SquareComplex(&Z, &Z);
                AddComplex(&Z, &c, &Z);
            }
            if (GetMagnitude(&Z) <= 2.0){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        //new line
        printf("\n");
    }
    return 0;
}
