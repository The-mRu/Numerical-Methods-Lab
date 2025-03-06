#include <bits/stdc++.h> 

using namespace std;

int main() {
    
    string line; 
    int num;
    
    while (getline(cin, line))
	 {
    	
        istringstream coeffStream(line);
        int cnt = 0, V_cnt = 0;
        int arr1[100], arr2[100];

        while (coeffStream >> num) 
        {
           arr1[cnt++] = num;	
		}
            

        getline(cin, line);
        istringstream valueStream(line);
        
        while (valueStream >> num) 
        {
        	arr2[V_cnt++] = num;
		}
            

        for (int i = 0; i < V_cnt; i++) {
            int e = cnt - 1;
            int result = 0;
            for (int j = 0; j < cnt; j++) {
                result += arr1[j] * pow(arr2[i], e);
                e--;
            }

            cout << result;
            if (i + 1 < V_cnt) 
                cout << " ";
            else 
                cout << endl;
        }
    }
    
    return 0;
}

