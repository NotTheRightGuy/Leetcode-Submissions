class Solution {
public:
	bool isAnagram(string s, string t) {
		vector<int> charMap(26, 0);
		if (s.size() != t.size()) return false;
		for (int i = 0; i < s.size(); i++) {
			charMap[s[i] - 'a']++;
		}

		for (int j = 0; j < t.size(); j++) {
			charMap[t[j] - 'a']--;
		}

		if (count(charMap.begin(), charMap.end(), 0) == 26)return true;
		return false;
	}
};