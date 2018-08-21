#include<iostream>
using namespace std;
void sort(int a[],int n){
	int i=0,m=0;
	int z1=0,z2=0;
	for(m=1;m<n;m++){
		if(m%2==0)
		for(i=z1;i<n-1-z2;i++){
			if(a[i]>a[i+1]){
				int temp=0;
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
			if(i==n-z2-2)
				z2++;
		}
		if(m%2==1)
		for(i=n-1-z2;i>z1;i--){
			if(a[i]<a[i-1]){
				int temp=0;
				temp=a[i];
				a[i]=a[i-1];
				a[i-1]=temp;
			}
			if(i==z1+1)
				z1++;
		}
	}
}
int main(){
	int *a;
	int n;
	cout<<"please import amount:"<<endl;
	cin>>n;
	a=new int[n];
	for(int i=0;i<n;i++){
		cout<<"please import number"<<endl;
		cin>>a[i];
	}
	sort(a,n);
	for(int i=0;i<n;i++){
		cout<<" "<<a[i];
	}
	return 0;
}
