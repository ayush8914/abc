#include <bits/stdc++.h>
using namespace std;

struct point{
    
    int x;
    int y;
};


vector<double> closetpair(vector<point> & points,int n){
    
	int min = INT_MAX;    
	double dist=0,i1,j1;
    for(int i=0;i<n;i++){
   	 for(int j=i+1;j<n;j++){
        	int d= (points[i].x - points[j].x) * (points[i].x - points[j].x) + (points[i].y - points[j].y)*(points[i].y - points[j].y);
     		 if(d < min){
     			 min = d;
     			 dist = sqrt(d);
     			 i1= i;
     			 j1 = j;
     		 }    
   	 }
    }
    return {i1,j1,dist};
}

int main() {
	 
 	int n;
 	cin>>n;
 	vector<point> points(n);
 	for(int i=0;i<n;i++){
		 int x,y;
		 cin>>x;
		 cin>>y;
		 point p;
		 p.x = x;
		 p.y= y;
		 points[i] = p;
 	}
	vector<double> sol = closetpair(points,n);
	 
 	for(int i=0;i<sol.size();i++){
		 cout<<sol[i]<<" ";
 	}
    // your code goes here
    return 0;
}
