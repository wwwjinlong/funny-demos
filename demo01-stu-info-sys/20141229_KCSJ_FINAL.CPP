#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//��Ԥ������
#define T1      "-----------------------ѧ����Ϣ����ϵͳ----------------------\n\n"
#define T2      "-------------------------[by Chain]-------------------------\n\n"
#define CHOOSE  ">������������еĲ������(0-%d):"
#define EXIT    "\n>��ȷ��Ҫ�˳�ϵͳô?�˳�ǰ��ע�Ᵽ���ޡ�\n (�Ƚ��б��沢�˳��밴S,ȷ��ֱ���˳��밴Y��ȡ�������ز˵��밴N):"
#define TABHEAD "|--------------------------------------------------------------|\n|   ���  ѧ��    ����    ����  |�����ɼ����| ����  ��ѧ  Ӣ��|\n"
#define TABLINE "|--------------------------------------------------------------|\n"

//����Ҫ����������
void s1_rec();     //���˵�_ѧ����Ϣ ¼�� �޸� ɾ��
void s2_rec();     //���˵�_ѧ����Ϣ ��� ��ѯ ����
void save_rec();   //���˵�_ѧ����Ϣ����
void exit_rec();   //���˵�_�˳�ϵͳ

void input_rec();  //�Ӳ˵�_ѧ����Ϣ ¼��
void add_rec();    //�Ӳ˵�_ѧ����Ϣ ����
void change_rec(); //�Ӳ˵�_ѧ����Ϣ �޸�
void delete_rec();//�Ӳ˵�_ѧ����Ϣ ɾ��

void surf_rec(); //�Ӳ˵�_ѧ����Ϣ ���
void search_rec(); //�Ӳ˵�_ѧ����Ϣ ��ѯ
void arrange_rec(); //�Ӳ˵�_ѧ����Ϣ ����

//���Ӻ�����
void add_s();//ѧ����Ϣ ¼�� ����
void surf_s();//ѧ����Ϣ ��� ����

//������������
void sys_load();//����ϵͳѡ��
void print_main_menu();//���˵���ʾ
void example_rec();//ϵͳ����ʾ��
void file_load();//�ļ�����            
void file_save();//�ļ�����
void sys_rec();//��ʼ��ʹ��                      

//�����ݽṹ���塿
//ѧ�ţ����������䣬�ɼ�
//�ɼ��ɰ����γ̵Ļ�����Ϣ���γ̱�š��γ����ơ����Գɼ���ƽʱ�ɼ����ۺϳɼ���ѧ�֡����޷��
typedef struct _score
{int math,english,chinese;}SCORE;
typedef struct _stu
{
	int num;
	char name[10];
	int age;
    SCORE score;
}STU;
STU stu[40];

//�����ȫ�ֱ�����
char sel=1;
int total=0;
int id=0;
int tabhead=1;
int i=0;
FILE *fp;

//*************************************************ϵͳ����********************************************************************************
//��main������
void main()
{
	sys_load();
}

void sys_load()
{
	while(1)
	{
	     system("cls");sel=1;
	     printf(T1);
	     printf("\n\n                    1.��������ϵͳ\n\n                    2.��ʼ������ϵͳ(��һ��ʹ��)\n\n\n                    0.�˳�ϵͳ\n\n");
	     printf(T2);

         printf(CHOOSE,1);
         sel=getchar();
		 switch(sel)
		 {
	       case '1':
			   {
				   	file_load();
					example_rec();
					printf("\n\n>OK,");
					system("pause");
					print_main_menu();
					break;
			   }
		   case '2':sys_rec();break;
		   case '0':exit(0);break;
		 }
	}
    return;
}


void print_main_menu()
{
	while(1)
	{
	   system("cls");sel=1;
	   printf(T1);
	   printf("1.ѧ����Ϣ ¼�� ���� �޸� ɾ�� \n");
	   printf("2.ѧ����Ϣ ��� ��ѯ ���� \n");
       printf("3.ѧ����Ϣ ����\n");
       printf("0.�˳�ϵͳ \n\n");
   	   printf(T2);

	   printf(CHOOSE,3);
	   sel=getchar();
       switch(sel)
	   {
	       case '1':s1_rec();break;
		   case '2':s2_rec();break;
		   case '3':file_save();break;
		   case '0':exit_rec();break;
		   default: continue;
	   }
	}
	return;
}

