workspace "Bloom"
  architecture "x64"
  startproject "Sandbox"

  configurations {
    "Debug",
    "Release",
    "Dist"
  }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Bloom"
  location "Bloom"
  kind "SharedLib"
  language "C++"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  files {
    "%{prj.name}/src/**.hpp",
    "%{prj.name}/src/**.cpp"
  }

  includedirs {
    "%{prj.name}/third_party/spdlog/include",
    "Bloom/src"
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

