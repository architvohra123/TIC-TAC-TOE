#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
////////////////////////////
int check(char arr[]){
    if(arr[0]==arr[1] && arr[0]==arr[2] && arr[0]=='X') return 1;
    if(arr[3]==arr[4] && arr[3]==arr[5] && arr[3]=='X') return 1;
    if(arr[6]==arr[7] && arr[6]==arr[8] && arr[6]=='X') return 1;
    if(arr[0]==arr[3] && arr[0]==arr[6] && arr[0]=='X') return 1;
    if(arr[1]==arr[4] && arr[1]==arr[7] && arr[1]=='X') return 1;
    if(arr[2]==arr[5] && arr[2]==arr[8] && arr[2]=='X') return 1;
    if(arr[0]==arr[4] && arr[0]==arr[8] && arr[0]=='X') return 1;
    if(arr[2]==arr[4] && arr[2]==arr[6] && arr[2]=='X') return 1;
    
    if(arr[0]==arr[1] && arr[0]==arr[2] && arr[0]=='O') return -1;
    if(arr[3]==arr[4] && arr[3]==arr[5] && arr[3]=='O') return -1;
    if(arr[6]==arr[7] && arr[6]==arr[8] && arr[6]=='O') return -1;
    if(arr[0]==arr[3] && arr[0]==arr[6] && arr[0]=='O') return -1;
    if(arr[1]==arr[4] && arr[1]==arr[7] && arr[1]=='O') return -1;
    if(arr[2]==arr[5] && arr[2]==arr[8] && arr[2]=='O') return -1;
    if(arr[0]==arr[4] && arr[0]==arr[8] && arr[0]=='O') return -1;
    if(arr[2]==arr[4] && arr[2]==arr[6] && arr[2]=='O') return -1;
    
    bool flag=false;
    for(int i=0;i<9;i++){
        if(arr[i]=='\0'){
            flag=true;
        }
    }
    if(flag) return 2;
    return 0;
}
///////////////////////////////
int freeS(char arr[]){
    int ans=0;
    for(int i=0;i<9;i++){
        if(arr[i]=='\0'){
            ans++;
        }
    }
    return ans;
}
////////////////////////////
int minmax(char arr[], bool isMaxer){
    int temp=check(arr);
    if(temp!=2){
        return temp*(1+freeS(arr));
    }else{
        if(isMaxer){
            int ans= INT_MIN;
            for(int i=0;i<9;i++){
                if(arr[i]=='\0'){
                    arr[i]='X';
                    int ok=minmax(arr, false);
                    if(ok>ans){
                        ans=ok;
                    }
                    arr[i]='\0';
                }
            }
            return ans;
        }else{
            int ans=INT_MAX;
            for(int i=0;i<9;i++){
                if(arr[i]=='\0'){
                    arr[i]='O';
                    int ok=minmax(arr, true);
                    if(ok<ans){
                        ans=ok;
                    }
                    arr[i]='\0';
                }
            }
            return ans;
        }
    }
    return 0;
}
/////////////////////////////////////
int minmaxN(char arr[], bool isMaxer){
    int temp=check(arr);
    if(temp!=2){
        return -temp*(1+freeS(arr));
    }else{
        if(isMaxer){
            int ans= INT_MIN;
            for(int i=0;i<9;i++){
                if(arr[i]=='\0'){
                    arr[i]='O';
                    int ok=minmaxN(arr, false);
                    if(ok>ans){
                        ans=ok;
                    }
                    arr[i]='\0';
                }
            }
            return ans;
        }else{
            int ans=INT_MAX;
            for(int i=0;i<9;i++){
                if(arr[i]=='\0'){
                    arr[i]='X';
                    int ok=minmaxN(arr, true);
                    if(ok<ans){
                        ans=ok;
                    }
                    arr[i]='\0';
                }
            }
            return ans;
        }
    }
    return 0;
}
////////////////////////
int getMove(char arr[]){
    int mm=INT_MIN;
    int move=0;
    for(int i=0;i<9;i++){
        if(arr[i]=='\0'){
            arr[i]='X';
            int temp=minmax(arr, false);
            if(temp>mm){
                mm=temp;
                move=i;
            }
            arr[i]='\0';
        }
    }
    return move;
}
int getMoveN(char arr[]){
    int mm=INT_MIN;
    int move=0;
    for(int i=0;i<9;i++){
        if(arr[i]=='\0'){
            arr[i]='O';
            int temp=minmaxN(arr, false);
            if(temp>mm){
                mm=temp;
                move=i;
            }
            arr[i]='\0';
        }
    }
    return move;
}
////////////////////////
void printer(char arr[]){
    printf(" %c | %c | %c \n", arr[0],arr[1],arr[2]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", arr[3],arr[4],arr[5]);
    printf("___|___|___\n");    
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", arr[6],arr[7],arr[8]);
}

int main()
{
    char choice;
    printf("What you want to play as: 'X' or 'O'\n");
    scanf("%c", &choice);
    while(choice!='X' && choice!='O'){
        printf("Invalid choice!!!\nPlease Enter Again: 'X' or 'O'\n");
        scanf("%c", &choice);
    }

    char* arr = (char*)calloc(9, sizeof(char));
    int usr;
    int counter=0;
    while(check(arr)==2){
        if(choice=='O'){   
            if(counter%2==0){
                if(counter==0){
                    int move=rand();
                    printf("%d ", move);
                    arr[move%9]='X';
                    printf("BOT has placed X on %d position\n", move%9);
                    counter++;
                    printer(arr);
                    continue;
                }
                int move=getMove(arr);
                arr[move]='X';
                printf("BOT has placed X on %d position\n", move);
                printer(arr);
            }else{
                
                printf("enter pos to place at: ");
                scanf("%d", &usr);
                printf("\n");
                while(arr[usr]!='\0' || usr>8 || usr<0){
                    printf("That place is already filled!! Please enter valid position\n");
                    scanf("%d", &usr);
                }
                arr[usr]='O';
            }
        }else{
            printer(arr);
            if(counter%2==0){

                printf("enter pos to place at: ");
                scanf("%d", &usr);
                printf("\n");
                while(arr[usr]!='\0' || usr>8 || usr<0){
                    printf("That place is already filled!! Please enter valid position\n");
                    scanf("%d", &usr);
                }
                arr[usr]='X';
            }else{
                int move=getMoveN(arr);
                arr[move]='O';
                printf("BOT has placed O on %d position\n", move);
            }
        }
        counter++;
    }

    printer(arr);
    if(check(arr)==0){
        printf("It is a draw\n");
    }else if((check(arr)==1 && choice=='O')||(check(arr)==-1 && choice=='X')){
        printf("You Lost!!!\n");
    }else{
        printf("You Won!!!\n");
    }
    
   
}