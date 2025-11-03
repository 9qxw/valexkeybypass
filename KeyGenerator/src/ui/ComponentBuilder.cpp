#include <imgui.h>

namespace UIComponents {
    class ButtonBuilder {
    public:
        static bool CreateGenerateButton(const char* label) {
            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.2f, 0.6f, 0.2f, 1.0f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.3f, 0.7f, 0.3f, 1.0f));
            bool clicked = ImGui::Button(label, ImVec2(120, 40));
            ImGui::PopStyleColor(2);
            return clicked;
        }
        
        static void CreateCopyButton(const std::string& textToCopy) {
            ImGui::SameLine();
            if (ImGui::Button("Copy", ImVec2(80, 40))) {
                ImGui::SetClipboardText(textToCopy.c_str());
            }
        }
        
        static void DisplayKeyText(const std::string& key) {
            ImGui::Text("Key: %s", key.c_str());
        }
    };
}