void s1_rec()
{
	while(1)
	{
	   system("cls");sel=1;
       printf(T1);
	   printf("*ѧ����Ϣ ¼�� ���� �޸� ɾ��: \n\n");
       printf("  1.ѧ����Ϣ ¼��  \n");
	   printf("  2.ѧ����Ϣ ����  \n");
       printf("  3.ѧ����Ϣ �޸� \n");
       printf("  4.ѧ����Ϣ ɾ�� \n\n");
	   printf("  0.�������˵�\n\n");
	   printf(T2);

       printf(CHOOSE,4);
	   sel=getchar();
       switch(sel)
	   {
	       case '1':input_rec();break;
		   case '2':add_rec();break;
           case '3':change_rec();break;
           case '4':delete_rec();break;
		   case '0':print_main_menu();break;
		   default: continue;
	   }
	}
	return;
}

void s2_rec()
{
	while(1)
	{
	   system("cls");sel=1;
       printf(T1);
       printf("*ѧ����Ϣ ��� ��ѯ ����: \n\n");
       printf("  1.ѧ����Ϣ ���\n");
       printf("  2.ѧ����Ϣ ��ѯ\n");
       printf("  3.ѧ����Ϣ ����\n\n");
	   printf("  0.�������˵�\n\n");
	   printf(T2);

       printf(CHOOSE,3);
       sel=getchar();
       switch(sel)
	   {
	       case '1':surf_rec();break;
		   case '2':search_rec();break;
           case '3':arrange_rec();break;
		   case '0':print_main_menu();break;
		   default: continue;
	   }
	}
	return;
}

//*===============================================��Ҫʵ�ֺ���====================================================================*
void input_rec()
{
	if(total!=0)
	{
		printf("\n��ǰ���ݿ�������%d��ѧ����Ϣ��ȷ��Ҫ��ʼ��������������?\n   (ȷ���밴Y��ȡ���������밴N���������ӹ����밴A):",total);
ask1:   sel=getchar();
		if(sel=='Y') goto inputfun;
		else if(sel=='N') print_main_menu();
		else if(sel=='A') add_rec();
		else goto ask1;
	}

inputfun:	
	sel=1;id=1;
	printf("\n>��ʼ������Ϣ¼��:\n");total=0;
	while(sel!='N')
	{
	   printf(" \n��������Ϊ%2d��ͬѧ����Ϣ��\n\n",total+1);
	   total++;
	   add_s();
	   sel=1;
	   printf("\n>�����Ƿ��������������һ��(Y/N):"); 
	   while(1)
	   {
	      sel=1;
	      sel=getchar();
		  if(sel=='Y'||sel=='N') break;
       }
	}
    printf("\n>������������ܹ�������%d������.\n\n",total);
	system("pause");
    print_main_menu();
	return;	
}


void add_rec()
{
	if(total!=0)
	{
		printf("\n��ǰ���ݿ�������%d��ѧ����Ϣ\nȷ�������밴Y��ȡ���������밴N):",total);
ask2:   sel=getchar();
		if(sel=='Y') goto addfun;
		else if(sel=='N') print_main_menu();
		else goto ask2;
	}

addfun:
	sel=1;id=1;
	printf("\n>��ʼ������Ϣ���ӹ���:\n\n");
	while(sel!='N')
	{
       printf("��ǰ����%d��ѧ������Ϣ\n",total);
       printf(" \n������Ҫ���ӵı��Ϊ%2d��ͬѧ����Ϣ��\n\n",total+1);
	   add_s();
       total++; 
	   printf("\n>�����Ƿ��������������һ��(Y/N):"); 
	   while(1)
	   {
	      sel=1;
	      sel=getchar();
		  if(sel=='Y'||sel=='N') break;
       }
	}

	printf("\n>���������ϵͳ���ݿ�Ŀǰ����%d������.\n\n",total);
	system("pause");
    print_main_menu();
	return;	
}

void add_s()
{
	    printf("   ������ѧ�ţ�");scanf("%d",&stu[total].num);
		printf("   ������������");scanf("%s",&stu[total].name);
		printf("   ���������䣺");scanf("%d",&stu[total].age);
		printf("   >��������������ɼ���أ�\n");
		printf("        �밴˳���������� ���� ��ѧ Ӣ�� �ɼ�(�ո����):");scanf("%d%d%d",&stu[total].score.chinese,&stu[total].score.math,&stu[total].score.english);
}

