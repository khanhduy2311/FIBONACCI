#include<bits/stdc++.h>
using namespace std;
//Use maths of CSC
long long fibo(int n)
{
	double phi= (1+sqrt(5)) /2 ;
	return round(pow(phi,n)/sqrt(5));
}
//Use matrix
long long fibo1(int n)
{
	int M[2][2]={{1,1},{1,0}};
	int F[2][2]={{1,1},{1,0}};
	for (int i=2;i<=n;i++)
	{
		int s1 = F[0][0] * M[0][0] + F[0][1] * M[1][0];
		int s2 = F[0][0] * M[0][1] + F[0][1] * M[1][1];
		int s3 = F[1][0] * M[0][0] + F[1][1] * M[1][0];
		int s4 = F[1][0] * M[0][1] + F[1][0] * M[1][1];
		F[0][0]=s1;
		F[0][1]=s2;
		F[1][0]=s3;
		F[1][1]=s4;
	}
	return F[0][0];
}
//Use map and DQ
long long fibo2(int n)
{
	map<long , long> F;
	if (F.count(n))
		return F[n];
	long k=n/2;
	if (n%2==0)
		return F[n] = (fibo2(k)*fibo2(k) + fibo2(k-1)*fibo2(k-1));
	else 
		return F[n] = (fibo2(k)*fibo2(k+1)+ fibo2(k-1)*fibo2(k));
}
main()
{
	int n;
	cin >> n;
	cout << fibo(n);
}
