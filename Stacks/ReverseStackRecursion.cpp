// reverse a stack using recursion


void insert(stack<int>& s, int x) {
   if(s.size() == 0) {
       s.push(x);
       return;
   }
   int temp = s.top();
   s.pop();
   insert(s, x);
   s.push(temp);
}
void reverse(stack<int>& s) {
    if(s.size() == 1) 
        return;
        
    int temp = s.top();
    s.pop();
    reverse(s);
    insert(s, temp);
} 


// https://www.youtube.com/watch?v=8YXQ68oHjAs&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=9&ab_channel=AdityaVerma
