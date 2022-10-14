#include <iostream>
using namespace std;

//print function for print the whole array
void printArray(int a[],int size){
  for(int i=0;i<size;i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
}

//marge function for marge the deviding array which is coming from the recursive call
int *marge(int a[],int low,int mid,int high){
  int i,j,k,b[low + high];
  i=low;
  j=mid+1;
  k=low;
  while(i<=mid && j<=high){
    if(a[i]<a[j]){
      b[k]=a[i];
      k++;
      i++;
    }
    else{
      b[k]=a[j];
      j++;
      k++;
    }
  }
  while(i<=mid){
    b[k]=a[i];
    k++;
    i++;
  }
  while(j<=high){
    b[k]=a[j];
    j++;
    k++;
  }
  for(int i=low;i<=high;i++){
    a[i]=b[i];
  }
  //return the all marging sorted array
  return a;
}

//function for marge_sort which is calling recursively
int *margesort(int a[],int low,int high){
  int mid;
  if(low<high){
    mid=(low+high)/2;
    //start recursively
    margesort(a,low,mid);  //recursive calling for margesort start to middle of the array
    margesort(a,mid+1,high); //recursive calling for margesort middle+1 to high ot the array
    marge(a,low,mid,high);  //finally after the recursive calling it will marge the array using marge function
  }
}

int main() 
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int mid;
  printArray(a,n);
  margesort(a,0,n);  //call the margesort function
  printArray(a,n);   //after the calling margesort function call print function to print sorted array
}
