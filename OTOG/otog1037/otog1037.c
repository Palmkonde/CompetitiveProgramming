#include<stdio.h>
#include<string.h>
#define N 100005

char sentense[N];
int len; 

short check_palindrome(int l, int r, char check[]) {
    if(l >= r) return 0; 
    if(check[l] != check[r]) return 0;
    if(check[l] == check[r])  {
        if(l + 1 >= r - 1) {
            return 1;
        } 
        
        return check_palindrome(l + 1, r - 1, check);
    }
}

int main() {
    scanf("%s", sentense);
    len = strlen(sentense) - 1;
    
    if(!len){
        printf("yes");
        return 0;
    }
   
    printf("%s", (check_palindrome(0, len, sentense)) ? "yes" : "no");
    
    return 0;
}