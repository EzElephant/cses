#include <bits/extc++.h>
using namespace std;
typedef long long ll;

mt19937 rng(random_device{}());

struct treap
{
    treap *lc = nullptr, *rc = nullptr;
    bool tag;
    int pri, size;
    ll sum, val;
    treap(int val) : pri(rng()), size(1), val(val), sum(val), tag(false) {}
    void pull();
    void push();
};

inline int treap_size(treap *root)
{
    return root ? root->size : 0;
}

void treap::pull()
{
    size = 1 + treap_size(lc) + treap_size(rc);
    sum = val;
    if (lc)
        sum += lc->sum;
    if (rc)
        sum += rc->sum;
}

void treap::push()
{
    if (!tag)
        return;
    swap(lc, rc);
    if (lc)
        lc->tag ^= true;
    if (rc)
        rc->tag ^= true;
    tag = false;
}

treap *merge(treap *a, treap *b)
{
    if (!a || !b)
        return a ? a : b;
    if (a->pri < b->pri)
    {
        a->push();
        a->rc = merge(a->rc, b);
        a->pull();
        return a;
    }
    else
    {
        b->push();
        b->lc = merge(a, b->lc);
        b->pull();
        return b;
    }
}

pair<treap *, treap *> splitk(treap *root, int k)
{
    treap *a = nullptr, *b = nullptr;
    if (!root)
        return {a, b};
    root->push();
    if (treap_size(root->lc) < k)
    {
        a = root;
        tie(a->rc, b) = splitk(root->rc, k - treap_size(root->lc) - 1);
    }
    else
    {
        b = root;
        tie(a, b->lc) = splitk(root->lc, k);
    }
    root->pull();
    return {a, b};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    treap *root = nullptr;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        root = merge(root, new treap(tmp));
    }
    while (m--)
    {
        int op, l, r;
        cin >> op >> l >> r;
        auto [a, b] = splitk(root, l - 1);
        auto [c, d] = splitk(b, r - l + 1);
        c->push();
        if (op == 1)
            c->tag ^= true;
        else
            cout << c->sum << '\n';
        root = merge(merge(a, c), d);
    }

    return 0;
}