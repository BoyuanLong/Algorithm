#include<iostream>
#include<vector>

using namespace std;

const int N = 100005;

struct node
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key)
{
    if (node == NULL) return newNode(key);
    
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

void DLR(struct node* node, vector<int> &ans){
    if(node != NULL)
    {
        ans.push_back(node->key);
        DLR(node->left, ans);
        DLR(node->right, ans);
    }
}

void LRD(node* node, vector<int> &ans){
    if(node != NULL){
        LRD(node->left, ans);
        LRD(node->right, ans);
        ans.push_back(node->key);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> sequence;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        sequence.push_back(tmp);
    }
    node* start = insert(start, sequence[0]);
    for (int i = 1; i < sequence.size(); ++i)
    {
        insert(start, sequence[i]);
        
    }
    vector<int> ans;
    DLR(start, ans);
    LRD(start, ans);
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << ans[n+i] << " ";
    }
    cout << endl;
}


