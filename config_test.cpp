#ifdef __WAND__
target[name[config-test.exe] type[application] platform[;Windows]]
target[name[config-test] type[application]]
#endif

#include <herbs/main/main.h>

#include "paramset.h"

#include "param_group.h"
#include "param_valuemapped.h"
#include "param_intnamed.h"
#include "param_flagset.h"
#include "uiprovider.h"

#include <herbs/path/path.h>
#include <herbs/timet/timet.h>
#include <mathext/valuemap.h>

#include <herbs/textencoder/textencoder.h>
#include <herbs/fileout/fileout.h>
#include <herbs/stringformat/stringformat.h>
#include <herbs/intformat/intformat.h>

using namespace Config;

struct Parameters
	{
	int32_t an_int;
	int64_t a_large_int;
	uint32_t an_unsigned_int;
	uint64_t a_large_unsigned_int;
	uint32_t a_named_int;
	uint64_t a_large_named_int;
	float a_float;
	double a_double;
	Herbs::Timestamp a_time;
	uint32_t some_flags;
	uint64_t more_flags;
	Herbs::String a_string;
	Herbs::Path a_path;
	};
	
template<class T>
class ValMap:public MathExt::ValueMap<T>
	{
	public:
		T forward(const T& x) const
			{return x;}
		
		T backward(const T& y) const
			{return y;}
		
		MathExt::Interval<T> range() const
			{return {0,16};}
		
		MathExt::Interval<T> domain() const
			{return {0,16};}
		
	};
	
class MyUI:public UIProvider
	{
	public:
		MyUI(Herbs::TextEncoder& enc):m_output(enc)
			{
			m_output.puts(STR("<html><head></head><body><form>"));
			}
		
		~MyUI()
			{
			m_output.puts(STR("</form></body></html>"));
			}
	
		void create(ParamGroup& group)
			{
			if(group.levelGet()>0)
				{
				m_output.puts(Herbs::format(STR("<h%1>%0</h%1>")
					,{group.nameGet().begin(),Herbs::IntFormat<uint32_t>(group.levelGet())}));
				}
			}
			
		void create(ParamValuemapped<int32_t>& param)
			{
			m_output.puts(Herbs::format(STR("<p>%0: <input type=\"text\" id=\"%1\"></p>")
					,{param.nameGet().begin(),Herbs::IntFormat<uint32_t>(param.idGet())}));
			}
	
		void create(ParamValuemapped<int64_t>& param)
			{
			m_output.puts(Herbs::format(STR("<p>%0: <input type=\"text\" id=\"%1\"></p>")
				,{param.nameGet().begin(),Herbs::IntFormat<uint32_t>(param.idGet())}));
			}
		
		void create(ParamValuemapped<uint32_t>& param)
			{
			m_output.puts(Herbs::format(STR("<p>%0: <input type=\"text\" id=\"%1\"></p>")
				,{param.nameGet().begin(),Herbs::IntFormat<uint32_t>(param.idGet())}));
			}
		
		void create(ParamValuemapped<uint64_t>& param)
			{
			m_output.puts(Herbs::format(STR("<p>%0: <input type=\"text\" id=\"%1\"></p>")
				,{param.nameGet().begin(),Herbs::IntFormat<uint32_t>(param.idGet())}));
			}
		
		void create(ParamIntnamed<uint32_t>& param)
			{}
	
		void create(ParamIntnamed<uint64_t>& param)
			{}
		
		void create(ParamValuemapped<float>& param)
			{}
		
		void create(ParamValuemapped<double>& param)
			{}
		
		void create(ParamValueraw<Herbs::Timestamp>& param)
			{}
		
		void create(ParamFlagset<uint32_t>& param)
			{}
			
		void create(ParamFlagset<uint64_t>& param)
			{}
		
		void create(ParamValueraw<Herbs::String>& param)
			{}
			
		void create(ParamValueraw<Herbs::Path>& param)
			{}
		
		
	private:
		Herbs::TextEncoder& m_output;
	};

int MAIN(int argc,charsys_t* argv[])
	{	
	Parameters params;
	ValMap<int32_t> my_map_int32;
	ValMap<int64_t> my_map_int64;
	ValMap<uint32_t> my_map_uint32;
	ValMap<uint64_t> my_map_uint64;
	
	ParamGroupInfo group{STR("Lorem ipsum"),1,1};
	ParamValuemappedInfo<int32_t> an_int{STR("An int"),2,params.an_int,ParamValueInfo<int32_t>::UpdateMethod::NORMAL ,my_map_int32};
	ParamValuemappedInfo<int64_t> a_large_int{STR("A large int"),3,params.a_large_int,ParamValueInfo<int64_t>::UpdateMethod::NORMAL,my_map_int64};
	ParamValuemappedInfo<uint32_t> an_uint{STR("An unsigned int"),4,params.an_unsigned_int,ParamValueInfo<uint32_t>::UpdateMethod::NORMAL ,my_map_uint32};
	ParamValuemappedInfo<uint64_t> a_large_uint{STR("A large unsigned int"),5,params.a_large_unsigned_int,ParamValueInfo<uint64_t>::UpdateMethod::NORMAL,my_map_uint64};
	
	ParamGroupInfo group_2{STR("Sit amet"),1,1};
	
//	Paraminfo* pi[]={&group,&an_int,&a_large_int,&group_2,&an_uint,&a_large_uint,nullptr};
	
	Herbs::FileOut form(Herbs::Path(STR("test.html")));
	Herbs::TextEncoder encoder(form,Herbs::TextEncoder::Mode::LATIN_1);
	MyUI ui(encoder);
	Paramset paramset({group,an_int,a_large_int,group_2,an_uint,a_large_uint});
	paramset.uiCreate(ui);
	
	
	return 0;
	}