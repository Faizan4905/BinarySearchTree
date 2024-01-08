#include<stdio.h>
#include<stdlib.h>
// first of all structure of a node of a binary search tree
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;
// globally declaring a pointer of type Node and I will also initialize it as NULL
// so initially nothing is there in Binary Search Tree

void Insert(int key)
{
    struct Node *t=root;
    struct Node *r,*p; // p is for creating a new Node

    if(root==NULL) // if root is NULL then it is very first Node
    {
        // so simply I have to create a New node and make it as New Node
        p=(struct Node *)malloc(sizeof(struct Node));
        p->data=key;
        p->lchild=p->rchild=NULL; // this has to be done if it is very first Node
        root=p;// root should point on new node
        return ;

    }
    // otherwise we have seen the procedure if t is not equal to NULL we will continue searching for a key value
    // and r will be following t , the procedure wll be same as searching
    while(t!=NULL)
    {
        r=t;
        if(key<t->data)  
            t=t->lchild;
        else if(key>t->data)      
            t=t->rchild;
        else // if key element is found we are not gonna insert anything 
             return; // simply we will return , means stop the procedure
           
    }

    // Once we have come out of the while loop so t will become NULL
    // and r will be pointing on some location where we have to insert a new Node
    // so first of all I will create a New Node
    p=(struct Node *)malloc(sizeof(struct Node)); // once node is created I have to link it with Binary Search Tree
    p->data=key;
    p->lchild=p->rchild=NULL;
    // so I have to again check using r
    if(key<r->data) // means the new node should come on left hand side
        r->lchild=p;
    else r->rchild=p; 
    // this is how new node will be inserted in a BInary Search Tree

}  

// Search Function Should return a Node in which the key value is found
struct Node * Search(int key)
{
    // for searching I start from root so I will take a pointer t
    struct Node *t=root;
    while(t!=NULL)
    {
        if(key==t->data)
        {
            return t;
        }
        else if(key<t->data)
            t=t->lchild;
        else
            t=t->rchild;

    }
    // if you comeout loop without any thing found simply return NULL
    return NULL;
}

void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

int main()
{
    struct Node *temp;
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);
    Inorder(root);
    printf("\n");
    temp=Search(20);
    if(temp!=NULL)
    {
        printf("element %d is found\n",temp->data);

    }
    else
    {
        printf("element is not found\n");
    }

}