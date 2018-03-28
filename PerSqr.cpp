/*
算法题：完美平方
给一个正整数 n，写一个函数找到若干个完全平方数（比如 1，4，9，...）使得他们的和等于 n。要求为你需要让平方数的个数最少，输出需要的最少的平方数的个数。
格式：
输入每一行输入一个 整数 n，输出每一行输出需要最少的平方数的个数。
样例输入
n = 12
n = 13
样例输出
3  
//12 = 4 + 4 + 4
2 
//13 = 4 + 9
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	while (1)
	{
		//flag为小于n的最大平方数的平方根
		int n,flag=1,flag2,n2,num,i,nR;
		vector<int> v;
		vector<vector<int>> vv,vv2;
		cout << "请输入一个正整数:";
		cin >> n;
		if (n <= 0)
		{
			cout << "input error!" << endl;
			return 0;
		}
		while (1)
		{
			if (flag*flag <= n)
				flag++;
			else
			{
				flag--;break;
			}
		}
		//如果最大平方数正好等于n，则输出
		if (flag*flag == n)
		{
			cout << flag<<endl;
			return 0;
		}
		//把得到的平方根添加到容器，容器内数据相加等于n，其中每个容器平方根最大为flag
		flag2 = flag;
		nR = n;
		while (flag2)
		{
			flag = flag2;
			n = nR;
			v.swap(vector<int>());
			while ((n - flag*flag >= 0) && (flag - 1>=0))
			{
				n2 = n - flag*flag;
				if (flag == 0) break;
				v.push_back(flag);
				while (1)
				{
					if (n2 - flag*flag < 0)
						--flag;
					else
					{
						n = n2; break;
					}
				}
			}
			vv.push_back(v);
			--flag2;
		}
		num = vv.size();
		flag = vv[0].size();
		for (i = 0; i < num; i++)
		{
			if (flag >= vv[i].size())
				flag = vv[i].size();
		}
		for (i = 0; i < num; i++)
		{
			if (vv[i].size() == flag)
				vv2.push_back(vv[i]);
		}
		cout << "个数最少为：" << flag << "个"<<endl;
		cout << "有" << vv2.size() << "种情况" << endl;
		for (i = 0; i < vv2.size(); i++)
		{
			for (auto j : vv2[i])
				cout << j*j << " ";
			cout << endl;
		}
		cout << "==============================="<< endl;
		
	}
}