void change_rec()
{
    if(total!=0)
	{
		printf("\n��ǰ���ݿ�������%d��ѧ����Ϣ\nȷ�Ͽ�ʼ�޸��밴Y��ȡ���������밴N:",total);
ask3:   sel=getchar();
		if(sel=='Y') goto changefun;
		else if(sel=='N') print_main_menu();
		else goto ask3;
	}
	else 
		if(total==0)
		{
		     printf("\n����δ�����κ�����!\n\n");
             system("pause");
             print_main_menu();
		}
	


changefun:
	tabhead=1;sel=1;id=1;
	printf("\n>��ʼ������Ϣ�޸Ĺ���:\n\n");sel=1;
    printf("��������Ҫ�޸ĵ�ѧ����ţ�");
	id=0;
	scanf("%d",&id);
    printf("\n��ѧ����Ϣ:\n");
	surf_s();  
	    printf("\n�����������ѧ����Ϣ:\n");
        printf("   ������ѧ�ţ�");scanf("%d",&stu[id].num);
		printf("   ������������");scanf("%s",&stu[id].name);
		printf("   ���������䣺");scanf("%d",&stu[id].age);
		printf("   >��������������ɼ���أ�\n");
		printf("        �밴˳���������� ���� ��ѧ Ӣ�� �ɼ�(�ո����):");
		scanf("%d%d%d",&stu[id].score.chinese,&stu[id].score.math,&stu[id].score.english);

    printf(">>>��Ϣ�޸���ɣ�����:\n");
    surf_s();
    system("pause");
	return;
}


void delete_rec()
{
	if(total!=0)
	{
		printf("\n��ǰ���ݿ�������%d��ѧ����Ϣ\nȷ�Ͽ�ʼɾ���밴Y��ȡ���������밴N:",total);
ask4:   sel=getchar();
		if(sel=='Y') goto deletefun;
		else if(sel=='N') print_main_menu();
		else goto ask4;
	}
	else 
		if(total==0)
		{
		     printf("\n����δ�����κ�����!\n\n");
             system("pause");
             print_main_menu();
		}


deletefun:
	tabhead=1;sel=1;id=1;
	printf("\n>��ʼ������Ϣɾ������:\n\n");sel=1;
	printf("��������Ҫɾ����ѧ����ţ�");
	id=0;
	scanf("%d",&id);
    printf("\n��ѧ����Ϣ:\n");
	surf_s();  
    
	printf("��ȷ����Ϣ���󣬰�Yɾ����N�������˵�:");
	sel=1;
	scanf("%s",&sel);
	if(sel=='N') print_main_menu();
	if(sel=='Y') 
	{
		for(int i=id;i<total;i++)
		{
           stu[i].num=stu[i+1].num;
		   strcpy(stu[i].name,stu[i+1].name);
		   stu[i].age=stu[i+1].age;
		   stu[i].score.chinese=stu[i+1].score.chinese;
		   stu[i].score.math=stu[i+1].score.math;
		   stu[i].score.english=stu[i+1].score.english;
		   
		}
		total--;
		printf("\n>>>ɾ�����Ϊ%d�Ĺ��������.\n",id);
        printf("\n��ǰ���ݿ���ʣ��%d��ѧ����Ϣ.\n",total);
	}
    printf("����������ز˵�...\n\n");
    system("pause");
    print_main_menu();
	return;
}


void surf_rec()
{
	if(total!=0)
	{
		printf("\n��ǰ���ݿ�������%d��ѧ����Ϣ\n��ʼ��������밴Y��ȡ���������밴N:",total);
ask5:   sel=getchar();
		if(sel=='Y') goto surffun;
		else if(sel=='N') print_main_menu();
		else goto ask5;
	}
	else 
		if(total==0)
		{
		     printf("\n����δ�����κ�����!\n\n");
             system("pause");
             print_main_menu();
		}


surffun:
    tabhead=1;sel=1;id=1;
    printf("\n>��ʼ������Ϣ�������:\n\n");sel=1;
	printf("���е�ѧ����Ϣ�������:\n");
	for(id=1;id<=total;id++)
	{
     surf_s();
	 tabhead=0;
	}
    printf("\n���е�ѧ����Ϣ����ȫ�������%d������...\n\n",total);
    printf("����������ز˵�...\n\n");
    system("pause");
    print_main_menu();
	return;
}

void surf_s()
{ 
    if(tabhead==1) printf(TABHEAD);
	printf(TABLINE);
    printf("|   %-5d %-5d   %-5s    %-2d                  %-3d   %-3d   %-3d |\n",
		id,stu[id].num,stu[id].name,stu[id].age,
		stu[id].score.chinese,stu[id].score.math,stu[id].score.english);
    printf(TABLINE);
	return;
}

