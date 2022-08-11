#pragma once

#ifndef SHUGAR_IMGUITWEAKS
#define SHUGAR_IMGUITWEAKS

#include <imgui.h>

#include <functional>
using callback_t = std::function<void()>;

namespace ImSugar
{
	__forceinline bool Button(const char* label, ImVec2 size, callback_t callback = nullptr)
	{
		if (ImGui::Button(label, size))
			callback();
	}

	__forceinline void Font(ImFont* font, callback_t callback = nullptr)
	{
		ImGui::PushFont(font);
		{
			callback();
		}
		ImGui::PopFont();
	}

	__forceinline void Group(callback_t callback = nullptr)
	{
		ImGui::BeginGroup();
		{
			callback();
		}
		ImGui::EndGroup();
	}

	__forceinline void Child(const char* label, ImVec2 size, callback_t callback, bool border = false, ImGuiWindowFlags flags = 0)
	{
		ImGui::BeginChild(label, size, border, flags);
		{
			callback();
		}
		ImGui::EndChild();
	}

	__forceinline void Window(const char* name, bool* p_open = NULL, ImGuiWindowFlags flags = 0, callback_t callback = nullptr)
	{
		ImGui::Begin(name, p_open, flags);
		{
			callback();
		}
		ImGui::End();
	}
}

#endif