MACRO (TR_DETECT_DEPENDENCY arg)
    MESSAGE (STATUS "Detecting ${arg}...")
    FIND_PACKAGE (${arg} REQUIRED)
    IF (DEPENDENCY_FOUND)
        MESSAGE (STATUS "Found ${arg}!")
        INCLUDE_DIRECTORIES(${${arg}_INCLUDE_DIR})
    ELSE (DEPENDENCY_FOUND)
        MESSAGE ("${arg} not found!")
    ENDIF (DEPENDENCY_FOUND)
ENDMACRO (TR_DETECT_DEPENDENCY arg)

MACRO (TR_TARGET_OPTIONS arg)
    SET_TARGET_PROPERTIES (
        ${arg}
        PROPERTIES
        DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
		RELWITHDEBINFO_POSTFIX ${CMAKE_RELWITHDEBINFO_POSTFIX}
    )
    IF (MSVC_IDE)
        TARGET_COMPILE_OPTIONS (
            ${arg} PRIVATE
        	/nologo /GR
            $<$<CONFIG:Debug>:/Od /Ob0 /RTC1 /D_DEBUG /Zi>
			$<$<CONFIG:RelWithDebInfo>:/MD /Zi /O2 /Ob1 /D>            
			$<$<CONFIG:Release>:/MT /O2 /Ob2 /MD>			
        )
    ENDIF (MSVC_IDE)
ENDMACRO (TR_TARGET_OPTIONS arg)

MACRO(READ_GCC_VERSION)
    IF (CMAKE_COMPILER_IS_GNUCC)
        EXECUTE_PROCESS(COMMAND ${CMAKE_C_COMPILER} -dumpversion
			OUTPUT_VARIABLE GCC_VERSION)
		STRING(REGEX MATCHALL "[0-9]+" GCC_VERSION_COMPONENTS ${GCC_VERSION})
	    LIST(GET GCC_VERSION_COMPONENTS 0 GCC_MAJOR)
		LIST(GET GCC_VERSION_COMPONENTS 1 GCC_MINOR)
	ENDIF()
ENDMACRO(READ_GCC_VERSION)
