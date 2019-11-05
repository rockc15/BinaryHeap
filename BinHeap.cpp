/*
 * BinHeap.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: casey
 */


#include "BinHeap.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

BinHeap::BinHeap(string arr[], int len) {
	heaplen = 0;
	arrlen = len;
	heap = new string[arrlen];

	for (int i = 0; i < len; i++) {
		insertHeap(arr[i]);
	}
	printHeap();
}

BinHeap::~BinHeap() {
	delete [] heap;
}

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

void BinHeap::insertHeap(string s) {
/* here – look at the .hpp for a description of the method that goes here */
}
string BinHeap::deleteHeap() { // returns the string that was deleted
/* here – look at the .hpp for a description of the method that goes here */
}
void BinHeap::bubbleUp(int i) {
/* here – look at the .hpp for a description of the method that goes here */
}
void BinHeap::bubbleDown(int i) {
/* here – look at the .hpp for a description of the method that goes here */
}
/***************************************************************************/
/* Part 2 */
string BinHeap::deleteHeap2() {
/* here – look at the .hpp for a description of the method that goes here */
}
void BinHeap::deleteAll() {
/* here – look at the .hpp for a description of the method that goes here */
}

