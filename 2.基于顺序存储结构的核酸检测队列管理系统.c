#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10       // 名字最大10个字
#define List_MAX 50  // 队伍最大50人

typedef struct people
{
    char name[MAX];
    int id;
}people;

typedef struct list
{
    people list[List_MAX];  // 队伍数组
    int front;  // 头
    int rear;   // 尾
}list;

// 入队模块
void in_list(list *p)
{
    int i,n; //录入人数
    char inName[MAX] ={'\0'};
    int inID = 0;
    printf("请输入需要录入的人数：");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        if( (p->rear+1)%List_MAX == p->front )
        {
            printf("排队人数已达上限50人");
            break; //结束
        }
        else
        {
            printf("请输入排队人员姓名:");
            scanf("%s",inName);
            printf("请输入排队人员身份证号码:");
            scanf("%d",&inID);

            strcpy(p->list[p->rear].name, inName); // 录入
            p->list[p->rear].id = inID;     //录入

            p->rear = (p->rear+1)%List_MAX ; // 录入成功指针向前
        }
    }
}

// 出队模块
void pop_list(list *p,list *m)
{
    if(p->rear == p->front)
    {
        printf("队空！");
    }
    else
    {
        m->list[m->rear].id = p->list[p->front].id ;           // 存储已检信息
        strcpy( m->list[m->rear].name, p->list[p->front].name);
        m->rear = m->rear+1 ;

        p->front = (p->front+1)%List_MAX ;
    }
}

// 查询函数
void find_list(list *p,list *m)
{
    int find_id = 0; // 查找的身份证
    int i =0 ,flag =0;
    printf("请输入查找人员身份证：");
    scanf("%d",&find_id);
    for(i=p->front;i<p->rear;i++)
    {
        if(find_id == p->list[i].id)
        {
            printf("【%s】此人正在排队！\n",p->list[i].name);
            flag = 1;
            break;
        }
    }
    for(i=m->front;i<m->rear ;i++)
    {
        if(find_id == m->list[i].id)
        {
            printf("【%s】此人已经完成核酸！\n",m->list[i].name);
            flag =1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("此人没有排队做核酸！\n");
    }
}

// 身份证排序展示功能
void id_show(list *p,list *m)
{
    int t_id;
    char t_name[10];
    int i ,j ,len;
    for( i=p->front ;i<=p->rear;i++ )  // 复制
    {
        m->list[i].id = p->list[i].id ;
        strcpy( m->list[i].name, p->list[i].name);
    }
    m->front = p->front;  // 长度匹配
    m->rear = p->rear;


    len =((m->rear)-(m->front)+List_MAX)%List_MAX;  // 长度
    for(j=m->front;j<len;j++) // 冒泡排序
    {
        for(i=m->front;i<=len-j;i++)
        {
            if( m->list[i].id < m->list[i+1].id)
            {
                t_id = m->list[i].id;
                strcpy( t_name, p->list[i].name);

                m->list[i].id = m->list[i+1].id;
                strcpy( m->list[i].name, m->list[i+1].name);

                m->list[i+1].id = t_id;
                strcpy( m->list[i+1].name, t_name);
            }
        }
    }

}

// 排队信息展示
void List_show(list *p)
{
    int i;
    if(p->rear == p->front)  // 队空
    {
        printf(" ● 排队信息展示 【 共有0人 】 \n");
        printf(" ●--【 完成全部检测需要0分钟 】\n");
    }
    else
    {
        printf(" ● 排队信息展示 【 共有%d人 】 \n",((p->rear)-(p->front)+List_MAX)%List_MAX);
        for(i= p->front;i<p->rear;i++)
        {
            printf(" ↓身份证号码：%d ,姓名：%s \n",p->list[i].id,p->list[i].name);
        }
        printf(" ●--【 完成全部检测需要%d.0分钟 】\n",((p->rear)-(p->front)+List_MAX)%List_MAX);
    }

}

// 主函数
int main()
{
    int choice = 0 , h_choice =0; // 选择
    int i;

    list My_list;    // 排队
    list end_list;   // 已检
    list temp_list;  // 排序

    My_list.rear=0;  // 队尾
    My_list.front=0; // 队头
    end_list.rear=0;
    end_list.front=0;
    temp_list.rear=0;
    temp_list.front=0;

    printf("--------------------------------------\n");
    printf("基于顺序存储结构的核酸检测队列管理系统\n");
    do
    {
        printf("--------------------------------------\n");
        List_show(&My_list);  // 排队信息展示

        printf("请选择系统功能：\n");
        printf("输入1录入排队人员信息\n");
        printf("输入2安排人员核酸检测\n");
        printf("输入3查询人员是否检测\n");
        printf("输入4身份证排序输出信息\n");
        printf("输入-1结束系统程序\n");
        printf("--------------------------------------\n");
        printf("我的选择是：");
        scanf("%d",&choice);
        if(choice == 1)
        {
            printf("-------------------录入-----------------\n");
            in_list(&My_list);
            printf("-----------------录入成功!---------------\n\n");

        }

        else if(choice ==2)
        {
            printf("-------------------安排-----------------\n");
            printf(" 【单检输入1】 ● 【10人混检输入2】 \n");
            printf("我的选择是：");
            scanf("%d",&h_choice);
            if(h_choice ==1)
            {
                pop_list(&My_list,&end_list);
            }
            if(h_choice ==2)
            {
                for(i=1;i<=10;i++)
                {
                    pop_list(&My_list,&end_list);
                }
            }
        }

        else if(choice ==3)
        {
            printf("-------------------查询-----------------\n");
            find_list(&My_list,&end_list);
        }

        else if(choice ==4)
        {
            printf("-------------------输出-----------------\n");
            id_show(&My_list,&temp_list);
            printf("按照身份证排序输出信息如下：\n");
            List_show(&temp_list);
        }

    }while(choice != -1);
    printf("----------------程序正常结束!--------------\n");
    return 0;
}
