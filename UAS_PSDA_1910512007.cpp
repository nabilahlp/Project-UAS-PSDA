#include<bits/stdc++.h> 
using namespace std; 

struct node 
{ 
	int data; 
	struct node *left;
	struct node *right; 
}; 

// Function to create a new node
struct node *newNode(int item) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->data = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// Function to searching a node
node* search(node ** root, int val)
{
	if(!(*root))
    {
        return NULL;
    }
    
    if(val < (*root)->data)
    {
    	printf("%s", " ");
        search(&((*root)->left), val);
    }
    else if(val > (*root)->data)
    {
    	printf("%s", " ");
        search(&((*root)->right), val);
    }
    else if(val == (*root)->data)
    {
        return *root;
    }
}

// Function in-order tranversal
void inorder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		inorder(root->left); 
		cout<< root->data; 
		printf(" ");
		inorder(root->right); 
	} 
}

// Function pre-order traversal
void preorder(struct node *root)
{
	if (root != NULL)
	{
		cout<< root->data;
		printf(" ");
		preorder(root->left);
		preorder(root->right);
	}
}

// Function post-order traversal
void postorder(struct node *root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<< root->data;
		printf(" ");
	}
}

// Function to inserting a new node
struct node* insert(struct node* node, int data) 
{ 
	if (node == NULL) 
		return newNode(data); 

	if (data < node->data) 
		node->left = insert(node->left, data); 
	else
		node->right = insert(node->right, data); 

	return node; 
} 

// Function struct of minimum value node
struct node * minValueNode(struct node* node) 
{ 
	struct node* curr = node; 

	while (curr && curr->left != NULL) 
		curr = curr->left; 

	return curr; 
	
}

// Function to deleting a node
void deltr(node * root)
{
    if (root)
    {
        deltr(root->left);
        deltr(root->right);
        free(root);
    }
} 

// Function struct of delete node
struct node* delNode(struct node* root, int data) 
{ 
	if (root == NULL) return root; 

	if (data < root->data) 
		root->left = delNode(root->left, data); 

	else if (data > root->data) 
		root->right = delNode(root->right, data); 

	else
	{ 
		if (root->left == NULL) 
		{ 
			struct node *temp = root->right; 
			free(root); 
			return temp; 
		} 
		else if (root->right == NULL) 
		{ 
			struct node *temp = root->left; 
			free(root); 
			return temp; 
		} 

		struct node* temp = minValueNode(root->right); 

		root->data = temp->data; 

		root->right = delNode(root->right, temp->data); 
	} 
	return root; 
} 

// Function to find the minimum value
int minValue(struct node* node)  
{  
struct node* curr = node;  
  
while (curr&&curr->left != NULL)  
{  
    curr = curr->left;  
}  
return(curr->data);  
}

// Function to find the maximum value
int maxValue(struct node* node)  
{  
struct node* curr = node;  
  
while (curr&&curr->right != NULL)  
{  
    curr = curr->right;  
}  
return(curr->data);  
}



int main() 
{ 
	node *root;
    node *tmp;
    root = NULL;
    int kondisi = 1, pil, x;
    while(kondisi)
    {
		printf("\tBINARY SEARCH TREE OPERATIONS\t");
    	printf("\n================================================\n");
		printf("MENU\n");
    	printf("[1] Insert\n");
    	printf("[2] Search\n");
    	printf("[3] Delete\n");
    	printf("[4] Pre-Order Traversal\n");
    	printf("[5] In-Order Traversal\n");
    	printf("[6] Post-Order Traversal\n");
    	printf("[7] Maximum Value\n");
    	printf("[8] Minimum Value\n");
    	printf("[9] Reset Tree\n");
    	printf("[x] EXIT\n");
    
    	printf("Pilih MENU : ");
    	scanf("%i", &pil);
    	
    	switch(pil)
    	{
    		case 0: kondisi = 0;
					break;
    				
    		case 1: printf("\nInput Data: ");
    				scanf("%i", &x);
    				root = insert(root, x);
					printf("Data berhasil ditambahkan!\n");
					break;
    				
    		case 2: printf("\nInput Data yang ingin dicari : ");
    				scanf("%i", &x);
    				tmp = search(&root, x);
    				if (tmp)
    					{
        					printf("Pencarian %d\n", tmp->data);
        					printf("Data Ditemukan!\n");
    					}
    				else
    					{
        					printf("Maaf, Data tidak ditemukan! Silakan coba lagi.\n");
    					}
    				break;
    		
    		case 3: printf("Input Data yang ingin dihapus : ");
    				scanf("%i", &x);
    				root = delNode(root, x);
    				printf("Data berhasil dihapus!\n");
    				break;
    				
    		case 4: printf("\nPre-Order Traversal : \n");
    				preorder(root);
    				printf("\n");
    				break;
    				
    		case 5: printf("\nIn-Order Tranversal : \n");
    				inorder(root);
    				printf("\n");
    				break;
    		
    		case 6: printf("\nPost-Order Traversal : \n");
    				postorder(root);
    				printf("\n");
    				break;
    				
    		case 7: cout << "\n Nilai Maximum : " << maxValue(root);
    				getchar();
    				printf("\n");
    				break;
    				
    		case 8: cout << "\n Nilai Minimum : " << minValue(root);  
					getchar();
    				printf("\n");
    				break;
    				
    		case 9: deltr(root);
    				printf("\nReset BST...\n");
    				break;
    				
    		default: printf("\nSilakan Coba Lagi!.\n");
		}
	}
	return x; 
}
