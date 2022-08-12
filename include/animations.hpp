#pragma once

#ifndef ANIMATION_IMGUITWEAKER
#define ANIMATION_IMGUITWEAKER

#include "easings.hpp"

#include <algorithm>
#include <unordered_map>

namespace ImAnim 
{
	/*
	* Easing functions are only available when the value type is float. 
	* Also, to use Easing, the minimum and maximum values must be 0.f and 1.f, respectively.
	*/
	template <class T = const char*, class B = float>
	class Animator {
	public:
		B Value(T indentifier, bool state, B min, B max, B speed) {
			auto value = storage.find(indentifier);

			if (value == storage.end()) {
				storage.insert({ indentifier, min });
				value = storage.find(indentifier);
			}

			const float frameRateSpeed = speed * (1.f - ImGui::GetIO().DeltaTime);

			state ? value->second += frameRateSpeed : value->second -= frameRateSpeed;

			value->second = std::clamp(value->second, min, max);

			return value->second;
		}

		B ValueInSine(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::InSine(Value(indentifier, state, min, max, speed));
		}
		B ValueOutSine(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::OutSine(Value(indentifier, state, min, max, speed));
		}
		B ValueInOutSine(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::InOutSine(Value(indentifier, state, min, max, speed));
		}
		B ValueInQuad(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::InQuad(Value(indentifier, state, min, max, speed));
		}
		B ValueOutQuad(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::OutQuad(Value(indentifier, state, min, max, speed));
		}
		B ValueInOutQuad(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::InOutQuad(Value(indentifier, state, min, max, speed));
		}
		B ValueInCubic(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::InCubic(Value(indentifier, state, min, max, speed));
		}
		B ValueOutCubic(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::OutCubic(Value(indentifier, state, min, max, speed));
		}
		B ValueInOutCubic(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::InOutCubic(Value(indentifier, state, min, max, speed));
		}
		B ValueInQuart(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::InQuart(Value(indentifier, state, min, max, speed));
		}
		B ValueOutQuart(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::OutQuart(Value(indentifier, state, min, max, speed));
		}
		B ValueInOutQuart(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::InOutQuart(Value(indentifier, state, min, max, speed));
		}
		B ValueInQuint(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::InQuint(Value(indentifier, state, min, max, speed));
		}
		B ValueOutQuint(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::OutQuint(Value(indentifier, state, min, max, speed));
		}
		B ValueInOutQuint(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::InOutQuint(Value(indentifier, state, min, max, speed));
		}
		B ValueInExpo(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::InExpo(Value(indentifier, state, min, max, speed));
		}
		B ValueOutExpo(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::OutExpo(Value(indentifier, state, min, max, speed));
		}
		B ValueInOutExpo(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::InOutExpo(Value(indentifier, state, min, max, speed));
		}
		B ValueInCirc(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::InCirc(Value(indentifier, state, min, max, speed));
		}
		B ValueOutCirc(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::OutCirc(Value(indentifier, state, min, max, speed));
		}
		B ValueInOutCirc(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::InOutCirc(Value(indentifier, state, min, max, speed));
		}
		B ValueInBack(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::InBack(Value(indentifier, state, min, max, speed));
		}
		B ValueOutBack(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::OutBack(Value(indentifier, state, min, max, speed));
		}
		B ValueInElastic(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::InElastic(Value(indentifier, state, min, max, speed));
		}
		B ValueOutElastic(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::OutElastic(Value(indentifier, state, min, max, speed));
		}
		B ValueInOutElastic(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::InOutElastic(Value(indentifier, state, min, max, speed));
		}
		B ValueInBounce(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::InBounce(Value(indentifier, state, min, max, speed));
		}
		B ValueOutBounce(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::OutBounce(Value(indentifier, state, min, max, speed));
		}
		B ValueInOutBounce(T indentifier, bool state, B min, B max, B speed) {
			return ImEasings::InOutBounce(Value(indentifier, state, min, max, speed));
		}
	private:
		std::unordered_map<T, B> storage;
	};
}

#endif