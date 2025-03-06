#include <bits/stdc++.h>
using namespace std;

int p, q, r, s, t, u; 
double f(double x)
   {
    return p*exp(-x)+q*sin(x)+ r * cos(x) + s * tan(x) + t * x * x + u;
   }

int main(){
    while(cin >> p >> q >> r >> s >> t >> u)
	 {
        double low = 0.0, high = 1.0;
        
        if(f(low) * f(high) > 0) 
		{
            cout << "No solution" <<endl;
            continue;
        }
        
        for (int i = 0; i < 100; i++){
            double mid = (low + high) / 2.0;
            if(f(mid) > 0)
                low = mid;
            else
                high = mid;
        }
        
        cout << fixed << setprecision(4) << high << endl;
    }
    return 0;
}

