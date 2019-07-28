#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std;

struct Node{
        int data;
        Node* lchild;
        Node* rchild;
};

int a1[12], a2[12];//存放输入的数据
int N, L;
vector <int> ans1, ans2;

Node* search(int x, Node* root)
{
        if(root == NULL)
        {
                Node* tmp = new Node;
                tmp->data = x;
                tmp->lchild = NULL;
                tmp->rchild = NULL;
                return tmp;
        }
        else if (x < root->data)
            root->lchild = search (x, root->rchild);
        else 
            root->rchild = search (x, root->rchild);
        return root;
}

Node* build_tree(int N, int a[])
{
        Node* root = new Node;
        root = NULL;
        for (int i = 0; i < N; i++)
        root = search (a[i], root);
        return root;
}

void pre_order(Node* root, vector<int>* ans)
{
        if(root == NULL) return;
        ans->push_back(root->data);
        pre_order(root->lchild, ans);
        pre_order(root->rchild, ans);
}

int main()
{
        while(scanf("%d", &N) != EOF)
        {
                if(N == 0) break;
                else scanf("%d", &L);
                ans1.clear();
                for(int i = 0; i < N; i++)
                {
                        scanf("%d", &a1[i]);
                        //ans1.push_back(a1[i]);
                }
                Node* root1 = build_tree(N, a1);
                pre_order(root1, &ans1);
                for(int i = 0; i < L; i++)
                {
                        ans2.clear();
                        for(int j = 0; j < N; j++)
                        {
                                scanf("%d", &a2[j]);
                        }
                        Node* root2 = build_tree(N, a2);
                        pre_order( root2, &ans2);
                        if(ans1 == ans2)
                            printf("Yes\n");
                        else
                                printf("No\n");
                }
        }
        return 0;
}