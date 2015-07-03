
void add_element(struct ArrayList*, void*);
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
struct ArrayList* newArrayList(void );

#include "Funcionarray.c"
