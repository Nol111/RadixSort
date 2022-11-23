#include <iostream>
#include <vector>
#include <string>
using namespace std;

void radixsort(vector<string>&a, int m, int k, int i){
    vector<string> result(a.size(), "");
    vector<int> count(26, 0);
    for(int j = 0; j < a.size(); j++){
        count[a[j][i] - 'a']++;
    }
    int t = 0;
    int p = 0;
    for(int j = 0; j < count.size(); j++){
        t = count[j];
        count[j] = p;
        p = p + t;
    }
    for(int j = 0; j < a.size(); j++){
        result[count[a[j][i] - 'a']] = a[j];
        count[a[j][i] - 'a']++;
     }
    a = result;
}
int main(){
    int x, y, z;
    cin >> x >> y >> z;
    vector<string> a(x, "");
    for (int i = 0; i < x; i++) {
        cin >> a[i];
    }
    for (int i = y - 1; i > y - z - 1; i--){
        radixsort(a, y, z, i);
    }
    for (int i = 0; i < x; i++) {
        cout << a[i]<<endl;
    };
}



