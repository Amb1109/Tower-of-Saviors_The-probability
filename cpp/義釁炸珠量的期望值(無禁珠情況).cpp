#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream> 
#include <unistd.h>
#include <windows.h>
using namespace std;

int main()
{
	const int row = 5;
	const int column = 6;
	unsigned seed;
		int iarr[row][column];
	int i,j,k,l,m,n,o,p,q,u,v,w;
    int num[31];
	double r,s,t;
	r=0;
	s=0;
	t=0;
	for (w=0;w<31;w++)
    {
    	num[w]=0;
	}
	seed = (unsigned)time(NULL);
	srand(seed);
	
	cout <<"數字1-6將會假定為不同符石，當中6為暗符石\n如果有3粒或以上相連情況，將不會算入演算次數當中\n\n請設定每一次演算隔間時間，單位為毫秒： ";
	cin >> u;
	cout << "請設定你想演算的次數：" ;
	cin >> v;
	cout << "\n\n";
	for (l=0;l<v;l++)
	{
		m=0;
	    for(i=0;i<row;i++)
	    {
		    for(j=0;j<column;j++)
		    {
			    k= rand()%6;			    		
		    	iarr[i][j]=k+1;
		    	cout << iarr[i][j];
	        }
	        cout << "\n";
	    }  

	    for(n=0;n<row;n++)
	    {
	    	for(o=0;o<column;o++)
	    	{
	            if(iarr[n][o]!=6)
	            {
					switch(n)
					{
						case 0:
							switch(o)
							{
								case 0:
									if(iarr[n][o]==iarr[n][o+1] || iarr[n][o]==iarr[n+1][o])
									{
										m++;
									}
									break;
									
								case 1 ... 4:
									if(iarr[n][o]==iarr[n+1][o] || iarr[n][o]==iarr[n][o+1] || iarr[n][o]==iarr[n][o-1])
									{
										m++;
									}
									break;
								case 5:
									if(iarr[n][o]==iarr[n+1][o] || iarr[n][o]==iarr[n][o-1])
									{
										m++;
									}
									break;
							}
							break;
						case 1 ... 3:
							switch(o)
							{
								case 0:
									if(iarr[n][o]==iarr[n][o+1] || iarr[n][o]==iarr[n+1][o] || iarr [n][o]==iarr[n-1][o])
									{
										m++;
									}
									break;
									
								case 1 ... 4:
									if(iarr[n][o]==iarr[n+1][o] || iarr[n][o]==iarr[n-1][o] || iarr[n][o]==iarr[n][o+1] || iarr[n][o]==iarr[n][o-1])
									{
										m++;
									}
									break;
								case 5:
									if(iarr[n][o]==iarr[n+1][o] || iarr[n][o]==iarr[n][o-1] || iarr[n][o]==iarr[n-1][o])
									{
										m++;
									}
									break;								
							}
							break;
						case 4:
							switch(o)
							{
								case 0:
									if(iarr[n][o]==iarr[n][o+1] || iarr [n][o]==iarr[n-1][o])
									{
										m++;
									}
									break;
									
								case 1 ... 4:
									if(iarr[n][o]==iarr[n-1][o] || iarr[n][o]==iarr[n][o+1] || iarr[n][o]==iarr[n][o-1])
									{
										m++;
									}
									break;
								case 5:
									if(iarr[n][o]==iarr[n][o-1] || iarr[n][o]==iarr[n-1][o])
									{
										m++;
									}
									break;	
							}						
							break;
					}
				}

			}
	    }
 	    
	    for(p=0;p<row;p++)
	    {
	    	for(q=0;q<column;q++)
	    	{
	    			if (p<3)
	    			{
						if(iarr[p][q]==iarr[p+1][q] && iarr[p+1][q]==iarr[p+2][q])
	    				{
	    					m=31;
						}
					}
					
					if (q<4)
					{
						if(iarr[p][q]==iarr[p][q+1] && iarr[p][q+1]==iarr[p][q+2])
	    				{
	    					m=31;
						}
					}
			}
		}
		
		r=r+m;
	    s++;
        num[m]++;
        
		if(m==31) 
	    {
	    	r=r-m;
	    	l--;
	    	s=s-1;
            num[m]--;
	    	cout << "有3粒或以上相連，不列入計算。\n\n";
		}	    
		else
		{
			cout << "第"<<s<<"次演算，相連珠子數目:"<<m<<"粒\n"<<endl;
		}
	    Sleep(u);
    }
    t = r/s; 
    cout<<"經"<<s<<"次演算後,炸珠量的期望值為"<<t<<"粒\n"<<endl; 
    cout<<"\n同色相連珠數統計數據如下:\n0珠:"<<num[0]<<"\n2珠:" <<num[2]<<" 3珠:"<<num[3]<<" 4珠:"<<num[4]<<" 5珠:"<<num[5]<<"\n6珠:"<<num[6]<<" 7珠:"<<num[7]<<" 8珠:"<<num[8]<<" 9珠:"<<num[9]<<" 10珠:"<<num[10]<<"\n11珠:"<<num[11]<<" 12珠:"<<num[12]<<" 13珠:"<<num[13]<<" 14珠:"<<num[14]<<" 15珠:"<<num[15]<<"\n16珠:"<<num[16]<<" 17珠:"<<num[17]<<" 18珠:"<<num[18]<<" 19珠:"<<num[19]<<" 20珠:"<<num[20]<<"\n21珠:"<<num[21]<<" 22珠:"<<num[22]<<" 23珠:"<<num[23]<<" 24珠:"<<num[24]<<" 25珠:"<<num[25]<<"\n26珠:"<<num[26]<<" 27珠:"<<num[27]<<" 28珠:"<<num[28]<<" 29珠:"<<num[29]<<" 30珠:"<<num[30];
    system("pause"); 
	return 0;
}
