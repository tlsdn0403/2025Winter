#include <iostream>
#include <vector>
using namespace std;

int num;
vector<vector<int>> map;
void findleaf(const vector<vector<int>> &tree, int currentNode, int &leaf) {
    if (tree[currentNode].size() <= 1) {  //자식이 없는경우
        leaf--;
        return;
    }
    else { //자식이 있다면
        for (int i = 1; i < tree[currentNode].size(); i++) {
            findleaf(tree, tree[currentNode][i], leaf);
        }
    }
    return;
}

int answer(const vector<vector<int>> &tree, int dn) {
    int leaf = 0;
    if (dn == 0) { //삭제할 노드가 루트인 경우
        return 0;
    }
    for (int i = 0; i < num; i++) { //삭제전 전체 리프노드 수
        if (tree[i].size() <= 1) { //자식이 없다
            leaf++;
        }
    }
    findleaf(tree, dn, leaf);
    int parent = tree[dn][0];
    if (tree[parent].size() == 2) { //삭제 노드의 부모가 리프노드가 될 경우
        leaf++;
    }
    return leaf;
}


int main() {
    cin >> num;
    map.resize(num);
    for (int i = 0; i < num; i++) {
        int parent;
        cin >> parent; // 부모 값 입력
        map[i].push_back(parent); // 부모 값 저장
        if (parent >= 0) {
            map[parent].push_back(i); // 부모에 자식 추가
        }
    }
    int deleteNode;
    cin >> deleteNode;
    cout << answer(map, deleteNode);
}
