#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x==1){
            cout<<2<<endl;
            continue;
        }
        cout<<x/3+(x%3!=0)<<endl;
    }
    return 0;
}
