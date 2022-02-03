#include "main.h"

namespace influenceMapping {
    bool update() { return (DxLib::ScreenFlip() != -1 && DxLib::ClearDrawScreen() != -1 && DxLib::ProcessMessage() != -1); }

    void main() {
        while (update()) {

        }
    }
}