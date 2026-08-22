#include "Clock.h"

//default constructor
Clock::Clock()
{
	hours = 0;
	minutes = 0;
	seconds = 0;
}

//alternative constructor
Clock::Clock(int hh, int mm, int ss)
{
	hours = hh;
	minutes = mm;
	seconds = ss;
}

void Clock::adjustClock()
{
	if (seconds >= HOUR_MIN_SEC)
	{
		int addition = seconds / HOUR_MIN_SEC;
		seconds %= HOUR_MIN_SEC;
		minutes += addition;
	}
	if (minutes >= HOUR_MIN_SEC)
	{
		int addition = minutes / HOUR_MIN_SEC;
		minutes %= HOUR_MIN_SEC;
		hours += addition;
	}
	if (hours >= HOURS_TO_WRAP)
	{
		hours %= HOURS_TO_WRAP;
	}

}

//set time to hh:mm:ss
void Clock::setClock(int hh, int mm, int ss)
{
	hours = hh;
	minutes = mm;
	seconds = ss;
}
	

//increase time by sec seconds
void Clock::incrementSeconds(int sec)
{
	seconds += sec;
	adjustClock();
}

//increase time by min minutes
void Clock::incrementMinutes(int min)
{
	minutes += min;
	adjustClock();
}

//increase time by hh hours, 
//if hours reach 24, simply wrap around to 0.
void Clock::incrementHours(int hh)
{
	hours += hh;
	adjustClock();
}

void Clock::addTime(Clock C)
{
	hours = hours + C.hours;
	minutes = minutes + C.minutes;
	seconds = seconds + C.seconds;
	adjustClock();
}

void Clock::printTime() const
{
	cout << setfill('0') << setw(2) << hours << " : " << setw(2) << minutes << setw(w) << seconds << endl;
}

int Clock::compareTime(Clock C) const
{
	//algorithm
	if (hours < C.hours)
	{
		return -1;
	}
	if (hours > C.hours)
	{
		return 1;
	}
	if (hours == C.hours)
	{
		
	}
}