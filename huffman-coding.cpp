#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left, *right; 

    Node(char ch, int freq, Node* left = NULL, Node* right = NULL)
    {
        this->ch = ch;
        this->freq = freq;
        this->left = left;
        this->right = right;
 
    }       
};

struct comp
{
    bool operator()(Node* l, Node* r)
    {
        return l->freq > r->freq;
    }
};
 
bool isLeaf(Node* root) 
{ 
    return root->left == nullptr && root->right == nullptr;
}
 
void encode(Node* root, string str, unordered_map<char, string> &huffmanCode)
{
    if (!root)
        return;

    if (isLeaf(root))
        huffmanCode[root->ch] = (str != "") ? str : "1";
 
    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}
 
void decode(Node* root, int &index, string str)
{
    if (!root)
        return;
 
    if (isLeaf(root)) 
    {
        cout << root->ch;
        return;
    }
 
    index++;
 
    if (str[index] == '0')
        decode(root->left, index, str);
    else
        decode(root->right, index, str);
}
 

void buildHuffmanTree(string s)
{
    if (s == "")
        return;
 
    unordered_map<char, int> freq;
    for (auto ch: s)
        freq[ch]++;
 
    priority_queue<Node*, vector<Node*>, comp> pq;
 
    for (auto it: freq)
    {
        pq.push(new Node(it.first, it.second));
    }
 
    while (pq.size() != 1)
    {
        Node *left = pq.top(); 
        pq.pop();
        
        Node *right = pq.top();    
        pq.pop();

        pq.push(new Node('\0', left->freq + right->freq, left, right));
    }

    Node* root = pq.top();
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);
 
    cout<<"Huffman Codes are:\n"<<'\n';
    for (auto it: huffmanCode) 
    {
        cout<<it.first<<" --> "<<it.second<<'\n';
    }
 
    cout<<"\nThe original string is:\n"<<s<<'\n';
 
    string str;
    for (auto ch: s)
        str += huffmanCode[ch];
 
    cout<<"\nThe encoded string is: \n"<<str<<'\n';
    
    cout<<"\nThe decoded string is : ";
    if (isLeaf(root))
    {
        while (root->freq--) 
        {
            cout << root->ch;
        }
    }
    else
    {
        int index = -1;
        while (index < (int)str.size() - 1) 
        {
            decode(root, index, str);
        }
    }
}

int main()
{
    cout<<"Enter any string : ";
    string s;
    cin>>s;

    buildHuffmanTree(s);

	return 0;

}