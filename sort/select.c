#include<stdio.h>

/**
*@brief 选择排序
*/
int select_sort(int b[],int n){
    for(int i=0;i<n;i++){
        int tmp=b[i];
        int min;
        //选择最小
        for(int j=i;j<n;j++){ 
            if(j==i){
                min=i;
            }
            if(b[min]>b[j]){
                min=j;
            }
        }

        //交换
        b[i]=b[min];
        b[min]=tmp;
    }

    for(int a=0;a<n;a++){
        printf("%d  ",b[a]);
    }
    printf("\n");

    return 0;
}


/**
*@brief 程序入口
*/
int main(int argc,char** argv){
    int b[10]={1,0,2,3,6,5,8,7,9,4};
    select_sort(b,10);
    return 0;
}