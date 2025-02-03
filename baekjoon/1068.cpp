#include <iostream>
#include <vector>
using namespace std;

int num;
vector<vector<int>> tree;
vector<int> parentNum;
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
    if (parentNum[dn] == -1) { //������ ��尡 ��Ʈ�� ���
        return 0;
    }
    for (int i = 0; i < num; i++) { //������ ��ü ������� ��
        for (int j = 0; j < num; j++) {
            if (isInVector(deleteParent, parentNum[j])) { //Ʈ���� �θ� deleteParent�� ������ �� 
                deleteParent.push_back(j);
            }
        }
        if (isInVector(deleteParent, parentNum[i])&& !isInVector(deleteParent , i) ) { //������� �Է��Ѵٴ� ������ �������� �� �� ��
            deleteParent.push_back(i);
        }
        else if (tree[i].empty() && !isInVector(deleteParent, i)) { //�ڽ��� ����
            leaf++;
        }
    }

    int parent = parentNum[dn];
    if (tree[parent].size() == 1) { //���� ����� �θ� ������尡 �� ���
        leaf++;
    }
   
    return leaf;
}


int main() {
    cin >> num;
    tree.resize(num);
    parentNum.resize(num);
    for (int i = 0; i < num; i++) {
        int parent;
        cin >> parent; // �θ� �� �Է�
        parentNum[i]= parent; //�θ� �� ����
        if (parent >= 0) {
            tree[parent].push_back(i); // �θ� �ڽ� �߰�
        }
    }
    int deleteNode;
    cin >> deleteNode;
    deleteParent.push_back(deleteNode);
    cout << answer(tree, deleteNode);
}
