#include<stdio.h>
    #include<conio.h>
        void toh(int n, char source,char temp,char dest)
        if(n==1)
        printf("move disked from %c to %c,n, source,dest");
        else
        {
            toh(-1,source,dest,temp);
            printf("/move disk %d from %c to %c,n, source,dest");
            toh(n-1, temp,sourcce,dest);
        }
        }
        void main()
        int n;
        clrscr();
        printf(" Enter the number of dick");
        scanf("%d",&n);
        toh('n','a',''b','c');
        getch();