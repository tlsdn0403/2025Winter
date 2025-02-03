#include <iostream>
#include <vector>
using namespace std;

int num;
vector<vector<int>> map(50);
int findleaf(vector<vector<int>> tree, int fn, int leaf) {
    int lc;
    int rc;
    if (tree[fn].size() <= 1) {  //자식이 없는경우
        leaf--;
        return leaf;
    }
    else { //자식이 있다면
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
        if (tree[i].size() <= 1) { //자식이 없다
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
