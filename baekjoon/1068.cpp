#include <iostream>
#include <vector>
using namespace std;

int num;
vector<vector<int>> map(50);
int findleaf(vector<vector<int>> tree, int fn, int leaf) {
    int lc;
    int rc;
    if (tree[fn].size() <= 1) {  //�ڽ��� ���°��
        leaf--;
        return leaf;
    }
    else { //�ڽ��� �ִٸ�
        lc = tree[fn][1];
        leaf = findleaf(tree, lc, leaf);
        if (tree[fn].size() == 3) {
            rc = tree[fn][2];
            leaf = findleaf(tree, rc, leaf);
        }
    }
    return leaf;
}

int answer(vector<vector<int>> tree, int dn) {
    int leaf = 0;
    if (dn == 0) {
        return 0;
    }
    for (int i = 0; i < num; i++) {
        if (tree[i].size() <= 1) { //�ڽ��� ����
            leaf++;
        }
    }
    leaf = findleaf(tree, dn, leaf);
    if (tree[tree[dn][0]].size() == 2) {
        leaf++;
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
    cout << answer(map, deleteNode);
}
