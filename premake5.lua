
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
	
	targetdir ("bin/" .. outputdir)
	objdir ("bin-int/" .. outputdir)
	
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
	
	targetdir ("bin/" .. outputdir)
	objdir ("bin-int/" .. outputdir)
	
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
	
	targetdir ("bin/" .. outputdir)
	objdir ("bin-int/" .. outputdir)
	
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
	
	targetdir ("bin/" .. outputdir)
	objdir ("bin-int/" .. outputdir)
	
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
	
	targetdir ("bin/" .. outputdir)
	objdir ("bin-int/" .. outputdir)
	
	files { "examples/dfsexample02/main.cpp" }		
	includedirs { "aisolver/include" }		
	links { "aisolver" }				
	
	filter { "system:window" } cppdialect "C++17" staticruntime "On" systemversion "8.1"		
	
	filter { "configurations:Debug" } defines { "DEBUG" } symbols "On"			
	filter { "configurations:Release" } defines { "NDEBUG" } optimize "On"



--GREEDYBFSEXAMPLE01	
		
project "greedybfsexample01"
	location "examples/greedybfsexample01"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir)
	objdir ("bin-int/" .. outputdir)
	
	files { "examples/greedybfsexample01/main.cpp" }		
	includedirs { "aisolver/include" }		
	links { "aisolver" }	
	
	filter { "system:window" } cppdialect "C++17" staticruntime "On" systemversion "8.1"		
	
	filter { "configurations:Debug" } defines { "DEBUG" } symbols "On"			
	filter { "configurations:Release" } defines { "NDEBUG" } optimize "On"
	


--GREEDYBFSEXAMPLE02	
		
project "greedybfsexample02"
	location "examples/greedybfsexample02"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir)
	objdir ("bin-int/" .. outputdir)
	
	files { "examples/greedybfsexample02/main.cpp" }		
	includedirs { "aisolver/include" }		
	links { "aisolver" }				
	
	filter { "system:window" } cppdialect "C++17" staticruntime "On" systemversion "8.1"		
	
	filter { "configurations:Debug" } defines { "DEBUG" } symbols "On"			
	filter { "configurations:Release" } defines { "NDEBUG" } optimize "On"
	
