#include<bits/stdc++.h>
using namespace std;
class Solution {
    int unsignedBitLength(unsigned int number) {
        int length;
        
        length = 0;
        while (number != 0) {
            ++length;
            number >>= 1;
        }

        return length;
    }

public:
    int divide(int dividend, int divisor) {
        bool minus;
        unsigned int unsigned_dividend, unsigned_divisor;
        unsigned int d;
        unsigned int quotient;
        int offset;

        minus = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0) ? true : false;

        unsigned_dividend = abs(dividend);
        unsigned_divisor = abs(divisor);
        
        if ((dividend == 0) || (unsigned_dividend < unsigned_divisor)) {
            return 0;
        }

        offset = unsignedBitLength(unsigned_dividend) - unsignedBitLength(unsigned_divisor);
        quotient = 0;
        while (offset >= 0) {
            d = unsigned_divisor << offset;
            if (unsigned_dividend >= d) {
                unsigned_dividend -= d;
                quotient += 1 << offset;
			
            }
            --offset;
        }
        

        cout<<quotient<<"\n";
        if (minus == false && quotient > numeric_limits<int>::max()) {
            return numeric_limits<int>::max();
        }

        return minus ? ~quotient + 1 : quotient;
    }
};


int main(){

	Solution s;
	cout<<s.divide(-20,3)<<endl;
	return 0;
}