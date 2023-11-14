#include <Windows.h>
#include "Timer.h"

using namespace MyUtil;

Timer::Timer() :
	mdDeltaTime{ -1.0 },
	mfScale{ 1.0f },
	mbStopped{false},
	mdSecondsPerCount{ 0.0 },
	mllBaseTime{ 0 },
	mllPausedTime{ 0 },
	mllStopTime{ 0 },
	mllPrevTime{ 0 },
	mllCurrTime{ 0 }
{
	long long countsPerSec;
	QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(& countsPerSec));

	mdSecondsPerCount = 1.0 / countsPerSec;
}

void Timer::Start()
{
	long long currTime;
	QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currTime));

	mllBaseTime = currTime;
	mllPrevTime = currTime;
	mllStopTime = 0;
	mbStopped = false;
}

void Timer::Stop()
{
	if (!mbStopped)
	{
		long long currTime;
		QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currTime));

		mllStopTime = currTime;
		mbStopped = true;
	}
}

void Timer::Resume()
{
	if (mbStopped)
	{
		long long currTime;
		QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currTime));

		mllPausedTime += (currTime - mllStopTime);
		mllPrevTime = currTime;
		mllStopTime = 0;
		mbStopped = false;
	}
}

void Timer::Update()
{
}

float Timer::TotalTime() const
{
	return 0.0f;
}

float Timer::DeltaTime() const
{
	return 0.0f;
}

void Timer::SetScale(float scale)
{
}
