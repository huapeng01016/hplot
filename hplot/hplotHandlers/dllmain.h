// dllmain.h : Declaration of module class.

class ChplotHandlersModule : public ATL::CAtlDllModuleT<ChplotHandlersModule>
{
public :
	DECLARE_LIBID(LIBID_hplotHandlersLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_HPLOTHANDLERS, "{16e7f9a7-a713-4987-9272-9a070fb3d2c9}")
};

extern class ChplotHandlersModule _AtlModule;
