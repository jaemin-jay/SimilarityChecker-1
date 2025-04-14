#include <string>
#include <unordered_set>
#include <cctype>
#include <cmath>

class Alpha {
public:
    int calculateAlphabetScore(const std::string& str1, const std::string& str2) {
        std::unordered_set<char> set1, set2;


        for (char c : str1) {
            if (std::isalpha(c)) set1.insert(std::toupper(c));
        }

        for (char c : str2) {
            if (std::isalpha(c)) set2.insert(std::toupper(c));
        }

        if (set1.empty() && set2.empty()) return 40;
        std::unordered_set<char> totalSet = set1;
        for (char c : set2) totalSet.insert(c);

        int sameCnt = 0;
        for (char c : set1) {
            if (set2.count(c)) sameCnt++;
        }

        int totalCnt = totalSet.size();
        if (totalCnt == 0) return 0;

        double score = (static_cast<double>(sameCnt) / totalCnt) * 40.0;
        return static_cast<int>(std::round(score));
    }
};