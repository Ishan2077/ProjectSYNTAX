workspace "SkyEngine"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--Include directories relative to root folder (solution directory)
IncludeDir = {} --Compiler Include directory,i.e., "%{IncludeDir.GLFW}"
IncludeDir["GLFW"] = "SkyEngine/vendor/GLFW/include"

include "SkyEngine/vendor/GLFW"

project "SkyEngine"
	location "SkyEngine" --Because it is a DLL file. So, 'link' a static library into it.
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "sepch.h"
	pchsource "SkyEngine/src/sepch.cpp" --[[VS Specific , creates our pre-compiled header file.]]

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

    includedirs
    {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
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

		defines{
			"SE_PLATFORM_WINDOWS",
			"SE_BUILD_DLL"
		}
		--[[PUTS DLL WHERE IT WANTS TO BE]]

		postbuildcommands{
			{"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"}
		}

	filter "configurations:Debug"
		defines "SE_DEBUG"
		symbols "On"

	 filter "configurations:Release"
		defines "SE_RELEASE"
		optimize "On"

	 filter "configurations:Dist"
		defines "SE_DIST"
		optimize "On"

	 filter {"system:windows", "configurations:Release"}

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"SkyEngine/vendor/spdlog/include",
		"SkyEngine/src"
	}

	--[[links to the main SkyEngine project/solution]]
	links {
		"SkyEngine" 
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"SE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SE_DEBUG"
		symbols "On"

	 filter "configurations:Release"
		defines "SE_RELEASE"
		optimize "On"

	 filter "configurations:Dist"
		defines "SE_DIST"
		optimize "On"
