#include<stdio.h>

/**
*@brief 插入排序
*/
int insert_sort(int b[],int n){
    for(int i=1;i<n;i++){
        int tmp=b[i];
        int j=i-1;
        while(j>=0){
            //移动
            if(tmp<b[j]){
                b[j+1]=b[j];
            }
            else{
                break;
            }
            j--;
        }
        //插入
        b[j+1]=tmp;
    }
    
    for(int a=0;a<n;a++){
        printf("%d  ",b[a]);
    }
    printf("\n");
    return 0;
}

/***不同的写法***/
/*
int insert_sort(int b[],int n){
    for(int i=1;i<n;i++){
        int tmp=b[i];
        int j=i-1;
        //移动
        while(j>=0&&b[j]>tmp){
            b[j+1]=b[j];
            j--;
        }
        //插入
        b[j+1]=tmp;
    }
    
    for(int a=0;a<n;a++){
        printf("%d  ",b[a]);
    }
    printf("\n");
    return 0;
}
*/

/**
*@brief 程序入口
*/
int main(int argc,char** argv){
    int b[10]={1,0,2,3,6,5,8,7,9,4};
    insert_sort(b,10);
    return 0;
}