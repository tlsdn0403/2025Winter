#include <iostream>
#include <vector>
using namespace std;

int num;
int leaf;
vector<vector<int>> tree;

void findleaf(const vector<vector<int>>& tree, int currentNode) {
    if (tree[currentNode].size() <= 1) {  //�ڽ��� ���°��
        leaf--;
        return;
    }
    else { //�ڽ��� �ִٸ�
        for (int i = 1; i < tree[currentNode].size(); i++) {
            findleaf(tree, tree[currentNode][i]);
        }
    }
    return;
}

int answer(const vector<vector<int>>& tree, int dn) {
    int leaf = 0;
    if (dn == 0) { //������ ��尡 ��Ʈ�� ���
        return 0;
    }
    for (int i = 0; i < num; i++) { //������ ��ü ������� ��
        if (tree[i].size() <= 1) { //�ڽ��� ����
            leaf++;
        }
    }
    findleaf(tree, dn);
    int parent = tree[dn][0];
    if (tree[parent].size() == 2) { //���� ����� �θ� ������尡 �� ���
        leaf++;
    }
    return leaf;
}


int main() {
    cin >> num;
    tree.resize(num);
    for (int i = 0; i < num; i++) {
        int parent;
        cin >> parent; // �θ� �� �Է�
        tree[i].push_back(parent); // �θ� �� ����
        if (parent >= 0) {
            tree[parent].push_back(i); // �θ� �ڽ� �߰�
        }
    }
    int deleteNode;
    cin >> deleteNode;
    cout << answer(tree, deleteNode);
}
�̷��� ®���� �ڲ� �޸� �ʰ��� ��