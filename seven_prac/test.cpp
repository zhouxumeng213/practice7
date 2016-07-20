#include<stdio.h>
#include<list>
#include<assert.h>

//��Ŀһ������������������͹�������
//
//˼·�����Է�Ϊ�����������ֲ�ͬ�������1����������ͨ����2����������ͨ����������ָ�򸸽��
//��ָ�룻3��������һ�Ŷ�����������
//
//1����������ͨ����û��ָ�򸸽��ָ������
#include<iostream>
using namespace std;
template<class T>
struct BinaryTreeNode
{
	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;
	T data;
};

template<class T>
class Tree
{
	typedef BinaryTreeNode<T> Node;
public:
	Node*  LCA(const K& key1, const K& key2)
	{
		Node* common = NULL;
		_LCA(_root, key1, key2, common);
		if (!common)
			cout << "�޹����ڵ�" << endl;
		return common;
	}

	int _LCA(Node* root, const K& key1, const K& key2, Node*& common)//��ͨ������
	{
		if (root)
		{
			int ret = (root->_key == key1 || root->_key == key2) +
				_LCA(root->_left, key1, key2, common) +
				_LCA(root->_right, key1, key2, common);
			if (ret == 2)
			{
				cout << root->_key << endl;
				common = root;
				return 0;
			}
			return ret;
		}
		else
			return 0;
	}
private:
	TreeNode<T> _root;
};

//2�������������ͨ��������������ָ�򸸽���ָ��
//˼·(1)�����һ�Ŷ�������ָ�򸸽���ָ�룬���Խ���ת��Ϊһ��˫������Ҫ�������������
//�������ȣ�������˫������ĵ�һ���������
//
//˼·(2)���������������ȣ���һ��Ľ��������Ȳ��Ȼ��������������ߣ�ֱ���ߵ�����
//�����Ϊֹ��
template<class T>
struct BinaryTreeNode
{
	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;
	BinaryTreeNode<T>* parent;
	T data;
};
template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
public:
	//�����Ľ������
	int lenth(Node* node)
	{
		int len = 0;
		while (node)
		{
			len++;
			node = node->parent;
		}
		return len;
	}
	Node* GetCommonNode(Node* node1, Node* node2)
	{
		//�������������Ȳ�
		int ret = lenth(node1) - lenth(node2);
		//��ȴ�Ľ����������Ȳ
		if (ret > 0)
		{
			for (int i = 0; i < ret; i++)
				node1 = node1->parent;
		}
		else if (ret < 0)
		{
			for (ret; ret < 0; ret++)
				node2 = node2->parent;
		}
		//��������������Ĺ������
		while (node1 != node2)
		{
			node1 = node1->parent;
			node2 = node2->parent;
		}
		cout << node1->data << endl;
		return node1;
	}
private:
	Node* _root;
};

//3�����������һ�Ŷ���������
//˼·�����ڶ���������������ģ����ԱȽ��������͸����ֵ�ô�С���ж����ڸ�����������
//���������������һ������������һ�������������������������Ĺ�����㣬����ݹ鵽�����
//�������������������ж�
template<class T>
struct BinaryTreeNode
{
	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;
	T data;
};
template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
public:
	Node* GetCommNode(Node* node1,Node* node2)
	{
		return _GetCommNode(_root, node1, node2);
	}
	Node* _GetCommNode(Node* root, Node* node1, Node* node2)
	{
		while (root)
		{
			//������㶼�ڸ�������������
			if ((root->data) > (node1->data) && (root->data) > (node2->data))
				root = root->left;
			//������㶼�ڸ�������������
			else if ((root->data) < (node1->data) && (root->data) < (node2->data))
				root = root->right;
			//�ֱ������������У����ҵ�����������
			else
			{
				cout << root->data << endl;
				return root;
			}
		}
		return NULL;
	}
private:
	Node* _root;
};



//��Ŀ�������˿����������5���ƣ��ж��ǲ���һ��˳�ӣ�����5�����ǲ��������ġ�2-10Ϊ���ֱ���
//AΪ1��JΪ11��QΪ12��KΪ13������С�����Կ����������֡�
//
//˼·�����Խ���5���ƿ����������е�5�����֣���С��������0�����档Ҫ�ж�5�����ǲ���˳�ӣ�������
//�ж������е������ǲ��������ģ�0���Կ��������������Կ��Խ����������������֮����������֮��
//�м����������0���档������3����������ɣ�1������������2��ͳ��������0�ĸ�����3��ͳ������
//֮�����������������֮��Ŀ�ȱ�����������ȱ����С�ڻ����0�ĸ���������������������ģ�����
//�ǲ������ġ�

