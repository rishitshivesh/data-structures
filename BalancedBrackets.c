/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int t, top=-1;
    char s[1000]={0};
    char st[1000]={0};
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        char *c=s;
        top=-1;
        while(*c!='\0'){
            if(*c=='{'||*c=='['||*c=='(')
                st[++top]=*c;
            else if(top!=-1&&((*c=='}'&&st[top]=='{')||(*c==']'&&st[top]=='[')||(*c==')'&&st[top]=='(')))
                top--;
            else{
                printf("No\n");
                break;
            }
            c++;
        }
        if(!*c){
            top==-1?printf("Yes\n"):printf("No\n");
            // printf(top==-1?"Yes/n":"No/n");
        }
    }

    return 0;
}
