#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100 //声明常量表示成绩信息结构体数组长度
#define STR 50  //声明常量表示字符数组长度

//声明成绩信息结构体
struct Score {
    char sno[STR];        //学    号
    char name[STR];       //姓    名
    char gender[STR];     //性    别
    char add[STR];        //家庭住址
    char telephone[STR];  //联系电话
    char classes[STR];    //班    级
    float chinese;        //语文成绩
    float math;           //数学成绩
    float english;        //英语成绩
};

//添加成绩信息
int addScoreInfo(struct Score sco[], int scoCount) {
    int i;
    struct Score input;
    //检查当前成绩信息是否已满
    if (scoCount == MAX) {
        printf("当前成绩信息已满,无法继续添加!\n\n");
        return scoCount;
    }
    //开始输入学号
    printf("请输入学号:");
    scanf("%s", input.sno);
    //检查输入的学号是否已存在
    for (i = 0; i < scoCount; i++) {
        if (strcmp(sco[i].sno, input.sno) == 0) {
            break;
        }
    }
    if (i == scoCount) {
        //输入的学号不存在
        //输入其他信息
        printf("请输入姓名:");
        scanf("%s", input.name);
        printf("请输入性别:");
        scanf("%s", input.gender);
        printf("家庭住址:");
        scanf("%s", input.add);
        printf("联系电话:");
        scanf("%s", input.telephone);
        printf("请输入班级:");
        scanf("%s", input.classes);
        printf("请输入语文成绩:");
        scanf("%f", &input.chinese);
        printf("请输入数学成绩:");
        scanf("%f", &input.math);
        printf("请输入英语成绩:");
        scanf("%f", &input.english);
        //保存成绩信息到数组中
        sco[scoCount] = input;
        scoCount++;
        //保存成绩信息成功
        printf("添加成绩信息成功!\n\n");
    }
    else {
        //输入的学号已存在
        printf("添加成绩信息失败,输入的学号已存在!\n\n");
    }
    return scoCount;
}
//修改成绩信息
void modifyScoreInfo(struct Score sco[], int scoCount) {
    int i;
    struct Score input;
    //检查当前成绩信息是否为空
    if (scoCount == 0) {
        printf("当前成绩信息为空,无法继续修改!\n\n");
        return;
    }
    //开始输入学号
    printf("请输入需要修改的学号:");
    scanf("%s", input.sno);
    //检查输入的学号是否存在
    for (i = 0; i < scoCount; i++) {
        if (strcmp(sco[i].sno, input.sno) == 0) {
            break;
        }
    }
    if (i != scoCount) {
        //输入的学号存在
        //输入其他信息
        printf("请输入姓名:");
        scanf("%s", input.name);
        printf("请输入性别:");
        scanf("%s", input.gender);
        printf("家庭住址:");
        scanf("%s", input.add);
        printf("联系电话:");
        scanf("%s", input.telephone);
        printf("请输入班级:");
        scanf("%s", input.classes);
        printf("请输入语文成绩:");
        scanf("%f", &input.chinese);
        printf("请输入数学成绩:");
        scanf("%f", &input.math);
        printf("请输入英语成绩:");
        scanf("%f", &input.english);
        //修改到数组中
        sco[i] = input;
        //修改成绩信息成功
        printf("修改成绩信息成功!\n\n");
    }
    else {
        //输入的学号不存在
        printf("修改成绩信息失败,输入的学号不存在!\n\n");
    }
}
//删除成绩信息
int deleteScoreInfo(struct Score sco[], int scoCount) {
    int i;
    struct Score input;
    //检查当前成绩信息是否为空
    if (scoCount == 0) {
        printf("当前成绩信息为空,无法继续删除!\n\n");
        return scoCount;
    }
    //开始输入学号
    printf("请输入需要删除的学号:");
    scanf("%s", input.sno);
    //检查输入的学号是否存在
    for (i = 0; i < scoCount; i++) {
        if (strcmp(sco[i].sno, input.sno) == 0) {
            break;
        }
    }
    if (i != scoCount) {
        //输入的学号存在
        //覆盖删除信息
        for (; i < scoCount - 1; i++) {
            sco[i] = sco[i + 1];
        }
        scoCount--;
        //删除成绩信息成功
        printf("删除成绩信息成功!\n\n");
    }
    else {
        //输入的学号不存在
        printf("删除成绩信息失败,输入的学号不存在!\n\n");
    }
    return scoCount;
}
//浏览成绩信息
void browserScoreInfo(struct Score sco[], int scoCount) {
    int i;
    //检查当前成绩信息是否为空
    if (scoCount == 0) {
        printf("当前成绩信息为空,无法继续浏览!\n\n");
        return;
    }
    //输出标题
    printf("%-12s%-12s%-12s%-12s%-12s%-12s%-12s%-12s%-12s\n", "学号", "姓名","性别","家庭住址","联系电话", "班级", "语文成绩", "数学成绩", "英语成绩");
    //遍历成绩信息结构体对象数组,输出每个成绩信息
    for (i = 0; i < scoCount; i++) {
        printf("%-12s%-12s%-12s%-12s%-12s%-12s%-12.2f%-12.2f%-12.2f\n", sco[i].sno, sco[i].name,sco[i].gender,sco[i].add,sco[i].telephone,sco[i].classes, sco[i].chinese, sco[i].math, sco[i].english);
    }
    //空行
    printf("\n");
}
//查询成绩信息
void queryScoreInfo(struct Score sco[], int scoCount) {
    int i, qobj, flag = 0;
    struct Score input;
    //检查当前成绩信息是否为空
    if (scoCount == 0) {
        printf("当前成绩信息为空,无法继续查询!\n\n");
        return;
    }
    //开始输入查询的对象编号
    printf("请输入需要查询的对象编号(1.学号 2.姓名 3.性别 4.家庭住址 5.联系电话 6.班级 7.语文成绩 8.数学成绩 9.英语成绩):");
    scanf("%d", &qobj);
    //输入查询的内容
    if (qobj == 1) {
        //输入学号
        printf("请输入查询的学号:");
        scanf("%s", input.sno);
    }
    else if (qobj == 2) {
        //输入姓名
        printf("请输入查询的姓名:");
        scanf("%s", input.name);
    }
    else if (qobj == 3) {
        //输入性别
        printf("请输入性别:");
        scanf("%s", input.gender);
    }
    else if (qobj == 4) {
        //输入家庭住址
        printf("请输入家庭住址:");
        scanf("%s", input.add);
    }
    else if (qobj == 5) {
        //输入联系电话
        printf("请输入联系电话");
        scanf("%s", input.telephone);
    }
    else if (qobj == 6) {
        //输入班级
        printf("请输入查询的班级:");
        scanf("%s", input.classes);
    }
    else if (qobj == 7) {
        //输入语文成绩
        printf("请输入查询的语文成绩:");
        scanf("%f", &input.chinese);
    }
    else if (qobj == 8) {
        //输入数学成绩
        printf("请输入查询的数学成绩:");
        scanf("%f", &input.math);
    }
    else if (qobj == 9) {
        //输入英语成绩
        printf("请输入查询的英语成绩:");
        scanf("%f", &input.english);
    }
    else {
        //输入的对象编号不存在
        printf("查询成绩信息失败,输入的对象编号不存在!\n\n");
        return;
    }
    //遍历成绩信息结构体对象数组,查询并输出结果
    for (i = 0; i < scoCount; i++) {
        if ((qobj == 1 && strcmp(sco[i].sno, input.sno) == 0) || (qobj == 2 && strcmp(sco[i].name, input.name) == 0) || (qobj == 3 && strcmp(sco[i].classes, input.classes) == 0) || (qobj == 4 && sco[i].chinese == input.chinese) || (qobj == 5 && sco[i].math == input.math) || (qobj == 6 && sco[i].english == input.english)) {
            //判断是否需要输出标题
            if (flag == 0) {
                //输出标题
                printf("%-12s%-12s%-12s%-12s%-12s%-12s%-12s%-12s%-12s\n", "学号", "姓名","性别","家庭住址","联系电话", "班级", "语文成绩", "数学成绩", "英语成绩");
                flag = 1;
            }
            //输出详细成绩信息
            printf("%-12s%-12s%-12s%-12s%-12s%-12s%-12.2f%-12.2f%-12.2f\n", sco[i].sno, sco[i].name,sco[i].gender,sco[i].add,sco[i].telephone, sco[i].classes, sco[i].chinese, sco[i].math, sco[i].english);
        }
    }
    //判断是否有查询结果
    if (flag == 0) {
        //没有查询结果
        printf("查询无结果!\n");
    }
    //空行
    printf("\n");
}
//排序成绩信息
void sortScoreInfo(struct Score sco[], int scoCount) {
    int i, j, sobj, stype;
    struct Score temp;
    //检查当前成绩信息是否为空
    if (scoCount == 0) {
        printf("当前成绩信息为空,无法继续排序!\n\n");
        return;
    }
    //开始输入排序的对象编号
    printf("请输入需要排序的对象编号(1.学号 2.姓名 3.性别 4.家庭住址 5.联系电话 6.班级 7.语文成绩 8.数学成绩 9.英语成绩 10.总分):");
    scanf("%d", &sobj);
    //输入排序的方式
    printf("请输入需要排序的方式编号(1.升序排序 2.降序排序):");
    scanf("%d", &stype);
    //检查编号输入是否正确
    if (sobj < 1 || sobj>8 || stype < 1 || stype>2) {
        printf("排序成绩信息失败,输入的编号不存在!\n\n");
        return;
    }
    //使用冒泡排序法进行排序
    for (i = 0; i < scoCount - 1; i++) {
        for (j = 0; j < scoCount - i - 1; j++) {
            //判断是否达到交换条件
            if ((sobj == 1 && stype == 1 && strcmp(sco[j].sno, sco[j + 1].sno) > 0) || (sobj == 1 && stype == 2 && strcmp(sco[j].sno, sco[j + 1].sno) < 0) || (sobj == 2 && stype == 1 && strcmp(sco[j].name, sco[j + 1].name) > 0) || (sobj == 2 && stype == 2 && strcmp(sco[j].name, sco[j + 1].name) < 0) || (sobj == 3 && stype == 1 && strcmp(sco[j].classes, sco[j + 1].classes) > 0) || (sobj == 3 && stype == 2 && strcmp(sco[j].classes, sco[j + 1].classes) < 0) || (sobj == 4 && stype == 1 && sco[j].chinese > sco[j + 1].chinese) || (sobj == 4 && stype == 2 && sco[j].chinese < sco[j + 1].chinese) || (sobj == 5 && stype == 1 && sco[j].math > sco[j + 1].math) || (sobj == 5 && stype == 2 && sco[j].math < sco[j + 1].math) || (sobj == 6 && stype == 1 && sco[j].english > sco[j + 1].english) || (sobj == 6 && stype == 2 && sco[j].english < sco[j + 1].english)) {
                //交换两个结构体变量值
                temp = sco[j];
                sco[j] = sco[j + 1];
                sco[j + 1] = temp;
            }
        }
    }
    //排序完成,输出排序结果
    //输出标题
    printf("%-12s%-12s%-12s%-12s%-12s%-12s%-12s%-12s%-12s\n", "学号", "姓名","性别","家庭住址","联系电话", "班级", "语文成绩", "数学成绩", "英语成绩");
    //遍历成绩信息结构体对象数组,输出每个成绩信息
    for (i = 0; i < scoCount; i++) {
        printf("%-12s%-12s%-12s%-12s%-12s%-12s%-12.2f%-12.2f%-12.2f\n", sco[i].sno, sco[i].name,sco[i].gender,sco[i].add,sco[i].telephone, sco[i].classes, sco[i].chinese, sco[i].math, sco[i].english);
    }
    //空行
    printf("\n");
}
//统计成绩信息
void statisScoreInfo(struct Score sco[], int scoCount) {
    int i, sobj;
    float max, min, score, aver, pass;
    struct Scoreinput;
    //检查当前成绩信息是否为空
    if (scoCount == 0) {
        printf("当前成绩信息为空,无法继续统计!\n\n");
        return;
    }
    //开始输入统计的对象编号
    printf("请输入需要统计的课程编号(1.语文 2.数学 3.英语):");
    scanf("%d", &sobj);
    //检查输入是否正确 
    if (sobj < 1 || sobj>4) {
        //输入的对象编号不存在
        printf("统计成绩信息失败,输入的编号不存在!\n\n");
        return;
    }
    //开始统计语文信息
    if (sobj == 1) {
        //同时统计最高分、最低分、平均分、及格率
        max = min = sco[0].chinese;
        score = pass = 0;
        //开始累加所有成绩
        for (i = 0; i < scoCount; i++) {
            //判断最高分
            if (max < sco[i].chinese) {
                max = sco[i].chinese;
            }
            //判断最低分
            if (max > sco[i].chinese) {
                min = sco[i].chinese;
            }
            //累加总分 
            score += sco[i].chinese;
            //累加及格人数
            if (60 <= sco[i].chinese) {
                pass++;
            }
        }
        //计算平均分
        aver = score / scoCount;
        //计算及格率 
        pass /= scoCount;
    }
    else if (sobj == 2) {
        //同时统计最高分、最低分、平均分、及格率
        max = min = sco[0].math;
        score = pass = 0;
        //开始累加所有成绩
        for (i = 0; i < scoCount; i++) {
            //判断最高分
            if (max < sco[i].math) {
                max = sco[i].math;
            }
            //判断最低分
            if (max > sco[i].math) {
                min = sco[i].math;
            }
            //累加总分 
            score += sco[i].math;
            //累加及格人数
            if (60 <= sco[i].math) {
                pass++;
            }
        }
        //计算平均分
        aver = score / scoCount;
        //计算及格率 
        pass /= scoCount;
    }
    else if (sobj == 3) {
        //同时统计最高分、最低分、平均分、及格率
        max = min = sco[0].english;
        score = pass = 0;
        //开始累加所有成绩
        for (i = 0; i < scoCount; i++) {
            //判断最高分
            if (max < sco[i].english) {
                max = sco[i].english;
            }
            //判断最低分
            if (max > sco[i].english) {
                min = sco[i].english;
            }
            //累加总分 
            score += sco[i].english;
            //累加及格人数
            if (60 <= sco[i].english) {
                pass++;
            }
        }
        //计算平均分
        aver = score / scoCount;
        //计算及格率 
        pass /= scoCount;
    }
 
    //统计完成,输出结果
    printf("当前课程的最高分为: %.2f\n", max);
    printf("当前课程的最低分为: %.2f\n", min);
    printf("当前课程的平均分为: %.2f\n", aver);
    printf("当前课程的及格率为: %.2f\n\n", pass);
}

