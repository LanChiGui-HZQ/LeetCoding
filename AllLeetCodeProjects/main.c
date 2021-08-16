#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "datastruct.h"
#include "algorithms.h"
#include "stringoperation.h"

int main(void) {
	while (1) {
		char s[100];
		scanf_s("%s", s, 100);
		lengthOfLongestSubstring(s);
	}
	return 0;
}