
class Solution {
public:
    int monkeyMove(int n) {
        const long long MOD = 1e9 + 7;

        long long ans = 1;
        long long base = 2;
        long long power = n;
        while (power > 0) {
            if (power % 2 == 1) {
                ans = (ans * base) % MOD;
            }

            base = (base * base) % MOD;
            power /= 2;
        }

        return (ans - 2 + MOD) % MOD;
    }
};
