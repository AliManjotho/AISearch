
-----------------------------------
-- WORKSPACE CONFIGURATIONS
-----------------------------------


workspace "AISearch"
	startproject "bfsexample01"
	platforms { "x86", "x64" }
	configurations
	{
		"Debug", "Release"
	}
	
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
	
	
	
	
	

	
--AISEARCH	
	
project "aisolver"
	location "aisolver"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"aisolver/include/aisolver/**.h",
		"aisolver/src/**.cpp"
	}
	
	includedirs
	{
		"aisolver/include"	
	}		
		
	defines
	{
		"AISOLVER_LIB",
	}
	
	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/bfsexample01")
	}
	
		
	filter { "system:window" }
		cppdialect "C++17"
		staticruntime "On"
		systemversion "8.1"

			
		
	filter { "configurations:Debug" }
		
		defines { "DEBUG" }
		symbols "On"		

			
		
	filter { "configurations:Release" }
		
		defines { "NDEBUG" }
		optimize "On"	

	












--BFSEXAMPLE01	
		
project "bfsexample01"
	location "examples/bfsexample01"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files { "examples/bfsexample01/main.cpp" }		
	includedirs { "aisolver/include" }		
	links { "aisolver" }	
	
	filter { "system:window" } cppdialect "C++17" staticruntime "On" systemversion "8.1"		
	
	filter { "configurations:Debug" } defines { "DEBUG" } symbols "On"			
	filter { "configurations:Release" } defines { "NDEBUG" } optimize "On"
	


--BFSEXAMPLE02	
		
project "bfsexample02"
	location "examples/bfsexample02"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files { "examples/bfsexample02/main.cpp" }		
	includedirs { "aisolver/include" }		
	links { "aisolver" }				
	
	filter { "system:window" } cppdialect "C++17" staticruntime "On" systemversion "8.1"		
	
	filter { "configurations:Debug" } defines { "DEBUG" } symbols "On"			
	filter { "configurations:Release" } defines { "NDEBUG" } optimize "On"
	

--DFSEXAMPLE01	
		
project "dfsexample01"
	location "examples/dfsexample01"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files { "examples/dfsexample01/main.cpp" }		
	includedirs { "aisolver/include" }		
	links { "aisolver" }				
	
	filter { "system:window" } cppdialect "C++17" staticruntime "On" systemversion "8.1"		
	
	filter { "configurations:Debug" } defines { "DEBUG" } symbols "On"			
	filter { "configurations:Release" } defines { "NDEBUG" } optimize "On"


--DFSEXAMPLE02
		
project "dfsexample02"
	location "examples/dfsexample02"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files { "examples/dfsexample02/main.cpp" }		
	includedirs { "aisolver/include" }		
	links { "aisolver" }				
	
	filter { "system:window" } cppdialect "C++17" staticruntime "On" systemversion "8.1"		
	
	filter { "configurations:Debug" } defines { "DEBUG" } symbols "On"			
	filter { "configurations:Release" } defines { "NDEBUG" } optimize "On"

