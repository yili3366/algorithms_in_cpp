Item max(Item a[], int l, int r)
{
    if (l == r)
        return a[l];

    int m = (l + r) / 2;
    Item u = max(a, l, m);
    Item v = max(a, m+1, r);

    if (u > v) {
        return u;
    } else {
        return v;
    }
}
