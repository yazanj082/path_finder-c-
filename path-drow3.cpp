#include<iostream.h>
#include<stdlib.h>
int x[102][102],n;
int r[102][102]={0},c[102][102];
int adownpath(int col,int row);
int bdownpath(int col,int row);
int cdownpath(int col,int row);
int ddownpath(int col,int row);
int downpath(int col,int row);


void path();
void fill();
main(){
	cout<<"enter the number of colum\n";
	cin>>n;
	fill();
	
	path();
 for(int a=1;a<=n;a++)
 {for(int b=1;b<=n;b++)
 cout<<r[a][b];
 cout<<endl;}
 cin>>n;
}
void fill(){

	for(int row=1;row<=n;row++)
	{for(int col=1;col<=n;col++){
	x[row][col]=(rand()%4)/2;cout<<x[row][col];
	}
	cout<<endl;
	}
cout<<"\n\n";}
int downpath(int col,int row){
if(x[row][col]==1)
{if(row==n){r[row][col]=1;return 1;}
if (col>n||col<1||row<1||row>n)return 0;

c[row][col]++;
if(c[row][col]>2)
return 0;


	if(adownpath(col,row)==1 || bdownpath(col,row)==1 || cdownpath(col,row)==1||ddownpath(col,row)==1)	
		return 1;
	
else return 0;
	
}
else return 0;
}
int adownpath(int col,int row){
if(x[row][col]==1){
	
if(x[row+1][col]==0&&x[row][col+1]==0&&x[row][col-1]==0)
x[row][col]=0;

		if(downpath(col,row+1)==1)	
		{r[row][col]=1;
		return 1;
		}
	

	else {
	return 0;
}}
else return 0;
}
 int bdownpath(int col,int row){
if(x[row][col]==1)
{
if(x[row+1][col]==0&&x[row][col+1]==0&&x[row-1][col]==0)
x[row][col]=0;		
if(downpath(col+1,row)==1)	
		{r[row][col]=1;
		return 1;		
		}

else {
return 0;
}}
else return 0;
}
 
 int cdownpath(int col,int row){
if(x[row][col]==1)
{if(x[row+1][col]==0&&x[row-1][col]==0&&x[row][col-1]==0)
x[row][col]=0;
		
	
	if(downpath(col-1,row)==1)	
		{
		r[row][col]=1;return 1;
		}
else	{
return 0;
}}
else return 0;
}
 int ddownpath(int col,int row){
if(x[row][col]==1)
{if(x[row-1][col]==0&&x[row][col+1]==0&&x[row][col-1]==0)
x[row][col]=0;
	
	if(downpath(col,row-1)==1)	
		{r[row][col]=1;
		return 1;	
		}
 else{
 	
  return 0;
 }
}
else return 0;
}

void path(){
	int sum=0;
	
	for(int a=1;a<=n;a++)
	{for(int i=1;i<=n;i++){
		for(int h=1;h<=n;h++)
		c[i][h]=0;
	}
	
	r[1][a]=downpath(a,1);}
	                        

	for(int flag=1;flag<=n;flag++)
	sum+=r[1][flag];
if(sum>0)
	cout<<"there is a path\n";
	else cout<<"there is no path\n" ;
	}//   yazan ahmad  jarrar   ID:201610711}