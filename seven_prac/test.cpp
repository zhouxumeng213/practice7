#include<stdio.h>
#include<list>
#include<assert.h>

//题目一：求树中两个结点的最低公共祖先
//
//思路：可以分为三种树，三种不同的情况：1、该树是普通树；2、该树是普通树，但是有指向父结点
//的指针；3、该树是一颗二叉搜索树。
//
//1、处理是普通树且没有指向父结点指针的情况
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
			cout << "无公共节点" << endl;
		return common;
	}

	int _LCA(Node* root, const K& key1, const K& key2, Node*& common)//普通二叉树
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

//2、处理该树是普通二叉数，但是有指向父结点的指针
//思路(1)：如果一颗二叉树有指向父结点的指针，可以将其转化为一个双向链表，要求两个结点的最低
//公共祖先，就是求双向链表的第一个公共结点
//
//思路(2)：求出两个结点的深度，深一点的结点先走深度差步，然后两个结点向上走，直到走到公共
//父结点为止。
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
	//求树的结点的深度
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
		//求出两个结点的深度差
		int ret = lenth(node1) - lenth(node2);
		//深度大的结点向上走深度差步
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
		//依次向上找最近的公共结点
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

//3、处理该树是一颗二叉搜索树
//思路：由于二叉搜索树是排序的，可以比较两个结点和根结点值得大小，判断是在根结点的左子树
//还是右子树，如果一个在左子树，一个在右子树，则根结点就是最近的公共结点，否则递归到根结点
//的左子树或者右子树判断
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
			//两个结点都在根结点的左子树中
			if ((root->data) > (node1->data) && (root->data) > (node2->data))
				root = root->left;
			//两个结点都在根结点的右子树中
			else if ((root->data) < (node1->data) && (root->data) < (node2->data))
				root = root->right;
			//分别在做右子树中，即找到最近公共结点
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



//题目二：从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2-10为数字本身
//A为1，J为11，Q为12，K为13，大王小王可以看成任意数字。
//
//思路：可以将这5张牌看成是数组中的5个数字，大小王可以用0来代替。要判断5张牌是不是顺子，即就是
//判断数组中的数字是不是连续的，0可以看成任意数。所以可以将数组排序，如果排序之后两个数字之间
//有间隔，可以用0代替。可以用3个步骤来完成：1、将数组排序；2、统计数组中0的个数；3、统计排序
//之后的数组中相邻数字之间的空缺总数，如果空缺总数小于或等于0的个数，则这个数组是连续的，否则
//是不连续的。

