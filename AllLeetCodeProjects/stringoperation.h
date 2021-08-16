#ifndef STRINGOPERATION_H
#define STRINGOPERATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mmax(a,b) ((a)>(b)?(a):(b))
#define mmin(a,b) ((a)<(b)?(a):(b))
/*����ظ��Ӵ�������һ���ַ���s �������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ���*/
int lengthOfLongestSubstring(char * s) {
	int maxLength = 50002;
	int numOfChars = 256;
	// ��¼ÿ����ĸ���һ�γ��ֵ��±�
	int lastAppear[256];
	memset(lastAppear, -1, numOfChars*sizeof(int));
	int length = strnlen_s(s, maxLength);
	int res = 0;
	int newStart = 0;
	for (int i = 0; i < length; i++) {
		if (lastAppear[s[i]] <0) {
			// ����ǵ�һ�γ���
			res = mmax(res, i - newStart + 1);
		}
		else if(newStart>lastAppear[s[i]]) {
			// �ظ��������м仹�б���ظ���ĸ
			res = mmax(res, i - newStart+1);
		}
		else {
			// �ظ��������м�û�б���ظ���ĸ
			res = mmax(res, i - lastAppear[s[i]]);
			newStart = lastAppear[s[i]] + 1;
		}
		lastAppear[s[i]] = i;
	}
	printf("%d\n", res);
	return res;
}
#endif // !STRINGOPERATION_H
