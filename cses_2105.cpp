#include <bits/extc++.h>
using namespace std;
const int MAXN = 1e5 + 87;
char s[MAXN];
int sa[MAXN], rk[MAXN], tmp[MAXN], h[MAXN];

struct CMP
{
	int len, k, *rank, a, b;
	inline bool operator()(int i, int j)
	{
		if (rank[i] != rank[j])
			return rank[i] < rank[j];
		a = (i += k) < len ? rank[i] : -1;
		b = (j += k) < len ? rank[j] : -1;
		return a < b;
	}
};
inline void suffix_array(const char *s, int len, int *sa, int *rank, int *tmp)
{
	for (int i = 0; i < len; ++i)
	{
		sa[i] = i;
		rank[i] = s[i];
	}
	CMP cmp = {len, 1};
	for (;; cmp.k <<= 1)
	{
		cmp.rank = rank;
		sort(sa, sa + len, cmp);
		tmp[sa[0]] = 0;
		for (int i = 1; i < len; ++i)
			tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
		if (tmp[sa[len - 1]] == len - 1)
			break;
		swap(rank, tmp);
	}
}

// LCP
inline void suffix_array_lcp(const char *s, int len, int *h, int *sa, int *rank)
{
	for (int i = 0; i < len; ++i)
		rank[sa[i]] = i;
	for (int i = 0, k = 0; i < len; ++i)
	{
		if (rank[i] == 0)
			continue;
		if (k)
			--k;
		while (s[i + k] == s[sa[rank[i] - 1] + k])
			++k;
		h[rank[i]] = k;
	}
	h[0] = 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;
	int n = strlen(s);
	int64_t cnt = 0;
	suffix_array(s, n, sa, rk, tmp);
	suffix_array_lcp(s, n, h, sa, rk);
	for (int i = 0; i < n; i++)
		cnt += h[i];
	cout << n * (n + 1LL) / 2 - cnt << '\n';

	return 0;
}