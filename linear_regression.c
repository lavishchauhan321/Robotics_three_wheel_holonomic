// C code for linear regression
#include<stdio.h>
//format for input is no. of cases n then (w V1 V2 V3) in following n lines
//line is y=a+bx
int main(){
    int n;
    scanf("%d,&n");
    long long int x[n], V1[n], V2[n], V3[n], sum_x=0, sum_V1=0, sum_V2=0, sum_V3=0, sum_xV1=0, sum_xV2=0, sum_xV3=0
    ,sum_x2=0;
    for(int iterator=0 ; iterator < n; iterator ++){
    scanf("%lld",&x[i]); sum_x += x[i]; sum_x2 += x[i]*x[i];
    scanf("%lld",&V1[i]); sum_V1 += V1[i] ; sum_xV1 += x[i] * V1[i] ;
    scanf("%lld",&V2[i]); sum_V2 += V1[i] ; sum_xV2 += x[i] * V2[i] ;
    scanf("%lld",&V3[i]); sum_V3 += V1[i] ; sum_xV3 += x[i] * V3[i] ;
}   double a1 = ( double )( sum_V1 * sum_x2 - sum_x * sum_xV1 )/( n * sum_x2 - sum_x * sum_x) ;
    double b1=  ( double )( n * sum_xV1 - sum_x * sum_V1) / ( n * sum_x2 - sum_x * sum_x) ;
    double a2 = ( double )( sum_V2 * sum_x2 - sum_x * sum_xV2 )/( n * sum_x2 - sum_x * sum_x) ;
    double b2=  ( double )( n * sum_xV2 - sum_x * sum_V2) / ( n * sum_x2 - sum_x * sum_x) ;
    double a3 = ( double )( sum_V3 * sum_x2 - sum_x * sum_xV3 )/( n * sum_x2 - sum_x * sum_x) ;
    double b3=  ( double )( n * sum_xV3 - sum_x * sum_V3) / ( n * sum_x2 - sum_x * sum_x) ;
    printf("%lf %lf\n",a1,b1);
    printf("%lf %lf\n",a2,b2);
    printf("%lf %lf\n",a3,b3);
    return 0;
}
