#include<stdio.h>
#include<string.h>
int et[30],dt[30];//encryption and decryption
char plaintext[30],key[10];
//encryption
void vigenereen(){
int j=0;
for(int i=0,j=0;i<strlen(plaintext);i++,j++){
et[i]=(((plaintext[i]-97)+(key[j%strlen(key)]-97))%26)+97;
}
}
//decryption
void vigenerede(){
for(int i=0,j=0;i<strlen(plaintext);i++,j++){
dt[i]=((((et[i]-97)-(key[j%strlen(key)]-97))+26)%26)+97;
}
}


void main(){
printf("enter the plain text:\n");
scanf("%s",plaintext);
printf("\nenter the key:\n");
scanf("%s",key);
printf("\n encrypted text:\n");
vigenereen();
for(int i=0;i<strlen(plaintext);i++){
printf("%c",et[i]);
}
printf("\n \ndecrypted text:\n");
vigenerede();
for(int i=0;i<strlen(plaintext);i++){
printf("%c",dt[i]);
}
printf("\n");
}
