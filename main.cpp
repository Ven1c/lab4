#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <iostream>
struct Node
{
	int data;// �������� ����������
	struct Node* right;
	struct Node* left;
};
int* manytimes(int data, struct Node* root);
struct Node* find(int data, struct Node* root);
void print_tree(struct Node* r, int l);
struct Node* CreateTree(struct Node* root, struct Node* r, int data);
int main()
{
	setlocale(LC_ALL, "");
	int D, start = 1;
	struct Node* root;

	root = NULL;
	printf("-1 - ��������� ���������� ������\n");
	while (start)
	{
		printf("������� �����: ");
		scanf_s("%d", &D);
		/*if (find(D, root) != NULL) {
			printf("����� ��� ����\n");
		}
		else*/
			if (D == -1)
		{
			printf("���������� ������ ��������\n\n");
			start = 0;
		}
		else
			root = CreateTree(root, root, D);

	}

	print_tree(root, 0);
	printf("������� ������� �����\n");
	scanf_s("%d", &D);
	struct Node* r = find(D, root);
	int* y = manytimes(D, root);
	int b=y[0];
	int a=y[1];
	printf("����� %d ����������� %d ���(a) \n",r->data, b);
	printf("����������� �� ������ %d \n",a-1);
	return 0;
}
struct Node* CreateTree(struct Node* root, struct Node* r, int data)
{
	if (r == NULL)
	{
		r = (struct Node*)malloc(sizeof(struct Node));
		if (r == NULL)
		{
			printf("������ ��������� ������");
			exit(0);
		}

		r->left = NULL;
		r->right = NULL;
		r->data = data;
		if (root == NULL) return r;

		if (data > root->data)	root->left = r;
		else root->right = r;
		return r;
	}

	if (data > r->data)
		CreateTree(r, r->left, data);
	else
		CreateTree(r, r->right, data);

	return root;
}
void print_tree(struct Node* r, int l)
{

	if (r == NULL)
	{
		return;
	}

	print_tree(r->right, l + 1);
	for (int i = 0; i < l; i++)
	{
		printf("  ");
	}

	printf("%d\n", r->data);
	print_tree(r->left, l + 1);
}
struct Node* find(int data, struct Node* root) {
	if(root==NULL){
		return NULL;
	}
	if (root->data == data) {
		return root;
	}
	if (data > root->data) {
		find(data, root->left);
	}
	else {
		find(data, root->right);
	}
}
int find(int data, struct Node* root,int delve){
	if(root==NULL){
		return NULL;
	}
	if (root->data == data) {
		delve++;
		return delve;
	} 
	if (data > root->data) {
		delve++;
		find(data, root->left,delve);
	}
	else {
		delve++;
		find(data, root->right,delve);
	}
}

int* manytimes(int data, struct Node* root) {
	int many[2] = {0};
	struct Node* r;
	r = find(data, root);
	int delv= find(data, root,0);
	while (1) {
		
		if (r != NULL) {
			many[0]++;
			delv+=find(data, r->right,0);
			r = find(data, r->right);
			
			
		}
		else {
			break;
		}
	}
	many[1]=delv;
	return many;
}
