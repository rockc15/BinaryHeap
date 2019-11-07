/*
 * BinHeap.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: casey
 *
 *      contains the function defintions for the binary heap
 */


#include "BinHeap.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

//constructor for the BinHeap class
BinHeap::BinHeap(string arr[], int len) {
	heaplen = 0;
	arrlen = len;
	heap = new string[arrlen];

	for (int i = 0; i < len; i++) {
		insertHeap(arr[i]);
	}
	printHeap();
}

//destructor for the BinHeap class
BinHeap::~BinHeap() {
	delete [] heap;
}

//prints the heap
void BinHeap::printHeap() {
	cout << endl;
	for (int i = 0; i < arrlen;i++) {
		cout << i << ", ";
	}
	cout << endl;
	for (int i = 0; i < heaplen;i++) {
		cout << heap[i] << ", ";
	}
	cout << endl;
}

//find the max elements in the heap, then returns the
//index of the max element
int BinHeap::findMax(int x, int y) {
	if ((x < heaplen) && (y < heaplen)) {
		if (heap[x] > heap[y]) {
			return(x);
		}
		else {
			return(y);
		}
	}
	else if (x < heaplen) {
		return x;
	}
	else return -1;
}

//inserts elements in the heap, then bubbles up
void BinHeap::insertHeap(string s) {
	heap[heaplen] = s;
	bubbleUp(heaplen);
	heaplen++;
}

//deletes the root from the heap, then bubbles down
string BinHeap::deleteHeap() {
	string str = heap[0];
	heap[0] = heap[heaplen -1 ];
	heaplen--;
	bubbleDown(0);
	return str;
}

//places the element in the right location of the heap when the
//starts at the last element in the heap
void BinHeap::bubbleUp(int i) {
	string swap = "";
	int index = i;
	int parent = ((index-1) /2);

	while((heap[index] > heap[parent]) && index != 0){
		swap = heap[index];
		heap[index] = heap[parent];
		heap[parent] = swap;
		index = parent;
		parent= ((index-1) /2);
	}

}

//places the element in the right location in the heap when
//the element starts at the root
void BinHeap::bubbleDown(int i) {
	bool flag = true;
	int index = i;

	while(flag){
		int leftChild = 2*index + 1;
		int rightChild = leftChild + 1;
		if((leftChild > heaplen || rightChild > heaplen)){
			flag = false;
		}
		else{
			int max = findMax(leftChild, rightChild);

			if(heap[index] > heap[max] ){
				flag = false;
			}
			else {
				string swap = heap[index];
				heap[index] = heap[max];
				heap[max] = swap;
				index = max;
			}
		}
	}
}

//swaps the fisrt and last element in the heap
//the buddles down
string BinHeap::deleteHeap2() {
	string str = heap[0];
	heap[0] = heap[heaplen -1 ];
	heap[heaplen -1 ] = str;
	heaplen--;
	bubbleDown(0);
	return str;
}

//deletes all the elements in the heap in a way that sorts the
//heap for lest priority to greatest
void BinHeap::deleteAll() {
	int len = heaplen;
	for(int i = 0; i < len; i ++){
		deleteHeap2();
	}
	heaplen = len;
}

