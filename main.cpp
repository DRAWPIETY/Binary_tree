#include "Utility.h"
//#include "Binary_tree.h"
#include"Binary_tree.cpp"
#define N 100


void test_creat_tree()
{
	cout << endl;
	cout << "��ʼ�����������д���һ��������" << endl;
	char preNode[N];
	char inNode[N];
	int n = 0;
	char ch;
	cout << "��������������:";
	while ((ch = getchar()) && ch != '\n')
		preNode[n++] = ch;
	n = 0;
	cout << "��������������:";;
	while ((ch = getchar()) && ch != '\n')
		inNode[n++] = ch;
	Binary_tree<char> A;
	A.createBiTree(preNode, inNode, n);

	cout << "�������д����Ķ������߶�Ϊ:" << A.height() << endl;
	cout << "�������д����Ķ����������Ϊ:" << A.size() << endl;
	cout << "�������д����Ķ�����Ҷ����Ϊ:" << A.leaf_count() << endl;
	cout << "�������д����Ķ�������ǰ�����Ϊ:";
	A.NoRePreorder();
	cout << endl;
	cout << "�������д����Ķ��������������Ϊ:";
	A.NoReInorder();
	cout << endl;
}

void main()
{
	Binary_tree<char> TA;

	if (TA.empty())
	{
		cout << "����Ϊ��" << endl;
	}

	string s = "ABCDEFGHIJK";
	for (unsigned int i = 0; i < s.size(); i++)
	{
		TA.insert(s[i]);
	}


	cout << "TAǰ�����:";
	TA.NoRePreorder();
	cout << endl;
	cout << "TA�������:";
	TA.NoReInorder();
	cout << endl;

	cout << "�����:" << TA.size() << endl;
	cout << "Ҷ����:" << TA.leaf_count() << endl;
	cout << "�߶�:" << TA.height() << endl;

	Binary_tree<char> TB(TA);
	cout << "TBǰ�����:";
	TB.NoRePreorder();
	cout << endl;

	Binary_tree<char> TC = TA;
	cout << "TC�������:";
	TC.NoReInorder();
	cout << endl;

	TC.clear();
	cout << "TCʹ��clear����������Ϊ:" << TC.size() << endl;

	test_creat_tree();

}