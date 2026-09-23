#include <switch.h>
#include <cstdio>

int main(int argc, char** argv) {
    consoleInit(nullptr);
    printf("Forza Horizon 2 Recomp - Nintendo Switch bootstrap\\n");
    printf("devkitA64/libnx target is working.\\n\\n");
    printf("Next: integrate ReXGlue runtime and recompiled FH2 modules.\\n");
    printf("Press + to exit.\\n");

    PadState pad;
    padConfigureInput(1, HidNpadStyleSet_NpadStandard);
    padInitializeDefault(&pad);

    while (appletMainLoop()) {
        padUpdate(&pad);
        if (padGetButtonsDown(&pad) & HidNpadButton_Plus) break;
        consoleUpdate(nullptr);
    }
    consoleExit(nullptr);
    return 0;
}
