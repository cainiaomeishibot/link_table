
Status InitList(SqList &L)
{
    L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem)
        exit(OVERFLOW);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;
}

Status DestroyList(SqList &L)
{
    free(L.elem);
    L.elem=NULL;
    L.length=0;
    L.listsize=0;
    return OK;
}

Status ClearList(SqList &L)
{
    L.length=0;
    return OK;
}

Status ListEmpty(SqList L)
{
    if(L.length==0)
        return TRUE;
    else
        return FALSE;
}

int ListLength(SqList L)
{
    return L.length;
}

Status GetElem(SqList L,int i,ElemType &e)
{
    if(i<1||i>L.length)
        exit(ERROR);
    e=*(L.elem+i-1);
    return OK;
}

int LocateElem(SqList L,ElemType e,Status(*compare)(ElemType,ElemType))
{
    ElemType *p;
    int i=1;
    p=L.elem;
    while(i<=L.length&&!compare(*p++,e))
        ++i;
    if(i<=L.length)
        return i;
    else
        return 0;
}

Status PriorElem(SqList L,ElemType cur_e,ElemType &pre_e)
{
    int i=2;
    ElemType *p=L.elem+1;
    while(i<=L.length&&*p!=cur_e)
    {
        p++;
        i++;
    }
    if(i>L.length)
        return INFEASIBLE;
    else
    {
        pre_e=*--p;
        return OK;
    }
}

Status NextElem(SqList L,ElemType cur_e,ElemType &next_e)
{
    int i=1;
    ElemType *p=L.elem;
    while(i<L.length&&*p!=cur_e)
    {
        i++;
        p++;
    }
    if(i==L.length)
        return INFEASIBLE;
    else
    {
        next_e=*++p;
        return OK;
    }
}

Status ListInsert(SqList &L,int i,ElemType e)
{
    ElemType *newbase,*q,*p;
    if(i<1||i>L.length+1)
        return ERROR;
    if(L.length>=L.listsize)
    {
        if(!(newbase=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType))))
            exit(OVERFLOW);
        L.elem=newbase;
        L.listsize+=LISTINCREMENT;
    }
    q=L.elem+i-1;
    for(p=L.elem+L.length-1;p>=q;--p)
        *(p+1)=*p;
    *q=e;
    ++L.length;
    return OK;
}

Status ListDelete(SqList &L,int i,ElemType &e)
{
    ElemType *p,*q;
    if(i<1||i>L.length)
        return ERROR;
    p=L.elem+i-1;
    e=*p;
    q=L.elem+L.length-1;
    for(++p;p<=q;++p)
        *(p-1)=*p;
    L.length--;
    return OK;
}

Status ListTraverse(SqList L,void(*vi)(ElemType&))
{

    ElemType *p;
    int i;
    p=L.elem;
    for(i=1;i<=L.length;i++)
        vi(*p++);

    printf(" ");
    return OK;
}


