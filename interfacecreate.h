#ifdef __WAND__
target[name[interfacecreate.h] type[include]]
dependency[interfacecreate.o]
#endif

namespace Config
	{
	class ParamCollector;
	class InterfaceBuilder;
	
	void interfaceCreate(const ParamCollector& params_in,InterfaceBuilder& builder);
	};