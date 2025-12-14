#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    set<string> used;
    used.insert(words[0]);

    for (int i = 1; i < words.size(); i++) {
        // 끝말잇기 실패
        if (words[i - 1].back() != words[i][0]) {
            return { (i % n) + 1, (i / n) + 1 };
        }

        // 중복 단어
        if (used.count(words[i])) {
            return { (i % n) + 1, (i / n) + 1 };
        }

        used.insert(words[i]);
    }

    return {0, 0};
}
