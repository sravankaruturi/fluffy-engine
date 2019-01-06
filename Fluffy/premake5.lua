workspace "Fluffy"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "FluffyEngine"
	location "FluffyEngine"
	kind "SharedLib"
	language "C++"

	targetdir	("bin/" .. outputdir .. "/%{prj.name}")
	objdir		("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/vendor/spdlog/include/"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"F_PLATFORM_WINDOWS",
			"F_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "F_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "F_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "F_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir	("bin/" .. outputdir .. "/%{prj.name}")
	objdir		("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"FluffyEngine/src/",
		"FluffyEngine/vendor/spdlog/include/"
	}

	links{
		"FluffyEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"F_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "F_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "F_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "F_DIST"
		optimize "On"