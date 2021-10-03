#ifndef MYTREE_H
#define MYTREE_H
#include <iostream>
#include "../Token/Token.h"
using namespace std;

/**
 * @brief 树类
 * 可以自由访问Token类型
 */
class MyTree
{
private:
    int child_num;
    MyTree * par;
    MyTree * LeftMostChild;
    MyTree * rightSibling;

public:
    Token token;

    /**
     * @brief Construct a new My Tree object
     * 
     */
    MyTree();

    /**
     * @brief Construct a new My Tree object
     * 
     * @param token_in 将被使用来初始化新节点的Token类型
     */
    MyTree(Token token_in);

    /**
     * @brief Construct a new My Tree object
     * 
     * @param str 
     */
    MyTree(string str);

    /**
     * @brief Destroy the My Tree object
     * 
     */
    ~MyTree();

    /**
     * @brief Get the Right Most Child object
     * 
     * 返回最右的子节点
     * @return MyTree* 
     */
    MyTree * getRightMostChild();

    /**
     * @brief Get the Par object
     * 
     * 返回父节点
     * @return MyTree* 
     */
    MyTree * getPar();

    /**
     * @brief Get the Right Sibling object
     * 
     * 返回右兄弟节点
     * @return MyTree* 
     */
    MyTree * getRightSibling();

    /**
     * @brief Get the Left Most Child object
     * 
     * 返回最左的子节点
     * @return MyTree* 
     */
    MyTree * getLeftMostChild();

    /**
     * @brief Get the child num object
     * 
     * 返回子节点的数目
     * @return int 
     */
    int getchild_num();

    /**
     * @brief 使用一个Token来新建一个子节点。
     * 
     * @param token_in 传入的Token
     */
    void newChild(Token token_in);

    /**
     * @brief 使用一个树节点来新建子节点。
     * 注意，这里的子节点需要已经分配好空间
     * 
     * @param node 传入的节点指针
     */
    void newChild(MyTree * node);

    /**
     * @brief 返回表示一棵树的字符串
     * 
     * @return string 
     */
    string treeToString();



};

#endif