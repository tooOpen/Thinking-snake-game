################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include Classes/subdir.mk
-include subdir.mk
-include objects.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs
-include makefile.func

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: pre-build main-build

# Main-build Target
main-build: hellocpp secondary-outputs

# Tool invocations
hellocpp: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: C++ Linker'
	$(CXX) -o"hellocpp" $(OBJS) $(USER_OBJS) $(LIBS) -L"D:\cocos2d-x-3.5-tizen\cocos2d-x-3.5-tizen\projects\AfterEarth\cocos2d\build\tizen\Debug" -L"D:\cocos2d-x-3.5-tizen\cocos2d-x-3.5-tizen\projects\AfterEarth\cocos2d\external\chipmunk\prebuilt\tizen\arm" -L"D:\cocos2d-x-3.5-tizen\cocos2d-x-3.5-tizen\projects\AfterEarth\cocos2d\external\jpeg\prebuilt\tizen\arm" -L"D:\cocos2d-x-3.5-tizen\cocos2d-x-3.5-tizen\projects\AfterEarth\cocos2d\external\png\prebuilt\tizen\arm" -L"D:\cocos2d-x-3.5-tizen\cocos2d-x-3.5-tizen\projects\AfterEarth\cocos2d\external\tiff\prebuilt\tizen\arm" -L"D:\cocos2d-x-3.5-tizen\cocos2d-x-3.5-tizen\projects\AfterEarth\cocos2d\external\webp\prebuilt\tizen\arm" -L"D:\cocos2d-x-3.5-tizen\cocos2d-x-3.5-tizen\projects\AfterEarth\cocos2d\external\websockets\prebuilt\tizen\arm" -static-libstdc++ $(TC_LINKER_MISC) $(RS_LINKER_MISC) -pie -lpthread -Xlinker -rpath="/home/developer/sdk_tools/lib" --sysroot="$(SBI_SYSROOT)" -Xlinker --version-script=$(PROJ_PATH)/.exportMap -L"$(SBI_SYSROOT)/usr/lib" $(RS_LIBRARIES) -Xlinker -rpath="/opt/usr/apps/$(APPID)/lib" -Werror-implicit-function-declaration
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(AST)$(CC_DEPS)$(C++_DEPS)$(MO_FILES)$(EXECUTABLES)$(C_UPPER_DEPS)$(CXX_DEPS)$(OBJS)$(FNMAP)$(EDJ_FILES)$(CPP_DEPS)$(C_DEPS) hellocpp
	-@echo ' '

pre-build:
	-../copy_resource.sh
	-@echo ' '

secondary-outputs: $(MO_FILES) $(EDJ_FILES)

.PHONY: all clean dependents
.SECONDARY: main-build pre-build

-include ../makefile.targets
