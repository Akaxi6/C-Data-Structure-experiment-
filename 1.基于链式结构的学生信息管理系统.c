#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define N 100

typedef struct student
{
    char name[N];     // ѧ������
    int x_num;        // ѧ��
    int tel_num;      // �绰����
    struct student *next; //ָ��
}student;


// ϵͳ����չʾ����
int System_Show(int x)
{
    printf("          ***************************************************************\n");
    printf("          ****************������ʽ�ṹ��ѧ����Ϣ����ϵͳ*****************\n");
    printf("          ***************************************************************\n");
    printf("          ***       ��ѡ��ϵͳ���ܣ�                                  ***\n");
    printf("          ***      >����1���ѧ����Ϣ                                 ***\n");
    printf("          ***      >����2����ѧ����Ϣ                                 ***\n");
    printf("          ***      >����3�޸�ѧ����Ϣ                                 ***\n");
    printf("          ***      >����4ɾ��ѧ����Ϣ                                 ***\n");
    printf("          ***      >����5��ӡѧ����Ϣ                                 ***\n");
    printf("          ***      >����-1����ϵͳ                                    ***\n");
    printf("          ***************************************************************\n");
    printf("          ***�ҵ�ѡ���ǣ�");
    scanf("%d",&x);  // �û�ѡ��
    return x;
}

// ����������
student* Creat_list(student* rear1)
{
    student* p = (student*)malloc(sizeof(student*));

    getchar();
    printf("          ***������ѧ�����֣�");
    scanf("%s",p->name);
    printf("          ***������ѧ��ѧ�ţ�");
    getchar();
    scanf("%d",&p->x_num);
    printf("          ***������ѧ���绰��");
    getchar();
    scanf("%d",&p->tel_num);
    printf("          ************************ѧ����Ϣ¼��ɹ���**********************\n");

    p->next = NULL;
    rear1->next = p;
    rear1 = p;
    return rear1;
}

// ��Ϣչʾ
void List_ALL_show(student* p)
{
    int count =0;
    printf("          ***************************************************************\n");
    printf("          ****************������ʽ�ṹ��ѧ����Ϣ����ϵͳ*****************\n");
    while(p!= NULL)
    {
        count++;
        printf("          ***************************************************************\n");
        printf("          ***ѧ��������%s  ѧ��ѧ�ţ�%d  ѧ���绰��%d   ***\n",p->name,p->x_num,p->tel_num);

        p = p->next;
    }
    printf("          **************************�ܹ���%d��ѧ��************************\n",count);
}

// ����չʾ
void List_single_show(student* p)
{
    printf("          ***************************************************************\n");
    printf("          ***ѧ��������%s  ѧ��ѧ�ţ�%d  ѧ���绰��%d   ***\n",p->name,p->x_num,p->tel_num);
}



// ����������
void change(student** p)
{
    int find_x_num =0; //����ѧ��
    int choice = 0;
    char change_name[N] ={'\0'};
    int change_num = 0;
    printf("          ***���������ѧ��ѧ�ţ�");
    scanf("%d",&find_x_num);
    int T=0;

    if((*p)->next == NULL)
    {
        printf("          ***����Ϊ��!");
    }
    else
    {
        *p = (*p)->next ;
        while((*p) != NULL )
        {
            if((*p)->x_num == find_x_num)
            {
                List_single_show(*p);   // չʾ
                printf("          ***����1�޸�������������2�޸���绰���룺");
                scanf("%d",&choice);
                if(choice == 1)
                {
                    printf("          ***�������޸ĺ�������");
                    scanf("%s",change_name);
                    strcpy((*p)->name, change_name);
                    List_single_show(*p); //չʾ
                }
                else if(choice == 2)
                {
                    printf("          ***�������޸ĺ�绰���룺");
                    scanf("%d",&change_num);
                    (*p)->tel_num = change_num;
                    List_single_show(*p); //չʾ
                }
                else
                {
                    printf("�������");
                }
                T = 1; // �ҵ�
            }
            (*p) = (*p)->next ;
        }
        if(T==0)
        {
            printf("          ***û�д�ѧ��ͬѧ��\n");
        }
    }

}

// ��������
void cha(student** m)
{
    int cha_x_num =0;
    student* t = (student*)malloc(sizeof(student*));

    printf("          ***����������λѧ��ͬѧ������룺");
    scanf("%d",&cha_x_num);
    *m = (*m)->next ;
    while((*m) != NULL )
    {
        if((*m)->x_num == cha_x_num)
        {
            List_single_show(*m);   // չʾ
            getchar();
            printf("          ***���������ѧ�����֣�");
            scanf("%s",t->name);
            printf("          ***���������ѧ��ѧ�ţ�");
            getchar();
            scanf("%d",&t->x_num);
            printf("          ***���������ѧ���绰��");
            getchar();
            scanf("%d",&t->tel_num);
            printf("          ************************ѧ����Ϣ����ɹ���**********************\n");
            t->next = (*m)->next;
            (*m)->next = t;
        }
        (*m) = (*m)->next;
    }
}

// ɾ��������
void delted(student** q)
{
    int find_x_num =0;
    printf("          ***��������Ҫɾ��ѧ����ѧ�ţ�");
    scanf("%d",&find_x_num);
    while((*q)->next != NULL)
    {
        if((*q)->next->x_num == find_x_num)
        {
            (*q)->next = (*q)->next->next; // ɾ��
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
    int choice = 0 ,i=0 , n=0;    // �û�ѡ��

    while(choice != -1)
    {
        if(choice == 1)
        {
            printf("          ************************¼��ѧ����Ϣ***************************\n");
            printf("          ***��������Ҫ¼���ѧ��������");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                rear1 = Creat_list(rear1); // ��������
            }
            List_ALL_show(head->next); // չʾ����
        }

       if(choice == 2)
        {
            printf("          ************************����ѧ����Ϣ***************************\n");
            List_ALL_show(head->next); // չʾ����
            rearc = head;
            cha(&rearc);
            List_ALL_show(head->next); // չʾ����
        }

        if(choice == 3)
        {
            printf("          ************************����ѧ����Ϣ***************************\n");
            List_ALL_show(head->next); // չʾ����
            rear2 = head;
            change(&rear2);  // ������Ʒ��Ϣ
            List_ALL_show(head->next);
        }

        if(choice == 4)
        {
            List_ALL_show(head->next); // չʾ����
            rear3 = head;
            delted(&rear3);
            List_ALL_show(head->next); // չʾ����
        }

        if(choice == 5)
        {
            List_ALL_show(head->next);
        }

        choice = System_Show(choice);  // չʾ���棬��һ��ѭ��
    }
    List_ALL_show(head->next); // չʾϵͳ
    printf("          ***********************ϵͳ��������������**********************\n");
}
