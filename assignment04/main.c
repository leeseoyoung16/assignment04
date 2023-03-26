#include<stdio.h>
#include<stdlib.h>


typedef struct {
	int row;
	int col;
	int val;
}element;

typedef struct SparseMatix {
	element* data;
	int rows;// Çà °¹¼ö
	int cols; // ¿­ °¹¼ö
	int terms; //Ç× °¹¼ö
}SparseMatix;

SparseMatix matrix_transpose2(SparseMatix a) {
	SparseMatix b;

	int bindex;
	b.rows = a.cols;
	b.cols = a.rows;
	b.terms = a.terms;

	b.data = (element*)malloc(b.terms * sizeof(element));

	if (a.terms > 0) {
		bindex = 0;
		for (int c = 0; c < a.cols; c++) {
			for (int i = 0; i < a.terms; i++) {
				if (a.data[i].col == c) {
					b.data[bindex].row = a.data[i].col;
					b.data[bindex].col = a.data[i].row;
					b.data[bindex].val = a.data[i].val;
					bindex++;
				}
			}
		}
	}
	return b;

}
SparseMatix input() {
	SparseMatix a;
	printf("Enter the size of rows and columns, the number of non-zero terms: ");
	scanf_s("%d %d %d", &a.rows, &a.cols, &a.terms);

	a.data = (element*)malloc(a.terms * sizeof(element));

	printf("Enter row, column, and value pairs in order:\n");
	for (int i = 0; i < a.terms; i++) {
		scanf_s("%d %d %d", &a.data[i].row, &a.data[i].col, &a.data[i].val);
	}
	return a;

}
void martix_print(SparseMatix b) {
	printf("The transposed matrix is:\n");
	for (int i = 0; i < b.terms; i++) {
		printf("%d %d %d \n", b.data[i].row, b.data[i].col, b.data[i].val);
	}
	
}

int main() {
	SparseMatix a, b;
	a = input();
	b = matrix_transpose2(a);

	martix_print(b);

	return 0;
}
