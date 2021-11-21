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
int par[200001];
int sparse_table[200001][21];
int depth[200001];
vi graph[200001];
int log_2[200001];
void dfs(int src,int pare,int d)
{
     depth[src] = d;
     par[src] = pare;
     for(int nbr:graph[src])
        { if(nbr!=pare)
          dfs(nbr,src,d+1);
        }
 
}
int parent(int x,int k)
{
     while(k)
          {
          x = sparse_table[x][log_2[(k&(-k))]];
          k -= (k&(-k)); 
          }
          if(x==0)
               x = -1;
         return x;
 
}
int32_t main()
{   c_p_c();
     int n,q;
     cin>>n>>q;
     memset(par,0,sizeof(par));
      log_2[1] = 0;
     for(int i=2;i<=n;i++)
      log_2[i] = log_2[i/2]+1;
     for(int i=1;i<=n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            graph[a].pb(b);
            graph[b].pb(a);

          }
     dfs(1,0,0);
     for(int i=0;i<=n;i++)
        sparse_table[i][0] = par[i];
     
    
     for(int j=1;j<=20;j++)
     {
        sparse_table[0][j] = 0;
        for(int i=1;i<=n;i++)
          sparse_table[i][j] = sparse_table[sparse_table[i][j-1]][j-1];
     }
     while(q--)
     {
        int x,y;
        cin>>x>>y;
        int ans = 0;
        if(depth[x]<depth[y])
               swap(x,y);
          if(depth[x]!=depth[y])
               {
                ans = depth[x]-depth[y];
                x = parent(x,depth[x]-depth[y]);
               }
          if(x==y)
          {
               cout<<ans<<endl;
               continue;
          }
          int subans = 0;
          for(int j=20;j>=0;j--)
          {
               if(sparse_table[x][j]!=sparse_table[y][j])
               {
                    subans += (1<<j);
                    x = sparse_table[x][j];
                    y = sparse_table[y][j];
               }
          }
          subans++;
          ans += 2*subans;
          cout<<ans<<endl;
     }
} 