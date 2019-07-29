//转录于https://www.cnblogs.com/slowman/p/9892689.html
#include <iostream>
#define CAN_NOT -5
#define REPEAT -4
#define SHOULD_NOT_BE_THERE -3
enum status {
    NON, ME, BYLEET, BYRIGHT
};//枚举表示增高原因, 未增高, 自己, 左, 右


typedef struct NODE{
    int n;
    int bl;
    NODE* l;
    NODE* r;
}NODE; //右树高减左树高（为了得到最大深度差 < 2）

NODE* AVL = NULL;

void RR(NODE* &root);
void RL(NODE* &root);
void LL(NODE* &root);
void LR(NODE* &root);

status Insert(NODE* &root, int a){
    status ret;
    if (root == NULL) {
        root = new NODE;
        root->l = NULL;
        root->r = NULL;
        root->n = a;
        return ME;
    } //我自己导致我的树增高,返回ME
    else if (a > root->n){
        ret = Insert(root->r, a);

        if (ret == NON)
            return NON;
        else
        {
            //右树增高,待处理
            ++root->bl;
            if (root->bl <= 0)
                return NON;
            else if (root->bl < 2){
                return BYRIGHT;
            }
            else {
                //自己失衡,原因RR或RL
                if (ret == BYRIGHT){
                    RR (root);
                    return NON;
                }else if (ret == BYLEET){
                    RL (root);  //RL旋转
                    return NON;
                }
                else{
                    exit(CAN_NOT);//ME导致失衡,不可能
                }
            }
        }
    }
    else if (a == root->n){
        exit(REPEAT); //不允许相等
    }
    else {
        ret = Insert(root->l, a);
        if (ret == NON){
            return NON;
        }
        else {
            --root->bl;
            if (root->bl >= 0){
                return NON; // 依然OK
            }else if (root->bl > -2){
                return BYLEET;
            }else{
                if (ret == BYLEET){
                    //LL旋转
                    LL(root);
                    return NON;
                }else if (ret == BYRIGHT){
                    LR (root);
                    return NON;
                }else {
                    exit(CAN_NOT);//ME失衡,不可能
                }
            }
        }
    }
    exit (SHOULD_NOT_BE_THERE);//不应该走到这个位置(if else嵌套的也太多了一点了吧:x)
}

int main() {
    int n;
    int tmp;

    NODE* AVL = NULL;

    std::cin >> n;
    for (int i = 0; i < n; ++i){
        std::cin >> tmp;
        Insert(AVL, tmp);
    }

    std::cout<< AVL->n;

    return 0;
}

void RR(NODE* &root) {
    //RR旋转
    NODE* tmp = root; //root变更为右树
    root = tmp->r;
    tmp->r = root->l;
    root->l = tmp;

    //调整平衡因子
    tmp->bl -= 2; //推算可得
    root->bl = 0; //因2破坏,设左树高n,右树高n+2, RR破坏,右右树高n-1,右树未破坏且右右高，右左高n+1
    return;
}

void LL(NODE* &root) {//可以用纸笔演算一下过程
    NODE* tmp = root;
    root = tmp->l;
    tmp->l = root->r;
    root->r = tmp;

    tmp->bl += 2;
    root->bl = 0;

    return;
}

void RL(NODE* &root) {
    NODE* tmp = root;
    root = tmp->r->l;

    tmp->r->l = root->r;
    root->r = tmp->r;
    tmp->r = root->l;
    root->l = tmp; //RL旋转复杂一些

    if (root->bl == -1) {
        //重新设置平衡因子,比较繁琐,推论可知
        root->r->bl = 1;
        root->bl = 0;
        root->l->bl = 0;
    }else if (root->bl == 1) {
        root->r->bl = 0;
        root->bl = 0;
        root->l->bl = -1;
    }else{
        root->l->bl = 0;
        root->r->bl = 0;
    }

    return;
}

void LR (NODE* &root) {
    NODE* tmp = root;
    root = tmp->l->r;

    tmp->l->r = root->l;
    root->l = tmp->l;
    tmp->l = root->r;
    root->r = tmp; 
    if (root->bl == -1){
        root->r->bl = 1;
        root->bl = 0;
        root->l->bl = 0;
    }else if (root->bl == 1) {
        root->r->bl = 0;
        root->bl = 0;
        root->l->bl = -1;
    }else {
        //LR旋转导致失衡,且root->bl为0,说明LR是新产生的节点
        root->l->bl = 0;
        root->r->bl = 0;
    }
    return;
}



