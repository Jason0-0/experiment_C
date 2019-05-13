#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<windows.h>
char OP(void);
//int Num(void);
int Cal(int v1,char COp,int v2);
int main()
{
    printf("Number:180310320\nsubject No.2 - program No.1\n\n");
    char op;
    int num1,num2;
    int answer,input;
    int counter;
    int right=0;
   // int flag=1;
    float rate;
    srand(time(NULL));

    for(int i=1;i<11;i++)
    {
        /*if(flag!=1)
        {
            right++;
        }*/
        counter=0;
       // flag=0;
        /*num1=Num();
        //Sleep(500);
        num2=Num();*/
        num1=rand()%10+1;
        num2=rand()%10+1;
        op=OP();
        answer=Cal(num1,op,num2);
        do{
            printf("subject%d: %d%c%d= ?\n",i,num1,op,num2);
            scanf("%d",&input);

            if(input==answer)
            {
                printf("Right!\n");
                right++;                //once the answer is right(no matter how many times he has tried), consider it right
                break;
            }
            else
            {
                counter++;
            }

            if(counter<=2)
            {
                printf("Wrong!Please try again.\n");
                //flag=1;
            }
            else
            {
                printf("Wrong!Test next subject!\n");
                //flag=1;
            }

        }while(counter<3);

    }
    /*if(flag!=1)
        {
            right++;
        }*/
    rate=((float)right/10);
    if(rate<0.75)
    {
        printf("The student get %7.2f%%. Please start again.\n",rate*100);
        return main();
    }
    else{
        printf("The student get %8.2f%%. Well Done!\n",rate*100);
    }


    return 0;
}

/*produce op */
char OP(void)
{
    char FOp;
    int r;
    //srand(time(NULL));
    r=rand()%4;
    switch(r)
    {
        case 0:
            FOp='+';
            break;
        case 1:
            FOp='-';
            break;
        case 2:
            FOp='*';
            /*printf("%c",FOp);*/
            break;
        case 3:
            FOp='/';
           /*printf("%c",FOp);*/
           break;
        default:
        return -1;
    }
    return FOp;
}

/*produce number randomly*/

/*int Num(void)
{
    //Sleep(167); 让两次输出的随机数不一样
    srand(time(NULL));
    return rand()%10+1;

}*/

int Cal(int v1,char COp,int v2)//input num1,op,num2
{
    /*float answer;*/
    switch(COp)
    {
    case '+':
        return v1+v2;
        break;
    case '-':
        return v1-v2;
        break;
    case '*':
        return v1*v2;
        break;
    case '/':
        return v1/v2;
    default:
        return 1000;
    }
}
