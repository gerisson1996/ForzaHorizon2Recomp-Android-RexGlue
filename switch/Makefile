ifeq ($(strip $(DEVKITPRO)),)
$(error "Please set DEVKITPRO in your environment")
endif

TOPDIR := $(CURDIR)
include $(DEVKITPRO)/libnx/switch_rules

TARGET := ForzaHorizon2Recomp-Switch
BUILD := build
SOURCES := source
INCLUDES := include
APP_TITLE := Forza Horizon 2 Recomp - Switch bootstrap
APP_AUTHOR := gerisson1996 / ReXGlue port
APP_VERSION := 0.0.1

ARCH := -march=armv8-a+crc+crypto -mtune=cortex-a57 -mtp=soft -fPIE
CFLAGS := -g -Wall -O2 -ffunction-sections $(ARCH) $(DEFINES) -I$(DEVKITPRO)/libnx/include
CXXFLAGS := $(CFLAGS) -fno-rtti -std=gnu++20
ASFLAGS := -g $(ARCH)
LDFLAGS = -specs=$(DEVKITPRO)/libnx/switch.specs -g $(ARCH) -L$(DEVKITPRO)/libnx/lib -Wl,-Map,$(notdir $*.map)

LIBS := -lnx
LIBDIRS := $(DEVKITPRO)/libnx

ifneq ($(BUILD),$(notdir $(CURDIR)))
export OUTPUT := $(CURDIR)/$(TARGET)
export TOPDIR := $(CURDIR)
export VPATH := $(foreach dir,$(SOURCES),$(CURDIR)/$(dir))
export DEPSDIR := $(CURDIR)/$(BUILD)
CFILES := $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c)))
CPPFILES := $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp)))
SFILES := $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.s)))
export LD := $(CXX)
export OFILES := $(CPPFILES:.cpp=.o) $(CFILES:.c=.o) $(SFILES:.s=.o)
export INCLUDE := $(foreach dir,$(INCLUDES),-I$(CURDIR)/$(dir)) -I$(DEVKITPRO)/libnx/include -I$(CURDIR)/$(BUILD)
export LIBPATHS := -L$(DEVKITPRO)/libnx/lib
.PHONY: all clean
all: $(BUILD)
$(BUILD):
	@[ -d $@ ] || mkdir -p $@
	@$(MAKE) --no-print-directory -C $(BUILD) -f $(CURDIR)/Makefile
clean:
	@rm -rf $(BUILD) $(TARGET).nro $(TARGET).elf $(TARGET).nacp
else
DEPENDS := $(OFILES:.o=.d)
$(OUTPUT).nro: $(OUTPUT).elf
$(OUTPUT).elf: $(OFILES)
-include $(DEPENDS)
endif
