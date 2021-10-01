//Stack Using Single Queue
#include<bits/stdc++.h>
#include<queue>
using namespace std;

class Stack{
	int N;
	queue<int>q1;
	
	public:
	   Stack(){
		N=0;
	}
	
		void push(int val){
			N++;
			q1.push(val);
			
			for(int i=0;i<size()-1;i++){
				q1.push(q1.front());
				q1.pop();
			}
			
		}
		
		void pop(){
			if(q1.empty()){
				return ;
			}
			q1.pop();
			N--;	
		}
		
		int top(){
			if(q1.empty()){
				return -1;
			}
			return q1.front();
		}
		
		int size(){
			return N;
		}
};

int main(){
	Stack st;
	st.push(5);
	st.push(22);
	st.push(12);
	st.push(45);
	cout<<st.top()<<endl;
	st.pop();
	cout<<st.top()<<endl;
	st.pop();
	cout<<"size is "<<st.size()<<endl;
	return 0;
}
