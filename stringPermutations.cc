#include <iostream>
using namespace std;

void permutate(string orig, string chosen);
void indent(int n);

int main() 
{
    permutate("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "");
    return 0;
}

void permutate(string orig, string chosen){
	indent(chosen.length());
	cout << "permuteHelper(" << orig << ", " << chosen << "), " << endl;
	if(orig.empty()){
		cout << chosen << endl;
	}else{
		for(int i =0; i < orig.length(); i++){
			char c = orig[i];
			chosen += c;
			orig = orig.erase(i,1);
			permutate(orig, chosen);
			//UNCHOOSE! C++ passes array by reference! Shit would be empty by the time the other calls backtrack...
			orig.insert(i,1,c);
			chosen.erase(chosen.length() - 1, 1);
		}
	}
}

void indent(int n){
	for (int i=0; i<n;i++){
		cout << "  ";
	}
}