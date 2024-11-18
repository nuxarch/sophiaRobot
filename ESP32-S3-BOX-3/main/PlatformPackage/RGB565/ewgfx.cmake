
set(EMWI_GFX_LIB "libewgfx")

if(${EMWI_SURFACE_ROTATION} MATCHES "90")
  set(EMWI_GFX_LIB "${EMWI_GFX_LIB}-r90")
elseif(${EMWI_SURFACE_ROTATION} MATCHES "180")
  set(EMWI_GFX_LIB "${EMWI_GFX_LIB}-r180")
elseif(${EMWI_SURFACE_ROTATION} MATCHES "270")
  set(EMWI_GFX_LIB "${EMWI_GFX_LIB}-r270")
endif()

set(EMWI_GFX_LIB "${EMWI_GFX_LIB}-gcc.a")

set(EMWI_GFX_FILES 
"ewextgfx.c")