void search_rec()
{
	if(total!=0)
	{
		printf("\n��ǰ���ݿ�������%d��ѧ����Ϣ\n��ʼ��ѯ�����밴Y��ȡ���������밴N:",total);
ask6:   sel=getchar();
		if(sel=='Y') goto searchfun;
		else if(sel=='N') print_main_menu();
		else goto ask6;
	}
	else 
		if(total==0)
		{
		     printf("\n����δ�����κ�����!\n\n");
             system("pause");
             print_main_menu();
		}


searchfun:
	sel=1;id=1;
	printf("\n>��ʼ������Ϣ��ѯ����:\n\n");sel=1;
    printf("�����������ѯ����Ϣ\n  (1.ѧ�� 2.���� 3.���� \nc.���ĳɼ� m.��ѧ�ɼ� e.Ӣ��ɼ�):");
input1:
    scanf("%s",&sel);
	int in1;
       switch(sel)
	   {
	       case '1':
			   {
				   printf("\n�������ѯ��ѧ��:");
                   scanf("%d",&id);
				   break;
			   }
		   case '2':
			   {
				   printf("\n�������ѯ������:");
                   char name1[10];
				   scanf("%s",name1);
				   for(int i=1;i<=total;i++)
				   if(strcmp(stu[i].name,name1)==0) {id=i;break;}
				   break;
			   }
           case '3':
			   {
				   printf("\n�������ѯ������:");
                   scanf("%d",&in1);
				   for(int i=1;i<=total;i++)
					   if(stu[i].age==in1) {id=i;break;}
				   break;
			   }
           case 'c':
			   {
				   printf("\n�������ѯ�����ĳɼ�:");
                   scanf("%d",&in1);
				   for(int i=1;i<=total;i++)
					   if(stu[i].score.chinese==in1) {id=i;break;}
				   break;
			   }
		   case 'm':
			   {
				   printf("\n�������ѯ����ѧ�ɼ�:");
                   scanf("%d",&in1);
				   for(int i=1;i<=total;i++)
					   if(stu[i].score.math==in1) {id=i;break;}
				   break;
			   }
           case 'e':
			   {
				   printf("\n�������ѯ��Ӣ��ɼ�:");
                   scanf("%d",&in1);
				   for(int i=1;i<=total;i++)
					   if(stu[i].score.english==in1) {id=i;break;}
				   break;
			   }
		   default: goto input1;
	   }
	   	printf("��ѧ������Ϣ���£�\n");
        surf_s();
        printf("\n����������ص����˵�...\n");
		system("pause");
        print_main_menu();

	return;
}