//�������������
void sort(int* array, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (array[j]>array[j + 1])
			{
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
} 
bool IsContinuous(int nums[], int len)
{
	if (nums == NULL || len < 1)
		return false;

	//qsort(nums, len, sizeof(int), compare);
	sort(nums, len);

	//ͳ��������0�ĸ���
	int numOfZero = 0;
	for (int i = 0; i < len&&nums[i] == 0; i++)
		numOfZero++;
	//ͳ�������еļ����Ŀ
	int numOfGap = 0;
	int small = numOfZero;
	int big = small + 1;
	while (big < len)
	{
		//�˿������ж���
		if (nums[small] == nums[big])
			return false;
		//��������Ŀ
		numOfGap += nums[big] - nums[small] - 1;
		small = big;
		++big;
	}
	return (numOfGap>numOfZero) ? false : true;
}
int main()
{
	int arr[] = {1,5,4,3,0};
	printf("%d\n", IsContinuous(arr, 5));
	return 0;
}


//��Ŀ����0��1...n-1��n�������ų�һ��ԲȦ��������0��ʼÿ�δ����ԲȦ��ɾ����m�����֡����
//���ԲȦ��ʣ�µ����һ�����֡�
//
//�ⷨ1���û�������ģ��ԲȦ������ʹ��STL�е�list���������ֽⷨ��Ҫ��α�����������ʱ�临�Ӷ�
//Ϊ0(mn),�ռ临�Ӷ�ΪO(n).

int LastExistNum(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
		return -1;
	unsigned int i = 0;

	//�����ݲ��������
	std::list<int> numbers;
	for (; i < n; i++)
	{
		numbers.push_back(i);
	}

	std::list<int>::iterator current = numbers.begin();
	while (numbers.size()>1)
	{
		//�ҵ�m����
		for (int i = 1; i < m; i++)
		{
			current++;
			//���������������β��Ҫ�����õ�begin
			if (current == numbers.end())
				current = numbers.begin();
		}
		//����Ҫɾ��������һ���ڵ㣬�Ա���һ�����¿�ʼ
		std::list<int>::iterator next = ++current;
		if (next == numbers.end())
			next = numbers.begin();

		--current;
		numbers.erase(current);
		current = next;
	}
	return *(current);
}
int main()
{
	int ret=LastExistNum(5, 3);
	printf("%d\n", ret);
	return 0;
}

//�ⷨ2��������ѧ��ʽ�Ƶ���һ���ݹ鹫ʽ��Ҫ�õ�n���������������ʣ�µ����֣�ֻ��Ҫ�õ�n-1������
//�����������ʣ�µ����֣����Դ����ơ��õݹ��ѭ�������Խ��

int LastExistNum(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
		return -1;
	int last = 0;
	for (int i = 2; i <= n; i++)
	{
		last = (last + m) % i;
	}
	return last;
}
int main()
{
	int ret = LastExistNum(5, 3);
	printf("%d\n", ret);
	return 0;
}





//��Ŀ�ģ���1+2+...+n,Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ�����
//�ж���䡣
//
//�ⷨ1�����ù��캯�����
class Add
{
public:
	Add()
	{
		++n;
		sum += n;
	}
	//��ʼ��
	static void Reset()
	{
		n = 0;
		sum = 0;
	}
	//��ȡ���Ľ��
	static unsigned int GetSum()
	{
		return sum;
	}
private:
	static unsigned int n;
	static unsigned int sum;
};
//��̬��Ա������������г�ʼ��
unsigned int Add::n = 0;
unsigned int Add::sum = 0;

unsigned int AddSum(unsigned int n)
{
	//����n�������͵�ʵ��
	Add* a = new Add[n];
	delete []a;
	a = NULL;
	return Add::GetSum();
}


//�ⷨ2�������麯�����

//˼·����Ȼ�����õݹ飬�����������������ʵ�֣�һ������ݹ飬һ������ݹ鷵�ص���������Ҫ
//���ľ����������������ѡһ�������ò����ͱ���������

class A;
A* Array[2];
class A
{
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return 0;
	}
};

class B :public A
{
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return Array[!!n]->Sum(n - 1) + n;
	}
};

int Sum_Solution(int n)
{
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;

	int value = Array[1]->Sum(n);
	return value;
}


//�ⷨ3�����ú���ָ�����

//��C���ԵĻ����У��������麯������ʱ�����ú���ָ����ģ�⡣
typedef unsigned int(*fun)(unsigned int);

unsigned int Solution_Teminator(unsigned int n)
{
	return 0;
}
unsigned int Sum_Solution(unsigned int n)
{
	static fun f[2] = { Solution_Teminator, Sum_Solution };
	return n + f[!!n](n - 1);
}

