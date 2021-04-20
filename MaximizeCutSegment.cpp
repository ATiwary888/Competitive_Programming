// problem: given a rod of length n, and three different length x,y,z;
// we have to cut the rod in different segment such that segments should be
// of the length x or, y or, z.

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    
    {
        int arr[n+1] = {0};
        bool trk[n+1]={0};
        arr[0]=-1;
        if(x<=n)
        trk[x]=1;
        if(y<=n)
        trk[y]=1;
        if(z<=n)
        trk[z]=1;
        trk[0]=1;
        // cout<<arr[0]<<endl;
        
        for(int i = 1;i<=n;i++){
            int a,b,c;
            a = i-x;
            b = i-y;
            c = i-z;
            int e,f,g;
            e = 0;f = 0;g = 0;
            int ch = 0;
            if(a>=0&&a<=n&&trk[a]==1){if(a==0){e = 0;ch = 1;}else{e = arr[a]+1;ch = 1;}}
            if(b>=0&&b<=n&&trk[b]==1){if(b==0){f = 0;ch = 1;}else{f = arr[b]+1;ch = 1;}}
            if(c>=0&&c<=n&&trk[c]==1){if(c==0){g = 0;ch = 1;}else{g = arr[c]+1;ch = 1;}}
            trk[i]=ch;
            vector<int>temp;
            temp.push_back(e);temp.push_back(f);temp.push_back(g);
            sort(temp.begin(),temp.end());
            arr[i]=temp[2];
            
        }
        // for(int i = 0;i<=n;i++){
        //     cout<<arr[i]<<" ";
        // }cout<<endl;
        int b = arr[n]+1;
        if(b == 1){if(n==x||n==y||n==z)return 1;
            else
            return 0;
        }
        return arr[n]+1;
        //Your code here
    }
};