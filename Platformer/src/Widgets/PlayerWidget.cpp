#include "PlayerWidget.h"
#include <format>
#include <imgui/imgui.h>

void PlayerWidget::OnDraw()
{
	std::string playerText = std::format("Player: {}", (void*)target);
	ImGui::Text(playerText.c_str());

	std::string debugText = "Debug Mode" + std::to_string(target->DebugMode);
	ImGui::Checkbox("Debug Mode", &target->DebugMode);

	// Position
	ImGui::Text("Position: ");
	if (ImGui::IsItemHovered()) {
		ImGui::BeginTooltip();
		ImGui::Text("The position of the object.");
		ImGui::EndTooltip();
	}
	ImGui::SameLine();
	float* positions[2] = { &target->position.X, &target->position.Y };
	ImGui::InputFloat2("##position", *positions);

	// Speed
	ImGui::Text("Speed: ");
	if (ImGui::IsItemHovered()) {
		ImGui::BeginTooltip();
		ImGui::Text("The speed of the object.");
		ImGui::EndTooltip();
	}
	ImGui::SameLine();
	ImGui::InputFloat("##speed", &target->speed);

	// Gravity
	ImGui::Text("Gravity: ");
	if (ImGui::IsItemHovered()) {
		ImGui::BeginTooltip();
		ImGui::Text("The gravity of the object.");
		ImGui::EndTooltip();
	}
	ImGui::SameLine();
	ImGui::InputFloat("##gravity", &target->gravity);

	// Collision
	ImGui::Text("Last Collision: ");
	if (ImGui::IsItemHovered()) {
		ImGui::BeginTooltip();
		ImGui::Text("The gravity of the object.");
		ImGui::EndTooltip();
	}
	float* collisions[4] = { &target->collision.x, &target->collision.y, &target->collision.w, &target->collision.h };
	ImGui::InputFloat4("##collision", *collisions);
}
