
#include<stdio.h>
#include<iostream>


using namespace std;

class Solution {
public:
    
    int path_count;

    void go_down(int x,int y,int  m,int  n)
    {
        y = y + 1;
	//cout<<"y:"<<y<<"\n";
        if(y == m - 1)
        {
            path_count++;
	    //if(path_count%100000 == 0)
	    //cout<<"path count:"<<path_count<<"\n";
        }
        else
        {
            go_down(x,y,m,n);
            if(x < n - 1)
                go_right(x,y,m,n);
        }
        return;
    }
    void go_right(int x,int y,int  m,int  n)
    {
        x = x + 1;
	//cout<<"x:"<<x<<"\n";
        if(x == n - 1)
        {
            path_count++;
	    //if(path_count%100000 == 0)
	    //cout<<"path count:"<<path_count<<"\n";
        }
        else
        {
            go_right(x,y,m,n);
            if(y < m - 1)
                go_down(x,y,m,n);
        }
        return;
    }
    
    int uniquePaths(int m, int n) {
        path_count = 0;
        
        if(m==1 && n==1)
            return 1;
        
        int x=0,y=0;
        if(y < m - 1)
            go_down(x,y,m,n);
        if(x < n - 1)
            go_right(x,y,m,n);
        return path_count;
        
    }
};


int main()
{
	Solution sol;
	int cnt=sol.uniquePaths(51,9);
	cout<<"path count: "<<cnt<<"\n";
	return 0;
}
