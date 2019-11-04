#pragma once
#include <cmath>

class Views
{
public:
	int id, grade, average, open[7], close[7];
	bool capable = false;
	float coords[2];

	int Open(int i) { return open[i]; }
	int Close(int i) { return close[i]; }
	float Coords(int i) { return coords[i]; }
	void SetId(int i) { id = i; }
	void SetGrade(int i) { grade = i; }
	void SetAverage(int i) { average = i; }
	void SetOpen(int i, int v) { open[i] = v; }
	void SetClose(int i, int v) { close[i] = v; }
	void SetCoords(int i, float x) { coords[i] = x; }

	float Distance(Views* v) {	//упокоцислос апостасгс
		float x1 = this->Coords(0);
		float y1 = this->Coords(1);
		float x2 = v->Coords(0);
		float y2 = v->Coords(1);
		return (float)sqrt(pow((x1 + x2), 2.0) + pow((y1 + y2), 2.0));
	}

};

