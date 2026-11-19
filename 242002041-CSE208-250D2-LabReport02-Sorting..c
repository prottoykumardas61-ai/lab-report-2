
#include <stdio.h>

int mc = 0, qc = 0;


void merge(int a[], int l, int m, int r)
{
    int temp[1000];
    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r)
    {
        mc++;

        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m)
        temp[k++] = a[i++];

    while (j <= r)
        temp[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++)
        a[i] = temp[k++];
}

void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}


int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        qc++;

        if (a[j] <= pivot)
        {
            i++;

            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }

    int t = a[i + 1];
    a[i + 1] = a[high];
    a[high] = t;

    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}


void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main()
{
    int n, m;
    int a[1000], b[1000], q[1000], c[2000];

    printf("Enter N and M: ");
    scanf("%d %d", &n, &m);

    printf("Enter original array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        q[i] = a[i];
    }

    printf("Enter sorted new array: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);


    mergeSort(a, 0, n - 1);

    printf("\nMerge Sort: ");
    print(a, n);


    quickSort(q, 0, n - 1);

    printf("Quick Sort: ");
    print(q, n);

    printf("Merge Comparisons: %d\n", mc);
    printf("Quick Comparisons: %d\n", qc);


    int i = 0, j = 0, k = 0;

    while (i < n && j < m)
    {
        if (a[i] <= b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    while (i < n)
        c[k++] = a[i++];

    while (j < m)
        c[k++] = b[j++];

    printf("Updated Array: ");
    print(c, n + m);

    return 0;
}
