#pragma once
#include <imgui.h>
#include "../api/ExternalEndpoint.cpp"
#include "../api/ExecutorEndpoint.hpp"
#include "ComponentBuilder.cpp"

namespace TabHandlers {
    class ExternalTab {
    private:
        ExternalKeyGenerator generator;
        std::string currentKey;
        
    public:
        void Render() {
            if (UIComponents::ButtonBuilder::CreateGenerateButton("Generate Key##External")) {
                currentKey = generator.Generate();
            }
            
            if (!currentKey.empty()) {
                ImGui::Spacing();
                UIComponents::ButtonBuilder::DisplayKeyText(currentKey);
                UIComponents::ButtonBuilder::CreateCopyButton(currentKey);
            }
        }
    };
    
    class ExecutorTab {
    private:
        ExecutorKeyGenerator generator;
        std::string currentKey;
        
    public:
        void Render() {
            if (UIComponents::ButtonBuilder::CreateGenerateButton("Generate Key##Executor")) {
                currentKey = generator.Generate();
            }
            
            if (!currentKey.empty()) {
                ImGui::Spacing();
                UIComponents::ButtonBuilder::DisplayKeyText(currentKey);
                UIComponents::ButtonBuilder::CreateCopyButton(currentKey);
            }
        }
    };
}