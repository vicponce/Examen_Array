#include <stdio.h>
#include <stdlib.h>
#include "Tipo.c"
#include "Funcionarray.h"




/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*struct ArrayList{
	int reservedSize;
	int  Size;
	void **elementos;

	void (*add_element)();
	void (*remove_element)();
	void (*set)();
	struct ArrayList* (*get)();
	void (*push)();
	struct ArrayList* (*pop)();
	int (*indexOf)();
	int (*size)();
	int (*contains)();
	int (*containsAll)();
	int (*isEmpty)();
	struct ArrayList* (*clone)();
	struct ArrayList* (*subList)();
	void (*clear)();	
} ;*/

/*void add_element(struct ArrayList*, void*);
void remove_element(struct ArrayList*, int);
void set(struct ArrayList*, int, void*);
struct ArrayList* get(struct ArrayList*,int);
void push(struct ArrayList*,int,void*);
struct ArrayList* pop(struct ArrayList*,int);
int indexOf(struct ArrayList*,void*);
int size(struct ArrayList*);
int contains(struct ArrayList*,void*);
int containsAll(struct ArrayList*,struct ArrayList*);
int isEmpty(struct ArrayList*);
struct ArrayList* clone(struct ArrayList*);
struct ArrayList* subList(struct ArrayList*,int,int);
void clear(struct ArrayList*);
struct ArrayList* newArrayList(void );*/


int main(int argc, char *argv[]) {
	
	struct ArrayList* list=newArrayList();
	struct ArrayList* listaClonada;
	if(list->isEmpty(list)==1)
		printf("La lista  esta vacia\n");
	else
		printf("La lista no esta vacia\n");
	void *p,*q;
	int i;
	for(i=0;i<20;i++){
	list->add_element(list,malloc(sizeof(int)));
	
		*(int*)list->elementos[i]=i*9;
	}
	p=malloc(sizeof(int));
	q=malloc(sizeof(int));
	*(int*)p=32;
	*(int*)q=20;
	list->remove_element(list,12);
	list->remove_element(list,8);
	if(list->contains(list,p)==0)
		printf("El elementono no esta en la lista\n");
	else
		printf("El elemento esta en la lista\n");
	list->push(list,16,p);

	if(list->contains(list,p)==0)
		printf("El elementono no esta en la lista\n");
	else
		printf("El elemento esta en la lista\n");
	list->set(list,3,q);
	p=pop(list,6);
	for(i=0;i<list->Size;i++){
		printf("en la posicion %d, esta el valor %d\n",i,*(int*)list->elementos[i]);
	}
	if(list->indexOf(list,p)!=-1){
		printf("Se encontro el elemento, que es %d\n",*(int*)list->get(list,list->indexOf(list,p)));
	}	
	else{
		printf("No se encontro el elemento\n");
	}

	printf("El elemento que se retiro de la lista es %d\n",*(int*)p);
	printf("El tamaÃo actual de la lista es igual a %d\n",list->size(list));
	
	listaClonada=list->subList(list,3,9);

	listaClonada->clear(listaClonada);

	if(list->containsAll(list,listaClonada)==1){
		printf("La lista esta contenida en la principal\n");
	}
	else{
		printf("La lista no esta contenida\n");
	}

	
	for(i=0;i<listaClonada->Size;i++){
		printf("en la posicion %d, esta el valor %d\n",i,*(int*)listaClonada->elementos[i]);
	}
	
//	list->clear(list);
	listaClonada=newArrayList();


        for(i=0;i<listaClonada->Size;i++){
                printf("en la posicion %d, esta el valor %d\n",i,*(int*)listaClonada->elementos[i]);
        }
	if(list->isEmpty(list)==1)
		printf("La lista esta vacia\n");
	else
		printf("La lista no esta vacia\n");
		

	return 0;

}

