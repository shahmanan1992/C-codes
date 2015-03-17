#include <iostream>

using namespace std;


int main()
{

	
int n1,n2,count=0;
	
cout<<"Enter the size of 1st array"<<"\n";
        
cin>>n1;
	
int *a=new int[n1]; 
	
cout<<"Enter the size of 2nd array"<<"\n";
        
cin>>n2;
	
int *b=new int[n2];

	
  if(n1==0)

	{

	count=0;

	}

	else

	{

		cout<<"Enter the elements of 1st array"<<"\n";
	
		for(int i=0;i<n1;i++)
		
		{
	
		  cin>>a[i];

		}

		cout<<"Enter the elements of 2nd array"<<"\n";

		for(int j=0;j<n2;j++)

		{

		  cin>>b[j];

		}

	}


      	if(n1>n2)

	{
	
	cout<<"First array greater than second array"<<"\n";

	}

       

	for(int k=0;k<n1;k++)

	{
			
	if(n1<=n2)

		{
		for(int m=0;m<n2;m++)

		  {
		
		    if(a[k]==b[m])

	            {
          	
			count++;

			break;
	
	   	    }
  
		  }

		}

       }



	if(count==n1 || n1==0)

	 cout<<"TRUE"<<"\n";

	 else

         cout<<"FALSE"<<"\n";
 
}
