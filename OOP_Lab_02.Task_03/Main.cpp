#include<iostream>

using namespace std;

class Time {
private:
	int *hour;
	int *minute;
	int *second;
public:
	Time();
	Time(int hour, int minute, int second);
	Time(const Time &one);
	~Time();

	void SetHour(int thour);
	void SetMinute(int tminute);
	void SetSecond(int tsecond);
	int GetHour();
	int GetMinute();
	int GetSecond();
};

Time::Time()
{
	this->hour = new int(0);
	this->minute = new int(0);
	this->second = new int(0);
}

Time::Time(int hour, int minute, int second)
{
	this->hour = new int(hour);
	this->minute = new int(minute);
	this->second = new int(second);
}

Time::Time(const Time &one)
{
	hour = new int(*one.hour);
	minute = new int(*one.minute);
	second = new int(*one.second);
}

Time::~Time()
{
	delete hour;
	delete minute;
	delete second;
}

void Time::SetHour(int thour)
{
	if (thour < 0 || thour > 23)
	{
		throw "Некоректне значення годин";
	}

	*hour = thour;
}

void Time::SetMinute(int tminute)
{
	if (tminute < 0 || tminute > 59)
	{
		throw "Некоректне значення хвилин";
	}

	*minute = tminute;
}

void Time::SetSecond(int tsecond)
{
	if (tsecond < 0 || tsecond > 59)
	{
		throw "Некоректне значення секунд";
	}

	*second = tsecond;
}

int Time::GetHour()
{
	return *hour;
}

int Time::GetMinute()
{
	return *minute;
}

int Time::GetSecond()
{
	return *second;
}

int main(void)
{
	Time* one = new Time;
	int hour = 0, minute = 0, second = 0;
	cout << "=============" << endl;
	cout << "Enter the time:" << endl;
	cout << "Hour: ";
	cin >> hour;
	one->SetHour(hour);
	cout << "Minute: ";
	cin >> minute;
	one->SetMinute(minute);
	cout << "Second: ";
	cin >> second;
	one->SetSecond(second);
	cout << "=============" << endl;
	cout << endl << "Time:" << endl;
	cout << endl << "-----------------------------" << endl;
	cout << one->GetHour() << " hour " << one->GetMinute() << " minute " << one->GetSecond() << " second" << endl;
	cout << "-----------------------------" << endl << endl;
	cout << endl << "---------" << endl;
	cout << one->GetHour() << ":" << one->GetMinute() << ":" << one->GetSecond() << endl;
	cout << "---------" << endl << endl;
	system("pause");
	return 0;
}