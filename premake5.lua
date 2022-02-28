workspace "Walnut"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Irelative to root folder (solution dir)
IncludeDir = {}
IncludeDir["GLFW"] = "Walnut/vendor/GLFW/include"
IncludeDir["spdlog"] = "Walnut/vendor/spdlog/include"

include "Walnut/vendor/GLFW"

project "Walnut"
	location "Walnut"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	pchheader "pch.h"
	pchsource "Walnut/src/pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}


	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.spdlog}",
	}

	links 
	{ 
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"WN_PLATFORM_WINDOWS",
			"WN_BUILD_DLL"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "WN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "WN_RELEASE"
		optimize "On"

	filter "configurations:Debug"
		defines "WN_DIST"
		optimize "On"
	

project "Sandbox"
	location "Sandbox"

	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Walnut/vendor/spdlog/include",
		"Walnut/src"
	}

	links
	{
		"Walnut"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"WN_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "WN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "WN_RELEASE"
		optimize "On"

	filter "configurations:Debug"
		defines "WN_DIST"
		optimize "On"