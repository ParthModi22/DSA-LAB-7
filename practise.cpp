#include<iostream>
using namespace std;
class graph{
    private:
    int adj[100][100];
    int n;

    public:
    graph(int n){
        this->n = n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                adj[i][j]=0;
            }
        }
    }
    void addedgeD(int u,int v){
        adj[u][v]=1;
    }
    void addedgeUD(int u,int v){
        adj[u][v]=1;
        adj[v][u]=1;
    }
    void InOutdegree(){
        for(int i=0;i<n;i++){
            int in=0;
            int out=0;

            for(int j=0;j<n;j++){
                in += adj[j][i];
            }
            for(int j=0;j<n;j++){
                out += adj[i][j];
            }
            cout<<"node "<< i<<": indegree is "<<in<<", outdgree is "<<out<<endl;
        }
    }
    void displaymatrix(){
        cout<<"Adjecency matrix:"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void displaylist(){
        cout<<"adjecency list:"<<endl;
        for(int i=0;i<n;i++){
            cout<<i<<"->";
            for(int j=0;j<n;j++){
                if(adj[i][j]==1){
                    cout<<j<<" ";
                }
            }
            cout<<endl;
        }
    }
    void inputg(){
        int numedge;
        cout<<"enter number of edges"<<endl;
        cin>>numedge;
        cout<<"enter the edges (u,v):"<<endl;
        for(int i=0;i<numedge;i++){
            int u,v;
            cin>>u>>v;
            addedgeD(u,v);
        }
    }

};
int main()
{
    int n;
    cout<<"enter number of nodes "<<endl;
    cin>>n;

    graph g(n);
    g.inputg();
    g.displaymatrix();
    g.displaylist();
    g.InOutdegree();


   return 0;
}