#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10       // �������10����
#define List_MAX 50  // �������50��

typedef struct people
{
    char name[MAX];
    int id;
}people;

typedef struct list
{
    people list[List_MAX];  // ��������
    int front;  // ͷ
    int rear;   // β
}list;

// ���ģ��
void in_list(list *p)
{
    int i,n; //¼������
    char inName[MAX] ={'\0'};
    int inID = 0;
    printf("��������Ҫ¼���������");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        if( (p->rear+1)%List_MAX == p->front )
        {
            printf("�Ŷ������Ѵ�����50��");
            break; //����
        }
        else
        {
            printf("�������Ŷ���Ա����:");
            scanf("%s",inName);
            printf("�������Ŷ���Ա���֤����:");
            scanf("%d",&inID);

            strcpy(p->list[p->rear].name, inName); // ¼��
            p->list[p->rear].id = inID;     //¼��

            p->rear = (p->rear+1)%List_MAX ; // ¼��ɹ�ָ����ǰ
        }
    }
}

// ����ģ��
void pop_list(list *p,list *m)
{
    if(p->rear == p->front)
    {
        printf("�ӿգ�");
    }
    else
    {
        m->list[m->rear].id = p->list[p->front].id ;           // �洢�Ѽ���Ϣ
        strcpy( m->list[m->rear].name, p->list[p->front].name);
        m->rear = m->rear+1 ;

        p->front = (p->front+1)%List_MAX ;
    }
}

// ��ѯ����
void find_list(list *p,list *m)
{
    int find_id = 0; // ���ҵ����֤
    int i =0 ,flag =0;
    printf("�����������Ա���֤��");
    scanf("%d",&find_id);
    for(i=p->front;i<p->rear;i++)
    {
        if(find_id == p->list[i].id)
        {
            printf("��%s�����������Ŷӣ�\n",p->list[i].name);
            flag = 1;
            break;
        }
    }
    for(i=m->front;i<m->rear ;i++)
    {
        if(find_id == m->list[i].id)
        {
            printf("��%s�������Ѿ���ɺ��ᣡ\n",m->list[i].name);
            flag =1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("����û���Ŷ������ᣡ\n");
    }
}

// ���֤����չʾ����
void id_show(list *p,list *m)
{
    int t_id;
    char t_name[10];
    int i ,j ,len;
    for( i=p->front ;i<=p->rear;i++ )  // ����
    {
        m->list[i].id = p->list[i].id ;
        strcpy( m->list[i].name, p->list[i].name);
    }
    m->front = p->front;  // ����ƥ��
    m->rear = p->rear;


    len =((m->rear)-(m->front)+List_MAX)%List_MAX;  // ����
    for(j=m->front;j<len;j++) // ð������
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

// �Ŷ���Ϣչʾ
void List_show(list *p)
{
    int i;
    if(p->rear == p->front)  // �ӿ�
    {
        printf(" �� �Ŷ���Ϣչʾ �� ����0�� �� \n");
        printf(" ��--�� ���ȫ�������Ҫ0���� ��\n");
    }
    else
    {
        printf(" �� �Ŷ���Ϣչʾ �� ����%d�� �� \n",((p->rear)-(p->front)+List_MAX)%List_MAX);
        for(i= p->front;i<p->rear;i++)
        {
            printf(" �����֤���룺%d ,������%s \n",p->list[i].id,p->list[i].name);
        }
        printf(" ��--�� ���ȫ�������Ҫ%d.0���� ��\n",((p->rear)-(p->front)+List_MAX)%List_MAX);
    }

}

// ������
int main()
{
    int choice = 0 , h_choice =0; // ѡ��
    int i;

    list My_list;    // �Ŷ�
    list end_list;   // �Ѽ�
    list temp_list;  // ����

    My_list.rear=0;  // ��β
    My_list.front=0; // ��ͷ
    end_list.rear=0;
    end_list.front=0;
    temp_list.rear=0;
    temp_list.front=0;

    printf("--------------------------------------\n");
    printf("����˳��洢�ṹ�ĺ�������й���ϵͳ\n");
    do
    {
        printf("--------------------------------------\n");
        List_show(&My_list);  // �Ŷ���Ϣչʾ

        printf("��ѡ��ϵͳ���ܣ�\n");
        printf("����1¼���Ŷ���Ա��Ϣ\n");
        printf("����2������Ա������\n");
        printf("����3��ѯ��Ա�Ƿ���\n");
        printf("����4���֤���������Ϣ\n");
        printf("����-1����ϵͳ����\n");
        printf("--------------------------------------\n");
        printf("�ҵ�ѡ���ǣ�");
        scanf("%d",&choice);
        if(choice == 1)
        {
            printf("-------------------¼��-----------------\n");
            in_list(&My_list);
            printf("-----------------¼��ɹ�!---------------\n\n");

        }

        else if(choice ==2)
        {
            printf("-------------------����-----------------\n");
            printf(" ����������1�� �� ��10�˻������2�� \n");
            printf("�ҵ�ѡ���ǣ�");
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
            printf("-------------------��ѯ-----------------\n");
            find_list(&My_list,&end_list);
        }

        else if(choice ==4)
        {
            printf("-------------------���-----------------\n");
            id_show(&My_list,&temp_list);
            printf("�������֤���������Ϣ���£�\n");
            List_show(&temp_list);
        }

    }while(choice != -1);
    printf("----------------������������!--------------\n");
    return 0;
}
