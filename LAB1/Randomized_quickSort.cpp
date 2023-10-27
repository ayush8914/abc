#include<bits/stdc++.h>
using namespace std;
 
//lab1 -  rand quick sort    -- O(nlog(n))   =>  2n(ln(n)-1)
int partition(int array[],int p,int r){
 
  srand(time(NULL));
  int rindex = p + rand()%(r-p+1);
 
  int pivot = array[rindex];
  array[rindex] = array[r];
  array[r]  = pivot;
 
  int i = p-1;
 
   for(int j=p;j<r;j++){
 
    if(array[j] < pivot){
    i++;
    swap(array[i],array[j]);
    }
 
   }
   swap(array[i+1],array[r]);
   return i+1;
 
}
 
 
void randMergeSort(int array[], int p, int r){
 
   if(p >=r)return;
 
   int q= partition(array,p,r);
   randMergeSort(array,p,q-1);
   randMergeSort(array,q+1,r);   
 
}
 
 
int main() {
 
 
 
    int array[] = {5,4,14,3,2,1};
     
    randMergeSort(array,0,5);  
    for(int i=0;i<6;i++){
     cout<< array[i] <<"\n";
    }
 
	return 0;
}