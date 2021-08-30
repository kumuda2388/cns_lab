#include<stdio.h>
#include<string.h>
#include<stdbool.h>
char et[10][20],dt[10][20];
char plaintext[20];
int key,i,j;
void encryption(){
	bool direction=false;
	int row=0;
	for(i=0;i<key;i++)
		for(j=0;j<strlen(plaintext);j++)
		{
			et[i][j]='*';
		}
	for(j=0;j<strlen(plaintext);j++){
		if(row==0 || row==key-1){
			direction=!direction;
		}
		et[row][j]=plaintext[j];
		direction?row++:row--;
	}
	printf("encrypted text is\n");
	for(i=0;i<key;i++){
		for(j=0;j<strlen(plaintext);j++)
			if(et[i][j]!='*'){
			printf("%c",et[i][j]);
			}
	}
printf("\n");
}
void decryption(){
	bool direction=false;
	int row=0,col=0;
	for(i=0;i<key;i++)
		for(j=0;j<strlen(plaintext);j++)
		{
			dt[i][j]='_';
		}
	for(j=0;j<strlen(plaintext);j++){
		if(row==0 || row==key-1){
			direction=!direction;
		}
		dt[row][j]='*';
		direction?row++:row--;
	}
	for(i=0;i<key;i++)
	for(j=0;j<strlen(plaintext);j++){
	if(dt[i][j]=='*'){
	dt[i][j]=plaintext[col];
	col++;
	}}
	row=0;
	for(j=0;j<strlen(plaintext);j++){
		if(row==0 || row==key-1){
			direction=!direction;
		}
		printf("%c",dt[row][j]);
		direction?row++:row--;
	}
	printf("\n");
}
void main()
{
int choice;
printf("enter the plain text:\n");
scanf("%[^\n]",plaintext);
printf("enter key:");
scanf("%d",&key);
printf("\nSelect 1 for encryption & 2 for decryption.\n");
scanf("%d",&choice);
switch(choice){
case 1: encryption();
break;
case 2:decryption();
break;
default:printf("Select valid option");
break;
}
}











