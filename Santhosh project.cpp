#include<iostream>
using namespace std;
int main() 
{  
  int n,a=0,q1,q2,temp; 
  int wtime=0,tat=0,at[10],bt[10],rt[10],tt[10],wt[10],pid[10]; 
  cout<<"Enter total number of Processes :\t "; 
  cin>>n; 
  for(int i=0;i<n;i++) 
  { 
  	pid[i]=i+1;
    cout<<"Enter Arrival Time for Process"<<pid[i]<<" :"; 
    cin>>at[i];
	cout<<"Enter Burst Time for Process"<<pid[i]<<" :"; 
	cin>>bt[i]; 
    rt[i]=bt[i]; 
    cout<<endl<<endl;
  }  
  q1=6; 
  q2=10;
  cout<<endl;
  for(int i=0;i<n;i++)
  {
  	rt[i]=rt[i]-q1;
  	a=a+6;
  	cout<<"Remaining time after Time quantum->6 : "<<pid[i]<<"="<<rt[i]<<"\n";
   } 
   cout<<"\n\n";
   for(int i=0;i<n;i++)
	{
  	rt[i]=rt[i]-q2;
  	a=a+10;
	cout<<"Remaining time after Time quantum->10 : "<<pid[i]<<"="<<rt[i]<<"\n";
    } 
   for(int i=0;i<n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(rt[i]>rt[j])
			{
				temp=rt[j];
				rt[j]=rt[i];
				rt[i]=temp;
				
				temp=at[j];
				at[j]=at[i];
				at[i]=temp;
				
				temp=bt[j];
				bt[j]=bt[i];
				bt[i]=temp;
				
				temp=pid[j];
				pid[j]=pid[i];
				pid[i]=temp;
			}
		}	
	}	
	cout<<"Now processing the process"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"-> "<<"P"<<pid[i]<<endl;
	}
	for(int i=0;i<n;i++)
	{	
	a=a+rt[i];
	tt[i]=a-at[i];
	wt[i]=tt[i]-bt[i];
	wtime+=wt[i];
	tat+=tt[i];
	}	
	cout<<"\nAverage Waiting Time= "<<wtime*1.0/n; 
  	cout<<"\nAverage Turnaround Time = "<<tat*1.0/n;
}
