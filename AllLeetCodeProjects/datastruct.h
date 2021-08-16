#ifndef DATASTRUCT_H
#define DATASTRUCT_H

#include <stdio.h>
#include <stdlib.h>
/*
2.两数相加
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/
/*
测试用例
struct ListNode *l1 = (struct ListNode *)calloc(1, sizeof(struct ListNode)),*l2 = (struct ListNode *)calloc(1, sizeof(struct ListNode));
struct ListNode *p1 = l1, *p2 = l2;
p1->val = 9; p1->next = (struct ListNode *)calloc(1, sizeof(struct ListNode)); p1 = p1->next;
p1->val = 9; p1->next = (struct ListNode *)calloc(1, sizeof(struct ListNode)); p1 = p1->next;
p1->val = 9; p1->next = (struct ListNode *)calloc(1, sizeof(struct ListNode)); p1 = p1->next;
p1->val = 9; p1->next = (struct ListNode *)calloc(1, sizeof(struct ListNode)); p1 = p1->next;
p1->val = 9;
p2->val = 9; p2->next = (struct ListNode *)calloc(1, sizeof(struct ListNode)); p2 = p2->next;
p2->val = 9; p2->next = (struct ListNode *)calloc(1, sizeof(struct ListNode)); p2 = p2->next;
p2->val = 9;
(void)addTwoNumbers(l1, l2);
*/
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* res = (struct ListNode *)calloc(1, sizeof(struct ListNode));
	res->val = 0;
	res->next = NULL;
	struct ListNode* pos1 = l1;
	struct ListNode* pos2 = l2;
	struct ListNode* posR = res;
	int valTmp = 0;
	while (pos1 != NULL || pos2 != NULL) {
		posR->next = (struct ListNode *)calloc(1, sizeof(struct ListNode));
		posR = posR->next;
		if (pos1 != NULL) {
			valTmp += pos1->val;
			pos1 = pos1->next;
		}
		if (pos2 != NULL) {
			valTmp += pos2->val;
			pos2 = pos2->next;
		}
		posR->val = valTmp % 10;
		valTmp = valTmp / 10;
	}
	if (valTmp > 0) {
		posR->next = (struct ListNode *)calloc(1, sizeof(struct ListNode));
		posR = posR->next;
		posR->val = valTmp;
	}
	posR = res->next;
	while (posR != NULL) {
		printf("%d", posR->val);
		posR = posR->next;
	}
	putchar('\n');
	return res->next;
}
#endif