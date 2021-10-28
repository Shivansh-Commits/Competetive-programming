// print the elements present at level K.

    #include<bits/stdc++.h>
    using namespace std;
    struct Node 
    {
        int data;
        struct Node* left;
        struct Node* right;
    };

    struct Node* newNode(int data)
    {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }

    void kdist(struct Node* node,int k,int curr)
    {
        if(node!=NULL)
        {
            if(curr!=k)
            {
                curr++;
                kdist(node->left , k ,curr);
                kdist(node->right , k ,curr);
            }
            else
            {
                cout<<node->data<<" ";
                return;
            }
        }
    }
    int main()
    {
        struct Node* root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->right->left = newNode(6);
        root->right->left->right = newNode(7);
        root->left->left = newNode(4);
        root->left->right = newNode(5);
        int k;
        cout<<"Enter the Value of K:";
        cin>>k;
        cout<<"Nodes at level K:";
        kdist(root,k,1);

        return 0;
    }
