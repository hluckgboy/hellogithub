#include<stdio.h>


/**
*@brief 冒泡排序
*/
int bubble_sort(int b[],int n){
    for(int i=1;i<n;i++){
        for(int j=1;j<n-i+1;j++){
            if(b[j]<b[j-1]){
                int tmp;
                tmp=b[j];
                b[j]=b[j-1];
                b[j-1]=tmp;
            }
        }
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
    printf("now try to sort a list\n");
    int b[10]={1,0,2,3,6,5,8,7,9,4};
    bubble_sort(b,10);
    return 0;
}