#include <iostream>
#include<stdio.h>

using namespace std;
long mcg(long a,long b);

int main()
{
    int n,i;
    long mus=1,zis=0,zheng;
    cin>>n;
    struct fenshu{
      long zi;
      long mu;
    }a[n];

    for(i=0;i<n;i++){
        scanf("%ld/%ld",&a[i].zi,&a[i].mu);
    }

    for(i=0;i<n;i++){
        mus*=a[i].mu;
    }

    for(i=0;i<n;i++){
        a[i].zi=mus/(a[i].mu)*(a[i].zi);
    }

    for(i=0;i<n;i++){
        zis+=a[i].zi;
    }

    if(zis==0) cout<<'0';
    if(zis>0) {
        if(zis==mus) cout<<'1';
        if(zis<mus) printf("%ld/%ld",zis/mcg(zis,mus),mus/mcg(zis,mus));
        if(zis>mus) {zheng=zis/mus;zis=zis-zheng*mus;
                     if(zis==0) {
                        printf("%ld",zheng);
                     }
                     else printf("%ld %ld/%ld",zheng,zis/mcg(zis,mus),mus/mcg(zis,mus));
                    }
    }
    if(zis<0) {
        if((-zis)==mus) cout<<'-1';
        if((-zis)<mus) printf("-%ld/%ld",(-zis)/mcg((-zis),mus),mus/mcg((-zis),mus));
        if((-zis)>mus) {zheng=(-zis)/mus;zis=-((-zis)-zheng*mus);
                        if(zis==0) printf("-%ld",zheng);
                        else printf("-%ld -%ld/%ld",zheng,(-zis)/mcg((-zis),mus),mus/mcg((-zis),mus));
                       }
    }
    return 0;
}

long mcg(long a,long b)
{
    long n;
    for(;;){
        n=a%b;
        a=b;
        b=n;
        if(n==0) break;
    }
    return a;
}
