/*******************************************************************************
*
* E M B E D D E D   W I Z A R D   P R O J E C T
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This software and related documentation ("Software") are intellectual
* property owned by TARA Systems and are copyright of TARA Systems.
* Any copying, reproduction or redistribution of the Software in whole or in
* part by any means not in accordance with the End-User License Agreement for
* Embedded Wizard is expressly prohibited. The removal of this preamble is
* expressly prohibited.
*
********************************************************************************
*
* DESCRIPTION:
*   This header file contains Graphics Engine configuration parameters and the
*   adaptation for the target specific graphics subsystem.
*
*******************************************************************************/

#ifndef EWEXTGFX_H
#define EWEXTGFX_H


#ifdef __cplusplus
  extern "C"
  {
#endif

/* Index8 color format expects the following macro to be defined */
#define EW_ENABLE_COLOR_TABLE 1


/* Index8 color format cannot operate with premultiplied colors */
#define EW_PREMULTIPLY_COLOR_CHANNELS         0


/*******************************************************************************
* FUNCTION:
*   GfxInitGfx
*
* DESCRIPTION:
*   The function GfxInitGfx is called from the Graphics Engine during the
*   initialization in order to make target specific configurations of the
*   Graphics Engine
*
* ARGUMENTS:
*   aArgs - Optional argument passed to the Graphics Engine init function.
*
* RETURN VALUE:
*   If successful, returns != 0.
*
*******************************************************************************/
int GfxInitGfx
(
  void*             aArgs
);


/*******************************************************************************
* FUNCTION:
*   GfxInitViewport
*
* DESCRIPTION:
*   The function GfxInitViewport is called from the Graphics Engine,
*   to create a new viewport on the target. The function uses the given
*   buffers passed in the arguments aDisplay1 and aDisplay2.
*
* ARGUMENTS:
*   aWidth,
*   aHeight       - Size of the application in pixel.
*   aExtentX,
*   aExtentY      - not used.
*   aExtentWidth,
*   aExtentHeight - Size of the physical or virtual framebuffer in pixel.
*   aOrient       - not used.
*   aOpacity      - not used.
*   aDisplay1     - Address of the framebuffer / scratch-pad buffer.
*   aDisplay2     - Address of the back-buffer in case of double-buffering.
*   aDisplay3     - not used.
*
* RETURN VALUE:
*   Handle of the surface descriptor (viewport).
*
*******************************************************************************/
void* GfxInitViewport
(
  int               aWidth,
  int               aHeight,
  int               aExtentX,
  int               aExtentY,
  int               aExtentWidth,
  int               aExtentHeight,
  int               aOrient,
  int               aOpacity,
  void*             aDisplay1,
  void*             aDisplay2,
  void*             aDisplay3
);


/*******************************************************************************
* FUNCTION:
*   GfxDoneViewport
*
* DESCRIPTION:
*   The function GfxDoneViewport is called from the Graphics Engine, to
*   release a previously created viewport on the target.
*
* ARGUMENTS:
*   aHandle - Handle of the surface descriptor (viewport).
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void GfxDoneViewport
(
  void*             aHandle
);


/*******************************************************************************
* FUNCTION:
*   GfxBeginUpdate
*
* DESCRIPTION:
*   The function GfxBeginUpdate is called from the Graphics Engine, to
*   initiate the screen update cycle.
*
* ARGUMENTS:
*   aHandle - Handle of the surface descriptor (viewport).
*
* RETURN VALUE:
*   Handle of the destination surface, used for all drawing operations.
*
*******************************************************************************/
void* GfxBeginUpdate
(
  void*             aHandle
);


/*******************************************************************************
* FUNCTION:
*   GfxBeginUpdateArea
*
* DESCRIPTION:
*   The function GfxBeginUpdateArea is called from the Graphics Engine, to
*   initiate a partial screen update cycle.
*
* ARGUMENTS:
*   aHandle - Handle of the surface descriptor (viewport).
*   aX,
*   aY,
*   aWidth,
*   aHeight - Position and size of the area affected by the screen update
*     (dirty rectangle).
*
* RETURN VALUE:
*   Handle of the destination surface, used for all drawing operations.
*
*******************************************************************************/
void* GfxBeginUpdateArea
(
  void*             aHandle,
  int               aX,
  int               aY,
  int               aWidth,
  int               aHeight
);


/*******************************************************************************
* FUNCTION:
*   GfxEndUpdate
*
* DESCRIPTION:
*   The function GfxEndUpdate is called from the Graphics Engine, to
*   finalize the screen update cycle.
*
* ARGUMENTS:
*   aHandle - Handle of the surface descriptor (viewport).
*   aX,
*   aY,
*   aWidth,
*   aHeight - Position and size of the area affected from the screen update
*     (dirty rectangle).
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void GfxEndUpdate
(
  void*             aHandle,
  int               aX,
  int               aY,
  int               aWidth,
  int               aHeight
);


/* Redirect the following operations to the functions within this module */
#define EwGfxInit            GfxInitGfx
#define EwGfxInitViewport    GfxInitViewport
#define EwGfxDoneViewport    GfxDoneViewport
#define EwGfxBeginUpdate     GfxBeginUpdate
#define EwGfxBeginUpdateArea GfxBeginUpdateArea
#define EwGfxEndUpdate       GfxEndUpdate


/*******************************************************************************
* FUNCTION:
*   GfxLoadClut
*
* DESCRIPTION:
*   The function GfxLoadClut is called from the Graphics Engine, to load or
*   modify one or more entries of the hardware color look-up table.
*
* ARGUMENTS:
*   aColors - Pointer to an array containing 32 bit RGBA color values to load
*     into the CLUT. The color values are stored in the following manner:
*
*              31           24           16             8            0
*               +------------+---------------------------------------+
*               |   alpha    |    blue    |    green    |    red     |
*               +------------+---------------------------------------+
*
*   aIndex  - Index to the CLUT entry to start the loading.
*   aCount  - Number of entries in the aColors array. This is the number of
*     CLUT entries to load.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
int GfxLoadClut
(
  unsigned long*    aColors,
  int               aIndex,
  int               aCount
);


/* Redirect the following operations to the functions within this module */
#define EwGfxLoadClut   GfxLoadClut


/*******************************************************************************
* FUNCTION:
*   GfxCreateSurface
*
* DESCRIPTION:
*   The function GfxCreateSurface() reserves pixel memory for a new surface
*   with the given size and color format. The function returns a handle to the
*   new surface.
*
* ARGUMENTS:
*   aFormat  - Color format of the surface. (See EW_PIXEL_FORMAT_XXX).
*   aWidth,
*   aHeight  - Size of the surface in pixel to create.
*
* RETURN VALUE:
*   The function returns a handle to the created surface. This can be a pointer
*   to a dynamically allocated data structure, an index in a list of surfaces,
*   or a handle returned by the lower level API.
*
*   If the creation is failed, the function should return 0.
*
*******************************************************************************/
void* GfxCreateSurface
(
  int               aFormat,
  int               aWidth,
  int               aHeight
);


/*******************************************************************************
* FUNCTION:
*   GfxCreateConstSurface
*
* DESCRIPTION:
*   The function GfxCreateConstSurface() creates a surface structure
*   that refers to a constant pixel memory. The function returns a handle to the
*   new surface.
*
* ARGUMENTS:
*   aFormat - Color format of the surface. (See EW_PIXEL_FORMAT_XXX).
*   aWidth,
*   aHeight - Size of the surface in pixel.
*   aMemory - Pointer to constant pixel memory.
*
* RETURN VALUE:
*   The function returns a handle to the created surface.
*   If the creation is failed, the function should return 0.
*
*******************************************************************************/
void* GfxCreateConstSurface
(
  int               aFormat,
  int               aWidth,
  int               aHeight,
  XSurfaceMemory*   aMemory
);


/*******************************************************************************
* FUNCTION:
*   GfxDestroySurface
*
* DESCRIPTION:
*   The function GfxDestroySurface() frees the resources of the given surface.
*   This function is a counterpart to GfxCreateSurface().
*
* ARGUMENTS:
*   aHandle - Handle to the surface to free.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void GfxDestroySurface
(
  void*             aHandle
);


/*******************************************************************************
* FUNCTION:
*   GfxLockSurface
*
* DESCRIPTION:
*   The function GfxLockSurface() provides a direct access to the pixel memory of
*   the given surface. The function returns a lock object containing pointers to
*   memory, where the caller can read/write the surface pixel values. Additional
*   pitch values also returned in the object allow the caller to calculate the
*   desired pixel addresses.
*
* ARGUMENTS:
*   aHandle     - Handle to the surface to obtain the direct memory access.
*   aX, aY,
*   aWidth,
*   aHeight     - Area within the surface affected by the access operation.
*     (Relative to the top-left corner of the surface). This is the area, the
*     caller wish to read/write the pixel data.
*   aIndex,
*   Count       - Optional start index and number of entries within the CLUT,
*     the caller wish to read/write. These paramaters are used for surfaces
*     with the index8 color format only.
*   aReadPixel  - Is != 0, if the caller intends to read the pixel information
*     from the surface memory. If == 0, the memory content may remain undefined
*     depending on the underlying graphics sub-system and its video-memory
*     management.
*   aWritePixel - Is != 0, if the caller intends to modify the pixel information
*     within the surface memory. If == 0, any modifications within the memory
*     may remain ignored depending on the underlying graphics sub-system and its
*     video-memory management.
*   aReadClut   - Is != 0, if the caller intends to read the CLUT information.
*     If == 0, the CLUT content may remain undefined.
*   aWriteClut  - Is != 0, if the caller intends to modify the CLUT information.
*     If == 0, any modifications within the memory may remain ignored depending
*     on the underlying graphics sub-system and its video-memory management.
*   aMemory     - Pointer to an object, where the desired surface pointers
*     should be stored.
*
* RETURN VALUE:
*   If successful, the function should return a kind of a lock object. This
*   object can contain additional information needed when the surface is
*   unlocked again. If you don't want to return additional information, return
*   any value != 0.
*
*   If there was not possible to lock the surface, or the desired access mode
*   is just not supported by the underlying graphics sub-system, the function
*   fails and returns zero.
*
*******************************************************************************/
void* GfxLockSurface
(
  void*             aHandle,
  int               aX,
  int               aY,
  int               aWidth,
  int               aHeight,
  int               aIndex,
  int               aCount,
  int               aReadPixel,
  int               aWritePixel,
  int               aReadClut,
  int               aWriteClut,
  XSurfaceMemory*   aMemory
);


/*******************************************************************************
* FUNCTION:
*   GfxUnlockSurface
*
* DESCRIPTION:
*   The function GfxUnlockSurface() has the job to unlock the given surface and
*   if necessary free any temporary used resources.
*   This function is a counterpart to GfxLockSurface().
*
* ARGUMENTS:
*   aSurfaceHandle - Handle to the surface to release the direct memory access.
*   aLockHandle    - value returned by the corresponding LockSurface() call.
*     If LockSurface() has allocated memory for the lock object, you will need
*     to free it now.
*   aX, aY,
*   aWidth,
*   aHeight     - Area within the surface affected by the access operation.
*     (Relative to the top-left corner of the surface). This is the area, the
*     caller wished to read/write the pixel data.
*   aIndex,
*   Count       - Optional start index and number of entries within the CLUT,
*     the caller wished to read/write. These paramaters are used for surfaces
*     with the index8 color format only.
*   aWritePixel - Is != 0, if the caller has modified the pixel information
*     within the surface memory. If == 0, no modification took place, so no
*     surface updates are needed.
*   aWriteClut  - Is != 0, if the caller has modified the CLUT information.
*     If == 0, no modification took place, so no surface updates are needed.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void GfxUnlockSurface
(
  void*             aSurfaceHandle,
  void*             aLockHandle,
  int               aX,
  int               aY,
  int               aWidth,
  int               aHeight,
  int               aIndex,
  int               aCount,
  int               aWritePixel,
  int               aWriteClut
);


/* Macros to redirect the Graphics Engine operations to the above functions. */
#define EwGfxCreateNativeSurface      GfxCreateSurface
#define EwGfxCreateConstNativeSurface GfxCreateConstSurface
#define EwGfxDestroyNativeSurface     GfxDestroySurface
#define EwGfxLockNativeSurface        GfxLockSurface
#define EwGfxUnlockNativeSurface      GfxUnlockSurface


#ifdef __cplusplus
  }
#endif

#endif /* EWEXTGFX_H */


/* msy */