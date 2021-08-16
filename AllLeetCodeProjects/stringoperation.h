#ifndef STRINGOPERATION_H
#define STRINGOPERATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mmax(a,b) ((a)>(b)?(a):(b))
#define mmin(a,b) ((a)<(b)?(a):(b))
/*最长不重复子串，给定一个字符串s ，请你找出其中不含有重复字符的 最长子串 的长度*/
int lengthOfLongestSubstring(char * s) {
	int maxLength = 50002;
	int numOfChars = 256;
	// 记录每个字母最后一次出现的下标
	int lastAppear[256];
	memset(lastAppear, -1, numOfChars*sizeof(int));
	int length = strnlen_s(s, maxLength);
	int res = 0;
	int newStart = 0;
	for (int i = 0; i < length; i++) {
		if (lastAppear[s[i]] <0) {
			// 如果是第一次出现
			res = mmax(res, i - newStart + 1);
		}
		else if(newStart>lastAppear[s[i]]) {
			// 重复出现且中间还有别的重复字母
			res = mmax(res, i - newStart+1);
		}
		else {
			// 重复出现且中间没有别的重复字母
			res = mmax(res, i - lastAppear[s[i]]);
			newStart = lastAppear[s[i]] + 1;
		}
		lastAppear[s[i]] = i;
	}
	printf("%d\n", res);
	return res;
}
#endif // !STRINGOPERATION_H
