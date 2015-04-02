#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int cases;
    cin >> cases;
    string str;
    for(int z = 0; z < cases; z++){
        cin >> str;
        bool finished = false;
        std::string::reverse_iterator j,i;
        
        for (i=str.rbegin(); (i!=str.rend()) && !finished; ++i){
			for (j=str.rbegin(); j!=i && !finished; ++j){
				//cout << "Left: " << *j << "   right:  " << *i << endl;
				if(*j > *i){
					//cout << "switching " << *j << " to the right and " << *i << " to the left " << endl;
					char temp = *i;
					*i = *j;
					*j = temp;
					finished = true;
				}	
			}
        }
        if(!finished){
            cout << "no answer" << endl;
        } else {
			i--;
			//cout << str << endl;
			sort(i.base(),str.end());
            cout << str << endl;
        }
    }
    return 0;
}
