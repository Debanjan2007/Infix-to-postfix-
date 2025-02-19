// infix to postfix expresion 

#include<stdio.h>
#include<string.h>
char fin[20];
char oper[20];
int top = -1 ;

// Returning the priority of any operator
int priorityChk(char sym){
    if(sym == '(' || sym == ')')
        return 4 ;
    if(sym == '^') 
        return 3 ;
    if(sym == '*' || sym == '/')
        return 2 ;
    if(sym == '+' || sym == '-')
        return 1 ;
}

// push function 
void push(char x){
    if(top >= 19 ){
        printf("Stack overflow!");
    }else{
     oper[++top] = x ;   
    }
}

// pop function 
char pop(){
    if(top <= -1){
        printf("Stack Underflow");
        return -1 ;
    }else{
        return oper[top--];
    }
}

// display function 
void display(){
    int n = strlen(fin);
    for(int i = 0 ; i < n ; i++){
        printf("%c",fin[i]);
    }
}

int main() {
    printf("INFIX to POSTFIX conversion\n");
    char expr[20] ;
    char oper ;  //oper variaable for temporary operator input 
    int j = 0 ;
    int p = 0;
    int c = 0 ;
    printf("You can enter Expresion within 20 digits,");
    printf("\nEnter the expresion :");
    scanf("%s",&expr);
    for(int i  = 0 ; expr[i] != '\0' ; i++){
        if(expr[i] == '(' || expr[i] == ')' || expr[i] == '^' || expr[i] == '*' || expr[i] == '/' || expr[i] == '+' || expr[i] == '-'){
            p = priorityChk(expr[i]);
            // Pop while the operator at the top has higher or equal precedence
            if(p > c){
                c = p ;
            }else{
                while (top != -1 && c >= p) {
                fin[j++] = pop();
            }   
            }
            push(expr[i]); 
        }else{
            fin[j++] = expr[i];
        }
    }
        while (top != -1) {
        fin[j++] = pop();
    }
    fin[j] = '\0';
    display();
    return 0;
}
