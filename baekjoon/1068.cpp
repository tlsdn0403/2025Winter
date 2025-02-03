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
            return true; // 수를 찾음
        }
    }
    return false;
}

int answer(const vector<vector<int>> &tree, int dn) {
    int leaf = 0;
    if (parentNum[dn] == -1) { //삭제할 노드가 루트인 경우
        return 0;
    }
    for (int i = 0; i < num; i++) { //삭제전 전체 리프노드 수
        for (int j = 0; j < num; j++) {
            if (isInVector(deleteParent, parentNum[j])) { //트리의 부모가 deleteParent에 있으면 참 
                deleteParent.push_back(j);
            }
        }
        if (isInVector(deleteParent, parentNum[i])&& !isInVector(deleteParent , i) ) { //순서대로 입력한다는 보장이 없음으로 한 번 더
            deleteParent.push_back(i);
        }
        else if (tree[i].empty() && !isInVector(deleteParent, i)) { //자식이 없다
            leaf++;
        }
    }

    int parent = parentNum[dn];
    if (tree[parent].size() == 1) { //삭제 노드의 부모가 리프노드가 될 경우
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
        cin >> parent; // 부모 값 입력
        parentNum[i]= parent; //부모 값 저장
        if (parent >= 0) {
            tree[parent].push_back(i); // 부모에 자식 추가
        }
    }
    int deleteNode;
    cin >> deleteNode;
    deleteParent.push_back(deleteNode);
    cout << answer(tree, deleteNode);
}
