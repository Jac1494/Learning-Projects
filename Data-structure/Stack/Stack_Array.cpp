#include<iostream>
#include<vector>
using namespace std;

void push(vector<int> &v,int size)
{
    v.push_back(size);     
}

void pop(vector<int> &v,int size)
{
    v.pop_back();
}

void top(vector<int> &v,int size)
{
    printf("top :- %d\n",v[v.size()-1]);
}

void print(vector<int> v,int size)
{
    printf("Array :- ");
    for(auto it=v.begin();it!=v.end();it++)
    printf("%d ",*it);
    printf("\n");
}

void stack(vector<int> v,int size)
{
    char ch;
    int op,num;
    do{
    printf("Stack\n");
    printf("1)push \n");
    printf("2)pop\n");
    printf("3)top\n");
    printf("4)print\n");
    printf("Select operation\n");
    scanf("%d",&op);
    if(op==1)
    {
    printf("Enter number\n");
    scanf("%d",&num);
    push(v,num);
    }
    else if(op==2)
    {
    pop(v,size);
    }
    else if(op==3)
    {
    top(v,size);
    }
    else if(op==4)
    {
    print(v,size);  
    }
    else
    {
    printf("Incorrect input\n");
    break;
    }
    printf("Show list again (Y / y )\n");
    scanf(" %c",&ch);

    }while(ch=='y'||ch=='Y');
}

int main()
{
    vector<int> v;//={1,2,3,4,5};

    stack(v,v.size());
    return 0;
}
