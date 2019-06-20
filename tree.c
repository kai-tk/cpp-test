#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
struct node{
    char item;
    link l,r;
};

//先行順
void preorder(link h){
    if(h==NULL) return;
    printf("%c ",h->item);
    preorder(h->l);
    preorder(h->r);
}

//中央順
void inorder(link h){
    if(h==NULL) return;
    inorder(h->l);
    printf("%c ",h->item);
    inorder(h->r);
}

//後行順
void postorder(link h){
    if(h==NULL) return;
    postorder(h->l);
    postorder(h->r);
    printf("%c ",h->item);
}

int main(void){
    link head,a,b,c,d,e,f,g,h;
    a=malloc(sizeof(*a)); a->item='A';
    b=malloc(sizeof(*b)); b->item='B';
    c=malloc(sizeof(*c)); c->item='C';
    d=malloc(sizeof(*a)); d->item='D';
    e=malloc(sizeof(*b)); e->item='E';
    f=malloc(sizeof(*c)); f->item='F';
    g=malloc(sizeof(*a)); g->item='G';
    h=malloc(sizeof(*b)); h->item='H';
    head=e;
    e->l=d; e->r=h;
    d->l=b; d->r=NULL;
    b->l=a; b->r=c;
    h->l=f; h->r=NULL;
    f->l=NULL; f->r=g;
    a->l=a->r=NULL;
    c->l=c->r=NULL;
    g->l=g->r=NULL;
    printf("### preorder ###\n");
    preorder(head);
    printf("\n### inorder ###\n");
    inorder(head);
    printf("\n### postorder ###\n");
    postorder(head);
}
