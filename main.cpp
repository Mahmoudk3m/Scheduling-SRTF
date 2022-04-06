#include<bits/stdc++.h>
//ACPC2022
//TposersFTW
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define pb push_back
#define lcm(x,y) x*y/__gcd(x,y)
#define summ(n) (n*(n+1))/2
using namespace std;

struct process{
    int pid;
    int endTime;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int remainingTime;
    bool isCompleted=0;
};
bool cmp1(process p1,process p2){
    return(p1.burstTime<p2.burstTime);
}
bool cmp2(process p1,process p2){
    return(p1.pid<p2.pid);
}
int main(){
    struct process p[100];
    cout<<"Enter Number of Processes: ";
    int n,av=0;cin>>n;
    vector<process>v;
    for(int i=0;i<n;i++){
        cout<<endl<<"Enter the arrival time of process #"<<i+1<<": ";
        cin>>p[i].arrivalTime;
        cout<<endl<<"Enter the burst time of process #"<<i+1<<": ";
        cin>>p[i].burstTime;
        p[i].remainingTime=p[i].burstTime;
        p[i].pid=i+1;
        v.pb(p[i]);
    }
    sort(v.begin(),v.end(),cmp2);
    int timer=0,completed=0;
    while(completed!=n){
        int mn=INT_MAX,it=-1;
        for(int i=0;i<n;i++){
            if(v[i].arrivalTime<=timer&&v[i].isCompleted==0){
                if(v[i].remainingTime<mn){
                    mn=v[i].remainingTime;
                    it=i;
                }
                if(v[i].remainingTime==mn){
                    if(v[i].arrivalTime<v[it].arrivalTime){
                        mn=v[i].remainingTime;
                        it=i;
                    }
                }
            }
        }
        if(it!=-1){
            v[it].remainingTime--;
            timer++;
            if(v[it].remainingTime==0){
                v[it].endTime=timer;
                v[it].waitingTime=(v[it].endTime-v[it].arrivalTime)-v[it].burstTime;
                v[it].isCompleted=1;
                completed++;
            }
        }
        else{
            timer++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<endl<<"Process #"<<v[i].pid<<" "<<"Arrival Time: "<<v[i].arrivalTime<<" "<<"Burst Time: "<<v[i].burstTime<<" "<<"Waiting Time: "<<v[i].waitingTime;
        av+=v[i].waitingTime;
    }
    cout<<endl<<"Average Time: "<<av/n;
}