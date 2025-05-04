//Program to check if a given number is palindrome, armstrong or perfect using a menu
#include <stdio.h>
#include <cstdlib>
#include <cmath>

bool IsPalindrome(int *num);
bool IsArmstrong(int *num);
bool IsPerfectNum(int *num);

int main(){
    int *choice=(int*)malloc(sizeof(int));
    int *number=(int*)malloc(sizeof(int));

    do{
        printf("\nMENU\n");
        printf("1. Palindrome Number\n2. Armstrong Number\n3. Perfect Number\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", choice);
        if ((*choice)>=1 && (*choice)<=3){
            printf("Enter number:");
            scanf("%d", number);
            if ((*number)<0){
                printf("Negative number not allowed.\n");
                continue;
            }
            switch(*choice){
                case 1:
                    if (IsPalindrome(number)){
                        printf("The number %d is a Palindrome number\n", *number);
                    }
                    else{
                        printf("The number %d is not a Palindrome number\n", *number);
                    }
                    break;
                case 2:
                    if (IsArmstrong(number)){
                        printf("The number %d is a Armstrong number\n", *number);
                    }
                    else{
                        printf("The number %d is not a Armstrong number\n", *number);
                    }
                    break;
                case 3:
                    if (IsPerfectNum(number)){
                        printf("The number %d is a Perfect number\n", *number);
                    }
                    else{
                        printf("The number %d is not a Perfect number\n", *number);
                    }
                    break;
            }
        }
        else if ((*choice)!=4){
            printf("Invalid choice. Try again\n");
        }
    } while ((*choice)!=4);
    free(choice);
    free(number);
    return 0;
}

//Function to check if the given number is a palindrome number or not
bool IsPalindrome(int *num){
    int *original = (int*)malloc(sizeof(int));
    int *reverse = (int*)malloc(sizeof(int));
    int *temp = (int*)malloc(sizeof(int));

    *original=*num;
    *reverse=0;
    *temp=*num;

    while (*temp>0){
        *reverse= ((*reverse)*10) + ((*temp)%10);
        *temp/=10; 
    }
    bool result = ((*original)==(*reverse));
    free(original);
    free(reverse);
    free(temp);
    return result;
}

//Function to check if the given number is an armstrong number or not
bool IsArmstrong(int *num){
    int *original = (int*)malloc(sizeof(int));
    int *sum = (int*)malloc(sizeof(int));
    int *digits = (int*)malloc(sizeof(int));
    int *temp = (int*)malloc(sizeof(int));

    *original=*num;
    *sum=0;
    *digits=0;
    *temp=*num;

    while (*temp>0){
        (*digits)++;
        (*temp)/=10; 
    }
    *temp=*num;

    while ((*temp)>0){
        (*sum)+= (pow(((*temp)%10), *digits));
        (*temp)/=10; 
    }
    bool result;
    result = ((*sum)==(*original));
    free(original);
    free(sum);
    free(digits);
    free(temp);
    return result;
}

//Function to check if the given number is a perfect number or not
bool IsPerfectNum(int *num){
    int *sum = (int*)malloc(sizeof(int));
    int *original = (int*)malloc(sizeof(int));
    int *i = (int*)malloc(sizeof(int));

    *sum=0;
    *original=*num;

    for (*i=1; (*i)<=((*num)/2); (*i)++){
        if ((*num)%(*i)==0){
            (*sum)+=(*i);
        }
    }
    int result;
    result = ((*original)==(*sum));
    free(i);
    free(sum);
    free(original);
    return result;
}