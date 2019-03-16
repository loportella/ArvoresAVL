#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
avl cria(){
	return NULL;
}
avl dados(){
	int v;
	avl no=(avl)malloc(sizeof(avl));
	printf("Valor: ");scanf("%d",&v);
	no->dir=NULL;
	no->esq=NULL;
	no->h=0;no->n=v;
	return no;
}
int altura(avl a){
	if(a==NULL)return -1;
	else return a->h;
}
int maior(int a,int b){
	if(a>b) return a;
	else return b;
}
avl direita(avl a){
	avl b;b=a->esq;
	a->esq=b->dir;
	b->dir=a;
	a->h=maior(altura(a->dir),altura(a->esq))+1;
	b->h=maior(altura(a->esq),a->h)+1;
	return b;
}
avl esquerda(avl a){
	avl b;b=a->dir;
	a->dir=b->esq;
	b->esq=a;
	a->h=maior(	altura(a->dir),altura(a->esq))+1;
	b->h=maior(altura(a->dir),a->h)+1;
	return b;	
}
avl esqdir(avl a){
	a->esq=esquerda(a->esq);
	return direita(a);
}
avl diresq(avl a){
	a->dir=direita(a->dir);
	return esquerda(a);
}
avl insere(avl a,avl dado){
	if(a==NULL) return dado;
	if(dado->n<a->n){
		a->esq=insere(a->esq,dado);
		if(altura(a->esq)-altura(a->dir)==2){
			if(dado->n<a->esq->n){
				a=direita(a);
			}else{
				a=esqdir(a);
			}
		}
	}else{
		if(dado->n>a->n){	
			a->dir=insere(a->dir,dado);
			if(altura(a->dir)-altura(a->esq)==2){
			if(dado->n>a->dir->n){
				a=esquerda(a);
			}else a=diresq(a);
			}
	}
	}a->h=maior(altura(a->esq),altura(a->dir))+1;
	return a;
}
void preord(avl a,FILE *f){
	if(a!=NULL){
		printf("<");fprintf(f,"<");
		printf("%d",a->n);
		fprintf(f,"%d",a->n);
		preord(a->esq,f);
		preord(a->dir,f);
		printf(">");fprintf(f,">");
	}
}
void simet(avl a,FILE *f){
	if(a!=NULL){
		printf("<");fprintf(f,"<");
		simet(a->esq,f);
		printf("%d",a->n);
		fprintf(f,"%d",a->n);
		simet(a->dir,f);
		printf(">");fprintf(f,">");
	}
}
void posord(avl a,FILE *f){
	if(a!=NULL){
		printf("<");fprintf(f,"<");
		posord(a->esq,f);
		posord(a->dir,f);
		printf("%d",a->n);fprintf(f,"%d",a->n);
		printf(">");fprintf(f,">");
	}
}
void busca(avl a,int val){
 if(a!=NULL){
 if(val==a->n) printf("%d econtrado",a->n);
	else{
		if(val<a->n){
			busca(a->esq,val);
		}else if(val>a->n){
			busca(a->dir,val);
		}
}}else printf("%d nao foi encontrado\n");}
