/* Name- Umang Agarwal
   Trade - CSE 
    College - IIT Mandi 
  Problem Objective - Maximise Summation of PiXi 
  Input Arguments - (1) No. Of variables n  (2) No. of constraints m (3) Values of Pi (4) Values of row constraints Rij
                    (5) Values of b Vector 
  Output Arguments - (1) Optimum Value of equation (2) Values of Xi at Optimum Value
  */

# include <iostream>
# include <vector>
# include <cmath>
using namespace std ;

void generator(int  *arr , int m , int n  ) // Function to compute permutation of variables and store in arr
{
    int a[n] ;
    int dec=m  , i=0 ;
    while(dec>0)
    {
        a[i]=dec%2 ;
        i++;
        dec=dec/2 ;
    }
    while(i<n)
    {
        a[i]=0;
        i++;
    }
    for(i=0;i<n;i++)
    {
        *(arr+i)=a[i] ;
    }
}




int main()
{
    int n , m ,i , j , k ;
    cout<<"Please Enter the value of n "<<endl ;
    cin>>n;
    cout<<"Please Enter the value of m  "<<endl ;
    cin>>m ;
    if(n>0 && m>0 )
    {
        vector <float> p(n);
        cout<<"Please start entering the problem objective:"<<endl ;        // Taking input from user of  Problem Objective
        for(i=0;i<n;i++)
        {
            printf("Enter the value of P%d \n",i+1);
            cin>>p[i];
        }
        float r [m][n] ;
        for(i=0;i<m;i++)                                                    // Taking input of row of constraints
        {
            printf("Please enter the %d row of constraints \n",i+1) ;
            for(j=0;j<n;j++)
            {
                printf("Enter the value of r%d%d \n",i+1,j+1);
                cin>>r [i][j];
            }
        }
        cout<<"Please enter the b vector "<<endl ;
        vector <float> b(n) ;
        for(i=0;i<m;i++)                                                    // Taking input of b
        {
            printf("Enter the value of b%d \n",i+1);
            cin>>b[i];
        }
        float max=0 ;
        float tmax ;
        int maxv[n] ;
        for(i=0;i<n;i++)
            maxv[i]=0;
        int temp[n] ;
        float cal ;
        int check=0 ;
        for(i=0;i<pow(2,n);i++)                                              // computing all the possible permutations of values of X i's
        {
            generator(temp,i , n );                                          // Calling generator function to compute a possible values for X i's
            int flag=0 ;
            for(k=0;k<m;k++)                                                 // To check whether values of X i's satisfy given conditions
            {
                cal=0;
               for(j=0;j<n;j++)
               {
                   cal+=temp[j]*r[k][j];
               }
                if(cal>b[k])
                {
                    flag=1;
                    break ;
                }
            }
            if(flag==0)
            {
                tmax=0;
                for(j=0;j<n;j++)
                {
                    tmax+=p[j]*temp[j];
                }
                if(tmax>max)
                {
                    max=tmax;
                    for(j=0;j<n;j++)
                    {
                        maxv[j]=temp[j];
                    }
                }
                check=1;
            }
        }
        if(check==1)
        {
           printf("The optimal value is %lf \n",max );                            // Displaying Optimal value
           cout<<"The variable values are: "<<endl ;                              // Displaying Variable values 
           for(i=0;i<n;i++)
           {
               printf("x%d=%d \n",i+1,maxv[i]);
           }
        }
        else
            printf("Solution Not Possible \n") ;
        
        
    }
    else
        return 0 ;
    return 0 ;
    
}
