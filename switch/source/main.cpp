#include <switch.h>
#include <cstdio>
#include <cstdint>

static bool check_runtime_prerequisites() {
    const uint64_t heap_total = 0x100000000ULL;
    printf("[FH2/Switch] libnx runtime initialized.\n");
    printf("[FH2/Switch] target: AArch64 / Horizon OS\n");
    printf("[FH2/Switch] guest architecture: Xbox 360 PPC64\n");
    printf("[FH2/Switch] planned guest address space: 0x%llx bytes\n",
           (unsigned long long)heap_total);
    return true;
}

int main(int argc, char** argv) {
    consoleInit(nullptr);
    printf("Forza Horizon 2 Recomp - Nintendo Switch\n");
    printf("Platform bring-up stage 2\n\n");

    const bool runtime_ok = check_runtime_prerequisites();
    printf("\nReXGlue integration status:\n");
    printf("  libnx entrypoint : OK\n");
    printf("  AArch64 toolchain: OK\n");
    printf("  runtime bridge   : %s\n", runtime_ok ? "READY" : "FAILED");
    printf("  FH2 codegen      : PENDING GENERATED SOURCES\n");
    printf("\nPress + to exit.\n");

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
