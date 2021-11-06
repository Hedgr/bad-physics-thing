#include <iostream>

using namespace std;

float ver = 1.2;

class object_c
{
public:
	float x_pos = 5;
	float y_pos = 500;
	float y_speed = 30;
	float x_speed = 0;
};

class externals_c
{
public:
	float gravity = -9.8;
	int seconds = 0;
	float wind = 1;

	int sleep(int seconds);
};

int externals_c::sleep(int seconds)
{
	clock_t temp;
	temp = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < temp) {}
	return 0;
}

externals_c externals;
object_c object;

int on_advance() {
	object.y_speed = (object.y_speed + externals.gravity);
	object.x_speed = (object.x_speed + externals.wind);
	object.x_pos = (object.x_pos + object.x_speed);
	object.y_pos = (object.y_pos + object.y_speed);
	externals.seconds = (externals.seconds + 1);
	if (object.x_pos < 0)
	{
		object.x_pos = 0;
		object.x_speed = 0;
	}
	if (object.y_pos < 0)
	{
		object.y_pos = 0;
		object.y_speed = 0;
	}
	return 0;
}

int main() {
	cout << "version " << ver << "\n";
	cout << "gravity: " << externals.gravity << "\nwind: " << externals.wind << "\n";
	do
	{
		cout << "\nsecond: " << externals.seconds << " \nx: " << object.x_pos << "\ny: " << object.y_pos << "\nx speed: " << object.x_speed << "\ny speed: " << object.y_speed << "\n";
		on_advance();
		externals.sleep(1);
	} while (true);
}