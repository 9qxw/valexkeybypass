#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
#include "TabController.hpp"

class ApplicationWindow {
private:
    GLFWwindow* window;
    TabHandlers::ExternalTab externalTab;
    TabHandlers::ExecutorTab executorTab;
    int currentTab = 0;
    
    void InitializeWindow() {
        glfwInit();
        window = glfwCreateWindow(600, 400, "Key Generator", nullptr, nullptr);
        glfwMakeContextCurrent(window);
        
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 130");
        
        // Minimalistic style
        ImGui::StyleColorsDark();
        ImGuiStyle& style = ImGui::GetStyle();
        style.WindowRounding = 5.0f;
        style.FrameRounding = 3.0f;
        style.Colors[ImGuiCol_Tab] = ImVec4(0.2f, 0.2f, 0.2f, 1.0f);
        style.Colors[ImGuiCol_TabActive] = ImVec4(0.3f, 0.3f, 0.3f, 1.0f);
    }
    
public:
    ApplicationWindow() : window(nullptr) {}
    
    bool Setup() {
        InitializeWindow();
        return window != nullptr;
    }
    
    void Run() {
        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents();
            
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();
            
            // Main window
            ImGui::SetNextWindowPos(ImVec2(0, 0));
            ImGui::SetNextWindowSize(ImVec2(600, 400));
            ImGui::Begin("Key Generator", nullptr, 
                        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | 
                        ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);
            
            // Tab bar
            if (ImGui::BeginTabBar("MainTabs")) {
                if (ImGui::BeginTabItem("External")) {
                    externalTab.Render();
                    ImGui::EndTabItem();
                }
                
                if (ImGui::BeginTabItem("Executor")) {
                    executorTab.Render();
                    ImGui::EndTabItem();
                }
                
                ImGui::EndTabBar();
            }
            
            ImGui::End();
            
            // Rendering
            ImGui::Render();
            int display_w, display_h;
            glfwGetFramebufferSize(window, &display_w, &display_h);
            glViewport(0, 0, display_w, display_h);
            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            
            glfwSwapBuffers(window);
        }
    }
    
    ~ApplicationWindow() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
        glfwDestroyWindow(window);
        glfwTerminate();
    }
};