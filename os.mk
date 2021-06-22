##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=os
ConfigurationName      :=Debug
WorkspacePath          :=/media/blaze/01D50741D2405DC0/os
ProjectPath            :=/media/blaze/01D50741D2405DC0/os/os
IntermediateDirectory  :=
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Blaze
Date                   :=03/06/21
CodeLitePath           :=/home/blaze/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="os.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS := -std=c++14 -Wall -g -O0 -W -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/disk_clook.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d  || $(MakeDirCommand) 


$(IntermediateDirectory)/.d:
	@test -d  || $(MakeDirCommand) 

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/disk_clook.cpp$(ObjectSuffix): disk_clook.cpp $(IntermediateDirectory)/disk_clook.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/blaze/01D50741D2405DC0/os/os/disk_clook.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/disk_clook.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/disk_clook.cpp$(DependSuffix): disk_clook.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/disk_clook.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/disk_clook.cpp$(DependSuffix) -MM disk_clook.cpp

$(IntermediateDirectory)/disk_clook.cpp$(PreprocessSuffix): disk_clook.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/disk_clook.cpp$(PreprocessSuffix) disk_clook.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) *$(ObjectSuffix)
	$(RM) *$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) "../.build-debug/os"


