PROJECT( HAtaGo )
CMAKE_MINIMUM_REQUIRED( VERSION 2.8)

FIND_PROGRAM( GHC ghc )
IF( NOT GHC )
	MESSAGE( FATAL_ERROR "Cannot find GHC" )
ELSE( NOT GHC)
    MESSAGE( STATUS "GHC found" )
ENDIF( NOT GHC )

set( hatago_sources
        main.hs
   )
set( hatago_main ${HAtaGo_SOURCE_DIR}/main.hs)

set( GHC_FLAGS
    --make ${hatago_main}
    -i${HAtaGo_SOURCE_DIR}
    -o HAtaGo${CMAKE_EXECUTABLE_SUFFIX}
    -odir ${CMAKE_CURRENT_BINARY_DIR}
    -hidir ${CMAKE_CURRENT_BINARY_DIR}
    -O3
    -threaded
    -W)
 
set(GHC_FLAGS ${haskell_compiler_flags_cmn} ${GHC_FLAGS})
 
add_custom_command(OUTPUT "${EXECUTABLE_OUTPUT_PATH}/HAtaGo${CMAKE_EXECUTABLE_SUFFIX}"
   	COMMAND "${GHC}"
   	ARGS ${GHC_FLAGS}
   	MAIN_DEPENDENCY ${hatago_main}
   	DEPENDS ${hatago_sources}
   	)

add_custom_target(HAtaGo ALL DEPENDS "${EXECUTABLE_OUTPUT_PATH}/HAtaGo${CMAKE_EXECUTABLE_SUFFIX}")

#install(PROGRAMS "${EXECUTABLE_OUTPUT_PATH}/HAtaGo${CMAKE_EXECUTABLE_SUFFIX}" DESTINATION ${target_dir})
#ADD_EXECUTABLE( HAtaGo main.hs)

#./HAtaGo +RTS -N(Cores)
