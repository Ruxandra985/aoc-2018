#include <cstdio>

using namespace std;
int v[50000010],w[10];
int main()
{
    FILE *fin=fopen ("a.in","r");
    FILE *fout=fopen ("a.out","w");
    int n,elem,p,q,sum,newp,newq,i,j;
    char c;
    c=fgetc (fin);
    n=0;
    while ('0'<=c && c<='9'){
        n=n*10+c-'0';
        w[++w[0]]=c-'0';
        c=fgetc (fin);
    }
    v[0]=3;
    v[1]=7;
    elem=2;
    p=0;
    q=1;
    for (;elem<=50000000;){
        sum=v[p]+v[q];
        if (sum<10){
            elem++;
            v[elem-1]=sum;
        }
        else {
            elem+=2;
            v[elem-2]=sum/10;
            v[elem-1]=sum%10;
        }
        //if (elem==19)
          //  printf ("a");
        //printf ("%d ",elem);
        p=(p+v[p]+1)%elem;
        q=(q+v[q]+1)%elem;
    }
    //printf ("%d ",elem);
    for (i=0;i+w[0]-1<=elem;i++){
        for (j=1;j<=w[0];j++){
            if (v[i+j-1]!=w[j])
                break;
        }
        if (j>w[0]){
            fprintf (fout,"%d",i);
            return 0;
        }
    }
    return 0;
}
