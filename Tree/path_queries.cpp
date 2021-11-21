 /*Jai Shree Ram*/
// Never Give Up
 
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define umii            unordered_map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define F(i,s,e,j)        for(int i=s;i<=e;i+=j)
#define mt19937                 rng(chrono::steady_clock::now().tjhe_since_epoch().count());   
//shuffle(arr,arr+n,rng)
/*---------------------------------------------------------------------------------------------------------------------------*/
int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
int expo(int a, int b,int m) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
int mminv(int a, int b) {int arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
int mminvprime(int a, int b) {return expo(a, b - 2, b);}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
int combination(int n, int r, int m, int*fact, int *ifact) {int val1 = fact[n]; int val2 = ifact[n - r]; int val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vi sieve(int n) {int*arr = new int[n + 1](); vi vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
int phin(int n) {int number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (int i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
/*--------------------------------------------------------------------------------------------------------------------------*/
 void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
const int N = 200000;
vi adj[N+1];
int val[N+1];
int  siz[N+1],parent[N+1],sc[N+1];
int chainNo[N+1],chainHead[N+1],pos[N+1],base_array[N+1];
int tree[4*N+1];
int cn,ptr;
void hld(int src)
{
    if(chainHead[cn]==-1)
    {
        chainHead[cn] = src; 
    }
    chainNo[src] = cn;
   
  if(sc[src]==-1)
    return;
  hld(adj[src][sc[src]]);
    for(int i=0;i<adj[src].size();i++)
  {
     int nbr = adj[src][i];
     if(nbr!=parent[src] && i!=sc[src])
     {
        cn++;
        hld(nbr);
     }
  }
}
void hld_(int src)
{
    pos[src] = ptr;
    base_array[ptr++] = val[src];
    if(sc[src]==-1)
    return;
     hld_(adj[src][sc[src]]);
    for(int i=0;i<adj[src].size();i++)
  {
     int nbr = adj[src][i];
     if(nbr!=parent[src] && i!=sc[src])
      hld_(nbr);
     
  }
}
void dfs(int src)
{
 
   siz[src] = 1;
  for(int nbr:adj[src])
  {
     if(nbr!=parent[src])
     {
       parent[nbr] = src;
       dfs(nbr);
       siz[src] += siz[nbr];
     }
  }
   sc[src] = -1;
   int scs = 0;
    for(int i=0;i<adj[src].size();i++)
  {
     int nbr = adj[src][i];
     if(nbr!=parent[src] && siz[nbr]>scs)
     {
        scs = siz[nbr];
        sc[src] = i;
     }
  }
  
}
void buildTree(int indx,int s,int e)
{
    if(s==e)
    {
        tree[indx] = base_array[s];
        return;
    }
    int mid = (s+e)/2;
   buildTree(2*indx,s,mid);
   buildTree(2*indx+1,mid+1,e);
   tree[indx] =  tree[2*indx]+tree[2*indx+1];
}
void update_point(int indx,int s,int e,int q,int nv)
{
   if(q==s && s==e)
   {
     tree[indx] = nv;
     return;
   }
   else if(q<s||q>e)
    return;
   int mid = (s+e)/2;
   update_point(2*indx,s,mid,q,nv);
   update_point(2*indx+1,mid+1,e,q,nv);
   tree[indx] =  tree[2*indx]+tree[2*indx+1];
}
int query(int indx,int s,int e,int qs,int qe)
{
    if(qs<=s && qe>=e)
    return tree[indx];
    else if(e<qs || s>qe)
        return 0;
    int mid = (s+e)/2;
    int left = query(2*indx,s,mid,qs,qe);
    int right = query(2*indx+1,mid+1,e,qs,qe);
    return left+right;
}
int queryUP(int u,int v)
{
    int ans = 0;
    while(true)
    {
 
        if(chainNo[u]==chainNo[v])
        {
            if(u==v)
                ans += val[u];
            else
             ans  +=  query(1,1,ptr-1,pos[v],pos[u]);
                
            break;
 
        }
        else
       {
           int h = chainHead[chainNo[u]];
           ans += query(1,1,ptr-1,pos[h],pos[u]);
           u = parent[h];
       }
    }
    return ans;
}
int32_t main()
{    
    c_p_c(); 
        cn = 1;
        ptr = 1;
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++)
         cin>>val[i];
        for(int i=1;i<=n;i++)
            chainHead[i] = -1;
        for(int i=1;i<=n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        parent[1] = 0; 
        dfs(1);
        hld(1);
        hld_(1);
        buildTree(1,1,ptr-1);
        while(q--)
        {
            int b;
            cin>>b;
            if(b==1)
            {
                int s,x;
                cin>>s>>x;
                update_point(1,1,ptr-1,pos[s],x);
            }
            else
            {
                int u;
                cin>>u;
                cout<<queryUP(u,1)<<endl;
            }
        }
     
}