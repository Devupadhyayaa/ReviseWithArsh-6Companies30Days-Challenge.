class Solution {
public:
    long long minimumCost(string s, string t, vector<char>& origin, vector<char>& destination, vector<int>& cost) {
        if (s.size() != t.size()) {
            return -1;
        }

        std::vector<std::vector<long long>> distance(26, std::vector<long long>(26, 1e12));
        distance[0][0] = 0;

        for (int i = 0; i < 26; i++) {
            distance[i][i] = 0;
        }

        int n = origin.size();

        for (int i = 0; i < n; ++i) {
            distance[origin[i] - 'a'][destination[i] - 'a'] = std::min(distance[origin[i] - 'a'][destination[i] - 'a'], static_cast<long long>(cost[i]));
        }

        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (distance[i][k] == 1e12 || distance[k][j] == 1e12) {
                        continue;
                    }
                    distance[i][j] = std::min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }

        long long totalCost = 0;
        int m = s.size();

        for (int i = 0; i < m; ++i) {
            long long diff = distance[s[i] - 'a'][t[i] - 'a'];

            if (diff == 1e12) {
                return -1;
            }
            totalCost += diff;
        }

        return totalCost;
    }
};
