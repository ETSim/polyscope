// Copyright 2017-2023, Nicholas Sharp and the Polyscope contributors. https://polyscope.run

#include "polyscope/imgui_config.h"
#include <polyscope/polyscope.h>

namespace polyscope {


// Forward declare compressed binary font functions
namespace render {
unsigned int getCousineRegularCompressedSize();
const unsigned int* getCousineRegularCompressedData();
unsigned int getLatoRegularCompressedSize();
const unsigned int* getLatoRegularCompressedData();
} // namespace render

void configureImGuiStyle() {

  ImGuiStyle* style = &ImGui::GetStyle();
  *style = ImGuiStyle(); // apply the default style as a starting point

  // Style
  style->WindowRounding = 1;
  style->FrameRounding = 1;
  style->FramePadding.y = 4;
  style->ScrollbarRounding = 1;
  style->ScrollbarSize = 20;
  style->ScaleAllSizes(options::uiScale);


  // Colors
  ImVec4* colors = style->Colors;
  colors[ImGuiCol_Text] = ImVec4(0.90f, 0.90f, 0.90f, 1.00f);
  colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
  colors[ImGuiCol_WindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.70f);
  colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
  colors[ImGuiCol_PopupBg] = ImVec4(0.11f, 0.11f, 0.14f, 0.92f);
  colors[ImGuiCol_Border] = ImVec4(0.50f, 0.50f, 0.50f, 0.50f);
  colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
  colors[ImGuiCol_FrameBg] = ImVec4(0.63f, 0.63f, 0.63f, 0.39f);
  colors[ImGuiCol_FrameBgHovered] = ImVec4(0.47f, 0.69f, 0.59f, 0.40f);
  colors[ImGuiCol_FrameBgActive] = ImVec4(0.41f, 0.64f, 0.53f, 0.69f);
  colors[ImGuiCol_TitleBg] = ImVec4(0.27f, 0.54f, 0.42f, 0.83f);
  colors[ImGuiCol_TitleBgActive] = ImVec4(0.32f, 0.63f, 0.49f, 0.87f);
  colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.27f, 0.54f, 0.42f, 0.83f);
  colors[ImGuiCol_MenuBarBg] = ImVec4(0.40f, 0.55f, 0.48f, 0.80f);
  colors[ImGuiCol_ScrollbarBg] = ImVec4(0.63f, 0.63f, 0.63f, 0.39f);
  colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.00f, 0.00f, 0.00f, 0.30f);
  colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.80f, 0.62f, 0.40f);
  colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.39f, 0.80f, 0.61f, 0.60f);
  colors[ImGuiCol_CheckMark] = ImVec4(0.90f, 0.90f, 0.90f, 0.50f);
  colors[ImGuiCol_SliderGrab] = ImVec4(1.00f, 1.00f, 1.00f, 0.30f);
  colors[ImGuiCol_SliderGrabActive] = ImVec4(0.39f, 0.80f, 0.61f, 0.60f);
  colors[ImGuiCol_Button] = ImVec4(0.35f, 0.61f, 0.49f, 0.62f);
  colors[ImGuiCol_ButtonHovered] = ImVec4(0.40f, 0.71f, 0.57f, 0.79f);
  colors[ImGuiCol_ButtonActive] = ImVec4(0.46f, 0.80f, 0.64f, 1.00f);
  colors[ImGuiCol_Header] = ImVec4(0.40f, 0.90f, 0.67f, 0.45f);
  colors[ImGuiCol_HeaderHovered] = ImVec4(0.45f, 0.90f, 0.69f, 0.80f);
  colors[ImGuiCol_HeaderActive] = ImVec4(0.53f, 0.87f, 0.71f, 0.80f);
  colors[ImGuiCol_Separator] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
  colors[ImGuiCol_SeparatorHovered] = ImVec4(0.60f, 0.70f, 0.66f, 1.00f);
  colors[ImGuiCol_SeparatorActive] = ImVec4(0.70f, 0.90f, 0.81f, 1.00f);
  colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.16f);
  colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.78f, 1.00f, 0.90f, 0.60f);
  colors[ImGuiCol_ResizeGripActive] = ImVec4(0.78f, 1.00f, 0.90f, 0.90f);
  colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
  colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
  colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
  colors[ImGuiCol_TextSelectedBg] = ImVec4(0.00f, 0.00f, 1.00f, 0.35f);
  colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);
  colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
  colors[ImGuiCol_Tab] = ImVec4(0.27f, 0.54f, 0.42f, 0.83f);
  colors[ImGuiCol_TabHovered] = ImVec4(0.34f, 0.68f, 0.53f, 0.83f);
  colors[ImGuiCol_TabSelected] = ImVec4(0.38f, 0.76f, 0.58f, 0.83f);
}


std::tuple<ImFontAtlas*, ImFont*, ImFont*> prepareImGuiFonts() {

  ImGuiIO& io = ImGui::GetIO();

  ImVec2 windowSize{static_cast<float>(view::windowWidth), static_cast<float>(view::windowHeight)};
  ImVec2 bufferSize{static_cast<float>(view::bufferWidth), static_cast<float>(view::bufferHeight)};
  ImVec2 imguiCoordScale = {bufferSize.x / windowSize.x, bufferSize.y / windowSize.y};

  // outputs
  ImFontAtlas* fontAtlas = nullptr; // right now this is unused by the caller, but I don't want to change
                                    // this callback signature until I'm more confident about how this
                                    // should work. (And it might be changing in an upcoming imgui version)
  ImFont* regularFont;
  ImFont* monoFont;

  float fontSize = 16.0 * options::uiScale;
  fontSize = std::max(1.0f, std::roundf(fontSize));

  { // add regular font
    ImFontConfig config;
    config.RasterizerDensity = std::max(imguiCoordScale.x, imguiCoordScale.y);
    regularFont = io.Fonts->AddFontFromMemoryCompressedTTF(render::getLatoRegularCompressedData(),
                                                           render::getLatoRegularCompressedSize(),
                                                           options::uiScale * 18.0f, &config);
  }

  { // add mono font
    ImFontConfig config;
    config.RasterizerDensity = std::max(imguiCoordScale.x, imguiCoordScale.y);
    monoFont = io.Fonts->AddFontFromMemoryCompressedTTF(render::getCousineRegularCompressedData(),
                                                        render::getCousineRegularCompressedSize(),
                                                        options::uiScale * 16.0f, &config);
  }

  // io.Fonts->AddFontFromFileTTF("test-font-name.ttf", 16);

  io.Fonts->Build();

  return std::tuple<ImFontAtlas*, ImFont*, ImFont*>{fontAtlas, regularFont, monoFont};
}

} // namespace polyscope
