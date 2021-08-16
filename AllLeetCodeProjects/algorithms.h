#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>

/*
576.�����·����
����һ����СΪ m x n �������һ���������ʼ����Ϊ [startRow, startColumn] ������Խ����Ƶ����ĸ����������ڵĵ�Ԫ���ڣ����Դ�������߽絽������֮�⣩���� ��� �����ƶ� maxMove ����
����������� m��n��maxMove��startRow �Լ� startColumn ���ҳ������ؿ��Խ����Ƴ��߽��·����������Ϊ�𰸿��ܷǳ��󣬷��ض� 109 + 7 ȡ�� ��Ľ����
*/
int findPaths(void) {
	//����
	int m, n, maxMove, startRow, startColumn;
	scanf_s("%d%d%d%d%d", &m, &n, &maxMove, &startRow, &startColumn);
	//��̬�滮
	int ***dp = (int ***)calloc(2, sizeof(int**));
	for (int i = 0; i < 2; i++) {
		dp[i] = (int**)calloc(m, sizeof(int*));
		for (int j = 0; j < m; j++) {
			dp[i][j] = (int*)calloc(n, sizeof(int));
		}
	}
	// dp[0][j][k]��ʾ��һ���ߵ����꣨j��k����·������dp[1][j][k]��ʾ��һ���ߵ�����j��k��·����
	dp[0][startRow][startColumn] = 1;
	// �ĸ�����
	int dir[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
	int resCnt = 0;
	for (int i = 0; i < maxMove; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (dp[0][j][k] > 0) {
					for (int d = 0; d < 4; d++) {
						int jj = j + dir[d][0];
						int kk = k + dir[d][1];
						if (jj >= 0 && jj < m && kk >= 0 && kk < n) {
							dp[1][jj][kk] = (dp[1][jj][kk] + dp[0][j][k]) % 1000000007;
						}
						else {
							resCnt = (resCnt + dp[0][j][k]) % 1000000007;
						}
					}
				}
			}
		}
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				dp[0][j][k] = dp[1][j][k];
				dp[1][j][k] = 0;
			}
		}
	}
	printf("%d\n", resCnt);
	return resCnt;
}

#endif