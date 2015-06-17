#include <string>
#include <vector>
#include <cassert>

using namespace std;


namespace my_string{

	/*
	*　strからsubに合致する部分文字列のインデックスを返す。
	*  計算量　O(str.size())
	*  
	*  例:
	*  find_substring_index("abcde","ce");
	*  ret -> {2, 4};
	*/
	vector<int> find_substring_index(string str, string sub){
		assert(str.size() >= sub.size() && "部分文字列の長さが本体よりも超えています");
		vector<int> indexs;

		for (int i = 0, j = 0; i < str.size() && j < sub.size(); ++i){
			if (str[i] == sub[j]){
				indexs.push_back(i);
				++j;
			}
		}

		return indexs;
	}
}