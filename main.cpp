#include"main_1.h"
typedef int ElemType;
#include"main_2.h"
#include"main_1.cpp"

Status equal(ElemType c1,ElemType c2)
{
    if(c1==c2)
        return TRUE;
    else
        return FALSE;
}

void Union(LinkList La,LinkList Lb)
{
    ElemType e;
    int La_len,Lb_len;
    int i;
    La_len=ListLength(La);
    Lb_len=ListLength(Lb);
    for(i=1;i<=Lb_len;i++)
    {
        GetElem(Lb,i,e);
        if(!LocateElem(La,e,equal))
            ListInsert(La,++La_len,e);
    }
}

void print(ElemType c)
{
    printf("%d ",c);
}

int  main()
{
    LinkList La,Lb;
    Status i;
    int j;
    i=InitList(La);
    if(i==1)
        for(j=1;j<=5;j++)
            i=ListInsert(La,j,j);
    printf("La= ");
    ListTraverse(La,print);
    InitList(Lb);
    for(j=1;j<=5;j++)
        i=ListInsert(Lb,j,2*j);
    printf("Lb= ");
    ListTraverse(Lb,print);
    Union(La,Lb);
    printf("new La= ");
    ListTraverse(La,print);
    return 0;
}
