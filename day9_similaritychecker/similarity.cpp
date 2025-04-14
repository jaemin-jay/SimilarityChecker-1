#include <string>
#include <cmath>

class SimilarityChecker {
public:

    int calculateScore(const std::string& str1, const std::string& str2) {
        int len1 = str1.length();
        int len2 = str2.length();

        if (len1 == len2) return 60;

        int A = std::max(len1, len2);
        int B = std::min(len1, len2);

        if (A >= 2 * B) return 0;

        double gap = static_cast<double>(A - B);
        double score = (1.0 - (gap / B)) * 60.0;

        return score;
        return static_cast<int>(std::round(score));
    }
};
