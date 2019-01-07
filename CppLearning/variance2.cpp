/*
** Date:2019-1-2
** Author£ºJason.Lee
** Brief: Choose 12 data with the smallest variance.
*/

#include<iostream>
#include<utility>
#include<cmath>
using namespace std;

float dataSets[9][12] =
{
	2.86,0.45,1.27,2.50,4.36,4.36,0.73,4.41,4.36,2.23,3.64,0.64,	  		//	1 
	4.67,10.22,8.78,10.67,7.33,0.44,9.44,10.33,7.56,8.44,8.22,4.33, 		//	2
	5.50,1.42,5.92,0.25,2.33,0.42,0.83,6.83,5.75,2.67,7.92,0.25,    		//	3
	7.33,6.33,12.83,13.33,3.17,8.17,7.50,10.83,11.83,12.50,4.67,11.33,		//	4
	8.25,2.00,1.50,6.25,12.00,4.25,7.38,2.75,9.38,3.25,6.38,8.75,			//	5
	7.42,8.00,4.58,1.17,1.25,2.17,7.00,2.08,6.75,2.00,7.75,2.92,			//	6
	6.67,8.33,20.67,15.67,11.67,27.67,19.67,18.33,30.67,9.67,25.33,25.00,   //	7
	7.60,11.40,1.60,1.00,10.60,15.60,18.60,2.60,11.40,9.40,0.20,6.80,		//	8
	0.70,3.43,1.35,2.30,0.74,2.61,1.13,2.83,3.00,3.26,1.96,0.35			//	9
};

pair<int, int> coord[12];
pair<int, int> smallestCoord[12];

float smallestVariance() {
	float avg = 0.0f;
	float vari = 0.0f;
	for (int i = 0; i < 12; i++) {
		avg += dataSets[coord[i].first][coord[i].second];
	}
	avg /= 12;
	for (int i = 0; i < 12; i++) {
		vari += pow((dataSets[coord[i].first][coord[i].second] - avg), 2);
	}
	vari /= 12;
	return vari;
}

int main() {
	bool selected[12];
	int rest[3];
	float smallest = 99999.999f;

	for (int row1 = 0; row1 < 12; row1++) {// row = 1
		fill(selected, selected + 12, false);
		selected[row1] = true;
		coord[0].first = 0;
		coord[0].second = row1;
		for (int row2 = 0; row2 < 12; row2++) {// row = 2
			if (selected[row2]) continue;
			else {
				selected[row2] = true;
				coord[1].first = 1;
				coord[1].second = row2;
			}
			for (int row3 = 0; row3 < 12; row3++) {// row = 3
				if (selected[row3]) continue;
				else {
					selected[row3] = true;
					coord[2].first = 2;
					coord[2].second = row3;
				}
				for (int row4 = 0; row4 < 12; row4++) {// row = 4
					if (selected[row4]) continue;
					else {
						selected[row4] = true;
						coord[3].first = 3;
						coord[3].second = row4;
					}
					for (int row5 = 0; row5 < 12; row5++) {// row = 5
						if (selected[row5]) continue;
						else {
							selected[row5] = true;
							coord[4].first = 4;
							coord[4].second = row5;
						}
						for (int row6 = 0; row6 < 12; row6++) {// row = 6
							if (selected[row6]) continue;
							else {
								selected[row6] = true;
								coord[5].first = 5;
								coord[5].second = row6;
							}
							for (int row7 = 0; row7 < 12; row7++) {// row = 7
								if (selected[row7]) continue;
								else {
									selected[row7] = true;
									coord[6].first = 6;
									coord[6].second = row7;
								}
								for (int row8 = 0; row8 < 12; row8++) {// row = 8
									if (selected[row8]) continue;
									else {
										selected[row8] = true;
										coord[7].first = 7;
										coord[7].second = row8;
									}
									for (int row9 = 0; row9 < 12; row9++) {// row = 9
										if (selected[row9]) continue;
										else {
											selected[row9] = true;
											coord[8].first = 8;
											coord[8].second = row9;
										}
										// the rest column.
										int index = 0;
										for (int i = 0; i < 12; i++) {
											if (selected[i] == false) {
												rest[index++] = i;
											}
										}
										// 
										for (int col1 = 0; col1 < 9; col1++) {
											coord[9].first = col1;
											coord[9].second = rest[0];
											for (int col2 = 0; col2 < 9; col2++) {
												coord[10].first = col2;
												coord[10].second = rest[1];
												for (int col3 = 0; col3 < 9; col3++) {
													coord[11].first = col3;
													coord[11].second = rest[2];
													//  
													float tempVariance = smallestVariance();
													if (tempVariance < smallest) {
														smallest = tempVariance;
														for (int k = 0; k < 12; k++) {
															smallestCoord[k] = coord[k];
														}
													}
												}
												//cout << "loop col3 is over.\n";
											}
											//cout << "loop col2 is over.\n";
										}
										//cout << "loop col is over.\n";
										selected[row9] = false;
									}// 9-for-end
									//cout << "loop row9 is over.\n";
									selected[row8] = false;
								}// 8-for-end
								//cout << "loop row8 is over.\n";
								selected[row7] = false;
							}// 7-for-end
							//cout << "loop row7 is over.\n";
							selected[row6] = false;
						}// 6-for-end
						//cout << "loop row6 is over.\n";
						selected[row5] = false;
					}// 5-for-end
					//cout << "loop row5 is over.\n";
					selected[row4] = false;
				}// 4-for-end
				//cout << "loop row4 is over.\n";
				selected[row3] = false;
			}// 3-for-end
			//cout << "loop row3 is over.\n";
			selected[row2] = false;
		}// 2-for-end
		cout << "loop row2 is over,row1 = "<<row1<<"\n";
		selected[row1] = false;
	}// 1-for-end
	cout << "loop row1 is over.\n";

	for (int i = 0; i < 12; i++) {
		cout << "(" << smallestCoord[i].first << "," << smallestCoord[i].second << ")=" << dataSets[smallestCoord[i].first][smallestCoord[i].second] << endl;
	}
	cout << "variance = " << smallest << endl;
	cin.get();
	return 0;
}