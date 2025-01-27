#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/    
    /* Решението, което предлагам, въвежда координатна система, в която координатното начало съвпада с корена. 
	   Координатите на останалите върхове определяме по относителното им местоположение спрямо корена.
	   Абсцисата на всеки връх е алгебричният сбор от стъпките при спускане от корена до този връх: наляво = -1, надясно = +1.
	   Ординатата на всеки връх = минус дължината на пътя от корена до този връх (броя стъпки).
	   Например за връх с път LLR ординатата = -3 (защото пътят има дължина 3), абсцисата = L+L+R = (-1) + (-1) + 1 = -1.
	   Нека си мислим за всяка права x = (xi)_x като за ниво, където (xi)_x е абсциса на връх на дървото (тоест (xi)_x обхожда множеството от абсцисите на върховете).
	   Геометрично ни интересува върху така обособените нива кои са най-високите върхове (с най-големи ординати).
	   Тази идея, реализирана на код, представлява решението ми на задачата за горен изглед на дърво (погледнато "отгоре").
	*/
    void dfs(Node* curr, int x, int y, map<int, pair<int, Node*>>& xYNode)
    {
        if(!curr) return;
        
        if(xYNode.find(x) != xYNode.end())
        {
            if(xYNode[x].first < y)
            {
                xYNode[x].first = y;
                xYNode[x].second = curr;
            }
        }
        else 
        {
            xYNode[x] = make_pair(y, curr);
        }
        
        dfs(curr->left, x - 1 , y - 1, xYNode);
        dfs(curr->right, x + 1, y - 1, xYNode);
    }
    
    void topView(Node * root) {
        map<int, pair<int, Node*>> xYNode;
        
        dfs(root, 0, 0, xYNode);
        for(const auto& kvp : xYNode)
        {
            std::cout << kvp.second.second->data << " ";
        }
    }

}; //End of Solution

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.topView(root);

    return 0;
}
