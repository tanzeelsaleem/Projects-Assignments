#include"Header.h"
//definition of functions.
//function for initializing an array of unsorted number.
void ini_unsort_array(int number[], const int size) {
	for (int i = 0; i < size; i++) {
		number[i] = (rand() % size) + 1;
	}
}

//function for initializing an arry of sorted numbers.
void ini_sort_array(int number[], const int size) {
	for (int i = 0; i < size; i++) {
		number[i] = i + 1;
	}
}

//function for wrong selection sort.
void wrong_selection_sort(int number[], const int size) {
	int min_number, location, temporary;
	for (int i = 0; i < (size - 1); i++) {
		min_number = number[i];
		location = i;
		for (int j = i + 1; j < size; j++) {
			if (number[j] < min_number) {
				min_number = number[j];
				location = j;
				swap(number[i], number[location]);
			}
		}
	}
}

//function for correct selection sort.                
void correct_selection_sort(int number[], const int size) {
	for (int i = 0; i < (size - 1); i++) {
		int min_index = i;
		for (int j = (i + 1); j < size; j++) {
			if (number[j] < number[min_index]) {
				min_index = j;
			}
		}
		if (i != min_index) {
			swap(number[i], number[min_index]);
		}
	}
}

//function for bubble sort without flag.
void bubble_sort_woutf(int number[], const int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (number[j] > number[j + 1])
			{
				swap( number[j], number[j + 1]);	
			}
		}
	}
}

//fuction for bubble sort with flag.
void bubble_sort_wf(int number[], const int size) {          
	bool swapped = true;
	int check = 1;
	while (swapped) {
		swapped = false;
		for (int j = size - 1; j >= check; j--) {
			if (number[j] < number[j - 1]) {
				swap(number[j], number[j - 1]);
				swapped = true;
			}
		}
		check++;
	}
}

//function for insertion sort.
void insertion_sort(int number[], const int size) {       
	for (int i = 1; i < size; i++) {
		int point = number[i];
		int j = i - 1;
		while (j >= 0 && point < number[j]) {
			number[j + 1] = number[j];
			j--;
		}
		number[j + 1] = point;
	}
}

//function for swapping values.
void swap(int& number1, int& number2) {
	int temporary = number1;
	number1 = number2;
	number2 = temporary;
}

//founction for execution and writing in csv file for an unsorted array.
void execution1(int number[], const int size) {
	fstream sorting("file.csv", ios::out);   //creating and opening new file in writing mode.
	if (sorting.is_open()) {
		auto total = 0;
		sorting << "Algorithm," << "Array Size," << "Array Type (Random/Sorted)," << "Number of runs," <<"Execution Time (in microseconds),"<< "Average time taken (in microseconds)" << endl;
		for (int i = 0; i < 10; i++) {
			//initializing unsorted array at every loop.
			ini_unsort_array(number, size);
			sorting << "Wrong Selection Sort,";
			sorting << size << ",";
			sorting << "Random,";
			sorting << i + 1 << ",";
			auto t1 = chrono::high_resolution_clock::now();
			wrong_selection_sort(number, size);
			auto t2 = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
			sorting << duration << endl;
			total = total + duration;
			if (i == 9) {
				auto average = 0;
				average = total / 10;
				sorting << ",,,,," << average << endl;
				total = 0;
			}
		}
		
		sorting << "\nAlgorithm," << "Array Size," << "Array Type (Random/Sorted)," << "Number of runs," << "Execution Time (in microseconds)," << "Average time taken (in microseconds)" << endl;
		for (int i = 0; i < 10; i++) {
			ini_unsort_array(number, size);
			sorting << "Correct Selection Sort,";
			sorting << size << ",";
			sorting << "Random,";
			sorting << i + 1 << ",";
			auto t1 = chrono::high_resolution_clock::now();
			correct_selection_sort(number, size);
			auto t2 = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
			sorting << duration << endl;
			total = total + duration;
			if (i == 9) {
				auto average = 0;
				average = total / 10;
				sorting << ",,,,," << average << endl;
				total = 0;
			}
		}
	
		sorting << "\nAlgorithm," << "Array Size," << "Array Type (Random/Sorted)," << "Number of runs," << "Execution Time (in microseconds)," << "Average time taken (in microseconds)" << endl;
		for (int i = 0; i < 10; i++) {
			ini_unsort_array(number, size);
			sorting << "Bubble Sort Without Flag,";
			sorting << size << ",";
			sorting << "Random,";
			sorting << i + 1 << ",";
			auto t1 = chrono::high_resolution_clock::now();
			bubble_sort_woutf(number, size);
			auto t2 = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
			sorting << duration << endl;
			total = total + duration;
			if (i == 9) {
				auto average = 0;
				average = total / 10;
				sorting << ",,,,," << average << endl;
				total = 0;
			}
		}
	
		sorting << "\nAlgorithm," << "Array Size," << "Array Type (Random/Sorted)," << "Number of runs," << "Execution Time (in microseconds)," << "Average time taken (in microseconds)" << endl;
		for (int i = 0; i < 10; i++) {
			ini_unsort_array(number, size);
			sorting << "Bubble Sort With Flag,";
			sorting << size << ",";
			sorting << "Random,";
			sorting << i + 1 << ",";
			auto t1 = chrono::high_resolution_clock::now();
			bubble_sort_wf(number, size);
			auto t2 = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
			sorting << duration << endl;
			total = total + duration;
			if (i == 9) {
				auto average = 0;
				average = total / 10;
				sorting << ",,,,," << average << endl;
				total = 0;
			}
		}
		
		sorting << "\nAlgorithm," << "Array Size," << "Array Type (Random/Sorted)," << "Number of runs," << "Execution Time (in microseconds)," << "Average time taken (in microseconds)" << endl;
		for (int i = 0; i < 10; i++) {
			ini_unsort_array(number, size);
			sorting << "Insertion Sort,";
			sorting << size << ",";
			sorting << "Random,";
			sorting << i + 1 << ",";
			auto t1 = chrono::high_resolution_clock::now();
			insertion_sort(number, size);
			auto t2 = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
			sorting << duration << endl;
			total = total + duration;
			if (i == 9) {
				auto average = 0;
				average = total / 10;
				sorting << ",,,,," << average << endl;
				total = 0;
			}
		}
	}
	sorting.close();  //closing file.
}

