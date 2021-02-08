#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> answer(2);
typedef struct node* nodePointer;
typedef struct node {
    int x, y;
    int data;
    nodePointer left, right;
};

bool cmp(vector<int> a, vector<int> b) {
    if (a[1] > b[1]) {
        return true;
    }
    else if (a[1] == b[1]) {
        return a[0] < b[0];
    }
    else {
        return false;
    }
}
void preorder(nodePointer pointer) { // 전위 순회
    if (pointer == NULL) {
        return;
    }
    answer[0].push_back(pointer->data);
    preorder(pointer->left);
    preorder(pointer->right);
}
void postorder(nodePointer pointer) { // 후위 순회
    if (pointer == NULL) {
        return;
    }
    postorder(pointer->left);
    postorder(pointer->right);
    answer[1].push_back(pointer->data);
}
void addNode(nodePointer parent, nodePointer children) {
    if (parent->x > children->x) {
        if (parent->left == NULL) {
            parent->left = children;
        }
        else {
            addNode(parent->left, children);
        }
    }
    else {
        if (parent->right == NULL) {
            parent->right = children;
        }
        else {
            addNode(parent->right, children);
        }
    }
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> cpy;

    for (int i = 1; i <= nodeinfo.size(); i++) {
        nodeinfo[i - 1].push_back(i); // 각 vertex 마다 번호 붙이기
    }
    cpy = nodeinfo;
    sort(cpy.begin(), cpy.end(), cmp);
    vector<node> nodes(cpy.size());
    // 초기화
    for (int i = 0; i < cpy.size(); i++) { 
        nodes[i].x = cpy[i][0];
        nodes[i].y = cpy[i][1];
        nodes[i].data = cpy[i][2];
        nodes[i].left = NULL;
        nodes[i].right = NULL;
    }
    // 노드 만들기
    nodePointer parent;
    parent = &nodes[0];
    for (int i = 1; i < nodes.size(); i++) {
        addNode(parent, &nodes[i]);
    }
    preorder(parent);
    postorder(parent);

    return answer;
}
int main()
{
    vector<vector<int>> result;
    result = solution({ {5,3}, {11,5}, {13,3}, {3,5}, {6,1}, {1,3}, {8,6}, {7,2}, {2,2} });
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}