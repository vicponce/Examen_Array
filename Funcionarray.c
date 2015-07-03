#include <stdio.h>
#include <stdlib.h>


struct ArrayList* newArrayList(){

	struct ArrayList* aux=malloc(sizeof(struct ArrayList));
	aux->reservedSize=10;
	aux->Size=0;
	aux->elementos=malloc(sizeof(void*)*aux->reservedSize);

	aux->add_element=add_element;
	aux->remove_element=remove_element;
	aux->set=set;
	aux->get=get;
	aux->push=push;
	aux->pop=pop;
	aux->indexOf=indexOf;
	aux->size=size;
	aux->contains=contains;
	aux->containsAll=containsAll;
	aux->isEmpty=isEmpty;
	aux->clone=clone;
	aux->subList=subList;
	aux->clear=clear;

	return aux;
}


void add_element(struct ArrayList* self, void *element){
	int i;
	if(!self->Size<self->reservedSize){
		self->reservedSize+=10;
		void *tmp;
		tmp=realloc(self->elementos,sizeof(void*)*self->reservedSize);
		if(tmp!=NULL){
			self->elementos=tmp;
			for (i=self->reservedSize;i>self->reservedSize-10;i--){
				self->elementos[i]=NULL;
			}
		self->elementos[self->Size]=element;
		self->Size+=1;
		}else{
			printf("No hay mas memoria disponible para agregar elementos");
		}
	}

}

void remove_element(struct ArrayList* self,int index){

	int i;
	for(i=index;i<self->Size;i++){
		self->elementos[i]=self->elementos[i+1];
	}
	self->elementos[i]=NULL;
	self->Size-=1;

}

void set(struct ArrayList* self, int index, void *element){
	self->elementos[index]=element;
}

struct ArrayList* get(struct ArrayList* self,int index){

	return self->elementos[index];
}

int indexOf(struct ArrayList* self,void *element){
	int i=0;
	while(i<self->Size&&self->elementos[i]!=element)
		i++;
	if(self->elementos[i]==NULL)
		return -1;
	else
		return i;
}

void push(struct ArrayList* self,int index,void *element){

	int i;
	if(!self->Size<self->reservedSize){
		self->reservedSize+=10;
		self->elementos=realloc(self->elementos,sizeof(void*)*self->reservedSize);

		for (i=self->reservedSize;i>self->reservedSize-10;i--){
			self->elementos[i]=NULL;
		}
	}

	for(i=self->Size;i>=index;i--){
		self->elementos[i+1]=self->elementos[i];
	}

	self->elementos[i]=element;
	self->Size+=1;
}

int size(struct ArrayList* self){
	return self->Size;
}

struct ArrayList* pop(struct ArrayList* self, int index){
	
	void *element=get(self,index);
	self->remove_element(self,index);
	return element;

}

int contains(struct ArrayList* self, void *element){

	if(self->indexOf(self,element)!=-1)
		return 1;
	else
		return 0;
}

int containsAll(struct ArrayList* self,struct ArrayList* array){
	int i,flag=0;
	if(array->Size!=0){
	for(i=0;i<array->size();i++){
		if(self->contains(self,array->elementos[i])==1)
			flag++;
	}
	if(flag==array->Size)
		return 1;
	else
		return 0;
	}
	else {
		return 0;
	}

}

int isEmpty(struct ArrayList* self){

	if(self->elementos[0]==NULL)
		return 1;
	else 
		return 0;
}

void clear(struct ArrayList* self){

	int i;
	for(i=0;i<self->Size;i++)
		self->elementos[i]=NULL;
	self->Size=0;
}

struct ArrayList* clone(struct ArrayList* self){
	struct ArrayList* aux=newArrayList();
	int i;
	for(i=0;i<self->Size;i++){
		aux->add_element(aux,self->elementos[i]);
	}

	return aux;

}

struct ArrayList* subList(struct ArrayList* self,int from, int to){
	struct ArrayList* aux=newArrayList();
	int i;
	for(i=from;i<to;i++){
		aux->add_element(aux,self->elementos[i]);
	}
	
	return aux;
}
