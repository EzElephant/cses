#include <bits/extc++.h>
using namespace std;

mt19937 rng(random_device{}());

struct treap
{
    treap *lc = nullptr, *rc = nullptr;
    int pri, size, key, val;
    bool tag;
    treap(int key) : pri(rng()), size(1), key(key), val(key), tag(false) {}
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
    key = val;
    if (lc)
        key = max(lc->key, key);
    if (rc)
        key = max(rc->key, key);
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
    if (root->key < key)
    {
        a = root;
        tie(a->rc, b) = split(root->rc, key);
    }
    else
    {
        b = root;
        tie(a, b->lc) = split(root->lc, key);
    }
    root->pull();
    return {a, b};
}

void insert(treap *&root, int key)
{
    auto [a, b] = split(root, key);
    root = merge(a, merge(new treap(key), b));
}

treap *&find(treap *&root, int key)
{
    if (!root || root->key == key)
        return root;
    return find(key < root->key ? root->lc : root->rc, key);
}

bool erase(treap *&root, int key)
{
    treap *&x = find(root, key);
    if (!x)
        return false;
    treap *tmp = x;
    x = merge(x->lc, x->rc);
    delete tmp;
    return true;
}

int ranK(treap *&root, int key)
{
    auto [a, b] = split(root, key);
    int ans = treap_size(a);
    root = merge(a, b);
    return ans;
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

int kth(treap *&root, int k)
{
    auto [a, b] = splitk(root, k);
    auto [c, d] = splitk(a, k - 1);
    int ans = d->key;
    root = merge(a, merge(c, d));
    return ans;
}

void dfs(treap* root)
{
    root->push();
    if (root->lc)
        dfs(root->lc);
    cout << root->val << ' ';
    if (root->rc)
        dfs(root->rc);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    vector<pair<int, int>> ans;
    treap *root = nullptr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        root = merge(root, new treap(tmp));
    }
    for (int i = n; i > 0; i--)
    {
        int l = 1, r = i;
        while (l < r)
        {
            int mid = (l + r) / 2;
            auto [a, b] = splitk(root, mid);
            if (a->key == i)
                r = mid;
            else
                l = mid + 1;
            merge(a, b);
        }
        if (l != i)
        {
            ans.emplace_back(l, i);
            auto [a, b] = splitk(root, l - 1);
            auto [c, d] = splitk(b, i + 1 - l);
            c->tag ^= true;
            merge(merge(a, c), d);
        }
        // dfs(root);
        // cout << '\n';
    }
    cout << ans.size() << '\n';
    for (auto [l, r] : ans)
        cout << l << ' ' << r << '\n';

    return 0;
}