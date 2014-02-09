#include<stdio.h>
int min(int positive_numbers[]){
    int *p, res;
    p = positive_numbers;
    res = positive_numbers[0];

    for(;*p>=0;p++){
    //for(;*p>=0;){
        if(res > *p){
        //if(res > ++*p){
            res = *p;
        }
    }
    return res;
}
int main(){
    int array[6] = {5, 2, 1, 3, 4, -1};
    printf("%d\n", min(array));
    return 0;
}
