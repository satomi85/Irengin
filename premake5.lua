workspace "Irengin"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Irengin"
	location "Irengin"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h"	,
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"IRNGN_BUILD_DLL",
			"IRNGN_PLATFORM_WINDOWS"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Blackbox")
		}

	filter "configurations:Debug"
		defines "IRNGN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "IRNGN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "IRNGN_DIST"
		optimize "On"


project "Blackbox"
	location "Blackbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Irengin/vendor/spdlog/include",
		"Irengin/src"
	}

	links
	{
		"Irengin"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"IRNGN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "IRNGN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "IRNGN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "IRNGN_DIST"
		optimize "On"