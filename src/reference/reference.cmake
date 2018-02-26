set(DRAWSVG_BUILD_REFERENCE OFF)

if(DRAWSVG_BUILD_REFERENCE)

  # Build reference
  include_directories(${CMAKE_CURRENT_SOURCE_DIR})

  # drawsvg reference source
  set(CMU462_DrawSVGREF_SOURCE
      reference/viewport.cpp
      reference/texture.cpp
      reference/software_renderer.cpp
  )

  # drawsvg reference lib
  add_library( drawsvg_ref STATIC
      ${CMU462_DrawSVGREF_SOURCE}
  )

  # output name
  if (UNIX)
    set_target_properties(drawsvg_ref PROPERTIES OUTPUT_NAME drawsvgref)
    if(APPLE)
      set_target_properties(drawsvg_ref PROPERTIES OUTPUT_NAME drawsvgref_osx)
    endif(APPLE)
  endif(UNIX)
  install(TARGETS drawsvg_ref DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/reference)

else(DRAWSVG_BUILD_REFERENCE)

  add_library( drawsvg_ref STATIC IMPORTED)

  # Import reference
  if (UNIX)
	if(CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 5.2)
      set_property(TARGET drawsvg_ref PROPERTY IMPORTED_LOCATION
                   ${CMAKE_CURRENT_SOURCE_DIR}/reference/libdrawsvgref.a)
    else()
      set_property(TARGET drawsvg_ref PROPERTY IMPORTED_LOCATION
                   ${CMAKE_CURRENT_SOURCE_DIR}/reference/libdrawsvgref_old.a)
    endif()
  endif(UNIX)

  if(APPLE)
    set_property(TARGET drawsvg_ref PROPERTY IMPORTED_LOCATION
                 ${CMAKE_CURRENT_SOURCE_DIR}/reference/libdrawsvgref_osx.a)
  endif(APPLE)

  if(WIN32)
    set_property(TARGET drawsvg_ref PROPERTY IMPORTED_LOCATION
                 ${CMAKE_CURRENT_SOURCE_DIR}/reference/drawsvg_ref.lib)
  endif(WIN32)

endif(DRAWSVG_BUILD_REFERENCE)
