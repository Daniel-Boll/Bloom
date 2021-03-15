workspace "Bloom"
  architecture "x64"
  startproject "Sandbox"

  configurations {
    "Debug",
    "Release",
    "Dist"
  }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder ($(SolutionDir))
IncludeDir = {}
IncludeDir["GLFW"] = "Bloom/third_party/GLFW/include"

include "Bloom/third_party/GLFW"

project "Bloom"
  location "Bloom"
  kind "SharedLib"
  language "C++"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  pchheader "bmpch.hpp"
  pchsource "Bloom/src/bmpch.cpp"

  files {
    "%{prj.name}/src/**.hpp",
    "%{prj.name}/src/**.cpp"
  }

  includedirs {
    "%{prj.name}/src",
    "%{prj.name}/third_party/spdlog/include",
    "%{IncludeDir.GLFW}"
  }

  links {
    "GLFW",
    "opengl32.lib"
  }

  filter "system:windows" 
    cppdialect "C++17"
    staticruntime "On"
    systemversion "latest"

    defines {
      "BM_PLATFORM_WINDOWS",
      "BM_BUILD_DLL"
    }

    postbuildcommands {
      ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox") 
    }
  
  filter "configurations:Debug"
    defines "BM_DEBUG"
    symbols "On"

  filter "configurations:Release"
    defines "BM_RELEASE"
    optimize "On"

  filter "configurations:Dist"
    defines "BM_DIST"
    optimize "On"
  
project "Sandbox"
  location "Sandbox"
  kind "ConsoleApp"

  language "C++"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  files {
    "%{prj.name}/src/**.hpp",
    "%{prj.name}/src/**.cpp"
  }

  includedirs {
    "Bloom/third_party/spdlog/include",
    "Bloom/src"
  }

  links {
    "Bloom"
  }

  filter "system:windows" 
    cppdialect "C++17"
    staticruntime "On"
    systemversion "latest"

    defines {
      "BM_PLATFORM_WINDOWS"
    }
  
  filter "configurations:Debug"
    defines "BM_DEBUG"
    symbols "On"

  filter "configurations:Release"
    defines "BM_RELEASE"
    optimize "On"

  filter "configurations:Dist"
    defines "BM_DIST"
    optimize "On"

