#include<iostream>
#include<cmath>
using namespace std;
int main(){
	
	float x[100] , y[100];
	int n;
	cout<<" Enter the number of data pair of (x,y) : ";
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cout<<"\n Data "<< i+1 <<endl;
	    cout<<" X[" << i+1 << "]= ";
		cin>>x[i] ;
	    cout<<" Y[" << i+1 << "]= ";
		cin>>y[i] ;
	}
	cout<<"\n\n ----Complete data table -----\n"<<endl;
		
	float sumy = 0 , sumx = 0,sumxx = 0,sumxy = 0;
	cout<<" X\tY\tSum[x]\tSum[y]\tSum[xx]\tSum[xy]"<<endl;
	for(int i = 0 ; i < n ; i++){
		sumy += y[i];
		sumx += x[i];
		sumxy += x[i]*y[i];
		sumxx += x[i]*x[i];
		
	    cout<<" "<<x[i]<<"\t"<<y[i]<<"\t "<<sumx<<"\t  "<<sumy<<"\t "<<sumxx<<"\t "<<sumxy<< endl;	
	}
	
	float a=(sumx*sumxy-sumy*sumxx)/(sumx*sumx-n*sumxx);
    float b=(sumy*sumx-n*sumxy)/(sumx*sumx-n*sumxx);

    cout<<" \n a = "<<a<<endl;
    cout<<" b = "<<b<<endl;
    cout<<" The equation : y = a + bx"<<endl;
    cout<<"\n The best fit value of curve is : y = "<< a<< " + "<< b<< "x.\n\n"<<endl;
	
	// error calculation
	
	float St ,Sr , r;
	float Ya = sumy/n; // average of y
	float Xa = sumx/n; // average of x
	
	/* St = Sum(Yi - Y')^2
	   Sr = Sum (Yi - Y)^2 
	   Y = a + bXi; 
	*/
	for(int i = 0 ; i < n ; i++){
		St += pow((y[i] - Ya) , 2);
		Sr += pow((y[i] - (a+b*x[i])) , 2);
	}
	cout<<" St = "<<St<<endl;
	cout<<" Sr = "<<Sr<<endl;
	
	r = pow((St - Sr)/St , 0.5); // calculating the r
	cout<<" r = "<<r<<endl;
	float Sy = sqrt(St/(n-1)); // standard deviation
	float Syx = sqrt(Sr/(n-2)); // standart error of estimate
	
	int diff = Syx - Sy;
	if(diff < 0){
		cout<<" The Linear model has good fitness "<<endl;
	}else{
		cout<<" The Linear model has not good fitness "<<endl;	
	}
	
	return 0;
}
