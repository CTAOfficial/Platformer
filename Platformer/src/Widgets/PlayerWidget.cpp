#include "PlayerWidget.h"
#include <format>
#include <imgui/imgui.h>

void PlayerWidget::OnDraw()
{
	std::string playerText = std::format("Player: {}", (void*)target);
	ImGui::Text(playerText.c_str());


	std::string debugText = "Debug Mode" + std::to_string(target->DebugMode);
	ImGui::Checkbox("Debug Mode", &target->DebugMode);
}