//对数组进行排序
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

	//统计数组中0的个数
	int numOfZero = 0;
	for (int i = 0; i < len&&nums[i] == 0; i++)
		numOfZero++;
	//统计数组中的间隔数目
	int numOfGap = 0;
	int small = numOfZero;
	int big = small + 1;
	while (big < len)
	{
		//扑克牌中有对子
		if (nums[small] == nums[big])
			return false;
		//计算间隔数目
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


//题目三：0，1...n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里删除第m个数字。求出
//这个圆圈里剩下的最后一个数字。
//
//解法1、用环形链表模拟圆圈，可以使用STL中的list。但是这种解法需要多次遍历环形链表，时间复杂度
//为0(mn),空间复杂度为O(n).

int LastExistNum(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
		return -1;
	unsigned int i = 0;

	//将数据插进链表中
	std::list<int> numbers;
	for (; i < n; i++)
	{
		numbers.push_back(i);
	}

	std::list<int>::iterator current = numbers.begin();
	while (numbers.size()>1)
	{
		//找第m个数
		for (int i = 1; i < m; i++)
		{
			current++;
			//如果迭代器到链表尾，要将它置到begin
			if (current == numbers.end())
				current = numbers.begin();
		}
		//保存要删除结点的下一个节点，以便下一次重新开始
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

//解法2、利用数学公式推导到一个递归公式。要得到n个数字序列中最后剩下的数字，只需要得到n-1个数字
//的序列中最后剩下的数字，并以此类推。用递归和循环都可以解决

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





//题目四：求1+2+...+n,要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件
//判断语句。
//
//解法1、利用构造函数求解
class Add
{
public:
	Add()
	{
		++n;
		sum += n;
	}
	//初始化
	static void Reset()
	{
		n = 0;
		sum = 0;
	}
	//获取最后的结果
	static unsigned int GetSum()
	{
		return sum;
	}
private:
	static unsigned int n;
	static unsigned int sum;
};
//静态成员变量在类外进行初始化
unsigned int Add::n = 0;
unsigned int Add::sum = 0;

unsigned int AddSum(unsigned int n)
{
	//定义n个该类型的实例
	Add* a = new Add[n];
	delete []a;
	a = NULL;
	return Add::GetSum();
}


//解法2、利用虚函数求解

//思路：既然不能用递归，则可以用两个函数来实现，一个负责递归，一个负责递归返回的条件，需要
//做的就是在两个函数里二选一。可以用布尔型变量来定义

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


//解法3、利用函数指针求解

//在C语言的环境中，不能用虚函数，此时可以用函数指针来模拟。
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

//解法4、利用模板类型来求解

//当编译器看到Sum_Solution1<100>时，就会为模板类Sum_Solution1以参数100生成该类型的代码。由于
//这个过程是在编译期间完成的，因此要求输入n必须是在编译期间就能确定的常量，不能动态输入。
template<unsigned int n> struct Sum_Solution1
{
	enum Value{N=Sum_Solution1<n-1>::N+n};
};
template<>struct Sum_Solution1<1>
{
	enum Value{N=1};
};



//题目五：写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

//思路：既然不能用四则运算符号，就只能用位运算，分三步来进行，1、不管进位，先加两个数；2、判断
//有没有进位；3、把前面的两个结果加起来

int Add(int num1, int num2)
{
	int sum, up;
	do
	{
		//异或运算：不考虑进位，先加（二进制1+1=0，0+0=0，1+0=1，0+1=1）即二进制的异或
		sum = num1 ^ num2;
		//up保存进位，up不为0，说明有进位，要将其加到之前加的和中
		up = (num1&num2) << 1;


		//更新num1和num2，知道没有进位产生
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



//题目六：用C++设计一个不能被继承的类

//解法1：将构造函数和析构函数设为私有的
//缺点：只能得到位于堆上的实例，而得不到位于栈上的
class SealedClass
{
public:
	//将构造函数和析构函数定义为私有，类外不能创建类的对象，所以定义一个静态的成员函数来获取
	//类的实例，该类也不能被继承，因为继承的类调用父类的构造函数和析构函数时会出错
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

//解法2、利用友元和虚继承来完成

//SealedClass2和一般的类没有区别，它虚继承了MakeSealed，因为SealedClass2是MakeSealed的友元函数，
//所以在SealedClass2中调用 MakeSealed<SealedClass2>不会有错误。并且不能从SealedClass2继承一个类
//因为SealedClass2继承了MakeSealed，在调用构造函数时，会直接调用MakeSealed的，但只有SealedClass2
//是MakeSealed的友元函数，所以会有错误。
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



//题目七：实现一个函数，将字符串转换成整数
long long _StrToInt(const char* str, bool minus);

//用全局变量来区分是字符串为空返回0，还是输入字符‘0’而返回0
enum Status{kValid,kInvalid};
int g_status = kValid;
int StrToInt(const char* str)
{
	g_status = kInvalid;
	long long num = 0;
	if (str != NULL && *str != '\0')
	{
		//标识是正数还是负数
		bool minus = false;
		//正数
		if (*str == '+')
			str++;
		//负数
		else if (*str == '-')
		{
			str++;
			minus = true;
		}
		//正常的输入
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
			//计算每个字符对应的整形数
			int flag = minus ? -1 : 1;
			num = num * 10 + flag*(*str - '0');
			//判断是否溢出
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