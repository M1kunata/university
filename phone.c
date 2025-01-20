#include<stdio.h>
#include<string.h>
int main()
{
    char input[200],ans[50];
    char phone[8][4]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};//index 0 ='2' index 7 ='9'
    scanf("%s",input);
    int p=0,count=0;
    for(int i=0;i<strlen(input);i++)
    {
        if(input[i]==input[i+1])count++;//count same integer
        else
        {
        while(1)
        {
            int num,index,choice;
            num=input[i]-'0';num-=2;
            index=strlen(phone[num]);// เพราะแต่ละจุดมีจำนวนไม่เท่ากันเลยต้องให้ค่าๆ1บันทึกไว้
            choice=count%index;//เพื่อหาตำแหน่งที่ถูกต้องของตัวอักษร
            ans[p]=phone[num][choice];
            p++;
            if(count<index)             
                count-=choice;
            else{
                count-=(choice+1);//เพื่อให้ค่าย้อนกลับไปมีค่า%แล้วไม่ใช่0
            }
            if(count==0)break;
        }
        }
    }
    ans[p]='\0';
 printf("%s",ans);
}
