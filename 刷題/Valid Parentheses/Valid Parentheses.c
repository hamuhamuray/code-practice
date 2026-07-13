#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s) {
    char* ptr = s;
    //Create the stack of the parantheses
    char* stack = malloc(sizeof(char) * strlen(s));
    int count = -1;
    while(*ptr != '\0'){
        //Add the corresponding right paranthesis to the stack
        if(*ptr == '(') stack[++count] = ')';
        else if(*ptr == '[') stack[++count] = ']';
        else if(*ptr == '{') stack[++count] = '}';
        //Check if the right paranthesis is the same as stack.pop();
        else if(count >= 0 && (*ptr == ')' || *ptr == ']' || *ptr == '}')){
            if(stack[count--] != *ptr)return false;
        }
        //If the next paranthesis is a right parenthesis and the stack is empty, return false
        else return false;
        for(int i = 0 ; i <= count ; i++){
            // printf("%c", stack[i]);
        }
        // printf("\n");
        // printf("%d\n", count);
        ptr++;
    }
    // printf("check\n");
    //Check if the stack is empty
    if(count >= 0)return false;
    else return true;
}