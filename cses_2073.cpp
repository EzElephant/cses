#include <bits/extc++.h>
using namespace std;

mt19937 rng(random_device{}());

struct treap
{
    treap *lc = nullptr, *rc = nullptr;
    bool tag;
    char key;
    int pri, size;
    treap(char key) : pri(rng()), size(1), key(key), tag(false) {}
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

pair<treap *, treap *> split(treap *root, int key)
{
    treap *a = nullptr, *b = nullptr;
    if (!root)
        return {a, b};
    root->push();
    if (treap_size(root->lc) < key)
    {
        a = root;
        tie(a->rc, b) = split(root->rc, key - treap_size(root->lc) - 1);
    }
    else
    {
        b = root;
        tie(a, b->lc) = split(root->lc, key);
    }
    root->pull();
    return {a, b};
}

void dfs(treap* root)
{
    root->push();
    if (root->lc)
        dfs(root->lc);
    cout << root->key;
    if (root->rc)
        dfs(root->rc);
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
        char ch;
        cin >> ch;
        root = merge(root, new treap(ch));
    }
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        auto [a, b] = split(root, l - 1);
        auto [c, d] = split(b, r - l + 1);
        c->tag ^= true;
        root = merge(merge(a, c), d);
    }
    dfs(root);
    cout << '\n';

    return 0;
}