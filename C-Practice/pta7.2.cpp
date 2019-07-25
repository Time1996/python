/*
        先给出项数，随后以指数递降的方式给出系数和指数
        一共两行，
        输出两个多项式的和与乘积，
        由于给出了项数，可以使用动态数组来存储
 */

#include <stdio.h>
#include <stdlib.h>

//定义部分
typedef struct _poly* pNode;

struct _poly {
        int coef;
        int expo;
        pNode next;
};

typedef pNode Poly;

Poly readPoly();
void attach(int c, int e, Poly *pRear);
int printPoly(Poly p);
void destroyPoly(Poly p);
Poly addPoly(Poly p1, Poly p2);
Poly MuttPoly(Poly p1, Poly p2);
//实现部分
/*
    打印每项系数和指数
    返回值是成功打印的项数
    若其为0，则为空表达式
 */
int printPoly(Poly p) {
    int cnt = 0;
    while(p){
        printf("%d %d", p->coef, p->expo);
        cnt++;
        if(p->next != NULL) {
                printf(" ");
        }else{
            printf("\n");
        }
        p = p->next;;
    }
    return cnt;
}

/*
        将项连接到链表末尾的函数
        指向pRear的指针1 pRear  last node
        [&(pRear)]  ->  [&(last node)] -> []

        指向pRear的指针2
        [&(pRear)]
        通过pRear来改变last node
        通过指向pRear的指针来改变pRear
        传递pRear的地址来实现
 */

void attach(int c, int e, Poly *pRear){
    if (c == 0)//若系数为0,不添加
        return;
    Poly p = (Poly)malloc(sizeof(struct _poly));
    p->coef = c;
    p->expo = e;
    p->next = NULL;
    (*pRear)->next = p;
    *pRear = p;
}

Poly readPoly(){
    //表头使用一个临时的空节点
    Poly p1 = (Poly)malloc(sizeof(struct _poly));
    p1->coef = 0;
    p1->expo = 0;
    p1->next = NULL;
    // a pointer to Currnet node
    Poly pRear = p1;

    int n = 0;
    scanf("%d", &n);
    while(n--){
        //读入节点
        int c = 0, e = 0;
        scanf("%d %d",&c, &e);
        //要想改变pRear值，则传入pRear的地址
        attach(c, e, &pRear);
    }
    //删除头节点
    Poly t = p1;
    p1 = p1->next;
    free(t);
    t = NULL;
    return p1;
}

void destroyPoly(Poly p){
        Poly tmp;
        while(p){
                tmp = p->next;
                free(p);
                p = tmp;
        }
}

Poly addPoly(Poly p1, Poly p2){
    //一个临时空节点
    Poly sumPoly = (Poly)malloc(sizeof(struct _poly));
    sumPoly->coef = 0;
    sumPoly->expo = 0;
    sumPoly->next = NULL;
    Poly pt1 = p1, pt2 = p2, pts = sumPoly; //指向当前节点的指针
    while (pt1 && pt2){
        if (pt1->expo > pt2->expo){
            attach(pt1->coef, pt1->expo, &pts);
            pt1 = pt1->next;
        }else if (pt2->expo > pt1->expo){
            attach(pt2->coef, pt2->expo, &pts);
            pt2 = pt2->next;
        }else{
            //两项的指数相同，将系数相加
            int sumCoef = pt1->coef + pt2->coef;
            //不为0,则加入节点链表
            if(sumCoef){
                attach(sumCoef, pt1->expo, &pts);
            }
            //pt1, pt2前进
            pt1 = pt1->next;
            pt2 = pt2->next;
        }
    }
    //将较长的一个多项式追加到末尾
    while (pt1){
        attach(pt1->coef, pt1->expo, &pts);
        pt1 = pt1->next;
    }
    while(pt2){
        attach(pt2->coef, pt2->expo, &pts);
        pt2 = pt2->next;
    }

    //删除头部的空节点
    Poly t = sumPoly;
    sumPoly = sumPoly->next;
    free(t);
    t = NULL;
    return sumPoly;
}

Poly MuttPoly(Poly p1, Poly p2){
        if(!p1 || !p2)
            return NULL;
        Poly prdPoly = (Poly)malloc(sizeof(struct _poly));
        prdPoly->coef = 0;
        prdPoly->expo = 0;
        prdPoly->next = NULL;
        Poly pt1 = p1, pt2 = p2, ptp = prdPoly;
        //先用pt1的第一项乘pt2的所有项
        while(pt2){
                attach(pt1->coef * pt2->coef, pt1->expo + pt2->expo, &ptp);
                pt2 = pt2->next;
        }
        //将随后的项目插入到得到的多项式中
        pt1 = pt1->next;
        while(pt1){
                pt2 = p2; ptp = prdPoly;
                while(pt2){
                    int e = pt1->expo + pt2->expo;
                    int c = pt1->coef * pt2->coef;
                    //查找插入的位置
                    while(ptp->next && ptp->next->expo > e){
                        ptp = ptp->next;
                    }
                    if(ptp->next && ptp->next->expo == e){
                        //直接加上c
                        ptp->next->coef += c;
                        if(!ptp->next->coef){
                            // =0 删除该节点
                            Poly tmp = ptp->next;
                            ptp->next = tmp->next;
                            free(tmp);
                            tmp = NULL;
                        }
                    }else{
                        //ptp->next < e 插入一个新节点
                        Poly tmp = (Poly)malloc(sizeof(struct _poly));
                        tmp->coef = c;
                        tmp->expo = e;
                        tmp->next = ptp->next;
                        ptp->next = tmp;
                        //由于按照指数递减,pt1乘以下一项的指数比当前结果小,故ptp指向该项,下次从这里开始搜索
                        ptp = tmp;// or ptp = ptp->next;
                    }
                    pt2 = pt2->next;
                }
                pt1 = pt1->next;
        }
        //删除头部的空节点
        Poly t = prdPoly;
        prdPoly = prdPoly->next;
        free(t);
        t = NULL;
        return prdPoly;
}

int main(void){
    Poly p1 = readPoly();
    Poly p2 = readPoly();
    Poly pSum = addPoly(p1, p2);
    Poly pPrd = MuttPoly(p1, p2);
    int c1 = printPoly(pPrd);
    if(!c1){
        printf("0 0");
    }
    destroyPoly(p1);
    destroyPoly(p2);
    destroyPoly(pSum);
    return 0;
}
