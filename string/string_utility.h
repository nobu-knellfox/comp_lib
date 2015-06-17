#include <string>
#include <vector>
#include <cassert>

using namespace std;


namespace my_string{

	/*
	*�@str����sub�ɍ��v���镔��������̃C���f�b�N�X��Ԃ��B
	*  �v�Z�ʁ@O(str.size())
	*  
	*  ��:
	*  find_substring_index("abcde","ce");
	*  ret -> {2, 4};
	*/
	vector<int> find_substring_index(string str, string sub){
		assert(str.size() >= sub.size() && "����������̒������{�̂��������Ă��܂�");
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