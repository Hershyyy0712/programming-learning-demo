#include <iostream>
#include <string>
#include<cmath>
#include <vector>
#include <algorithm>
using namespace std;

bool bigger(vector<int>a, vector<int>b)
{
	if (a.size() > b.size())
		return 1;
	else if (a.size() < b.size())
		return 0;
	else
	{
		for (int i = a.size() - 1; i >= 0; i--)
		{
			if (a[i] > b[i])
				return 1;
			if (a[i] < b[i])
				return 0;
		}
		
	}
	return 1;
}
vector<int> change(int x)
{
	vector<int> res;
	int cnt = 0;
	int temp = x;
	while (temp > 0)
	{
		temp /= 10;
		cnt++;
	}
	for (int i = 0; i < cnt; i++)
	{
		res.push_back(x / (int)pow(10, i) % 10);
	}
	return res;

}




vector<int> add(vector<int> a, vector <int> b)
{
	vector<int> res;
	int carry = 0;
	
	int m = b.size();
	if (a.size() >= m)
	{
		for (int i = m; i < a.size(); i++)
			b.push_back(0);
	}
	else
	{
		for (int i = a.size(); i < m; i++)
			a.push_back(0);
	}
	for (int i = 0; i < a.size() || carry; i++)
	{
		carry += a[i] + b[i];
		res.push_back(carry % 10);
		carry /= 10;

	}
	return res;
}


vector<int> mul(vector<int> a, vector<int> b)
{
	int n = a.size();
	int m = b.size();
	int carry = 0;
	vector<int> res(n+m,0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			res[i + j] += a[i] * b[j];
		}
	}

	for (int i = 0; i < res.size(); i++)
	{
		int total = res[i] + carry;
		res[i] = total % 10;
		carry =total/10;
	}
	while (res.size() > 1 && res.back() == 0)
		res.pop_back();
	return res;
}

//baozheng a>b;
vector<int> minu(vector<int> a, vector<int>b)
{
	vector<int> res;

	int m = b.size();
	int borrow = 0;
	for (int i = m; i < a.size(); i++)
		b.push_back(0);
	for (int i = 0; i < a.size(); i++)
	{
		res.push_back((a[i] - b[i] - borrow + 10) % 10);
		if (a[i] - borrow < b[i])
			borrow = 1;
		else
			borrow = 0;
	}

	while (res.size() > 1 && res.back() == 0)
		res.pop_back();
	return res;
}

//baozheng a>b;
vector<int> div(vector<int> a, vector<int> b, vector<int>& rem) {
	vector<int> quotient; 
	vector<int> temp;     
	if (b.size() == 1 && b[0] == 0) 
	{
		rem = { 0 };
		return { 0 };
	}

	for (int i = a.size() - 1; i >= 0; i--) {
		
		temp.push_back(a[i]);
		while (temp.size() > 1 && temp[0] == 0) 
		{
			temp.erase(temp.begin());
		}

		vector<int> temp_rev(temp.rbegin(), temp.rend());

		int cnt = 0;
		while (bigger(temp_rev, b)) {
			temp_rev = minu(temp_rev, b);
			cnt++;
		}

		quotient.push_back(cnt);

		temp = vector<int>(temp_rev.rbegin(), temp_rev.rend());
	}
	while (quotient.size() > 1 && quotient[0] == 0) {
		quotient.erase(quotient.begin());
	}


	rem = temp;

	while (rem.size() > 1 && rem[0] == 0) {
		rem.erase(rem.begin());
	}


	reverse(quotient.begin(), quotient.end());
	return quotient;
}





vector<int> jiecheng(int x)
{
	vector<int> ans;
	ans.push_back(1);
	for (int i = 2; i <= x; i++)
	{
		ans = mul(ans, change(i));
	}

	return ans;
}

int main()
{
	string s1;
	string s2;
	cin >> s1;
	cin >> s2;
	vector<int> a;
	vector<int> b;
	for (int i = s1.size()-1; i >= 0; i--)
		a.push_back( s1[i] - '0');
	for (int i = s2.size()-1; i >= 0; i--)
		b.push_back( s2[i] - '0');
	
	vector<int> rem;

	if (bigger(a, b))
	{
		
		vector<int> res = div(a, b,rem);
		reverse(res.begin(), res.end());
		cout << "result:";
		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i];
		}
		cout << endl<< "rem:";
		for (int i = 0; i < rem.size(); i++)
		{
			cout << rem[i];
		}
	}
	/*else
	{
		vector<int> res = minu(b, a);
		reverse(res.begin(), res.end());
		cout << '-';
		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i];
		}

	}*/
	

	return 0;
}