//founction for execution and writing in csv file for a sorted array.
void execution2(int number[], const int size) {
	fstream sorting("file.csv", ios::out | ios::app);  //opening file in append mode.
	if (sorting.is_open()) {
		auto total = 0;
		sorting << "\nAlgorithm," << "Array Size," << "Array Type (Random/Sorted)," << "Number of runs," << "Execution Time (in microseconds)," << "Average time taken (in microseconds)" << endl;
		for (int i = 0; i < 10; i++) {
			//initializing sorted array at every loop.
			ini_sort_array(number, size);
			sorting << "Wrong Selection Sort,";
			sorting << size << ",";
			sorting << "Sorted,";
			sorting << i + 1 << ",";
			auto t1 = chrono::high_resolution_clock::now();
			wrong_selection_sort(number, size);
			auto t2 = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
			sorting << duration << endl;
			total = total + duration;
			if (i == 9) {
				auto average = 0;
				average = total / 10;
				sorting << ",,,,," << average << endl;
				total = 0;
			}
		}

		sorting << "\nAlgorithm," << "Array Size," << "Array Type (Random/Sorted)," << "Number of runs," << "Execution Time (in microseconds)," << "Average time taken (in microseconds)" << endl;
		for (int i = 0; i < 10; i++) {
			ini_sort_array(number, size);
			sorting << "Correct Selection Sort,";
			sorting << size << ",";
			sorting << "Sorted,";
			sorting << i + 1 << ",";
			auto t1 = chrono::high_resolution_clock::now();
			correct_selection_sort(number, size);
			auto t2 = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
			sorting << duration << endl;
			total = total + duration;
			if (i == 9) {
				auto average = 0;
				average = total / 10;
				sorting << ",,,,," << average << endl;
				total = 0;
			}
		}

		sorting << "\nAlgorithm," << "Array Size," << "Array Type (Random/Sorted)," << "Number of runs," << "Execution Time (in microseconds)," << "Average time taken (in microseconds)" << endl;
		for (int i = 0; i < 10; i++) {
			ini_sort_array(number, size);
			sorting << "Bubble Sort Without Flag,";
			sorting << size << ",";
			sorting << "Sorted,";
			sorting << i + 1 << ",";
			auto t1 = chrono::high_resolution_clock::now();
			bubble_sort_woutf(number, size);
			auto t2 = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
			sorting << duration << endl;
			total = total + duration;
			if (i == 9) {
				auto average = 0;
				average = total / 10;
				sorting << ",,,,," << average << endl;
				total = 0;
			}
		}

		sorting << "\nAlgorithm," << "Array Size," << "Array Type (Random/Sorted)," << "Number of runs," << "Execution Time (in microseconds)," << "Average time taken (in microseconds)" << endl;
		for (int i = 0; i < 10; i++) {
			ini_sort_array(number, size);
			sorting << "Bubble Sort With Flag,";
			sorting << size << ",";
			sorting << "Sorted,";
			sorting << i + 1 << ",";
			auto t1 = chrono::high_resolution_clock::now();
			bubble_sort_wf(number, size);
			auto t2 = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
			sorting << duration << endl;
			total = total + duration;
			if (i == 9) {
				auto average = 0;
				average = total / 10;
				sorting << ",,,,," << average << endl;
				total = 0;
			}
		}

		sorting << "\nAlgorithm," << "Array Size," << "Array Type (Random/Sorted)," << "Number of runs," << "Execution Time (in microseconds)," << "Average time taken (in microseconds)" << endl;
		for (int i = 0; i < 10; i++) {
			ini_sort_array(number, size);
			sorting << "Insertion Sort,";
			sorting << size << ",";
			sorting << "Sorted,";
			sorting << i + 1 << ",";
			auto t1 = chrono::high_resolution_clock::now();
			insertion_sort(number, size);
			auto t2 = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
			sorting << duration << endl;
			total = total + duration;
			if (i == 9) {
				auto average = 0;
				average = total / 10;
				sorting << ",,,,," << average << endl;
				total = 0;
			}
		}
	}
	sorting.close();//closing file
}