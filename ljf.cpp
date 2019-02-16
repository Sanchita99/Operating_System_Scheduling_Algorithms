#include<stdio.h>
#include<limits.h>

int main()
{
	int n,i,j,m,max,c=0,k,count=0,min=INT_MAX,t=0;
	float av_tat=0,av_wt=0;
	
	printf("Enter number of processes\n");
	scanf("%d",&n);
	
	int a[n],b[n],ct[n],bt[n],tat[n],wt[n],ac[n],btc[n],p[n];
	
	printf("Enter arrival time\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		ac[i]=a[i];
		b[i]=i;
		if(min>a[i])
		{
			min=a[i];
		}
	}

	printf("Enter burst time\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
		btc[i]=bt[i];
	}
	
	printf("Order:\n");
	
	if(min!=0)
	{
		printf("idle for %d sec",min);
		c=min;
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i]<a[j])
			{
				m=a[i];
				a[i]=a[j];
				a[j]=m;
				
				m=b[i];
				b[i]=b[j];
				b[j]=m;
			}
		}
	}
	
	
	int z=0;
	for(i=0;i<INT_MAX;)
	{
		max=INT_MIN;
		for(j=0;j<n;j++)
		{
			if(ac[b[j]]<=i)
			{	
				if(max<bt[b[j]])
				{
					max=bt[b[j]];
					k=b[j];
				}
			
			}
		}
		if(max!=INT_MIN)
		{
			p[z]=k;
		//	printf("%d bt %d at %d\n ",p[z]+1,bt[p[z]],ac[p[z]]);
			if(ct[p[z-1]]<ac[p[z]])
			{
				c=ac[p[z]]-ct[p[z-1]]+c;
			//	printf("idle for %d sec\n as ac is %d and ct is %d and c is %d\n",ac[p[z]]-ct[p[z-1]],ac[p[z]],ct[p[z-1]],c);
				printf("|idle for %d sec| ",ac[p[z]]-ct[p[z-1]]);		
			}
			printf("%d ",p[z]+1);
			z++;
			i=i+max;
			ct[k]=c+bt[k];
			c=ct[k];
		//	printf("c of process %d\n",c);
			tat[k]=ct[k]-ac[k];
			wt[k]=tat[k]-bt[k];
			bt[k]=INT_MIN;
			count++;
			if(count==n)
			{
				break;
			}
		}
		else
			i++;
	}
	
	printf("\n");
		
	printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\n");
	
	/*
	for(i=0;i<n;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",i+1,ac[i],btc[i],ct[i],tat[i],wt[i]);
	}
	*/
	
	for(i=0;i<n;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",i+1,ac[i],btc[i],ct[i],tat[i],wt[i]);
	}
	
		for(i=0;i<n;i++)
	{
		av_tat=tat[i]+av_tat;
		av_wt=wt[i]+av_wt;
	}
	printf("avg tat : %f \n avg wt : %f",(av_tat/n),(av_wt/n));
	
	
		
}
