#include <stdio.h>
#include <stdlib.h>


typedef struct nodetype
{
    int key;
    struct nodetype *left,*right;
} NodeT;

//1
NodeT *create(int givenkey)
{
    NodeT *p=(NodeT*)malloc(sizeof(NodeT));
    p->key=givenkey;
    p->left=NULL;
    p->right=NULL;
    return p;
}

//2
void cautare(NodeT* root, int givenkey) //cauta daca exista nodul in arbore si afiseaza
{
    if(root == NULL) return;

    if(givenkey == root->key)
    {
        printf("exista nodul");
        return;
    }
    cautare(root->left, givenkey);
    if(givenkey == root->key)
    {
        printf("exista nodul");
        return;
    }

    cautare(root->right, givenkey);
    if(givenkey == root->key)
    {
        printf("exista nodul");
        return;
    }

}

//3
NodeT* cautarea(NodeT *root,int givenkey) //cauta daca exista nodul si daca da il afiseaza
{
    if(root->key == givenkey)
        return root;
    else
    {
        if(givenkey<root->key)
            return cautarea(root->left ,givenkey);
        else
            return cautarea(root->right,givenkey);
    }

}

//4
void insert(NodeT **root,int givenkey)
{
    if(*root==NULL)
        *root=create(givenkey);
    else
    {
        NodeT *p=*root;
        while(1)
        {
            if(givenkey < p->key)
            {
                if(p->left==NULL)
                {
                    p->left=create(givenkey);
                    break;
                }
                else
                p=p->left;
            }
            else if(givenkey>p->key)
            {
                if(p->right==NULL)
                {
                    p->right=create(givenkey);
                    break;
                }
                else
                p=p->right;
            }
            else
                break;
        }
    }
}

//5
void preorder(NodeT *root)
{
    if(root==NULL)
        return;
    else
    {
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

//6
void inorder(NodeT *root)
{
    if(root==NULL)
        return;
    else
    {
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
}

//7
void postorder(NodeT *root)
{
    if(root==NULL)
        return;
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->key);
    }
}

//8
NodeT* minimul(NodeT* root) //cauta minimul din tot arborele
{
    if(root->left==NULL)
        return root;
    else
        return minimul(root->left);
}

//9
NodeT* maximul(NodeT* root) //cauta maximul din tot arborele
{
    if(root->right==NULL)
        return root;
    else
        return maximul(root->right);
}

//10
NodeT* stergere(NodeT *root, int key) //min, max pt stergere
{
    NodeT *p;
    if(root==NULL)
        return root;
    if(key<root->key)
        root->left=stergere(root->left,key);
    else if(key>root->key)
            root->right=stergere(root->right,key);
        else
        {
            if(root->left==NULL)
            {
                p=root->right;
                free(root);
                return p;
            }
            else if(root->right==NULL)
                {
                    p=root->left;
                    free(root);
                    return p;
                }
            p=minimul(root->right);
            root->key=p->key;
            root->right=stergere(root->right,p->key);
        }
        return root;
}

int main()
{
    NodeT *root=NULL;
    insert(&root,7);
    insert(&root,1);
    insert(&root,9);
    insert(&root,3);
    insert(&root,6);
    insert(&root,8);

    preorder(root);

    printf("\n");
    inorder(root);

    printf("\n");
    postorder(root);

    stergere(root,3);
    printf("\n");
    inorder(root);

    printf("\n");
    cautare(root, 9);

    printf("\n");
    NodeT *p=cautarea(root,8);
    printf("%d ",p->key);
    return 0;
}
