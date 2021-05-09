#include<stdio.h>
#include<string.h>
#include<stdlib.h>
	char lwr[]={'a','b','c','d','e','f','g',
				'h','j','k','l','m','n','o','p','q','r','s','t',
				'u','v','w','x','y','z'};
	char up[]={'A','B','C','D','E','F','G',
			   'H','J','K','L','M','N','O','P','Q','R','S','T',
	           'U','V','W','X','Y','Z'};

int capslock(char a){
	if(a >= 65 && a <= 90) return 1; // buyuk harfse 1
   else return 0; //kucuk harfse 0
}
int indexnumberup(char a){
	for(int i =0;i<25;i++){
		if(a==up[i]){
			return i;
		}
	}
}

int indexnumberlwr(char a){
	for(int i =0;i<25;i++){
		if(a==lwr[i]){
			return i;
		}
	}
}


int main(){

	int key;
	char message[25],ch;
	printf("sifrelenecek cumleyi girinz");
	gets(message);
	int uzunluk = strlen(message);
	printf("kac harf otelenecegini giriniz");
	scanf("%d",&key);
	int kontrol,index;
	for(int i =0;i<uzunluk;i++){
		if(message[i]==' ') continue;
		ch = message[i];
		kontrol = capslock(ch);
		//buyuk harfse
		if(kontrol == 1){
			index = indexnumberup(ch);
			if(index+key<=24){
				message[i]=up[index+key];

			}
			else if(index+key>24){
				message[i] = up[index+key-24];
			}
		}
		//kucuk harfse
		else if(kontrol ==0){
			index = indexnumberlwr(ch);
			if(index+key<=24){
				message[i]=lwr[index+key];
			}
			else if(index+key>24){
				message[i] = lwr[index+key-24];
			}
		}
	}

	printf("%s",message);
	return 0;
}
