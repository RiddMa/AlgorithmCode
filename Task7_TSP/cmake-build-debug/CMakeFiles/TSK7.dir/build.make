# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Ridd\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.8194.17\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Ridd\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.8194.17\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\Courseware\Algorithm\AlgorithmFinal\Task7_TSP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\Courseware\Algorithm\AlgorithmFinal\Task7_TSP\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\TSK7.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\TSK7.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\TSK7.dir\flags.make

CMakeFiles\TSK7.dir\TSP.cpp.obj: CMakeFiles\TSK7.dir\flags.make
CMakeFiles\TSK7.dir\TSP.cpp.obj: ..\TSP.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\Courseware\Algorithm\AlgorithmFinal\Task7_TSP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TSK7.dir/TSP.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\TSK7.dir\TSP.cpp.obj /FdCMakeFiles\TSK7.dir\ /FS -c G:\Courseware\Algorithm\AlgorithmFinal\Task7_TSP\TSP.cpp
<<

CMakeFiles\TSK7.dir\TSP.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TSK7.dir/TSP.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\TSK7.dir\TSP.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\Courseware\Algorithm\AlgorithmFinal\Task7_TSP\TSP.cpp
<<

CMakeFiles\TSK7.dir\TSP.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TSK7.dir/TSP.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\TSK7.dir\TSP.cpp.s /c G:\Courseware\Algorithm\AlgorithmFinal\Task7_TSP\TSP.cpp
<<

# Object files for target TSK7
TSK7_OBJECTS = \
"CMakeFiles\TSK7.dir\TSP.cpp.obj"

# External object files for target TSK7
TSK7_EXTERNAL_OBJECTS =

TSK7.exe: CMakeFiles\TSK7.dir\TSP.cpp.obj
TSK7.exe: CMakeFiles\TSK7.dir\build.make
TSK7.exe: CMakeFiles\TSK7.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\Courseware\Algorithm\AlgorithmFinal\Task7_TSP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TSK7.exe"
	C:\Users\Ridd\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.8194.17\bin\cmake\win\bin\cmake.exe -E vs_link_exe --intdir=CMakeFiles\TSK7.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\TSK7.dir\objects1.rsp @<<
 /out:TSK7.exe /implib:TSK7.lib /pdb:G:\Courseware\Algorithm\AlgorithmFinal\Task7_TSP\cmake-build-debug\TSK7.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\TSK7.dir\build: TSK7.exe

.PHONY : CMakeFiles\TSK7.dir\build

CMakeFiles\TSK7.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TSK7.dir\cmake_clean.cmake
.PHONY : CMakeFiles\TSK7.dir\clean

CMakeFiles\TSK7.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" G:\Courseware\Algorithm\AlgorithmFinal\Task7_TSP G:\Courseware\Algorithm\AlgorithmFinal\Task7_TSP G:\Courseware\Algorithm\AlgorithmFinal\Task7_TSP\cmake-build-debug G:\Courseware\Algorithm\AlgorithmFinal\Task7_TSP\cmake-build-debug G:\Courseware\Algorithm\AlgorithmFinal\Task7_TSP\cmake-build-debug\CMakeFiles\TSK7.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\TSK7.dir\depend

