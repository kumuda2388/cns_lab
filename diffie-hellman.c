#include<stdio.h>
#include<math.h>
int q,alpha;
int keygeneration(int x,int y){
return ((int)pow(y,x))%q;
}
int publickeygeneration(int x)
{
return ((int)pow(alpha,x))%q;
}
void main(){
int xa,xb,ya,yb,k1,k2;
printf("\nenter q and alpha:");
scanf("%d",&q);
scanf("%d",&alpha);
printf("\nenter xa and xb:");
scanf("%d",&xa);
scanf("%d",&xb);
ya=publickeygeneration(xa);
yb=publickeygeneration(xb);
k1=keygeneration(xa,yb);
k2=keygeneration(xb,ya);
printf("q=%d\talpha=%d\nxa=%d\txb=%d\nya=%d\t yb=%d\nk1=%d \t k2=%d\n",q,alpha,xa,xb,ya,yb,k1,k2);
if(k1==k2){
printf("key generation is successful");
}else{
printf("key generation not successful");}
}
