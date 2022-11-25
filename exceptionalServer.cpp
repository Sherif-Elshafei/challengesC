#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;

class Server {
private:
	static int load;
public:
	static int compute(long long A, long long B) {
		load += 1;
		if(A < 0) {
			throw std::invalid_argument("A is negative");
		}
		vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
		if(B == 0) throw 0;
		real = (A/B)*real;
		int ans = v.at(B);
		return real + A - B*ans;
	}
	static int getLoad() {
		return load;
	}
};
int Server::load = 0;

int main() {
	int T; cin >> T;
	while(T--) {
		long long A, B;
		cin >> A >> B;
		/* Enter your code here. */
        int temp;
        bool okFlag=true;
        try{
            temp= Server::compute(A,B);
        }
        catch (std::invalid_argument e){
            cout<<"Exception: "<<e.what()<<endl;
            okFlag=false;
        }
        catch (std::out_of_range e){
            cout<<"Exception: "<<e.what()<<endl;
            okFlag=false;
        }
        // catch (int i){
        //     cout<<"B is: "<<i<<endl;
        //     okFlag=false;
        // }
        catch (std::bad_alloc& e){
            cout<<"Not enough memory"<<endl;
            okFlag=false;
        }
        catch (...){
            cout<<"Other Exception"<<endl;
            okFlag=false;
        }
        if (okFlag)
            cout<<temp<<endl;
	}
	cout << Server::getLoad() << endl;
	return 0;
}