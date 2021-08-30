#include<stdio.h>
#include<math.h>
int prime(int n){
int flag=0;
for(int i = 2; i <= n / 2; ++i) {
    if (n % i == 0) {
      flag = 1;
      break;
    }
  }
  return flag;
}

//gcd using euclidian method
 int gcd(int a, int b)
{
int t;
 while(1){
 t=a%b;
 if(t==0){return b;}
 a=b;
 b=t;
 }
}

// public key(e,n) and private key (d,n)
void main()
{
int p,q,msg;//p and q prime numbers

do{
printf("enter p(prime number):");
scanf("%d",&p);
}while(prime(p)||p==1);
 do{
 printf("\nenter q(prime number):");
scanf("%d",&q);
}while(prime(q)||q==1);
printf("\n p=%d \t q=%d",p,q);
int n = p*q;
int e = 2;
int phi=(p-1)*(q-1);
	//to find e,e must be co-prime to phi i.e gcd(e,phi)=1 and e<phi
	while (e < phi)
	{
		if (gcd(phi, e)==1)
			break;
		else
			e++;
	}
printf("\tphi=%d \t e=%d\n",phi,e);
// d*e = 1 + k * totient
//int k = 2; // A constant value
double d1=1/e;
double d =fmod(d1,phi);
printf("\nd:");
printf("%lf",d);
printf("\nenter the message:");
scanf("%d",&msg);//message
printf("\nMessage data = %d\n", msg);
// Encryption c = (msg ^ e) % n
double c = pow(msg, e);
c = fmod(c, n);
printf("\nEncrypted text:%lf", c);
// Decryption m = (c ^ d) % n
double m = pow(c, d);
m = fmod(m, n);
printf("\ndecrypted text:%lf", m);
}


