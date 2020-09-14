#include<iostream>
using namespace std;

void job_sq(int a,int b,int *job, int *dead, int *profit);
int max_dead(int l,int *dead);
void order(int a,int *job, int *dead, int *profit)
{
	int k,x,tp1,td1,tj1;
	for(x=0;x<a-1;x++)
	{
		for(k=0;k<a-1;k++)
		if(profit[k] < profit[k+1])
		{
			int tp1,td1,tj1;
	        tp1 = profit[k];    
	        profit[k]=profit[k+1];
	        profit[k+1]=tp1;
	        
			td1 = dead[k];    
	        dead[k]=dead[k+1];
	        dead[k+1]=td1;
	        
			tj1 = job[k];    
	        job[k]=job[k+1];
	        job[k+1]=tj1;			
		}		
	}	
}
void job_sq(int a,int b,int *job, int *dead, int *profit)
{
	//find max profit and jobs to be done
	int i,j,d1=0;
	int jobs_done[b];
	for(i=0;i<b;i++)
	jobs_done[i]=0;
	int tpro = 0;
	for(i=0;i<b;i++)     //assigning jobs_done
	{	
		for(j=b-1;j>=0;j--)
		{
			if(jobs_done[j]== 0)
			{
			jobs_done[i]=job[i];
			tpro += profit[i];
			break; 
		    }
		}
	}
	cout<<"Jobs done are: ";
	for(i=0;i<b;i++)
	cout<<"j"<<jobs_done[i]<<" ,";
	cout<<"\n"<<"Total profit= "<<tpro;		
}

int max_dead(int l,int *dead)
{
	int max=0,i;
	for(i=0;i<l;i++)
	{
		if(dead[i]>max)
		max = dead[i];		
	}
	return max;	
}
int main()
{
   int n,i,md;
   cout<<"enter no. of jobs";
   cin>>n;
   int job[n], dead[n],profit[n];
   for(i=0;i<n;i++)
   cin>>job[i];
   cout<<"enter deadline for "<<n<<" jobs"<<"\n";
   for(i=0;i<n;i++)
   cin>>dead[i];
   cout<<"enter profit for "<<n<<" jobs"<<"\n";
   for(i=0;i<n;i++)
   cin>>profit[i];
   order(n,job,dead,profit);
   md = max_dead(n,dead);
   job_sq(n,md,job,dead,profit);   
   return 0;   	
}
