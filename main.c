#include <stdio.h>
#include <stdlib.h>

void pomenyatt (int*a, int*b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

int lopopam (int a[], int n, int* sr, int* per)
{
    int i=0, j=n-1, m=a[n/2];
    do
    {

        while (i != n/2 && a[i] < m)
            i++,
            *sr+=1;
        if(i != n/2)
            *sr+=1;
        while (j != n/2 && a[j] > m)
            j--,
            *sr+=1;
        if(j != n/2)
            *sr+=1;
        if (i<j)
            pomenyatt(&a[i], &a[j]),
            *per+=1,
            --j,++i;
    }
    while (i < j);
    return i;
}

void s(int a[], int n, int* sr, int* per)
{
    int k;
    if(n>1)
    {
        k=lopopam(a, n, sr, per);
        if (k==0){
            s(a+1,n-1,sr,per);
            return;
        }
        if(k == n-1)
        {
            s(a,n-1,sr,per);
            return;
        }
        s(a, k, sr, per);
        s(a+k, n-k, sr, per);
    }

}

int main()
{
    int n, i, sr=0, per=0;
    printf("kol-vo elementov = ");
    scanf("%d", &n);
    int* a;
    a = (int*) malloc(n*sizeof(int));
    for (i=0; i<n; i++)
    {
        printf("a[%d]=", i);
        scanf("%d", a+i);
    }
    s(a, n, &sr, &per);
    for (i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\nsravneniy = %d perestanovok = %d", sr, per);
    return 0;
}
