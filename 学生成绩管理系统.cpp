#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100 //����������ʾ�ɼ���Ϣ�ṹ�����鳤��
#define STR 50  //����������ʾ�ַ����鳤��

//�����ɼ���Ϣ�ṹ��
struct Score {
    char sno[STR];        //ѧ    ��
    char name[STR];       //��    ��
    char gender[STR];     //��    ��
    char add[STR];        //��ͥסַ
    char telephone[STR];  //��ϵ�绰
    char classes[STR];    //��    ��
    float chinese;        //���ĳɼ�
    float math;           //��ѧ�ɼ�
    float english;        //Ӣ��ɼ�
};

//��ӳɼ���Ϣ
int addScoreInfo(struct Score sco[], int scoCount) {
    int i;
    struct Score input;
    //��鵱ǰ�ɼ���Ϣ�Ƿ�����
    if (scoCount == MAX) {
        printf("��ǰ�ɼ���Ϣ����,�޷��������!\n\n");
        return scoCount;
    }
    //��ʼ����ѧ��
    printf("������ѧ��:");
    scanf("%s", input.sno);
    //��������ѧ���Ƿ��Ѵ���
    for (i = 0; i < scoCount; i++) {
        if (strcmp(sco[i].sno, input.sno) == 0) {
            break;
        }
    }
    if (i == scoCount) {
        //�����ѧ�Ų�����
        //����������Ϣ
        printf("����������:");
        scanf("%s", input.name);
        printf("�������Ա�:");
        scanf("%s", input.gender);
        printf("��ͥסַ:");
        scanf("%s", input.add);
        printf("��ϵ�绰:");
        scanf("%s", input.telephone);
        printf("������༶:");
        scanf("%s", input.classes);
        printf("���������ĳɼ�:");
        scanf("%f", &input.chinese);
        printf("��������ѧ�ɼ�:");
        scanf("%f", &input.math);
        printf("������Ӣ��ɼ�:");
        scanf("%f", &input.english);
        //����ɼ���Ϣ��������
        sco[scoCount] = input;
        scoCount++;
        //����ɼ���Ϣ�ɹ�
        printf("��ӳɼ���Ϣ�ɹ�!\n\n");
    }
    else {
        //�����ѧ���Ѵ���
        printf("��ӳɼ���Ϣʧ��,�����ѧ���Ѵ���!\n\n");
    }
    return scoCount;
}
//�޸ĳɼ���Ϣ
void modifyScoreInfo(struct Score sco[], int scoCount) {
    int i;
    struct Score input;
    //��鵱ǰ�ɼ���Ϣ�Ƿ�Ϊ��
    if (scoCount == 0) {
        printf("��ǰ�ɼ���ϢΪ��,�޷������޸�!\n\n");
        return;
    }
    //��ʼ����ѧ��
    printf("��������Ҫ�޸ĵ�ѧ��:");
    scanf("%s", input.sno);
    //��������ѧ���Ƿ����
    for (i = 0; i < scoCount; i++) {
        if (strcmp(sco[i].sno, input.sno) == 0) {
            break;
        }
    }
    if (i != scoCount) {
        //�����ѧ�Ŵ���
        //����������Ϣ
        printf("����������:");
        scanf("%s", input.name);
        printf("�������Ա�:");
        scanf("%s", input.gender);
        printf("��ͥסַ:");
        scanf("%s", input.add);
        printf("��ϵ�绰:");
        scanf("%s", input.telephone);
        printf("������༶:");
        scanf("%s", input.classes);
        printf("���������ĳɼ�:");
        scanf("%f", &input.chinese);
        printf("��������ѧ�ɼ�:");
        scanf("%f", &input.math);
        printf("������Ӣ��ɼ�:");
        scanf("%f", &input.english);
        //�޸ĵ�������
        sco[i] = input;
        //�޸ĳɼ���Ϣ�ɹ�
        printf("�޸ĳɼ���Ϣ�ɹ�!\n\n");
    }
    else {
        //�����ѧ�Ų�����
        printf("�޸ĳɼ���Ϣʧ��,�����ѧ�Ų�����!\n\n");
    }
}
//ɾ���ɼ���Ϣ
int deleteScoreInfo(struct Score sco[], int scoCount) {
    int i;
    struct Score input;
    //��鵱ǰ�ɼ���Ϣ�Ƿ�Ϊ��
    if (scoCount == 0) {
        printf("��ǰ�ɼ���ϢΪ��,�޷�����ɾ��!\n\n");
        return scoCount;
    }
    //��ʼ����ѧ��
    printf("��������Ҫɾ����ѧ��:");
    scanf("%s", input.sno);
    //��������ѧ���Ƿ����
    for (i = 0; i < scoCount; i++) {
        if (strcmp(sco[i].sno, input.sno) == 0) {
            break;
        }
    }
    if (i != scoCount) {
        //�����ѧ�Ŵ���
        //����ɾ����Ϣ
        for (; i < scoCount - 1; i++) {
            sco[i] = sco[i + 1];
        }
        scoCount--;
        //ɾ���ɼ���Ϣ�ɹ�
        printf("ɾ���ɼ���Ϣ�ɹ�!\n\n");
    }
    else {
        //�����ѧ�Ų�����
        printf("ɾ���ɼ���Ϣʧ��,�����ѧ�Ų�����!\n\n");
    }
    return scoCount;
}
//����ɼ���Ϣ
void browserScoreInfo(struct Score sco[], int scoCount) {
    int i;
    //��鵱ǰ�ɼ���Ϣ�Ƿ�Ϊ��
    if (scoCount == 0) {
        printf("��ǰ�ɼ���ϢΪ��,�޷��������!\n\n");
        return;
    }
    //�������
    printf("%-12s%-12s%-12s%-12s%-12s%-12s%-12s%-12s%-12s\n", "ѧ��", "����","�Ա�","��ͥסַ","��ϵ�绰", "�༶", "���ĳɼ�", "��ѧ�ɼ�", "Ӣ��ɼ�");
    //�����ɼ���Ϣ�ṹ���������,���ÿ���ɼ���Ϣ
    for (i = 0; i < scoCount; i++) {
        printf("%-12s%-12s%-12s%-12s%-12s%-12s%-12.2f%-12.2f%-12.2f\n", sco[i].sno, sco[i].name,sco[i].gender,sco[i].add,sco[i].telephone,sco[i].classes, sco[i].chinese, sco[i].math, sco[i].english);
    }
    //����
    printf("\n");
}
//��ѯ�ɼ���Ϣ
void queryScoreInfo(struct Score sco[], int scoCount) {
    int i, qobj, flag = 0;
    struct Score input;
    //��鵱ǰ�ɼ���Ϣ�Ƿ�Ϊ��
    if (scoCount == 0) {
        printf("��ǰ�ɼ���ϢΪ��,�޷�������ѯ!\n\n");
        return;
    }
    //��ʼ�����ѯ�Ķ�����
    printf("��������Ҫ��ѯ�Ķ�����(1.ѧ�� 2.���� 3.�Ա� 4.��ͥסַ 5.��ϵ�绰 6.�༶ 7.���ĳɼ� 8.��ѧ�ɼ� 9.Ӣ��ɼ�):");
    scanf("%d", &qobj);
    //�����ѯ������
    if (qobj == 1) {
        //����ѧ��
        printf("�������ѯ��ѧ��:");
        scanf("%s", input.sno);
    }
    else if (qobj == 2) {
        //��������
        printf("�������ѯ������:");
        scanf("%s", input.name);
    }
    else if (qobj == 3) {
        //�����Ա�
        printf("�������Ա�:");
        scanf("%s", input.gender);
    }
    else if (qobj == 4) {
        //�����ͥסַ
        printf("�������ͥסַ:");
        scanf("%s", input.add);
    }
    else if (qobj == 5) {
        //������ϵ�绰
        printf("��������ϵ�绰");
        scanf("%s", input.telephone);
    }
    else if (qobj == 6) {
        //����༶
        printf("�������ѯ�İ༶:");
        scanf("%s", input.classes);
    }
    else if (qobj == 7) {
        //�������ĳɼ�
        printf("�������ѯ�����ĳɼ�:");
        scanf("%f", &input.chinese);
    }
    else if (qobj == 8) {
        //������ѧ�ɼ�
        printf("�������ѯ����ѧ�ɼ�:");
        scanf("%f", &input.math);
    }
    else if (qobj == 9) {
        //����Ӣ��ɼ�
        printf("�������ѯ��Ӣ��ɼ�:");
        scanf("%f", &input.english);
    }
    else {
        //����Ķ����Ų�����
        printf("��ѯ�ɼ���Ϣʧ��,����Ķ����Ų�����!\n\n");
        return;
    }
    //�����ɼ���Ϣ�ṹ���������,��ѯ��������
    for (i = 0; i < scoCount; i++) {
        if ((qobj == 1 && strcmp(sco[i].sno, input.sno) == 0) || (qobj == 2 && strcmp(sco[i].name, input.name) == 0) || (qobj == 3 && strcmp(sco[i].classes, input.classes) == 0) || (qobj == 4 && sco[i].chinese == input.chinese) || (qobj == 5 && sco[i].math == input.math) || (qobj == 6 && sco[i].english == input.english)) {
            //�ж��Ƿ���Ҫ�������
            if (flag == 0) {
                //�������
                printf("%-12s%-12s%-12s%-12s%-12s%-12s%-12s%-12s%-12s\n", "ѧ��", "����","�Ա�","��ͥסַ","��ϵ�绰", "�༶", "���ĳɼ�", "��ѧ�ɼ�", "Ӣ��ɼ�");
                flag = 1;
            }
            //�����ϸ�ɼ���Ϣ
            printf("%-12s%-12s%-12s%-12s%-12s%-12s%-12.2f%-12.2f%-12.2f\n", sco[i].sno, sco[i].name,sco[i].gender,sco[i].add,sco[i].telephone, sco[i].classes, sco[i].chinese, sco[i].math, sco[i].english);
        }
    }
    //�ж��Ƿ��в�ѯ���
    if (flag == 0) {
        //û�в�ѯ���
        printf("��ѯ�޽��!\n");
    }
    //����
    printf("\n");
}
//����ɼ���Ϣ
void sortScoreInfo(struct Score sco[], int scoCount) {
    int i, j, sobj, stype;
    struct Score temp;
    //��鵱ǰ�ɼ���Ϣ�Ƿ�Ϊ��
    if (scoCount == 0) {
        printf("��ǰ�ɼ���ϢΪ��,�޷���������!\n\n");
        return;
    }
    //��ʼ��������Ķ�����
    printf("��������Ҫ����Ķ�����(1.ѧ�� 2.���� 3.�Ա� 4.��ͥסַ 5.��ϵ�绰 6.�༶ 7.���ĳɼ� 8.��ѧ�ɼ� 9.Ӣ��ɼ� 10.�ܷ�):");
    scanf("%d", &sobj);
    //��������ķ�ʽ
    printf("��������Ҫ����ķ�ʽ���(1.�������� 2.��������):");
    scanf("%d", &stype);
    //����������Ƿ���ȷ
    if (sobj < 1 || sobj>8 || stype < 1 || stype>2) {
        printf("����ɼ���Ϣʧ��,����ı�Ų�����!\n\n");
        return;
    }
    //ʹ��ð�����򷨽�������
    for (i = 0; i < scoCount - 1; i++) {
        for (j = 0; j < scoCount - i - 1; j++) {
            //�ж��Ƿ�ﵽ��������
            if ((sobj == 1 && stype == 1 && strcmp(sco[j].sno, sco[j + 1].sno) > 0) || (sobj == 1 && stype == 2 && strcmp(sco[j].sno, sco[j + 1].sno) < 0) || (sobj == 2 && stype == 1 && strcmp(sco[j].name, sco[j + 1].name) > 0) || (sobj == 2 && stype == 2 && strcmp(sco[j].name, sco[j + 1].name) < 0) || (sobj == 3 && stype == 1 && strcmp(sco[j].classes, sco[j + 1].classes) > 0) || (sobj == 3 && stype == 2 && strcmp(sco[j].classes, sco[j + 1].classes) < 0) || (sobj == 4 && stype == 1 && sco[j].chinese > sco[j + 1].chinese) || (sobj == 4 && stype == 2 && sco[j].chinese < sco[j + 1].chinese) || (sobj == 5 && stype == 1 && sco[j].math > sco[j + 1].math) || (sobj == 5 && stype == 2 && sco[j].math < sco[j + 1].math) || (sobj == 6 && stype == 1 && sco[j].english > sco[j + 1].english) || (sobj == 6 && stype == 2 && sco[j].english < sco[j + 1].english)) {
                //���������ṹ�����ֵ
                temp = sco[j];
                sco[j] = sco[j + 1];
                sco[j + 1] = temp;
            }
        }
    }
    //�������,���������
    //�������
    printf("%-12s%-12s%-12s%-12s%-12s%-12s%-12s%-12s%-12s\n", "ѧ��", "����","�Ա�","��ͥסַ","��ϵ�绰", "�༶", "���ĳɼ�", "��ѧ�ɼ�", "Ӣ��ɼ�");
    //�����ɼ���Ϣ�ṹ���������,���ÿ���ɼ���Ϣ
    for (i = 0; i < scoCount; i++) {
        printf("%-12s%-12s%-12s%-12s%-12s%-12s%-12.2f%-12.2f%-12.2f\n", sco[i].sno, sco[i].name,sco[i].gender,sco[i].add,sco[i].telephone, sco[i].classes, sco[i].chinese, sco[i].math, sco[i].english);
    }
    //����
    printf("\n");
}
//ͳ�Ƴɼ���Ϣ
void statisScoreInfo(struct Score sco[], int scoCount) {
    int i, sobj;
    float max, min, score, aver, pass;
    struct Scoreinput;
    //��鵱ǰ�ɼ���Ϣ�Ƿ�Ϊ��
    if (scoCount == 0) {
        printf("��ǰ�ɼ���ϢΪ��,�޷�����ͳ��!\n\n");
        return;
    }
    //��ʼ����ͳ�ƵĶ�����
    printf("��������Ҫͳ�ƵĿγ̱��(1.���� 2.��ѧ 3.Ӣ��):");
    scanf("%d", &sobj);
    //��������Ƿ���ȷ 
    if (sobj < 1 || sobj>4) {
        //����Ķ����Ų�����
        printf("ͳ�Ƴɼ���Ϣʧ��,����ı�Ų�����!\n\n");
        return;
    }
    //��ʼͳ��������Ϣ
    if (sobj == 1) {
        //ͬʱͳ����߷֡���ͷ֡�ƽ���֡�������
        max = min = sco[0].chinese;
        score = pass = 0;
        //��ʼ�ۼ����гɼ�
        for (i = 0; i < scoCount; i++) {
            //�ж���߷�
            if (max < sco[i].chinese) {
                max = sco[i].chinese;
            }
            //�ж���ͷ�
            if (max > sco[i].chinese) {
                min = sco[i].chinese;
            }
            //�ۼ��ܷ� 
            score += sco[i].chinese;
            //�ۼӼ�������
            if (60 <= sco[i].chinese) {
                pass++;
            }
        }
        //����ƽ����
        aver = score / scoCount;
        //���㼰���� 
        pass /= scoCount;
    }
    else if (sobj == 2) {
        //ͬʱͳ����߷֡���ͷ֡�ƽ���֡�������
        max = min = sco[0].math;
        score = pass = 0;
        //��ʼ�ۼ����гɼ�
        for (i = 0; i < scoCount; i++) {
            //�ж���߷�
            if (max < sco[i].math) {
                max = sco[i].math;
            }
            //�ж���ͷ�
            if (max > sco[i].math) {
                min = sco[i].math;
            }
            //�ۼ��ܷ� 
            score += sco[i].math;
            //�ۼӼ�������
            if (60 <= sco[i].math) {
                pass++;
            }
        }
        //����ƽ����
        aver = score / scoCount;
        //���㼰���� 
        pass /= scoCount;
    }
    else if (sobj == 3) {
        //ͬʱͳ����߷֡���ͷ֡�ƽ���֡�������
        max = min = sco[0].english;
        score = pass = 0;
        //��ʼ�ۼ����гɼ�
        for (i = 0; i < scoCount; i++) {
            //�ж���߷�
            if (max < sco[i].english) {
                max = sco[i].english;
            }
            //�ж���ͷ�
            if (max > sco[i].english) {
                min = sco[i].english;
            }
            //�ۼ��ܷ� 
            score += sco[i].english;
            //�ۼӼ�������
            if (60 <= sco[i].english) {
                pass++;
            }
        }
        //����ƽ����
        aver = score / scoCount;
        //���㼰���� 
        pass /= scoCount;
    }
 
    //ͳ�����,������
    printf("��ǰ�γ̵���߷�Ϊ: %.2f\n", max);
    printf("��ǰ�γ̵���ͷ�Ϊ: %.2f\n", min);
    printf("��ǰ�γ̵�ƽ����Ϊ: %.2f\n", aver);
    printf("��ǰ�γ̵ļ�����Ϊ: %.2f\n\n", pass);
}