//�ⷨ4������ģ�����������

//������������Sum_Solution1<100>ʱ���ͻ�Ϊģ����Sum_Solution1�Բ���100���ɸ����͵Ĵ��롣����
//����������ڱ����ڼ���ɵģ����Ҫ������n�������ڱ����ڼ����ȷ���ĳ��������ܶ�̬���롣
template<unsigned int n> struct Sum_Solution1
{
	enum Value{N=Sum_Solution1<n-1>::N+n};
};
template<>struct Sum_Solution1<1>
{
	enum Value{N=1};
};



//��Ŀ�壺дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/����������š�

//˼·����Ȼ����������������ţ���ֻ����λ���㣬�����������У�1�����ܽ�λ���ȼ���������2���ж�
//��û�н�λ��3����ǰ����������������

int Add(int num1, int num2)
{
	int sum, up;
	do
	{
		//������㣺�����ǽ�λ���ȼӣ�������1+1=0��0+0=0��1+0=1��0+1=1���������Ƶ����
		sum = num1 ^ num2;
		//up�����λ��up��Ϊ0��˵���н�λ��Ҫ����ӵ�֮ǰ�ӵĺ���
		up = (num1&num2) << 1;


		//����num1��num2��֪��û�н�λ����
		num1 = sum;
		num2 = up;
	} while (num2 != 0);
	return num1;
}
int main()
{
	int num1 = 5;
	int num2 = 17;
	int ret = Add(num1, num2);
	printf("%d\n", ret);
}



//��Ŀ������C++���һ�����ܱ��̳е���

//�ⷨ1�������캯��������������Ϊ˽�е�
//ȱ�㣺ֻ�ܵõ�λ�ڶ��ϵ�ʵ�������ò���λ��ջ�ϵ�
class SealedClass
{
public:
	//�����캯����������������Ϊ˽�У����ⲻ�ܴ�����Ķ������Զ���һ����̬�ĳ�Ա��������ȡ
	//���ʵ��������Ҳ���ܱ��̳У���Ϊ�̳е�����ø���Ĺ��캯������������ʱ�����
	static SealedClass* GetInstance()
	{
		return new SealedClass();
	}
	static void DeleteInstance(SealedClass* instance)
	{
		delete instance;
	}
private:
	SealedClass()
	{}
	~SealedClass()
	{}
};

//�ⷨ2��������Ԫ����̳������

//SealedClass2��һ�����û����������̳���MakeSealed����ΪSealedClass2��MakeSealed����Ԫ������
//������SealedClass2�е��� MakeSealed<SealedClass2>�����д��󡣲��Ҳ��ܴ�SealedClass2�̳�һ����
//��ΪSealedClass2�̳���MakeSealed���ڵ��ù��캯��ʱ����ֱ�ӵ���MakeSealed�ģ���ֻ��SealedClass2
//��MakeSealed����Ԫ���������Ի��д���
template<class T>
class MakeSealed
{
	friend T;
private:
	MakeSealed()
	{}
	~MakeSealed()
	{}
};

class SealedClass2:virtual public MakeSealed<SealedClass2>
{
public:
	SealedClass2()
	{}
	~SealedClass2()
	{}
};



//��Ŀ�ߣ�ʵ��һ�����������ַ���ת��������
long long _StrToInt(const char* str, bool minus);

//��ȫ�ֱ������������ַ���Ϊ�շ���0�����������ַ���0��������0
enum Status{kValid,kInvalid};
int g_status = kValid;
int StrToInt(const char* str)
{
	g_status = kInvalid;
	long long num = 0;
	if (str != NULL && *str != '\0')
	{
		//��ʶ���������Ǹ���
		bool minus = false;
		//����
		if (*str == '+')
			str++;
		//����
		else if (*str == '-')
		{
			str++;
			minus = true;
		}
		//����������
		if (*str != '\0')
		{
			num = _StrToInt(str, minus);
		}
	}
	return (int)num;
}
long long _StrToInt(const char* str, bool minus)
{
	long long num = 0;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			//����ÿ���ַ���Ӧ��������
			int flag = minus ? -1 : 1;
			num = num * 10 + flag*(*str - '0');
			//�ж��Ƿ����
			if ((!minus && num > 0x7FFFFFFF) || (minus && num < 0x80000000))
			{
				num = 0;
				break;
			}
			str++;
		}
		else
		{
			num = 0;
			break;
		}
	}
	if (*str == '\0')
	{
		g_status = kValid;
	}
	return num;
}
int main()
{
	char* str = "124";
	int ret = StrToInt(str);
	printf("%d\n", ret);
	return 0;
}