void arrange_rec()
{
	if(total!=0)
	{
		printf("\n��ǰ���ݿ�������%d��ѧ����Ϣ\n��ʼ��������밴Y��ȡ���������밴N:",total);
ask7:   sel=getchar();
		if(sel=='Y') goto arrangefun;
		else if(sel=='N') print_main_menu();
		else goto ask7;
	}
	else 
		if(total==0)
		{
		     printf("\n����δ�����κ�����!\n\n");
             system("pause");
             print_main_menu();
		}


arrangefun:
    int t1,t2,t3;char name1[10];

    struct _score2
	{int math,english,chinese;};
    struct _stu2
	{
	   int num;
	   char name[10];
	   int age;
       struct _score2 score;
	}arr[40];

	sel=1;id=1;tabhead=1;int j=0;
	printf("\n>��ʼ������Ϣ����(����)����:\n\n");
	printf("�����������������Ϣ\n  (c.���ĳɼ� m.��ѧ�ɼ� e.Ӣ��ɼ�):");
	for(i=0;i<=total;i++)
	   {
		   arr[i].num=stu[i].num;
		   strcpy(arr[i].name,stu[i].name);
           arr[i].age=stu[i].age;
		   arr[i].score.chinese=stu[i].score.chinese;
           arr[i].score.english=stu[i].score.english;
		   arr[i].score.math=stu[i].score.math;
	   }
input2:
    scanf("%s",&sel);
       switch(sel)
	   {
	        case 'c':
			   {
				   printf("\n�����ĳɼ���������:\n");
                  for(j=0;j<total;j++)
		          for(i=0;i<total-j;i++)
			        if(arr[i].score.chinese<arr[i+1].score.chinese)
					{
				       strcpy(name1,arr[i].name);
					   strcpy(arr[i].name,arr[i+1].name);
				       strcpy(arr[i+1].name,name1);

					   t1=arr[i].score.chinese;
				       arr[i].score.chinese=arr[i+1].score.chinese;
				       arr[i+1].score.chinese=t1;

				       t2=arr[i].score.english;
				       arr[i].score.english=arr[i+1].score.english;
				       arr[i+1].score.english=t2;

				       t3=arr[i].score.math;
				       arr[i].score.math=arr[i+1].score.math;
				       arr[i+1].score.math=t3;

					}

			  break;
			   }
		   case 'm':
			   {
			   printf("\n����ѧ�ɼ���������:\n");
			   for(j=0;j<total;j++)
		          for(i=0;i<total-j;i++)
			         if(arr[i].score.math<arr[i+1].score.math)
					{
				       strcpy(name1,arr[i].name);
					   strcpy(arr[i].name,arr[i+1].name);
				       strcpy(arr[i+1].name,name1);

					   t1=arr[i].score.chinese;
				       arr[i].score.chinese=arr[i+1].score.chinese;
				       arr[i+1].score.chinese=t1;

				       t2=arr[i].score.english;
				       arr[i].score.english=arr[i+1].score.english;
				       arr[i+1].score.english=t2;

				       t3=arr[i].score.math;
				       arr[i].score.math=arr[i+1].score.math;
				       arr[i+1].score.math=t3;
					 }
			   break;
			   }
           case 'e':
			   {
			   printf("\n��Ӣ��ɼ���������:\n");
                 for(j=0;j<total;j++)
		          for(i=0;i<total-j;i++)
			         if(arr[i].score.english<arr[i+1].score.english)
					{
				       strcpy(name1,arr[i].name);
					   strcpy(arr[i].name,arr[i+1].name);
				       strcpy(arr[i+1].name,name1);

					   t1=arr[i].score.chinese;
				       arr[i].score.chinese=arr[i+1].score.chinese;
				       arr[i+1].score.chinese=t1;

				       t2=arr[i].score.english;
				       arr[i].score.english=arr[i+1].score.english;
				       arr[i+1].score.english=t2;

				       t3=arr[i].score.math;
				       arr[i].score.math=arr[i+1].score.math;
				       arr[i+1].score.math=t3;
					 }
			   break;
			   }
		   default: goto input2;
	   }


		printf("|   ���    ����    ����  ��ѧ  Ӣ�� |\n");
		for(i=0;i<=total-1;i++)
            printf("|   %-5d   %-5s    %-3d   %-3d   %-3d |\n",
	     	i+1,arr[i].name,arr[i].score.chinese,arr[i].score.math,arr[i].score.english);
		putchar(10);
		printf(">�������!\n");
		system("pause");

	return;
}

//-----------------------------------------������������----------------------------------------------------------------
void exit_rec()
{
    printf(EXIT);
	while(1)
	{
	    sel=1;
		sel=getchar();
        switch(sel)
		{
	       case 'Y':{printf("|-------------------------|\n|       Thank you!!       |\n|-------------------------|\n\n");exit(0);break;}
		   case 'N':print_main_menu();break;
           case 'S':file_save();break;
		   default: continue;
		}
	}
    fclose(fp);
	return;
}


void file_load()
{
	if((fp=fopen("data","rb"))==NULL) {printf("\n�޷������ļ�data\n");exit(0);}
	assert(fp);total=0;
    for(i=0;i<=40;i++)
		fread(&stu[i],sizeof(struct _stu),1,fp);
    for(i=0;i<=40;i++)
		if(stu[i+1].num==0) break;
	total=i;
    fclose(fp);
	return;
}

void file_save()
{
	if((fp=fopen("data","wb"))==NULL) {printf("\n�޷���д�ļ�data\n");exit(0);}
	assert(fp);
    for(i=0;i<=total;i++)
		fwrite(&stu[i],sizeof(struct _stu),1,fp);
	printf(">����ɹ�..��������������˵�...\n");
	fclose(fp);
	system("pause");
	print_main_menu();
	return;
}

void sys_rec()
{
		printf("\n\n>��ȷ��Ҫ��ʼ������ϵͳô? ע�����������ݽ���ʧ!!\n  ��Yȷ��N����:");
ask8:   sel=getchar();
		if(sel=='Y') goto sysrecfun;
		else if(sel=='N')	sys_load();
		else goto ask8;


sysrecfun:
	sel=1;
	if((fp=fopen("data","wb+"))==NULL) {printf("\n�޷���д�ļ�data\n");exit(0);}
	printf("\n\n>��ʼ���ɹ�,");
	fclose(fp);
	system("pause");
	sys_load();
	return;
}


//----------------------------------ϵͳ����ʾ��---------------------------------------------
void example_rec()
{
	stu[0].num=0;
	strcpy(stu[0].name,"exa");
    stu[0].age=20;
    stu[0].score.chinese=0;
    stu[0].score.math=0;
    stu[0].score.english=0;
    return;
}
