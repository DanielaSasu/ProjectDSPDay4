#pragma once

#include "../AudioEngine/SignalGenerator.h"

namespace AudioEngineWrapper
{
	public enum class SignalType
	{
		Sin,
		Dirac,
		Square,
		Sum
	};

	public ref class SignalGenerator
	{
	public:
		SignalGenerator(double time, unsigned int sampleRate, double freq);

		array<double>^ Generate(SignalType type);

		property int SampleRate {
			int get();
		}

		~SignalGenerator();

	internal:
		std::vector<double> GetBuffer();

	private:
		AudioEngine::SignalGenerator* m_generator;
	};
}
