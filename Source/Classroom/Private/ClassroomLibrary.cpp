// Fill out your copyright notice in the Description page of Project Settings.


#include "ClassroomLibrary.h"

void UClassroomLibrary::classForLoop(int initial, int final, int iter, FForLoopDelegate execute) {
	//Fix Edge Cases
	if (iter == 0) {
		if (initial > final) {
			iter = -1;
		}
		else {
			iter = 1;
		}
	}
	else if (iter > 0) {
		if(initial > final) { 
			int temp = initial;
			initial = final;
			final = temp;
		}
	}
	else {
		if (initial < final) {
			int temp = initial;
			initial = final;
			final = temp;
		}
	}

	for (int i = initial; i < final; i += iter) {
		execute.ExecuteIfBound(i);
	}
}
