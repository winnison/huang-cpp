// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#pragma once

// Change these values to use different versions
#define WINVER		0x0400
//#define _WIN32_WINNT	0x0400
#define _WIN32_IE	0x0400
#define _RICHEDIT_VER	0x0100

#include <atlbase.h>
#include <atlapp.h>

extern CAppModule _Module;

#include <atlwin.h>

#include <atlmisc.h>
#include <atlgdi.h>




#include <atlcoll.h>

#define EDIT			8500
#include <Imm.h>
#pragma comment(lib, "imm32.lib")


#include <vector>
using namespace std;

