#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data, index;
    struct Node* Parent, * Left, * Right;
}Node;
int GetHeight(Node* node)
{
    if (node == NULL) return 0;

    int leftDepth = GetHeight(node->Left);
    int rightDepth = GetHeight(node->Right);

    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}
int CalculateBalanceFactor(Node* node)
{
    return GetHeight(node->Left) - GetHeight(node->Right);
}
Node* RR(Node* node)
{
    Node* childNode = node->Right;
    node->Right = childNode->Left;
    if (childNode->Left != NULL)
        childNode->Left->Parent = node;

    childNode->Left = node;
    childNode->Parent = node->Parent;
    node->Parent = childNode;

    return childNode;
}
Node* LL(Node* node)
{
    Node* childNode = node->Left;
    node->Left = childNode->Right;
    if (childNode->Right != NULL)
        childNode->Right->Parent = node;

    childNode->Right = node;
    childNode->Parent = node->Parent;
    node->Parent = childNode;

    return childNode;
}
Node* LR(Node* node)
{
    node->Left = RR(node->Left);
    return LL(node);
}
Node* RL(Node* node)
{
    node->Right = LL(node->Right);
    return RR(node);
}
Node* AVLSet(Node* node)
{
    int depth = CalculateBalanceFactor(node);
    if (depth >= 2)
    {
        depth = CalculateBalanceFactor(node->Left);
        if (depth >= 1)
        {
            //LL : Left Left
            node = LL(node);
        }
        else
        {
            //LR : Left Right
            node = LR(node);
        }
    }
    else if (depth <= -2)
    {
        depth = CalculateBalanceFactor(node->Right);
        if (depth <= -1)
        {
            //RR : Right Right
            node = RR(node);
        }
        else
        {
            //RL : Right Left
            node = RL(node);
        }

    }

    return node;
}
Node* Insert(Node* node, int data)
{
    if (node == NULL)
    {
        node = (Node*)malloc(sizeof(Node));
        node->Left = NULL;
        node->Right = NULL;
        node->Parent = NULL;
        node->data = data;

        return node;
    }
    else if (data < node->data)
    {
        node->Left = Insert(node->Left, data);
        node->Left->Parent = node;
        node = AVLSet(node);
    }
    else if (data > node->data)
    {
        node->Right = Insert(node->Right, data);
        node->Right->Parent = node;
        node = AVLSet(node);
    }
    else
    {
        //데이터가 중복되므로 추가하지 않는다.
    }

    return node;
}
Node* GetMinNode(Node* node, Node* parent)
{
    if (node->Left == NULL)
    {
        if (node->Parent != NULL)
        {
            if (parent != node->Parent)
            {
                node->Parent->Left = node->Right;
            }
            else
            {
                node->Parent->Right = node->Right;
            }

            if (node->Right != NULL)
            {
                node->Right->Parent = node->Parent;
            }
        }

        return node;
    }
    else
    {
        return GetMinNode(node->Left, parent);
    }
}
Node* Delete(Node* node, int data)
{
    if (node == NULL) return NULL;

    if (data < node->data)
    {
        node->Left = Delete(node->Left, data);
        node = AVLSet(node);
    }
    else if (data > node->data)
    {
        node->Right = Delete(node->Right, data);
        node = AVLSet(node);
    }
    else
    {
        if (node->Left == NULL && node->Right == NULL)
        {
            node = NULL;
        }
        else if (node->Left != NULL && node->Right == NULL)
        {
            node->Left->Parent = node->Parent;
            node = node->Left;
        }
        else if (node->Left == NULL && node->Right != NULL)
        {
            node->Right->Parent = node->Parent;
            node = node->Right;
        }
        else
        {
            Node* deleteNode = node;
            Node* minNode = GetMinNode(node->Right, deleteNode);

            minNode->Parent = node->Parent;

            minNode->Left = deleteNode->Left;
            if (deleteNode->Left != NULL)
            {
                deleteNode->Left->Parent = minNode;
            }

            minNode->Right = deleteNode->Right;
            if (deleteNode->Right != NULL)
            {
                deleteNode->Right->Parent = minNode;
            }

            node = minNode;
            free(deleteNode);
        }
    }

    return node;
}
Node* nodelist[20];
int np = 0;
void Inorder(Node* node)
{
    if (node == NULL) return;

    Inorder(node->Left);
    nodelist[np++] = node;
    Inorder(node->Right);
}
int main()
{
    Node* root = NULL;

    root = Insert(root, 12);
    root = Insert(root, 11);
    root = Insert(root, 10);
    root = Insert(root, 5);
    root = Insert(root, 3);
    root = Insert(root, 7);
    root = Insert(root, 6);
    root = Insert(root, 1);
    root = Insert(root, 13);
    root = Insert(root, 2);
    root = Insert(root, 4);


    Inorder(root);

    for (int i = 0; i < np; ++i)
        printf("%d : %d,%d\n", nodelist[i]->data, nodelist[i]->Left != NULL ? nodelist[i]->Left->data : 0, nodelist[i]->Right != NULL ? nodelist[i]->Right->data : 0);

    /*
    
    1. 7을 탐색하려면 3번만 해도 된다.
    2. 루트값은 5다.
    3. 맞겟지머
    4. 맞다.

    1번이 답.
    
    */

    return 0;
}