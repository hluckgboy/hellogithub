#include<stdio.h>

/**
*@brief 交换数组中的两个元素
*/
void swap(int *b,int i,int j){
    int tmp;
    tmp=b[i];
    b[i]=b[j];
    b[j]=tmp;
}

int parting(int *b,int start,int end){
    int right=end;
    int left=start;
    while(left<right){
        while(left<right&&b[right]>=b[start]){
            right--;
        }
        while(left<right&&b[left]<=b[start]){
            left++;
        }
        swap(b,left,right);
    }
    swap(b,start,left);
    return left;
}

/**
*@brief 快速排序
*/
void quick_sort(int *b,int i,int j){
    if(i>=j){
        return;
    }
   //哨兵
   int line=parting(b,i,j);
   quick_sort(b,i,line-1);
   quick_sort(b,line+1,j);
}

/**
*@brief 程序入口
*/
int main(int argc,char** argv){
    printf("now try to sort a list\n");
    int b[10]={1,0,2,3,6,5,8,7,9,4};
    quick_sort(b,0,9);

    for(int a=0;a<10;a++){
        printf("%d  ",b[a]);
    }
    printf("\n");
    return 0;
}