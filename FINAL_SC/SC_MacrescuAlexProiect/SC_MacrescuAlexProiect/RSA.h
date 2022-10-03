#pragma once
#include <stdio.h>
#include <iostream>
using namespace std;
class RSA
{

	long int p, q, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i;
	char msg[100];

	int prime(long int pr)
	{
		int i;
		j = sqrt(pr);
		for (i = 2; i <= j; i++)
		{
			if (pr % i == 0)
				return 0;
		}
		return 1;
	}
	long int cd_RSA(long int x)
	{
		long int k = 1;
		while (1)
		{
			k = k + t;
			if (k % x == 0)
				return (k / x);
		}
	}
	void ce_RSA()
	{
		int k;
		k = 0;
		for (i = 2; i < t; i++)
		{
			if (t % i == 0)
				continue;
			flag = prime(i);
			if (flag == 1 && i != p && i != q)
			{
				e[k] = i;
				flag = cd_RSA(e[k]);
				if (flag > 0)
				{
					d[k] = flag;
					k++;
				}
				if (k == 99)
					break;
			}
		}
	}
	void encrypt_RSA()
	{
		long int pt, ct, key = e[0], k, len;
		i = 0;
		len = strlen(msg);
		while (i != len)
		{
			pt = m[i];
			pt = pt - 96;
			k = 1;
			for (j = 0; j < key; j++)
			{
				k = k * pt;
				k = k % n;
			}
			temp[i] = k;
			ct = k + 96;
			en[i] = ct;
			i++;
		}
		en[i] = -1;
		cout << "\nTHE ENCRYPTED MESSAGE IS\n";
		for (i = 0; en[i] != -1; i++)
			printf("\\x%02hhx", en[i]);
	}
	void decrypt_RSA()
	{
		long int pt, ct, key = d[0], k;
		i = 0;
		while (en[i] != -1)
		{
			ct = temp[i];
			k = 1;
			for (j = 0; j < key; j++)
			{
				k = k * ct;
				k = k % n;
			}
			pt = k + 96;
			m[i] = pt;
			i++;
		}
		m[i] = -1;
		cout << "\nTHE DECRYPTED MESSAGE IS\n";
		for (i = 0; m[i] != -1; i++)
			printf("%c", m[i]);
	}
public: int runRSA()
{
	cout << "\nENTER FIRST PRIME NUMBER\n";
	do {
		cin >> p;
		flag = prime(p);
		if (flag == 0)
		{
			cout << "\nWRONG INPUT\n";
		}
	} while (!flag);

	int flag2 = 0;
	do {
		std::cout << "\nENTER ANOTHER PRIME NUMBER\n";
		std::cin >> q;
		flag = prime(q);
		if (flag == 0 || p == q)
		{
			cout << "\nWRONG INPUT\n";
			flag2 = 0;
		}
		else flag2 = 1;
	} while (!flag2);
	cout << "\nENTER MESSAGE\n";
	fflush(stdin);
	cin >> msg;
	for (i = 0; msg[i] != '\0'; i++)
		m[i] = msg[i];
	n = p * q;
	t = (p - 1) * (q - 1);
	ce_RSA();
	encrypt_RSA();
	decrypt_RSA();
	return 0;
}
};