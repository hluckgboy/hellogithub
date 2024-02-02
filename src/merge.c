#include<stdio.h>

/**
*@brief 合并操作：需要注意的是左右子数组是有序
*       这是合并的前提
*/

void merge(int *b,int left,int mid,int right){
    int tmpsize=right-left+1;
    int *tmp=(int*)malloc(tmpsize*sizeof(int));
    int i=left;
    int j=mid+1;
    int k=0;
    while(i<=mid&&j<=right){
        if(b[i]<=b[j]){
            tmp[k++]=b[i++];
        }
        else{
            tmp[k++]=b[j++];
        }
    }
    while(j<=right){
        tmp[k++]=b[j++];
    }
    while(i<=mid){
        tmp[k++]=b[i++];
    }

    for(int d=0;d<tmpsize;d++){
        b[left++]=tmp[d];
    }

    free(tmp);
}

/**
*@brief 归并排序
*/
void merge_sort(int *b,int left,int right){
    if(left>=right){
        return;
    }
    int mid=(right+left)/2;
    merge_sort(b,left,mid);
    merge_sort(b,mid+1,right);

    merge(b,left,mid,right);
}

/**
*@brief 程序入口
*/
int main(int argc,char** argv){
    printf("now try to sort a list\n");
    int b[10]={1,0,2,3,6,5,8,7,9,4};
    merge_sort(b,0,9);

    for(int a=0;a<10;a++){
        printf("%d  ",b[a]);
    }
    printf("\n");
    return 0;
}