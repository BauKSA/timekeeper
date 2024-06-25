#pragma once
#include<chrono>

struct Clock {
	int hours;
	int minutes;
	int seconds;
	int milliseconds;
};

class Timekeeper {
private:
	std::chrono::time_point<std::chrono::steady_clock> init_point;
	std::chrono::time_point<std::chrono::steady_clock> actual_point;
	std::chrono::steady_clock::duration temp;
	bool paused;
	bool running;
	int lap_count;
public:
	Timekeeper() :
		init_point(std::chrono::steady_clock::time_point()) {
		actual_point = init_point;
		paused = false;
		temp = std::chrono::steady_clock::duration::zero();
		running = false;
		lap_count = 0;
	};

	Clock format_clock() const;
	void init_clock();
	void show_time() const;
	void start();
	void run();
	void pause();
	void stop();
	void lap() { lap_count++; }
};