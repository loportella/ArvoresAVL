#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "avl.h"
int main(int argc, char *argv[]) {
	int op,val,i;char c;
	avl a,b;a=cria();
	do{
		printf("MENU:\n1-Inserir;\n2-Buscar;\n3-Mostrar arvore: \t");
		scanf("%d",&op);
		switch(op){
			case 1:b=dados();a=insere(a,b);break;
			case 2:
			if(a!=NULL){
			printf("Buscar: ");scanf("%d",&val);
			busca(a,val);}
			else printf("Nao ha dados\n");break;
			case 3:
				printf("MOSTRAR:\na-Pre-ordem;\nb-Simetrico;\nc-Pos-ordem: \t");
				fflush(stdin); scanf("%c",&c);
				switch(c){
					case 'a':unlink("SaidaPre-Ordem.txt");
					FILE *f1=fopen("SaidaPre-Ordem.txt","w");
					printf("Pre-ordem:\n");preord(a,f1);
					fclose(f1);		break;
					case 'b':unlink("SaidaSimetrica.txt");
					FILE *f2=fopen("SaidaSimetrica.txt","w");
					printf("Simetrico:\n");simet(a,f2);
					fclose(f2); break;
					case 'c':unlink("SaidaPos-Ordem.txt");
					FILE *f3=fopen("SaidaPos-Ordem.txt","w");
					printf("Pos-ordem:\n");posord(a,f3);
					fclose(f3); break;
					default: printf("Opcao invalida\n");break;
				}				
				printf("\n");break;
			default: printf("Opcao invalida\n");break;
		}
	}while(op!=0);
}
