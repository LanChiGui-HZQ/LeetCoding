#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>

/*
576.出界的路径数
给你一个大小为 m x n 的网格和一个球。球的起始坐标为 [startRow, startColumn] 。你可以将球移到在四个方向上相邻的单元格内（可以穿过网格边界到达网格之外）。你 最多 可以移动 maxMove 次球。
给你五个整数 m、n、maxMove、startRow 以及 startColumn ，找出并返回可以将球移出边界的路径数量。因为答案可能非常大，返回对 109 + 7 取余 后的结果。
*/
int findPaths(void) {
	//输入
	int m, n, maxMove, startRow, startColumn;
	scanf_s("%d%d%d%d%d", &m, &n, &maxMove, &startRow, &startColumn);
	//动态规划
	int ***dp = (int ***)calloc(2, sizeof(int**));
	for (int i = 0; i < 2; i++) {
		dp[i] = (int**)calloc(m, sizeof(int*));
		for (int j = 0; j < m; j++) {
			dp[i][j] = (int*)calloc(n, sizeof(int));
		}
	}
	// dp[0][j][k]表示上一步走到坐标（j，k）的路径数，dp[1][j][k]表示这一步走到坐标j，k的路径数
	dp[0][startRow][startColumn] = 1;
	// 四个方向
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