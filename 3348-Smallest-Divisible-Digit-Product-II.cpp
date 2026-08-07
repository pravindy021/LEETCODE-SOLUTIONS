class Solution {
public:
    using ll = long long;

    string buildSmallestString(ll targetFactor, int slots) {
        string result;

        for (int value = 9; value >= 2; value--) {
            while (targetFactor % value == 0) {
                result.push_back(char(value + '0'));
                targetFactor /= value;
            }
        }

        while (result.size() < slots) {
            result.push_back('1');
        }

        reverse(result.begin(), result.end());
        return result;
    }

    string smallestNumber(string number, long long target) {
        int length = number.size();

        ll checkFactor = target;

        for (int prime : {2, 3, 5, 7}) {
            while (checkFactor % prime == 0) {
                checkFactor /= prime;
            }
        }

        if (checkFactor != 1) {
            return "-1";
        }

        vector<ll> factorNeeded(length + 1, target);

        for (int idx = 0; idx < length; idx++) {
            int currentDigit = number[idx] - '0';

            if (currentDigit == 0) {
                break;
            }

            factorNeeded[idx + 1] =
                factorNeeded[idx] / gcd(factorNeeded[idx], (ll)currentDigit);
        }

        if (factorNeeded[length] == 1) {
            return number;
        }

        int firstZero = number.find('0');
        int startIndex = length - 1;

        if (firstZero != -1) {
            startIndex = firstZero;
        }

        for (int pos = startIndex; pos >= 0; pos--) {
            ll currentNeed = factorNeeded[pos];
            int remainingSlots = length - pos - 1;

            for (int nextDigit = (number[pos] - '0') + 1; nextDigit <= 9; nextDigit++) {
                ll updatedNeed = currentNeed / gcd(currentNeed, (ll)nextDigit);

                string suffix = buildSmallestString(updatedNeed, remainingSlots);

                if (suffix.size() == remainingSlots) {
                    return number.substr(0, pos) + char(nextDigit + '0') + suffix;
                }
            }
        }

        return buildSmallestString(target, length + 1);
    }
};