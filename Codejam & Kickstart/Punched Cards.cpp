#include<bits/stdc++.h>
using namespace std;
void xuly(){
    int t;
    cin>>t;
    int x=t;
    while(t--){
        cout<<"Case #"<<x-t<<":"<<endl;
        int rows, cols;
        cin>>rows>>cols;
        for(int i=0;i<2*rows+1;i++){
            for(int j=0;j<2*cols+1;j++){
                if((i==0 && j==0)||(i==0&&j==1)||(i==1&&j==0)||(i==1&&j==1)){
                    cout<<(".");
                }
                else if(j%2!=0&&i%2==0){
                    cout<<("-");
                }
                else if(j%2==0&&i%2==0){
                    cout<<"+";
                }
                else if(j%2==0&&i%2!=0){
                    cout<<"|";
                }
                else if(j%2!=0&&i%2!=0){
                	cout<<".";
				}

            }
            cout<<endl;
        }
    }
}
int main(){
    xuly();
}