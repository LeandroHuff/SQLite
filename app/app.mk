##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=app
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/leandro/Projects/SQLite/app
ProjectPath            :=/home/leandro/Projects/SQLite/app
IntermediateDirectory  :=./build-$(ConfigurationName)/
OutDir                 :=./build-$(ConfigurationName)/
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=leandro
Date                   :=12/03/2022
CodeLitePath           :=/home/leandro/.codelite
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
OutputFile             :=./build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  -lpthread -ldl -lm
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)./ $(IncludeSwitch)/usr/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)sqlite3 
ArLibs                 :=  "libsqlite3.a" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/lib/x86_64-linux-gnu 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g0 -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g0 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=./build-$(ConfigurationName)//up_sql_src_c_sql3.c$(ObjectSuffix) ./build-$(ConfigurationName)//main.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ./build-$(ConfigurationName)//.d $(Objects) 
	@mkdir -p "./build-$(ConfigurationName)/"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "./build-$(ConfigurationName)/"
	@mkdir -p ""./build-$(ConfigurationName)/bin""

./build-$(ConfigurationName)//.d:
	@mkdir -p "./build-$(ConfigurationName)/"

PreBuild:


##
## Objects
##
./build-$(ConfigurationName)//up_sql_src_c_sql3.c$(ObjectSuffix): ../sql/src/c/sql3.c ./build-$(ConfigurationName)//up_sql_src_c_sql3.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/leandro/Projects/SQLite/sql/src/c/sql3.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_sql_src_c_sql3.c$(ObjectSuffix) $(IncludePath)
./build-$(ConfigurationName)//up_sql_src_c_sql3.c$(DependSuffix): ../sql/src/c/sql3.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT./build-$(ConfigurationName)//up_sql_src_c_sql3.c$(ObjectSuffix) -MF./build-$(ConfigurationName)//up_sql_src_c_sql3.c$(DependSuffix) -MM ../sql/src/c/sql3.c

./build-$(ConfigurationName)//up_sql_src_c_sql3.c$(PreprocessSuffix): ../sql/src/c/sql3.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ./build-$(ConfigurationName)//up_sql_src_c_sql3.c$(PreprocessSuffix) ../sql/src/c/sql3.c

./build-$(ConfigurationName)//main.c$(ObjectSuffix): main.c ./build-$(ConfigurationName)//main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/leandro/Projects/SQLite/app/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
./build-$(ConfigurationName)//main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT./build-$(ConfigurationName)//main.c$(ObjectSuffix) -MF./build-$(ConfigurationName)//main.c$(DependSuffix) -MM main.c

./build-$(ConfigurationName)//main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ./build-$(ConfigurationName)//main.c$(PreprocessSuffix) main.c


-include ./build-$(ConfigurationName)///*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


