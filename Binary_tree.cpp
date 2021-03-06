#include "Binary_tree.h"
template <class Entry>
Binary_node<Entry>::Binary_node()
{
	left = right = NULL;
}

template <class Entry>
Binary_node<Entry>::Binary_node(const Entry &x)
{
	data = x;
	left = right = NULL;
}

template <class Entry>
Binary_tree<Entry>::Binary_tree()
{
	root = NULL;
}


template <class Entry>
bool Binary_tree<Entry>::empty()const
{
	return root == NULL;
}

template <class Entry>
int Binary_tree<Entry>::leaf_count() const
{
	return recursive_leaf_count(root);
}

template <class Entry>
int Binary_tree<Entry>::recursive_leaf_count(Binary_node<Entry> *sub_root) const
{
	if (sub_root == NULL) return 0;
	if (sub_root->left == NULL && sub_root->right == NULL)
		return 1;
	return recursive_leaf_count(sub_root->left) + recursive_leaf_count(sub_root->right);
}




template <class Entry>
void Binary_tree<Entry>::preorder(void(*visit)(Entry &))
{
	recursive_preorder(root, visit);
}

template <class Entry>
void Binary_tree<Entry>::recursive_preorder(Binary_node<Entry> *sub_root, void(*visit)(Entry &))
{
	if (sub_root != NULL)
	{
		(*visit)(sub_root->data);
		recursive_preorder(sub_root->left, visit);
		recursive_preorder(sub_root->right, visit);
	}
}


template <class Entry>
void Binary_tree<Entry>::inorder(void(*visit)(Entry &))
{
	recursive_inorder(root, visit);
}


template <class Entry>
void Binary_tree<Entry>::recursive_inorder(Binary_node<Entry> *sub_root, void(*visit)(Entry &))
{
	if (sub_root != NULL)
	{
		recursive_inorder(sub_root->left, visit);
		(*visit)(sub_root->data);
		recursive_inorder(sub_root->right, visit);
	}
}


template <class Entry>
void Binary_tree<Entry>::postorder(void(*visit)(Entry &))
{
	recursive_postorder(root, visit);
}

template <class Entry>
void Binary_tree<Entry>::recursive_postorder(Binary_node<Entry> *sub_root, void(*visit)(Entry &))
{
	if (sub_root != NULL)
	{
		recursive_postorder(sub_root->left, visit);
		recursive_postorder(sub_root->right, visit);
		(*visit)(sub_root->data);
	}
}




template<class Entry>
void Binary_tree<Entry>::NoRePreorder()
{
	if (root == NULL)
		return;
	Binary_node<Entry> * p = root;
	stack<Binary_node<Entry>*> s;
	while (!s.empty() || p)
	{
		if (p)
		{
			cout << p->data;
			s.push(p);
			p = p->left;
		}
		else
		{
			p = s.top();
			s.pop();
			p = p->right;
		}
	}
}


template <class Entry>
void Binary_tree<Entry>::NoReInorder()
{
	//空树  
	if (root == NULL)
		return;
	//树非空  
	Binary_node<Entry> * p = root;
	stack<Binary_node<Entry>*> s;
	while (!s.empty() || p)
	{
		if (p)
		{
			s.push(p);
			p = p->left;
		}
		else
		{
			p = s.top();
			s.pop();
			cout << p->data;
			p = p->right;
		}
	}
}


template <class Entry>
int Binary_tree<Entry>::size() const
{
	return recursive_size(root);
}


template <class Entry>
int Binary_tree<Entry>::recursive_size(Binary_node<Entry> *sub_root) const
{
	if (sub_root == NULL)
		return 0;
	return 1 + recursive_size(sub_root->left) + recursive_size(sub_root->right);
}

template <class Entry>
int Binary_tree<Entry>::height() const
{
	return recursive_height(root);
}

template <class Entry>
int Binary_tree<Entry> ::recursive_height(Binary_node<Entry> *sub_root) const
{
	if (sub_root == NULL)
		return 0;
	int l = recursive_height(sub_root->left);
	int r = recursive_height(sub_root->right);
	if (l > r)
		return 1 + l;
	else
		return 1 + r;
}

