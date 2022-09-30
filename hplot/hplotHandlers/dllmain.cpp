// dllmain.cpp : Implementation of DllMain.

#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "hplotHandlers_i.h"
#include "dllmain.h"
#include "xdlldata.h"

ChplotHandlersModule _AtlModule;

class ChplotHandlersApp : public CWinApp
{
public:

// Overrides
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(ChplotHandlersApp, CWinApp)
END_MESSAGE_MAP()

ChplotHandlersApp theApp;

BOOL ChplotHandlersApp::InitInstance()
{
	if (!PrxDllMain(m_hInstance, DLL_PROCESS_ATTACH, nullptr))
		return FALSE;
	return CWinApp::InitInstance();
}

int ChplotHandlersApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
