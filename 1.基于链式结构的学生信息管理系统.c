#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define N 100

typedef struct student
{
    char name[N];     // 学生名字
    int x_num;        // 学号
    int tel_num;      // 电话号码
    struct student *next; //指针
}student;


// 系统界面展示函数
int System_Show(int x)
{
    printf("          ***************************************************************\n");
    printf("          ****************基于链式结构的学生信息管理系统*****************\n");
    printf("          ***************************************************************\n");
    printf("          ***       请选择系统功能：                                  ***\n");
    printf("          ***      >输入1添加学生信息                                 ***\n");
    printf("          ***      >输入2插入学生信息                                 ***\n");
    printf("          ***      >输入3修改学生信息                                 ***\n");
    printf("          ***      >输入4删除学生信息                                 ***\n");
    printf("          ***      >输入5打印学生信息                                 ***\n");
    printf("          ***      >输入-1结束系统                                    ***\n");
    printf("          ***************************************************************\n");
    printf("          ***我的选择是：");
    scanf("%d",&x);  // 用户选择
    return x;
}

// 创建链表函数
student* Creat_list(student* rear1)
{
    student* p = (student*)malloc(sizeof(student*));

    getchar();
    printf("          ***请输入学生名字：");
    scanf("%s",p->name);
    printf("          ***请输入学生学号：");
    getchar();
    scanf("%d",&p->x_num);
    printf("          ***请输入学生电话：");
    getchar();
    scanf("%d",&p->tel_num);
    printf("          ************************学生信息录入成功！**********************\n");

    p->next = NULL;
    rear1->next = p;
    rear1 = p;
    return rear1;
}

// 信息展示
void List_ALL_show(student* p)
{
    int count =0;
    printf("          ***************************************************************\n");
    printf("          ****************基于链式结构的学生信息管理系统*****************\n");
    while(p!= NULL)
    {
        count++;
        printf("          ***************************************************************\n");
        printf("          ***学生姓名：%s  学生学号：%d  学生电话：%d   ***\n",p->name,p->x_num,p->tel_num);

        p = p->next;
    }
    printf("          **************************总共有%d个学生************************\n",count);
}

// 单次展示
void List_single_show(student* p)
{
    printf("          ***************************************************************\n");
    printf("          ***学生姓名：%s  学生学号：%d  学生电话：%d   ***\n",p->name,p->x_num,p->tel_num);
}



// 更改链表函数
void change(student** p)
{
    int find_x_num =0; //查找学号
    int choice = 0;
    char change_name[N] ={'\0'};
    int change_num = 0;
    printf("          ***请输入待查学生学号：");
    scanf("%d",&find_x_num);
    int T=0;

    if((*p)->next == NULL)
    {
        printf("          ***链表为空!");
    }
    else
    {
        *p = (*p)->next ;
        while((*p) != NULL )
        {
            if((*p)->x_num == find_x_num)
            {
                List_single_show(*p);   // 展示
                printf("          ***输入1修改其姓名，输入2修改其电话号码：");
                scanf("%d",&choice);
                if(choice == 1)
                {
                    printf("          ***请输入修改后姓名：");
                    scanf("%s",change_name);
                    strcpy((*p)->name, change_name);
                    List_single_show(*p); //展示
                }
                else if(choice == 2)
                {
                    printf("          ***请输入修改后电话号码：");
                    scanf("%d",&change_num);
                    (*p)->tel_num = change_num;
                    List_single_show(*p); //展示
                }
                else
                {
                    printf("输入错误！");
                }
                T = 1; // 找到
            }
            (*p) = (*p)->next ;
        }
        if(T==0)
        {
            printf("          ***没有此学号同学！\n");
        }
    }

}

// 插入链表
void cha(student** m)
{
    int cha_x_num =0;
    student* t = (student*)malloc(sizeof(student*));

    printf("          ***请输入在哪位学号同学后面插入：");
    scanf("%d",&cha_x_num);
    *m = (*m)->next ;
    while((*m) != NULL )
    {
        if((*m)->x_num == cha_x_num)
        {
            List_single_show(*m);   // 展示
            getchar();
            printf("          ***请输入插入学生名字：");
            scanf("%s",t->name);
            printf("          ***请输入插入学生学号：");
            getchar();
            scanf("%d",&t->x_num);
            printf("          ***请输入插入学生电话：");
            getchar();
            scanf("%d",&t->tel_num);
            printf("          ************************学生信息插入成功！**********************\n");
            t->next = (*m)->next;
            (*m)->next = t;
        }
        (*m) = (*m)->next;
    }
}

// 删除链表函数
void delted(student** q)
{
    int find_x_num =0;
    printf("          ***请输入需要删除学生的学号：");
    scanf("%d",&find_x_num);
    while((*q)->next != NULL)
    {
        if((*q)->next->x_num == find_x_num)
        {
            (*q)->next = (*q)->next->next; // 删除
        }
        (*q) = (*q)->next ;
    }

}

int main()
{
    student* head = (student*)malloc(sizeof(student*));
    head->name[N] ='\0';
    head->x_num=0;
    head->tel_num=0;
    head->next=NULL;

    student* rear1 = head;
    student* rear2 = head;
    student* rear3 = head;
    student* rearc = head;
    int choice = 0 ,i=0 , n=0;    // 用户选择

    while(choice != -1)
    {
        if(choice == 1)
        {
            printf("          ************************录入学生信息***************************\n");
            printf("          ***请输入需要录入的学生人数：");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                rear1 = Creat_list(rear1); // 创建链表
            }
            List_ALL_show(head->next); // 展示链表
        }

       if(choice == 2)
        {
            printf("          ************************插入学生信息***************************\n");
            List_ALL_show(head->next); // 展示链表
            rearc = head;
            cha(&rearc);
            List_ALL_show(head->next); // 展示链表
        }

        if(choice == 3)
        {
            printf("          ************************更改学生信息***************************\n");
            List_ALL_show(head->next); // 展示链表
            rear2 = head;
            change(&rear2);  // 更改物品信息
            List_ALL_show(head->next);
        }

        if(choice == 4)
        {
            List_ALL_show(head->next); // 展示链表
            rear3 = head;
            delted(&rear3);
            List_ALL_show(head->next); // 展示链表
        }

        if(choice == 5)
        {
            List_ALL_show(head->next);
        }

        choice = System_Show(choice);  // 展示界面，下一次循环
    }
    List_ALL_show(head->next); // 展示系统
    printf("          ***********************系统程序正常结束！**********************\n");
}
