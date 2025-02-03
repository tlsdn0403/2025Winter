#include <iostream>
#include <vector>
using namespace std;

int num;
vector<vector<int>> tree;
vector<int> deleteParent;
bool isInVector(const vector<int>& vec, int deleteNode) {
    for (int num : vec) {
        if (num == deleteNode) {
            return true; // ���� ã��
        }
    }
    return false;
}

int answer(const vector<vector<int>> &tree, int dn) {
    int leaf = 0;
    if (dn == 0) { //������ ��尡 ��Ʈ�� ���
        return 0;
    }
    for (int i = 0; i < num; i++) { //������ ��ü ������� ��
        if (isInVector(deleteParent, tree[i][0])) { //Ʈ���� �θ� deleteParent�� ������ ��
            deleteParent.push_back(i);
        }
        else if (tree[i].size() <= 1 && !isInVector(deleteParent, i)) { //�ڽ��� ����
            leaf++;
        }
    }
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
    deleteParent.push_back(deleteNode);
    cout << answer(tree, deleteNode);
}