//������
int main() {
    int choice;
    int running = 1;
    //�����ɼ���Ϣ�ṹ���������
    struct Score sco[MAX];
    //�����ɼ���Ϣ�ṹ������Ԫ�ظ�������
    int scoCount = 0;
    //����whileѭ��
    while (running) {
        //��ʾ���˵�
        printf("================================================\n");
        printf("=               ѧ���ɼ�����ϵͳ               =\n");
        printf("=                                              =\n");
        printf("=                1.��ӳɼ���Ϣ                =\n");
        printf("=                2.�޸ĳɼ���Ϣ                =\n");
        printf("=                3.ɾ���ɼ���Ϣ                =\n");
        printf("=                4.����ɼ���Ϣ                =\n");
        printf("=                5.��ѯ�ɼ���Ϣ                =\n");
        printf("=                6.����ɼ���Ϣ                =\n");
        printf("=                7.ͳ�Ƴɼ���Ϣ                =\n");
        printf("=                0.�˳�ϵͳ                    =\n");
        printf("=                                              =\n");
        printf("================================================\n");
        //���빦�ܱ��
        printf("����������Ҫִ�еĹ��ܱ��:");
        scanf("%d", &choice);
        //���ݹ��ܱ��ѡ���Ӧ����
        switch (choice) {
        case 0:
            //�˳�ϵͳ
            running = 0;
            break;
        case 1:
            //��ӳɼ���Ϣ
            scoCount = addScoreInfo(sco, scoCount);
            break;
        case 2:
            //�޸ĳɼ���Ϣ
            modifyScoreInfo(sco, scoCount);
            break;
        case 3:
            //ɾ���ɼ���Ϣ
            scoCount = deleteScoreInfo(sco, scoCount);
            break;
        case 4:
            //����ɼ���Ϣ
            browserScoreInfo(sco, scoCount);
            break;
        case 5:
            //��ѯ�ɼ���Ϣ
            queryScoreInfo(sco, scoCount);
            break;
        case 6:
            //����ɼ���Ϣ
            sortScoreInfo(sco, scoCount);
            break;
        case 7:
            //ͳ�Ƴɼ���Ϣ
            statisScoreInfo(sco, scoCount);
            break;
        default:
            //���빦�ܱ�Ų�����
            printf("������Ĺ��ܱ�Ų�����,����������!\n\n");
            break;
        }
        if (running) {
            //�����������
            system("pause");
            //����
            system("cls");
        }
    }
    //����ϵͳ
    printf("��л����ʹ��,�ټ�!~\n");
}