template <class Entry>
void Binary_tree<Entry>::clear()
{
	recursive_clear(root);
}

template <class Entry>
void Binary_tree<Entry>::recursive_clear(Binary_node<Entry> *&sub_root)
{
	Binary_node<Entry> *temp = sub_root;
	if (sub_root == NULL)
		return;
	recursive_clear(sub_root->left);
	recursive_clear(sub_root->right);
	sub_root = NULL;
	delete temp;
}


template <class Entry>
void Binary_tree<Entry>::insert(const Entry &x)
{
	recursive_insert(root, x);
}


template <class Entry>
void Binary_tree<Entry>::recursive_insert(Binary_node<Entry> *&sub_root, const Entry &x)
{
	if (sub_root == NULL)
		sub_root = new Binary_node<Entry>(x);
	else
		if (recursive_height(sub_root->right) < recursive_height(sub_root->left))
			recursive_insert(sub_root->right, x);
		else
			recursive_insert(sub_root->left, x);
}

template <class Entry>
Binary_tree<Entry>::~Binary_tree()
{
	clear();
}

template <class Entry>
Binary_tree<Entry>::Binary_tree(const Binary_tree<Entry> &original)
{
	root = recursive_copy(original.root);
}


template <class Entry>
Binary_node<Entry> *Binary_tree<Entry>::recursive_copy(Binary_node<Entry> *sub_root)
{
	if (sub_root == NULL)
		return NULL;
	Binary_node<Entry> *temp = new Binary_node<Entry>(sub_root->data);
	temp->left = recursive_copy(sub_root->left);
	temp->right = recursive_copy(sub_root->right);
	return temp;
}


template <class Entry>
Binary_tree<Entry> &Binary_tree<Entry>::operator =(const Binary_tree<Entry> &original)
{
	Binary_tree<Entry> new_copy(original);
	clear();
	root = new_copy.root;
	new_copy.root = NULL;
	return *this;
}

template <class Entry>
void Binary_tree<Entry> ::level_traverse(void(*visit)(Entry &))
{
	Binary_node<Entry> *sub_root;
	if (root != NULL) {
		Queue < Binary_node<Entry> * > waiting_nodes;
		waiting_nodes.append(root);
		do {
			waiting_nodes.retrieve(sub_root);
			(*visit)(sub_root->data);
			if (sub_root->left) waiting_nodes.append(sub_root->left);
			if (sub_root->right) waiting_nodes.append(sub_root->right);
			waiting_nodes.serve();
		} while (!waiting_nodes.empty());
	}
}


template<class Entry>
Binary_node<Entry>* Binary_tree<Entry>::createBiTree(Entry *pre, Entry *in, int n)
{

	int i = 0;
	int n1 = 0, n2 = 0;
	int m1 = 0, m2 = 0;
	Binary_node<Entry> *node = NULL;
	char lpre[100], rpre[100];
	char lin[100], rin[100];
	if (n == 0)
	{
		return NULL;
	}

	node = (Binary_node<Entry>*)malloc(sizeof(Binary_node<Entry>));

	if (node == NULL)
	{
		return NULL;
	}

	memset(node, 0, sizeof(Binary_node<Entry>));
	//先序序列的第一个元素必为根结点  
	node->data = pre[0];
	//根据根结点将中序序列分为左子树和右子数  
	for (i = 0; i<n; i++)
	{
		if ((i <= n1) && (in[i] != pre[0]))
		{
			lin[n1++] = in[i];
		}
		else if (in[i] != pre[0])
		{
			rin[n2++] = in[i];
		}
	}
	//根据树的先序序列的长度等于中序序列的长度  
	//且先序遍历是先左子树再后子树,无论先序还是中序 左子树和右子树的长度都是固定的  
	//主意 从i=1开始 因为先序遍历的第一个是根   
	for (i = 1; i < n; i++)
	{
		if (i< (n1 + 1))//n1代表了左子树的长度  
		{
			lpre[m1++] = pre[i];
		}
		else
		{
			rpre[m2++] = pre[i];
		}
	}
	node->left = createBiTree(lpre, lin, n1);
	node->right = createBiTree(rpre, rin, n2);
	root = node;
	return node;
}