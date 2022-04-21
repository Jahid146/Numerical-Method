#include<iostream>
using namespace std;

int main(){
	float a[10][10] , b[10] , x[10] ,y[10];
	int n , m;
	cout<<" Enter the size of the equation as 2D array : ";
	cin>>n;
	cout<<" Enter the coeff as Matrix : "<<endl;
	for(int i = 0 ; i < n; i++){
		for(int j = 0 ; j < n ; j++){
			cin>>a[i][j];
		}
	}
	
	cout<<" Enter the constant term "<<endl;
	for(int i = 0 ; i < n ; i++){
		cin>>b[i];
	} 
	
	cout<<" Enter the initial value of x"<<endl;
	for(int i = 0 ; i < n ; i++){
		cout<<" X"<<i+1<<" ";
		cin>>x[i];
	} 
	
	cout<<" Enter the number of iteration : ";
	cin>>m;
	int step = 1;
	while(m>0){
		
	    for(int i = 0 ; i < n ; i++){
	    	y[i] = (b[i] / a[i][i]);
		    for(int j = 0 ; j < n ; j++){
				if(j == i){
					continue;
				}
				y[i] = y[i] - ((a[i][j] / a[i][i])* x[j]);
				x[i] = y[i];
			}
		    printf(" X%d = %.3f\t" ,i+1 , y[i] );
		} 
		cout<<endl;
		m--;
	}
	
	return 0;
}