//主函数
int main() {
    int choice;
    int running = 1;
    //声明成绩信息结构体数组变量
    struct Score sco[MAX];
    //声明成绩信息结构体数组元素个数变量
    int scoCount = 0;
    //进入while循环
    while (running) {
        //显示主菜单
        printf("================================================\n");
        printf("=               学生成绩排名系统               =\n");
        printf("=                                              =\n");
        printf("=                1.添加成绩信息                =\n");
        printf("=                2.修改成绩信息                =\n");
        printf("=                3.删除成绩信息                =\n");
        printf("=                4.浏览成绩信息                =\n");
        printf("=                5.查询成绩信息                =\n");
        printf("=                6.排序成绩信息                =\n");
        printf("=                7.统计成绩信息                =\n");
        printf("=                0.退出系统                    =\n");
        printf("=                                              =\n");
        printf("================================================\n");
        //输入功能编号
        printf("请输入您需要执行的功能编号:");
        scanf("%d", &choice);
        //根据功能编号选择对应功能
        switch (choice) {
        case 0:
            //退出系统
            running = 0;
            break;
        case 1:
            //添加成绩信息
            scoCount = addScoreInfo(sco, scoCount);
            break;
        case 2:
            //修改成绩信息
            modifyScoreInfo(sco, scoCount);
            break;
        case 3:
            //删除成绩信息
            scoCount = deleteScoreInfo(sco, scoCount);
            break;
        case 4:
            //浏览成绩信息
            browserScoreInfo(sco, scoCount);
            break;
        case 5:
            //查询成绩信息
            queryScoreInfo(sco, scoCount);
            break;
        case 6:
            //排序成绩信息
            sortScoreInfo(sco, scoCount);
            break;
        case 7:
            //统计成绩信息
            statisScoreInfo(sco, scoCount);
            break;
        default:
            //输入功能编号不存在
            printf("您输入的功能编号不存在,请重新输入!\n\n");
            break;
        }
        if (running) {
            //按任意键继续
            system("pause");
            //清屏
            system("cls");
        }
    }
    //结束系统
    printf("感谢您的使用,再见!~\n");
}
