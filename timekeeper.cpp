#include<iostream>
#include<iomanip>
#include<Windows.h>

#include "timekeeper.h"
#include "utils.h"

Clock Timekeeper::format_clock() const {
	std::chrono::steady_clock::duration elapsed = actual_point - init_point + temp;
	auto _hours = std::chrono::duration_cast<std::chrono::hours>(elapsed);
	auto _minutes = std::chrono::duration_cast<std::chrono::minutes>(elapsed) - _hours;
	auto _seconds = std::chrono::duration_cast<std::chrono::seconds>(elapsed) - _hours - _minutes;
	auto _milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed) - _hours - _minutes - _seconds;

	Clock clock{};
	clock.hours = _hours.count();
	clock.minutes = _minutes.count();
	clock.seconds = _seconds.count();
	clock.milliseconds = _milliseconds.count();

	return clock;
}

void Timekeeper::init_clock() {
	clear_screen(lap_count + 1);
	lap_count = 0;

	gotoxy(0, 0);
	std::cout << "00:00:00:000";
}

void Timekeeper::show_time() const {
	Clock clock = format_clock();
	gotoxy(0, lap_count);
	std::cout <<
		std::setfill('0') << std::setw(2) << clock.hours << ":" <<
		std::setfill('0') << std::setw(2) << clock.minutes << ":" <<
		std::setfill('0') << std::setw(2) << clock.seconds << ":" <<
		std::setfill('0') << std::setw(3) << clock.milliseconds;
}

void Timekeeper::start() {
	init_point = std::chrono::steady_clock::now();
	if (!running) init_clock();
	running = true;
}

void Timekeeper::run() {
	if (paused) return;
	actual_point = std::chrono::steady_clock::now();
	show_time();
}

void Timekeeper::pause() {
	if(paused){
		paused = false;
		init_point = std::chrono::steady_clock::now();
	} else {
		paused = true;
		temp += actual_point - init_point;
	}
}

void Timekeeper::stop() {
	temp = std::chrono::steady_clock::duration::zero();
	running = false;
}