#include <iostream>
#include <vector>
using namespace std;

int num;
vector<vector<int>> map(50);
int findleaf(vector<vector<int>> tree, int fn) {
    int node;
    if (tree[fn].size() <= 1) {
        return tree[tree[fn][0]].size();
    }
    else {
        node = tree[fn][1];
    }
    findleaf(tree, node);
}

int answer(vector<vector<int>> tree , int dn) {
    int leaf = 0;
    for (int i = 0; i < num; i++) {
        if (tree[i].size() <= 1) { //�ڽ��� ����
            leaf++;
        }
    }
    if (tree[dn].size() <= 1) {
        leaf--;
    }
    if (findleaf(tree, dn) == 2) {
        leaf--;
    }
    return leaf;
}


int main() {
    cin >> num;
    for (int i = 0; i < num; i++) {
        int parent;
        cin >> parent; // �θ� �� �Է�
        map[i].push_back(parent); // �θ� �� ����
        if (parent >= 0) {
            map[parent].push_back(i); // �θ� �ڽ� �߰�
        }
    }
    int deleteNode;
    cin >> deleteNode;
    cout << answer(map,deleteNode);
}
