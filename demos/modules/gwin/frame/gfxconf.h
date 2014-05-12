/**
 * This file has a different license to the rest of the uGFX system.
 * You can copy, modify and distribute this file as you see fit.
 * You do not need to publish your source modifications to this file.
 * The only thing you are not permitted to do is to relicense it
 * under a different license.
 */

/**
 * Copy this file into your project directory and rename it as gfxconf.h
 * Edit your copy to turn on the uGFX features you want to use.
 * The values below are the defaults. You should delete anything
 * you are leaving as default.
 *
 * Please use spaces instead of tabs in this file.
 */

#ifndef _GFXCONF_H
#define _GFXCONF_H

/* The operating system to use. One of these must be defined - preferably in your Makefile */
//#define GFX_USE_OS_CHIBIOS                         TRUE
//#define GFX_USE_OS_WIN32                           TRUE
//#define GFX_USE_OS_LINUX                           TRUE
//#define GFX_USE_OS_OSX                             TRUE


///////////////////////////////////////////////////////////////////////////
// GDISP                                                                 //
///////////////////////////////////////////////////////////////////////////
#define GFX_USE_GDISP                                TRUE

#define GDISP_NEED_AUTOFLUSH                         FALSE
#define GDISP_NEED_TIMERFLUSH                        FALSE
#define GDISP_NEED_VALIDATION                        TRUE
#define GDISP_NEED_CLIP                              TRUE
#define GDISP_NEED_TEXT                              TRUE
    #define GDISP_INCLUDE_FONT_UI2                   TRUE
#define GDISP_NEED_CIRCLE                            TRUE
#define GDISP_NEED_CONVEX_POLYGON                    TRUE
#define GDISP_NEED_MULTITHREAD                       TRUE

#define GDISP_DEFAULT_ORIENTATION                    GDISP_ROTATE_LANDSCAPE

///////////////////////////////////////////////////////////////////////////
// GWIN                                                                  //
///////////////////////////////////////////////////////////////////////////
#define GFX_USE_GWIN                                 TRUE

#define GWIN_NEED_WINDOWMANAGER                      TRUE

#define GWIN_NEED_CONSOLE                            TRUE
    #define GWIN_CONSOLE_USE_HISTORY                 TRUE
        #define GWIN_CONSOLE_HISTORY_AVERAGING       TRUE
        #define GWIN_CONSOLE_HISTORY_ATCREATE        TRUE
    #define GWIN_CONSOLE_ESCSEQ                      TRUE
	#define GWIN_CONSOLE_USE_BASESTREAM              TRUE
#define GWIN_NEED_GRAPH                              TRUE

#define GWIN_NEED_WIDGET                             TRUE
    #define GWIN_NEED_LABEL                          TRUE
        #define GWIN_LABEL_ATTRIBUTE                 TRUE
    #define GWIN_NEED_BUTTON                         TRUE
        #define GWIN_BUTTON_LAZY_RELEASE             TRUE
    #define GWIN_NEED_SLIDER                         TRUE
    #define GWIN_NEED_CHECKBOX                       TRUE
    #define GWIN_NEED_IMAGE                          FALSE
        #define GWIN_NEED_IMAGE_ANIMATION            TRUE
    #define GWIN_NEED_RADIO                          TRUE
    #define GWIN_NEED_LIST                           TRUE
        #define GWIN_NEED_LIST_IMAGES                FALSE
    #define GWIN_NEED_PROGRESSBAR                    TRUE
        #define GWIN_PROGRESSBAR_AUTO                TRUE
	#define GWIN_FLAT_STYLING                        TRUE
#define GWIN_NEED_CONTAINERS                         TRUE
    #define GWIN_NEED_CONTAINER                      TRUE
    #define GWIN_NEED_FRAME                          TRUE


///////////////////////////////////////////////////////////////////////////
// GEVENT                                                                //
///////////////////////////////////////////////////////////////////////////
#define GFX_USE_GEVENT                               TRUE

///////////////////////////////////////////////////////////////////////////
// GTIMER                                                                //
///////////////////////////////////////////////////////////////////////////
#define GFX_USE_GTIMER                               TRUE

///////////////////////////////////////////////////////////////////////////
// GQUEUE                                                                //
///////////////////////////////////////////////////////////////////////////
#define GFX_USE_GQUEUE                               TRUE

#define GQUEUE_NEED_ASYNC                            TRUE
#define GQUEUE_NEED_GSYNC                            TRUE
#define GQUEUE_NEED_FSYNC                            FALSE
#define GQUEUE_NEED_BUFFERS                          FALSE

///////////////////////////////////////////////////////////////////////////
// GINPUT                                                                //
///////////////////////////////////////////////////////////////////////////
#define GFX_USE_GINPUT                               TRUE

#define GINPUT_NEED_MOUSE                            TRUE

#endif /* _GFXCONF_H */