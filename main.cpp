#include "Utility.h"
//#include "Binary_tree.h"
#include"Binary_tree.cpp"
#define N 100


void test_creat_tree()
{
	cout << endl;
	cout << "开始测试两个序列创建一个二叉树" << endl;
	char preNode[N];
	char inNode[N];
	int n = 0;
	char ch;
	cout << "请输入先序序列:";
	while ((ch = getchar()) && ch != '\n')
		preNode[n++] = ch;
	n = 0;
	cout << "请输入中序序列:";;
	while ((ch = getchar()) && ch != '\n')
		inNode[n++] = ch;
	Binary_tree<char> A;
	A.createBiTree(preNode, inNode, n);

	cout << "由两序列创建的二叉树高度为:" << A.height() << endl;
	cout << "由两序列创建的二叉树结点数为:" << A.size() << endl;
	cout << "由两序列创建的二叉树叶子数为:" << A.leaf_count() << endl;
	cout << "由两序列创建的二叉树的前序遍历为:";
	A.NoRePreorder();
	cout << endl;
	cout << "由两序列创建的二叉树的中序遍历为:";
	A.NoReInorder();
	cout << endl;
}

void main()
{
	Binary_tree<char> TA;

	if (TA.empty())
	{
		cout << "该树为空" << endl;
	}

	string s = "ABCDEFGHIJK";
	for (unsigned int i = 0; i < s.size(); i++)
	{
		TA.insert(s[i]);
	}


	cout << "TA前序遍历:";
	TA.NoRePreorder();
	cout << endl;
	cout << "TA中序遍历:";
	TA.NoReInorder();
	cout << endl;

	cout << "结点数:" << TA.size() << endl;
	cout << "叶子数:" << TA.leaf_count() << endl;
	cout << "高度:" << TA.height() << endl;

	Binary_tree<char> TB(TA);
	cout << "TB前序遍历:";
	TB.NoRePreorder();
	cout << endl;

	Binary_tree<char> TC = TA;
	cout << "TC中序遍历:";
	TC.NoReInorder();
	cout << endl;

	TC.clear();
	cout << "TC使用clear函数后结点数为:" << TC.size() << endl;

	test_creat_tree();

}