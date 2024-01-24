#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long lli;
typedef long double ld;
typedef pair<int, int> p2i;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<p2i> vp2i;

const int SIZE = 1e5 + 1,INF = 1e8 + 1;

class Node{
    public:
        string directory;
        string complete_directory;
        Node *parent;
        map<string, Node*> children;

    Node(string dir, Node *par){
        directory = dir;
        parent = par;
        if(par!=NULL)
            complete_directory = par->complete_directory + "/" + dir;
    }

};

void addParent(string dir, Node *par){
    Node *n = new Node(dir, par);
    par->children[dir] = n;
}

Node *findParent(Node *curr){
        while(curr->parent != NULL){
            curr = curr->parent;
        }
        return curr;
    }

Node *processPath(string Path, Node *curr){
    Path;
    bool root = false;
    queue<string> Tokens;
    string aux = "";
    forn(i, Path.size()){
        char c = Path[i];
        if(i == 0 && c == '/'){
            root = true;
        }
        if(c == '.'){
            Tokens.push("..");
            aux = "";
            i++;
        }
        if(c == '/'){
            if(!aux.empty()){
                Tokens.push(aux);
            }
            aux = "";
        }
        if(isalpha(c)){
            aux += c;
        }
    }

    if(!aux.empty()){
        Tokens.push(aux);
    }

    // while(!Tokens.empty()){
    //     cout << Tokens.front();
    //     Tokens.pop();
    // }
    // cout << endl;

    if(root){
        curr = findParent(curr);
    }
    
    while(!Tokens.empty()){
        string token = Tokens.front();
        Tokens.pop();
        if(token == ".."){
            curr = curr->parent;
        }
        else{
            addParent(token, curr);
            curr = curr->children[token];
        }
    }

    return curr;
}

void solve(){
    int n; cin >> n;
    string ins;
    Node *root = new Node("", NULL);
    Node *curr = root;
    string newPath;
    while(n--){
        cin >> ins;
        if(ins == "pwd"){
            cout << curr->complete_directory << '/' << endl;
        }
        else if(ins == "cd"){
            cin >> newPath;
            curr = processPath(newPath, curr);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;

    // while(t--)
        solve();

    return 0;
}