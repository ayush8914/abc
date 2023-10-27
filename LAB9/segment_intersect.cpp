#include<bits/stdc++.h>

#define point pair<int,int>
#define lineseg  pair<point,point>
#define ff first
#define ss second


using namespace std;

int direction(point &pi, point &pj, point &pk){
    point pki = {pk.ff - pi.ff,pk.ss - pi.ss};
    point pji = {pj.ff - pi.ff,pj.ss - pi.ss};

    int d = (pki.ff * pji.ss) - (pji.ff * pki.ss);
    return d;
}


bool onseg(point &pi, point &pj, point &pk){
   
   if(min(pi.ff,pj.ff) <= pk.ff && max(pi.ff,pj.ff) >= pk.ff && min(pi.ss,pj.ss) <= pk.ss && max(pi.ss,pj.ss) >= pk.ss){
       return true;
   }
   else return false;
}


bool Isintersecting(lineseg &pq, lineseg &rs){
   
   int d1 = direction(rs.ff,rs.ss,pq.ff);
    int d2 = direction(rs.ff,rs.ss,pq.ss);
    int d3 = direction(pq.ff,pq.ss,rs.ff);
    int d4 = direction(pq.ff,pq.ss,rs.ss);

    if( d1 * d2 < 0 &&  d3 * d4 < 0){
        return true;
    }
    else if( d1 == 0 && onseg(rs.ff,rs.ss,pq.ff)){
        return true;
    }
    else if( d2 == 0 && onseg(rs.ff,rs.ss,pq.ss)){
        return true;
    }
    else if( d3 == 0 && onseg(pq.ff,pq.ss,rs.ff)){
        return true;
    }
    else if( d4 == 0 && onseg(pq.ff,pq.ss,rs.ss)){
        return false;
    }
    else return false;
}



int main(){
   int x1,x2,x3,x4,y1,y2,y3,y4;
   
   cin>>x1>>y1;
    cin>>x2>>y2;
    cin>>x3>>y3;
    cin>>x4>>y4;

    point p1({x1,y1}), p2({x2,y2}), p3({x3,y3}), p4({x4,y4});

    lineseg pq({p1,p2}), rs({p3,p4});

    cout<<Isintersecting(pq,rs)<<endl;

    return 0;
}